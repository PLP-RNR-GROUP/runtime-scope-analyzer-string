//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/DollarSlashyStringHandler.h"
std::unique_ptr<Construction> DollarSlashyStringHandler::Handle(const Construction& construction, ScopeAnalyzerState& state) {
  if (construction.type == DollarSlashyString && construction.state == Opened) {
    return std::make_unique<Construction>(Closed, LongComment);
  }

  return nullptr;
}
TryAddConstructionResult DollarSlashyStringHandler::TryAddConstructionTo(char character,
                                                                  ConstructionStreamExtractorState& state,
                                                                  std::list<Construction>& constructions) {
  bool add_current_char = true;
  if (state.buffer_.empty()) return {add_current_char};

  if (character == '/' && state.buffer_[0] == '$') {
    constructions.emplace_back(Opened, DollarSlashyString);
    state.buffer_.pop_front();
    add_current_char = false;
  }
  else if (character == '$' && state.buffer_[0] == '/') {
    constructions.emplace_back(Closed, DollarSlashyString);
    state.buffer_.pop_front();
    add_current_char = false;
  }

  return {add_current_char};
}