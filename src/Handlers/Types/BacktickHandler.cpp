//
// Created by Даник 💪 on 01.11.2023.
//

#include "Handlers/Types/BacktickHandler.h"
HandleResult BacktickHandler::Handle(const Construction& construction,
                                     const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};
  if (construction == Backtick) {
    return {std::make_unique<Construction>(construction), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult BacktickHandler::TryAddConstructionTo(char character,
                                                               const ConstructionStreamExtractorState& state,
                                                               std::list<Construction>& constructions) {
  if (character != '`') return {true, false};
  if (!state.buffer_.empty() && state.buffer_[0] == '\\') return {false, false};

  constructions.emplace_back(Backtick);
  return {false, false};
}
BacktickHandler::BacktickHandler() : IHandler({
                                                  '`',
                                              },
                                              {
                                                  Backtick
                                              }) {

}
