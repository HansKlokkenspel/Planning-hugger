#include "Task.h"

Task::Task(int processingTime) :
        processingTime(processingTime), criticalTime(0) {

}

void Task::updateCriticalTime(int time) {
    criticalTime = time;
}

bool Task::hasCriticalTime() {
    return (bool) criticalTime;
}

bool Task::hasNextConnectedTasks() {
    return nextConnectedTasks.size() > 0;
}

bool Task::nextConnectedTasksHaveCriticalValues() {
    for (Task& task : nextConnectedTasks) {
        if (!task.hasCriticalTime()) {
            return false;
        }
    }

    return true;
}

void Task::backflow() {

}
