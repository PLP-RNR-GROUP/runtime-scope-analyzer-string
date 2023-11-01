//
// Created by Даник 💪 on 27.10.2023.
//

#ifndef RUNTIME_SRC_HANDLERS_IHANDLERLIST_H_
#define RUNTIME_SRC_HANDLERS_IHANDLERLIST_H_

#include "Handlers/IHandler.h"
#include <vector>
#include <memory>

typedef std::shared_ptr<IHandler> handler;
typedef const std::vector<handler> handlers_list;
typedef std::unique_ptr<handlers_list> handlers_list_ptr;

#endif //RUNTIME_SRC_HANDLERS_IHANDLERLIST_H_
