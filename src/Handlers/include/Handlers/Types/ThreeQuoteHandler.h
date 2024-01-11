//
// Created by Даник 💪 on 02.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_TYPES_THREEQUOTEHANDLER_H_
#define RUNTIME_SRC_HANDLERS_TYPES_THREEQUOTEHANDLER_H_

#include "Handlers/IHandler.h"
class ThreeQuoteHandler : public IHandler {
 public:
  explicit ThreeQuoteHandler();
  explicit ThreeQuoteHandler(const std::vector<char>& handling_text,
                             const std::vector<Construction>& handling_constructions);
  HandleResult Handle(const Construction& construction,
                      const std::unique_ptr<Construction>& waiting_for_construction) override;
  TryAddConstructionResult TryAddConstructionTo(char character,
                                                const boost::circular_buffer<char>& buffer,
                                                std::list<Construction>& constructions) override;
  [[nodiscard]] ThreeQuoteHandler* clone() const override;
};

#endif //RUNTIME_SRC_HANDLERS_TYPES_THREEQUOTEHANDLER_H_
