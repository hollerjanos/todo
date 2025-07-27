#ifndef FLAG_MANAGER_H
#define FLAG_MANAGER_H

#include <iostream>
#include <map>
#include <string>
#include <functional>

class FlagManager {
private:
    std::map<std::string, std::function<void()>> flags;

public:
    void addFlag(
        const std::string &name,
        const std::function<void()> &callback
    );
    bool runFlag(const std::string &name) const;
};

#endif
