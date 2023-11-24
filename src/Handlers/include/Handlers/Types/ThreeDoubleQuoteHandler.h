//
// Created by Даник 💪 on 01.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_THREEDOUBLEQUOTEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_THREEDOUBLEQUOTEHANDLER_H_

#include "Handlers/IHandler.h"
class ThreeDoubleQuoteHandler : public IHandler {
 public:
  explicit ThreeDoubleQuoteHandler();
  HandleResult Handle(const Construction& construction,
                      const std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                const boost::circular_buffer<char>& buffer,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_THREEDOUBLEQUOTEHANDLER_H_
