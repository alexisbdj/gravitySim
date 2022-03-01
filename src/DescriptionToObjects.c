#include <string.h>
#include "DescriptionToObjects.h"
#include "Utils.h"

int ConvertDescriptionToObjects(LinkedList *objDefs, Game_t *game)
{
    DefConversionProcess process;
    process.game = game;
    process.success = 1;

    LinkedList_foreach(objDefs, (void*)ProcessDescription, &process);
    if (!process.success)
        return 1;
    return 0;
}

void ProcessDescription(ObjectDefinition_t *def, DefConversionProcess *process)
{
    if (strcmp(def->name, "camera") == 0) {
        ProcessCameraDefinition(def, process);
    }
    else {
        ProcessRegularDefinition(def, process);
    }
}