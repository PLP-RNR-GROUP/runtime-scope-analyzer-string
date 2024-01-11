//
// Created by Даник 💪 on 07.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_

#include "Tokenizers/Tokenizer.h"
#include "BaseAnalyzer.h"

class BraceAnalyzer : public BaseAnalyzer {
 public:
  BraceAnalyzer(const Tokenizer& tokenizer,
                handlers_list_ptr handlers,
                ScopeContext context);

  BraceAnalyzer(const BraceAnalyzer& braceAnalyzer) = default;

  [[nodiscard]] BraceAnalyzer* clone() const override;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_BRACEANALYZER_H_
