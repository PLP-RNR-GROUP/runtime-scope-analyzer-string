//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_INCLUDE_STRINGQUOTEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_INCLUDE_STRINGQUOTEHANDLER_H_

#include "Handlers/IHandler.h"
class StringQuoteHandler : public IHandler {
 public:
  std::unique_ptr<Construction> Handle(const Construction& construction, ScopeAnalyzerState& state) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                ConstructionStreamExtractorState& state,
                                                std::list<Construction>& constructions) override;
};

#endif //RUNTIME_SRC_HANDLERS_INCLUDE_STRINGQUOTEHANDLER_H_
