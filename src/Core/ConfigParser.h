#pragma once

#include <vector>
#include <string>

namespace Core{

    enum configParseOutput
    {
        cpo_SUCCESS,
        cpo_MISSING_REQUIRED_PARAMETER,
        cpo_ADDITIONAL_PARAMETER_GIVEN,
        cpo_MISSING_INPUT,
        cpo_MISSING_FILE
    };
    class ConfigParser
    {
        public:
            ConfigParser();
            ~ConfigParser();
            void generateArgument(const char *&output, const char *name, bool required = false);
            int Parse(const char *file, const char *separator = "=", bool assertArgument = false);
        private:

        struct Argument
        {
            const char *&output;
            const char* name;
            bool required;
        };

        std::vector<Argument*> argList;
        std::vector<std::string *> valList;
    };
}