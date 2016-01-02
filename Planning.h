#ifndef PLANNING_HUGGER_PLANNING_H
#define PLANNING_HUGGER_PLANNING_H

#include <vector>
#include <queue>
#include "Task.h"

class Planning {
public:
    Planning(const Planning&) = delete;
    Planning& operator=(const Planning&) = delete;

    Planning();

    void initTasks();

    bool allEndsReached();

    // TODO, add container type
    void getCriticalPath();
    bool checkAllEndsReached();
private:
    std::vector<Task*> beginTasks;
    std::vector<Task*> endTasks;

//    std::priority_queue<Task> criticalPath;
};

#endif //PLANNING_HUGGER_PLANNING_H
