#include "Dictionary.h"
#include <fstream>

namespace Ame
{
    Dictionary::Dictionary(){}
    
    ame_result Dictionary::loadXMLRegexFromFile(std::string file, unsigned int options, pugi::xml_encoding enconding)
    {
        ame_result output(true, statusCode::OK, "");

        pugi::xml_parse_result result = xml_regexInstruction.load_file(file.c_str(), options, enconding);

        if(result.status != pugi::status_ok)
            output = ame_result(false, statusCode::xml_ERR_LOAD);

        return output;
    }

    ame_result Dictionary::loadXMLRegexFromString(std::string content, unsigned int options)
    {

        ame_result output(true, statusCode::OK, "");

        pugi::xml_parse_result result = xml_regexInstruction.load_string(content.c_str(), options);

        if(result.status != pugi::status_ok)
            output = ame_result(false, statusCode::xml_ERR_LOAD);

        return output;
    }

}