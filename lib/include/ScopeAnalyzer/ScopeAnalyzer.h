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
#include "ScopeState/ScopeState.h"

#include <fstream>
#include <vector>

using json = nlohmann::json;

class ScopeAnalyzer {
 public:
  explicit ScopeAnalyzer(const std::string& json_vocab, ScopeContext context);

  AddTokenResult AddToken(int32_t token);
  void ResetState(ScopeContext context);
 private:
  void ApplyContext(ScopeContext context);

  ConstructionsStreamExtractor constructions_extractor_;
  std::vector<std::unique_ptr<IHandler, IHandler::Deleter>> handlers_;

  std::unique_ptr<Construction> waiting_for_construction_;
  ScopeState state_;
};


#ifdef __cplusplus
extern "C" {
#endif

ScopeAnalyzer* scope_analyzer_new(const char* json_vocab, ScopeContext* context);
void scope_analyzer_del(ScopeAnalyzer* scope_analyzer);
void apply_context(ScopeAnalyzer* scope_analyzer, ScopeContext* context);
AddTokenResult add_token(ScopeAnalyzer* scope_analyzer, int32_t token);

#ifdef __cplusplus
}
#endif

#endif //RUNTIME_SRC_ANALYZER_H_
