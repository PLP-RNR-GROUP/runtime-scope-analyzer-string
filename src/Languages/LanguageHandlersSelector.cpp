//
// Created by Даник 💪 on 24.10.2023.
//

#include "LanguageHandlersSelector.h"
void LanguageHandlersSelector::Add(Language language, std::vector<std::unique_ptr<IHandler, IHandler::Deleter>> handlers) {
  languages_handlers_.insert({language, std::move(handlers)});
}
const std::vector<std::unique_ptr<IHandler, IHandler::Deleter>>& LanguageHandlersSelector::Get(Language language) {
  return languages_handlers_[language];
}
