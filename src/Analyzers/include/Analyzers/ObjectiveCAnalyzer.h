//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_OBJECTIVECANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_OBJECTIVECANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class ObjectiveCAnalyzer : public BraceAnalyzer {
 public:
  explicit ObjectiveCAnalyzer(const Tokenizer& tokenizer, ScopeContext context);
};

#endif //RUNTIME_SRC_ANALYZERS_OBJECTIVECANALYZER_H_
