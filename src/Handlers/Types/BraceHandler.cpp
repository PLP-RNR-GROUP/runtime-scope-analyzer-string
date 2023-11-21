//
// Created by Даник 💪 on 27.10.2023.
//

#include "Handlers/Types/BraceHandler.h"

HandleResult BraceHandler::Handle(const Construction& construction,
                                  const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction.type == Brace) {
    switch (construction.state) {
      case Undefined:
        throw std::invalid_argument("invalid state");
      case Closed:
        --state_.brace_balance;
        if (state_.brace_balance <= 0) {
          return {nullptr, Stop};
        }
        break;
      case Opened:
        ++state_.brace_balance;
        break;
    }
  }

  return {nullptr, Continue};
}

TryAddConstructionResult BraceHandler::TryAddConstructionTo(char character,
                                                            const ConstructionStreamExtractorState& state,
                                                            std::list<Construction>& constructions) {
  if (!state.buffer_.empty() && state.buffer_[0] == '\\') return {false, false};

  if (character == '{') {
    constructions.emplace_back(Opened, Brace);
    return {false, false};
  }
  else if (character == '}') {
    constructions.emplace_back(Closed, Brace);
    return {false, false};
  }

  return {true, false};
}

BraceHandler::BraceHandler(BraceAnalyzerState& state) : state_(state), IHandler({
                                                                                    '{',
                                                                                    '}'
                                                                                },
                                                                                {
                                                                                    {Opened, Brace},
                                                                                    {Closed, Brace}
                                                                                }) {}
