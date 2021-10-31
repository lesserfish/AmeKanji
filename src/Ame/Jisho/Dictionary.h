#pragma once

#include <string>
#include <pugixml.hpp>
#include "../Regex/Regex.h"


namespace Ame
{
    class Dictionary
    {
        public:

            enum class mode{None, XML, UTF8};
            enum class regexMode{None, XML, UTF8};

            Dictionary();
            virtual int loadXMLFromFile(std::string file);
            virtual int loadXMLFromString(std::string content);
            virtual int loadUTF8FromFile(std::string file);
            virtual int loadUTF8FromString(std::string content);

            virtual void setMode(mode _Mode);
            virtual void setRegexMode(regexMode _Mode);

            virtual int loadXMLRegexFromFile(std::string file);
            virtual int loadXMLRegexFromString(std::string content);
            virtual int loadTXTRegexFromFile(std::string file);
            virtual int loadTXTRegexFromString(std::string content);

            virtual int generateRegexInstance() = 0;

        private:
            pugi::xml_document XMLDoc;
            std::string UTF8Doc;
            
            mode Mode;
            regexMode RegexMode;

            pugi::xml_document xml_regexInstruction; 
            std::string txt_regexInstruction;
    };
}