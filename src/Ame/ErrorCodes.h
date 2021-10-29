#pragma once

namespace Ame
{
    enum ameError
    {
        ame_SUCCESS,
        ame_ARGPARSER_MISSING_REQUIRED_PARAMETER,
        ame_ARGPARSER_ADDITIONAL_PARAMETER_GIVEN,
        ame_ARGPARSER_MISSING_INPUT,
        ame_ARGPARSER_MISSING_CONFIG_FILE
    };
}