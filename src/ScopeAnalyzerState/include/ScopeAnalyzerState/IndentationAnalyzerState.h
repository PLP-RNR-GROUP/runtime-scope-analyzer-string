//
// Created by Даник 💪 on 11.11.2023.
//

#ifndef RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_INDENTATIONANALYZERSTATE_H_
#define RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_INDENTATIONANALYZERSTATE_H_

#include "Constructions/Construction.h"

#include <memory>

struct IndentationAnalyzerState {
  std::unique_ptr<Construction> waiting_for_construction_;
  int current_indentation_level;
  bool line_no_chars_at_moment;
};

#endif //RUNTIME_SRC_SCOPEANALYZERSTATE_INCLUDE_SCOPEANALYZERSTATE_INDENTATIONANALYZERSTATE_H_
