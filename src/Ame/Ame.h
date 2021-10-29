#pragma once

#include "AmeConfig.h"

namespace Ame
{
    class Ame
    {
        public:
            Ame(int argc, char **argv);
        private:
            int Load(int argc, char **argv);
            int loadConfigurationFile();
            int assertRequiredConfig();
            int Run();
            AmeConfig configInstance;
    };
}