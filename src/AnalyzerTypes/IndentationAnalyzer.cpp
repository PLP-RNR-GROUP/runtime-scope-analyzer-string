//
// Created by Даник 💪 on 07.11.2023.
//

#include "AnalyzerTypes/IndentationAnalyzer.h"
#include "Handlers/Types/TabIndentationHandler.h"
#include "Handlers/Types/SpaceIndentationHandler.h"

AddTokenResult IndentationAnalyzer::AddToken(int32_t token) {
  GetResult get_result = constructions_stream_extractor_.Get(token);
  if (get_result.stop_generation) {
    return Stop;
  }

  for (const auto& construction : get_result.constructions) {
    if (state_.waiting_for_construction_ != nullptr) {
      if (construction.type == state_.waiting_for_construction_->type
          && construction.state == state_.waiting_for_construction_->state) {
        state_.waiting_for_construction_ = nullptr;
      }
      continue;
    }

    if (construction.type == ShortComment && construction.state == Closed) {
      state_.current_indentation_level = 0;
      state_.line_no_chars_at_moment = true;
      continue;
    }
    if (state_.line_no_chars_at_moment && (construction.type != TabIndentation && construction.type != SpaceIndentation)) {
      if (state_.line_no_chars_at_moment && state_.current_indentation_level < context_.start_indentation_level) {
        return Stop;
      }

      state_.line_no_chars_at_moment = false;
    }

    for (const auto& kHandler : *handlers_) {
      auto handleResult = kHandler->Handle(construction);
      if (handleResult != nullptr) {
        state_.waiting_for_construction_ = std::move(handleResult);
        break;
      }
    }
  }

  return Continue;
}

IndentationAnalyzer::IndentationAnalyzer(const Tokenizer& tokenizer, handlers_list_ptr handlers, ScopeContext context)
    : IAnalyzer(tokenizer, std::move(handlers), context) {
  handlers_->push_back(handler(new TabIndentationHandler(state_, context.start_indentation_level)));
  handlers_->push_back(handler(new SpaceIndentationHandler(state_, context.start_indentation_level)));
}

void IndentationAnalyzer::ResetState(ScopeContext context, Language language) {

}
void IndentationAnalyzer::ApplyContext(ScopeContext context) {

}
