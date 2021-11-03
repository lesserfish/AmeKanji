#include "Ame.h"
#include <iostream>
#include "Jisho/Library.h"

namespace Ame
{
    Ame::Ame() : configInstance()
    {
        std::cout << "Ame Initialized!\n";
    }
    Ame::Ame(int argc, char **argv) : configInstance()
    {
        std::cout << "Ame Initialized!\n";
        loadArgs(argc, argv);   
    }
    void Ame::printConfiguration()
    {
    }

    ame_result Ame::Run()
    {
        // Before running Run(), one needs to run Initialize(). This function will generate the remaining parameters of AmeConfig, which, in turn, will
        // be used by the remaining functions. For example: This will load the Library class.
        // Afterwards, a template Class will be created. This is just a vector of strings, corresponding to each of the deck faces.
        // For every word (or kanji), one will get all of the information required using the Library class.
        // Then, one will create a copy of the template, replacing every variable of the form @variable with the corresponding value from the class.
        // Perhaps this should be done on the Library class?? Or perhaps the class Kanji and Word should be subclasses of a greater class, which has a virtual function
        // that transforms its content into 
        return ame_result();
    }
}