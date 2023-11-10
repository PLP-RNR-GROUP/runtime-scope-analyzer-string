//
// Created by Даник 💪 on 10.11.2023.
//

#include "Analyzers/CSharpAnalyzer.h"

#include "Handlers/Types/BacktickHandler.h"
#include "Handlers/Types/StringQuoteHandler.h"
#include "Handlers/Types/ShortCommentHandler.h"
#include "Handlers/Types/LongCommentHandler.h"
#include "Handlers/Types/ThreeDoubleQuoteHandler.h"
#include "Handlers/Types/CharacterQuoteHandler.h"

static handlers_list_ptr getHandlersListPtr() {
  handler registered_handlers[] = {
      handler(new StringQuoteHandler()),
      handler(new CharacterQuoteHandler()),
      handler(new ShortCommentHandler()),
      handler(new LongCommentHandler()),
      handler(new BacktickHandler()),
      handler(new ThreeDoubleQuoteHandler())
  };

  std::vector<handler> registered_handlers_vector(std::make_move_iterator(std::begin(registered_handlers)),
                                                  std::make_move_iterator(std::end(registered_handlers)));

  handlers_list_ptr handlers_ptr = handlers_list_ptr(
      std::make_unique<handlers_list>(std::move(registered_handlers_vector))
  );

  return handlers_ptr;
}

CSharpAnalyzer::CSharpAnalyzer(const Tokenizer& tokenizer)
    : BraceAnalyzer(tokenizer, getHandlersListPtr()) {
}
