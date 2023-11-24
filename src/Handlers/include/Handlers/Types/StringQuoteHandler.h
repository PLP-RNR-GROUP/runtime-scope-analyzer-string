//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_INCLUDE_STRINGQUOTEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_INCLUDE_STRINGQUOTEHANDLER_H_

#include "Handlers/IHandler.h"
#include "Handlers/Results/HandleResult.h"
class StringQuoteHandler : public IHandler {
 public:
  explicit StringQuoteHandler();
  HandleResult Handle(const Construction& construction,
                      const std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                const boost::circular_buffer<char>& buffer,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_INCLUDE_STRINGQUOTEHANDLER_H_
