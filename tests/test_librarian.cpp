#include <gtest/gtest.h>
#include <pugixml.hpp>
#include <string>
#include <vector>
#include "../src/Ame/Jisho/Librarian.h"
#include "../src/Ame/Jisho/EventChain.h"
#include "../src/Ame/Jisho/Parsers/JMdict.h"
#include "../src/Ame/StatusCodes.h"
#include "../src/Ame/Cards/Word.h"

TEST(Librarian, DefaultArgument)
{
    auto x = Ame::Librarian<int, Ame::Parser::Edict>::RetrieveParser();
    EXPECT_FALSE(x);
}
TEST(Librarian, AutomaticJMdict)
{
    std::shared_ptr<pugi::xml_document> XML_Doc(new pugi::xml_document());
    std::shared_ptr<pugi::xml_document> RegXML_Doc(new pugi::xml_document());

    XML_Doc->load_file("./files/dictionary/JMdict.xml");
    RegXML_Doc->load_file("./files/regex/JMdictRegex.xml");

    Ame::Word w;

    auto p1 = Ame::Librarian<Ame::Word, Ame::Parser::JMdict, std::shared_ptr<pugi::xml_document>>::RetrieveParser(XML_Doc);

    Ame::EventChain<Ame::Word> chain;

    chain.RegisterChain(p1);

    Ame::ame_result out = chain.Call(w, {"食べる"});

    std::string word_ent_seq = w.ent_seq.value;
    std::string word_first_gloss = w.SENSE_List[0].GLOSS_List[0].value;
    std::string word_second_gloss = w.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358280");
    EXPECT_STREQ(word_first_gloss.c_str(), "to eat");
    EXPECT_STREQ(word_second_gloss.c_str(), "to live on (e.g. a salary)");
}
TEST(Librarian, AutomaticJMdictRegex)
{
    std::shared_ptr<pugi::xml_document> XML_Doc(new pugi::xml_document());
    std::shared_ptr<pugi::xml_document> RegXML_Doc(new pugi::xml_document());

    XML_Doc->load_file("./files/dictionary/JMdict.xml");
    RegXML_Doc->load_file("./files/regex/JMdictRegex.xml");

    Ame::Word w;

    auto p1 = Ame::Librarian<Ame::Word, Ame::Parser::JMdict, std::shared_ptr<pugi::xml_document>>::RetrieveParser(XML_Doc);
    auto p2 = Ame::Librarian<Ame::Word, Ame::Parser::JMdictRegex, std::shared_ptr<pugi::xml_document>>::RetrieveParser(RegXML_Doc);

    Ame::EventChain<Ame::Word> chain;

    chain.RegisterChain(p1);
    chain.RegisterChain(p2);

    Ame::ame_result out = chain.Call(w, {"食べる"});

    std::string word_ent_seq = w.ent_seq.value;
    std::string word_first_gloss = w.SENSE_List[0].GLOSS_List[0].value;
    std::string word_second_gloss = w.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358480");
    EXPECT_STREQ(word_first_gloss.c_str(), "Pascual eat");
    EXPECT_STREQ(word_second_gloss.c_str(), "Pascualn (e.g. a salary)");
}