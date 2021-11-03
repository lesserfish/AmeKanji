#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

#include "../AmeConfig.h"
#include "../StatusCodes.h"
#include "../Web/AmeWeb.h"

#include "../Cards/Word.h"
#include "../Cards/Kanji.h"
#include "Parsers/Edict.h"
#include "Parsers/JMdict.h"
#include "Parsers/Kanjidic.h"
#include "Parsers/NewKanjidic.h"


namespace Ame
{
    enum class CardMode {Unkown, Kanji, Word};
    enum class ParserMode {Unkown, JMdict, Edict, Kanjidic, NewKanjidic};
    enum class RegexMode {Unknown, JMDict, Edict, Kanjidic, NewKanjidic};
    enum class ParserInput {ANY, XML, TXT};
   
   
    template<class K> 
    class AmeLibrary
    {
        public:
            AmeLibrary(AmeConfig &config) : configInstance(config), 
                                                parserFunction([=](K& k, std::string str, std::vector<std::string> s1, std::vector<std::string>s2){
                                                    return ame_result(false, statusCode::ERR, "No parser given!");
                                                }),
                                                parserXMLFunction([=](K& k, pugi::xml_document&, std::vector<std::string> s1, std::vector<std::string>s2){
                                                    return ame_result(false, statusCode::ERR, "No parser given!");
                                                }),
                                                regexParserFunction([=](K& k, std::string, std::vector<std::string>){
                                                    return ame_result(false, statusCode::ERR, "No regex parser given!");
                                                }),
                                                regexParserXMLFunction([=](K& k, pugi::xml_document&, std::vector<std::string>){
                                                    return ame_result(false, statusCode::ERR, "No regex parser given!");
                                                })
            {
                guessCardMode();
            }


            // Loading functions

            inline ame_result Load(){
                return ame_result();
            }
            inline ame_result loadParserManually(std::function < ame_result(K&, std::string, std::vector<std::string>, std::vector<std::string>) > func)            {
                parserMode = ParserMode::Unkown;
                parserInput = ParserInput::TXT;
                parserFunction = func;
                
                return ame_result();
            }
            inline ame_result loadParserAutomatically(){
                guessParser();
                parserInput = ParserInput::ANY;

                switch(parserMode)
                {
                    case ParserMode::JMdict: 
                        parserFunction = JMdict::getInformation;
                        parserXMLFunction = JMdict::getInformationXML; 
                        return ame_result(true, statusCode::OK);
                    default: break; 
                }

                return ame_result(false, statusCode::ERR, "Failed to find the Parser given the configuration!");
            }
            inline ame_result loadRegexParserManually(std::function < ame_result(K&, std::string, std::vector<std::string>) > func)
            {
                regexMode = RegexMode::Unknown;
                regexParserFunction = func;
                return ame_result(true, statusCode::OK);
            }
            inline ame_result loadRegexParserAutomatically()
            {
                guessRegex();
                return ame_result(false, statusCode::ERR, "Failed to find the Regex Parser given the configuration! You can always set DisableParser to 'true' in the configuration and skip it!");
            }

            // Invoking functions

            inline ame_result invokeParser(K& output, std::string dict, std::vector<std::string> input = {}, std::vector<std::string> args = {}, bool includeDictionaryArgs = false){
                addArgs(args);
                if(includeDictionaryArgs){
                    setDictionaryAutomatically();
                    args.push_back(dictionaryOptions.Mode);
                }
                return parserFunction(output, dict, input, args);
            }
            inline ame_result invokeParser(K& output, std::vector<std::string> input = {}, bool includeDictionaryArgs = false){
                return invokeParser(output, input, {}, includeDictionaryArgs);
            }
            inline ame_result invokeParser(K& output, std::vector<std::string> input = {}, std::vector<std::string> args = {}, bool includeDictionaryArgs = false){
                addArgs(args);
                setDictionaryAutomatically();

                if(includeDictionaryArgs){
                    args.push_back(dictionaryOptions.Mode);
                }

                return parserFunction(output, dictionaryOptions.Arg, input, args);
            }
            inline ame_result invokeParser(K& output, pugi::xml_document &dict, std::vector<std::string> input = {}, std::vector<std::string> args = {}, bool includeDictionaryArgs = false){
                addArgs(args);
                if(includeDictionaryArgs){
                    setDictionaryAutomatically();
                    args.push_back(dictionaryOptions.Mode);
                }
                return parserXMLFunction(output, dict, input, args);
            }
            inline ame_result InvokeRegex(K& output, std::string Regex, std::vector<std::string> args)
            {
                return regexParserFunction(output, Regex, args);
            }


            // Configuration Function

            inline void setDictionaryManually(std::string Arg, std::string Mode = "")
            {
                dictionaryOptions.Arg = Arg;
                dictionaryOptions.Mode = Mode;
            }
            inline void setDictionaryAutomatically()
            {
                if(configInstance.ConfigurationFile == "" || configInstance.PreferDictionaryContentOverFile == "true")
                {
                    dictionaryOptions.Arg = configInstance.DictionaryContent;
                    dictionaryOptions.Mode = "string";
                }
                else
                {
                    dictionaryOptions.Arg = configInstance.ConfigurationFile;
                    dictionaryOptions.Mode = "file";
                }
            }
            inline void addArgs(std::vector<std::string>& currentArgs){}
            
            
            // Retrieval Functions
            
            inline CardMode getCardMode(){
                return cardMode;
            }
            inline std::string getDictionaryArgument(){
               return dictionaryOptions.Arg;
            } 
            inline std::string getDictionaryMode(){
               return dictionaryOptions.Mode;
            }
            inline ParserMode getParserMode(){
                return parserMode;
            }
            inline RegexMode getRegexMode(){
                return regexMode;
            }
            private:
            
            // Members

            CardMode cardMode;
            ParserMode parserMode;
            ParserInput parserInput;
            RegexMode regexMode;

            AmeConfig& configInstance;
            std::function<ame_result(K&, pugi::xml_document &, std::vector<std::string>, std::vector<std::string>)> parserXMLFunction;
            std::function<ame_result(K&, std::string, std::vector<std::string>, std::vector<std::string>)> parserFunction;
            std::function<ame_result(K&, pugi::xml_document &, std::vector<std::string>)> regexParserXMLFunction;
            std::function<ame_result(K&, std::string, std::vector<std::string>)> regexParserFunction;
            
            struct DictionaryOptions {
                std::string Mode;
                std::string Arg;
            };
            DictionaryOptions dictionaryOptions;
            

            // Private functions

            inline void guessParser()
            {
                std::string cParserValue = configInstance.Parser;
                std::transform(cParserValue.begin(), cParserValue.end(), cParserValue.begin(), ::tolower);
                
                if(cParserValue == "jmdict")
                    parserMode = ParserMode::JMdict;
                else if(cParserValue == "edict")
                    parserMode = ParserMode::Edict;
                else if(cParserValue == "hispadic")
                    parserMode = ParserMode::Edict;
                else if(cParserValue == "hispamix")
                    parserMode = ParserMode::Edict;
                else if(cParserValue == "kanjidic")
                    parserMode = ParserMode::Kanjidic;
                else if(cParserValue == "kanjidic2")
                    parserMode = ParserMode::NewKanjidic;
                else
                    parserMode = ParserMode::Unkown;
            }
            inline void guessRegex()
            {

            }
            void guessCardMode();

            

    };
}