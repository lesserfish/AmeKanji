#pragma once

 #include "../AmeConfig.h"


namespace Ame
{

    // Holds all of the distinct Dictionaries. Intermediary between Ame and each one of them
    class AmeLibrary
    {
        public:
            AmeLibrary();
            AmeLibrary(AmeConfig config);
            void loadConfiguration(AmeConfig config);
            
        private:
            AmeConfig configInstance;
    };
}