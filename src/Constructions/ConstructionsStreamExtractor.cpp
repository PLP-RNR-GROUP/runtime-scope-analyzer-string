//
// Created by Даник 💪 on 10.10.2023.
//
#include "Constructions/ConstructionsStreamExtractor.h"

#include <list>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

ConstructionsStreamExtractor::ConstructionsStreamExtractor(const std::string& json_vocab, const handlers_list* handlers) :
  tokenizer_(json_vocab)
{
  state_.buffer_ = boost::circular_buffer<char>(2);
  handlers_ = handlers;
}

std::list<Construction> ConstructionsStreamExtractor::Get(int32_t token) {
  std::string token_metadata = tokenizer_.Decode(token);
  std::list<Construction> constructions;
  for (char character: token_metadata) {
    bool save_current_character = true;
    for (const auto& kHandler : *handlers_) {
      TryAddConstructionResult result = kHandler->TryAddConstructionTo(character, state_, constructions);
      if (!result.save_current_character) {
        save_current_character = false;
      }
    }

    if (save_current_character) {
      state_.buffer_.push_front(character);
    }
  }

  return constructions;
}
