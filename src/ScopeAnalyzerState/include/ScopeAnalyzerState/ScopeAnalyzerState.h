//
// Created by Даник 💪 on 01.11.2023.
//

#ifndef RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_SCOPEANALYZERSTATE_H_
#define RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_SCOPEANALYZERSTATE_H_

struct ScopeAnalyzerState {
  explicit ScopeAnalyzerState() : brace_balance(0) {}
  int brace_balance;
};

#endif //RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_SCOPEANALYZERSTATE_H_