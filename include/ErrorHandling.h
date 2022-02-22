#ifndef ERROR_HANDLING_H_
#define ERROR_HANDLING_H_

    #ifdef DEBUG
        void printError_(const char * errorMessage, const char * functionName, const char * fileName, int line);

        #define printError(errorMessage) printError_(errorMessage, __FUNCTION__, __FILE__, __LINE__)
    #else
        void printError_(const char * errorMessage);

        #define printError(errorMessage) printError_(errorMessage)
    #endif

#endif