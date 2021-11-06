#include "Ame.h"
#include <iostream>

namespace Ame
{
    Ame::Ame() : configInstance(), stdout_callback([=](std::string input){ return; })
    {
        std::cout << "Ame Initialized!\n";
    }
    Ame::Ame(int argc, char **argv) : configInstance()
    {
        std::cout << "Ame Initialized!\n";
        loadArgs(argc, argv);   
    }

    ame_result Ame::Go()
    {
        return ame_result();
    }
}