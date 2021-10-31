#pragma once

#include <string>
#include <vector>

namespace Ame
{
    enum regOP{MATCH, SEARCH, REPLACE};
    struct RegexInstruction
    {
        RegexInstruction(regOP _op, std::string _regexInstruction, std::string _Argument) : op(_op), regexInstruction(_regexInstruction), Argument(_Argument){};
        RegexInstruction() : op(), regexInstruction(), Argument() {};
        regOP op;
        std::string regexInstruction;
        std::string Argument;
    };
    struct RegexOrder
    {
        RegexOrder(std::vector<RegexInstruction> _regexOrder) : regexOrder(_regexOrder) {};
        RegexOrder(RegexInstruction _regexInstruction) : regexOrder() {regexOrder.push_back(_regexInstruction);};
        RegexOrder() : regexOrder() {};
        std::vector<RegexInstruction> regexOrder;
    };

    std::vector<std::string> ParseRegex(RegexOrder order, std::string Target);
}