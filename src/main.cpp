#include "Ame/Jisho/EventChain.h"
#include "Ame/Jisho/Parsers/JMdict.h"
#include "Ame/StatusCodes.h"
#include "Ame/Cards/Word.h"
#include <iostream>
#include <string>
#include <pugixml.hpp>
#include "Ame/Jisho/Librarian.h"
#include "Core/Regex/Regex.h"
int main(int argc, char **argv)
{
    Core::RegexInstruction i1(Core::regOP::MATCH, "sub(\\w*)a", "");
    Core::RegexOrder o1(i1);
    std::vector<std::string> out = Core::ParseRegex(o1, "submarine subcars submama subhuman metropolos subcat konosuba");

    for(auto a : out)
    {
        std::cout << a << std::endl;
    }

}