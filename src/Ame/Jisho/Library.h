#pragma once

#include <tuple>
#include <vector>
#include <functional>
#include <pugixml.hpp>
#include <memory>
#include "../AmeConfig.h"
#include "../StatusCodes.h"
#include "../Web/AmeWeb.h"
#include "Dictionary.h"


namespace Ame
{
    enum class CardMode {None, Manual, Kanji, Word};
    enum class ParserMode {None, Manual, Edict, JMdict, Kanjidic, NewKanjidic};

   template<class K> 
    class AmeLibrary
    {
        public:
            AmeLibrary(AmeConfig &config);
        /*    ame_result Load();

            ame_result invokeParser(K &output, std::vector<std::string> input, std::vector<std::string> args = {});
            ame_result invokeRegex(K &output, std::vector<std::string> args = {});
            ame_result invokeWebparser(K &output, std::vector<std::string> Args = {});
            template<class D>
            ame_result loadDictionaryManually(D& instance);
            template<class D>
            ame_result loadDictionaryManually();
            ame_result loadDictionary();
            template<class W>
            ame_result loadWebparserManually(W& instance);
            ame_result loadWebparserManually();
            ame_result loadWebparser();*/

        private:
          /*  std::shared_ptr<Dictionary> dictionaryInstance;
            std::shared_ptr<AmeWeb> webParser;*/
            AmeConfig &configInstance;
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