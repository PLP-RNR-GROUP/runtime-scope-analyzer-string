//
// Created by Даник 💪 on 07.11.2023.
//

#include "ScopeAnalyzer/Analyzers/IndentationAnalyzer.h"
IndentationAnalyzer::IndentationAnalyzer(ConstructionsStreamExtractor* constructions_stream_extractor,
                                         ScopeAnalyzerState& state,
                                         const handlers_list* handlers) :
                                         constructions_stream_extractor_(constructions_stream_extractor),
                                         state_(state),
                                         handlers_(handlers) {

}

AddTokenResult IndentationAnalyzer::AddToken(int32_t token) {
  // TODO:
  return Continue;
}
