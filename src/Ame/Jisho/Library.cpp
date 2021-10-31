#include "Library.h"

namespace Ame
{
    AmeLibrary::AmeLibrary() : configInstance() {}
    AmeLibrary::AmeLibrary(AmeConfig config)
    {
        loadConfiguration(config);
    }
    void AmeLibrary::loadConfiguration(AmeConfig config)
    {
        configInstance = config;
    }
}