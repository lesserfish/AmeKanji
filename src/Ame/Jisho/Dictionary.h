#pragma once

#include <string>
#include <pugixml.hpp>

namespace Ame
{
    class Dictionary
    {
        public:
            Dictionary();
            virtual int loadXMLFromFile(std::string file);
            virtual int loadXMLFromString(std::string content);
            virtual int loadUTF8FromFile(std::string file);
            virtual int loadUTF8FromString(std::string content);

            virtual void setMode(std::string mode);

        private:
            pugi::xml_document XMLDoc;
            std::string UTF8Doc;
            std::string Mode;
    };
}