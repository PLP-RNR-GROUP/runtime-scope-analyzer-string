#include <iostream>
#include <fstream>
#include "analyzer/Analyzer.h"
int main() {
  const std::string vocabPath = "/Users/katsushooter/Projects/sber-scope/preprocessing/tokenizer/analyzed_vocab.json";
  std::ifstream vocabFile = std::ifstream(vocabPath);
  Analyzer analyzer(vocabFile);
  return 0;
}
