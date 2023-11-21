//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/ShortCommentHandler.h"
HandleResult ShortCommentHandler::Handle(const Construction& construction,
                                         const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction.type == ShortComment && construction.state == Opened) {
    return {std::make_unique<Construction>(Closed, ShortComment), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult ShortCommentHandler::TryAddConstructionTo(char character,
                                                                   const ConstructionStreamExtractorState& state,
                                                                   std::list<Construction>& constructions) {
  if (
      character == '\n' ||
      (character == 'n' && !state.buffer_.empty() && state.buffer_[0] == '\\')) {
    constructions.emplace_back(Closed, ShortComment);
    return {true, false};
  }

  if (character != '/') return {true, false};

  if (!state.buffer_.empty() && state.buffer_[0] == '/') {
    constructions.emplace_back(Opened, ShortComment);
    return {false, false};
  }

  return {true, false};
}
ShortCommentHandler::ShortCommentHandler() : IHandler({
                                                          '/',
                                                          '\n',
                                                          'n'
                                                      },
                                                      {
                                                          {Opened, ShortComment},
                                                      }) {

}
