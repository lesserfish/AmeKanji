#include "Dictionary.h"

namespace Ame
{
    Dictionary::Dictionary(){}
    
    int Dictionary::loadXMLFromFile(std::string File)
    {
        int output = 0;

        pugi::xml_parse_result result = XMLDoc.load_file(File.c_str());

        if(result.status != pugi::status_ok)
            output = 1;
        return output;
    }

    int Dictionary::loadXMLFromString(std::string Content)
    {

        int output = 0;

        pugi::xml_parse_result result = XMLDoc.load_string(Content.c_str());

        if(result.status != pugi::status_ok)
            output = 1;
        return output;
    }
}