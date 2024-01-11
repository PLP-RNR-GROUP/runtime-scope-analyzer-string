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
                                                                   const boost::circular_buffer<char>& buffer,
                                                                   std::list<Construction>& constructions) {
  if (
      character == '\n' ||
      (character == 'n' && !buffer.empty() && buffer[0] == '\\')) {
    constructions.emplace_back(ClosedShortComment);
    return {true, false};
  }

  if (character != '/') return {true, false};

  if (!buffer.empty() && buffer[0] == '/') {
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
                                                      }) {}
ShortCommentHandler::ShortCommentHandler(const std::vector<char> &handling_text,
                                         const std::vector<Construction> &handling_constructions)
    : IHandler(handling_text, handling_constructions) {}

ShortCommentHandler *ShortCommentHandler::clone() const {
    return new ShortCommentHandler(handling_text, handling_constructions);
}
