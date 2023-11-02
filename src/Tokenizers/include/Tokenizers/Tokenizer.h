//
// Created by Даник 💪 on 30.10.2023.
//

#ifndef RUNTIME_SRC_TOKENIZER_TOKENIZER_H_
#define RUNTIME_SRC_TOKENIZER_TOKENIZER_H_

#include <string>
#include <unordered_map>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

class Tokenizer {
 public:
  explicit Tokenizer(const std::string& json_vocab);
  std::string Decode(int32_t token);
 private:
  std::unordered_map<wchar_t, int32_t> byte_decoder_;
  std::unordered_map<int32_t, std::wstring> vocab_;
};

#endif //RUNTIME_SRC_TOKENIZER_TOKENIZER_H_
