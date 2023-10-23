//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/Types/StringQuoteHandler.h"

std::unique_ptr<Construction> StringQuoteHandler::Handle(const Construction& construction) {
  if (construction.type == StringQuote && construction.state == Undefined) {
    return std::make_unique<Construction>(construction);
  }

  return nullptr;
}
