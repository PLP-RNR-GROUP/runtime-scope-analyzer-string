//
// Created by Даник 💪 on 07.11.2023.
//

#include "AnalyzerTypes/BraceAnalyzer.h"
#include "Handlers/Types/BraceHandler.h"

AddTokenResult BraceAnalyzer::AddToken(int32_t token) {
  int prev_brace_balance = state_.brace_balance;
  bool updated_brace_balance = false;

  for (const auto& construction : constructions_stream_extractor_.Get(token)) {
    if (state_.waiting_for_construction_ != nullptr) {
      if (construction.type == state_.waiting_for_construction_->type
          && construction.state == state_.waiting_for_construction_->state) {
        state_.waiting_for_construction_ = nullptr;
      }
      continue;
    }

    for (const auto& kHandler: *handlers_) {
      auto handleResult = kHandler->Handle(construction);
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

void BraceAnalyzer::ResetState(ScopeContext context, Language language) {
  ApplyContext(context);
}

void BraceAnalyzer::ApplyContext(ScopeContext context) {
  if (context.in_character + context.in_long_comment + context.in_short_comment + context.in_string > 1) {
    throw std::invalid_argument("start context is invalid");
  }

  // TODO: Make interface
  if (context.in_character) {
    state_.waiting_for_construction_ = std::make_unique<Construction>(
        Undefined,
        Quote);
  }
  else if (context.in_string) {
    state_.waiting_for_construction_ = std::make_unique<Construction>(
        Undefined,
        DoubleQuote
    );
  }
  else if (context.in_short_comment) {
    state_.waiting_for_construction_ = std::make_unique<Construction>(
        Closed,
        ShortComment
    );
  }
  else if (context.in_long_comment) {
    state_.waiting_for_construction_ = std::make_unique<Construction>(
        Closed,
        LongComment
    );
  }

  if (context.scope_opened) {
    state_.brace_balance = 1;
  }
}

BraceAnalyzer::BraceAnalyzer(const Tokenizer& tokenizer, handlers_list_ptr handlers)
  : IAnalyzer(tokenizer, std::move(handlers), ScopeContext(false, false, false, false, false, 0)) {
  handlers_->push_back(handler(new BraceHandler(state_)));
};