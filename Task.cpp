#include "Task.h"

Task::Task(
    const int id,
    const std::string &description,
    const bool isCompleted
) {
    this->id = id;
    this->description = description;
    this->isCompleted = isCompleted;
}

std::string Task::getDescription() const {
    return this->description;
}

nlohmann::json Task::getObject() const {
    nlohmann::json json;

    json["id"] = this->id;
    json["description"] = this->description;
    json["isCompleted"] = this->isCompleted;

    return json;
}
