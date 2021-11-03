#include "Library.h"
#include <algorithm>

namespace Ame
{
        template<class K>
        void AmeLibrary<K>::guessCardMode(){
            cardMode = CardMode::Unkown;
        }
        template<>
        void AmeLibrary<Word>::guessCardMode(){
            cardMode = CardMode::Word;
        }
        template<>
        void AmeLibrary<Kanji>::guessCardMode(){
            cardMode = CardMode::Kanji;
        }

}