//
// Created by Даник 💪 on 16.11.2023.
//

#include "Handlers/HandlersMap.h"

HandlersMap::HandlersMap(handlers_list_ptr handlers, handlers_list_ptr required_handlers_for_char) {
  empty_handlers_list_ = std::list<IHandler*>();

  if (required_handlers_for_char != nullptr) {
    handlers_ = std::move(required_handlers_for_char);
  } else {
    handlers_ = std::make_unique<handlers_list>();
  }

  required_handlers_for_char_ = std::list<IHandler*>();
  for (const auto& h: *handlers_) {
    required_handlers_for_char_.emplace_back(h.get());
  }

  for (auto& handler: *handlers) {
    Add(std::move(handler));
  }
}

const std::list<IHandler*>& HandlersMap::GetHandlersFor(char character) const {
  auto result = char_handlers_map_.find(character);
  if (result == char_handlers_map_.end()) {
    return required_handlers_for_char_;
  }

  return result->second;
}

const std::list<IHandler*>& HandlersMap::GetHandlersFor(Construction construction) const {
  auto result = construction_handlers_map_.find(construction);
  if (result == construction_handlers_map_.end()) {
    return empty_handlers_list_;
  }

  return result->second;
}

void HandlersMap::Add(handler handler) {
  handlers_->emplace_back(std::move(handler));
  auto& current_handler = handlers_->back();

  for (char character: current_handler->GetHandlingText()) {
    if (char_handlers_map_.find(character) == char_handlers_map_.end()) {
      char_handlers_map_.insert(std::make_pair(character, std::list<IHandler*>(required_handlers_for_char_)));
    }

    char_handlers_map_[character].emplace_back(current_handler.get());
  }

  for (Construction construction: current_handler->GetHandlingConstructions()) {
    if (construction_handlers_map_.find(construction) == construction_handlers_map_.end()) {
      construction_handlers_map_.insert(std::make_pair(construction, std::list<IHandler*>()));
    }

    construction_handlers_map_[construction].emplace_back(current_handler.get());
  }
}
