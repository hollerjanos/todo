#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <iostream>

#include "Task.h"

class TaskManager {
private:
    std::vector<Task> tasks;
public:
    void addTask(const std::string &title, const std::string &description);
    void printTasks() const;
};

#endif
