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

////  "{{{}}}"void scope {}
  std::vector<int32_t> tokens {355, 308, 8050, 98, 3766, 83, 2637};

  ScopeAnalyzer analyzer(buffer.str(), ScopeContext(false, false, false, false, false), Java);
  for (const auto token: tokens) {
    std::cout << analyzer.AddToken(token) << '\n';
  }

  return 0;
}
