#pragma once

#include "../../../Core/Regex/Regex.h"
#include <pugixml.hpp>
#include <string>

namespace Ame{


    Core::RegexInstruction GetRegexInstructionFromNode(pugi::xml_node &node)
    {
        Core::RegexInstruction rInstruction;

        pugi::xml_node OP = node.child("OP");
        std::string OP_str = OP.text().as_string();

        Core::regOP rOP;

        if(OP_str.compare("M") == 0)
            rOP = Core::regOP::MATCH;
        else if(OP_str.compare("S") == 0)
            rOP = Core::regOP::SEARCH;
        else if(OP_str.compare("R") == 0)
            rOP = Core::regOP::REPLACE;
        else
            rOP = Core::regOP::NONE; 

        rInstruction.op = rOP;

        rInstruction.regexInstruction = node.child("Instruction").text().as_string();
        rInstruction.Argument = node.child("Argument").text().as_string();

        return rInstruction;
    }

    void PrintOrder(Core::RegexOrder);
    Core::RegexOrder getRegexOrderFromNode(pugi::xml_node &node, std::string NodeName = "RegInstruction")
    {
        Core::RegexOrder rOrder;
        for(pugi::xml_node order_it = node.child(NodeName.c_str()); order_it; order_it = order_it.next_sibling(NodeName.c_str()))
        {
            Core::RegexInstruction thisInstruction = GetRegexInstructionFromNode(order_it);
            rOrder.regexOrder.push_back(thisInstruction);
        }
        return rOrder;
    }

    void PrintOrder(Core::RegexOrder ro)
    {
        for(Core::RegexInstruction& ri : ro.regexOrder)
        {
            std::string op = ri.op == Core::regOP::MATCH ? "Match" :
                                        ri.op == Core::regOP::REPLACE ? "Replace" : 
                                        ri.op == Core::regOP::SEARCH ? "Search" : "None";

            std::cout << "OP: " << op << "\nInstruction: " << ri.regexInstruction << "\nArgument: " << ri.Argument << "\n";
        }
    }

}