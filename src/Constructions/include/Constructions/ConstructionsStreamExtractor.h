//
// Created by Даник 💪 on 10.10.2023.
//

#ifndef RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
#define RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_

#include "ConstructionStreamExtractorState.h"
#include "Handlers/IHandlerList.h"
#include "Tokenizers/Tokenizer.h"
#include "GetResult.h"

#include <unordered_map>
#include <fstream>

class ConstructionsStreamExtractor {
 public:
  explicit ConstructionsStreamExtractor(const Tokenizer& tokenizer, const handlers_list* handlers);
  GetResult Get(int32_t token);
  void UpdateHandlers(const handlers_list* handlers);
 private:
  const Tokenizer& tokenizer_;
  ConstructionStreamExtractorState state_;
  const handlers_list* handlers_;
};

#endif //RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
