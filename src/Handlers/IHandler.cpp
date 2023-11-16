//
// Created by Даник 💪 on 23.10.2023.
//

#include "Handlers/IHandler.h"
void IHandler::Delete() {
  delete this;
}

IHandler::IHandler(const std::vector<char>& handling_text, const std::vector<Construction>& handling_constructions)
    : handling_text(handling_text), handling_constructions(handling_constructions) {}

const std::vector<char>& IHandler::GetHandlingText() const {
  return handling_text;
}

const std::vector<Construction>& IHandler::GetHandlingConstructions() const {
  return handling_constructions;
}

IHandler::~IHandler() = default;