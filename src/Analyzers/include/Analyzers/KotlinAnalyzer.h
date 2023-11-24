//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_KOTLINANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_KOTLINANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class KotlinAnalyzer : public BraceAnalyzer {
 public:
  explicit KotlinAnalyzer(const Tokenizer& tokenizer, ScopeContext context);
};

#endif //RUNTIME_SRC_ANALYZERS_KOTLINANALYZER_H_
