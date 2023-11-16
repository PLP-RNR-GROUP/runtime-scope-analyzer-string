//
// Created by Даник 💪 on 07.11.2023.
//

#include "AnalyzerTypes/BraceAnalyzer.h"
#include "Handlers/Types/BraceHandler.h"

AddTokenResult BraceAnalyzer::AddToken(int32_t token) {
  GetResult get_result = constructions_stream_extractor_.Get(token);
  if (get_result.stop_generation && state_.waiting_for_construction_ == nullptr) {
    return Stop;
  }

  int prev_brace_balance = state_.brace_balance;
  bool updated_brace_balance = false;

  for (const auto& construction : get_result.constructions) {
    if (state_.waiting_for_construction_ != nullptr &&
        state_.waiting_for_construction_->type == construction.type &&
        state_.waiting_for_construction_->state == construction.state) {
      state_.waiting_for_construction_ = nullptr;
      continue;
    }

    auto handlers = handlers_map_.GetHandlersFor(construction);
    if (handlers != nullptr) {
      for (const auto& kHandler : *handlers) {
        auto handleResult = kHandler->Handle(construction, state_.waiting_for_construction_);
        if (prev_brace_balance != state_.brace_balance) updated_brace_balance = true;
        if (handleResult == nullptr) continue;

        state_.waiting_for_construction_ = std::move(handleResult);
      }
    }
  }

  if (updated_brace_balance && state_.brace_balance <= 0) {
    return Stop;
  }
  return Continue;
}

void BraceAnalyzer::ApplyContext(ScopeContext context) {
  if (!context.IsValid()) {
    throw std::invalid_argument("start context is invalid");
  }

  // TODO: Make interface?
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

BraceAnalyzer::BraceAnalyzer(const Tokenizer& tokenizer,
                             handlers_list_ptr handlers,
                             ScopeContext context)
  : handlers_map_(std::move(handlers)),
    constructions_stream_extractor_(tokenizer, handlers_map_){

  handlers_map_.Add(handler(new BraceHandler(state_)));
  ApplyContext(context);
}