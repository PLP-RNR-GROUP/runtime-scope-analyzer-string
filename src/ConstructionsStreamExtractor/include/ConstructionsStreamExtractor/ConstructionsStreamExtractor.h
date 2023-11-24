//
// Created by Даник 💪 on 10.10.2023.
//

#ifndef RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
#define RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_

#include "Handlers/IHandlerList.h"
#include "Tokenizers/Tokenizer.h"
#include "GetResult.h"
#include "HandlersMap/HandlersMap.h"

#include <unordered_map>
#include <fstream>

class ConstructionsStreamExtractor {
 public:
  explicit ConstructionsStreamExtractor(const Tokenizer& tokenizer, const HandlersMap& handlers_map);
  GetResult Get(int32_t token);
 private:
  const Tokenizer& tokenizer_;
  const HandlersMap& handlers_map_;
  boost::circular_buffer<char> buffer_;
};


#ifdef __cplusplus
extern "C" {
#endif

struct CGetResult {
  bool stop_generation;
  size_t constructions_amount;
  Construction* constructions;
};

ConstructionsStreamExtractor* constructions_stream_extractor_new(const Tokenizer* tokenizer, const HandlersMap* handlers_map);
void constructions_stream_extractor_del(ConstructionsStreamExtractor* stream_extractor);
CGetResult* constructions_stream_extractor_add_token(ConstructionsStreamExtractor* stream_extractor, int32_t token);

void cget_result_del(CGetResult result);
#ifdef __cplusplus
}
#endif

#endif //RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_TOKENTOCONSTRUCTIONSCONVERTER_H_
