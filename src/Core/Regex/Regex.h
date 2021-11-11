#pragma once

#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <pugixml.hpp>

namespace Core
{
    enum regOP
    {
        NONE,
        MATCH,
        SEARCH,
        REPLACE
    };
    struct RegexInstruction
    {
        RegexInstruction(regOP _op, std::string _regexInstruction, std::string _Argument) : op(_op), regexInstruction(_regexInstruction), Argument(_Argument){};
        RegexInstruction() : op(), regexInstruction(), Argument(){};
        regOP op;
        std::string regexInstruction;
        std::string Argument;
    };
    struct RegexOrder
    {
        RegexOrder(std::vector<RegexInstruction> _regexOrder) : regexOrder(_regexOrder){};
        RegexOrder(RegexInstruction _regexInstruction) : regexOrder() { regexOrder.push_back(_regexInstruction); };
        RegexOrder() : regexOrder(){};
        std::vector<RegexInstruction> regexOrder;
    };

    static const inline std::vector<std::string> ParseRegex(RegexOrder order, std::string Target)
    {
        //    std::cout << "Parsing Regex!\n\nOrder: " << "\n\nTarget: " << Target << std::endl;
        std::vector<std::string> output;
        output.push_back(Target);

        for (const RegexInstruction &instruction : order.regexOrder)
        {
            std::vector<std::string> updatedOutput;

            for (const std::string &currentTarget : output)
            {
                std::string T;
                std::smatch match;
                std::regex currentRegex;

                std::string result;

                switch (instruction.op)
                {
                case regOP::MATCH:
                    T = currentTarget;
                    currentRegex = std::regex(instruction.regexInstruction);

                    while (std::regex_search(T, match, currentRegex))
                    {
                        if (match.size() > 0)
                            updatedOutput.push_back(match[0]);
                        /*for(auto result: match)
                            {
                                updatedOutput.push_back(result);
                            }*/
                        T = match.suffix().str();
                    }
                    break;
                case regOP::REPLACE:
                    //                        std::cout << "We have to replace shit!\n";
                    T = currentTarget;
                    currentRegex = std::regex(instruction.regexInstruction);
                    result = std::regex_replace(T, currentRegex, instruction.Argument);
                    updatedOutput.push_back(result);

                    break;
                case regOP::SEARCH:
                    break;
                default:
                    break;
                }
            }

            output = updatedOutput;
        }

        return output;
    }
}
