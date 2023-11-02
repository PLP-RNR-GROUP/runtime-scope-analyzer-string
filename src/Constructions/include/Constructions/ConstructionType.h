//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_INCLUDE_SCOPEANALYZER_SPECIALSYMBOLS_SPECIALSYMBOLTYPE_H_
#define RUNTIME_SRC_INCLUDE_SCOPEANALYZER_SPECIALSYMBOLS_SPECIALSYMBOLTYPE_H_

enum ConstructionType {
  DoubleQuote = 1,
  Quote,
  ThreeDoubleQuote,
  ThreeQuote,
  ShortComment,
  LongComment,
  DollarSlashyString,
  Brace,
  Backtick
};

#endif //RUNTIME_SRC_INCLUDE_SCOPEANALYZER_SPECIALSYMBOLS_SPECIALSYMBOLTYPE_H_
