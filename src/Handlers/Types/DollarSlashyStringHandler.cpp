//
// Created by Даник 💪 on 02.11.2023.
//

#include "Handlers/Types/DollarSlashyStringHandler.h"
#include "Handlers/Results/HandleResult.h"
HandleResult DollarSlashyStringHandler::Handle(const Construction& construction,
                                                                const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == OpenedDollarSlashyString) {
    return {std::make_unique<Construction>(ClosedDollarSlashyString), Continue};
  }

  return {nullptr, Continue};
}
TryAddConstructionResult DollarSlashyStringHandler::TryAddConstructionTo(char character,
                                                                         const boost::circular_buffer<char>& buffer,
                                                                         std::list<Construction>& constructions) {
  bool add_current_char = true;
  if (buffer.empty()) return {add_current_char, false};

  if (character == '/' && buffer[0] == '$') {
    constructions.emplace_back(OpenedDollarSlashyString);
    add_current_char = false;
  }
  else if (character == '$' && buffer[0] == '/') {
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
                                                                  }) {}
DollarSlashyStringHandler::DollarSlashyStringHandler(const std::vector<char>& handling_text,
                                                     const std::vector<Construction>& handling_constructions)
    : IHandler(handling_text, handling_constructions) {}

DollarSlashyStringHandler* DollarSlashyStringHandler::clone() const {
    return new DollarSlashyStringHandler(handling_text, handling_constructions);
}
