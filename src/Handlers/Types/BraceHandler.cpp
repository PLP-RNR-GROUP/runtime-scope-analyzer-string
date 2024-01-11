//
// Created by Даник 💪 on 27.10.2023.
//

#include "Handlers/Types/BraceHandler.h"

HandleResult BraceHandler::Handle(const Construction& construction,
                                  const std::unique_ptr<Construction>& waiting_for_construction) {
  if (waiting_for_construction != nullptr) return {nullptr, Continue};

  if (construction == OpenedBrace) {
    ++brace_balance_;
  }
  else if (construction == ClosedBrace) {
    --brace_balance_;
    if (brace_balance_ <= 0) {
      return {nullptr, Stop};
    }
  }

  return {nullptr, Continue};
}

TryAddConstructionResult BraceHandler::TryAddConstructionTo(char character,
                                                            const boost::circular_buffer<char>& buffer,
                                                            std::list<Construction>& constructions) {
  if (!buffer.empty() && buffer[0] == '\\') return {false, false};

  if (character == '{') {
    constructions.emplace_back(OpenedBrace);
    return {false, false};
  }
  else if (character == '}') {
    constructions.emplace_back(ClosedBrace);
    return {false, false};
  }

  return {true, false};
}

BraceHandler::BraceHandler(int brace_balance) : brace_balance_(brace_balance), IHandler({
                                                                                    '{',
                                                                                    '}'
                                                                                },
                                                                                {
                                                                                    OpenedBrace,
                                                                                    ClosedBrace
                                                                                }) {}

BraceHandler::BraceHandler(const std::vector<char>& handling_text,
                           const std::vector<Construction>& handling_constructions,
                           int brace_balance)
    : IHandler(handling_text, handling_constructions),
      brace_balance_(brace_balance){}

BraceHandler* BraceHandler::clone() const {
    return new BraceHandler(handling_text, handling_constructions, brace_balance_);
}
