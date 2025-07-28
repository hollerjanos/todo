#include "TaskManager.h"
#include "external/json.hpp"
#include <string>

void TaskManager::load() {
    std::ifstream file("data.json");
    nlohmann::json data = nlohmann::json::parse(file);
    file.close();

    for (const nlohmann::json &task : data) {
        this->append(task["id"], task["description"], task["completed"]);
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

void TaskManager::append(
    const int id,
    const std::string &description,
    const bool completed
) {
    this->tasks.push_back(Task(id, description, completed));
}

void TaskManager::printTasks() const {
    std::cout << "Open tasks: " << std::endl;
    for (const Task &task : this->tasks) {
        if (!task.getCompleted()) {
            std::cout << task.getId() << ": " << task.getDescription() << std::endl;
        }
    }

    std::cout << std::endl << "Completed tasks: " << std::endl;
    for (const Task &task : this->tasks) {
        if (task.getCompleted()) {
            std::cout << task.getId() << ": " << task.getDescription() << std::endl;
        }
    }
}

void TaskManager::add() {
    std::string description;

    std::cout << "Description of the Task: ";
    std::getline(std::cin, description);

    const int id = this->tasks.size() + 1;

    this->append(id, description, false);

    this->save();
}

void TaskManager::remove() {
    int id;

    std::cout << "ID of the Task: ";
    std::cin >> id;

    std::vector<Task>::iterator iterator = std::find_if(
        this->tasks.begin(),
        this->tasks.end(),
        [&id](const Task &task){return task.getId() == id;}
    );

    if (iterator != this->tasks.end()) {
        this->tasks.erase(iterator);

        this->save();

        std::cout << "Task has been removed!" << std::endl;
    } else {
        std::cout << "Invalid ID given!" << std::endl;
    }
}
