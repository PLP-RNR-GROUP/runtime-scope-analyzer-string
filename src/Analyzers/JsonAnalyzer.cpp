//
// Created by Даник 💪 on 10.11.2023.
//

#include "Analyzers/JsonAnalyzer.h"

#include "Handlers/Types/BacktickHandler.h"
#include "Handlers/Types/StringQuoteHandler.h"

static handlers_list_ptr getHandlersListPtr() {
  handler registered_handlers[] = {
      handler(new BacktickHandler()),
      handler(new StringQuoteHandler()),
  };

  std::vector<handler> registered_handlers_vector(std::make_move_iterator(std::begin(registered_handlers)),
                                                  std::make_move_iterator(std::end(registered_handlers)));

  handlers_list_ptr handlers_ptr = handlers_list_ptr(
      std::make_unique<handlers_list>(std::move(registered_handlers_vector))
  );

  return handlers_ptr;
}

JsonAnalyzer::JsonAnalyzer(const Tokenizer& tokenizer, ScopeContext context)
    : BraceAnalyzer(tokenizer, getHandlersListPtr(), context) {

}
