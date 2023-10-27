//
// Created by Даник 💪 on 27.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_BRACEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_BRACEHANDLER_H_

#include "Handlers/IHandler.h"
#include "Handlers/TryAddConstructionResult.h"

class BraceHandler : public IHandler {
 public:
  std::unique_ptr<Construction> Handle(const Construction& construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                ConstructionStreamExtractorState& state,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_BRACEHANDLER_H_
