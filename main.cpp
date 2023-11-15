#include "ScopeAnalyzer/ScopeAnalyzer.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

int main() {
  const std::string vocabPath = "/Users/katsushooter/Projects/sber-scope/preprocessing-scope-analyzer-string/string_vocab.json";

  std::ifstream vocabFile = std::ifstream(vocabPath);
  std::stringstream buffer;
  buffer << vocabFile.rdbuf();

  std::vector<int32_t> tokens {4690, 11192, 8228, 204, 264, 5967, 7, 936, 1272, 204, 37488, 7, 204, 264, 3901, 204};

  ScopeAnalyzer analyzer(buffer.str(), ScopeContext(false, false, false, false, false, 0), Python);
  for (const auto token: tokens) {
    std::cout << analyzer.AddToken(token) << '\n';
  }

  return 0;
}
