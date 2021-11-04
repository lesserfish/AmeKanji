#include "Core/ArgsParser.h"
#include "Ame/Ame.h"
#include "Core/Regex/Regex.h"
#include "Ame/Cards/Word.h"
#include "Ame/Jisho/Parsers/JMdict.h"
#include "Ame/Jisho/Library.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "Ame/Cards/Template/TemplateRenderer.h"


int main(int argc, char **argv)
{
    Ame::MapTable mapTable;
    mapTable.Add("victor", "pascual");
    std::string o = Ame::TemplateRenderer::Render("$(victor)", mapTable);
    std::cout << o << std::endl;
    mapTable.Add("pascual", "victor");
    mapTable.Add("feo", "hermoso");
    o = Ame::TemplateRenderer::Render("abc$(pascual)def!", mapTable);
    std::cout << o << std::endl;
    mapTable.Add("PrimeraVariable", "pasc");
    mapTable.Add("SegundaVariable", "ual");
    o = Ame::TemplateRenderer::Render("El $($(PrimeraVariable)$(SegundaVariable)) es lindo!", mapTable);
    std::cout << o << std::endl;
}
