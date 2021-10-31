#pragma once

#include "Dictionary.h"
#include "../../Word.h"
#include <pugixml.hpp>

namespace Ame
{

    // Class specialized in parsing dictionaries JMdict - edict2 - hispadix - hispamix
    class JMdict : public Dictionary
    {
        public:
            JMdict();
            Word getWordInformation(std::string Kanji, std::string Mode = "");
            Word getWordiinformation(std::string Kanji, std::string Katakana, std::string Mode = "");
            
            int loadDictionaryFromFile(std::string file);
            int loadDictionaryFromString(std::string content);
        private:
            pugi::xml_document XMLDoc;
    };
}
