//
// Created by Даник 💪 on 23.10.2023.
//
#include "Handlers/Types/CharacterQuoteHandler.h"

std::unique_ptr<Construction> CharacterQuoteHandler::Handle(const Construction& construction) {
  if (construction.type == CharacterQuote && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
void CharacterQuoteHandler::TryAddConstructionTo(char character,
                                                 ConstructionStreamExtractorState& state,
                                                 std::list<Construction>& constructions) {
  if (character != '\'') return;
  constructions.push_back(Construction(Undefined, CharacterQuote));
}
