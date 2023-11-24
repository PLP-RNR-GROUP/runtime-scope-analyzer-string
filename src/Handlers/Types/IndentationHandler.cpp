//
// Created by Даник 💪 on 06.11.2023.
//

#include "Handlers/Types/IndentationHandler.h"
HandleResult IndentationHandler::Handle(const Construction& construction,
                                        const std::unique_ptr<Construction>& waiting_for_construction) {
  return {nullptr, Continue};
}

TryAddConstructionResult IndentationHandler::TryAddConstructionTo(char character,
                                                                  const boost::circular_buffer<char>& buffer,
                                                                  std::list<Construction>& constructions) {
  if (
      character == '\n' ||
          (character == 'n' && !buffer.empty() && buffer[0] == '\\')) {
    line_no_chars_at_moment = true;
    current_indentation_level = 0;
    return {true, false};
  }

  if (!line_no_chars_at_moment) return {true, false};

  if (character == '\t' ||
      (character == 't' && !buffer.empty() && buffer[0] == '\\')) {
    current_indentation_level += context_.tab_in_spaces;
  }
  else if (character == ' ') {
    ++current_indentation_level;
  }
  else {
    line_no_chars_at_moment = false;

    if (current_indentation_level <= context_.start_indentation_level) {
      return {true, true};
    }
  }

  return {true, false};
}
IndentationHandler::IndentationHandler(ScopeContext context)
  :context_(context), line_no_chars_at_moment(false), current_indentation_level(0), IHandler({
                                                                                                 '\n',
                                                                                                 'n',
                                                                                                 't',
                                                                                                 '\t',
                                                                                             },
                                                                                             {}) {
}
