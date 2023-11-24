//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TYPES_LONGCOMMENTHANDLER_H_
#define RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TYPES_LONGCOMMENTHANDLER_H_

#include "Handlers/IHandler.h"
#include "Handlers/Results/HandleResult.h"
class LongCommentHandler : public IHandler {
 public:
  explicit LongCommentHandler();
  HandleResult Handle(const Construction& construction,
                      const std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                const boost::circular_buffer<char>& buffer,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TYPES_LONGCOMMENTHANDLER_H_
