#pragma once

#include "Dictionary.h"
#include "../Word.h"

namespace Ame
{
    class VocabDict : public Dictionary
    {
        public:
            VocabDict();
            Word getWordInformation(std::string Kanji);
            Word getWordiinformation(std::string Kanji, std::string Katakana);
        private:
            pugi::xml_document XMLDoc;
            std::string UTF8Doc;
    };
}
