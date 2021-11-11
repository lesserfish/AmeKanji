#include "Default.h"

namespace Ame
{

    ame_result DefaultParser::GetInformation(DefaultCard &output, std::vector<std::string> input, pugi::xml_document *XMLDoc, std::vector<std::string> Args)
    {
        return ame_result();
    }
    DefaultCard::Node DefaultParser::GetNode(pugi::xml_node &node)
    {
        DefaultCard::Node output;
        output.Name = node.name();
        output.Value = node.value();
        output.Text = node.text().as_string();
        for (auto it = node.attributes_begin(); it != node.attributes_end(); it++)
        {
            output.Attributes.push_back(it->as_string());
        }
        for (pugi::xml_node it = node.first_child(); it; it = it.next_sibling())
        {
            DefaultCard::Node childNode = GetNode(it);
            output.ChildNodes.push_back(childNode);
        }

        return output;
    }
}