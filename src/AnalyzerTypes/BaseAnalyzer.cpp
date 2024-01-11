//
// Created by Даник 💪 on 21.11.2023.
//

#include "AnalyzerTypes/BaseAnalyzer.h"
AddTokenResult BaseAnalyzer::AddToken(int32_t token) {
  GetResult get_result = constructions_stream_extractor_.Get(token);
  if (get_result.stop_generation && waiting_for_construction_ == nullptr) {
    return Stop;
  }

  for (const auto& construction : get_result.constructions) {
    if (waiting_for_construction_ != nullptr &&
        *waiting_for_construction_ == construction) {
      waiting_for_construction_ = nullptr;
      continue;
    }

    for (const auto& kHandler : handlers_map_.GetHandlersFor(construction)) {
      auto handleResult = kHandler->Handle(construction, waiting_for_construction_);
      if (handleResult.result == Stop) {
        return Stop;
      }

      if (handleResult.construction != nullptr) {
        waiting_for_construction_ = std::move(handleResult.construction);
      }
    }
  }

  return Continue;
}
BaseAnalyzer::BaseAnalyzer(const Tokenizer& tokenizer,
                           ScopeContext context,
                           handlers_list_ptr handlers,
                           handlers_list_ptr required_handlers)
    : handlers_map_(std::move(handlers), std::move(required_handlers))
    , constructions_stream_extractor_(tokenizer, handlers_map_){
  ApplyContext(context);
}

BaseAnalyzer::BaseAnalyzer(const BaseAnalyzer& baseAnalyzer)
    : handlers_map_(baseAnalyzer.handlers_map_)
    , waiting_for_construction_(baseAnalyzer.waiting_for_construction_
                                ? new Construction(*baseAnalyzer.waiting_for_construction_)
                                : nullptr)
    , constructions_stream_extractor_(baseAnalyzer.constructions_stream_extractor_) {}

BaseAnalyzer* BaseAnalyzer::clone() const {
    return new BaseAnalyzer(*this);
}

void BaseAnalyzer::ApplyContext(ScopeContext context) {
  if (!context.IsValid()) throw std::invalid_argument("context is invalid");

  if (context.in_character) {
    waiting_for_construction_ = std::make_unique<Construction>(Quote);
  } else if (context.in_string) {
    waiting_for_construction_ = std::make_unique<Construction>(DoubleQuote);
  } else if (context.in_short_comment) {
    waiting_for_construction_ = std::make_unique<Construction>(ClosedShortComment);
  } else if (context.in_long_comment) {
    waiting_for_construction_ = std::make_unique<Construction>(ClosedLongComment);
  }
}