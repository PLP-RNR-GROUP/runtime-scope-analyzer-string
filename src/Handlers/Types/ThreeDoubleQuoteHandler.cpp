//
// Created by Даник 💪 on 01.11.2023.
//

#include "Handlers/Types/ThreeDoubleQuoteHandler.h"
HandleResult ThreeDoubleQuoteHandler::Handle(const Construction& construction,
                                             const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr && *waiting_for_construction != DoubleQuote) return {nullptr, Continue};

  if (construction == ThreeDoubleQuote) {
    return {std::make_unique<Construction>(construction), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult ThreeDoubleQuoteHandler::TryAddConstructionTo(char character,
                                                                       const ConstructionStreamExtractorState& state,
                                                                       std::list<Construction>& constructions) {
  if (character != '"') return {true, false};

  if (state.buffer_.size() >= 2 && state.buffer_[0] == '"' && state.buffer_[1] == '"') {
    if (!constructions.empty() && constructions.back() == DoubleQuote) {
      constructions.pop_back();
    }

    constructions.emplace_back(ThreeDoubleQuote);
    return {false, false};
  }

  return {true, false};
}
ThreeDoubleQuoteHandler::ThreeDoubleQuoteHandler() : IHandler({
                                                                  '"',
                                                              },
                                                              {
                                                                  ThreeDoubleQuote
                                                              }) {

}
