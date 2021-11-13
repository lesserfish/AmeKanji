#include "Ame/Cards/Deck/Deck.h"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{

    Ame::RenderedCard rca({"Field One", "Field Two"});
    Ame::RenderedCard rcn({"Fie One", "Fldo"});
    Ame::RenderedCard rcc({"Fid One", "eld Two"});

    Ame::Deck deck;
    deck.Cards.push_back(rca);
    deck.Cards.push_back(rcn);
    deck.Cards.push_back(rcc);

    deck.Render();
    std::string result = deck.AsString();
    std::cout << "output: " << result << std::endl;
}