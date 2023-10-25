//
// Created by Даник 💪 on 24.10.2023.
//

#include "include/Languages/LanguageHandlersSelector.h"
void LanguageHandlersSelector::Add(Language language, HandlersList handlers) {
  languages_handlers_.insert({language, std::move(handlers)});
}
const HandlersList* LanguageHandlersSelector::Get(Language language) {
  return &languages_handlers_.at(language);
}
