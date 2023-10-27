//
// Created by Даник 💪 on 10.10.2023.
//
#include "Constructions/ConstructionsStreamExtractor.h"

#include <utility>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

ConstructionsStreamExtractor::ConstructionsStreamExtractor(const std::string& json_vocab) {
  pos_ = 0;
  buffer_ = boost::circular_buffer<char>(3);

  json parsed_vocab = json::parse(json_vocab);

  // Deserialize std::map from JSON;
  for (json::iterator it = parsed_vocab.begin(); it != parsed_vocab.end(); ++it) {
    int32_t token_key = std::atoi(it.key().data());

    std::string current_token_string = it.value().template get<std::string>();

    vocab_[token_key] = current_token_string;
  }
}

std::set<ConstructionWithPosition> ConstructionsStreamExtractor::Get(int32_t token) {
  std::string token_metadata = vocab_.at(token);
  std::set<ConstructionWithPosition> constructions;
  for (char character: token_metadata) {
    if (character == '\'') {
      ConstructionWithPosition construction_to_add = ConstructionWithPosition(Undefined, CharacterQuote, pos_);
      constructions.insert(construction_to_add);
    } else if (character == '"') {
      ConstructionWithPosition construction_to_add = ConstructionWithPosition(Undefined, StringQuote, pos_);
      constructions.insert(construction_to_add);
    } else if (character == '/' && !buffer_.empty() && buffer_[0] == '/') {
      ConstructionWithPosition construction_to_add = ConstructionWithPosition(Opened, ShortComment, pos_);
      constructions.insert(construction_to_add);
    } else if (character == '\n') {
      ConstructionWithPosition construction_to_add = ConstructionWithPosition(Closed, ShortComment, pos_);
      constructions.insert(construction_to_add);
    } else if (character == '/' && !buffer_.empty() && buffer_[0] == '*') {
      ConstructionWithPosition construction_to_add = ConstructionWithPosition(Opened, LongComment, pos_);
      constructions.insert(construction_to_add);
    } else if (character == '*' && !buffer_.empty() && buffer_[0] == '/') {
      ConstructionWithPosition construction_to_add = ConstructionWithPosition(Closed, LongComment, pos_);
      constructions.insert(construction_to_add);
    } else if (character == '{') {
      ConstructionWithPosition construction_to_add = ConstructionWithPosition(Opened, Brace, pos_);
      constructions.insert(construction_to_add);
    } else if (character == '}') {
      ConstructionWithPosition construction_to_add = ConstructionWithPosition(Closed, Brace, pos_);
      constructions.insert(construction_to_add);
    }

    buffer_.push_front(character);
    ++pos_;
  }

  return constructions;
}
