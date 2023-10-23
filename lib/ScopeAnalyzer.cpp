//
// Created by Даник 💪 on 09.10.2023.
//

#include <memory>

#include "ScopeAnalyzer/ScopeAnalyzer.h"
#include "Handlers/Types/StringQuoteHandler.h"
#include "Handlers/Types/CharacterQuoteHandler.h"
#include "Handlers/Types/LongCommentHandler.h"
#include "Handlers/Types/ShortCommentHandler.h"

ScopeAnalyzer::ScopeAnalyzer(const std::string& json_vocab, const ScopeContext context) : constructions_extractor_(json_vocab),
                                                                                          state_(ScopeState(0)) {
  waiting_for_construction_ = nullptr;

  handlers_ = std::vector<std::unique_ptr<IHandler, IHandler::Deleter>>();
  handlers_.push_back(std::unique_ptr<StringQuoteHandler, IHandler::Deleter>(new StringQuoteHandler()));
  handlers_.push_back(std::unique_ptr<CharacterQuoteHandler, IHandler::Deleter>(new CharacterQuoteHandler()));
  handlers_.push_back(std::unique_ptr<LongCommentHandler, IHandler::Deleter>(new LongCommentHandler()));
  handlers_.push_back(std::unique_ptr<ShortCommentHandler, IHandler::Deleter>(new ShortCommentHandler()));

  ApplyContext(context);
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
          throw std::invalid_argument("invalid state");
        case Closed:
          --state_.brace_balance;
          break;
        case Opened:
          ++state_.brace_balance;
          break;
      }
      updated_brace_balance = true;
      continue;
    }

    for (const auto& kHandler: handlers_) {
      auto handleResult = kHandler->Handle(construction);
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

void ScopeAnalyzer::ResetState(ScopeContext context) {
  waiting_for_construction_ = nullptr;
  state_.brace_balance = 0;
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
    state_.brace_balance = 1;
  }
}

// Обвязка C для методов C++

ScopeAnalyzer* scope_analyzer_new(const char* json_vocab, ScopeContext* context) {
  return new ScopeAnalyzer(std::string(json_vocab), *context);
}

void apply_context(ScopeAnalyzer* scope_analyzer, ScopeContext* context) {
  scope_analyzer->ResetState(*context);
}

void scope_analyzer_del(ScopeAnalyzer* scope_analyzer) {
  delete scope_analyzer;
}

AddTokenResult add_token(ScopeAnalyzer* scope_analyzer, int32_t token) {
  return scope_analyzer->AddToken(token);
}