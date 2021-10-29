#include "Ame.h"
#include "ErrorCodes.h"
#include "../Core/ArgsParser.h"
#include "../Core/ConfigParser.h"
#include <iostream>

namespace Ame
{
    int Ame::Load(int argc, char **argv)
    {
        int output = 0;
        
        Core::ArgsParser argParser;

        argParser.generateArgument(configInstance.inputFile, "-input", true, true, "", false);
        argParser.generateArgument(configInstance.outputFile, "-output", false, true, "New Anki Deck.txt", true);
        argParser.generateArgument(configInstance.configurationFile, "-config", false, true, "Config/config.cfg", true);
        argParser.generateArgument(configInstance.logFile, "-log", false, true, "Log.txt", true);
        argParser.generateArgument(configInstance.Tag, "-tag", false, true, "", true);
        argParser.generateArgument(configInstance.ignoreConfigurationFile, "-ignoreConfig", false, false, "true", false);


        int parseOutput = argParser.Parse(argc, argv);
        if(parseOutput != Core::parseOutput::po_SUCCESS)
        {
            //TODO: HANDLE ERROR PROPERLY
            std::cout << "Error! The argument parser failed!\n";
            switch(parseOutput)
            {
                case Core::parseOutput::po_ADDITIONAL_PARAMETER_GIVEN: output = ameError::ame_ARGPARSER_ADDITIONAL_PARAMETER_GIVEN;
                case Core::parseOutput::po_MISSING_INPUT: output = ameError::ame_ARGPARSER_MISSING_INPUT;
                case Core::parseOutput::po_MISSING_REQUIRED_PARAMETER:  output = ameError::ame_ARGPARSER_MISSING_REQUIRED_PARAMETER;
                default: output = -1;
            }
        }

        return output;
    }

    int Ame::loadConfigurationFile()
    {
        int output = 0;

        Core::ConfigParser configParser;

        configParser.generateArgument(configInstance.logFile, "Log", false);
        configParser.generateArgument(configInstance.Tag, "Tag", false);

        int configOutput = configParser.Parse(configInstance.configurationFile, "=", false);
        
        if(configOutput != Core::configParseOutput::cpo_SUCCESS)
        {
            //TODO: HANDLE ERROR PROPERLY
            std::cout << "Error! The argument parser failed!\n";
            switch(configOutput)
            {
                case Core::configParseOutput::cpo_ADDITIONAL_PARAMETER_GIVEN: output = ameError::ame_ARGPARSER_ADDITIONAL_PARAMETER_GIVEN;
                case Core::configParseOutput::cpo_MISSING_INPUT: output = ameError::ame_ARGPARSER_MISSING_INPUT;
                case Core::configParseOutput::cpo_MISSING_REQUIRED_PARAMETER:  output = ameError::ame_ARGPARSER_MISSING_REQUIRED_PARAMETER;
                case Core::configParseOutput::cpo_MISSING_FILE: output = ameError::ame_ARGPARSER_MISSING_CONFIG_FILE;
                default: output = -1;
            }
        }

        return output;
    }

    int Ame::assertRequiredConfig()
    {
        int output = 0;

        if(configInstance.inputFile == NULL) return -1;
        if(configInstance.outputFile == NULL) return -1;
        
        return output;
    }
}