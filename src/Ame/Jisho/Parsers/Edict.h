#pragma once

#include "Dictionary.h"
#include "../../Word.h"

namespace Ame
{

    // Class specialized in parsing dictionaries JMdict - edict2 - hispadix - hispamix
    class Edict : public Dictionary
    {
        public:
            Edict();
            Word getWordInformation(std::string Kanji, std::string Mode = "");
            Word getWordiinformation(std::string Kanji, std::string Katakana, std::string Mode = "");
            
            virtual int loadDictionaryFromFile(std::string file) = 0;
            virtual int loadDictionaryFromString(std::string content) = 0;
        private:
            std::string UTF8Doc;
    };
}
