#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string title;
    std::string description;
    bool isCompleted;
    std::string createdAt;
    std::string completedAt;

public:
    Task(const std::string &title, const std::string &description);
    std::string getDescription() const;
};

#endif
