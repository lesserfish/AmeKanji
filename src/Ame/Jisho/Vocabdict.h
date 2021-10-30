#pragma once

#include "Dictionary.h"
#include "../Word.h"

namespace Ame
{
    class VocabDict : public Dictionary
    {
        public:
            VocabDict();
            Word getWordInformation(std::string Kanji, std::string Mode = "");
            Word getWordiinformation(std::string Kanji, std::string Katakana, std::string Mode = "");
        private:
            pugi::xml_document XMLDoc;
            std::string UTF8Doc;
    };
}
