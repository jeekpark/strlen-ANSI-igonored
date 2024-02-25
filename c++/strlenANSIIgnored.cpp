#include "strlenANSIIgnored.hpp"

uint64_t strlenANSIIgnored(const std::string& str)
{
    uint64_t length = 0;
    bool inEscapeSequence = false;
    const char* c_str = str.c_str();
    for (uint64_t i = 0; c_str[i] != '\0'; ++i)
    {
        if (c_str[i] == '\033')
            inEscapeSequence = true;
        else if (inEscapeSequence && c_str[i] == 'm')
            inEscapeSequence = false;
        else if (!inEscapeSequence)
            ++length;
    }
    return length;
}

uint64_t strlenANSIIgnored(const char* str)
{
    uint64_t length = 0;
    bool inEscapeSequence = false;
    for (uint64_t i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == '\033')
            inEscapeSequence = true;
        else if (inEscapeSequence && str[i] == 'm')
            inEscapeSequence = false;
        else if (!inEscapeSequence)
            ++length;
    }
    return length;
}
