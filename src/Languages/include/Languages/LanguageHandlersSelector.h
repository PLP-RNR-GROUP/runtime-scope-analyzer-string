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

    Add(Java, handlers_list_ptr(std::make_unique<const std::vector<handler>>(std::move(javaHandlers))));

//    TODO: later
//    assert(languages_handlers_.size() == languages_amount);
  };

  void Add(Language language, handlers_list_ptr handlers);
  const handlers_list* Get(Language language);

 private:
  std::unordered_map<Language, handlers_list_ptr> languages_handlers_;
};

#endif //RUNTIME_SRC_LANGUAGES_LANGUAGEHANDLERSSELECTOR_H_
