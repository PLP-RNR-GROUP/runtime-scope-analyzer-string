//
// Created by Даник 💪 on 10.10.2023.
//
#include "Constructions/ConstructionsStreamExtractor.h"

#include <utility>
#include <list>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

ConstructionsStreamExtractor::ConstructionsStreamExtractor(const std::string& json_vocab, const handlers_list* handlers) {
  state_.buffer_ = boost::circular_buffer<char>(3);
  handlers_ = handlers;

  json parsed_vocab = json::parse(json_vocab);

  // Deserialize std::map from JSON;
  for (json::iterator it = parsed_vocab.begin(); it != parsed_vocab.end(); ++it) {
    int32_t token_key = std::atoi(it.key().data());

    std::string current_token_string = it.value().template get<std::string>();

    vocab_[token_key] = current_token_string;
  }
}

std::list<Construction> ConstructionsStreamExtractor::Get(int32_t token) {
  std::string token_metadata = vocab_.at(token);
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
