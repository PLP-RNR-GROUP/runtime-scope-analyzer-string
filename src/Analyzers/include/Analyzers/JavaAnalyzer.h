//
// Created by Даник 💪 on 09.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_JAVAANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_JAVAANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class JavaAnalyzer : public BraceAnalyzer {
 public:
  explicit JavaAnalyzer(const Tokenizer& tokenizer, ScopeContext context);
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_JAVAANALYZER_H_
