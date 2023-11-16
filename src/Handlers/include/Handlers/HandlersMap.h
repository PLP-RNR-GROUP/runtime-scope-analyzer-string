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
  explicit HandlersMap(handlers_list_ptr handlers, handlers_list_ptr required_handlers_for_char);

  const std::list<IHandler*>& GetHandlersFor(char character) const;
  const std::list<IHandler*>& GetHandlersFor(Construction construction) const;
  void Add(handler handler);
 private:
  std::unordered_map<char, std::list<IHandler*>> char_handlers_map_;
  std::unordered_map<Construction, std::list<IHandler*>> construction_handlers_map_;
  handlers_list_ptr handlers_;
  std::list<IHandler*> required_handlers_for_char_;
  std::list<IHandler*> empty_handlers_list_;
};

#endif //RUNTIME_SRC_HANDLERS_HANDLERSMAP_H_
