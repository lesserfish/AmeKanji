#include "Ame.h"
#include <iostream>
#include <assert.h>

namespace Ame
{
    Ame::Ame(int argc, char **argv) : configInstance()
    {
        std::cout << "Initializing Ame!\n";

        int loadOutput = Load(argc, argv);

        assert(loadOutput == 0);
        assert(configInstance.configurationFile != NULL);

        int configOutput = loadConfigurationFile();
        
        assert(configOutput == 0);

    }
}