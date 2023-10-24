#include "ScopeAnalyzer/ScopeAnalyzer.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

int main() {
  const std::string vocabPath = "/Users/katsushooter/Projects/sber-scope/preprocessing/tokenizer/analyzed_vocab.json";

  std::ifstream vocabFile = std::ifstream(vocabPath);
  std::stringstream buffer;
  buffer << vocabFile.rdbuf();

////  "{{{}}}"void scope {}
  std::vector<int32_t> tokens {7, 40210, 5768, 98, 7112, 3970, 5136, 2637};

  ScopeAnalyzer analyzer(buffer.str(), ScopeContext(false, false, false, false, false));
  for (const auto token: tokens) {
    std::cout << analyzer.AddToken(token) << '\n';
  }

  return 0;
}
