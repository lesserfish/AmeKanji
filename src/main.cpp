#include "Core/ArgsParser.h"
#include "Ame/Ame.h"
#include "Core/Regex/Regex.h"
#include "Ame/Cards/Word.h"
#include "Ame/Jisho/Parsers/JMdict.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>


int main(int argc, char **argv)
{
    Ame::Ame ame;

    int loadOutput = ame.loadArgs(argc, argv);
    ame.debug();
    //int configOutput = ame.loadConfigurationFromFile();
    //configOutput = ame.loadConfigurationFromString("Tag=159\n");
    //ame.printConfiguration();

    //Ame::VocabDict vocabDict;
    //vocabDict.loadXMLFromString("<template><field>This is the first Field: We have @kanji: &#28450;&#23383;</field><field>This is the second Field: We have @katakana: &lt;&#12363;&#12435;&#12376;&gt;</field><field>This is the third Field. There is nothing to see here!</field></template>");
    //vocabDict.loadUTF8FromFile("test.txt");

    /*Core::RegexInstruction ri(Core::regOP::MATCH, "\\d", "");
    ri = Core::RegexInstruction(Core::regOP::REPLACE, "\\d", "VICTOR");
    Core::RegexOrder ro(ri);

    std::vector<std::string> re = Core::ParseRegex(ro, "abc1def2hij3v");

    for(std::string& s : re)
    {
        std::cout << s << std::endl;
    }*/

    Ame::JMdict jm;

    int r = jm.loadDictionaryFromFile("/home/vchavauty/Documents/Code/AmeKanji/Repository/vocab/JMdict.xml");
    std::cout << "Result: " << r << std::endl;

    Ame::Word w;
    Ame::parse_output o = jm.getWordInformation(w, "開ける", "ひらける");
    std::cout << "Result: " << o.Message << std::endl;
    w.Print();
}
