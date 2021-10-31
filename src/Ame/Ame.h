#pragma once

#include "AmeConfig.h"
#include <string>

namespace Ame
{
    class Ame
    {
        public:
            Ame(int argc, char **argv);
            Ame();

            int loadArgs(int argc, char **argv);

            int loadConfigurationFromString(std::string config = "");
            int loadConfigurationFromFile(std::string file = "");

            int preRunChecklist();
            int Run();


            int loadTemplateFromFile(std::string file = "");
            int loadTemplateFromString(std::string cTemplate);

            int loadWordlistFromFile(std::string file = "");
            int loadWordlistFromString(std::string cWordlist);

            void printConfiguration();

            void debug();
        private:
            AmeConfig configInstance;
    };
}