#include "strlen_ANSI_ignored.h"

uint64_t strlen_ANSI_ignored(const char* str)
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
