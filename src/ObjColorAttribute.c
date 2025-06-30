#include <string.h>
#include "DescriptionToObjects.h"
#include "ErrorHandling.h"
#include "Utils.h"

int setColorByName(DefConversionProcess *process, char * name)
{
    // TODO unuglify
    if (strcmp(name, "LIGHTGRAY") == 0) {
        process->currentWorkingObject->color = LIGHTGRAY;
    }
    else if (strcmp(name, "GRAY") == 0) {
        process->currentWorkingObject->color = GRAY;
    }
    else if (strcmp(name, "DARKGRAY") == 0) {
        process->currentWorkingObject->color = DARKGRAY;
    }
    else if (strcmp(name, "YELLOW") == 0) {
        process->currentWorkingObject->color = YELLOW;
    }
    else if (strcmp(name, "GOLD") == 0) {
        process->currentWorkingObject->color = GOLD;
    }
    else if (strcmp(name, "ORANGE") == 0) {
        process->currentWorkingObject->color = ORANGE;
    }
    else if (strcmp(name, "PINK") == 0) {
        process->currentWorkingObject->color = PINK;
    }
    else if (strcmp(name, "RED") == 0) {
        process->currentWorkingObject->color = RED;
    }
    else if (strcmp(name, "MAROON") == 0) {
        process->currentWorkingObject->color = MAROON;
    }
    else if (strcmp(name, "GREEN") == 0) {
        process->currentWorkingObject->color = GREEN;
    }
    else if (strcmp(name, "LIME") == 0) {
        process->currentWorkingObject->color = LIME;
    }
    else if (strcmp(name, "DARKGREEN") == 0) {
        process->currentWorkingObject->color = DARKGREEN;
    }
    else if (strcmp(name, "SKYBLUE") == 0) {
        process->currentWorkingObject->color = SKYBLUE;
    }
    else if (strcmp(name, "BLUE") == 0) {
        process->currentWorkingObject->color = BLUE;
    }
    else if (strcmp(name, "DARKBLUE") == 0) {
        process->currentWorkingObject->color = DARKBLUE;
    }
    else if (strcmp(name, "PURPLE") == 0) {
        process->currentWorkingObject->color = PURPLE;
    }
    else if (strcmp(name, "VIOLET") == 0) {
        process->currentWorkingObject->color = VIOLET;
    }
    else if (strcmp(name, "DARKPURPLE") == 0) {
        process->currentWorkingObject->color = DARKPURPLE;
    }
    else if (strcmp(name, "BEIGE") == 0) {
        process->currentWorkingObject->color = BEIGE;
    }
    else if (strcmp(name, "BROWN") == 0) {
        process->currentWorkingObject->color = BROWN;
    }
    else if (strcmp(name, "DARKBROWN") == 0) {
        process->currentWorkingObject->color = DARKBROWN;
    }
    else if (strcmp(name, "WHITE") == 0) {
        process->currentWorkingObject->color = WHITE;
    }
    else if (strcmp(name, "BLACK") == 0) {
        process->currentWorkingObject->color = BLACK;
    }
    else if (strcmp(name, "BLANK") == 0) {
        process->currentWorkingObject->color = BLANK;
    }
    else if (strcmp(name, "MAGENTA") == 0) {
        process->currentWorkingObject->color = MAGENTA;
    }
    else if (strcmp(name, "RAYWHITE") == 0) {
        process->currentWorkingObject->color = RAYWHITE;
    }
    else {
        printError("bad color name");
        return 1;
    }
    return 0;
}

int objSetColor(DefConversionProcess *process, Token_t *token)
{
    char * value;
        if (getTokenAsName(token, &value) == 0) {
        return setColorByName(process, value);
    }
    else {
        return 1;
    }

    return 0;
}