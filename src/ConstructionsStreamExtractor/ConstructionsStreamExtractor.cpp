//
// Created by Даник 💪 on 10.10.2023.
//
#include "ConstructionsStreamExtractor/ConstructionsStreamExtractor.h"

#include <list>


GetResult ConstructionsStreamExtractor::Get(int32_t token) {
  std::string token_metadata = tokenizer_.Decode(token);
  std::list<Construction> constructions;

  bool should_stop_generation = false;
  for (char character: token_metadata) {
    bool save_current_character = true;

      for (const auto& kHandler : handlers_map_.GetHandlersFor(character)) {
      TryAddConstructionResult result = kHandler->TryAddConstructionTo(character, buffer_, constructions);
      if (result.should_stop_generation) {
        should_stop_generation = result.should_stop_generation;
      }

      if (!result.save_current_character) {
        save_current_character = false;
        buffer_.clear();
        break;
      }
    }

    if (save_current_character) {
      buffer_.push_front(character);
    }
  }

  return {constructions, should_stop_generation};
}

ConstructionsStreamExtractor::ConstructionsStreamExtractor(const Tokenizer& tokenizer, const HandlersMap& handlers_map) :
    tokenizer_(tokenizer),
    handlers_map_(handlers_map) {
  buffer_ = boost::circular_buffer<char>(2);
}


ConstructionsStreamExtractor* constructions_stream_extractor_new(const Tokenizer* tokenizer, const HandlersMap* handlers_map) {
  return new ConstructionsStreamExtractor(*tokenizer, *handlers_map);
}

void constructions_stream_extractor_del(ConstructionsStreamExtractor* stream_extractor) {
  delete stream_extractor;
}

CGetResult* constructions_stream_extractor_add_token(ConstructionsStreamExtractor* stream_extractor, int32_t token) {
  auto result = stream_extractor->Get(token);

  auto* parsed_constructions = new Construction[result.constructions.size()];
  std::copy(result.constructions.begin(), result.constructions.end(), parsed_constructions);

  return new CGetResult {
    result.stop_generation,
    result.constructions.size(),
    parsed_constructions
  };
}

void cget_result_del(CGetResult result) {
  delete result.constructions;
}