#include <iostream>
#include <string>
#include <fstream>
#include <boost/tokenizer.hpp>
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
    void ConfigParser::generateArgument(const char *&output, const char *name, bool required)
    {
        Argument *arg = new Argument{output, name, required};
        argList.push_back(arg);
    }
    int ConfigParser::Parse(const char *file, const char *separator, bool assertArgument)
    {
        std::vector<Argument *> missingParameters = argList;

        std::ifstream inputFile;
        inputFile.open(file, std::ios::in);

        if(!inputFile)
        {
            std::cout << "Failed reading file!";
            return configParseOutput::cpo_MISSING_FILE;
        }
        else
        {
            std::string Line;
            while (getline(inputFile, Line))
            {
                
                std::vector<std::string> splitLine;
                
                boost::char_separator<char> sep(separator);
                boost::tokenizer<boost::char_separator<char>> tok{Line, sep};

                for(const auto &t : tok)
                {
                    std::string l = std::string(t);
                    splitLine.push_back(l);
                }
                
                if(splitLine.size() < 2)
                    continue;
                
                
                const char *val = splitLine.at(0).c_str();

                bool argFound = false;

                for(int i = 0; i < missingParameters.size(); i++)
                {
                    Argument *arg = missingParameters.at(i);
                    if(std::string(val) == std::string(arg->name))
                    {
                        std::string *soutput = new std::string("");
                        for(int j = 1; j < splitLine.size(); j++)
                        {
                            *soutput = *soutput + std::string(separator) + splitLine.at(j);
                        }
                        
                        valList.push_back(soutput);
                        arg->output = soutput->c_str(); 
                        missingParameters.erase(missingParameters.begin() + i);
                        argFound = true;
                        break;
                    }
                }

                if(!argFound & assertArgument)
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
}