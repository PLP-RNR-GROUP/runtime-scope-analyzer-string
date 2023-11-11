//
// Created by Даник 💪 on 11.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_PYTHONANALYZER_H_
#define RUNTIME_SRC_ANALYZERS_PYTHONANALYZER_H_

#include "AnalyzerTypes/IndentationAnalyzer.h"

class PythonAnalyzer : public IndentationAnalyzer {
 public:
  PythonAnalyzer(const Tokenizer& tokenizer, const ScopeContext& context);
};

#endif //RUNTIME_SRC_ANALYZERS_PYTHONANALYZER_H_
