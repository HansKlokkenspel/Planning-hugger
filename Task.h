#ifndef PLANNING_HUGGER_TASK_H
#define PLANNING_HUGGER_TASK_H

#include <vector>

class Task {
public:
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    Task(int processingTime);

    // checks the highest critical time of nextVertex and assigns it to own criticalTime + processingTime
    void updateCriticalTime(int time);

    // When !nextVertices[x].hasCriticalTime, backflow from another point
    bool hasCriticalTime();
    bool hasNextConnectedTasks();
    bool nextConnectedTasksHaveCriticalValues();

    void backflow();
private:
    int processingTime;
    int criticalTime;

    std::vector<Task> prerequisiteTasks;
    std::vector<Task> nextConnectedTasks;
};

#endif //PLANNING_HUGGER_TASK_H
