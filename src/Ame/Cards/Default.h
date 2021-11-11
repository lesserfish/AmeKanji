#pragma once

#include "Card.h"
#include <string>
#include <vector>

namespace Ame
{
    class DefaultCard : public AbstractCard
    {
    public:
        std::string RenderTemplate(std::string Template);
        std::string RenderTemplate(std::string Template, MapTable additionalTable);
        std::string RenderTemplate(std::string Template, std::vector<MapTable> additionalTables);
        std::string Print() const;

    public:
        struct Node
        {
            std::string Name;
            std::string Value;
            std::string Text;
            std::vector<std::string> Attributes;
            std::vector<Node> ChildNodes;
        };
        Node root_node;
        static std::string PrintNode(Node node, std::string strStart = "");
    };
}