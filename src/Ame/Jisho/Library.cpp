#include "Library.h"

namespace Ame
{
    AmeLibrary::AmeLibrary(const AmeConfig& config) : configInstance(config){}
    void AmeLibrary::debug()
    {
        std::cout << "Debug: ";
        std::cout << configInstance.inputFile << std::endl;
    }
}