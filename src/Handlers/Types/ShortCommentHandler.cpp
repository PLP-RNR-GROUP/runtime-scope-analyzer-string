//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/ShortCommentHandler.h"
std::unique_ptr<Construction> ShortCommentHandler::Handle(const Construction& construction) {
  if (construction.type == ShortComment && construction.state == Opened) {
    return std::make_unique<Construction>(Closed, ShortComment);
  }

  return nullptr;
}
TryAddConstructionResult ShortCommentHandler::TryAddConstructionTo(char character,
                                                                   ConstructionStreamExtractorState& state,
                                                                   std::list<Construction>& constructions) {
  if (
      character == '\n' ||
      (character == 'n' && !state.buffer_.empty() && state.buffer_[0] == '\\')) {
    constructions.emplace_back(Closed, ShortComment);
    return {false};
  }

  bool add_current_char = true;
  if (character != '/') return {add_current_char};

  if (!state.buffer_.empty() && state.buffer_[0] == '/') {
    add_current_char = false;
    constructions.emplace_back(Opened, ShortComment);
    state.buffer_.pop_front();
  }

  return {add_current_char};
}
