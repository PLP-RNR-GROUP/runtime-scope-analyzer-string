//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/ThreeQuoteHandler.h"
std::unique_ptr<Construction> ThreeQuoteHandler::Handle(const Construction& construction) {
  if (construction.type == ThreeQuote && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
TryAddConstructionResult ThreeQuoteHandler::TryAddConstructionTo(char character,
                                                                 ConstructionStreamExtractorState& state,
                                                                 std::list<Construction>& constructions) {
  if (character != '\'') return {true, false};

  if (state.buffer_.size() >= 2 && state.buffer_[0] == '\'' && state.buffer_[1] == '\'') {
    if (!constructions.empty() && constructions.back().type == Quote) {
      constructions.pop_back();
    }

    constructions.emplace_back(Undefined, ThreeQuote);
    return {false, false};
  }

  return {true, false};
}
