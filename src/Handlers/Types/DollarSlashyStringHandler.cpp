//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/DollarSlashyStringHandler.h"
#include "Handlers/HandleResult.h"
HandleResult DollarSlashyStringHandler::Handle(const Construction& construction,
                                                                const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == OpenedDollarSlashyString) {
    return {std::make_unique<Construction>(ClosedDollarSlashyString), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult DollarSlashyStringHandler::TryAddConstructionTo(char character,
                                                                         const ConstructionStreamExtractorState& state,
                                                                         std::list<Construction>& constructions) {
  bool add_current_char = true;
  if (state.buffer_.empty()) return {add_current_char, false};

  if (character == '/' && state.buffer_[0] == '$') {
    constructions.emplace_back(OpenedDollarSlashyString);
    add_current_char = false;
  }
  else if (character == '$' && state.buffer_[0] == '/') {
    constructions.emplace_back(ClosedDollarSlashyString);
    add_current_char = false;
  }

  return {add_current_char, false};
}
DollarSlashyStringHandler::DollarSlashyStringHandler() : IHandler({
                                                                      '$',
                                                                      '/'
                                                                  },
                                                                  {
                                                                      OpenedDollarSlashyString,
                                                                  }) {

}
