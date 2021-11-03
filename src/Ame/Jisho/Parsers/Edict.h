#pragma once

#include "../Dictionary.h"
#include "../../Cards/Word.h"

namespace Ame
{

    // Class specialized in parsing dictionaries JMdict - edict2 - hispadix - hispamix
    class Edict : public Dictionary
    {
        public:
            Edict();
            Word getWordInformation(std::string Kanji, std::string Mode = "");
            Word getWordiinformation(std::string Kanji, std::string Katakana, std::string Mode = "");

            static Word getInformation(Word &output, std::vector<std::string> Input, std::string Dictionary, std::vector<std::string> Args);
            
            virtual ame_result loadDictionaryFromFile(std::string file) = 0;
            virtual ame_result loadDictionaryFromString(std::string content) = 0;
        private:
            std::string UTF8Doc;
    };
}
