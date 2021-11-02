#include "Kanjidic.h"
#include <fstream>

namespace Ame
{
    Kanjidict::Kanjidict() : Dictionary()
    {
    }

    ame_result Kanjidict::loadDictionaryFromFile(std::string file)
    {
        ame_result output(true, statusCode::OK);

        std::ifstream inputfile;
        inputfile.open(file, std::ios::in);

        if(!inputfile.is_open())
            return ame_result(false, statusCode::ERR);
        
        std::string content;
        
        std::string Line;
        while(inputfile)
        {
            std::getline(inputfile, Line);
            content = content + Line + "\n";    
        }

        UTF8Doc = content;
        return output;
    }

    ame_result Kanjidict::loadDictionaryFromString(std::string content)
    {
        UTF8Doc = content;

        return ame_result(true, statusCode::OK);
    }

}