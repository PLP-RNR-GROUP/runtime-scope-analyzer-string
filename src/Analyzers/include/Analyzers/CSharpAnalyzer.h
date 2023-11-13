//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_CSHARPANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_CSHARPANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class CSharpAnalyzer : public BraceAnalyzer {
 public:
  explicit CSharpAnalyzer(const Tokenizer& tokenizer, ScopeContext context);
};

#endif //RUNTIME_SRC_ANALYZERS_CSHARPANALYZER_H_
