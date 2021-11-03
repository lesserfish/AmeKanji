#include "Core/ArgsParser.h"
#include "Ame/Ame.h"
#include "Core/Regex/Regex.h"
#include "Ame/Cards/Word.h"
#include "Ame/Jisho/Parsers/JMdict.h"
#include "Ame/Jisho/Library.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

int main(int argc, char **argv)
{
    Ame::AmeConfig config;
    Ame::AmeLibrary<Ame::Word> lib(config);


    // Loading the parser directly!
    
    lib.loadParserManually(Ame::JMdict::getInformation);
    Ame::Word word;
    Ame::ame_result o = lib.invokeParser(word, "/home/vchavauty/Documents/Code/AmeKanji/Repository/vocab/JMdict.xml", {"開ける"});
    std::cout << "Result: " << o.Message << std::endl;
    std::cout << word;
    
    // Loading the parser automatically through the configuration, but sending the dictionary manually
    config.Parser = "JMdict";
    Ame::AmeLibrary<Ame::Word> newlib(config);
    o = newlib.loadParserAutomatically();
    newlib.setDictionaryManually("/home/vchavauty/Documents/Code/AmeKanji/Repository/vocab/JMdict.xml", "file");
    newlib.invokeParser(word, {"試みる"}, {}, true);
    std::cout << word;

    // Loading everything through the configuration

    
    Ame::AmeLibrary<Ame::Word> newnewlib(config);
    config.ConfigurationFile = "/home/vchavauty/Documents/Code/AmeKanji/Repository/vocab/JMdict.xml";
    newnewlib.setDictionaryAutomatically();
    newnewlib.loadParserAutomatically();
    newnewlib.invokeParser(word, {"乳首"}, true);
    std::cout << word;
}
