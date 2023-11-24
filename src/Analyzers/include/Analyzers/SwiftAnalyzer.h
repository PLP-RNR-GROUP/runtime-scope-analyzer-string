//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_SWIFTANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_SWIFTANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class SwiftAnalyzer : public BraceAnalyzer {
 public:
  explicit SwiftAnalyzer(const Tokenizer& tokenizer, ScopeContext context);
};

#endif //RUNTIME_SRC_ANALYZERS_SWIFTANALYZER_H_
