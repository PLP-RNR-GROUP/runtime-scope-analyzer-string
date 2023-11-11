//
// Created by Даник 💪 on 06.11.2023.
//

#include "Handlers/Types/TabIndentationHandler.h"
std::unique_ptr<Construction> TabIndentationHandler::Handle(const Construction& construction) {
  if (construction.type == TabIndentation && construction.state == Undefined) {
   state_.current_indentation_level += tab_in_spaces_;
  }

  return nullptr;
}

TryAddConstructionResult TabIndentationHandler::TryAddConstructionTo(char character,
                                                                     ConstructionStreamExtractorState& state,
                                                                     std::list<Construction>& constructions) {
  if (character == '\t') {
    constructions.emplace_back(Undefined, TabIndentation);
  }

  return {false};
}

TabIndentationHandler::TabIndentationHandler(IndentationAnalyzerState& state, int tab_in_spaces)
    : state_(state), tab_in_spaces_(tab_in_spaces) {}
