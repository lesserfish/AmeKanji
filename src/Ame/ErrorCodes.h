#pragma once

#include <iostream>

namespace Ame
{
    enum errorCode
    {
        OK,
        ERR,
        conf_ERR_MISSING_REQUIRED_PARAMETER,
        conf_ERR_ADDITIONAL_PARAMETER_GIVEN,
        conf_MISSING_INPUT,
        conf_MISSING_CONFIG_FILE,
        parser_ERR,
        parser_ERR_MISSING_VALUE,
        parser_ERR_EMPTY_DIC,
    };

    struct ame_result
    {
        ame_result(){}
        ame_result(bool ok) : OK(ok){}
        ame_result(bool ok, errorCode ec) : OK(ok), value(ec){}
        ame_result(bool ok, errorCode ec, std::string m) : OK(ok), value(ec), Message(m){}
        bool OK;
        errorCode value;
        std::string Message;
    };
}