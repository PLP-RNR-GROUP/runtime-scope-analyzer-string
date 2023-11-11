//
// Created by Даник 💪 on 11.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_INDENTATIONENDHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_INDENTATIONENDHANDLER_H_

#include "Handlers/IHandler.h"

class IndentationEndHandler : public IHandler {
  std::unique_ptr<Construction> Handle(const Construction& construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                ConstructionStreamExtractorState& state,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_INDENTATIONENDHANDLER_H_
