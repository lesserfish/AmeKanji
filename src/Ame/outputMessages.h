#pragma once

#include <tuple>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>


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
    static const std::vector<omsg> outMessages = {omsg(AME_OUTPUT_MESSAGES::E_NO_CONFIG_FILE, "E!NO_CONFIG_FILE", "Error! Failed to find the configuration file!"),
                                    omsg(AME_OUTPUT_MESSAGES::E_NO_INPUT_FILE ,"E!NO_INPUT_FILE", "Error! Failed to find the input file!"),
                                    omsg(AME_OUTPUT_MESSAGES::E_DEFAULT ,"E!", "Error! No further information available!"),
                                    omsg(AME_OUTPUT_MESSAGES::S_DEFAULT ,"S!", "Success! Everything worked out well!"),
                                    omsg(AME_OUTPUT_MESSAGES::W_UNRCGZ_WRD ,"W!UNRCGNZ_WRD", "Warning! Fail to recognize the following word: "),
                                    omsg(AME_OUTPUT_MESSAGES::I_LD_ARGS ,"I!LD_FRM_ARGS", "Loading from Args!"),
                                    omsg(AME_OUTPUT_MESSAGES::I_LD_CFG ,"I!LD_FRM_CFG", "Loading from Config!")};


    static void printOutputMessage(AME_OUTPUT_MESSAGES Message, bool robotReadable = false, std::string end = "\n")
    {
        std::string outMsg = "";
        int messageCount = outMessages.size();

        for(int i = 0; i < messageCount; i++)
        {
            if(Message == std::get<0>(outMessages[i]))
            {
                outMsg = robotReadable ? std::string(std::get<1>(outMessages[i])) : std::string(std::get<2>(outMessages[i]));
                outMsg = outMsg + end;

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
        int messageCount = outMessages.size();

        for(int i = 0; i < messageCount; i++)
        {
            if(Message == std::get<0>(outMessages[i]))
            {
                outMsg = humanReadable ? std::string(std::get<2>(outMessages[i])) : std::string(std::get<1>(outMessages[i]));
                outMsg = outMsg + end;

                std::cout << outMsg;
                return;
            }
        }
    }
}