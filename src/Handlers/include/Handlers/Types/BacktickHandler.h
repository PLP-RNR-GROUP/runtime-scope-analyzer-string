//
// Created by Даник 💪 on 01.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_BACKTICKHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_BACKTICKHANDLER_H_

#include "Handlers/IHandler.h"

class BacktickHandler : public IHandler {
 public:
  explicit BacktickHandler();
  std::unique_ptr<Construction> Handle(const Construction& construction,
                                       const std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                ConstructionStreamExtractorState& state,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_BACKTICKHANDLER_H_
