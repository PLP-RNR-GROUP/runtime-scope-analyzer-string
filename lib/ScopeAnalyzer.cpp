//
// Created by Даник 💪 on 09.10.2023.
//

#include <memory>

#include "ScopeAnalyzer/ScopeAnalyzer.h"
#include "Analyzers/JavaAnalyzer.h"

ScopeAnalyzer::ScopeAnalyzer(
    const std::string& json_vocab, ScopeContext context, Language selected_language)
    : tokenizer_(json_vocab) {

  ResetState(context, selected_language);
}

void ScopeAnalyzer::ResetState(ScopeContext context, Language language) {
  analyzer_ = PickAnalyzerForLanguage(language);
  analyzer_->ApplyContext(context);
}

//int ScopeAnalyzer::GetBraceBalance() const {
////  return state_.brace_balance;
//}
//
//const Construction* ScopeAnalyzer::GetWaitingForConstruction() const {
////  return state_.waiting_for_construction_.get();
//}

AddTokenResult ScopeAnalyzer::AddToken(int32_t token) {
  return analyzer_->AddToken(token);
}
std::unique_ptr<IAnalyzer, IAnalyzer::Deleter> ScopeAnalyzer::PickAnalyzerForLanguage(Language language) {
  switch (language) {
    case Java:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new JavaAnalyzer(tokenizer_));
      break;

//    case Javascript:break;
//    case ObjectiveC:break;
//    case CSharp:break;
//    case Go:break;
//    case Groovy:break;
//    case Kotlin:break;
//    case Scala:break;
//    case Swift:break;
//    case Json:break;
//    case Python:break;
  }

  // TODO: throw exception
  return nullptr;
}

// Обвязка C для методов C++

ScopeAnalyzer* scope_analyzer_new(const char* json_vocab, ScopeContext* context, Language selected_language) {
  return new ScopeAnalyzer(std::string(json_vocab), *context, selected_language);
}

void reset(ScopeAnalyzer* scope_analyzer, ScopeContext* context, Language language) {
  scope_analyzer->ResetState(*context, language);
}

void scope_analyzer_del(ScopeAnalyzer* scope_analyzer) {
  delete scope_analyzer;
}

AddTokenResult add_token(ScopeAnalyzer* scope_analyzer, int32_t token) {
  return scope_analyzer->AddToken(token);
}

//int get_brace_balance(ScopeAnalyzer* scope_analyzer) {
//  return scope_analyzer->GetBraceBalance();
//}
//
//const Construction* get_waiting_for_construction(ScopeAnalyzer* scope_analyzer) {
//  return scope_analyzer->GetWaitingForConstruction();
//}