//
// Created by Даник 💪 on 09.10.2023.
//

#include <memory>

#include "ScopeAnalyzer/ScopeAnalyzer.h"
#include "ScopeAnalyzer/AnalyzerTypes/BraceAnalyzer.h"
#include "ScopeAnalyzer/AnalyzerTypes/IndentationAnalyzer.h"

ScopeAnalyzer::ScopeAnalyzer(
    const std::string& json_vocab, ScopeContext context, Language selected_language){
  constructions_stream_extractor_ = std::make_unique<ConstructionsStreamExtractor>(json_vocab, handlers_);

  ResetState(context, selected_language);
}

void ScopeAnalyzer::ResetState(ScopeContext context, Language language) {
  handlers_ = handlers_selector_.Get(language);
  constructions_stream_extractor_->UpdateHandlers(handlers_);
  ApplyContext(context);

  if (language == Python) {
    analyzer_ = std::unique_ptr<IAnalyzer, IAnalyzer::Deleter>(
        new IndentationAnalyzer(
            constructions_stream_extractor_.get(),
            state_,
            handlers_));
  } else {
    analyzer_ = std::unique_ptr<IAnalyzer, IAnalyzer::Deleter>(
        new BraceAnalyzer(
            constructions_stream_extractor_.get(),
            state_,
            handlers_));
  }
}

void ScopeAnalyzer::ApplyContext(ScopeContext context) {
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

int ScopeAnalyzer::GetBraceBalance() const {
  return state_.brace_balance;
}

const Construction* ScopeAnalyzer::GetWaitingForConstruction() const {
  return state_.waiting_for_construction_.get();
}

AddTokenResult ScopeAnalyzer::AddToken(int32_t token) {
  return analyzer_->AddToken(token);
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