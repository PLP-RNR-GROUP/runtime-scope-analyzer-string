//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_JSONANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_JSONANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class JsonAnalyzer : public BraceAnalyzer {
 public:
  explicit JsonAnalyzer(const Tokenizer& tokenizer);
};

#endif //RUNTIME_SRC_ANALYZERS_JSONANALYZER_H_
