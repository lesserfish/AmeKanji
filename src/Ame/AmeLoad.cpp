#include "Ame.h"
#include "outputMessages.h"
#include "StatusCodes.h"
#include "../Core/ArgsParser.h"
#include "../Core/ConfigParser.h"
#include <iostream>

namespace Ame
{

    ame_result Ame::load_stdout_callback(std::function<void(std::string)> Func)
    {
        stdout_callback = Func;
        return ame_result();
    }
    ame_result Ame::loadArgs(int argc, char **argv)
    {
        ame_result output(true, statusCode::OK);

        Core::ArgsParser argParser;


        /*argParser.generateArgument(configInstance.inputFile, "-input");
        argParser.generateArgument(configInstance.outputFile, "-output");
        argParser.generateArgument(configInstance.configurationFile, "-config");
        argParser.generateArgument(configInstance.logFile, "-log");
        argParser.generateArgument(configInstance.Tag, "-tag");
        argParser.generateArgument(configInstance.ErrorMD5, "-md5");
*/
        int parseOutput = argParser.Parse(argc, argv);
        if(parseOutput != Core::parseOutput::po_SUCCESS)
        {
            output.OK = false;
            //TODO: HANDLE ERROR PROPERLY
            switch(parseOutput)
            {
                case Core::configParseOutput::cpo_ADDITIONAL_PARAMETER_GIVEN: output.value = statusCode::conf_ERR_ADDITIONAL_PARAMETER_GIVEN;
                case Core::configParseOutput::cpo_MISSING_INPUT: output.value = statusCode::conf_MISSING_INPUT;
                case Core::configParseOutput::cpo_MISSING_REQUIRED_PARAMETER:  output.value = statusCode::conf_ERR_MISSING_REQUIRED_PARAMETER;
                case Core::configParseOutput::cpo_MISSING_FILE: output.value = statusCode::conf_MISSING_CONFIG_FILE;
                default: output.value = statusCode::ERR;
            }
        }

        return output;
    }

    ame_result Ame::loadConfigurationFromFile(std::string file)
    {

        ame_result output(true, statusCode::OK, "");

        Core::ConfigParser configParser;
/*
        configParser.generateArgument(configInstance.logFile, "Log");
        configParser.generateArgument(configInstance.Tag, "Tag");
*/
        
        if(file == "")
            file = configInstance.ConfigurationFile;

        int configOutput = configParser.Parse(file, "=", false);
        
        if(configOutput != Core::configParseOutput::cpo_SUCCESS)
        {
            output.OK = false;
            //TODO: HANDLE ERROR PROPERLY
            switch(configOutput)
            {
                case Core::configParseOutput::cpo_ADDITIONAL_PARAMETER_GIVEN: output.value = statusCode::conf_ERR_ADDITIONAL_PARAMETER_GIVEN;
                case Core::configParseOutput::cpo_MISSING_INPUT: output.value = statusCode::conf_MISSING_INPUT;
                case Core::configParseOutput::cpo_MISSING_REQUIRED_PARAMETER:  output.value = statusCode::conf_ERR_MISSING_REQUIRED_PARAMETER;
                case Core::configParseOutput::cpo_MISSING_FILE: output.value = statusCode::conf_MISSING_CONFIG_FILE;
                default: output.value = statusCode::ERR;
            }
        }

        return output;
    }

    ame_result Ame::loadConfigurationFromString(std::string config)
    {
        
        ame_result output(true, statusCode::OK, "");

        Core::ConfigParser configParser;

        configParser.generateArgument(configInstance.SplitStdout, "splitstdout");
/*        configParser.generateArgument(configInstance.logFile, "Log");
        configParser.generateArgument(configInstance.Tag, "Tag");
*/
        
        int configOutput = configParser.ParseFromString(config, "=", false);
        
        if(configOutput != Core::configParseOutput::cpo_SUCCESS)
        {
            output.OK = false;
            //TODO: HANDLE ERROR PROPERLY
            switch(configOutput)
            {
                case Core::configParseOutput::cpo_ADDITIONAL_PARAMETER_GIVEN: output.value = statusCode::conf_ERR_ADDITIONAL_PARAMETER_GIVEN;
                case Core::configParseOutput::cpo_MISSING_INPUT: output.value = statusCode::conf_MISSING_INPUT;
                case Core::configParseOutput::cpo_MISSING_REQUIRED_PARAMETER:  output.value = statusCode::conf_ERR_MISSING_REQUIRED_PARAMETER;
                case Core::configParseOutput::cpo_MISSING_FILE: output.value = statusCode::conf_MISSING_CONFIG_FILE;
                default: output.value = statusCode::ERR;
            }
        }

        return output;
    }

    ame_result Ame::preRunChecklist()
    {
        ame_result output(true, statusCode::OK);

/*        if(configInstance.inputFile == "") return -1;
        if(configInstance.outputFile == "") return -1;
  */      
        return output;
    }
}