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
    std::vector<handler> javaHandlers;
    javaHandlers.push_back(handler(new StringQuoteHandler()));
    javaHandlers.push_back(handler(new CharacterQuoteHandler()));
    javaHandlers.push_back(handler(new ShortCommentHandler()));
    javaHandlers.push_back(handler(new LongCommentHandler()));
    javaHandlers.push_back(handler(new BraceHandler()));

    Add(Java, handlers_list_ptr(std::make_unique<handlers_list>(std::move(javaHandlers))));

    std::vector<handler> javascriptHandlers;
    javascriptHandlers.push_back(handler(new StringQuoteHandler()));
    javascriptHandlers.push_back(handler(new CharacterQuoteHandler()));
    javascriptHandlers.push_back(handler(new ShortCommentHandler()));
    javascriptHandlers.push_back(handler(new LongCommentHandler()));
    javascriptHandlers.push_back(handler(new BraceHandler()));
    javascriptHandlers.push_back(handler(new BacktickHandler()));

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
