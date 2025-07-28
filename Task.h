#ifndef TASK_H
#define TASK_H

#include <string>
#include "external/json.hpp"

class Task {
private:
    int id;
    std::string description;
    bool isCompleted;

public:
    Task(const int id, const std::string &description, const bool isCompleted);
    std::string getDescription() const;
    nlohmann::json getObject() const;
};

#endif
