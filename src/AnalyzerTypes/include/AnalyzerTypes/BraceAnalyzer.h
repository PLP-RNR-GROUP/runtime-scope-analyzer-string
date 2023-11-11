//
// Created by Даник 💪 on 07.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_

#include "IAnalyzer.h"
#include "Constructions/ConstructionsStreamExtractor.h"
#include "AnalyzerTypes/Results/AddTokenResult.h"

class BraceAnalyzer : public IAnalyzer {
 public:
  BraceAnalyzer(const Tokenizer& tokenizer,
                handlers_list_ptr handlers);
  AddTokenResult AddToken(int32_t token) override;
  void ResetState(ScopeContext context, Language language) override;
  void ApplyContext(ScopeContext context) override;
 private:
  BraceAnalyzerState state_;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_
