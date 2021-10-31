#pragma once

#include <string>
#include <pugixml.hpp>

namespace Ame
{

    // Template class for every dictionary parser. Every dictionary parser inherits from this class.
    // Currently we have two parsers: Vocabdict and Kanjidict. 
    class Dictionary
    {
        public:

            enum class regexMode{None, XML, UTF8};

            Dictionary();
            virtual int loadDictionaryFromFile(std::string file) = 0;
            virtual int loadDictionaryFromString(std::string content) = 0;


            virtual int loadXMLRegexFromFile(std::string file);
            virtual int loadXMLRegexFromString(std::string content);
            virtual int loadTXTRegexFromFile(std::string file);
            virtual int loadTXTRegexFromString(std::string content);

            virtual void setRegexMode(regexMode _Mode);
            virtual int generateRegexInstance() = 0;

        private:
            regexMode RegexMode;

            pugi::xml_document xml_regexInstruction; 
            std::string txt_regexInstruction;
    };
}