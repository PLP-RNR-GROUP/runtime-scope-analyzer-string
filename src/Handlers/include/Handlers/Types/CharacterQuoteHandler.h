//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_CHARACTERQUOTEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_CHARACTERQUOTEHANDLER_H_

#include "Handlers/IHandler.h"
class CharacterQuoteHandler : public IHandler {
 public:
  std::unique_ptr<Construction> Handle(const Construction& construction) override;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_CHARACTERQUOTEHANDLER_H_
