//
// Created by Даник 💪 on 09.10.2023.
//

#include <memory>

#include "ScopeAnalyzer/ScopeAnalyzer.h"

ScopeAnalyzer::ScopeAnalyzer(const std::string& json_vocab, ScopeContext context, Language selected_language){
  waiting_for_construction_ = nullptr;

  handlers_ = handlers_selector_.Get(selected_language);
  // TODO: put on stack
  constructions_stream_extractor_ = std::make_unique<ConstructionsStreamExtractor>(json_vocab, handlers_);

  ApplyContext(context);
}

AddTokenResult ScopeAnalyzer::AddToken(int32_t token) {
  int prev_brace_balance = state_.brace_balance;
  bool updated_brace_balance = false;

  for (const auto& construction : constructions_stream_extractor_->Get(token)) {
    if (waiting_for_construction_ != nullptr) {
      if (construction.type == waiting_for_construction_->type
          && construction.state == waiting_for_construction_->state) {
        waiting_for_construction_ = nullptr;
      }
      continue;
    }


    for (const auto& kHandler: *handlers_) {
      auto handleResult = kHandler->Handle(construction, state_);
      if (prev_brace_balance != state_.brace_balance) updated_brace_balance = true;
      if (handleResult != nullptr) {
        waiting_for_construction_ = std::move(handleResult);
        break;
      }
    }
  }

  if (updated_brace_balance && state_.brace_balance <= 0) {
    return Stop;
  }
  return Continue;
}

void ScopeAnalyzer::ResetState(ScopeContext context, Language language) {
  waiting_for_construction_ = nullptr;
  state_.brace_balance = 0;
  handlers_ = handlers_selector_.Get(language);
  constructions_stream_extractor_->UpdateHandlers(handlers_);
  ApplyContext(context);
}

void ScopeAnalyzer::ApplyContext(ScopeContext context) {
  if (context.in_character + context.in_long_comment + context.in_short_comment + context.in_string > 1) {
    throw std::invalid_argument("start context is invalid");
  }

  // TODO: Make interface
  if (context.in_character) {
    waiting_for_construction_ = std::make_unique<Construction>(
        Undefined,
        Quote);
  }
  else if (context.in_string) {
    waiting_for_construction_ = std::make_unique<Construction>(
        Undefined,
        DoubleQuote
    );
  }
  else if (context.in_short_comment) {
    waiting_for_construction_ = std::make_unique<Construction>(
        Closed,
        ShortComment
    );
  }
  else if (context.in_long_comment) {
    waiting_for_construction_ = std::make_unique<Construction>(
        Closed,
        LongComment
    );
  }

  if (context.scope_opened) {
    state_.brace_balance = 1;
  }
}
int ScopeAnalyzer::GetBraceBalance() const {
  return state_.brace_balance;
}
const Construction* ScopeAnalyzer::GetWaitingForConstruction() const {
  return waiting_for_construction_.get();
}

// Обвязка C для методов C++

ScopeAnalyzer* scope_analyzer_new(const char* json_vocab, ScopeContext* context, Language selected_language) {
  return new ScopeAnalyzer(std::string(json_vocab), *context, selected_language);
}

void reset(ScopeAnalyzer* scope_analyzer, ScopeContext* context, Language language) {
  scope_analyzer->ResetState(*context, language);
}

void scope_analyzer_del(ScopeAnalyzer* scope_analyzer) {
  delete scope_analyzer;
}

AddTokenResult add_token(ScopeAnalyzer* scope_analyzer, int32_t token) {
  return scope_analyzer->AddToken(token);
}

int get_brace_balance(ScopeAnalyzer* scope_analyzer) {
  return scope_analyzer->GetBraceBalance();
}

const Construction* get_waiting_for_construction(ScopeAnalyzer* scope_analyzer) {
  return scope_analyzer->GetWaitingForConstruction();
}