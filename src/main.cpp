#include "Ame/Jisho/JMDict.h"
#include "Core/ArgsParser.h"
#include "Ame/Ame.h"
#include <assert.h>
#include <iostream>

int main(int argc, char **argv)
{
    Ame::Ame ame;

    int loadOutput = ame.loadArgs(argc, argv);
    int configOutput = ame.loadConfigurationFromFile();
    configOutput = ame.loadConfigurationFromString("Tag=159\n");
    ame.printConfiguration();

    Ame::JMDict jmdict;
    jmdict.loadXMLFromString("<template><field>This is the first Field: We have @kanji: &#28450;&#23383;</field><field>This is the second Field: We have @katakana: &lt;&#12363;&#12435;&#12376;&gt;</field><field>This is the third Field. There is nothing to see here!</field></template>");
}