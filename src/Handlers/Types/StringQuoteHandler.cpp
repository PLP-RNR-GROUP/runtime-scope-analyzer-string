//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/StringQuoteHandler.h"
#include "Handlers/HandleResult.h"

HandleResult StringQuoteHandler::Handle(const Construction& construction,
                                                         const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == DoubleQuote) {
    return {std::make_unique<Construction>(construction), Continue};
  }

  return {nullptr, Continue};
}

TryAddConstructionResult StringQuoteHandler::TryAddConstructionTo(char character,
                                                                  const ConstructionStreamExtractorState& state,
                                                                  std::list<Construction>& constructions) {
  if (character != '"') return {true, false};
  if (!state.buffer_.empty() && state.buffer_[0] == '\\') return {false, false};

  constructions.emplace_back(DoubleQuote);
  return {true, false};
}

StringQuoteHandler::StringQuoteHandler() : IHandler({
                                                        '"',
                                                    }, {
                                                        DoubleQuote
                                                    }) {}
