#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "DescriptionToObjects.h"
#include "ErrorHandling.h"


int getTokenAsInt(Token_t *token, int *dest)
{
    int result;
    char *ending = NULL;
    if (token->type & TK_NUM) {
        errno = 0;
        result = strtol(token->content, &ending, 10);
        if (errno != 0) {
            printError(strerror(errno));
            return 1;
        }
        if (*ending != '\0') {
            warn("chars found after parsed number");
        }
        *dest = result;
    }
    else {
        return 1;
    }
    return 0;
}

int getTokenAsFloat(Token_t *token, float *dest)
{
    float result;
    char *ending = NULL;
    if (token->type & TK_FLOAT) {
        errno = 0;
        result = strtod(token->content, &ending);
        if (errno != 0) {
            printError(strerror(errno));
            return 1;
        }
        if (*ending != '\0') {
            warn("chars found after parsed number");
        }
        *dest = result;
    }
    else {
        return 1;
    }
    return 0;
}

int getTokenAsName(Token_t *token, char **dest)
{
    if (token->type & TK_NAME) {
        *dest = token->content;
    }
    else {
        return 1;
    }
    return 0;
}
