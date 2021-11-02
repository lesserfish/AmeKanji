#include "Edict.h"
#include <fstream>

namespace Ame
{
    Edict::Edict() : Dictionary()
    {
    }

    ame_result Edict::loadDictionaryFromFile(std::string file)
    {
        ame_result output(true, statusCode::OK);

        std::ifstream inputfile;
        inputfile.open(file, std::ios::in);

        if(!inputfile.is_open())
            ame_result(false, statusCode::ERR);
        
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

    ame_result Edict::loadDictionaryFromString(std::string content)
    {
        UTF8Doc = content;
        return ame_result(true, statusCode::OK);
    }

}