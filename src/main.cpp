#include "Ame/Jisho/Vocabdict.h"
#include "Core/ArgsParser.h"
#include "Ame/Ame.h"
#include <assert.h>
#include <iostream>
#include "Ame/Jisho/Regex/Regex.h"
#include <vector>
#include <string>

int main(int argc, char **argv)
{
    //Ame::Ame ame;

    //int loadOutput = ame.loadArgs(argc, argv);
    //int configOutput = ame.loadConfigurationFromFile();
    //configOutput = ame.loadConfigurationFromString("Tag=159\n");
    //ame.printConfiguration();

    //Ame::VocabDict vocabDict;
    //vocabDict.loadXMLFromString("<template><field>This is the first Field: We have @kanji: &#28450;&#23383;</field><field>This is the second Field: We have @katakana: &lt;&#12363;&#12435;&#12376;&gt;</field><field>This is the third Field. There is nothing to see here!</field></template>");
    //vocabDict.loadUTF8FromFile("test.txt");

    Ame::RegexInstruction ri(Ame::regOP::MATCH, "\\d", "");
    ri = Ame::RegexInstruction(Ame::regOP::REPLACE, "\\d", "VICTOR");
    Ame::RegexOrder ro(ri);

    std::vector<std::string> re = Ame::ParseRegex(ro, "abc1def2hij3v");

    for(std::string& s : re)
    {
        std::cout << s << std::endl;
    }
}