//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/LongCommentHandler.h"
std::unique_ptr<Construction> LongCommentHandler::Handle(const Construction& construction,
                                                         const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return nullptr;

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
    add_current_char = false;
  }
  else if (character == '*' && state.buffer_[0] == '/') {
    constructions.emplace_back(Opened, LongComment);
    add_current_char = false;
  }

  return {add_current_char, false};
}
LongCommentHandler::LongCommentHandler() : IHandler({
                                                        '*',
                                                        '/'
                                                    },
                                                    {
                                                          {Opened, LongComment},
                                                    }) {

}
