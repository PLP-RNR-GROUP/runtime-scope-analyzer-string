//
// Created by Даник 💪 on 19.10.2023.
//

#ifndef RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_CONSTRUCTIONWITHPOSITION_H_
#define RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_CONSTRUCTIONWITHPOSITION_H_

#include "Constructions/Construction.h"
#include <cstddef>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct ConstructionWithPosition : public Construction {
  ConstructionWithPosition() : Construction() {
    pos = 0;
  }
  ConstructionWithPosition(ConstructionState state, ConstructionType type, size_t pos) : Construction(
      state,
      type), pos(pos) {}

  size_t pos;

  bool operator<(const ConstructionWithPosition& rhs) const {
    return pos < rhs.pos;
  }
  bool operator>(const ConstructionWithPosition& rhs) const {
    return rhs < *this;
  }
  bool operator<=(const ConstructionWithPosition& rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const ConstructionWithPosition& rhs) const {
    return !(*this < rhs);
  }
  bool operator==(const ConstructionWithPosition& rhs) const {
    return state == rhs.state &&
        type == rhs.type &&
        pos == rhs.pos;
  }
  bool operator!=(const ConstructionWithPosition& rhs) const {
    return !(rhs == *this);
  }
};

static void from_json(const json& j, ConstructionWithPosition& p) {
  j.at("state").get_to(p.state);
  j.at("type").get_to(p.type);
  j.at("pos").get_to(p.pos);
}

#endif //RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_CONSTRUCTIONWITHPOSITION_H_
