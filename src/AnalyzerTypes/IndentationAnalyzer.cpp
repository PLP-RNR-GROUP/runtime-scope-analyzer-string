//
// Created by Даник 💪 on 07.11.2023.
//

#include "AnalyzerTypes/IndentationAnalyzer.h"
#include "Handlers/Types/IndentationHandler.h"

AddTokenResult IndentationAnalyzer::AddToken(int32_t token) {
  GetResult get_result = constructions_stream_extractor_.Get(token);
  if (get_result.stop_generation && state_.waiting_for_construction_ == nullptr) {
    return Stop;
  }

  for (const auto& construction : get_result.constructions) {
    if (state_.waiting_for_construction_ != nullptr &&
        state_.waiting_for_construction_->type == construction.type &&
        state_.waiting_for_construction_->state == construction.state) {
      state_.waiting_for_construction_ = nullptr;
      continue;
    }

    for (const auto& kHandler : handlers_map_.GetHandlersFor(construction)) {
      auto handleResult = kHandler->Handle(construction, state_.waiting_for_construction_);
      if (handleResult.result == Stop) {
        return Stop;
      }

      if (handleResult.construction != nullptr) {
        state_.waiting_for_construction_ = std::move(handleResult.construction);
      }
    }
  }

  return Continue;
}

static handlers_list_ptr getRequiredHandlers(ScopeContext context) {
  handler registered_handlers[] = {
      handler(new IndentationHandler(context))
  };

  std::vector<handler> registered_handlers_vector(std::make_move_iterator(std::begin(registered_handlers)),
                                                  std::make_move_iterator(std::end(registered_handlers)));

  handlers_list_ptr handlers_ptr = handlers_list_ptr(
      std::make_unique<handlers_list>(std::move(registered_handlers_vector))
  );

  return handlers_ptr;
}

IndentationAnalyzer::IndentationAnalyzer(const Tokenizer& tokenizer, handlers_list_ptr handlers, ScopeContext context)
    : handlers_map_(std::move(handlers), getRequiredHandlers(context)),
      constructions_stream_extractor_(tokenizer, handlers_map_) {
  ApplyContext(context);
}

void IndentationAnalyzer::ApplyContext(ScopeContext context) {
  if (!context.IsValid()) {
    throw std::invalid_argument("start context is invalid");
  }

  // TODO: Make interface?
  if (context.in_character) {
    state_.waiting_for_construction_ = std::make_unique<Construction>(
        Undefined,
        Quote);
  } else if (context.in_string) {
    state_.waiting_for_construction_ = std::make_unique<Construction>(
        Undefined,
        DoubleQuote
    );
  } else if (context.in_short_comment) {
    state_.waiting_for_construction_ = std::make_unique<Construction>(
        Closed,
        ShortComment
    );
  } else if (context.in_long_comment) {
    state_.waiting_for_construction_ = std::make_unique<Construction>(
        Closed,
        LongComment
    );
  }
}
