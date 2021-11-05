#include <gtest/gtest.h>
#include <string>
#include "../src/Ame/Cards/Template/TemplateRenderer.h"

TEST(TemplateRenderer, RenderParser)
{
    Ame::MapTable mapTable;
    mapTable.Add("pascual", "victor");
    mapTable.Add("MyPasswordIs", "Sharks123");
    mapTable.Add("OneLastTest", "MaybeTwoMore");
    mapTable.Add("ONE", "pas");
    mapTable.Add("TWO", "cual");

    std::string t1 = Ame::TemplateRenderer::Render("Mi nombre es $(pascual) y soy hermoso!", mapTable);
    std::string t2 = Ame::TemplateRenderer::Render("My password is $(MyPasswordIs)", mapTable);
    std::string t3 = Ame::TemplateRenderer::Render("$(OneLastTest), i swear!", mapTable);
    std::string t4 = Ame::TemplateRenderer::Render("My name is $($(ONE)$(TWO))!", mapTable);
    std::string t5 = Ame::TemplateRenderer::Render("$(pascual)", mapTable);


    EXPECT_STREQ(t1.c_str(), "Mi nombre es victor y soy hermoso!");
    EXPECT_STREQ(t2.c_str(), "My password is Sharks123");
    EXPECT_STREQ(t3.c_str(), "MaybeTwoMore, i swear!");
    EXPECT_STREQ(t4.c_str(), "My name is victor!");
    EXPECT_STREQ(t5.c_str(), "victor");
} 

TEST(TemplateRenderer, MultipleTables)
{
    Ame::MapTable T1;
    Ame::MapTable T2;

    T1.Add("pascual", "victor");
    T1.Add("one", "two");
    T2.Add("orange", "apple");
    T2.Add("two","three");

    std::vector<Ame::MapTable> Tables;
    Tables.push_back(T1);
    Tables.push_back(T2);

    std::string o1 = Ame::TemplateRenderer::Render("My name is $(pascual) and i like $(orange)", Tables);
    std::string o2 = Ame::TemplateRenderer::Render("I have $($(one)) more car", Tables);

    EXPECT_STREQ(o1.c_str(), "My name is victor and i like apple");
    EXPECT_STREQ(o2.c_str(), "I have three more car");

}
TEST(TemplateRenderer, NonstaticMethods)
{
    Ame::MapTable mapTable;
    mapTable.Add("pascual", "victor");
    mapTable.Add("MyPasswordIs", "Sharks123");
    mapTable.Add("OneLastTest", "MaybeTwoMore");
    mapTable.Add("ONE", "pas");
    mapTable.Add("TWO", "cual");

    Ame::TemplateRenderer renderer;

    renderer.Add("firstTable", mapTable);
    std::string t1 = renderer.Render("Mi nombre es $(pascual) y soy hermoso!", "firstTable");
    std::string t2 = renderer.Render("My password is $(MyPasswordIs)", "firstTable");
    std::string t3 = renderer.Render("$(OneLastTest), i swear!", "firstTable");
    std::string t4 = renderer.Render("My name is $($(ONE)$(TWO))!", "firstTable");
    std::string t5 = renderer.Render("$(pascual)", "firstTable");


    EXPECT_STREQ(t1.c_str(), "Mi nombre es victor y soy hermoso!");
    EXPECT_STREQ(t2.c_str(), "My password is Sharks123");
    EXPECT_STREQ(t3.c_str(), "MaybeTwoMore, i swear!");
    EXPECT_STREQ(t4.c_str(), "My name is victor!");
    EXPECT_STREQ(t5.c_str(), "victor");

    Ame::MapTable newTable;
    newTable.Add("victor", "Dinosaurio!");
    renderer.Add("secondTable", newTable);

    std::string t6 = renderer.Render("mi nombre es $(victor)", "secondTable");
    EXPECT_STREQ(t6.c_str(), "mi nombre es Dinosaurio!");

    std::string t7 = renderer.RenderAll("mi nombre es $($(pascual))");
    EXPECT_STREQ(t7.c_str(), "mi nombre es Dinosaurio!");

    std::string t8 = renderer.Render("Su nombre es $($(pascual))", std::vector<std::string>{"firstTable", "secondTable"});
    EXPECT_STREQ(t8.c_str(), "Su nombre es Dinosaurio!");

    std::string t9 = renderer.Render("Tres mas Dos son $($(pascual))", std::vector<Ame::MapTable>{mapTable, newTable});
    EXPECT_STREQ(t9.c_str(), "Tres mas Dos son Dinosaurio!");

    Ame::MapTable newnewTable;
    newnewTable.Add("Sharks123", "Sharks321");

    std::string t10 = renderer.RenderAll("My password is no longer $($(MyPasswordIs))", newnewTable);
    EXPECT_STREQ(t10.c_str(), "My password is no longer Sharks321");

    Ame::MapTable fourthTable;
    fourthTable.Add("Dinosaurio!", "pop");

    std::string t11 = renderer.RenderAll("My password is $($(MyPasswordIs)) and I am $($($(pascual)))",
                                            std::vector<Ame::MapTable>{newnewTable, fourthTable});
    EXPECT_STREQ(t11.c_str(), "My password is Sharks321 and I am pop");
}