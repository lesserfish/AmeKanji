#include "Word.h"
#include <iostream>

namespace Ame
{
    std::string Word::RenderTemplate(std::string Template)
    {
        std::string output = "";
        return output;
    }
    void Word::Print()
    {
        std::cout << "Entry sequence: " << ent_seq.value << std::endl;
        std::cout << "K_Elemenets: " << std::endl;
        for(Ame::Word::K_ELE& kele : K_ELE_List)
        {
            std::cout << "\tKEB Elements: " << std::endl;
            for(Ame::Word::K_ELE::KEB &keb : kele.KEB_List)
            {
                std::cout << "\t\tValue: " << keb.value << std::endl;
            }
            std::cout << "\tK_INF Elements: " << std::endl;
            for(Ame::Word::K_ELE::KE_INF& kinf : kele.KE_INF_List)
            {
                std::cout << "\t\tValue: " << kinf.value << std::endl;
            }
            std::cout << "\tK_PRI Elements: " << std::endl;
            for(Ame::Word::K_ELE::KE_PRI& kpri : kele.KE_PRI_List)
            {
                std::cout << "\t\tValue: " << kpri.value << std::endl;
            }
            std::cout << std::endl;
        }
        std::cout << "R_Elements: " << std::endl;
        for(Ame::Word::R_ELE& rele : R_ELE_List)
        {
            std::cout << "\tREB Elements: " << std::endl;
            for(Ame::Word::R_ELE::REB &reb : rele.REB_List)
            {
                std::cout << "\t\tValue: " << reb.value << std::endl;
            }
            std::cout << "\tR_INF Elements: " << std::endl;
            for(Ame::Word::R_ELE::RE_INF& rinf : rele.RE_INF_List)
            {
                std::cout << "\t\tValue: " << rinf.value << std::endl;
            }
            std::cout << "\tR_PRI Elements: " << std::endl;
            for(Ame::Word::R_ELE::RE_PRI& rpri : rele.RE_PRI_List)
            {
                std::cout << "\t\tValue: " << rpri.value << std::endl;
            }
            std::cout << std::endl;
        }
        std::cout << "SENSE Elements: " << std::endl;
        for(Ame::Word::SENSE& sense : SENSE_List)
        {
            std::cout << "\tPOS Elements: " << std::endl;
            for(Ame::Word::SENSE::POS& pos : sense.POS_List)
            {
                std::cout << "\t\tValue: " << pos.value << std::endl;
            }
            std::cout << "\tGLOSS Elements: " << std::endl;
            for(Ame::Word::SENSE::GLOSS& gloss : sense.GLOSS_List)
            {
                std::cout << "\t\tValue: " << gloss.value << std::endl;
            }
            std::cout << std::endl;
        }
    }
}