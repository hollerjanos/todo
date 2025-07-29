#include "Task.h"

Task::Task(
    const std::string &description,
    const bool completed
) {
    this->description = description;
    this->completed = completed;
}

std::string Task::getDescription() const {
    return this->description;
}

bool Task::getCompleted() const {
    return this->completed;
}

nlohmann::json Task::getObject() const {
    nlohmann::json json;

    json["description"] = this->description;
    json["completed"] = this->completed;

    return json;
}

void Task::setCompleted(const bool completed) {
    this->completed = completed;
}
