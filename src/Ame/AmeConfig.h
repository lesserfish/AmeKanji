#pragma once

#include <ostream>
#include <vector>
#include <iostream>
#include <tuple>

namespace Ame
{

    typedef std::tuple<std::string, std::string> scfg;
    struct AmeConfig
    {
        std::string inputFile;
        std::string outputFile;
        std::string configurationFile;
        std::string logFile;
        std::string jishoFile;
        std::string Tag;
        std::string Mode;
        std::string forceOnlineMode;
        std::string ErrorAudioFile;
        std::string asdasd;
        std::string ErrorMD5;
        std::string noHumanOutput;
        std::string ignoreConfigurationFile;

        inline friend std::ostream& operator<<(std::ostream&os, AmeConfig &config)
        {
            std::vector<scfg> output = {
            scfg("Input file: " , config.inputFile),
            scfg("Output file: ", config.outputFile),
            scfg("Configuration file: ", config.configurationFile),
            scfg("Log file: ", config.logFile),
            scfg("Jisho file: ", config.jishoFile),
            scfg("Tag: ", config.Tag),
            scfg("Mode: ", config.Mode),
            scfg("Force online mode: ", config.forceOnlineMode),
            scfg("Error audio file: ", config.ErrorAudioFile),
            scfg("Error MD5: ", config.ErrorMD5),
            scfg("No human output: ", config.noHumanOutput),
            scfg("Ignore Configuration file: ", config.ignoreConfigurationFile),
            };

            std::string outputString = "";

            for(int i = 0; i < output.size(); i++)
            {
                outputString = outputString + std::get<0>(output.at(i)) + std::get<1>(output.at(i)) + "\n";
            }
            return os << outputString;
            
        }
    };

}