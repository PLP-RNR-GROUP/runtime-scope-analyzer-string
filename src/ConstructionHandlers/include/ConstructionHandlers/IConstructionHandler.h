//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_ICONSTRUCTIONHANDLER_H_
#define RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_ICONSTRUCTIONHANDLER_H_

#include "Constructions/Construction.h"

class IConstructionHandler {
 public:
  virtual ~IConstructionHandler() = default;
  IConstructionHandler& operator=(const IConstructionHandler&) = delete;

  // Handle returns expected Construction, that needs to be found otherwise other Constructions are ignored.
  virtual Construction Handle(int32_t token) = 0;
};

#endif //RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_ICONSTRUCTIONHANDLER_H_
