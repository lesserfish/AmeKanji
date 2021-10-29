#pragma once

#include <tuple>

namespace Ame
{
    typedef std::tuple<char *, char *> omsg;
    static omsg outputMessages[] = {omsg("E!NO_CONFIG_FILE", "Error! Failed to find the configuration file!"),
                                    omsg("E!NO_INPUT_FILE", "Error! Failed to find the input file!"),
                                    omsg("E!", "Error! No further information available!"),
                                    omsg("S!", "Success! Everything worked out well!"),
                                    omsg("W!UNRCGNZ_WRD", "Warning! Fail to recognize the following word: ")};
}