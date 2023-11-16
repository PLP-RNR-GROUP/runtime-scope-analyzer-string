//
// Created by Даник 💪 on 07.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_

#include "IAnalyzer.h"
#include "Constructions/ConstructionsStreamExtractor.h"
#include "IndentationAnalyzerState.h"

class IndentationAnalyzer : public IAnalyzer {
 public:
  IndentationAnalyzer(
                const Tokenizer& tokenizer,
                handlers_list_ptr handlers,
                ScopeContext context);
  AddTokenResult AddToken(int32_t token) override;
 private:
  void ApplyContext(ScopeContext context);

  IndentationAnalyzerState state_;
  HandlersMap handlers_map_;
  ConstructionsStreamExtractor constructions_stream_extractor_;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_INDENTATIONANALYZER_H_
