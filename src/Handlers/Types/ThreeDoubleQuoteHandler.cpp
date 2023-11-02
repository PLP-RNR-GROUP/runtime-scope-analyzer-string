//
// Created by Даник 💪 on 01.11.2023.
//

#include "Handlers/Types/ThreeDoubleQuoteHandler.h"
std::unique_ptr<Construction> ThreeDoubleQuoteHandler::Handle(const Construction& construction,
                                                              ScopeAnalyzerState& state) {
  if (construction.type == ThreeDoubleQuote && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
TryAddConstructionResult ThreeDoubleQuoteHandler::TryAddConstructionTo(char character,
                                                                       ConstructionStreamExtractorState& state,
                                                                       std::list<Construction>& constructions) {
  if (character != '"') return {true};

  if (!state.buffer_.empty() && state.buffer_[0] == '"' && state.buffer_[1] == '"') {
    // Remove the last two constructions, as they are guaranteed to be `DoubleQuote`.
    constructions.pop_back();
    constructions.pop_back();

    constructions.emplace_back(Undefined, ThreeDoubleQuote);
    return {false};
  }

  return {true};
}