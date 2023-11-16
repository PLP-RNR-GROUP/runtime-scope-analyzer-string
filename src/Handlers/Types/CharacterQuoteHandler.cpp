//
// Created by Даник 💪 on 23.10.2023.
//
#include "Handlers/Types/CharacterQuoteHandler.h"

std::unique_ptr<Construction> CharacterQuoteHandler::Handle(const Construction& construction,
                                                            const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return nullptr;

  if (construction.type == Quote && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
TryAddConstructionResult CharacterQuoteHandler::TryAddConstructionTo(char character,
                                                                     ConstructionStreamExtractorState& state,
                                                                     std::list<Construction>& constructions) {
  if (character != '\'') return {true, false};
  if (!state.buffer_.empty() && state.buffer_[0] == '\\') return {false, false};

  constructions.emplace_back(Undefined, Quote);
  return {true, false};
}
CharacterQuoteHandler::CharacterQuoteHandler() : IHandler({
                                                              '\'',
                                                          }, {
                                                              {Undefined, Quote}
                                                          }) {

}
