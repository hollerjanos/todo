#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <iostream>
#include <fstream>

#include "external/json.hpp"
#include "Task.h"

class TaskManager {
private:
    std::vector<Task> tasks;

    void load();
    void save() const;
public:
    TaskManager();
    void add(
        const int id,
        const std::string &description,
        const bool isCompleted = false
    );
    void add();
    void printTasks() const;
};

#endif
