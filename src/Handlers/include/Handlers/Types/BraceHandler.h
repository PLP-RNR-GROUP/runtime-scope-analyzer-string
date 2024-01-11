//
// Created by Даник 💪 on 27.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_BRACEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_BRACEHANDLER_H_

#include "Handlers/IHandler.h"
#include "Handlers/TryAddConstructionResult.h"

class BraceHandler : public IHandler {
 public:
  explicit BraceHandler(int brace_balance);
  explicit BraceHandler(const std::vector<char>& handling_text,
                        const std::vector<Construction>& handling_constructions,
                        int brace_balance_);

  HandleResult Handle(const Construction& construction,
                      const std::unique_ptr<Construction>& waiting_for_construction) override;

  TryAddConstructionResult TryAddConstructionTo(char character,
                                                const boost::circular_buffer<char>& buffer,
                                                std::list<Construction>& constructions) override;

  [[nodiscard]] BraceHandler* clone() const override;

 private:
  int brace_balance_;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_BRACEHANDLER_H_
