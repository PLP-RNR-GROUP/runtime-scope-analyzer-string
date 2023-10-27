//
// Created by Даник 💪 on 27.10.2023.
//

#include "Handlers/Types/BraceHandler.h"

std::unique_ptr<Construction> BraceHandler::Handle(const Construction& construction) {
  // TODO
  return nullptr;
}

TryAddConstructionResult BraceHandler::TryAddConstructionTo(char character,
                                                            ConstructionStreamExtractorState& state,
                                                            std::list<Construction>& constructions) {
  if (character == '{') {
    constructions.emplace_back(Opened, Brace);
    return {false};
  }
  else if (character == '}') {
    constructions.emplace_back(Closed, Brace);
    return {false};
  }

  return {true};
}
