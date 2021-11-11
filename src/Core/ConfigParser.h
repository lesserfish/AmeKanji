#pragma once

#include <vector>
#include <string>
#include <pugixml.hpp>

namespace Core
{

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
        void generateArgument(std::string &output, std::string name, bool required = false);
        int Parse(std::string file, std::string = "=", bool assertArgument = false);
        int ParseFromString(std::string Content, std::string separator = "=", bool assertArgument = false);
        int ParseFromXML(std::string rootNode, pugi::xml_document &XMLDoc, bool assertArgument = false);
        int ParseFromXML(std::string rootNode, std::string XMLContent, bool assertArgument = false);

    private:
        struct Argument
        {
            std::string &output;
            std::string name;
            bool required;
        };

        std::vector<Argument *> argList;
        std::vector<std::string *> valList;
    };
}