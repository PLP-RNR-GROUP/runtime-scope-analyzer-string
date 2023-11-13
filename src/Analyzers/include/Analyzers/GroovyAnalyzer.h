//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_GROOVYANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_GROOVYANALYZER_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class GroovyAnalyzer : public BraceAnalyzer {
 public:
  explicit GroovyAnalyzer(const Tokenizer& tokenizer, ScopeContext context);
};

#endif //RUNTIME_SRC_ANALYZERS_GROOVYANALYZER_H_
