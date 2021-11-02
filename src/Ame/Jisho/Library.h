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
/* Maybe?
    template<class T> AmeLibrary
    {
        public:
            ...
            ...

            // Sets parser manually
            ame_result setParser(std::function<ame_result(......
            {
                invokeParser = _invokeParser;
            }
            // Sets parser automatically
            ame_result setParser()
            {
                ...
                ...
                ...
            }

            // Sets args manually
            ame_result setArgs(std::vector<std::string> args)
            {
                ...
                ...
            }

            // Sets args automatically
            ame_result setArgs()
            {
                ...
                ...
            }

            ame_result populateCard(T &card, std::vector<std::string> input) {
                invokeParser(card, input, Args);
                ...
                ...
            }

        private:
            std::function<ame_result(T&, std::vector<std::string>, std::vector<std::string>) invokeParser;
            std::function<ame_result(T&, std::vector<std::string>, std::vector<std::string>) applyRegex;

            std:.vector<std::string> Args;
    }

/*

How I think this API should be used:

////
////
////

config.Dictionary = "JMDict";
AmeLibrary<Kanji> library(config);


library_result = library.Load();
if(!library_result.OK)
    return;

std::vector<Kanji> cardList;

for(auto& request in Requests)
{
    Kanji k;
    read_results r = library.populateCard(k, request);
    web_results w = library.downloadCardMedia(k, request);

    if(!r.OK || !w.OK)
        return;
    
    cardList.push_back(k);
}


AnkiDeck deck;
for(Kanji& k : cardList)
{
    AnkiCard card;
    for(Field& f : Template)
    {
        std::string field_str = k.RenderTemplate(f);
        Card.push_back(field_str);
    }
    deck.AddCard(card);
}


deck.save("New Anki Deck.txt");

////
////
////



Notice that on the previous thingy, the fact that we were working with objects of the class Kanji was never truly significant. So this leaves a possibility, for us to write:

void Ame::Run()
{
    ...
    ...
    ...
    switch(config.Mode)
    {
        case "Kanji":
            config.Dictionary = "JMdict";
            return Render<Kanji>();
    }
}

Template<Class T>
int Render()
{
    AmeLibrary<T> library(config);

    library_result = library.Load();
    if(!library_result.OK)
        return;

    std::vector<T> cardList;

    for(auto& request : Requests)
    {
        T c;
        // 
        read_results r = library.populateCard(*c, request);
        web_results w = library(*c);

        if(!read_results.OK || !web_results.OK)
            return;
        
        cardList.push_back(c);
    }

    AnkiDeck deck;
    for(T& c : cardList)
    {
        AnkiCard card;
        for(Field& f : Template)
        {
            std::string field_str = c.RenderTemplate(f);
            Card.push_back(field_str);
        }
        deck.AddCard(card);
    }


    deck.save("New Anki Deck.txt");

}
*/