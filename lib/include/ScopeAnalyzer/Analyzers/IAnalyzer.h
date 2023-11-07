//
// Created by Даник 💪 on 06.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_IANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_IANALYZER_H_

#include "ScopeAnalyzer/Results/AddTokenResult.h"
#include <cstdint>

class IAnalyzer {
 protected:
  IAnalyzer() = default;
  virtual void Delete() {
    delete this;
  };
  virtual ~IAnalyzer() = default;

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
