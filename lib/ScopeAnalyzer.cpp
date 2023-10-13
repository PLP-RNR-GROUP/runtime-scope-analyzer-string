//
// Created by Даник 💪 on 09.10.2023.
//

#include "ScopeAnalyzer/ScopeAnalyzer.h"

ScopeAnalyzer::ScopeAnalyzer(std::ifstream& vocabFile) : constructions_extractor_(vocabFile) {
  waiting_for_construction_ = nullptr;
  brace_balance = 0;
}

AddTokenResult ScopeAnalyzer::AddToken(int32_t token) {
  bool updated_brace_balance = false;
  for (const auto& construction : constructions_extractor_.Get(token)) {
    if (waiting_for_construction_ != nullptr) {
      if (construction.type == waiting_for_construction_->type
          && construction.state == waiting_for_construction_->state) {
        waiting_for_construction_ = nullptr;
      }
      continue;
    }

    if (construction.type == Brace) {
      switch (construction.state) {
        case Undefined:
          // TODO:
          throw std::runtime_error("invalid state");
        case Closed:
          --brace_balance;
          break;
        case Opened:
          ++brace_balance;
          break;
      }
      updated_brace_balance = true;
      continue;
    }

    if (construction.state == Opened) {
      Construction next_waiting_construction = Construction();
      next_waiting_construction.state = Closed;
      next_waiting_construction.type = construction.type;
      waiting_for_construction_ = std::make_unique<Construction>(next_waiting_construction);
      continue;
    }

    if (construction.type == Quote && construction.state == Undefined) {
      waiting_for_construction_ = std::make_unique<Construction>(Construction(construction));
      continue;
    }
  }

  if (updated_brace_balance && brace_balance <= 0) {
    return Stop;
  }
  return Continue;
}
