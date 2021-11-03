#pragma once

#include "../Dictionary.h"
#include "../../Cards/Kanji.h"

namespace Ame
{
    // Class specialized in parsing dictionaries: kanjidic2 - kanjidic - kanjidic_es
    class Kanjidict : public Dictionary
    {
        public:
            Kanjidict();
            Kanji getKanjiInformation(std::string Kanji, std::string Mode = "");
            
            ame_result loadDictionaryFromFile(std::string file);
            ame_result loadDictionaryFromString(std::string content);

            static Kanji getInformation(Kanji &output, std::vector<std::string> Input, std::string Dictionary, std::vector<std::string> Args);
            // Create a structure in which we can hold the set of regex instructions to be applied for each value of the class Kanji
            // When using getKanjiInformation, apply the corresponding set of regex instructions to the output, so that we can modify things easily
            // This means that there should be two distinct functions of getKanjiInformation: getKanjiInformationFromXML (like JMdict) and getKanjiInformationFromUTF (like Edict)
            // By passing distinct Regex Files, we can parse the values accordingly.
        private:
            int getKanjiJISX0208Code(std::string Kanji);
            std::string UTF8Doc;
    };
}
