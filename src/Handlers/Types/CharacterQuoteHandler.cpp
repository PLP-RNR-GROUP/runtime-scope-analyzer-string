//
// Created by Даник 💪 on 23.10.2023.
//
#include "Handlers/Types/CharacterQuoteHandler.h"

HandleResult CharacterQuoteHandler::Handle(const Construction& construction,
                                           const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == Quote) {
    return {std::make_unique<Construction>(construction), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult CharacterQuoteHandler::TryAddConstructionTo(char character,
                                                                     const ConstructionStreamExtractorState& state,
                                                                     std::list<Construction>& constructions) {
  if (character != '\'') return {true, false};
  if (!state.buffer_.empty() && state.buffer_[0] == '\\') return {false, false};

  constructions.emplace_back(Quote);
  return {true, false};
}
CharacterQuoteHandler::CharacterQuoteHandler() : IHandler({
                                                              '\'',
                                                          }, {
                                                              Quote
                                                          }) {

}
