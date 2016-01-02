#include "Planning.h"

void Planning::getCriticalPath() {

}

bool Planning::checkAllEndsReached() {
    for (Task& vertex : beginVertices) {
        if (!vertex.hasCriticalTime()) {
            return false;
        }
    }

    return true;
}

Planning::Planning() {

}
