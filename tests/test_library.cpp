#include <gtest/gtest.h>
#include <pugixml.hpp>
#include <string>
#include "../src/Ame/Jisho/Regex/RegexParser.h"
#include "../src/Ame/Jisho/Library.h"
#include "../src/Ame/Jisho/Parsers/JMdict.h"
#include "../src/Ame/AmeConfig.h"
#include "../src/Ame/Cards/Word.h"

TEST(JishoLibrary, InvokeRegexParserManually_XML)
{
    // Load dictionary from pugi::xml_document
    
    pugi::xml_document DictXMLDoc;
    DictXMLDoc.load_file("./files/dictionary/JMdict.xml"); 

    pugi::xml_document RegexXMLDoc;
    RegexXMLDoc.load_file("./files/regex/JMdictRegex.xml");

    Ame::AmeConfig configInstace;
    Ame::AmeLibrary<Ame::Word> lib(configInstace);

    Ame::Word word;

    Ame::ame_result output_A = lib.loadParserManually(Ame::JMdict::getInformationXML);
    Ame::ame_result output_B = lib.loadRegexParserManually(Ame::JMdict::applyRegexXML);

    Ame::ame_result output_C = lib.invokeParser(word, DictXMLDoc, {"食べる"}, {});
    Ame::ame_result output_D = lib.InvokeRegex(word, RegexXMLDoc, {});

    EXPECT_EQ(output_A.OK, true);
    EXPECT_EQ(output_B.OK, true);
    EXPECT_EQ(output_C.OK, true);
    EXPECT_EQ(output_D.OK, true);

    std::string word_ent_seq = word.ent_seq.value;
    std::string word_first_gloss = word.SENSE_List[0].GLOSS_List[0].value;
    std::string word_second_gloss = word.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358480");
    EXPECT_STREQ(word_first_gloss.c_str(), "Pascual eat");
    EXPECT_STREQ(word_second_gloss.c_str(), "Pascualn (e.g. a salary)");
} 

TEST(JishoLibrary, InvokeParserManually_XML)
{
    // Load dictionary from pugi::xml_document

    pugi::xml_document DictXMLDoc;
    DictXMLDoc.load_file("./files/dictionary/JMdict.xml");
    
    Ame::AmeConfig configInstace;
    Ame::AmeLibrary<Ame::Word> lib(configInstace);

    Ame::Word word;

    Ame::ame_result output_A = lib.loadParserManually(Ame::JMdict::getInformationXML);

    Ame::ame_result output_B = lib.invokeParser(word, DictXMLDoc, {"食べる"}, {});

    EXPECT_EQ(output_A.OK, true);
    EXPECT_EQ(output_B.OK, true);

    std::string word_ent_seq = word.ent_seq.value;
    std::string word_first_keb = word.K_ELE_List[0].KEB_List[0].value;
    std::string word_second_ke_ele_reb = word.K_ELE_List[1].KEB_List[0].value;
    std::string word_first_reb = word.R_ELE_List[0].REB_List[0].value;
    std::string word_second_gloss = word.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358280");
    EXPECT_STREQ(word_first_keb.c_str(), "食べる");
    EXPECT_STREQ(word_second_ke_ele_reb.c_str(), "喰べる");
    EXPECT_STREQ(word_first_reb.c_str(), "たべる");
    EXPECT_STREQ(word_second_gloss.c_str(), "to live on (e.g. a salary)");
}

