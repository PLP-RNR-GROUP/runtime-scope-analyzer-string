//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/DollarSlashyStringHandler.h"
#include "Handlers/HandleResult.h"
HandleResult DollarSlashyStringHandler::Handle(const Construction& construction,
                                                                const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction.type == DollarSlashyString && construction.state == Opened) {
    return {std::make_unique<Construction>(Closed, DollarSlashyString), Continue};
  }

  return {nullptr, Continue};
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
