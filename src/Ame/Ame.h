#pragma once

#include "AmeConfig.h"
#include "StatusCodes.h"
#include <string>
#include <functional>
#include <pugixml.hpp>

namespace Ame
{
    class Ame
    {
        public:
            Ame(int argc, char **argv);
            Ame();

            ame_result loadArgs(int argc, char **argv);
            ame_result load_stdout_callback(std::function<void(std::string)> Func);

            ame_result loadConfigurationFromString(std::string config = "");
            ame_result loadConfigurationFromFile(std::string file = "");
            ame_result loadConfigurationFromXML(std::string XMLContent, std::string rootNode = "ame");
            ame_result loadConfigurationFromXML(pugi::xml_document &XMLDoc, std::string rootNode = "ame");

            ame_result preRunChecklist();
            ame_result Run();

            ame_result loadTemplateFromFile(std::string file = "");
            ame_result loadTemplateFromString(std::string cTemplate);

            ame_result loadWordlistFromFile(std::string file = "");
            ame_result loadWordlistFromString(std::string cWordlist);

            void AmePrint(std::string content);
            // TODO: Remove this, make AmeConfig public and overload << operator. Also, add method to load config directly from an instance of AmeConfig.
            void printConfiguration();

            // TODO: Remove this.
            void debug();

            /*
            
            */
        private:
            AmeConfig configInstance;
            std::function<void(std::string)> stdout_callback;
    };
}