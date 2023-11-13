//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/StringQuoteHandler.h"

std::unique_ptr<Construction> StringQuoteHandler::Handle(const Construction& construction) {
  if (construction.type == DoubleQuote && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
TryAddConstructionResult StringQuoteHandler::TryAddConstructionTo(char character,
                                                                  ConstructionStreamExtractorState& state,
                                                                  std::list<Construction>& constructions) {
  if (character != '"') return {true};
  if (!state.buffer_.empty() && state.buffer_[0] == '\\') return {false};

  constructions.emplace_back(Undefined, DoubleQuote);
  return {true};
}
