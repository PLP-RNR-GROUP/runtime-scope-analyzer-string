//
// Created by Даник 💪 on 10.10.2023.
//
#include "Constructions/ConstructionsStreamExtractor.h"

#include <utility>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

ConstructionsStreamExtractor::ConstructionsStreamExtractor(const std::string& json_vocab) {
  previous_token = nullptr;
  sequence_length = 0;

  json parsed_vocab = json::parse(json_vocab);

  // Deserialize std::map from JSON;
  for (json::iterator it = parsed_vocab.begin(); it != parsed_vocab.end(); ++it) {
    int32_t token_key = std::atoi(it.key().data());

    TokenMetadata currentTokenMetadata = it.value().template get<TokenMetadata>();

    vocab_[token_key] = currentTokenMetadata;
  }
}

class PrevTokenSetter{
 public:
  PrevTokenSetter(TokenMetadata current_token, std::unique_ptr<TokenMetadata>& previous_token)
  : current_token(std::move(current_token)),
    previous_token(previous_token) {}

  ~PrevTokenSetter() {
    previous_token = std::make_unique<TokenMetadata>(current_token);
  }
 private:
  TokenMetadata current_token;
  std::unique_ptr<TokenMetadata>& previous_token;
};

std::set<ConstructionWithPosition> ConstructionsStreamExtractor::Get(int32_t token) {
  TokenMetadata token_metadata = vocab_.at(token);
  PrevTokenSetter token_setter(token_metadata, previous_token);

  if (previous_token == nullptr) return token_metadata.constructions;

  auto constructions = token_metadata.constructions;
  size_t last_symbol_pos = sequence_length + previous_token->length;

  // TODO: abstraction
  if (previous_token->endsWithSlash && token_metadata.startsWithSlash) {
    ConstructionWithPosition short_comment = ConstructionWithPosition(Opened, ShortComment, last_symbol_pos);
    constructions.insert(short_comment);
  }
  else if (previous_token->endsWithStar && token_metadata.startsWithSlash) {
    ConstructionWithPosition end_long_comment = ConstructionWithPosition(Closed, LongComment, last_symbol_pos);
    constructions.insert(end_long_comment);
  }
  else if (previous_token->endsWithSlash && token_metadata.startsWithStar) {
    ConstructionWithPosition end_long_comment = ConstructionWithPosition(Closed, LongComment, last_symbol_pos);
    constructions.insert(end_long_comment);
  }

  if (constructions.empty()) return constructions;

  // Remove escaped constructions
  ConstructionWithPosition first_construction = *constructions.begin();
  if (previous_token->endsWithBackslash && first_construction.pos == 0) {
    constructions.erase(first_construction);
  }

  return constructions;
}
