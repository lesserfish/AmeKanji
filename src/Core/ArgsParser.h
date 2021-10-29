#pragma once

#include <vector>

namespace Core{

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
            void generateArgument(const char *&output, const char *name, bool required = false, bool requiresInput = true, const char *defaultInput = "", bool copyDefaultInput = false);
            int Parse(int argc, char **argv, bool assertArgument = false);
        private:

        struct Argument
        {
            const char *&output;
            const char* name;
            bool required;
            bool requiresInput;
            const char *defaultInput;
            bool copyDefaultInput;
        };

        std::vector<Argument*> argList;
    };
}