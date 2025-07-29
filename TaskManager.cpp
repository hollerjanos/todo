#include "TaskManager.h"
#include "external/json.hpp"
#include <filesystem>
#include <string>

void TaskManager::load() {
    std::ifstream file(this->fileName);
    nlohmann::json data = nlohmann::json::parse(file);
    file.close();

    for (const nlohmann::json &task : data) {
        this->append(task["description"], task["completed"]);
    }
}

void TaskManager::save() {
    nlohmann::json json = nlohmann::json::array();

    for (const Task &task : this->tasks) {
        json.push_back(task.getObject());
    }

    std::ofstream file(this->fileName);
    file << json.dump(4);
    file.close();
}

int TaskManager::getNumberOfTasks() const {
    return this->tasks.size();
}

TaskManager::TaskManager() {
    this->createFileIfNotExist();

    this->load();
}

void TaskManager::append(
    const std::string &description,
    const bool completed
) {
    this->tasks.push_back(Task(description, completed));
}

void TaskManager::printTask(
    const int index,
    const std::string &description
) const {
    std::cout << index << ": " << description << std::endl;
}

bool TaskManager::isValidIndex(const int index) const {
    return index >= 0 && index < this->getNumberOfTasks();
}

void TaskManager::createFileIfNotExist() const {
    if (std::filesystem::exists(this->fileName)) return;

    nlohmann::json json = nlohmann::json::array();

    std::ofstream file(this->fileName);
    file << json.dump(4);
    file.close();
}

std::string TaskManager::inputDescription() const {
    std::string description;

    std::cout << "- Description of the task: ";
    std::getline(std::cin, description);

    return description;
}

int TaskManager::inputIndex() const {
    int index;

    std::cout << "- Index of the task: ";
    std::cin >> index;

    return --index;
}

void TaskManager::list() const {
    std::cout << "Open tasks: " << std::endl;
    for (std::size_t index = 0; index < this->getNumberOfTasks(); ++index) {
        if (!this->tasks[index].getCompleted()) {
            this->printTask(index + 1, this->tasks[index].getDescription());
        }
    }

    std::cout << std::endl << "Completed tasks: " << std::endl;
    for (std::size_t index = 0; index < this->getNumberOfTasks(); ++index) {
        if (this->tasks[index].getCompleted()) {
            this->printTask(index + 1, this->tasks[index].getDescription());
        }
    }
}

void TaskManager::add() {
    std::cout << "Adding a new task" << std::endl;

    const std::string description = inputDescription();

    this->append(description);

    this->save();

    std::cout << "Task has been added!" << std::endl;
}

void TaskManager::remove() {
    std::cout << "Removing an already existing task!" << std::endl;

    const int index = this->inputIndex();

    if (this->isValidIndex(index)) {
        this->tasks.erase(this->tasks.begin() + index);

        this->save();

        std::cout << "Task has been removed!" << std::endl;
    } else {
        std::cout << "Invalid index was given!" << std::endl;
    }
}

void TaskManager::close() {
    std::cout << "Closing an open task!" << std::endl;

    const int index = this->inputIndex();

    if (this->isValidIndex(index)) {
        this->tasks[index].setCompleted(true);

        this->save();

        std::cout << "Task has been closed!" << std::endl;
    } else {
        std::cout << "Invalid index was given!" << std::endl;
    }
}

void TaskManager::open() {
    std::cout << "Opening an already closed task!" << std::endl;

    const int index = this->inputIndex();

    if (isValidIndex(index)) {
        this->tasks[index].setCompleted(false);

        this->save();

        std::cout << "Task has been reopened!" << std::endl;
    } else {
        std::cout << "Invalid index was given!" << std::endl;
    }
}
