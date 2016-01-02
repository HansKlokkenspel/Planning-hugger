#include "Planning.h"

void Planning::getCriticalPath() {
    
}

bool Planning::checkAllEndsReached() {
    for (Task& vertex : beginVertices) {
        if (!vertex.hasCritical) {
            return false;
        }
    }

    return true;
}

Planning::Planning() {

}
