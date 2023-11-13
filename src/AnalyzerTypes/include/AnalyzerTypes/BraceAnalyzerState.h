//
// Created by Даник 💪 on 01.11.2023.
//

#ifndef RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_BRACEANALYZERSTATE_H_
#define RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_BRACEANALYZERSTATE_H_

struct BraceAnalyzerState {
  explicit BraceAnalyzerState() :
    brace_balance(0),
    waiting_for_construction_(nullptr) {}

  int brace_balance;
  std::unique_ptr<Construction> waiting_for_construction_;
};

#endif //RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_BRACEANALYZERSTATE_H_
