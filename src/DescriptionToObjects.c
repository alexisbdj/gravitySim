#include <string.h>
#include <stdlib.h>
#include "DescriptionToObjects.h"
#include "Utils.h"
#include "ErrorHandling.h"

static int launchPostCalculs(DefConversionProcess *process)
{
    LinkedList_foreach(process->postCreateCalculs, (void*)processPostCalcul, process);
    if (process->success == 0)
        return 1;
    return 0;
}

int ConvertDescriptionToObjects(LinkedList *objDefs, Game_t *game)
{
    DefConversionProcess process;
    process.game = game;
    process.success = 1;
    process.postCreateCalculs = NULL;

    LinkedList_foreach(objDefs, (void*)ProcessDescription, &process);
    if (!process.success) {
        LinkedList_destroy(process.postCreateCalculs);
        return 1;
    }
    if (launchPostCalculs(&process) != 0) {
        LinkedList_destroy(process.postCreateCalculs);
        return 1;
    }
    LinkedList_destroy(process.postCreateCalculs);
    return 0;
}

void ProcessDescription(ObjectDefinition_t *def, DefConversionProcess *process)
{
    process->currentObjName = def->name;
    if (strcmp(def->name, "camera") == 0) {
        if (ProcessCameraDefinition(def, process) != 0) {
            process->success = 0;
        }
    }
    else {
        if (ProcessRegularDefinition(def, process) != 0) {
            process->success = 0;
        }
    }
}

PostCreateCalcul *newPostCalcul(DefConversionProcess *process)
{
    if (process->currentCalc != NULL) {
        printError("double postCalcul");
        return NULL;
    }

    process->currentCalc = malloc(sizeof(PostCreateCalcul));

    if (process->currentCalc == NULL) {
        printError("failed to malloc");
        return NULL;
    }

    process->postCreateCalculs = LinkedList_forcePush(process->postCreateCalculs, process->currentCalc);
    if (process->postCreateCalculs == NULL) {
        return NULL;
    }

    process->currentCalc->direction = (Vector3){0, 0, 0};
    process->currentCalc->subject = process->currentWorkingObject;
    process->currentCalc->targetName = NULL;

    return process->currentCalc;
}
