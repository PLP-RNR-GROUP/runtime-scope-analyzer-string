//
// Created by Даник 💪 on 27.10.2023.
//

#include "Handlers/Types/BraceHandler.h"

std::unique_ptr<Construction> BraceHandler::Handle(const Construction& construction) {
  if (construction.type == Brace) {
    switch (construction.state) {
      case Undefined:
        throw std::invalid_argument("invalid state");
      case Closed:
        --state_.brace_balance;
        break;
      case Opened:
        ++state_.brace_balance;
        break;
    }
  }

  return nullptr;
}

TryAddConstructionResult BraceHandler::TryAddConstructionTo(char character,
                                                            ConstructionStreamExtractorState& state,
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

BraceHandler::BraceHandler(BraceAnalyzerState& state) : state_(state) {}
