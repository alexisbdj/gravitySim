#ifndef FILE_READER_H_
#define FILE_READER_H_

#include <stddef.h>

typedef struct {
    size_t bufferSize;
    int fd;
    char *buffer;
    size_t cursor;
    size_t currentLength;
} FileReader_t;

FileReader_t *FileReader_create(int fd, size_t bufferSize);

char FileReader_getChar(FileReader_t *reader);

void FileReader_destroy(FileReader_t *reader);

#endif