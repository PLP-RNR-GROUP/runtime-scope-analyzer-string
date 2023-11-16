//
// Created by Даник 💪 on 16.11.2023.
//

#include "Handlers/HandlersMap.h"
HandlersMap::HandlersMap(handlers_list_ptr handlers) {
  handlers_ = std::move(handlers);

  for (auto& handler: *handlers_) {
    Add(std::move(handler));
  }
}

std::list<IHandler*> HandlersMap::GetHandlersFor(char character) const {
  auto result = handlers_map_.find(character);
  if (result == handlers_map_.end()) {
    return {};
  }

  return result->second;
}

void HandlersMap::Add(handler handler) {
  for (char character:handler->GetHandlingText()) {
    if (handlers_map_.find(character) == handlers_map_.end()) {
      handlers_map_.insert(std::make_pair(character, std::list<IHandler*>()));
    }

    handlers_map_[character].emplace_back(handler.get());
  }
}
