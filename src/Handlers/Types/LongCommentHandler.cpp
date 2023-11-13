//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/LongCommentHandler.h"
std::unique_ptr<Construction> LongCommentHandler::Handle(const Construction& construction) {
  if (construction.type == LongComment && construction.state == Opened) {
    return std::make_unique<Construction>(Closed, LongComment);
  }

  return nullptr;
}
TryAddConstructionResult LongCommentHandler::TryAddConstructionTo(char character,
                                                                  ConstructionStreamExtractorState& state,
                                                                  std::list<Construction>& constructions) {
  bool add_current_char = true;
  if (state.buffer_.empty()) return {add_current_char, false};

  if (character == '/' && state.buffer_[0] == '*') {
    constructions.emplace_back(Closed, LongComment);
    state.buffer_.pop_front();
    add_current_char = false;
  }
  else if (character == '*' && state.buffer_[0] == '/') {
    constructions.emplace_back(Opened, LongComment);
    state.buffer_.pop_front();
    add_current_char = false;
  }

  return {add_current_char, false};
}
