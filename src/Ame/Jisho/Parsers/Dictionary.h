#pragma once

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
            virtual int loadDictionaryFromFile(std::string file) = 0;
            virtual int loadDictionaryFromString(std::string content) = 0;

            virtual int loadXMLRegexFromFile(std::string file);
            virtual int loadXMLRegexFromString(std::string content);

            virtual int generateRegexInstance() = 0;

        private:
            pugi::xml_document xml_regexInstruction; 
    };
}