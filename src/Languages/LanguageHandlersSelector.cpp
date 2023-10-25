//
// Created by Даник 💪 on 24.10.2023.
//

#include "include/Languages/LanguageHandlersSelector.h"
void LanguageHandlersSelector::Add(Language language, handlers_list_ptr handlers) {
  languages_handlers_.insert({language, std::move(handlers)});
}
const handlers_list* LanguageHandlersSelector::Get(Language language) {
  return languages_handlers_.at(language).get();
}
