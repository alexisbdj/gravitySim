#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "FileParsing.h"

static const size_t blockSize = 25;

char *addCharToWord(char * current, char c)
{
    if (current == NULL) {
        current = malloc(sizeof(char) * blockSize);
        current[0] = '\0';
    }
    int len = strlen(current);
    if (((len + 1) % blockSize) == 0) {
        int nblocks = ((len + 1) / blockSize) + 1;
        current = realloc(current, sizeof(char) * (blockSize * (nblocks)));
        printf("allocation de %d blocs\n", nblocks);
    }
    current[len] = c;
    current[len + 1] = '\0';

    return current;
}
