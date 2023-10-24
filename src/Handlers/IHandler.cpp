//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/IHandler.h"
void IHandler::Delete() {
  delete this;
}

IHandler::~IHandler() = default;