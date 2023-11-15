//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/IHandler.h"
void IHandler::Delete() {
  delete this;
}

IHandler::IHandler(const std::vector<char>& handling_text) : handling_text(handling_text) {}

const std::vector<char>& IHandler::GetHandlingText() const {
  return handling_text;
}

IHandler::~IHandler() = default;