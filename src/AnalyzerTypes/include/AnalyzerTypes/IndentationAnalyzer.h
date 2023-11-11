//
// Created by Даник 💪 on 07.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_

#include "IAnalyzer.h"
#include "Constructions/ConstructionsStreamExtractor.h"
#include "ScopeAnalyzerState/IndentationAnalyzerState.h"

class IndentationAnalyzer : public IAnalyzer {
 public:
  IndentationAnalyzer(
                const Tokenizer& tokenizer,
                handlers_list_ptr handlers,
                ScopeContext context);
  AddTokenResult AddToken(int32_t token) override;
  void ResetState(ScopeContext context, Language language) override;
  void ApplyContext(ScopeContext context) override;
 private:
  IndentationAnalyzerState state_;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_
