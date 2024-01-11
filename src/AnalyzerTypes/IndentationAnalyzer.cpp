//
// Created by Даник 💪 on 07.11.2023.
//

#include "AnalyzerTypes/IndentationAnalyzer.h"
#include "Handlers/Types/IndentationHandler.h"

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

IndentationAnalyzer::IndentationAnalyzer(const Tokenizer& tokenizer,
                                         handlers_list_ptr handlers,
                                         ScopeContext context)
    : BaseAnalyzer(tokenizer, context, std::move(handlers), getRequiredHandlers(context)) {}

IndentationAnalyzer* IndentationAnalyzer::clone() const {
    return new IndentationAnalyzer(*this);
}
