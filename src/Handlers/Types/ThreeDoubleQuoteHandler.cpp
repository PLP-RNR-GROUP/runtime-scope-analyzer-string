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
                                                                       const boost::circular_buffer<char>& buffer,
                                                                       std::list<Construction>& constructions) {
  if (character != '"') return {true, false};

  if (buffer.size() >= 2 && buffer[0] == '"' && buffer[1] == '"') {
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
