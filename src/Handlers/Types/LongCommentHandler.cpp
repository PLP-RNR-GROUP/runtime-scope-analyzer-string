//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/LongCommentHandler.h"
#include "Handlers/Results/HandleResult.h"
HandleResult LongCommentHandler::Handle(const Construction& construction,
                                                         const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == OpenedLongComment) {
    return {std::make_unique<Construction>(ClosedLongComment), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult LongCommentHandler::TryAddConstructionTo(char character,
                                                                  const boost::circular_buffer<char>& buffer,
                                                                  std::list<Construction>& constructions) {
  bool add_current_char = true;
  if (buffer.empty()) return {add_current_char, false};

  if (character == '/' && buffer[0] == '*') {
    constructions.emplace_back(ClosedLongComment);
    add_current_char = false;
  }
  else if (character == '*' && buffer[0] == '/') {
    constructions.emplace_back(OpenedLongComment);
    add_current_char = false;
  }

  return {add_current_char, false};
}
LongCommentHandler::LongCommentHandler() : IHandler({
                                                        '*',
                                                        '/'
                                                    },
                                                    {
                                                          OpenedLongComment,
                                                    }) {

}
