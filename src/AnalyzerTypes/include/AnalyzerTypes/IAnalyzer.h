//
// Created by Даник 💪 on 06.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_IANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_IANALYZER_H_

#include "Languages/Language.h"
#include "AnalyzerTypes/Results/AddTokenResult.h"
#include "ScopeContext.h"
#include "Handlers/IHandlerList.h"
#include "Tokenizers/Tokenizer.h"
#include "Constructions/ConstructionsStreamExtractor.h"

#include <cstdint>

class IAnalyzer {
 protected:
  virtual void Delete() {
    delete this;
  };
  virtual ~IAnalyzer() = default;

  explicit IAnalyzer() = default;
 public:
  IAnalyzer& operator=(const IAnalyzer&) = delete;

  virtual AddTokenResult AddToken(int32_t token) = 0;

  struct Deleter
  {
    void operator()(IAnalyzer* p) const { p->Delete(); }
  };

  friend struct IAnalyzer::Deleter;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_IANALYZER_H_
