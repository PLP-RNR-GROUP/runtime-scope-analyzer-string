//
// Created by Даник 💪 on 13.11.2023.
//

#ifndef RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_GETRESULT_H_
#define RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_GETRESULT_H_

#include "Constructions/Construction.h"
#include <list>

struct GetResult {
  std::list<Construction> constructions;
  bool stop_generation;
};

#endif //RUNTIME_SRC_CONSTRUCTIONS_INCLUDE_CONSTRUCTIONS_GETRESULT_H_
