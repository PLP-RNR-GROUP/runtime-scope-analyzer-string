//
// Created by Даник 💪 on 07.11.2023.
//

#include "AnalyzerTypes/BraceAnalyzer.h"
#include "Handlers/Types/BraceHandler.h"

BraceAnalyzer::BraceAnalyzer(const Tokenizer& tokenizer,
                             handlers_list_ptr handlers,
                             ScopeContext context) : BaseAnalyzer(tokenizer,
                                                                  context,
                                                                  std::move(handlers),
                                                                  {}) {
  int brace_balance = 0;
  if (context.scope_opened) brace_balance = 1;
  handlers_map_.Add(handler(new BraceHandler(brace_balance)));
}