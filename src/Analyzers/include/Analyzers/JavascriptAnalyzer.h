//
// Created by Даник 💪 on 10.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERS_JAVASCRIPTANALYZERS_H_
#define RUNTIME_SRC_ANALYZERS_JAVASCRIPTANALYZERS_H_

#include "AnalyzerTypes/BraceAnalyzer.h"

class JavascriptAnalyzer : public BraceAnalyzer {
 public:
  explicit JavascriptAnalyzer(const Tokenizer& tokenizer);
};

#endif //RUNTIME_SRC_ANALYZERS_JAVASCRIPTANALYZERS_H_
