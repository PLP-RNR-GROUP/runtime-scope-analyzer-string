//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_ANALYZER_H_
#define RUNTIME_SRC_ANALYZER_H_

#include "nlohmann/json.hpp"
#include "ScopeAnalyzer/Results/AddWordResult.h"
#include "Constructions/include/Tokens/TokenMetadata.h"

#include "ConstructionHandlers/IConstructionHandler.h"
#include "ConstructionHandlers/IConstructionHandlerDeleter.h"
#include "Constructions/include/Constructions/Construction.h"
#include "Constructions/ConstructionsConverter.h"

#include <fstream>
#include <list>

using json = nlohmann::json;

class ScopeAnalyzer {
 public:
  explicit ScopeAnalyzer(std::ifstream& vocabFile);

  AddWordResult AddWord(int32_t token);
 private:
  std::map<int, TokenMetadata> vocab_;

  std::list<Construction> constructions_;
  std::list<std::unique_ptr<IConstructionHandler, IConstructionHandlerDeleter>> construction_handlers_;
  ConstructionsConverter converter_;
};

#endif //RUNTIME_SRC_ANALYZER_H_
