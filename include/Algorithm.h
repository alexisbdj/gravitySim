#ifndef ALGORITHM_H_
#define ALGORITHM_H_

typedef struct {
    char *name;
    int (*fnc)(void *a, void *b);
} fncPtr;

typedef struct {
    char *name;
    void *a;
    void *b;
} fncSwitchInput;

int switchFncFromArray(const int fncCount, const fncPtr * fnc, fncSwitchInput * input);

#endif