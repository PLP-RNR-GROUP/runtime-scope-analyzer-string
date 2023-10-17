//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_INCLUDE_ANALYZER_TOKENMETADATA_H_
#define RUNTIME_SRC_INCLUDE_ANALYZER_TOKENMETADATA_H_

#include "nlohmann/json.hpp"
#include "Constructions/Construction.h"

#include <vector>
#include <set>

using json = nlohmann::json;

struct TokenMetadata {
  bool endsWithBackslash;

  bool endsWithStar;
  bool startsWithStar;

  bool endsWithSlash;
  bool startsWithSlash;

  size_t length;
  std::set<Construction> constructions;
};

static void from_json(const json& j, TokenMetadata& p) {
  j.at("endsWithBackslash").get_to(p.endsWithBackslash);

  j.at("endsWithStar").get_to(p.endsWithStar);
  j.at("startsWithStar").get_to(p.startsWithStar);

  j.at("endsWithSlash").get_to(p.endsWithSlash);
  j.at("startsWithSlash").get_to(p.startsWithSlash);

  j.at("length").get_to(p.length);
  j.at("constructions").get_to(p.constructions);
}

#endif //RUNTIME_SRC_INCLUDE_ANALYZER_TOKENMETADATA_H_
