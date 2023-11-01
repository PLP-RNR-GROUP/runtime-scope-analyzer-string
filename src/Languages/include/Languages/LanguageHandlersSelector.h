//
// Created by Даник 💪 on 24.10.2023.
//

#ifndef RUNTIME_SRC_LANGUAGES_LANGUAGEHANDLERSSELECTOR_H_
#define RUNTIME_SRC_LANGUAGES_LANGUAGEHANDLERSSELECTOR_H_

#include "Language.h"
#include "Handlers/IHandler.h"
#include "Handlers/Types/StringQuoteHandler.h"
#include "Handlers/Types/CharacterQuoteHandler.h"
#include "Handlers/Types/ShortCommentHandler.h"
#include "Handlers/Types/LongCommentHandler.h"
#include "Handlers/IHandlerList.h"
#include "Handlers/Types/BraceHandler.h"
#include "Handlers/Types/BacktickHandler.h"

#include <vector>
#include <unordered_map>

class LanguageHandlersSelector {
 public:
  LanguageHandlersSelector() {
    auto string_quote_handler = handler(new StringQuoteHandler());
    auto character_quote_handler = handler(new CharacterQuoteHandler());
    auto short_comment_handler = handler(new ShortCommentHandler());
    auto long_comment_handler = handler(new LongCommentHandler());
    auto brace_handler = handler(new BraceHandler());
    auto backtick_handler = handler(new BacktickHandler());

    std::vector<handler> base_handlers = {
        string_quote_handler,
        character_quote_handler,
        short_comment_handler,
        long_comment_handler,
        brace_handler
    };

    std::vector<handler> javaHandlers(base_handlers);
    Add(Java, handlers_list_ptr(std::make_unique<handlers_list>(std::move(javaHandlers))));

    std::vector<handler> javascriptHandlers(base_handlers);
    javascriptHandlers.push_back(backtick_handler);

    Add(Javascript, handlers_list_ptr(std::make_unique<handlers_list>(std::move(javascriptHandlers))));


//    TODO: later
//    assert(languages_handlers_.size() == languages_amount);
  };

  void Add(Language language, handlers_list_ptr handlers);
  const handlers_list* Get(Language language);

 private:
  std::unordered_map<Language, handlers_list_ptr> languages_handlers_;
};

#endif //RUNTIME_SRC_LANGUAGES_LANGUAGEHANDLERSSELECTOR_H_
