#include "JMdict.h"

#include <iostream>
#include <pugixml.hpp>

namespace Ame
{

    const char* JMdict::root_name = "JMdict";
    const char* JMdict::entry_name = "entry";
    const char* JMdict::ent_seq_name = "ent_seq";
    const char* JMdict::r_ele_name = "r_ele";
    const char* JMdict::reb_name = "reb";
    const char* JMdict::re_pri_name = "re_pri";
    const char* JMdict::re_inf_name = "re_inf";
    const char* JMdict::sense_name = "sense";
    const char* JMdict::pos_name = "pos";
    const char* JMdict::gloss_name = "gloss";
    const char* JMdict::k_ele_name = "k_ele";
    const char* JMdict::keb_name = "keb";
    const char* JMdict::ke_pri_name = "ke_pri";
    const char* JMdict::ke_inf_name = "ke_inf";
                            
    JMdict::JMdict() : Dictionary(){}


    ame_result JMdict::getInformation(Word &output, std::string dictionary, std::vector<std::string> Input, std::vector<std::string> Args)
    {
        pugi::xml_document XMLDoc;

        ame_result dict_load;
        if(Args.size() < 1)
        {
            dict_load = loadDictionaryFromFile(XMLDoc, dictionary);
        }
        else
        {
            if(Args[0] == "file")
                dict_load = loadDictionaryFromFile(XMLDoc, dictionary);
            else if(Args[0] == "string")
                dict_load = loadDictionaryFromString(XMLDoc, dictionary);
            else
                dict_load = ame_result(false, statusCode::parser_ERR_MISSING_ARGUMENTS, "It is necessary to specify whether the dictionary is being loaded with 'file' or with 'string' on the first parameter of Args");
        }

        if(!dict_load.OK)
            return dict_load;

        if(Input.size() < 1) 
            return ame_result{false, statusCode::parser_ERR_MISSING_ARGUMENTS, "Missing arguments! Please provide the kanji of the required word!"};
        else if(Input.size() == 1)
            return getWordInformation(output, Input[0], XMLDoc, Args);
        else
            return getWordInformation(output, Input[0], Input[1], XMLDoc, Args); 
    }

    ame_result JMdict::getInformationXML(Word &output, pugi::xml_document& XMLDoc, std::vector<std::string> Input, std::vector<std::string> Args)
    {
        if(Input.size() < 1) 
            return ame_result{false, statusCode::parser_ERR_MISSING_ARGUMENTS, "Missing arguments! Please provide the kanji of the required word!"};
        else if(Input.size() == 1)
            return getWordInformation(output, Input[0], XMLDoc, Args);
        else
            return getWordInformation(output, Input[0], Input[1], XMLDoc, Args); 
    }

