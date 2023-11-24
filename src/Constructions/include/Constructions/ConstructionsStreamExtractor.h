//
// Created by Даник 💪 on 10.10.2023.
//

#ifndef RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
#define RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_

#include "ConstructionStreamExtractorState.h"
#include "Handlers/IHandlerList.h"
#include "Tokenizers/Tokenizer.h"
#include "GetResult.h"
#include "Handlers/HandlersMap.h"

#include <unordered_map>
#include <fstream>

class ConstructionsStreamExtractor {
 public:
  explicit ConstructionsStreamExtractor(const Tokenizer& tokenizer, const HandlersMap& handlers_map);
  GetResult Get(int32_t token);
 private:
  const Tokenizer& tokenizer_;
  const HandlersMap& handlers_map_;
  ConstructionStreamExtractorState state_;
};

#endif //RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
