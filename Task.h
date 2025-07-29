#ifndef TASK_H
#define TASK_H

#include <string>
#include "external/json.hpp"

class Task {
private:
    std::string description;
    bool completed;

public:
    Task(const std::string &description, const bool completed);

    std::string getDescription() const;
    bool getCompleted() const;

    nlohmann::json getObject() const;

    void setCompleted(const bool completed);
};

#endif
