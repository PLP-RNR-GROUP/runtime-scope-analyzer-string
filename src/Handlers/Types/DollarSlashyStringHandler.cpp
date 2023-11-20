//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/DollarSlashyStringHandler.h"
std::unique_ptr<Construction> DollarSlashyStringHandler::Handle(const Construction& construction,
                                                                const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return nullptr;

  if (construction.type == DollarSlashyString && construction.state == Opened) {
    return std::make_unique<Construction>(Closed, DollarSlashyString);
  }

  return nullptr;
}
TryAddConstructionResult DollarSlashyStringHandler::TryAddConstructionTo(char character,
                                                                         const ConstructionStreamExtractorState& state,
                                                                         std::list<Construction>& constructions) {
  bool add_current_char = true;
  if (state.buffer_.empty()) return {add_current_char, false};

  if (character == '/' && state.buffer_[0] == '$') {
    constructions.emplace_back(Opened, DollarSlashyString);
    add_current_char = false;
  }
  else if (character == '$' && state.buffer_[0] == '/') {
    constructions.emplace_back(Closed, DollarSlashyString);
    add_current_char = false;
  }

  return {add_current_char, false};
}
DollarSlashyStringHandler::DollarSlashyStringHandler() : IHandler({
                                                                      '$',
                                                                      '/'
                                                                  },
                                                                  {
                                                                      {Opened, DollarSlashyString},
                                                                  }) {

}
