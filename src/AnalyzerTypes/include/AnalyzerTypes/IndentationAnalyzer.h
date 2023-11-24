//
// Created by Даник 💪 on 07.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_


#include "AnalyzerTypes/BaseAnalyzer.h"

class IndentationAnalyzer : public BaseAnalyzer {
 public:
  IndentationAnalyzer(
                      const Tokenizer& tokenizer,
                      handlers_list_ptr handlers,
                      ScopeContext context);
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_
