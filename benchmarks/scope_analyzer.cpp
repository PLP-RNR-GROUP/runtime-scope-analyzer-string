//
// Created by Даник 💪 on 27.10.2023.
//

#include "benchmark/benchmark.h"
#include "ScopeAnalyzer/ScopeAnalyzer.h"

#include <sstream>

const std::string vocabPath = "/Users/katsushooter/Projects/sber-scope/preprocessing-scope-analyzer-string/string_vocab.json";

static std::string slurp(const std::ifstream& in) {
  std::ostringstream sstr;
  sstr << in.rdbuf();
  return sstr.str();
}

class AnalyzerFixture : public benchmark::Fixture
{
 public:
  ScopeAnalyzer analyzer_;

  AnalyzerFixture() : analyzer_(slurp(std::ifstream(vocabPath)), ScopeContext(false, false, false, false, false), Java)
  {
  }
};

BENCHMARK_DEFINE_F(AnalyzerFixture, ScopeAnalyzerAdd) (benchmark::State& state) {
  std::vector<int32_t> tokens = std::vector<int32_t>(state.range(0), 46856);
  state.SetComplexityN(tokens.size());
  for (auto _ : state) {
    for (int32_t token: tokens) {
      if (analyzer_.AddToken(token) == Stop) {
        throw std::runtime_error("");
      }
    }

    analyzer_.ResetState(ScopeContext(false, false, false, false, false));
  }
}

BENCHMARK_REGISTER_F(AnalyzerFixture, ScopeAnalyzerAdd)
  ->RangeMultiplier(2)
  ->Range(2<<8,2<<12)
  ->ArgName("Tokens amount")
  ->Complexity(benchmark::oAuto)
  ->Unit(benchmark::kMillisecond);