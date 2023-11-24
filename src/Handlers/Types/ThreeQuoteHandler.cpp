//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/ThreeQuoteHandler.h"
HandleResult ThreeQuoteHandler::Handle(const Construction& construction,
                                       const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr && *waiting_for_construction != Quote) return {nullptr, Continue};

  if (construction == ThreeQuote) {
    return {std::make_unique<Construction>(construction), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult ThreeQuoteHandler::TryAddConstructionTo(char character,
                                                                 const boost::circular_buffer<char>& buffer,
                                                                 std::list<Construction>& constructions) {
  if (character != '\'') return {true, false};

  if (buffer.size() >= 2 && buffer[0] == '\'' && buffer[1] == '\'') {
    if (!constructions.empty() && constructions.back() == Quote) {
      constructions.pop_back();
    }

    constructions.emplace_back(ThreeQuote);
    return {false, false};
  }

  return {true, false};
}
ThreeQuoteHandler::ThreeQuoteHandler() : IHandler({
                                                      '\'',
                                                  },
                                                  {
                                                        ThreeQuote
                                                  }) {

}
