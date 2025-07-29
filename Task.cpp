#include "Task.h"

Task::Task(
    const int id,
    const std::string &description,
    const bool completed
) {
    this->id = id;
    this->description = description;
    this->completed = completed;
}

int Task::getId() const {
    return this->id;
}

std::string Task::getDescription() const {
    return this->description;
}

bool Task::getCompleted() const {
    return this->completed;
}

nlohmann::json Task::getObject() const {
    nlohmann::json json;

    json["id"] = this->id;
    json["description"] = this->description;
    json["completed"] = this->completed;

    return json;
}

void Task::setId(const int id) {
    this->id = id;
}
