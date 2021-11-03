#pragma once

#include "../StatusCodes.h"
#include <string>
#include <pugixml.hpp>

namespace Ame
{
    class Dictionary
    {
        public:
            virtual ~Dictionary(){};
            
            static ame_result loadDictionaryFromFile(pugi::xml_document& XMLDoc, std::string file)
            {
                ame_result output = ame_result(true, statusCode::OK);

                pugi::xml_parse_result result = XMLDoc.load_file(file.c_str());

                if(result.status != pugi::status_ok)
                    output = ame_result(false, statusCode::ERR);

                return output;
            }

            static ame_result loadDictionaryFromString(pugi::xml_document& XMLDoc, std::string content)
            {
                ame_result output(true, statusCode::OK);

                pugi::xml_parse_result result = XMLDoc.load_string(content.c_str());

                if(result.status != pugi::status_ok)
                    output = ame_result(false, statusCode::ERR);

                return output;
            }

    };
}