//
// Created by Даник 💪 on 02.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_THREEQUOTEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_THREEQUOTEHANDLER_H_

#include "Handlers/IHandler.h"
class ThreeQuoteHandler : public IHandler {
 public:
  std::unique_ptr<Construction> Handle(const Construction& construction,
                                       const std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                ConstructionStreamExtractorState& state,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_THREEQUOTEHANDLER_H_
