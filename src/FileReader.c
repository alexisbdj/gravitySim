#include <stdlib.h>
#include <unistd.h>
#include "FileReader.h"
#include "ErrorHandling.h"


FileReader_t *FileReader_create(int fd, size_t bufferSize)
{
    FileReader_t *reader = malloc(sizeof(FileReader_t));

    if (reader == NULL) {
        printError("malloc failed");
        return NULL;
    }
    reader->bufferSize = bufferSize;
    reader->fd = fd;
    reader->buffer = malloc(sizeof(char) * reader->bufferSize);

    if (reader->buffer == NULL) {
        printError("malloc failed");
        free(reader);
        return NULL;
    }
    reader->cursor = 0;
    reader->currentLength = 0;
    return reader;
}

char FileReader_getChar(FileReader_t *reader)
{
    if (reader->cursor >= reader->currentLength) {
        reader->currentLength = read(reader->fd, reader->buffer, reader->bufferSize);
        if (reader->currentLength == 0)
            return '\0';
        reader->cursor = 0;
    }
    return reader->buffer[reader->cursor++];
}

void FileReader_destroy(FileReader_t *reader)
{
    free(reader->buffer);
    free(reader);
}