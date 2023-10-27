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
void ShortCommentHandler::TryAddConstructionTo(char character,
                                               ConstructionStreamExtractorState& state,
                                               std::list<Construction>& constructions) {
  if (character == '\n') {
    constructions.push_back(Construction(Closed, ShortComment));
    return;
  }

  if (character != '/') return;
  if (!state.buffer_.empty() && state.buffer_[0] == '/') {
    constructions.push_back(Construction(Opened, ShortComment));
    state.buffer_.pop_front();
  }
}
