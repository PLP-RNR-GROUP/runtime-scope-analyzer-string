//
// Created by Даник 💪 on 09.11.2023.
//
#include "Analyzers/JavaAnalyzer.h"
#include "Handlers/Types/BacktickHandler.h"
#include "Handlers/Types/StringQuoteHandler.h"
#include "Handlers/Types/ShortCommentHandler.h"
#include "Handlers/Types/LongCommentHandler.h"

handler registered_handlers[] = {
    handler(new BacktickHandler()),
    handler(new StringQuoteHandler()),
    handler(new ShortCommentHandler()),
    handler(new LongCommentHandler()),
};

std::vector<handler> registered_handlers_vector(std::make_move_iterator(std::begin(registered_handlers)),
    std::make_move_iterator(std::end(registered_handlers)));

handlers_list_ptr handlers_ptr = handlers_list_ptr(
    std::make_unique<handlers_list>(std::move(registered_handlers_vector))
        );

JavaAnalyzer::JavaAnalyzer(const Tokenizer& tokenizer)
: BraceAnalyzer(tokenizer, std::move(handlers_ptr)) {

}
