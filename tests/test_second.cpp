#include <gtest/gtest.h>
#include <string>
#include "../src/Ame/Cards/Template/TemplateRenderer.h"

TEST(TemplateRendererTest, RenderTestB)
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

;


    EXPECT_STREQ(t1.c_str(), "Mi nombre es victor y soy hermoso!");
    EXPECT_STREQ(t2.c_str(), "My password is Sharks123");
    EXPECT_STREQ(t3.c_str(), "MaybeTwoMore, i swear!");
    EXPECT_STREQ(t4.c_str(), "My name is victor!");
    EXPECT_STREQ(t5.c_str(), "victor");
} 