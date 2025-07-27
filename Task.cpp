#include "Task.h"

Task::Task(const std::string &title, const std::string &description) {
    this->title = title;
    this->description = description;
}

std::string Task::getDescription() const {
    return this->description;
}
