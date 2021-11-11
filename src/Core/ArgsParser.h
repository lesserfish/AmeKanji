#pragma once

#include <vector>
#include <string>

namespace Core
{

    enum parseOutput
    {
        po_SUCCESS,
        po_MISSING_REQUIRED_PARAMETER,
        po_ADDITIONAL_PARAMETER_GIVEN,
        po_MISSING_INPUT
    };
    class ArgsParser
    {
    public:
        ArgsParser();
        ~ArgsParser();
        void generateArgument(std::string &output, std::string name, bool required = false, bool requiresInput = true, std::string defaultInput = "", bool copyDefaultInput = false);
        int Parse(int argc, char **argv, bool assertArgument = false);

    private:
        struct Argument
        {
            std::string &output;
            std::string name;
            bool required;
            bool requiresInput;
            std::string defaultInput;
            bool copyDefaultInput;
        };

        std::vector<Argument *> argList;
    };
}
