#include <stdio.h>
#include "ErrorHandling.h"


#ifdef DEBUG
    void printError_(const char * errorMessage, const char * functionName, const char * fileName, int line)
    {
        dprintf(2, "error: %s %s:%d -> %s\n", errorMessage, fileName, line, functionName);
    }

#else
    void printError_(const char * errorMessage)
    {
        dprintf(2, "error: %s\n", errorMessage);
    }

#endif

void warn(const char * warnMessage)
{
    printf("WARNING: %s\n", warnMessage);
}

