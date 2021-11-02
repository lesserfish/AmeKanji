#pragma once

#include "../Dictionary.h"
#include "../../Cards/Word.h"
#include "../../StatusCodes.h"
#include <pugixml.hpp>

namespace Ame
{

    // Class specialized in parsing dictionaries JMdict - edict2 - hispadix - hispamix
    class JMdict : public Dictionary
    {
        public:
            JMdict();
            ame_result getWordInformation(Word &output, std::string Kanji, std::vector<std::string> Args = {});
            ame_result getWordInformation(Word &output, std::string Kanji, std::string Katakana, std::vector<std::string> Args = {});

            // Do this??

            template<class T>
            ame_result getInformation(T &output, std::vector<std::string> Input = {}, std::vector<std::string> Args = {});
            
            regex_output applyRegex(Word &input);
            
            ame_result loadDictionaryFromFile(std::string file);
            ame_result loadDictionaryFromString(std::string content);

            ame_result generateRegexInstance();
        private:
            pugi::xml_document XMLDoc;
            const char * root_name;
            const char * entry_name;
            const char * ent_seq_name;
            const char * r_ele_name;
            const char * reb_name;
            const char * re_pri_name;
            const char * re_inf_name;
            const char * sense_name;
            const char * pos_name;
            const char * gloss_name;
            const char * k_ele_name;
            const char * keb_name;
            const char * ke_pri_name;
            const char * ke_inf_name;
    };
}
