//
// Created by Даник 💪 on 06.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_INDENTATIONSCOPECONTEXT_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_INDENTATIONSCOPECONTEXT_H_

struct IndentationScopeContext {
  IndentationScopeContext(bool in_string,
                          bool in_character,
                          bool in_short_comment,
                          bool in_long_comment,
                          bool scope_opened,
                          int tabulation_in_spaces)
      : in_string(in_string),
        in_character(in_character),
        in_short_comment(in_short_comment),
        in_long_comment(in_long_comment),
        scope_opened(scope_opened),
        tabulation_in_spaces(tabulation_in_spaces)
        {}

  bool in_string;
  bool in_character;
  bool in_short_comment;
  bool in_long_comment;
  bool scope_opened;
  int tabulation_in_spaces;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_INDENTATIONSCOPECONTEXT_H_
