#pragma once

#include <string>

namespace Ame
{
    class AbstractCard
    {
        public:
            AbstractCard(){}
            virtual std::string RenderTemplate(std::string Template) = 0;
            virtual ~AbstractCard() = 0;
    };
}