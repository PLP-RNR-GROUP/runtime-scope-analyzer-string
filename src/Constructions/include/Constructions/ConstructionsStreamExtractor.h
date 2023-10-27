//
// Created by Даник 💪 on 10.10.2023.
//

#ifndef RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
#define RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_

#include "Construction.h"
#include "ConstructionWithPosition.h"
#include "boost/circular_buffer.hpp"

#include <set>
#include <map>
#include <fstream>

class ConstructionsStreamExtractor {
 public:
  explicit ConstructionsStreamExtractor(const std::string& json_vocab);
  std::set<ConstructionWithPosition> Get(int32_t token);
 private:
  std::map<int32_t, std::string> vocab_;
  boost::circular_buffer<char> buffer_;
  size_t sequence_length;
  size_t pos_;
};

#endif //RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
