#pragma once

#include "Dictionary.h"
#include "../../Cards/Kanji.h"
#include <pugixml.hpp>

namespace Ame
{
    // Class specialized in parsing dictionaries: kanjidic2 - kanjidic - kanjidic_es
    class NewKanjidict : public Dictionary
    {
        public:
            NewKanjidict();
            Kanji getKanjiInformation(std::string Kanji, std::string Mode = "");
            
            virtual int loadDictionaryFromFile(std::string file) = 0;
            virtual int loadDictionaryFromString(std::string content) = 0;
            
            // Create a structure in which we can hold the set of regex instructions to be applied for each value of the class Kanji
            // When using getKanjiInformation, apply the corresponding set of regex instructions to the output, so that we can modify things easily
        private:
            int getKanjiJISX0208Code(std::string Kanji);
            pugi::xml_document XMLDoc;
    };
}
