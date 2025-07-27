#include "TaskManager.h"

void TaskManager::addTask(
    const std::string &title,
    const std::string &description
) {
    this->tasks.push_back(Task(title, description));
}

void TaskManager::printTasks() const {
    for (const Task &task : this->tasks) {
        std::cout << "Description: " << task.getDescription() << std::endl;
    }
}
