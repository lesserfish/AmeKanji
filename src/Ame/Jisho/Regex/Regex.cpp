#include "Regex.h"
#include <regex>

namespace Ame
{
    std::vector<std::string> ParseRegex(RegexOrder order, std::string Target)
    {
        std::vector<std::string> output;
        output.push_back(Target);

        for(const RegexInstruction& instruction : order.regexOrder)
        {
            std::vector<std::string> updatedOutput;

            for(const std::string& currentTarget : output)
            {
                std::string T;
                std::smatch match;
                std::regex currentRegex;

                std::string result;

                switch(instruction.op)
                {
                    case regOP::MATCH:
                        T = currentTarget;
                        currentRegex = std::regex(instruction.regexInstruction);

                        while(std::regex_search(T, match, currentRegex))
                        {
                            for(auto result: match)
                            {
                                updatedOutput.push_back(result);
                            }
                            T = match.suffix().str();
                        }
                        break;
                    case regOP::REPLACE:
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