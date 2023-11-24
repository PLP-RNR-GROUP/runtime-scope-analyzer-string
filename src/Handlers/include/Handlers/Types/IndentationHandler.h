//
// Created by Даник 💪 on 06.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_INDENTATIONHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_INDENTATIONHANDLER_H_

#include "Handlers/IHandler.h"
#include "Contexts/ScopeContext.h"

class IndentationHandler : public IHandler {
 public:
  explicit IndentationHandler(ScopeContext context);
  HandleResult Handle(const Construction& construction,
                      const std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                const boost::circular_buffer<char>& buffer,
                                                std::list<Construction>& constructions) override;
 private:
  ScopeContext context_;
  bool line_no_chars_at_moment;
  int current_indentation_level;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_INDENTATIONHANDLER_H_
