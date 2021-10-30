#pragma once

#include <string>
#include <vector>

namespace Ame
{
    struct Word
    {
        struct K_ELE
        {
            struct KEB
            {
                std::string value;
            };
            struct KE_PRI
            {
                std::string value;
            };
            struct KE_INF
            {
                std::string value;
            };
            std::vector<KEB> KEB_List;
            std::vector<KE_PRI> KE_PRI_List;
            std::vector<KE_INF> KE_INF_List;
        };
        struct R_ELE
        {
            struct REB
            {
                std::string value;
            };
            struct RE_PRI
            {
                std::string value;
            };
            struct RE_INF
            {
                std::string value;
            };
            std::vector<REB> REB_List;
            std::vector<RE_PRI> RE_PRI_List;
            std::vector<RE_INF> RE_INF_List;
        };
        struct SENSE
        {
            struct POS
            {
                std::string value;
            };
            struct GLOSS
            {
                std::string value;
            };
            std::vector<POS> POS_List;
            std::vector<GLOSS> GLOSS_List;
        };
        struct ENT_SEQ
        {
            std::string value;
        };

        ENT_SEQ ent_seq;
        std::vector<K_ELE> K_ELE_List;
        std::vector<R_ELE> R_ELE_List;
        std::vector<SENSE> SENSE_List;
    };
}