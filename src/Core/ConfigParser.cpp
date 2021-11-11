#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "ConfigParser.h"

namespace Core
{
    ConfigParser::ConfigParser() : argList(), valList() {}

    ConfigParser::~ConfigParser()
    {
        while (!argList.empty())
        {
            Argument *arg = argList.at(argList.size() - 1);
            argList.pop_back();
            free(arg);
        }
        while (!valList.empty())
        {
            std::string *val = valList.at(valList.size() - 1);
            valList.pop_back();
            free(val);
        }
    }
    void ConfigParser::generateArgument(std::string &output, std::string name, bool required)
    {
        Argument *arg = new Argument{output, name, required};
        argList.push_back(arg);
    }
    int ConfigParser::Parse(std::string file, std::string separator, bool assertArgument)
    {
        std::vector<Argument *> missingParameters = argList;

        std::ifstream inputFile;
        inputFile.open(file, std::ios::in);

        if (!inputFile)
        {
            return configParseOutput::cpo_MISSING_FILE;
        }
        else
        {
            std::string Line;
            while (getline(inputFile, Line))
            {

                bool argFound = false;

                int index = Line.find(separator);

                if (index == std::string::npos || index >= Line.length() - 1)
                    continue;

                std::string name = Line.substr(0, index);
                std::string value = Line.substr(index + 1, Line.length());

                for (int i = 0; i < missingParameters.size(); i++)
                {
                    Argument *arg = missingParameters.at(i);
                    if (name == arg->name)
                    {
                        arg->output = value;
                        missingParameters.erase(missingParameters.begin() + i);
                        argFound = true;
                        break;
                    }
                }

                if (!argFound & assertArgument)
                    return configParseOutput::cpo_ADDITIONAL_PARAMETER_GIVEN;
            }
        }

        inputFile.close();

        for (int i = 0; i < missingParameters.size(); i++)
        {
            Argument *arg = missingParameters.at(i);
            if (arg->required == true)
                return configParseOutput::cpo_MISSING_REQUIRED_PARAMETER;
        }

        return configParseOutput::cpo_SUCCESS;
    }

    int ConfigParser::ParseFromString(std::string Content, std::string separator, bool assertArgument)
    {
        std::vector<Argument *> missingParameters = argList;

        std::istringstream ContentStream(Content);

        std::string Line;
        while (getline(ContentStream, Line))
        {
            bool argFound = false;

            int index = Line.find(separator);

            if (index == std::string::npos || index >= Line.length() - 1)
                continue;

            std::string name = Line.substr(0, index);
            std::string value = Line.substr(index + 1, Line.length());

            for (int i = 0; i < missingParameters.size(); i++)
            {
                Argument *arg = missingParameters.at(i);
                if (name == arg->name)
                {
                    arg->output = value;
                    missingParameters.erase(missingParameters.begin() + i);
                    argFound = true;
                    break;
                }
            }

            if (!argFound & assertArgument)
                return configParseOutput::cpo_ADDITIONAL_PARAMETER_GIVEN;
        }

        for (int i = 0; i < missingParameters.size(); i++)
        {
            Argument *arg = missingParameters.at(i);
            if (arg->required == true)
                return configParseOutput::cpo_MISSING_REQUIRED_PARAMETER;
        }

        return configParseOutput::cpo_SUCCESS;
    }
    int ConfigParser::ParseFromXML(std::string rootNode, pugi::xml_document &XMLDoc, bool assertArgument)
    {
        std::vector<Argument *> missingParameters = argList;

        pugi::xml_node root = XMLDoc.child(rootNode.c_str());
        for (pugi::xml_node arg = root.first_child(); arg; arg = arg.next_sibling())
        {
            std::string argname = arg.name();
            std::string argval = arg.text().as_string();

            bool argFound = false;

            for (int i = 0; i < missingParameters.size(); i++)
            {
                Argument *arg = missingParameters.at(i);
                if (argname == arg->name)
                {
                    arg->output = argval;
                    missingParameters.erase(missingParameters.begin() + i);
                    argFound = true;
                    break;
                }
            }

            if (!argFound & assertArgument)
                return configParseOutput::cpo_ADDITIONAL_PARAMETER_GIVEN;
        }

        for (int i = 0; i < missingParameters.size(); i++)
        {
            Argument *arg = missingParameters.at(i);
            if (arg->required == true)
                return configParseOutput::cpo_MISSING_REQUIRED_PARAMETER;
        }

        return configParseOutput::cpo_SUCCESS;
    }
    int ConfigParser::ParseFromXML(std::string rootNode, std::string XMLContent, bool assertArgument)
    {
        std::vector<Argument *> missingParameters = argList;

        pugi::xml_document XMLDoc;
        XMLDoc.load_string(XMLContent.c_str());
        pugi::xml_node root = XMLDoc.child(rootNode.c_str());
        for (pugi::xml_node arg = root.first_child(); arg; arg = arg.next_sibling())
        {
            std::string argname = arg.name();
            std::string argval = arg.text().as_string();
            bool argFound = false;

            for (int i = 0; i < missingParameters.size(); i++)
            {
                Argument *arg = missingParameters.at(i);
                if (argname == arg->name)
                {
                    arg->output = argval;
                    missingParameters.erase(missingParameters.begin() + i);
                    argFound = true;
                    break;
                }
            }

            if (!argFound & assertArgument)
                return configParseOutput::cpo_ADDITIONAL_PARAMETER_GIVEN;
        }

        for (int i = 0; i < missingParameters.size(); i++)
        {
            Argument *arg = missingParameters.at(i);
            if (arg->required == true)
                return configParseOutput::cpo_MISSING_REQUIRED_PARAMETER;
        }

        return 0;
    }

}