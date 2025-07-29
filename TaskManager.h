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
    void save();
    int getNumberOfTasks() const;
    void sort();
public:
    TaskManager();
    void append(
        const int id,
        const std::string &description,
        const bool completed = false
    );
    void printTasks() const;
    void add();
    void remove();
};

#endif
