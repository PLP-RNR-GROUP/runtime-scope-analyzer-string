//
// Created by Даник 💪 on 10.10.2023.
//
#include "Constructions/ConstructionsConverter.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

ConstructionsConverter::ConstructionsConverter(std::ifstream& vocab_file) {
  // Deserialize std::map from JSON;
  json parsed_vocab = json::parse(vocab_file);

  for (json::iterator it = parsed_vocab.begin(); it != parsed_vocab.end(); ++it) {
    int32_t token_key = std::atoi(it.key().data());

    TokenMetadata currentTokenMetadata = it.value().template get<TokenMetadata>();

    vocab_[token_key] = currentTokenMetadata;
  }
}
std::set<Construction> ConstructionsConverter::ParseFromToken(int32_t token) {
  TokenMetadata token_metadata = vocab_.at(token);
  std::set<Construction> output_constructions;

  std::set_union(token_metadata.curlyBraces.cbegin(), token_metadata.curlyBraces.cend(),
                 token_metadata.quotationMarks.cbegin(), token_metadata.quotationMarks.cend(),
                 std::inserter(output_constructions, output_constructions.begin()));

  return output_constructions;
}
