//
// Created by Даник 💪 on 01.11.2023.
//

#include "Handlers/Types/BacktickHandler.h"
std::unique_ptr<Construction> BacktickHandler::Handle(const Construction& construction, ScopeAnalyzerState& state) {
  if (construction.type == Backtick && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
TryAddConstructionResult BacktickHandler::TryAddConstructionTo(char character,
                                                               ConstructionStreamExtractorState& state,
                                                               std::list<Construction>& constructions) {
  if (character != '`') return {true};
  if (!state.buffer_.empty() && state.buffer_[0] == '\\') return {false};

  constructions.emplace_back(Undefined, Backtick);
  return {true};
}
