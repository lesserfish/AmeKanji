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


void p(std::string C)
{
    std::cout << "ASDASDSAD> " <<C;
}
int main(int argc, char **argv)
{
    Ame::AmeConfig config;
    Ame::AmeLibrary<Ame::Word> lib(config);

    //std::vector<std::string> test = Core::ParseRegex(Core::RegexOrder(Core::RegexInstruction(Core::regOP::REPLACE, "2", "4")), "222333");
    //std::cout << test[0] << std::endl;
    pugi::xml_document Regexdoc;
    Regexdoc.load_file("/home/vchavauty/Documents/Code/AmeKanji/tmp/regex.xml");

    // Loading the parser directly!
    
    lib.loadParserManually(Ame::JMdict::getInformation);
    lib.loadRegexParserManually(Ame::JMdict::applyRegexXML);
    Ame::Word word;
    Ame::ame_result o = lib.invokeParser(word, "/home/vchavauty/Documents/Code/AmeKanji/Repository/vocab/JMdict.xml", {"開ける"});
    std::cout << word;
    o = lib.InvokeRegex(word, Regexdoc, {});
    std::cout << word;
    
}
