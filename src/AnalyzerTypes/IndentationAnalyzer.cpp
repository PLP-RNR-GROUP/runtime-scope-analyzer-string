//
// Created by Даник 💪 on 07.11.2023.
//

#include "AnalyzerTypes/IndentationAnalyzer.h"

AddTokenResult IndentationAnalyzer::AddToken(int32_t token) {
  // TODO:
  return Continue;
}
IndentationAnalyzer::IndentationAnalyzer(const Tokenizer& tokenizer, handlers_list_ptr handlers) :
    IAnalyzer(tokenizer, std::move(handlers))
    {

}