TEST(JishoLibrary, InvokeRegexParserManually_Path)
{
    // Load dictionary from file dir
    Ame::AmeConfig configInstace;
    Ame::AmeLibrary<Ame::Word> lib(configInstace);

    Ame::Word word;

    Ame::ame_result output_A = lib.loadParserManually(Ame::JMdict::getInformation);
    Ame::ame_result output_B = lib.loadRegexParserManually(Ame::JMdict::applyRegex);

    Ame::ame_result output_C = lib.invokeParser(word, "./files/dictionary/JMdict.xml", {"食べる"}, {});
    Ame::ame_result output_D = lib.InvokeRegex(word, "./files/regex/JMdictRegex.xml", {});

    EXPECT_EQ(output_A.OK, true);
    EXPECT_EQ(output_B.OK, true);
    EXPECT_EQ(output_C.OK, true);
    EXPECT_EQ(output_D.OK, true);

    std::string word_ent_seq = word.ent_seq.value;
    std::string word_first_gloss = word.SENSE_List[0].GLOSS_List[0].value;
    std::string word_second_gloss = word.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358480");
    EXPECT_STREQ(word_first_gloss.c_str(), "Pascual eat");
    EXPECT_STREQ(word_second_gloss.c_str(), "Pascualn (e.g. a salary)");
} 
TEST(JishoLibrary, InvokeParserManually_Path)
{
    // Load dictionary from file dir
    Ame::AmeConfig configInstace;
    Ame::AmeLibrary<Ame::Word> lib(configInstace);

    Ame::Word word;

    Ame::ame_result output_A = lib.loadParserManually(Ame::JMdict::getInformation);
    Ame::ame_result output_B = lib.invokeParser(word, "./files/dictionary/JMdict.xml", {"食べる"});

    EXPECT_EQ(output_A.OK, true);
    EXPECT_EQ(output_B.OK, true);

    std::string word_ent_seq = word.ent_seq.value;
    std::string word_first_keb = word.K_ELE_List[0].KEB_List[0].value;
    std::string word_second_ke_ele_reb = word.K_ELE_List[1].KEB_List[0].value;
    std::string word_first_reb = word.R_ELE_List[0].REB_List[0].value;
    std::string word_second_gloss = word.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358280");
    EXPECT_STREQ(word_first_keb.c_str(), "食べる");
    EXPECT_STREQ(word_second_ke_ele_reb.c_str(), "喰べる");
    EXPECT_STREQ(word_first_reb.c_str(), "たべる");
    EXPECT_STREQ(word_second_gloss.c_str(), "to live on (e.g. a salary)");
}

TEST(JishoLibrary, LoadRegexParserAutomatically)
{
    // Load both JMDict parser and JMDict Regex parser from configuration file
    Ame::AmeConfig configInstace;
    configInstace.Parser = "JMdict";
    
    Ame::AmeLibrary<Ame::Word> lib(configInstace);

    Ame::Word word;

    Ame::ame_result output_A = lib.loadParserAutomatically();
    Ame::ame_result output_B = lib.loadRegexParserAutomatically();

    Ame::ame_result output_C = lib.invokeParser(word, "./files/dictionary/JMdict.xml", {"食べる"}, {});
    Ame::ame_result output_D = lib.InvokeRegex(word, "./files/regex/JMdictRegex.xml", {});

    EXPECT_EQ(output_A.OK, true);
    EXPECT_EQ(output_B.OK, true);
    EXPECT_EQ(output_C.OK, true);
    EXPECT_EQ(output_D.OK, true);

    std::string word_ent_seq = word.ent_seq.value;
    std::string word_first_gloss = word.SENSE_List[0].GLOSS_List[0].value;
    std::string word_second_gloss = word.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358480");
    EXPECT_STREQ(word_first_gloss.c_str(), "Pascual eat");
    EXPECT_STREQ(word_second_gloss.c_str(), "Pascualn (e.g. a salary)");
} 
TEST(JishoLibrary, LoadParserAutomatically)
{
    // Load JMDict parsers from configuration file
    Ame::AmeConfig configInstace;
    configInstace.Parser = "JMdict";

    Ame::AmeLibrary<Ame::Word> lib(configInstace);


    Ame::Word word;

    Ame::ame_result output_A = lib.loadParserAutomatically();
    Ame::ame_result output_B = lib.invokeParser(word, "./files/dictionary/JMdict.xml", {"食べる"});

    EXPECT_EQ(output_A.OK, true);
    EXPECT_EQ(output_B.OK, true);

    std::string word_ent_seq = word.ent_seq.value;
    std::string word_first_keb = word.K_ELE_List[0].KEB_List[0].value;
    std::string word_second_ke_ele_reb = word.K_ELE_List[1].KEB_List[0].value;
    std::string word_first_reb = word.R_ELE_List[0].REB_List[0].value;
    std::string word_second_gloss = word.SENSE_List[1].GLOSS_List[0].value;

    EXPECT_STREQ(word_ent_seq.c_str(), "1358280");
    EXPECT_STREQ(word_first_keb.c_str(), "食べる");
    EXPECT_STREQ(word_second_ke_ele_reb.c_str(), "喰べる");
    EXPECT_STREQ(word_first_reb.c_str(), "たべる");
    EXPECT_STREQ(word_second_gloss.c_str(), "to live on (e.g. a salary)");
}