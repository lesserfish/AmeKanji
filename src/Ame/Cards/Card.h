#pragma once

#include <string>
#include <vector>
#include "Template/TemplateRenderer.h"

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
    };
}