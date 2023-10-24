//
// Created by Даник 💪 on 23.10.2023.
//
#include "Handlers/Types/CharacterQuoteHandler.h"

std::unique_ptr<Construction> CharacterQuoteHandler::Handle(const Construction& construction, const ScopeState& state) {
  if (construction.type == CharacterQuote && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
