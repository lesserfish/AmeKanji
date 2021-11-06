#include <gtest/gtest.h>
#include <pugixml.hpp>
#include <string>
#include <vector>
#include "../src/Ame/Jisho/Librarian.h"
#include "../src/Ame/Jisho/EventChain.h"
#include "../src/Ame/Jisho/Parsers/JMdict.h"
#include "../src/Ame/StatusCodes.h"
#include "../src/Ame/Cards/Word.h"

Ame::ame_result TestA(int &w, std::vector<std::string> Input)
{
    w = 24;
    return Ame::ame_result(true, Ame::statusCode::parser_ERR_MISSING_VALUE, "Hello");
}
Ame::ame_result TestB(int &w, std::vector<std::string> Input, float b, char d)
{
    w = -12;
    EXPECT_EQ(b, 12);
    EXPECT_EQ(d, 'd');
    return Ame::ame_result(true, Ame::statusCode::OK, "Hola");
}

TEST(EventChain, ChainLinkCall)
{
    auto t1 = Ame::ChainLink<int>::Setup(&TestA);
    auto t2 = Ame::ChainLink<int>::Setup(&TestB, 12, 'd');

    int w = 5;
    int k = 3;

    Ame::ame_result t3 = t1->Call(w, {});
    Ame::ame_result t4 = t2->Call(k, {});

    EXPECT_EQ(w, 24);
    EXPECT_EQ(k, -12);

    EXPECT_STREQ(t3.Message.c_str(), "Hello");
    EXPECT_STREQ(t4.Message.c_str(), "Hola");
} 

TEST(EventChain, EventChainCall)
{
    auto t1 = Ame::ChainLink<int>::Setup(&TestA);
    auto t2 = Ame::ChainLink<int>::Setup(&TestB, 12, 'd');

    int w = 5;

    Ame::EventChain<int> ec;

    ec.RegisterChain(t1);
    ec.RegisterChain(t2);

    ec.Call(w, {});

    EXPECT_EQ(w, -12);
}

TEST(EventChain, JMdictCall)
{
    std::shared_ptr<pugi::xml_document> XML_Doc(new pugi::xml_document());
    
    XML_Doc->load_file("./files/dictionary/JMdict.xml");
    
    Ame::Word word;
    auto q = Ame::ChainLink<Ame::Word>::Setup(&Ame::JMdict::getInformationXML, XML_Doc, std::vector<std::string>{});

    Ame::ame_result out = q->Call(word, {"食べる"});

    std::string word_ent_seq = word.ent_seq.value;
    std::string word_first_gloss = word.SENSE_List[0].GLOSS_List[0].value;
    std::string word_second_gloss = word.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358280");
    EXPECT_STREQ(word_first_gloss.c_str(), "to eat");
    EXPECT_STREQ(word_second_gloss.c_str(), "to live on (e.g. a salary)");
} 
TEST(EventChain, JMdictRegexCall)
{
    std::shared_ptr<pugi::xml_document> XML_Doc(new pugi::xml_document());
    std::shared_ptr<pugi::xml_document> RegXML_Doc(new pugi::xml_document());
    
    XML_Doc->load_file("./files/dictionary/JMdict.xml");
    RegXML_Doc->load_file("./files/regex/JMdictRegex.xml");
    
    Ame::Word word;

    auto q = Ame::ChainLink<Ame::Word>::Setup(&Ame::JMdict::getInformationXML, XML_Doc, std::vector<std::string>{});
    auto r = Ame::ChainLink<Ame::Word>::Setup(&Ame::JMdict::applyRegexXML, RegXML_Doc, std::vector<std::string>{});

    Ame::EventChain<Ame::Word> chain;
    chain.RegisterChain(q);
    chain.RegisterChain(r);

    Ame::ame_result out = chain.Call(word, {"食べる"});

    std::string word_ent_seq = word.ent_seq.value;
    std::string word_first_gloss = word.SENSE_List[0].GLOSS_List[0].value;
    std::string word_second_gloss = word.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358480");
    EXPECT_STREQ(word_first_gloss.c_str(), "Pascual eat");
    EXPECT_STREQ(word_second_gloss.c_str(), "Pascualn (e.g. a salary)");
}