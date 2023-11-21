//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_CHARACTERQUOTEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_CHARACTERQUOTEHANDLER_H_

#include "Handlers/IHandler.h"
class CharacterQuoteHandler : public IHandler {
 public:
  explicit CharacterQuoteHandler();
  HandleResult Handle(const Construction& construction,
                      const std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                const ConstructionStreamExtractorState& state,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_CHARACTERQUOTEHANDLER_H_
