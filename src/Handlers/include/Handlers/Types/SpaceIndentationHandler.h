//
// Created by Даник 💪 on 11.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_SPACEINDENTATIONHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_SPACEINDENTATIONHANDLER_H_

#include "Handlers/IHandler.h"
#include "ScopeAnalyzerState/IndentationAnalyzerState.h"

class SpaceIndentationHandler : public IHandler {
 public:
  SpaceIndentationHandler(IndentationAnalyzerState& state, int tab_in_spaces);
  std::unique_ptr<Construction> Handle(const Construction& construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                ConstructionStreamExtractorState& state,
                                                std::list<Construction>& constructions) override;
 private:
  IndentationAnalyzerState& state_;
  int tab_in_spaces_;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_SPACEINDENTATIONHANDLER_H_
