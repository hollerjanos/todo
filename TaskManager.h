#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "external/json.hpp"
#include "Task.h"

class TaskManager {
private:
    const std::string fileName = "data.json";

    std::vector<Task> tasks;

    void load();
    void save();
    int getNumberOfTasks() const;
    void printTask(const int index, const std::string &description) const;
    bool isValidIndex(const int index) const;
    void createFileIfNotExist() const;
    std::string inputDescription() const;
    int inputIndex() const;
public:
    TaskManager();
    void append(const std::string &description, const bool completed = false);
    void list() const;
    void add();
    void remove();
    void close();
    void open();
};

#endif
