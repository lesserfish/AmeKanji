#include "Library.h"

namespace Ame
{
    AmeLibrary::AmeLibrary(const AmeConfig& config) : configInstance(config), mode(CardMode::None), parser(ParserMode::None){}
    void AmeLibrary::debug()
    {
        std::cout << "Debug: ";
        std::cout << configInstance.inputFile << std::endl;
    }
}