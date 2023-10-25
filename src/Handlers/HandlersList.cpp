//
// Created by Даник 💪 on 25.10.2023.
//

#include "Handlers/HandlersList.h"

HandlersList::HandlersList(std::unique_ptr<const std::vector<handler>> handlers) : handlers_(std::move(handlers)) {}
const std::vector<HandlersList::handler>& HandlersList::GetHandlers() const {
  return *handlers_;
}
