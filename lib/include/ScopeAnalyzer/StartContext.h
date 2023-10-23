//
// Created by Даник 💪 on 19.10.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_STARTCONTEXT_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_STARTCONTEXT_H_

struct StartContext {
  StartContext(bool in_string, bool in_character, bool in_short_comment, bool in_long_comment, bool scope_opened)
      : in_string(in_string),
        in_character(in_character),
        in_short_comment(in_short_comment),
        in_long_comment(in_long_comment),
        scope_opened(scope_opened) {}

  bool in_string;
  bool in_character;
  bool in_short_comment;
  bool in_long_comment;
  bool scope_opened;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_STARTCONTEXT_H_
