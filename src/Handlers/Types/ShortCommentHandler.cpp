//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/ShortCommentHandler.h"
std::unique_ptr<Construction> ShortCommentHandler::Handle(const Construction& construction) {
  if (construction.type == ShortComment && construction.state == Opened) {
    return std::make_unique<Construction>(Opened, ShortComment);
  }

  return nullptr;
}
