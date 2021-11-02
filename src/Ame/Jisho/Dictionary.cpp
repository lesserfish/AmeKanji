#include "Dictionary.h"
#include <fstream>

namespace Ame
{
    Dictionary::Dictionary(){}
    
    int Dictionary::loadXMLRegexFromFile(std::string file)
    {
        int output = 0;

        pugi::xml_parse_result result = xml_regexInstruction.load_file(file.c_str(), 116U, pugi::encoding_utf8);

        if(result.status != pugi::status_ok)
            output = 1;

        return output;
    }

    int Dictionary::loadXMLRegexFromString(std::string content)
    {

        int output = 0;

        pugi::xml_parse_result result = xml_regexInstruction.load_string(content.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        return output;
    }

}