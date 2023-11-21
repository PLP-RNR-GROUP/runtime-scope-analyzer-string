//
// Created by Даник 💪 on 21.11.2023.
//

#ifndef RUNTIME_SRC_ANALYZERTYPES_INCLUDE_ANALYZERTYPES_BASEANALYZER_H_
#define RUNTIME_SRC_ANALYZERTYPES_INCLUDE_ANALYZERTYPES_BASEANALYZER_H_

#include "IAnalyzer.h"
class BaseAnalyzer : public IAnalyzer {
 public:
  AddTokenResult AddToken(int32_t token) override;
 protected:
  BaseAnalyzer(const Tokenizer& tokenizer,
               ScopeContext context,
               handlers_list_ptr handlers,
               handlers_list_ptr required_handlers);

  HandlersMap handlers_map_;
  std::unique_ptr<Construction> waiting_for_construction_;
  ConstructionsStreamExtractor constructions_stream_extractor_;
 private:
  void ApplyContext(ScopeContext context);
};

#endif //RUNTIME_SRC_ANALYZERTYPES_INCLUDE_ANALYZERTYPES_BASEANALYZER_H_
