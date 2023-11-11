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
#include "Analyzers/PythonAnalyzer.h"

ScopeAnalyzer::ScopeAnalyzer(
    const std::string& json_vocab, ScopeContext context, Language selected_language)
    : tokenizer_(json_vocab) {
  ResetState(context, selected_language);
}

void ScopeAnalyzer::ResetState(ScopeContext context, Language language) {
  analyzer_ = PickAnalyzerForLanguage(language, ScopeContext(false, false, false, false, false, 0));
  analyzer_->ApplyContext(context);
}

AddTokenResult ScopeAnalyzer::AddToken(int32_t token) {
  return analyzer_->AddToken(token);
}

std::unique_ptr<IAnalyzer, IAnalyzer::Deleter> ScopeAnalyzer::PickAnalyzerForLanguage(Language language,
                                                                                      ScopeContext context) {
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
      return std::unique_ptr<IAnalyzer,
                             IAnalyzer::Deleter>(new PythonAnalyzer(tokenizer_, context));
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