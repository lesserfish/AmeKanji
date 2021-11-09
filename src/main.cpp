#include <pugixml.hpp>
#include <iostream>
#include "Ame/Cards/Default.h"
#include "Ame/Jisho/Parsers/Default.h"

int main(int argc, char **argv)
{
    pugi::xml_document XMLDoc;
    XMLDoc.load_file("/home/vchavauty/Documents/Code/AmeKanji/file2.xml");

    pugi::xml_node root = XMLDoc.first_child();
    Ame::DefaultCard::Node node = Ame::DefaultParser::GetNode(root);
    std::cout << node.Name << std::endl;
    std::cout << Ame::DefaultCard::PrintNode(node, "\t");
}