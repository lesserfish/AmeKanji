#include <iostream>
#include <string>
#include "ArgsParser.h"

namespace Core
{
    ArgsParser::ArgsParser() : argList() {}

    ArgsParser::~ArgsParser()
    {
        while (!argList.empty())
        {
            Argument *arg = argList.at(argList.size() - 1);
            argList.pop_back();
            free(arg);
        }
    }
    void ArgsParser::generateArgument(std::string &output, std::string name, bool required, bool requiresInput, std::string defaultInput, bool copyDefaultInput)
    {
        Argument *arg = new Argument{output, name, required, requiresInput, defaultInput, copyDefaultInput};
        argList.push_back(arg);
    }
    int ArgsParser::Parse(int argc, char **argv, bool assertArgument)
    {
        std::vector<Argument *> missingParameters = argList;
        int position = 0;
        while (++position < argc)
        {
		std::string val = argv[position];

            bool argFound = false;
            for (int i = 0; i < missingParameters.size(); i++)
            {
                Argument *arg = missingParameters.at(i);
                if (val == arg->name)
                {
                    if (arg->requiresInput)
                    {
                        if (++position >= argc)
                            return parseOutput::po_MISSING_INPUT;
                        
                        arg->output = std::string(argv[position]);
                        missingParameters.erase(missingParameters.begin() + i);
                        argFound = true;
                        break;
                    }
                    else
                    {
                        arg->output = arg->defaultInput;
                        missingParameters.erase(missingParameters.begin() + i);
                        argFound = true;
                        break;
                    }
                }
            }
            if(!argFound & assertArgument)
                return parseOutput::po_ADDITIONAL_PARAMETER_GIVEN;
        }
        for (int i = 0; i < missingParameters.size(); i++)
        {
            Argument *arg = missingParameters.at(i);
            if (arg->required == true)
                return parseOutput::po_MISSING_REQUIRED_PARAMETER;
            if(arg->copyDefaultInput == true)
                arg->output = arg->defaultInput;
        }
        
        return parseOutput::po_SUCCESS;
    }
}
