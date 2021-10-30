#pragma once

#include "Dictionary.h"
#include "../Kanji.h"

namespace Ame
{
    class Kanjidict : public Dictionary
    {
        public:
            Kanjidict();
            Kanji getKanjiInformation(std::string Kanji);
        private:
            int getKanjiJISX0208Code(std::string Kanji);
    };
}
