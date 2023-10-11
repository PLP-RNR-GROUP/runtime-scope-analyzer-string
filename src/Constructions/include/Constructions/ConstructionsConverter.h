//
// Created by Даник 💪 on 10.10.2023.
//

#ifndef RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
#define RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_

#include "Construction.h"
#include "Tokens/TokenMetadata.h"

#include <set>
#include <map>
#include <fstream>

class ConstructionsConverter {
 public:
  explicit ConstructionsConverter(std::ifstream& vocab_file);
  std::set<Construction> ParseFromToken(int32_t token);
 private:
  std::map<int32_t, TokenMetadata> vocab_;
};

#endif //RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
