#pragma once

#include <tuple>
#include <vector>
#include "../AmeConfig.h"

// How should we store all of the different Parsers? On a huge big list? On a dictionary with enumeration?
// Should we store them by return type?

namespace Ame
{
    enum class CardMode {None, Kanji, Word};
    enum class ParserMode {None, Edict, JMdict, Kanjidic, NewKanjidic};
    
    typedef std::tuple<CardMode, ParserMode> fit;
    static const std::vector<fit> validModes = {fit(CardMode::Kanji, ParserMode::Kanjidic), 
                                                fit(CardMode::Kanji, ParserMode::NewKanjidic),
                                                fit(CardMode::Word, ParserMode::Edict),
                                                fit(CardMode::Word, ParserMode::JMdict)};
    
    // Holds all of the distinct Dictionaries. Intermediary between Ame and each one of them
    // Reads from the configuration in order to determine which dictionary parser to use, which dictionary file to send, and which regex file to send.
    class AmeLibrary
    {
        public:
            AmeLibrary(const AmeConfig &config);
            
            int Configure();
            
            std::string RenderTemplate(std::string Template, std::string Card); 
            
            void forceMode(CardMode cmode);
            void forceMode(ParserMode pmode);
            void forceMode(CardMode, ParserMode);

            void debug(); 
        private:

            template<class T> T populateCard(std::string Card);

            int establishCardMode();
            int establishParser();
            int checkCompatibility();

            const AmeConfig &configInstance;
            CardMode mode;
            ParserMode parser;
    };
}