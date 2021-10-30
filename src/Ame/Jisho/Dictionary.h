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
            int loadXMLFromString(std::string Content);
        private:
            pugi::xml_document XMLDoc;
    };
}