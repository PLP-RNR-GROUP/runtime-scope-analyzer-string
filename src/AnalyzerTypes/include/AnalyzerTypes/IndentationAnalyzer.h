//
// Created by Даник 💪 on 07.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_

#include "IAnalyzer.h"
#include "Constructions/ConstructionsStreamExtractor.h"

class IndentationAnalyzer : public IAnalyzer {
 public:
  IndentationAnalyzer(
                const Tokenizer& tokenizer,
                handlers_list_ptr handlers);
  AddTokenResult AddToken(int32_t token) override;

 private:
  ScopeAnalyzerState state_;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_
