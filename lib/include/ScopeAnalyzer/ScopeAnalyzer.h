//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_ANALYZER_H_
#define RUNTIME_SRC_ANALYZER_H_

#include "nlohmann/json.hpp"
#include "ScopeAnalyzer/Results/AddTokenResult.h"
#include "Constructions/ConstructionsStreamExtractor.h"

#include <fstream>
#include <list>

using json = nlohmann::json;

class ScopeAnalyzer {
 public:
  explicit ScopeAnalyzer(std::ifstream& vocabFile);

  AddTokenResult AddToken(int32_t token);
 private:
  ConstructionsStreamExtractor constructions_extractor_;
  std::unique_ptr<Construction> waiting_for_construction_;
  int brace_balance;
};

#endif //RUNTIME_SRC_ANALYZER_H_
