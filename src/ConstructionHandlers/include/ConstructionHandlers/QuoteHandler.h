//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_ICONSTRUCTIONHANDLERS_QUOTEHANDLER_H_
#define RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_ICONSTRUCTIONHANDLERS_QUOTEHANDLER_H_

#include "IConstructionHandler.h"
class QuoteHandler: public IConstructionHandler {
 public:
  ~QuoteHandler() override;
  Construction Handle(int32_t token) override;
};

#endif //RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_ICONSTRUCTIONHANDLERS_QUOTEHANDLER_H_
