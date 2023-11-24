//
// Created by Даник 💪 on 16.11.2023.
//

#include "include/HandlersMap/HandlersMap.h"
#include "Handlers/Types/StringQuoteHandler.h"
#include "Handlers/Types/CharacterQuoteHandler.h"
#include "Handlers/Types/ShortCommentHandler.h"
#include "Handlers/Types/LongCommentHandler.h"
#include "Handlers/Types/BacktickHandler.h"
#include "Handlers/Types/ThreeDoubleQuoteHandler.h"
#include "Handlers/Types/ThreeQuoteHandler.h"
#include "Handlers/Types/DollarSlashyStringHandler.h"
#include "Handlers/Types/IndentationHandler.h"
#include "Handlers/Types/BraceHandler.h"

HandlersMap::HandlersMap(handlers_list_ptr handlers, handlers_list_ptr required_handlers_for_char) {
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

// Обвязка методов

HandlersMap* handlers_map_new(int tab_in_spaces) {
  ScopeContext context = ScopeContext(false, false, false, false, false, 0, tab_in_spaces);
  handler all_handlers[] = {
      handler(new BraceHandler(0)),
      handler(new StringQuoteHandler()),
      handler(new CharacterQuoteHandler()),
      handler(new ShortCommentHandler()),
      handler(new LongCommentHandler()),
      handler(new BacktickHandler()),
      handler(new ThreeDoubleQuoteHandler()),
      handler(new ThreeQuoteHandler()),
      handler(new DollarSlashyStringHandler())
  };

  handler required_handlers[] = {
      handler(new IndentationHandler(context)),
  };

  std::vector<handler> registered_handlers_vector(std::make_move_iterator(std::begin(all_handlers)),
                                                  std::make_move_iterator(std::end(all_handlers)));

  handlers_list_ptr registered_handlers_ptr = handlers_list_ptr(
      std::make_unique<handlers_list>(std::move(registered_handlers_vector))
  );

  std::vector<handler> required_handlers_vector(std::make_move_iterator(std::begin(required_handlers)),
                                                  std::make_move_iterator(std::end(required_handlers)));

  handlers_list_ptr required_handlers_ptr = handlers_list_ptr(
      std::make_unique<handlers_list>(std::move(required_handlers_vector))
  );

  return new HandlersMap(std::move(registered_handlers_ptr), std::move(required_handlers_ptr));
}

void handlers_map_del(HandlersMap* handlers_map) {
  delete handlers_map;
}