//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/ShortCommentHandler.h"
HandleResult ShortCommentHandler::Handle(const Construction& construction,
                                         const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == OpenedShortComment) {
    return {std::make_unique<Construction>(ClosedShortComment), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult ShortCommentHandler::TryAddConstructionTo(char character,
                                                                   const ConstructionStreamExtractorState& state,
                                                                   std::list<Construction>& constructions) {
  if (
      character == '\n' ||
      (character == 'n' && !state.buffer_.empty() && state.buffer_[0] == '\\')) {
    constructions.emplace_back(ClosedShortComment);
    return {true, false};
  }

  if (character != '/') return {true, false};

  if (!state.buffer_.empty() && state.buffer_[0] == '/') {
    constructions.emplace_back(OpenedShortComment);
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
                                                          OpenedShortComment,
                                                      }) {

}
