#include "TaskManager.h"
#include "external/json.hpp"

void TaskManager::load() {
    std::ifstream file("data.json");
    nlohmann::json data = nlohmann::json::parse(file);
    file.close();

    for (const nlohmann::json &task : data) {
        this->add(task["id"], task["description"], task["isCompleted"]);
    }
}

void TaskManager::save() const {
    nlohmann::json json = nlohmann::json::array();

    for (const Task &task : this->tasks) {
        json.push_back(task.getObject());
    }

    std::ofstream file("data.json");
    file << json.dump(4);
    file.close();
}

TaskManager::TaskManager() {
    this->load();
}

void TaskManager::add(
    const int id,
    const std::string &description,
    const bool isCompleted
) {
    this->tasks.push_back(Task(id, description, isCompleted));
}

void TaskManager::add() {
    std::string description;

    std::cout << "Description of the Task: ";
    std::cin >> description;

    const int id = this->tasks.size() + 1;

    this->add(id, description, false);

    this->save();
}

void TaskManager::printTasks() const {
    for (const Task &task : this->tasks) {
        std::cout << "Description: " << task.getDescription() << std::endl;
    }
}
