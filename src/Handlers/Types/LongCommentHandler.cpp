//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/LongCommentHandler.h"
std::unique_ptr<Construction> LongCommentHandler::Handle(const Construction& construction, const ScopeState& state) {
  if (construction.type == LongComment && construction.state == Opened) {
    return std::make_unique<Construction>(Opened, LongComment);
  }

  return nullptr;
}
