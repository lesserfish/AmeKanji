#include "Ame.h"
#include <iostream>
#include <assert.h>
#include <cstring>
#include "outputMessages.h"

namespace Ame
{
    Ame::Ame() : configInstance()
    {
        std::cout << "Ame Initialized!\n";
    }
    Ame::Ame(int argc, char **argv) : configInstance()
    {
        std::cout << "Ame Initialized!\n";
        loadArgs(argc, argv);   
    }
    void Ame::printConfiguration()
    {
        std::cout << configInstance;
    }
}