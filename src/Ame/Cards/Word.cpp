#include "Word.h"
#include <iostream>

namespace Ame
{
    std::string Word::RenderTemplate(std::string Template)
    {
        std::string output = "";
        return output;
    }
    std::string Word::Print() const
    {
        std::string output;
        output = output +  "Entry sequence: " + ent_seq.value + "\n";
        output = output +  "K_Elemenets: " + "\n";
        for(Ame::Word::K_ELE kele : K_ELE_List)
        {
            output = output +  "\tKEB Elements: " + "\n";
            for(Ame::Word::K_ELE::KEB keb : kele.KEB_List)
            {
                output = output +  "\t\tValue: " + keb.value + "\n";
            }
            output = output +  "\tK_INF Elements: " + "\n";
            for(Ame::Word::K_ELE::KE_INF kinf : kele.KE_INF_List)
            {
                output = output +  "\t\tValue: " + kinf.value + "\n";
            }
            output = output +  "\tK_PRI Elements: " + "\n";
            for(Ame::Word::K_ELE::KE_PRI kpri : kele.KE_PRI_List)
            {
                output = output +  "\t\tValue: " + kpri.value + "\n";
            }
            output = output +  "\n";
        }
        output = output +  "R_Elements: " + "\n";
        for(Ame::Word::R_ELE rele : R_ELE_List)
        {
            output = output +  "\tREB Elements: " + "\n";
            for(Ame::Word::R_ELE::REB reb : rele.REB_List)
            {
                output = output +  "\t\tValue: " + reb.value + "\n";
            }
            output = output +  "\tR_INF Elements: " + "\n";
            for(Ame::Word::R_ELE::RE_INF rinf : rele.RE_INF_List)
            {
                output = output +  "\t\tValue: " + rinf.value + "\n";
            }
            output = output +  "\tR_PRI Elements: " + "\n";
            for(Ame::Word::R_ELE::RE_PRI rpri : rele.RE_PRI_List)
            {
                output = output +  "\t\tValue: " + rpri.value + "\n";
            }
            output = output +  "\n";
        }
        output = output +  "SENSE Elements: " + "\n";
        for(Ame::Word::SENSE sense : SENSE_List)
        {
            output = output +  "\tPOS Elements: " + "\n";
            for(Ame::Word::SENSE::POS pos : sense.POS_List)
            {
                output = output +  "\t\tValue: " + pos.value + "\n";
            }
            output = output +  "\tGLOSS Elements: " + "\n";
            for(Ame::Word::SENSE::GLOSS gloss : sense.GLOSS_List)
            {
                output = output +  "\t\tValue: " + gloss.value + "\n";
            }
            output = output +  "\n";
        }

        return output;
    }
    std::ostream& operator<<(std::ostream& os, const Word& w)
    {
        std::string content = w.Print();
        os << content;
        return os;
    }
}