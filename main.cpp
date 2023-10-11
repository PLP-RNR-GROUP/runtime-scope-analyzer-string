#include <iostream>
#include <fstream>
#include "ScopeAnalyzer/ScopeAnalyzer.h"

int main() {
  const std::string vocabPath = "/Users/katsushooter/Projects/sber-scope/preprocessing/tokenizer/analyzed_vocab.json";
  std::ifstream vocabFile = std::ifstream(vocabPath);
  ScopeAnalyzer analyzer(vocabFile);
  return 0;
}
