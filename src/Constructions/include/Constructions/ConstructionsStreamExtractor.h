//
// Created by Даник 💪 on 10.10.2023.
//

#ifndef RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
#define RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_

#include "Construction.h"
#include "ConstructionStreamExtractorState.h"
#include "Handlers/IHandlerList.h"

#include <map>
#include <fstream>
#include <list>

class ConstructionsStreamExtractor {
 public:
  explicit ConstructionsStreamExtractor(const std::string& json_vocab, const handlers_list* handlers);
  std::list<Construction> Get(int32_t token);
 private:
  std::map<int32_t, std::string> vocab_;
  ConstructionStreamExtractorState state_;
  const handlers_list* handlers_;
};

#endif //RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
