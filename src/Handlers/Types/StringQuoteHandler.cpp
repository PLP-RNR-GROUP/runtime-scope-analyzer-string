//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/StringQuoteHandler.h"
#include "Handlers/Results/HandleResult.h"

HandleResult StringQuoteHandler::Handle(const Construction& construction,
                                                         const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == DoubleQuote) {
    return {std::make_unique<Construction>(construction), Continue};
  }

  return {nullptr, Continue};
}

TryAddConstructionResult StringQuoteHandler::TryAddConstructionTo(char character,
                                                                  const boost::circular_buffer<char>& buffer,
                                                                  std::list<Construction>& constructions) {
  if (character != '"') return {true, false};
  if (!buffer.empty() && buffer[0] == '\\') return {false, false};

  constructions.emplace_back(DoubleQuote);
  return {true, false};
}

StringQuoteHandler::StringQuoteHandler() : IHandler({
                                                        '"',
                                                    }, {
                                                        DoubleQuote
                                                    }) {}
StringQuoteHandler::StringQuoteHandler(const std::vector<char> &handling_text,
                                       const std::vector<Construction> &handling_constructions)
    : IHandler(handling_text, handling_constructions) {}

StringQuoteHandler* StringQuoteHandler::clone() const {
    return new StringQuoteHandler(handling_text, handling_constructions);
}
