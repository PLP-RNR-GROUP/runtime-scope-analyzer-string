//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/LongCommentHandler.h"
std::unique_ptr<Construction> LongCommentHandler::Handle(const Construction& construction) {
  if (construction.type == LongComment && construction.state == Opened) {
    return std::make_unique<Construction>(Opened, LongComment);
  }

  return nullptr;
}
void LongCommentHandler::TryAddConstructionTo(char character,
                                              ConstructionStreamExtractorState& state,
                                              std::list<Construction>& constructions) {
  if (state.buffer_.empty()) return;

  if (character == '/' && state.buffer_[0] == '*') {
    constructions.push_back(Construction(Closed, LongComment));
    state.buffer_.pop_front();
  }
  else if (character == '*' && state.buffer_[0] == '/') {
    constructions.push_back(Construction(Opened, LongComment));
    state.buffer_.pop_front();
  }
}
