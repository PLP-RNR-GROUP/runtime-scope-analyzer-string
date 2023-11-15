//
// Created by Даник 💪 on 02.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_DOLLARSLASHYSTRINGHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_DOLLARSLASHYSTRINGHANDLER_H_

#include "Handlers/IHandler.h"
class DollarSlashyStringHandler : public IHandler {
 public:
  std::unique_ptr<Construction> Handle(const Construction& construction,
                                       std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                ConstructionStreamExtractorState& state,
                                                std::list<Construction>& constructions) override;
};
#endif //RUNTIME_SRC_HANDLERS_TYPES_DOLLARSLASHYSTRINGHANDLER_H_
