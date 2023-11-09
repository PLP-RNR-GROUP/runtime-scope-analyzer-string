//
// Created by Даник 💪 on 09.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_JAVAANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_JAVAANALYZER_H_

#include "ScopeAnalyzer/AnalyzerTypes/BraceAnalyzer.h"

class JavaAnalyzer : public BraceAnalyzer {
 public:
  JavaAnalyzer(ConstructionsStreamExtractor* constructions_stream_extractor);
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_JAVAANALYZER_H_
