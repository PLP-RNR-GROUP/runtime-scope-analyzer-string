//
// Created by Даник 💪 on 09.10.2023.
//

#include <memory>

#include "ScopeAnalyzer/ScopeAnalyzer.h"
#include "Analyzers/JavaAnalyzer.h"
#include "Analyzers/JavascriptAnalyzer.h"
#include "Analyzers/ObjectiveCAnalyzer.h"
#include "Analyzers/CSharpAnalyzer.h"
#include "Analyzers/GoAnalyzer.h"
#include "Analyzers/GroovyAnalyzer.h"
#include "Analyzers/KotlinAnalyzer.h"
#include "Analyzers/ScalaAnalyzer.h"
#include "Analyzers/SwiftAnalyzer.h"
#include "Analyzers/JsonAnalyzer.h"

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
    case Javascript:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new JavascriptAnalyzer(tokenizer_));
    case ObjectiveC:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new ObjectiveCAnalyzer(tokenizer_));
    case CSharp:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new CSharpAnalyzer(tokenizer_));
    case Go:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new GoAnalyzer(tokenizer_));
    case Groovy:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new GroovyAnalyzer(tokenizer_));
    case Kotlin:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new KotlinAnalyzer(tokenizer_));
    case Scala:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new ScalaAnalyzer(tokenizer_));
    case Swift:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new SwiftAnalyzer(tokenizer_));
    case Json:
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new JsonAnalyzer(tokenizer_));
    case Python:
      throw std::runtime_error("python is not implemented");
  }

  throw std::invalid_argument("selected language is not supported");
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