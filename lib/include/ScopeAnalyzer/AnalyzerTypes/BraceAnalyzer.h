//
// Created by Даник 💪 on 07.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_

#include "IAnalyzer.h"
#include "Constructions/ConstructionsStreamExtractor.h"
class BraceAnalyzer : public IAnalyzer {
 public:
  BraceAnalyzer(ConstructionsStreamExtractor* constructions_stream_extractor,
                handlers_list_ptr handlers);
  AddTokenResult AddToken(int32_t token) override;

 private:
  ConstructionsStreamExtractor* constructions_stream_extractor_;
  ScopeAnalyzerState state_;
  handlers_list_ptr handlers_;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_
