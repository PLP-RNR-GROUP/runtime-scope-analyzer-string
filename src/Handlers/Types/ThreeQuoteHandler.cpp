//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/ThreeQuoteHandler.h"
HandleResult ThreeQuoteHandler::Handle(const Construction& construction,
                                       const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr &&
      (waiting_for_construction->type != Quote && waiting_for_construction->state != Undefined )) return {nullptr, Continue};

  if (construction.type == ThreeQuote && construction.state == Undefined) {
    return {std::make_unique<Construction>(construction), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult ThreeQuoteHandler::TryAddConstructionTo(char character,
                                                                 const ConstructionStreamExtractorState& state,
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
ThreeQuoteHandler::ThreeQuoteHandler() : IHandler({
                                                      '\'',
                                                  },
                                                  {
                                                        {Undefined, ThreeQuote}
                                                  }) {

}
