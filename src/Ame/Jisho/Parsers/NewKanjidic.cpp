#include "NewKanjidic.h"

namespace Ame
{
    NewKanjidict::NewKanjidict() : Dictionary()
    {
    }

    ame_result NewKanjidict::loadDictionaryFromFile(std::string file)
    {
        ame_result output(true, statusCode::OK);

        pugi::xml_parse_result result = XMLDoc.load_file(file.c_str());

        if (result.status != pugi::status_ok)
            ame_result(false, statusCode::ERR);

        return output;
    }

    ame_result NewKanjidict::loadDictionaryFromString(std::string content)
    {

        ame_result output(true, statusCode::OK);

        pugi::xml_parse_result result = XMLDoc.load_string(content.c_str());

        if (result.status != pugi::status_ok)
            output = ame_result(false, statusCode::ERR);

        return output;
    }

}