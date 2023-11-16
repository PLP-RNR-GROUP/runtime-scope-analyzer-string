//
// Created by Даник 💪 on 16.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_HANDLERSMAP_H_
#define RUNTIME_SRC_HANDLERS_HANDLERSMAP_H_

#include "IHandler.h"
#include "IHandlerList.h"

#include <map>
#include <list>
class HandlersMap {
 public:
  explicit HandlersMap(handlers_list_ptr handlers);

  std::list<IHandler*> GetHandlersFor(char character) const;
  void Add(handler handler);
 private:
    std::map<char, std::list<IHandler*>> handlers_map_;
    handlers_list_ptr handlers_;
};

#endif //RUNTIME_SRC_HANDLERS_HANDLERSMAP_H_
