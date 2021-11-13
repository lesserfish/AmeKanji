#include "Deck.h"
#include "../../../Core/Regex/Regex.h"
#include <fstream>

namespace Ame
{
    ame_result Deck::Render(AmeConfig configuration)
    {
        std::string output = "";
        for(auto& c : Cards){
            std::string entry = "";
            for(auto& field : c.FieldList)
            {
                entry = entry + "\"" + field + "\";";
            }
            output += entry + "\n";
        }

        if(configuration.Tag != "")
            deckContent += configuration.Tag + ";";

        deckContent = output;
        renderStatus = true;
        return ame_result();
    }
    ame_result Deck::SaveToFile(std::string File, bool autoRender)
    {
        if(!renderStatus)
        {
            if(!autoRender)
                return ame_result(false, statusCode::ERR, "Deck has not yet been rendered!");
            Render();
        }
        
        std::ofstream file(File);
        file << deckContent;

        return ame_result();
    }
    std::string Deck::AsString()
    {
        return deckContent;
    }
}