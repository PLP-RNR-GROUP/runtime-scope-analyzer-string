//
// Created by Даник 💪 on 19.10.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_SCOPECONTEXT_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_SCOPECONTEXT_H_

struct ScopeContext {
  ScopeContext(bool in_string,
               bool in_character,
               bool in_short_comment,
               bool in_long_comment,
               bool scope_opened,
               int tab_in_spaces = 4)
      : in_string(in_string),
        in_character(in_character),
        in_short_comment(in_short_comment),
        in_long_comment(in_long_comment),
        scope_opened(scope_opened),
        tab_in_spaces(tab_in_spaces)
        {}

  bool in_string;
  bool in_character;
  bool in_short_comment;
  bool in_long_comment;
  bool scope_opened;
  // TODO: Divide in two different contexts?
  int tab_in_spaces;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_SCOPECONTEXT_H_
