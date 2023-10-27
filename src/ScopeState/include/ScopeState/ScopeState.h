//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_SCOPESTATE_INCLUDE_SCOPESTATE_SCOPESTATE_H_
#define RUNTIME_SRC_SCOPESTATE_INCLUDE_SCOPESTATE_SCOPESTATE_H_

#include <memory>

struct ScopeState {
  explicit ScopeState(int brace_balance)
      : brace_balance(brace_balance) {
  }

  int brace_balance;
};

#endif //RUNTIME_SRC_SCOPESTATE_INCLUDE_SCOPESTATE_SCOPESTATE_H_
