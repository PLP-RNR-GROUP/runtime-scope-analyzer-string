//
// Created by Даник 💪 on 07.11.2023.
//

#include "ScopeAnalyzer/AnalyzerTypes/IndentationAnalyzer.h"

AddTokenResult IndentationAnalyzer::AddToken(int32_t token) {
  // TODO:
  return Continue;
}
IndentationAnalyzer::IndentationAnalyzer(ConstructionsStreamExtractor* constructions_stream_extractor,
                                         const handlers_list* handlers) : constructions_stream_extractor_(constructions_stream_extractor),
                                                                          handlers_(handlers){

}
