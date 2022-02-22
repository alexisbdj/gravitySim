#include "FileParsing.h"

TokenFlag runValidators(Parser_t * parser, char * current, TokenFlag flags)
{
    for (size_t i = 0; i < parser->ntypes; i++) {
        if ((flags & parser->types[i].value) != 0) {
            int result = parser->types[i].validator(current);
            if (result == 0) {
                flags ^= parser->types[i].value;
            }
        }
    }
    return flags;
}