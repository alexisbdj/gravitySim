#include <stdio.h>
#include "ErrorHandling.h"


#ifdef DEBUG
    void printError_(const char * errorMessage, const char * functionName, const char * fileName, int line)
    {
        dprintf(2, "error: %s %s:%d -> %s\n", errorMessage, fileName, line, functionName);
    }

    #warning "is debug"

#else
    void printError_(const char * errorMessage, const char * functionName)
    {
        dprintf(2, "error: %s -> %s\n", errorMessage, functionName);
    }

    #warning "is not debug"
#endif