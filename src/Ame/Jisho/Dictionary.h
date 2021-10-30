#pragma once

#include <string>
#include <pugixml.hpp>

namespace Ame
{
    class Dictionary
    {
        public:
            Dictionary();
            int loadXMLFromFile(std::string file);
            int loadXMLFromString(std::string content);
            int loadUTF8FromFile(std::string file);
            int loadUTF8FromString(std::string content);
        private:
            pugi::xml_document XMLDoc;
            std::string UTF8Doc;
    };
}