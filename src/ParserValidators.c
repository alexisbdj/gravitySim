#include <string.h>
#include "ParserValidators.h"

static int composed_validator(const char * current, const char * list)
{
    for (int i = 0; current[i]; i++) {
        int valid = 0;
        for (int c = 0; list[c]; c++) {
            if (current[i] == list[c])
                valid = 1;
        }
        if (valid == 0)
            return 0;
    }
    return 1;
}

static int ranged_validator(const char * current, char min, char max)
{
    for (int i = 0; current[i]; i++) {
        if (current[i] < min || current[i] > max)
            return 0;
    }
    return 1;
}

int eol_validator(const char * current)
{
    return composed_validator(current, "\n");
}

int num_validator(const char * current)
{
    return ranged_validator(current, '0', '9');
}

int float_validator(const char * current)
{
    for (int i = 0; current[i]; i++) {
        if ((current[i] < '0' || current[i] > '9') && current[i] != '.' && current[i] != 'e' && !(current[i] == '-' && i == 0)) {
            return 0;
        }
    }
    return 1;
}

int name_validator(const char * current)
{

    for (int i = 0; current[i]; i++) {
        if ((current[i] < '0' || current[i] > '9') && (current[i] < 'a' || current[i] > 'z') && (current[i] < 'A' || current[i] > 'Z'))
            return 0;
    }
    return 1;
}

int equal_validator(const char * current)
{
    if (strlen(current) != 1)
        return 0;
    return current[0] == '=';
}

int blockstart_validator(const char * current)
{
    if (strlen(current) != 1)
        return 0;
    return current[0] == '{';
}

int blockend_validator(const char * current)
{
    if (strlen(current) != 1)
        return 0;
    return current[0] == '}';
}

int areastart_validator(const char * current)
{
    if (strlen(current) != 1)
        return 0;
    return current[0] == '#';
}

int axe_validator(const char * current)
{
    (void)current;
    return 0;
}
