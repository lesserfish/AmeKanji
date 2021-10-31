#include "Kanjidic.h"
#include <fstream>

namespace Ame
{
    Kanjidict::Kanjidict() : Dictionary()
    {
    }

    int Kanjidict::loadDictionaryFromFile(std::string file)
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

        UTF8Doc = content;
        return output;
    }

    int Kanjidict::loadDictionaryFromString(std::string content)
    {
        UTF8Doc = content;

        return 0;
    }

}