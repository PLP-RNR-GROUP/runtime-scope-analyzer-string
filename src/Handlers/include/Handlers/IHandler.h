//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_INCLUDE_IHANDLER_H_
#define RUNTIME_SRC_HANDLERS_INCLUDE_IHANDLER_H_

#include "TryAddConstructionResult.h"
#include "Handlers/Results/HandleResult.h"
#include "boost/circular_buffer.hpp"

#include <vector>
#include <memory>
#include <list>

class IHandler {
 protected:
  virtual ~IHandler() = 0;
  virtual void Delete();

  std::vector<char> handling_text;
  std::vector<Construction> handling_constructions;
  explicit IHandler(const std::vector<char>& handling_text,
                    const std::vector<Construction>& handling_constructions);

 public:
  IHandler& operator=(const IHandler&) = delete;

  // Handle returns next waiting construction.
  virtual HandleResult Handle(const Construction& construction,
                              const std::unique_ptr<Construction>& waiting_for_construction) = 0;
  virtual TryAddConstructionResult TryAddConstructionTo(char character,
                                                        const boost::circular_buffer<char>& buffer,
                                                        std::list<Construction>& constructions) = 0;
  [[nodiscard]] virtual IHandler* clone() const = 0;

  const std::vector<char>& GetHandlingText() const;
  const std::vector<Construction>& GetHandlingConstructions() const;

  struct Deleter
  {
    void operator()(IHandler* p) const { p->Delete(); }
  };

  friend struct IHandler::Deleter;
};

#endif //RUNTIME_SRC_HANDLERS_INCLUDE_IHANDLER_H_
