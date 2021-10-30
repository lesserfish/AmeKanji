#pragma once

#include <tuple>
#include <iostream>
#include <string>
#include <cstring>

namespace Ame
{

    enum AME_OUTPUT_MESSAGES{
        E_NO_CONFIG_FILE,
        E_NO_INPUT_FILE,
        E_DEFAULT,
        S_DEFAULT,
        W_UNRCGZ_WRD,
        I_LD_ARGS,
        I_LD_CFG
    };
    typedef std::tuple<AME_OUTPUT_MESSAGES, const char *, const char *> omsg;
    static omsg outputMessages[] = {omsg(AME_OUTPUT_MESSAGES::E_NO_CONFIG_FILE, "E!NO_CONFIG_FILE", "Error! Failed to find the configuration file!"),
                                    omsg(AME_OUTPUT_MESSAGES::E_NO_INPUT_FILE ,"E!NO_INPUT_FILE", "Error! Failed to find the input file!"),
                                    omsg(AME_OUTPUT_MESSAGES::E_DEFAULT ,"E!", "Error! No further information available!"),
                                    omsg(AME_OUTPUT_MESSAGES::S_DEFAULT ,"S!", "Success! Everything worked out well!"),
                                    omsg(AME_OUTPUT_MESSAGES::W_UNRCGZ_WRD ,"W!UNRCGNZ_WRD", "Warning! Fail to recognize the following word: "),
                                    omsg(AME_OUTPUT_MESSAGES::I_LD_ARGS ,"I!LD_FRM_ARGS", "Loading from Args!"),
                                    omsg(AME_OUTPUT_MESSAGES::I_LD_CFG ,"I!LD_FRM_CFG", "Loading from Config!")};


    static void printOutputMessage(AME_OUTPUT_MESSAGES Message, bool robotReadable = false, const char *end = "\n")
    {
        std::string outMsg = "";
        int messageCount = sizeof(outputMessages) / sizeof(omsg);

        for(int i = 0; i < messageCount; i++)
        {
            if(Message == std::get<0>(outputMessages[i]))
            {
                outMsg = robotReadable ? std::string(std::get<1>(outputMessages[i])) : std::string(std::get<2>(outputMessages[i]));
                outMsg = outMsg + std::string(end);

                std::cout << outMsg;
                return;
            }
        }
    }
    
    static void printOutputMessage(AME_OUTPUT_MESSAGES Message, std::string cc_robotReadable, std::string end = "\n")
    {

        bool humanReadable;
        
        humanReadable = cc_robotReadable == "false" ? false : true;

        std::string outMsg = "";
        int messageCount = sizeof(outputMessages) / sizeof(omsg);

        for(int i = 0; i < messageCount; i++)
        {
            if(Message == std::get<0>(outputMessages[i]))
            {
                outMsg = humanReadable ? std::string(std::get<2>(outputMessages[i])) : std::string(std::get<1>(outputMessages[i]));
                outMsg = outMsg + std::string(end);

                std::cout << outMsg;
                return;
            }
        }
    }
}