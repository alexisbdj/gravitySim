#include <string.h>
#include "Algorithm.h"

int switchFncFromArray(const int fncCount, const fncPtr * fnc, fncSwitchInput * input)
{
    for (int i = 0; i < fncCount; i++) {
        if (strcmp(input->name, fnc[i].name) == 0) {
            return fnc[i].fnc(input->a, input->b);
        }
    }

    return 1;   //no function were found
}