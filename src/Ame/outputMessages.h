#pragma once

#include <string>
#include <sstream>

namespace Ame
{
    void Ame::AmePrint(std::string Content)
    {
        if (configInstance.SplitStdout == "true")
        {
            std::istringstream iss(Content);
            std::string Line;
            while (iss)
            {
                iss >> Line;
                stdout_callback(Line);
            }
        }
        else
        {
            stdout_callback(Content);
        }
    }
}