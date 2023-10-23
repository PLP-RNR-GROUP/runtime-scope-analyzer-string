//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_ANALYZER_H_
#define RUNTIME_SRC_ANALYZER_H_

#include "nlohmann/json.hpp"
#include "ScopeAnalyzer/Results/AddTokenResult.h"
#include "Constructions/ConstructionsStreamExtractor.h"
#include "StartContext.h"
#include "Handlers/IHandler.h"

#include <fstream>
#include <vector>

using json = nlohmann::json;

class ScopeAnalyzer {
 public:
  explicit ScopeAnalyzer(const std::string& json_vocab, StartContext context);

  AddTokenResult AddToken(int32_t token);
  void ResetState(StartContext context);
 private:
  void ApplyContext(StartContext context);
  ConstructionsStreamExtractor constructions_extractor_;
  std::vector<std::unique_ptr<IHandler, IHandler::Deleter>> handlers_;
  std::unique_ptr<Construction> waiting_for_construction_;
  int brace_balance;
};


#ifdef __cplusplus
extern "C" {
#endif

ScopeAnalyzer* scope_analyzer_new(const char* json_vocab, StartContext* context);
void scope_analyzer_del(ScopeAnalyzer* scope_analyzer);
void apply_context(ScopeAnalyzer* scope_analyzer, StartContext* context);
AddTokenResult add_token(ScopeAnalyzer* scope_analyzer, int32_t token);

#ifdef __cplusplus
}
#endif

#endif //RUNTIME_SRC_ANALYZER_H_
