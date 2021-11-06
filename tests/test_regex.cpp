#include <gtest/gtest.h>
#include <string>
#include "../src/Core/Regex/Regex.h"

TEST(CoreLibrary, ParseRegexReplace)
{
    Core::RegexInstruction i1(Core::regOP::REPLACE, "12.*21", "yolo");
    Core::RegexOrder o1(i1);
    std::vector<std::string> out = Core::ParseRegex(o1, "asd12rrerere21asd");

    EXPECT_EQ(out.size(), 1);
    EXPECT_STREQ(out[0].c_str(), "asdyoloasd");
} 

TEST(CoreLibrary, ParseRegexMatch)
{
    //TODO
    Core::RegexInstruction i1(Core::regOP::MATCH, "sub(\\w*)a", "");
    Core::RegexOrder o1(i1);
    std::vector<std::string> out = Core::ParseRegex(o1, "submarine subcars submama subhuman metropolos subcat konosuba");

    EXPECT_EQ(out.size(), 6);
    EXPECT_STREQ(out[0].c_str(), "subma");
    EXPECT_STREQ(out[1].c_str(), "subca");
    EXPECT_STREQ(out[2].c_str(), "submama");
    EXPECT_STREQ(out[3].c_str(), "subhuma");
    EXPECT_STREQ(out[4].c_str(), "subca");
    EXPECT_STREQ(out[5].c_str(), "suba");
} 
