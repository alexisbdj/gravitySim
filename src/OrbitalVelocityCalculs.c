#include <string.h>
#include "DescriptionToObjects.h"
#include "math.h"
#include "ErrorHandling.h"
#include "VectorOperations.h"
#include "Constants.h"

static Object_t *findTargetObject(Game_t *game, char *name)
{
    ObjectList_t *node = game->objectList;

    while (node != NULL) {
        if (strcmp(node->element->name, name) == 0) {
            return node->element;
        }
        node = node->next;
    }
    return NULL;
}

void processPostCalcul(PostCreateCalcul *task, DefConversionProcess *process)
{
    Object_t *targetObject = findTargetObject(process->game, task->targetName);

    if (targetObject == NULL) {
        printError("target name not found");
        process->success = 0;
        return;
    }

    task->subject->velocity = Vector3_normalize(task->direction, sqrtf((targetObject->mass * Gconst) / getDistance(targetObject->pos, task->subject->pos)));
    task->subject->velocity = Vector3_addition(task->subject->velocity, targetObject->velocity);
}
