//
// Created by Даник 💪 on 06.11.2023.
//

#ifndef RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_IANALYZER_H_
#define RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_IANALYZER_H_

#include "Languages/Language.h"
#include "AnalyzerTypes/Results/AddTokenResult.h"
#include "ScopeContext.h"
#include "Handlers/IHandlerList.h"
#include "Tokenizers/Tokenizer.h"
#include "Constructions/ConstructionsStreamExtractor.h"

#include <cstdint>

class IAnalyzer {
 protected:
  virtual void Delete() {
    delete this;
  };
  virtual ~IAnalyzer() = default;

  explicit IAnalyzer(const Tokenizer& tokenizer, handlers_list_ptr handlers, ScopeContext context) :
  handlers_(std::move(handlers)),
  constructions_stream_extractor_(tokenizer, handlers_.get()),
  context_(context) {
  }

  handlers_list_ptr handlers_;
  ConstructionsStreamExtractor constructions_stream_extractor_;
  ScopeContext context_;

 public:
  IAnalyzer& operator=(const IAnalyzer&) = delete;

  virtual AddTokenResult AddToken(int32_t token) = 0;
  virtual void ResetState(ScopeContext context, Language language) = 0;
  virtual void ApplyContext(ScopeContext context) = 0;

  struct Deleter
  {
    void operator()(IAnalyzer* p) const { p->Delete(); }
  };

  friend struct IAnalyzer::Deleter;
};

#endif //RUNTIME_LIB_INCLUDE_SCOPEANALYZER_ANALYZERS_IANALYZER_H_
