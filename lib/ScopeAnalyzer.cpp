//
// Created by Даник 💪 on 09.10.2023.
//

#include "ScopeAnalyzer/ScopeAnalyzer.h"

ScopeAnalyzer::ScopeAnalyzer(const std::string& json_vocab, const StartContext context) : constructions_extractor_(json_vocab) {
  waiting_for_construction_ = nullptr;
  brace_balance = 0;

  if (context.in_character + context.in_long_comment + context.in_short_comment + context.in_string > 1) {
    throw std::invalid_argument("start context is invalid");
  }

  if (context.in_character) {
    waiting_for_construction_ = std::make_unique<Construction>(
        Undefined,
        CharacterQuote);
  }
  else if (context.in_string) {
    waiting_for_construction_ = std::make_unique<Construction>(
        Undefined,
        StringQuote
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
    brace_balance = 1;
  }
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
      waiting_for_construction_ = std::make_unique<Construction>(Construction(Closed, construction.type));
      continue;
    }

    if (construction.type == StringQuote || construction.type == CharacterQuote) {
      waiting_for_construction_ = std::make_unique<Construction>(Construction(construction));
      continue;
    }
  }

  if (updated_brace_balance && brace_balance <= 0) {
    return Stop;
  }
  return Continue;
}

// Обвязка C для методов C++

ScopeAnalyzer* scope_analyzer_new(const char* json_vocab, StartContext* context) {
  return new ScopeAnalyzer(std::string(json_vocab), *context);
}

void scope_analyzer_del(ScopeAnalyzer* scope_analyzer) {
  delete scope_analyzer;
}

AddTokenResult add_token(ScopeAnalyzer* scope_analyzer, int32_t token) {
  return scope_analyzer->AddToken(token);
}