#pragma once

#include "../StatusCodes.h"
#include <string>
#include <pugixml.hpp>

namespace Ame
{
    // Template class for every dictionary parser. Every dictionary parser inherits from this class.
    // Currently we have four parsers: NewKanjidict, Kanjidict, JMdict and Edict. 
    
    class Dictionary
    {
        public:
            Dictionary();
            virtual ame_result loadDictionaryFromFile(std::string file) = 0;
            virtual ame_result loadDictionaryFromString(std::string content) = 0;

            virtual ame_result loadXMLRegexFromFile(std::string file, unsigned int options = 116U, pugi::xml_encoding enconding = pugi::encoding_utf8);
            virtual ame_result loadXMLRegexFromString(std::string file, unsigned int options = 116U);

            virtual ame_result generateRegexInstance() = 0;

        private:
            pugi::xml_document xml_regexInstruction; 
    };
}