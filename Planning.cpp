#include <iostream>
#include "Planning.h"

void Planning::getCriticalPath() {
    bool allEndsReached = false;

    while (!allEndsReached) {
        for (Task* task : endTasks) {
            if (task->hasCriticalTime()) {
                task->backflow();
            } else {
                // critical = processingTime;
                task->updateCriticalTime();
            }
        }

        allEndsReached = checkAllEndsReached();
    }

    std::cout << "all ends reached!";
}

bool Planning::checkAllEndsReached() {
    for (Task* task : beginTasks) {
        if (!task->hasCriticalTime()) {
            return false;
        }
    }

    return true;
}

Planning::Planning() {

}

void Planning::initTasks() {
    Task* task10 = new Task(0);
    Task* task11 = new Task(0);
    Task* task12 = new Task(0);
    Task* task8 = new Task(1);
    Task* task9 = new Task(1);
    Task* task6 = new Task(1);
    Task* task7 = new Task(2);
    Task* task4 = new Task(4);
    Task* task5 = new Task(5);
    Task* task1 = new Task(3);
    Task* task2 = new Task(2);
    Task* task3 = new Task(9);

    task1->addPrerequisiteTask(task4);
    task2->addPrerequisiteTask(task4);
    task3->addPrerequisiteTask(task5);

    task6->addPrerequisiteTask(task11);
    task6->addPrerequisiteTask(task10);
    task6->addNextConnectedTask(task4);

    task7->addPrerequisiteTask(task8);
    task7->addPrerequisiteTask(task9);
    task7->addNextConnectedTask(task5);

    task4->addPrerequisiteTask(task6);
    task4->addPrerequisiteTask(task7);
    task4->addNextConnectedTask(task1);
    task4->addNextConnectedTask(task2);

    task5->addPrerequisiteTask(task7);
    task5->addNextConnectedTask(task3);

    task8->addPrerequisiteTask(task12);
    task8->addNextConnectedTask(task7);

    task9->addPrerequisiteTask(task12);
    task9->addNextConnectedTask(task7);

    task10->addNextConnectedTask(task6);

    task11->addNextConnectedTask(task6);

    task12->addNextConnectedTask(task8);
    task12->addNextConnectedTask(task9);

    endTasks.push_back(task1);
    endTasks.push_back(task2);
    endTasks.push_back(task3);

    beginTasks.push_back(task10);
    beginTasks.push_back(task11);
    beginTasks.push_back(task12);
}

bool Planning::allEndsReached() {
    for (Task* task : beginTasks) {
        if (!task->hasCriticalTime()) {
            return false;
        }
    }

    return true;
}
