//
// Created by Даник 💪 on 06.11.2023.
//

#include "Handlers/Types/IndentationHandler.h"
std::unique_ptr<Construction> IndentationHandler::Handle(const Construction& construction,
                                                         std::unique_ptr<Construction>& waiting_for_construction) {
  return nullptr;
}

TryAddConstructionResult IndentationHandler::TryAddConstructionTo(char character,
                                                                     ConstructionStreamExtractorState& state,
                                                                     std::list<Construction>& constructions) {
  if (
      character == '\n' ||
          (character == 'n' && !state.buffer_.empty() && state.buffer_[0] == '\\')) {
    line_no_chars_at_moment = true;
    current_indentation_level = 0;
    return {true, false};
  }

  if (!line_no_chars_at_moment) return {true, false};

  if (character == '\t' ||
      (character == 't' && !state.buffer_.empty() && state.buffer_[0] == '\\')) {
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
  :context_(context), line_no_chars_at_moment(false), current_indentation_level(0)   {
}
