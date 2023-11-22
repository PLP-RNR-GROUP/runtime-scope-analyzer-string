//
// Created by Даник 💪 on 09.10.2023.
//

#ifndef RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_
#define RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_

enum Construction {
  DoubleQuote = 1,
  Quote,
  ThreeDoubleQuote,
  ThreeQuote,
  OpenedShortComment,
  ClosedShortComment,
  OpenedLongComment,
  ClosedLongComment,
  OpenedDollarSlashyString,
  ClosedDollarSlashyString,
  OpenedBrace,
  ClosedBrace,
  Backtick,
};

#endif //RUNTIME_SRC_INCLUDE_SCOPEANALYZER_CONSTRUCTIONS_CONSTRUCTION_H_
