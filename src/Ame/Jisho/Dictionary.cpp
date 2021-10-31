#include "Dictionary.h"
#include <fstream>
#include <iostream>
namespace Ame
{
    Dictionary::Dictionary() : Mode(mode::None), RegexMode(regexMode::None) {}
    
    int Dictionary::loadXMLFromFile(std::string file)
    {
        int output = 0;

        pugi::xml_parse_result result = XMLDoc.load_file(file.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        Mode = mode::XML;
        return output;
    }

    int Dictionary::loadXMLFromString(std::string content)
    {

        int output = 0;

        pugi::xml_parse_result result = XMLDoc.load_string(content.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        Mode = mode::XML;
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
        Mode = mode::UTF8;
        return output;
    }

    int Dictionary::loadUTF8FromString(std::string content)
    {
        UTF8Doc = content;
        Mode = mode::UTF8;

        return 0;
    }

    
    int Dictionary::loadXMLRegexFromFile(std::string file)
    {
        int output = 0;

        pugi::xml_parse_result result = xml_regexInstruction.load_file(file.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        RegexMode = regexMode::XML;
        return output;
    }

    int Dictionary::loadXMLRegexFromString(std::string content)
    {

        int output = 0;

        pugi::xml_parse_result result = xml_regexInstruction.load_string(content.c_str());

        if(result.status != pugi::status_ok)
            output = 1;

        RegexMode = regexMode::XML;
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
        txt_regexInstruction = content;
        RegexMode = regexMode::UTF8;
        return output;
    }

    int Dictionary::loadTXTRegexFromString(std::string content)
    {
        txt_regexInstruction = content;
        RegexMode = regexMode::UTF8;

        return 0;
    }

    void Dictionary::setMode(mode _Mode)
    {
        Mode = _Mode;
    }

    void Dictionary::setRegexMode(regexMode _Mode)
    {
        RegexMode = _Mode;
    }
}