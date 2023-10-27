//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_ANALYZER_H_
#define RUNTIME_SRC_ANALYZER_H_

#include "nlohmann/json.hpp"
#include "ScopeAnalyzer/Results/AddTokenResult.h"
#include "Constructions/ConstructionsStreamExtractor.h"
#include "ScopeContext.h"
#include "Handlers/IHandler.h"
#include "Languages/Language.h"
#include "Languages/LanguageHandlersSelector.h"

#include <fstream>
#include <vector>

using json = nlohmann::json;

class ScopeAnalyzer {
 public:
  explicit ScopeAnalyzer(const std::string& json_vocab,
                         ScopeContext context,
                         Language selected_language);

  AddTokenResult AddToken(int32_t token);
  void ResetState(ScopeContext context);
 private:
  void ApplyContext(ScopeContext context);
  std::unique_ptr<ConstructionsStreamExtractor> constructions_stream_extractor_;

  const handlers_list* handlers_;
  LanguageHandlersSelector handlers_selector_;
  boost::circular_buffer<char> chars_buffer;
  std::unique_ptr<Construction> waiting_for_construction_;

  int brace_balance;
};


#ifdef __cplusplus
extern "C" {
#endif

ScopeAnalyzer* scope_analyzer_new(const char* json_vocab, ScopeContext* context, Language selected_language);
void scope_analyzer_del(ScopeAnalyzer* scope_analyzer);
void apply_context(ScopeAnalyzer* scope_analyzer, ScopeContext* context);
AddTokenResult add_token(ScopeAnalyzer* scope_analyzer, int32_t token);

#ifdef __cplusplus
}
#endif

#endif //RUNTIME_SRC_ANALYZER_H_
