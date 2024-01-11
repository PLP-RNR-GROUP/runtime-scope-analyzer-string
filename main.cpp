#include "ScopeAnalyzer/ScopeAnalyzer.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <fstream>
#include <sstream>


int main() {
  const std::string vocabPath = "/home/akkyma/models/gpt_java_small/string_vocab.json";

  std::ifstream vocabFile = std::ifstream(vocabPath);
  std::stringstream buffer;
  buffer << vocabFile.rdbuf();

  std::vector<int32_t> tokens {
      226, 372, 513, 433, 1286, 328, 349, 627, 1514, 14, 293, 204, 226, 308, 204, 98};

  ScopeAnalyzer analyzer(buffer.str(), ScopeContext(false, false, false, false, false, 0), Python);
  ScopeAnalyzer analyzer2(analyzer);
  for (const auto token: tokens) {
    std::cout << analyzer.AddToken(token) << '\n';
  }

  return 0;
}
