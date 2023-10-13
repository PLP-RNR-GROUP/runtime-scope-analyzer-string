#include <iostream>
#include <fstream>
#include "ScopeAnalyzer/ScopeAnalyzer.h"

int main() {
  const std::string vocabPath = "~/analyzed_vocab.json";

  std::ifstream vocabFile = std::ifstream(vocabPath);

//  "{{{}}}"void scope {}
  std::vector<int32_t> tokens {7, 40210, 5768, 98, 7112, 3970, 5136, 2637};

  ScopeAnalyzer analyzer(vocabFile);
  for (const auto token: tokens) {
    std::cout << analyzer.AddToken(token) << '\n';
  }

  return 0;
}
