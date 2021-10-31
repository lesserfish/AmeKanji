#pragma once

#include "../AmeConfig.h"

// How should we store all of the different Parsers? On a huge big list? On a dictionary with enumeration?
// Should we store them by return type?

namespace Ame
{
    // Holds all of the distinct Dictionaries. Intermediary between Ame and each one of them
    // Reads from the configuration in order to determine which dictionary parser to use, which dictionary file to send, and which regex file to send.
    class AmeLibrary
    {
        public:
            AmeLibrary(const AmeConfig &config);
            void debug(); 
        private:
            const AmeConfig &configInstance;
    };
}