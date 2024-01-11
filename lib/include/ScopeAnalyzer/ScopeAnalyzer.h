//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_ANALYZER_H_
#define RUNTIME_SRC_ANALYZER_H_

#include "nlohmann/json.hpp"
#include "Handlers/Results/AddTokenResult.h"
#include "ConstructionsStreamExtractor/ConstructionsStreamExtractor.h"
#include "AnalyzerTypes/BraceAnalyzerState.h"
#include "AnalyzerTypes/IAnalyzer.h"

#include "Contexts/ScopeContext.h"
#include "Handlers/IHandler.h"
#include "Languages/Language.h"

#include <fstream>
#include <vector>
#include <string>

using json = nlohmann::json;

class ScopeAnalyzer {
 public:

  explicit ScopeAnalyzer(const ScopeAnalyzer& scope_analyzer);

  explicit ScopeAnalyzer(const std::string& json_vocab,
                         ScopeContext context,
                         Language selected_language);

  AddTokenResult AddToken(int32_t token);
  void ResetState(ScopeContext context, Language language);

 private:
  std::unique_ptr<IAnalyzer, IAnalyzer::Deleter> analyzer_;

  std::unique_ptr<IAnalyzer, IAnalyzer::Deleter> PickAnalyzerForLanguage(Language language,
                                                                         ScopeContext context);
  Tokenizer tokenizer_;
};


#ifdef __cplusplus
extern "C" {
#endif

ScopeAnalyzer* scope_analyzer_new(const char* json_vocab, ScopeContext* context, Language selected_language);
void scope_analyzer_del(ScopeAnalyzer* scope_analyzer);
void reset(ScopeAnalyzer* scope_analyzer, ScopeContext* context, Language language);
AddTokenResult add_token(ScopeAnalyzer* scope_analyzer, int32_t token);

#ifdef __cplusplus
}
#endif

#endif //RUNTIME_SRC_ANALYZER_H_
