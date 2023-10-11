//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_
#define RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_

#include "ConstructionState.h"
#include "ConstructionTypes.h"

using json = nlohmann::json;

struct Construction {
  ConstructionState state;
  ConstructionTypes type;
  size_t pos;

  bool operator<(const Construction& rhs) const {
    return pos < rhs.pos;
  }
  bool operator>(const Construction& rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Construction& rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const Construction& rhs) const {
    return !(*this < rhs);
  }
};

static void from_json(const json& j, Construction& p) {
  j.at("state").get_to(p.state);
  j.at("type").get_to(p.type);
  j.at("pos").get_to(p.pos);
}

#endif //RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_
