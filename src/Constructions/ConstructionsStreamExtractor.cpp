//
// Created by Даник 💪 on 10.10.2023.
//
#include "Constructions/ConstructionsStreamExtractor.h"

#include <list>
#include "nlohmann/json.hpp"
#include "Constructions/GetResult.h"
#include "Handlers/HandlersMap.h"

using json = nlohmann::json;

GetResult ConstructionsStreamExtractor::Get(int32_t token) {
  std::string token_metadata = tokenizer_.Decode(token);
  std::list<Construction> constructions;

  bool should_stop_generation = false;
  for (char character: token_metadata) {
    bool save_current_character = true;

    auto handlers = handlers_map_.GetHandlersFor(character);
    if (handlers != nullptr) {
      for (const auto& kHandler : *handlers) {
      TryAddConstructionResult result = kHandler->TryAddConstructionTo(character, state_, constructions);
      if (result.should_stop_generation) {
        should_stop_generation = result.should_stop_generation;
      }

      if (!result.save_current_character) {
        save_current_character = false;
        state_.buffer_.clear();
        break;
      }
    }
    }

    if (save_current_character) {
      state_.buffer_.push_front(character);
    }
  }

  return {constructions, should_stop_generation};
}

ConstructionsStreamExtractor::ConstructionsStreamExtractor(const Tokenizer& tokenizer, const HandlersMap& handlers_map) :
    tokenizer_(tokenizer),
    handlers_map_(handlers_map) {
  state_.buffer_ = boost::circular_buffer<char>(2);
}
