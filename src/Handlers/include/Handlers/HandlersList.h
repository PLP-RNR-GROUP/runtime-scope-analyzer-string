//
// Created by Даник 💪 on 25.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_HANDLERSLIST_H_
#define RUNTIME_SRC_HANDLERS_HANDLERSLIST_H_

#include "IHandler.h"
#include <vector>

class HandlersList {
 public:
  typedef std::unique_ptr<IHandler, IHandler::Deleter> handler;
  explicit HandlersList(std::unique_ptr<const std::vector<handler>> handlers);
  const std::vector<HandlersList::handler>& GetHandlers() const;

 private:
  std::unique_ptr<const std::vector<handler>> handlers_;
};

#endif //RUNTIME_SRC_HANDLERS_HANDLERSLIST_H_
