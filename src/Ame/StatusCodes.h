#pragma once

#include <iostream>

namespace Ame
{
    enum statusCode
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
        parser_ERR_WRONG_TYPE,
        parser_ERR_MISSING_ARGUMENTS,
        xml_ERR_LOAD,
    };

    struct ame_result
    {
        ame_result(){}
        ame_result(bool ok) : OK(ok){}
        ame_result(bool ok, statusCode ec) : OK(ok), value(ec){}
        ame_result(bool ok, statusCode ec, std::string m) : OK(ok), value(ec), Message(m){}
        bool OK;
        statusCode value;
        std::string Message;
    };
}