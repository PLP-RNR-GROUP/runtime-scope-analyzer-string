//
// Created by Даник 💪 on 24.10.2023.
//

#ifndef RUNTIME_SRC_LANGUAGES_LANGUAGEHANDLERSSELECTOR_H_
#define RUNTIME_SRC_LANGUAGES_LANGUAGEHANDLERSSELECTOR_H_

#include <unordered_map>
#include "Language.h"
#include "Handlers/IHandler.h"

class LanguageHandlersSelector {
  LanguageHandlersSelector() = default;
  void Add(Language language, std::vector<std::unique_ptr<IHandler, IHandler::Deleter>> handlers);
  const std::vector<std::unique_ptr<IHandler, IHandler::Deleter>>& Get(Language language);

 private:
  std::unordered_map<Language, std::vector<std::unique_ptr<IHandler, IHandler::Deleter>>> languages_handlers_;
};

#endif //RUNTIME_SRC_LANGUAGES_LANGUAGEHANDLERSSELECTOR_H_
