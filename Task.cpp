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
    for (Task& task : prerequisiteTasks) {
        if (task.hasCriticalTime()) {
            task.backflow();
        } else {
            if (task.hasNextConnectedTasks()) {
                if (task.nextConnectedTasksHaveCriticalValues()) {
                    // vertex has list with all connected vertices, get's one with highest critical value
                    const Task& connectedTask = task.getHighestConnectedTask();
                    task.updateCriticalTime(connectedTask.criticalTime);
                    task.backflow();
                }
            }
        }
    }
}

const Task& Task::getHighestConnectedTask() {
    int highestIndex = 0;
    int highestCriticalTime = 0;
    int currentCriticalTime = 0;

    for (int i = 0; i < nextConnectedTasks.size(); ++i) {
        currentCriticalTime = nextConnectedTasks[i].criticalTime;

        if (currentCriticalTime > highestCriticalTime) {
            highestCriticalTime = currentCriticalTime;
            highestIndex = i;
        }
    }

    return nextConnectedTasks[highestIndex];
}

void Task::addNextConnectedTask(const Task& task) {
    nextConnectedTasks.push_back(task);
}

void Task::addPrerequisiteTask(const Task& task) {
    prerequisiteTasks.push_back(task);
}
