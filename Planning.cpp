#include <iostream>
#include "Planning.h"

void Planning::getCriticalPath() {
    bool allEndsReached = false;

    while (!allEndsReached) {
        for (Task& task : endTasks) {
            if (task.hasCriticalTime()) {
                task.backflow();
            } else {
                // critical = processingTime;
                task.updateCriticalTime();
            }
        }

        allEndsReached = checkAllEndsReached();
    }

    std::cout << "all ends reached!";
}

bool Planning::checkAllEndsReached() {
    for (Task& vertex : beginTasks) {
        if (!vertex.hasCriticalTime()) {
            return false;
        }
    }

    return true;
}

Planning::Planning() {

}

void Planning::initTasks() {
    Task task10(0);
    Task task11(0);
    Task task12(0);

    Task task8(1);
    task8.addPrerequisiteTask(task12);

    Task task9(1);
    task9.addPrerequisiteTask(task12);

    Task task6(1);
    task6.addPrerequisiteTask(task11);
    task6.addPrerequisiteTask(task10);

    Task task7(2);
    task7.addPrerequisiteTask(task8);
    task7.addPrerequisiteTask(task9);

    Task task4(4);
    task4.addPrerequisiteTask(task6);
    task4.addPrerequisiteTask(task7);

    Task task5(5);
    task5.addPrerequisiteTask(task7);

    Task task1(3);
    task1.addPrerequisiteTask(task4);

    Task task2(2);
    task2.addPrerequisiteTask(task4);

    Task task3(9);
    task3.addPrerequisiteTask(task5);

    endTasks.push_back(task1);
    endTasks.push_back(task2);
    endTasks.push_back(task3);

    beginTasks.push_back(task10);
    beginTasks.push_back(task11);
    beginTasks.push_back(task12);
}

bool Planning::allEndsReached() {
    for (Task& task : beginTasks) {
        if (!task.hasCriticalTime()) {
            return false;
        }
    }

    return true;
}
