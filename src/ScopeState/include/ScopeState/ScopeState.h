//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_SCOPESTATE_INCLUDE_SCOPESTATE_SCOPESTATE_H_
#define RUNTIME_SRC_SCOPESTATE_INCLUDE_SCOPESTATE_SCOPESTATE_H_

#include <memory>

struct ScopeState {
  explicit ScopeState(int brace_balance)
      : brace_balance(brace_balance) {
    prev_char = '\0';
  }

  int brace_balance;
  char prev_char;
};

#endif //RUNTIME_SRC_SCOPESTATE_INCLUDE_SCOPESTATE_SCOPESTATE_H_
