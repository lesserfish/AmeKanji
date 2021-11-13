#pragma once

#include <string>
#include <vector>
#include "Template/TemplateRenderer.h"
#include "../../Core/Regex/Regex.h"
#include "../AmeConfig.h"

namespace Ame
{
    class AbstractCard
    {
    public:
        AbstractCard() {}
        virtual std::string RenderTemplate(std::string Template) = 0;
        virtual std::string RenderTemplate(std::string Template, MapTable additionalTable) = 0;
        virtual std::string RenderTemplate(std::string Template, std::vector<MapTable> additionalTables) = 0;
        virtual std::string Print() const = 0;
        inline static std::string FormatText(std::string input)
        {
            std::string output = input;

            Core::RegexInstruction regexA = Core::RegexInstruction(Core::regOP::REPLACE, "\"", "\"\"");
            Core::RegexInstruction regexB = Core::RegexInstruction(Core::regOP::REPLACE, "\n", "<br>");
            Core::RegexInstruction regexC = Core::RegexInstruction(Core::regOP::REPLACE, "&", "&amp;");
            Core::RegexInstruction regexD = Core::RegexInstruction(Core::regOP::REPLACE, "<", "&lt;");
            Core::RegexInstruction regexE = Core::RegexInstruction(Core::regOP::REPLACE, ">", "&gt;");

            std::vector<Core::RegexInstruction> regex = {regexA, regexB, regexC, regexD, regexE};

            Core::RegexOrder order(regex);

            std::vector<std::string> regexResult = Core::ParseRegex(order, input);

            output = regexResult.size() > 0 ? regexResult[0] : "";

            return output;
        }
    };
}