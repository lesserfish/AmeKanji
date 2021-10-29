#include "Ame.h"
#include <iostream>
#include <assert.h>
#include <cstring>
#include "outputMessages.h"

namespace Ame
{
    Ame::Ame(int argc, char **argv) : configInstance()
    {
        std::cout << "Initializing Ame!\n";

        int loadOutput = Load(argc, argv);

        assert(loadOutput == 0);

        if(configInstance.configurationFile != NULL);
        {
            if(std::strcmp(configInstance.configurationFile, "") != 0)
            {
                int configOutput = loadConfigurationFile();
                assert(configOutput == 0);
            }
        }

    }
}