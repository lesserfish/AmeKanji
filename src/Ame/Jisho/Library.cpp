#include "Library.h"

namespace Ame
{
    AmeLibrary::AmeLibrary(AmeConfig& config) : configInstance(config){}
    void AmeLibrary::loadConfiguration(AmeConfig &config)
    {
        configInstance = config;
    }
}