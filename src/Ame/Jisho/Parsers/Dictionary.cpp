#include "Dictionary.h"
#include <fstream>

namespace Ame
{
    Dictionary::Dictionary() : RegexMode(regexMode::None) {}
    
    int Dictionary::loadXMLRegexFromFile(std::string file)
    {
        int output = 0;

        pugi::xml_parse_result result = xml_regexInstruction.load_file(file.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        RegexMode = regexMode::XML;
        return output;
    }

    int Dictionary::loadXMLRegexFromString(std::string content)
    {

        int output = 0;

        pugi::xml_parse_result result = xml_regexInstruction.load_string(content.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        RegexMode = regexMode::XML;
        return output;
    }

    int Dictionary::loadTXTRegexFromFile(std::string file)
    {
        int output = 0;

        std::ifstream inputfile;
        inputfile.open(file, std::ios::in);

        if(!inputfile.is_open())
            return -1;
        
        std::string content;
        
        std::string Line;
        while(inputfile)
        {
            std::getline(inputfile, Line);
            content = content + Line + "\n";    
        }

        txt_regexInstruction = content;
        RegexMode = regexMode::UTF8;
        return output;
    }

    int Dictionary::loadTXTRegexFromString(std::string content)
    {
        txt_regexInstruction = content;
        RegexMode = regexMode::UTF8;

        return 0;
    }

    void Dictionary::setRegexMode(regexMode _Mode)
    {
        RegexMode = _Mode;
    }
}