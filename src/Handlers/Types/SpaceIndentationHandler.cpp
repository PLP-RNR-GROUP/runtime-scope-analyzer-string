//
// Created by Даник 💪 on 11.11.2023.
//

#include "Handlers/Types/SpaceIndentationHandler.h"

std::unique_ptr<Construction> SpaceIndentationHandler::Handle(const Construction& construction) {
  if (construction.type == SpaceIndentation && construction.state == Undefined) {
    ++state_.current_indentation_level;
  }

  return nullptr;
}

TryAddConstructionResult SpaceIndentationHandler::TryAddConstructionTo(char character,
                                                                     ConstructionStreamExtractorState& state,
                                                                     std::list<Construction>& constructions) {
  if (std::isspace(character)) {
    constructions.emplace_back(Undefined, SpaceIndentation);
  }

  return {false};
}

SpaceIndentationHandler::SpaceIndentationHandler(IndentationAnalyzerState& state, int tab_in_spaces)
    : state_(state), tab_in_spaces_(tab_in_spaces) {}
