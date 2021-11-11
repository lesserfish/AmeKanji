#include "Default.h"

namespace Ame
{
    std::string DefaultCard::RenderTemplate(std::string Template)
    {
        std::string output = "";
        return output;
    }
    std::string DefaultCard::RenderTemplate(std::string Template, MapTable additionalTable) { return ""; }
    std::string DefaultCard::RenderTemplate(std::string Template, std::vector<MapTable> additionalTables) { return ""; }
    std::string DefaultCard::Print() const
    {
        return PrintNode(root_node);
    }
    std::string DefaultCard::PrintNode(DefaultCard::Node node, std::string strStart)
    {

        std::string output = "";
        output += strStart + "Name: " + node.Name + "\n";
        if (node.Value != "")
            output += strStart + "Value: " + node.Value + "\n";
        if (node.Text != "")
            output += strStart + "Text: " + node.Text + "\n";
        if (node.Attributes.size() > 0)
        {
            output += strStart + "Attributes Begin:\n";
            for (auto &it : node.Attributes)
            {
                output += strStart + "\t" + it;
            }
            output += strStart + "Attributes End.\n";
        }

        if (node.ChildNodes.size() > 0)
        {
            output += strStart + "Child nodes begin:\n";
            for (auto &it : node.ChildNodes)
            {
                output += PrintNode(it, strStart + "\t");
            }
            output += strStart + "Child nodes end.\n";
        }
        return output;
    }
}