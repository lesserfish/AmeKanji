#pragma once

#include "../Dictionary.h"
#include "../../Cards/Default.h"
#include "../../StatusCodes.h"
#include <pugixml.hpp>
#include <vector>
#include <string>

namespace Ame
{
    class DefaultParser : public Dictionary
    {
    public:
        static ame_result GetInformation(DefaultCard &output, std::vector<std::string> input, pugi::xml_document *XMLDoc, std::vector<std::string> Args);

        //private:
        static DefaultCard::Node GetNode(pugi::xml_node &node);
    };
}