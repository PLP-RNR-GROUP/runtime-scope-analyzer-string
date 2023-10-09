//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_ANALYZER_H_
#define RUNTIME_SRC_ANALYZER_H_

#include "nlohmann/json.hpp"
#include "analyzer/results/AddWordResult.h"
#include "TokenMetadata.h"

#include <fstream>
using json = nlohmann::json;

class Analyzer {
 public:
  explicit Analyzer(std::ifstream& vocabFile);

  AddWordResult AddWord(int32_t token);
 private:
  std::map<int, TokenMetadata> vocab_;
};

#endif //RUNTIME_SRC_ANALYZER_H_
