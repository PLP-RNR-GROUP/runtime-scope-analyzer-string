//
// Created by Даник 💪 on 16.11.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_HANDLERSMAP_H_
#define RUNTIME_SRC_HANDLERS_HANDLERSMAP_H_

#include "Handlers/IHandler.h"
#include "Handlers/IHandlerList.h"

#include <map>
#include <list>
#include <unordered_map>


class HandlersMap {
 public:
  explicit HandlersMap(handlers_list_ptr handlers, handlers_list_ptr required_handlers_for_char);
  explicit HandlersMap(const HandlersMap& handlersMap);

  const std::list<IHandler*>& GetHandlersFor(char character) const;
  const std::list<IHandler*>& GetHandlersFor(Construction construction) const;
  void Add(handler handler);
 private:
  std::unordered_map<char, std::list<IHandler*>> char_handlers_map_;
  std::unordered_map<Construction, std::list<IHandler*>> construction_handlers_map_;
  handlers_list_ptr handlers_;
  std::list<IHandler*> required_handlers_for_char_;
  const std::list<IHandler*> empty_handlers_list_ {};
};


#ifdef __cplusplus
extern "C" {
#endif

HandlersMap* handlers_map_new(int tab_in_spaces);
void handlers_map_del(HandlersMap* handlers_map);

#ifdef __cplusplus
}
#endif

#endif //RUNTIME_SRC_HANDLERS_HANDLERSMAP_H_
