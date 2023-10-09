//
// Created by Даник 💪 on 09.10.2023.
//

#include "analyzer/Analyzer.h"

Analyzer::Analyzer(std::ifstream& vocabFile) {
  json parsedVocab = json::parse(vocabFile);

  for (json::iterator it = parsedVocab.begin(); it != parsedVocab.end(); ++it) {
    int32_t tokenKey = std::atoi(it.key().data());

    TokenMetadata currentTokenMetadata = it.value().template get<TokenMetadata>();

    vocab_[tokenKey] = currentTokenMetadata;
  }
  auto a = vocab_[25203];
}

AddWordResult Analyzer::AddWord(int32_t token) {
  return Stop;
}
