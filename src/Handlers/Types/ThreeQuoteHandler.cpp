//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/ThreeQuoteHandler.h"
std::unique_ptr<Construction> ThreeQuoteHandler::Handle(const Construction& construction, ScopeAnalyzerState& state) {
  if (construction.type == ThreeQuote && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
TryAddConstructionResult ThreeQuoteHandler::TryAddConstructionTo(char character,
                                                                 ConstructionStreamExtractorState& state,
                                                                 std::list<Construction>& constructions) {
  if (character != '\'') return {true};

  if (!state.buffer_.empty() && state.buffer_[0] == '\'' && state.buffer_[1] == '\'') {
    // Remove the last two constructions, as they are guaranteed to be `Quote`.
    constructions.pop_back();
    constructions.pop_back();

    constructions.emplace_back(Undefined, ThreeQuote);
    return {false};
  }

  return {true};
}
