#pragma once

#include <tuple>
#include <iostream>
#include <string>

namespace Ame
{
    typedef std::tuple<const char *, const char *> omsg;
    static omsg outputMessages[] = {omsg("E!NO_CONFIG_FILE", "Error! Failed to find the configuration file!"),
                                    omsg("E!NO_INPUT_FILE", "Error! Failed to find the input file!"),
                                    omsg("E!", "Error! No further information available!"),
                                    omsg("S!", "Success! Everything worked out well!"),
                                    omsg("W!UNRCGNZ_WRD", "Warning! Fail to recognize the following word: ")};


    static void printOutputMessage(const char *Message, bool humanReadable = false, const char *end = "")
    {
        std::string outMsg = "";
        int messageCount = sizeof(outputMessages) / sizeof(omsg);

        for(int i = 0; i < messageCount; i++)
        {
            if(std::string(Message) == std::string(std::get<0>(outputMessages[i])))
            {
                outMsg = humanReadable ? std::string(std::get<1>(outputMessages[i])) : std::string(std::get<0>(outputMessages[i]));
                outMsg = outMsg + std::string(end);

                std::cout << outMsg;
                return;
            }
        }
    }
}