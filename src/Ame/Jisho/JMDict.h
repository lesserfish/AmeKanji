#pragma once

#include "Dictionary.h"
#include "../Word.h"

namespace Ame
{
    class JMDict : public Dictionary
    {
        public:
            JMDict();
            Word getWordInformation(std::string Kanji);
            Word getWordiinformation(std::string Kanji, std::string Katakana);
        private:
    };
}
