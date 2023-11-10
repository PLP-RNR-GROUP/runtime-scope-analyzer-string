//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_GOANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_GOANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class GoAnalyzer : public BraceAnalyzer {
 public:
  explicit GoAnalyzer(const Tokenizer& tokenizer);
};

#endif //RUNTIME_SRC_ANALYZERS_GOANALYZER_H_
