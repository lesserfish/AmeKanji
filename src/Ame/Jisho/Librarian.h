#pragma once

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <pugixml.hpp>
#include "EventChain.h"
#include "../StatusCodes.h"
#include "Parsers/JMdict.h"
#include "../Cards/Word.h"

namespace Ame
{

    enum class Parser{JMdict, Edict, Kanjidic, NewKanjidic, JMdictRegex};
    template<typename T, Parser parser, typename... A>
    class Librarian
    {
        public:
            static std::shared_ptr<ChainLink<T>> RetrieveParser(A... args)
            {
                return std::shared_ptr<ChainLink<T>>(nullptr);
            }
    };

    template<typename... A>
    class Librarian<Word, Parser::JMdict, std::shared_ptr<pugi::xml_document>, A...>{
        public:
            static std::shared_ptr<ChainLink<Word>> RetrieveParser(std::shared_ptr<pugi::xml_document> XMLDoc, A... args)
            {
                return ChainLink<Word>::Setup(&JMdict::getInformationXML, XMLDoc, std::vector<std::string>{});
            }
    };
    
    template<typename... A>
    class Librarian<Word, Parser::JMdict, std::string, std::vector<std::string>, A...>{
        public:
            static std::shared_ptr<ChainLink<Word>> RetrieveParser(std::string Doc, std::vector<std::string> Mode, A... args)
            {
                return ChainLink<Word>::Setup(&JMdict::getInformation, Doc, Mode);
            }
    };
    template<typename... A>
    class Librarian<Word, Parser::JMdictRegex, std::shared_ptr<pugi::xml_document>, A...>{
        public:
            static std::shared_ptr<ChainLink<Word>> RetrieveParser(std::shared_ptr<pugi::xml_document> XMLDoc, A... args)
            {
                return ChainLink<Word>::Setup(&JMdict::applyRegexXML, XMLDoc, std::vector<std::string>{});
            }
    };
    template<typename... A>
    class Librarian<Word, Parser::JMdictRegex, std::string, std::vector<std::string>, A...>{
        public:
            static std::shared_ptr<ChainLink<Word>> RetrieveParser(std::string Doc, std::vector<std::string> Mode, A... args)
            {
                return ChainLink<Word>::Setup(&JMdict::applyRegexXML, Doc, Mode);
            }
    };
}