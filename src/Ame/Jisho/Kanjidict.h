#pragma once

#include "Dictionary.h"
#include "../Kanji.h"

namespace Ame
{
    class Kanjidict : public Dictionary
    {
        public:
            Kanjidict();
            Kanji getKanjiInformation(std::string Kanji, std::string Mode = "");
        private:
            int getKanjiJISX0208Code(std::string Kanji);
            pugi::xml_document XMLDoc;
            std::string UTF8Doc;
    };
}
