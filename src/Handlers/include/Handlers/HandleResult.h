//
// Created by Даник 💪 on 20.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_HANDLERESULT_H_
#define RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_HANDLERESULT_H_

#include "Constructions/Construction.h"
#include "Handlers/Results/AddTokenResult.h"

struct HandleResult {
  HandleResult(std::unique_ptr<Construction> construction, AddTokenResult result)
      : construction(std::move(construction)), result(result) {}
  std::unique_ptr<Construction> construction;
  AddTokenResult result;
};

#endif //RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_HANDLERESULT_H_