    ame_result JMdict::getWordInformation(Word &output, std::string Kanji, pugi::xml_document& XMLDoc, std::vector<std::string> Args){
        
        ame_result o{false, statusCode::parser_ERR_MISSING_VALUE, "Error! Failed to find the provided word."};
        
        if(XMLDoc.empty())
        {
            o.OK = false;
            o.value = statusCode::parser_ERR_EMPTY_DIC;
            o.Message = "Error! The dictionary provided is empty";
            return o;
        }
        
        pugi::xml_node root = XMLDoc.child(root_name);
        if(root.empty())
        {
            o.OK = false;
            o.value = statusCode::parser_ERR_MISSING_VALUE;
            o.Message = "Error! The XML Dictionary provided does not have a JMDict node. Are you sure this is the correct file?";
            return o;
        }

        int i = 0;
        for(pugi::xml_node entry = root.child(entry_name); entry; entry = entry.next_sibling(entry_name))
        {
            
            bool kanjiMatch = false;

            for(pugi::xml_node k_ele_instance = entry.child(k_ele_name); k_ele_instance; k_ele_instance = k_ele_instance.next_sibling(k_ele_name))
            {
                std::string entryKanji = k_ele_instance.child(keb_name).text().as_string();
                if(entryKanji == Kanji)
                    kanjiMatch = true;
            }
            if(kanjiMatch) // Found a match!
            {

                Word::ENT_SEQ thisENT_SEQ;
                std::vector<Word::K_ELE> thisK_ELE_List;
                std::vector<Word::R_ELE> thisR_ELE_List;
                std::vector<Word::SENSE> thisSENSE_List;

                //Get Entry Sequence
                std::string EntSeqValue = entry.child(ent_seq_name).text().as_string();
                thisENT_SEQ.value = EntSeqValue;

                // Get K_ELE_List

                for(pugi::xml_node K_ELE_entry = entry.child(k_ele_name); K_ELE_entry; K_ELE_entry = K_ELE_entry.next_sibling(k_ele_name))
                {
                    Word::K_ELE K_ELE_element;

                    // Get KEB entries
                    for(pugi::xml_node KEB_entry = K_ELE_entry.child(keb_name); KEB_entry; KEB_entry = KEB_entry.next_sibling(keb_name))
                    {
                        Word::K_ELE::KEB KEB_element;

                        std::string KebValue = KEB_entry.text().as_string();
                        KEB_element.value = KebValue;

                        K_ELE_element.KEB_List.push_back(KEB_element);
                    }
                    // Get KE_PRI entries

                    for(pugi::xml_node KE_PRI_entry = K_ELE_entry.child(ke_pri_name); KE_PRI_entry; KE_PRI_entry = KE_PRI_entry.next_sibling(ke_pri_name))
                    {
                        Word::K_ELE::KE_PRI KE_PRI_element;

                        std::string Ke_PriValue = KE_PRI_entry.text().as_string();
                        KE_PRI_element.value = Ke_PriValue;

                        K_ELE_element.KE_PRI_List.push_back(KE_PRI_element);
                    }

                    // Get KE_INF entries
                    
                    for(pugi::xml_node KE_INF_entry = K_ELE_entry.child(ke_inf_name); KE_INF_entry; KE_INF_entry = KE_INF_entry.next_sibling(ke_inf_name))
                    {
                        Word::K_ELE::KE_INF KE_INF_element;

                        std::string Ke_InfValue = KE_INF_entry.text().as_string();
                        KE_INF_element.value = Ke_InfValue;

                        K_ELE_element.KE_INF_List.push_back(KE_INF_element);
                    }

                   thisK_ELE_List.push_back(K_ELE_element); 
                }

                // Get R_ELE_List

                for(pugi::xml_node R_ELE_entry = entry.child(r_ele_name); R_ELE_entry; R_ELE_entry = R_ELE_entry.next_sibling(r_ele_name))
                {
                    Word::R_ELE R_ELE_element;

                    // Get REB entries
                    for(pugi::xml_node REB_entry = R_ELE_entry.child(reb_name); REB_entry; REB_entry = REB_entry.next_sibling(reb_name))
                    {
                        Word::R_ELE::REB REB_element;

                        std::string RebValue = REB_entry.text().as_string();
                        REB_element.value = RebValue;

                        R_ELE_element.REB_List.push_back(REB_element);
                    }
                    // Get RE_PRI entries

                    for(pugi::xml_node RE_PRI_entry = R_ELE_entry.child(re_pri_name); RE_PRI_entry; RE_PRI_entry = RE_PRI_entry.next_sibling(re_pri_name))
                    {
                        Word::R_ELE::RE_PRI RE_PRI_element;

                        std::string Re_PriValue = RE_PRI_entry.text().as_string();
                        RE_PRI_element.value = Re_PriValue;

                        R_ELE_element.RE_PRI_List.push_back(RE_PRI_element);
                    }

                    // Get RE_INF entries
                    
                    for(pugi::xml_node RE_INF_entry = R_ELE_entry.child(re_inf_name); RE_INF_entry; RE_INF_entry = RE_INF_entry.next_sibling(re_inf_name))
                    {
                        Word::R_ELE::RE_INF RE_INF_element;

                        std::string Re_InfValue = RE_INF_entry.text().as_string();
                        RE_INF_element.value = Re_InfValue;

                        R_ELE_element.RE_INF_List.push_back(RE_INF_element);
                    }

                   thisR_ELE_List.push_back(R_ELE_element); 
                }

                // Get SENSE_List

                for(pugi::xml_node SENSE_entry = entry.child(sense_name); SENSE_entry; SENSE_entry = SENSE_entry.next_sibling(sense_name))
                {
                    Word::SENSE SENSE_element;

                    // Get POS entries

                    for(pugi::xml_node POS_entry = SENSE_entry.child(pos_name); POS_entry; POS_entry = SENSE_entry.next_sibling(pos_name))
                    {
                        Word::SENSE::POS POS_element;

                        std::string PosValue = POS_entry.text().as_string();
                        POS_element.value = PosValue;

                        SENSE_element.POS_List.push_back(POS_element);
                    }
                    
                    // Get GLOSS entries
                    for(pugi::xml_node GLOSS_entry = SENSE_entry.child(gloss_name); GLOSS_entry; GLOSS_entry = SENSE_entry.next_sibling(gloss_name))
                    {
                        Word::SENSE::GLOSS GLOSS_element;

                        std::string GlossValue = GLOSS_entry.text().as_string();
                        GLOSS_element.value = GlossValue;

                        SENSE_element.GLOSS_List.push_back(GLOSS_element);
                    }

                    thisSENSE_List.push_back(SENSE_element);
                }

                output.ent_seq = thisENT_SEQ;
                output.K_ELE_List = thisK_ELE_List;
                output.R_ELE_List = thisR_ELE_List;
                output.SENSE_List = thisSENSE_List;

                o.OK = true;
                o.value = statusCode::OK;
                o.Message = "OK!";

                return o;
            }
        }
        return o;
    }
    ame_result JMdict::getWordInformation(Word &output, std::string Kanji, std::string Hiragana, pugi::xml_document& XMLDoc, std::vector<std::string> Args){
        ame_result o{false, statusCode::parser_ERR_MISSING_VALUE, "Error! Failed to find the provided word."};
        
        if(XMLDoc.empty())
        {
            o.OK = false;
            o.value = statusCode::parser_ERR_EMPTY_DIC;
            o.Message = "Error! The dictionary provided is empty";
            return o;
        }
        
        pugi::xml_node root = XMLDoc.child(root_name);
        if(root.empty())
        {
            o.OK = false;
            o.value = statusCode::parser_ERR_MISSING_VALUE;
            o.Message = "Error! The XML Dictionary provided does not have a JMDict node. Are you sure this is the correct file?";
            return o;
        }

        int i = 0;
        for(pugi::xml_node entry = root.child(entry_name); entry; entry = entry.next_sibling(entry_name))
        {
            
            bool kanjiMatch = false;
            bool hiraganaMatch = false;

            for(pugi::xml_node k_ele_instance = entry.child(k_ele_name); k_ele_instance; k_ele_instance = k_ele_instance.next_sibling(k_ele_name))
            {
                std::string entryKanji = k_ele_instance.child(keb_name).text().as_string();
                if(entryKanji == Kanji)
                    kanjiMatch = true;
            }
            for(pugi::xml_node r_ele_instance = entry.child(r_ele_name); r_ele_instance; r_ele_instance = r_ele_instance.next_sibling(r_ele_name))
            {
                std::string entryHiragana = r_ele_instance.child(reb_name).text().as_string();
                if(entryHiragana == Hiragana)
                    hiraganaMatch = true;
            }
            if(kanjiMatch && hiraganaMatch) // Found a match!
            {

                Word::ENT_SEQ thisENT_SEQ;
                std::vector<Word::K_ELE> thisK_ELE_List;
                std::vector<Word::R_ELE> thisR_ELE_List;
                std::vector<Word::SENSE> thisSENSE_List;

                //Get Entry Sequence
                std::string EntSeqValue = entry.child(ent_seq_name).text().as_string();
                thisENT_SEQ.value = EntSeqValue;

                // Get K_ELE_List

                for(pugi::xml_node K_ELE_entry = entry.child(k_ele_name); K_ELE_entry; K_ELE_entry = K_ELE_entry.next_sibling(k_ele_name))
                {
                    Word::K_ELE K_ELE_element;

                    // Get KEB entries
                    for(pugi::xml_node KEB_entry = K_ELE_entry.child(keb_name); KEB_entry; KEB_entry = KEB_entry.next_sibling(keb_name))
                    {
                        Word::K_ELE::KEB KEB_element;

                        std::string KebValue = KEB_entry.text().as_string();
                        KEB_element.value = KebValue;

                        K_ELE_element.KEB_List.push_back(KEB_element);
                    }
                    // Get KE_PRI entries

                    for(pugi::xml_node KE_PRI_entry = K_ELE_entry.child(ke_pri_name); KE_PRI_entry; KE_PRI_entry = KE_PRI_entry.next_sibling(ke_pri_name))
                    {
                        Word::K_ELE::KE_PRI KE_PRI_element;

                        std::string Ke_PriValue = KE_PRI_entry.text().as_string();
                        KE_PRI_element.value = Ke_PriValue;

                        K_ELE_element.KE_PRI_List.push_back(KE_PRI_element);
                    }

                    // Get KE_INF entries
                    
                    for(pugi::xml_node KE_INF_entry = K_ELE_entry.child(ke_inf_name); KE_INF_entry; KE_INF_entry = KE_INF_entry.next_sibling(ke_inf_name))
                    {
                        Word::K_ELE::KE_INF KE_INF_element;

                        std::string Ke_InfValue = KE_INF_entry.text().as_string();
                        KE_INF_element.value = Ke_InfValue;

                        K_ELE_element.KE_INF_List.push_back(KE_INF_element);
                    }

                   thisK_ELE_List.push_back(K_ELE_element); 
                }

                // Get R_ELE_List

                for(pugi::xml_node R_ELE_entry = entry.child(r_ele_name); R_ELE_entry; R_ELE_entry = R_ELE_entry.next_sibling(r_ele_name))
                {
                    Word::R_ELE R_ELE_element;

                    // Get REB entries
                    for(pugi::xml_node REB_entry = R_ELE_entry.child(reb_name); REB_entry; REB_entry = REB_entry.next_sibling(reb_name))
                    {
                        Word::R_ELE::REB REB_element;

                        std::string RebValue = REB_entry.text().as_string();
                        REB_element.value = RebValue;

                        R_ELE_element.REB_List.push_back(REB_element);
                    }
                    // Get RE_PRI entries

                    for(pugi::xml_node RE_PRI_entry = R_ELE_entry.child(re_pri_name); RE_PRI_entry; RE_PRI_entry = RE_PRI_entry.next_sibling(re_pri_name))
                    {
                        Word::R_ELE::RE_PRI RE_PRI_element;

                        std::string Re_PriValue = RE_PRI_entry.text().as_string();
                        RE_PRI_element.value = Re_PriValue;

                        R_ELE_element.RE_PRI_List.push_back(RE_PRI_element);
                    }

                    // Get RE_INF entries
                    
                    for(pugi::xml_node RE_INF_entry = R_ELE_entry.child(re_inf_name); RE_INF_entry; RE_INF_entry = RE_INF_entry.next_sibling(re_inf_name))
                    {
                        Word::R_ELE::RE_INF RE_INF_element;

                        std::string Re_InfValue = RE_INF_entry.text().as_string();
                        RE_INF_element.value = Re_InfValue;

                        R_ELE_element.RE_INF_List.push_back(RE_INF_element);
                    }

                   thisR_ELE_List.push_back(R_ELE_element); 
                }

                // Get SENSE_List

                for(pugi::xml_node SENSE_entry = entry.child(sense_name); SENSE_entry; SENSE_entry = SENSE_entry.next_sibling(sense_name))
                {
                    Word::SENSE SENSE_element;

                    // Get POS entries

                    for(pugi::xml_node POS_entry = SENSE_entry.child(pos_name); POS_entry; POS_entry = SENSE_entry.next_sibling(pos_name))
                    {
                        Word::SENSE::POS POS_element;

                        std::string PosValue = POS_entry.text().as_string();
                        POS_element.value = PosValue;

                        SENSE_element.POS_List.push_back(POS_element);
                    }
                    
                    // Get GLOSS entries
                    for(pugi::xml_node GLOSS_entry = SENSE_entry.child(gloss_name); GLOSS_entry; GLOSS_entry = SENSE_entry.next_sibling(gloss_name))
                    {
                        Word::SENSE::GLOSS GLOSS_element;

                        std::string GlossValue = GLOSS_entry.text().as_string();
                        GLOSS_element.value = GlossValue;

                        SENSE_element.GLOSS_List.push_back(GLOSS_element);
                    }

                    thisSENSE_List.push_back(SENSE_element);
                }

                output.ent_seq = thisENT_SEQ;
                output.K_ELE_List = thisK_ELE_List;
                output.R_ELE_List = thisR_ELE_List;
                output.SENSE_List = thisSENSE_List;

                o.OK = true;
                o.value = statusCode::OK;
                o.Message = "OK!";

                return o;
            }
        }
        return o;
    }

    ame_result JMdict::applyRegex(Word &input)
    {
        ame_result o{true, statusCode::OK};
        
        return o;
    }
    ame_result JMdict::generateRegexInstance(){
        return ame_result(true, statusCode::OK);
    }

}