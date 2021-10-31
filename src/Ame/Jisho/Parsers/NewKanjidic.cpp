#include "NewKanjidic.h"

namespace Ame
{
    NewKanjidict::NewKanjidict() : Dictionary()
    {
    }
    
    int NewKanjidict::loadDictionaryFromFile(std::string file)
    {
        int output = 0;

        pugi::xml_parse_result result = XMLDoc.load_file(file.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        return output;
    }

    int NewKanjidict::loadDictionaryFromString(std::string content)
    {

        int output = 0;

        pugi::xml_parse_result result = XMLDoc.load_string(content.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        return output;
    }

}