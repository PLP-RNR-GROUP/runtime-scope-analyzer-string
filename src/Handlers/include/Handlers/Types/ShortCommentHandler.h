//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TYPES_SHORTCOMMENTHANDLER_H_
#define RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TYPES_SHORTCOMMENTHANDLER_H_

#include "Handlers/IHandler.h"
class ShortCommentHandler : public IHandler {
 public:
  std::unique_ptr<Construction> Handle(const Construction& construction, const ScopeState& state) override;
};

#endif //RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TYPES_SHORTCOMMENTHANDLER_H_