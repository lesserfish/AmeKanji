#pragma once

#include <string>
#include <vector>
#include "Card.h"

namespace Ame
{
    class Kanji : public AbstractCard
    {
        public:
            std::string RenderTemplate(std::string Template);
            std::string RenderTemplate(std::string Template, MapTable additionalTable);
            std::string RenderTemplate(std::string Template, std::vector<MapTable> additionalTables);
            std::string Print() const;
        public:
            struct LITERAL
            {
                std::string value;
            };

            struct CODEPOINT
            {
                struct CP_VALUE
                {
                    struct CP_TYPE
                    {
                        std::string value;
                    };
                    CP_TYPE Cp_Type;
                    std::string value;
                };
                std::vector<CP_VALUE> CP_VALUE_List;
            };

            struct RADICAL
            {
                struct RAD_VALUE
                {
                    struct RAD_TYPE
                    {
                        std::string value;
                    };
                    std::string value;
                    RAD_TYPE RadType;
                };
                std::vector<RAD_VALUE> RAD_VALUE_List;
            };

            struct MISC
            {
                struct VARIANT
                {
                    struct VAR_TYPE
                    {
                        std::string value;
                    };
                    VAR_TYPE Var_Type;
                    std::string value;
                };
                std::string GRADE;
                std::string STROKE_COUNT;
                VARIANT Variant;
                std::string FREQ;
                std::string JLPT;
            };

            struct DIC_NUMBER
            {
                struct DIC_REF
                {
                    struct DR_TYPE
                    {
                        std::string value;
                    };
                    struct M_VOL
                    {
                        std::string value;
                    };
                    struct M_PAGE
                    {
                        std::string value;
                    };
                    std::string value;
                    DR_TYPE Dr_Type;
                    M_VOL M_Vol;
                    M_PAGE M_Page;
                };
                std::vector<DIC_REF> DIC_REF_List;
            };

            struct QUERY_CODE
            {
                struct Q_CODE
                {
                    struct QC_TYPE
                    {
                        std::string value;
                    };
                    std::string value;
                    QC_TYPE Qc_Type;
                };
                std::vector<Q_CODE> Q_CODE_List;
            };

            struct READING_MEANING
            {
                struct RMGROUP
                {
                    struct READING
                    {
                        struct R_TYPE
                        {
                            std::string value;
                        };
                        std::string value;
                        R_TYPE R_Type;
                    };
                    struct MEANING
                    {
                        struct M_LANG
                        {
                            std::string value;
                        };
                        std::string value;
                        M_LANG M_Lang;
                    };

                    std::vector<READING> READING_List;
                    std::vector<MEANING> MEANING_List;
                };
                struct NANORI
                {
                    std::string value;
                };

                RMGROUP Rmgroup;
                std::vector<NANORI> NANORI_List;
            };

            struct MEDIA
            {
                struct RADICAL
                {
                    std::string value;
                };

                RADICAL Radical;
            };

            MEDIA Media;
            LITERAL Literal;
            CODEPOINT Codepoint;
            RADICAL Radical;
            MISC Misc;
            DIC_NUMBER Dic_Number;
            QUERY_CODE Query_Code;
            READING_MEANING Reading_Meaning;
    };
}