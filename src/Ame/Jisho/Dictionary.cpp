#include "Dictionary.h"
#include <fstream>
#include <iostream>
namespace Ame
{
    Dictionary::Dictionary(){}
    
    int Dictionary::loadXMLFromFile(std::string file)
    {
        int output = 0;

        pugi::xml_parse_result result = XMLDoc.load_file(file.c_str());

        if(result.status != pugi::status_ok)
            output = 1;
        return output;
    }

    int Dictionary::loadXMLFromString(std::string content)
    {

        int output = 0;

        pugi::xml_parse_result result = XMLDoc.load_string(content.c_str());

        if(result.status != pugi::status_ok)
            output = 1;
        return output;
    }

    int Dictionary::loadUTF8FromFile(std::string file)
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

        std::cout << content << std::endl;
        UTF8Doc = content;

        return output;
    }

    int Dictionary::loadUTF8FromString(std::string content)
    {
        UTF8Doc = content;

        return 0;
    }
}