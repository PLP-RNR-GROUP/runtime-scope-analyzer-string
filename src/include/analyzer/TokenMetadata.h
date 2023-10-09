//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_INCLUDE_ANALYZER_TOKENMETADATA_H_
#define RUNTIME_SRC_INCLUDE_ANALYZER_TOKENMETADATA_H_

#include <vector>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct TokenMetadata {
  bool endsWithBackslash;
  bool startsWithBackslash;

  bool endsWithStar;
  bool startsWithStar;

  bool endsWithSlash;
  bool startsWithSlash;

  std::vector<int32_t> quotationMarksIndexes;
  std::vector<int32_t> curlyBracesIndexes;
};

static void from_json(const json& j, TokenMetadata& p) {
  j.at("endsWithBackslash").get_to(p.endsWithBackslash);
  j.at("startsWithBackslash").get_to(p.startsWithBackslash);

  j.at("endsWithStar").get_to(p.endsWithStar);
  j.at("startsWithStar").get_to(p.startsWithStar);

  j.at("endsWithSlash").get_to(p.endsWithSlash);
  j.at("startsWithSlash").get_to(p.startsWithSlash);

  j.at("quotationMarksIndexes").get_to(p.quotationMarksIndexes);
  j.at("curlyBracesIndexes").get_to(p.curlyBracesIndexes);
}

#endif //RUNTIME_SRC_INCLUDE_ANALYZER_TOKENMETADATA_H_
