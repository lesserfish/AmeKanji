#pragma once

#include "../Dictionary.h"
#include "../../Cards/Word.h"
#include "../../StatusCodes.h"
#include <pugixml.hpp>
#include <memory>

namespace Ame
{

    // Class specialized in parsing dictionaries JMdict - edict2 - hispadix - hispamix
    class JMdict : public Dictionary
    {
    public:
        JMdict();
        static ame_result getInformation(Word &output, std::vector<std::string> Input, std::string &dictionary, std::vector<std::string> Args = {});
        static ame_result getInformationXML(Word &output, std::vector<std::string> Input, std::shared_ptr<pugi::xml_document> XMLDoc, std::vector<std::string> Args = {});
        static ame_result applyRegex(Word &input, std::vector<std::string> Input, std::string &Regex, std::vector<std::string> Args = {});
        static ame_result applyRegexXML(Word &input, std::vector<std::string> Input, std::shared_ptr<pugi::xml_document> Regex, std::vector<std::string> Args = {});

    private:
        static ame_result getWordInformation(Word &output, std::string Kanji, pugi::xml_document &XMLDoc, std::vector<std::string> Args = {});
        static ame_result getWordInformation(Word &output, std::string Kanji, std::string Katakana, pugi::xml_document &XMLDoc, std::vector<std::string> Args = {});

        static const char *t;

        static const char *root_name;
        static const char *entry_name;
        static const char *ent_seq_name;
        static const char *r_ele_name;
        static const char *reb_name;
        static const char *re_pri_name;
        static const char *re_inf_name;
        static const char *sense_name;
        static const char *pos_name;
        static const char *gloss_name;
        static const char *k_ele_name;
        static const char *keb_name;
        static const char *ke_pri_name;
        static const char *ke_inf_name;
        static const char *regex_root_name;
        static const char *regex_entry_name;
        static const char *regex_ent_seq_name;
        static const char *regex_r_ele_name;
        static const char *regex_reb_name;
        static const char *regex_re_pri_name;
        static const char *regex_re_inf_name;
        static const char *regex_sense_name;
        static const char *regex_pos_name;
        static const char *regex_gloss_name;
        static const char *regex_k_ele_name;
        static const char *regex_keb_name;
        static const char *regex_ke_pri_name;
        static const char *regex_ke_inf_name;
    };
}
