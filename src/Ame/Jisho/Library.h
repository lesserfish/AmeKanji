#pragma once

#include "../AmeConfig.h"


namespace Ame
{
    // Holds all of the distinct Dictionaries. Intermediary between Ame and each one of them
    // Reads from the configuration in order to determine which dictionary parser to use, which dictionary file to send, and which regex file to send.
    class AmeLibrary
    {
        public:
            AmeLibrary();
            AmeLibrary(AmeConfig &config);
            void loadConfiguration(AmeConfig &config);
            
        private:
            AmeConfig &configInstance;
    };
}