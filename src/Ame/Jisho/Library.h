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
   
   
    template<class K> 
    class AmeLibrary
    {
        public:
            AmeLibrary(AmeConfig &config) : configInstance(config) {}

            inline ame_result Load(){
                return ame_result();
            }
            inline ame_result loadParserManually(std::function < ame_result(K&, std::string, std::vector<std::string>, std::vector<std::string>) > func)            {
                parserFunction = func;
                guessCardMode();
                return ame_result{};
            }
            inline ame_result loadParserAutomatically(){
                guessCardMode();
                guessParser();

                if(parserMode == ParserMode::JMdict)
                {
                    parserFunction = JMdict::getInformation;
                }

                return ame_result();
            }
            inline ame_result invokeParser(K& output, std::string dict, std::vector<std::string> input = {}, std::vector<std::string> args = {}, bool includeDictionaryArgs = false){
                if(includeDictionaryArgs){
                    guessDictionary();
                    args.push_back(dictionaryOptions.Mode);
                }
                return parserFunction(output, dict, input, args);
            }
            inline ame_result invokeParser(K& output, std::vector<std::string> input = {}, bool includeDictionaryArgs = false){
                return invokeParser(output, input, {}, includeDictionaryArgs);
            }
            inline ame_result invokeParser(K& output, std::vector<std::string> input = {}, std::vector<std::string> args = {}, bool includeDictionaryArgs = false){

                addArgs(args);
                guessDictionary();

                std::cout << args.size() << std::endl;
                if(includeDictionaryArgs){
                    args.push_back(dictionaryOptions.Mode);
                }

                return parserFunction(output, dictionaryOptions.Arg, input, args);
            }
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
            inline CardMode getCardMode(){
                return cardMode;
            }
            
            inline void addArgs(std::vector<std::string>& currentArgs){}
            private:
            
            CardMode cardMode;
            ParserMode parserMode;
            
            AmeConfig& configInstance;
            std::function<ame_result(K&, std::string, std::vector<std::string>, std::vector<std::string>)> parserFunction;

            struct DictionaryOptions {
                std::string Mode;
                std::string Arg;
            };

            DictionaryOptions dictionaryOptions;
            
            inline void guessDictionary(){

            }
   
            void guessCardMode();
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

            

    };
}