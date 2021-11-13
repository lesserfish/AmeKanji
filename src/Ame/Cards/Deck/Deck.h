#pragma once

#include "../Template/Template.h"
#include "../../StatusCodes.h"
#include "../../AmeConfig.h"
#include <string>
#include <vector>

namespace Ame
{
    struct RenderedCard
    {
        RenderedCard(std::vector<std::string> FL) : FieldList(FL){}
        std::vector<std::string> FieldList;
    };
    class Deck
    {
        public:
            Deck() : renderStatus(false){}

            ame_result Render(AmeConfig configuration = AmeConfig());
            ame_result SaveToFile(std::string File, bool autoRender = true);
            std::string AsString();

            std::vector<RenderedCard> Cards;
        private:
            bool renderStatus;
            std::string deckContent;
    };
}