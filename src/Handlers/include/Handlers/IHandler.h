//
// Created by Даник 💪 on 23.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_INCLUDE_IHANDLER_H_
#define RUNTIME_SRC_HANDLERS_INCLUDE_IHANDLER_H_

#include "Constructions/Construction.h"

class IHandler {
 protected:
  IHandler() = default;
  virtual ~IHandler() = 0;
  virtual void Delete();

 public:
  IHandler& operator=(const IHandler&) = delete;

  // Handle returns next waiting construction.
  virtual std::unique_ptr<Construction> Handle(const Construction& construction) = 0;

  struct Deleter
  {
    void operator()(IHandler* p) const { p->Delete(); }
  };

  friend struct IHandler::Deleter;
};

#endif //RUNTIME_SRC_HANDLERS_INCLUDE_IHANDLER_H_
