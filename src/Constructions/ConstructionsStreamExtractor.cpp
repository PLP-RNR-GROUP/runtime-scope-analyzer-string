//
// Created by Даник 💪 on 10.10.2023.
//
#include "Constructions/ConstructionsStreamExtractor.h"

#include <list>
#include "nlohmann/json.hpp"
#include "Constructions/GetResult.h"

using json = nlohmann::json;

GetResult ConstructionsStreamExtractor::Get(int32_t token) {
  std::string token_metadata = tokenizer_.Decode(token);
  std::list<Construction> constructions;
  for (char character: token_metadata) {
    bool save_current_character = true;
    for (const auto& kHandler : *handlers_) {
      TryAddConstructionResult result = kHandler->TryAddConstructionTo(character, state_, constructions);
      if (result.should_stop_generation) {
        return {constructions, true};
      }

      if (!result.save_current_character) {
        save_current_character = false;
      }
    }

    if (save_current_character) {
      state_.buffer_.push_front(character);
    }
  }

  return {constructions, false};
}

void ConstructionsStreamExtractor::UpdateHandlers(const handlers_list* handlers) {
  handlers_ = handlers;
  state_.buffer_.clear();
}

ConstructionsStreamExtractor::ConstructionsStreamExtractor(const Tokenizer& tokenizer, const handlers_list* handlers) :
tokenizer_(tokenizer ){
  state_.buffer_ = boost::circular_buffer<char>(2);
  handlers_ = handlers;
}
