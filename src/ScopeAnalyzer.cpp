//
// Created by Даник 💪 on 09.10.2023.
//

#include "ScopeAnalyzer/ScopeAnalyzer.h"
#include "ConstructionHandlers/QuoteHandler.h"

ScopeAnalyzer::ScopeAnalyzer(std::ifstream& vocabFile) : converter_(vocabFile) {
  // Register construction handlers.
  construction_handlers_.push_back(std::unique_ptr<IConstructionHandler, IConstructionHandlerDeleter>(new QuoteHandler()));
}

AddWordResult ScopeAnalyzer::AddWord(int32_t token) {
//  vocab_.at(token).;
  for (auto& handler: construction_handlers_) {
    handler->Handle(token);
  }
}
