#include <string.h>
#include "DescriptionToObjects.h"
#include "Utils.h"

int ConvertDescriptionToObjects(LinkedList *objDefs, Game_t *game)
{
    DefConvertionProcess process;
    process.game = game;
    process.success = 1;

    LinkedList_foreach(objDefs, (void*)ProcessDescription, &process);
    if (!process.success)
        return 1;
    return 0;
}

void ProcessDescription(ObjectDefinition_t *def, DefConvertionProcess *process)
{
    if (strcmp(def->name, "camera") == 0) {
        ProcessCameraDefinition(def, process);
    }
}