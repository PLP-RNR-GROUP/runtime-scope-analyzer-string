//
// Created by Даник 💪 on 11.11.2023.
//

#include "Handlers/Types/IndentationEndHandler.h"

std::unique_ptr<Construction> IndentationEndHandler::Handle(const Construction& construction) {
  if (construction.type == ShortComment && construction.state == Closed) {

  }
}

TryAddConstructionResult IndentationEndHandler::TryAddConstructionTo(char character,
                                                                  ConstructionStreamExtractorState& state,
                                                                  std::list<Construction>& constructions) {
  return {true, false};
}
