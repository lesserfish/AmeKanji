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

}