#ifndef TASK_H
#define TASK_H

#include <string>
#include "external/json.hpp"

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    Task(const int id, const std::string &description, const bool completed);

    int getId() const;
    std::string getDescription() const;
    bool getCompleted() const;

    nlohmann::json getObject() const;
};

#endif
