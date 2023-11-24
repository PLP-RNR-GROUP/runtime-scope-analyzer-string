//
// Created by Даник 💪 on 27.10.2023.
//

#include "Handlers/Types/BraceHandler.h"

HandleResult BraceHandler::Handle(const Construction& construction,
                                  const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == OpenedBrace) {
    ++brace_balance_;
  }
  else if (construction == ClosedBrace) {
    --brace_balance_;
    if (brace_balance_ <= 0) {
      return {nullptr, Stop};
    }
  }

  return {nullptr, Continue};
}

TryAddConstructionResult BraceHandler::TryAddConstructionTo(char character,
                                                            const ConstructionStreamExtractorState& state,
                                                            std::list<Construction>& constructions) {
  if (!state.buffer_.empty() && state.buffer_[0] == '\\') return {false, false};

  if (character == '{') {
    constructions.emplace_back(OpenedBrace);
    return {false, false};
  }
  else if (character == '}') {
    constructions.emplace_back(ClosedBrace);
    return {false, false};
  }

  return {true, false};
}

BraceHandler::BraceHandler(int brace_balance) : brace_balance_(brace_balance), IHandler({
                                                                                    '{',
                                                                                    '}'
                                                                                },
                                                                                {
                                                                                    OpenedBrace,
                                                                                    ClosedBrace
                                                                                }) {}
