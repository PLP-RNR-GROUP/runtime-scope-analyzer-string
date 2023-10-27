//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_
#define RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_

#include "ConstructionState.h"
#include "ConstructionType.h"

struct Construction {
  Construction() = default;
  Construction(ConstructionState state, ConstructionType type) : state(state), type(type) {}

  ConstructionState state;
  ConstructionType type;

  bool operator==(const Construction& rhs) const {
    return state == rhs.state &&
        type == rhs.type;
  }
  bool operator!=(const Construction& rhs) const {
    return !(rhs == *this);
  }
};

#endif //RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_
