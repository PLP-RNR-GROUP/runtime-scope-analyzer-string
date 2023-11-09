//
// Created by Даник 💪 on 07.11.2023.
//

#include "ScopeAnalyzer/AnalyzerTypes/BraceAnalyzer.h"

AddTokenResult BraceAnalyzer::AddToken(int32_t token) {
  int prev_brace_balance = state_.brace_balance;
  bool updated_brace_balance = false;

  for (const auto& construction : constructions_stream_extractor_->Get(token)) {
    if (state_.waiting_for_construction_ != nullptr) {
      if (construction.type == state_.waiting_for_construction_->type
          && construction.state == state_.waiting_for_construction_->state) {
        state_.waiting_for_construction_ = nullptr;
      }
      continue;
    }

    for (const auto& kHandler: *handlers_) {
      auto handleResult = kHandler->Handle(construction, state_);
      if (prev_brace_balance != state_.brace_balance) updated_brace_balance = true;
      if (handleResult != nullptr) {
        state_.waiting_for_construction_ = std::move(handleResult);
        break;
      }
    }
  }

  if (updated_brace_balance && state_.brace_balance <= 0) {
    return Stop;
  }
  return Continue;
}

BraceAnalyzer::BraceAnalyzer(ConstructionsStreamExtractor* constructions_stream_extractor,
                             handlers_list_ptr handlers) :
                             constructions_stream_extractor_(constructions_stream_extractor),
                             handlers_(std::move(handlers)) {};