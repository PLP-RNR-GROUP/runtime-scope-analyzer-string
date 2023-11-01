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
#include "Handlers/Types/ThreeDoubleQuoteHandler.h"

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
    auto three_double_quote_handler = handler(new ThreeDoubleQuoteHandler());

    std::vector<handler> base_handlers = {
        string_quote_handler,
        character_quote_handler,
        short_comment_handler,
        long_comment_handler,
        brace_handler
    };

    std::vector<handler> java_handlers(base_handlers);
    Add(Java, handlers_list_ptr(std::make_unique<handlers_list>(std::move(java_handlers))));

    std::vector<handler> javascript_handlers(base_handlers);
    javascript_handlers.push_back(backtick_handler);
    Add(Javascript, handlers_list_ptr(std::make_unique<handlers_list>(std::move(javascript_handlers))));

    std::vector<handler> objc_handlers(base_handlers);
    Add(ObjectiveC, handlers_list_ptr(std::make_unique<handlers_list>(std::move(objc_handlers))));

    std::vector<handler> go_handlers(base_handlers);
    go_handlers.push_back(backtick_handler);

    Add(Go, handlers_list_ptr(std::make_unique<handlers_list>(std::move(go_handlers))));

    std::vector<handler> csharp_handlers(base_handlers);
    csharp_handlers.push_back(backtick_handler);
    csharp_handlers.push_back(three_double_quote_handler);

    Add(CSharp, handlers_list_ptr(std::make_unique<handlers_list>(std::move(csharp_handlers))));

    std::vector<handler> kotlin_handlers(base_handlers);
    kotlin_handlers.push_back(backtick_handler);
    kotlin_handlers.push_back(three_double_quote_handler);

    Add(Kotlin, handlers_list_ptr(std::make_unique<handlers_list>(std::move(kotlin_handlers))));

    std::vector<handler> scala_handlers(base_handlers);
    scala_handlers.push_back(backtick_handler);
    scala_handlers.push_back(three_double_quote_handler);

    Add(Scala, handlers_list_ptr(std::make_unique<handlers_list>(std::move(scala_handlers))));

    std::vector<handler> swift_handlers(base_handlers);
    swift_handlers.push_back(backtick_handler);
    swift_handlers.push_back(three_double_quote_handler);

    Add(Swift, handlers_list_ptr(std::make_unique<handlers_list>(std::move(swift_handlers))));

    std::vector<handler> json_handlers {
      brace_handler,
      string_quote_handler,
      long_comment_handler,
      short_comment_handler
    };

    Add(Json, handlers_list_ptr(std::make_unique<handlers_list>(std::move(json_handlers))));

//    TODO: later
//    assert(languages_handlers_.size() == languages_amount);
  };

  void Add(Language language, handlers_list_ptr handlers);
  const handlers_list* Get(Language language);

 private:
  std::unordered_map<Language, handlers_list_ptr> languages_handlers_;
};

#endif //RUNTIME_SRC_LANGUAGES_LANGUAGEHANDLERSSELECTOR_H_
