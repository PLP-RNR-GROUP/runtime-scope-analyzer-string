//
// Created by Даник 💪 on 27.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TRYADDCONSTRUCTIONRESULT_H_
#define RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TRYADDCONSTRUCTIONRESULT_H_

struct TryAddConstructionResult {
  TryAddConstructionResult(bool save_current_character, bool should_stop_generation) : save_current_character(
      save_current_character), should_stop_generation(should_stop_generation) {}
  bool save_current_character;
  bool should_stop_generation;
};

#endif //RUNTIME_SRC_HANDLERS_INCLUDE_HANDLERS_TRYADDCONSTRUCTIONRESULT_H_
