//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_SCALAANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_SCALAANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class ScalaAnalyzer : public BraceAnalyzer {
 public:
  explicit ScalaAnalyzer(const Tokenizer& tokenizer, ScopeContext context);
};

#endif //RUNTIME_SRC_ANALYZERS_SCALAANALYZER_H_
