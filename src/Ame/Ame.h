#pragma once

#include "AmeConfig.h"
#include "ErrorCodes.h"
#include <string>

namespace Ame
{
    class Ame
    {
        public:
            Ame(int argc, char **argv);
            Ame();

            ame_result loadArgs(int argc, char **argv);

            ame_result loadConfigurationFromString(std::string config = "");
            ame_result loadConfigurationFromFile(std::string file = "");

            ame_result preRunChecklist();
            ame_result Run();


            ame_result loadTemplateFromFile(std::string file = "");
            ame_result loadTemplateFromString(std::string cTemplate);

            ame_result loadWordlistFromFile(std::string file = "");
            ame_result loadWordlistFromString(std::string cWordlist);

            void printConfiguration();

            void debug();
        private:
            AmeConfig configInstance;
    };
}