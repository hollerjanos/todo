#include "Flag.h"

void Flag::addFlag(
    const std::string &name,
    const std::function<void()> &callback
) {
    this->flags[name] = callback;
}

bool Flag::runFlag(const std::string &name) const {
    auto it = this->flags.find(name);

    if (it != this->flags.end()) {
        it->second();
        return true;
    } else {
        std::cout << "Flag not found! " << name << std::endl;
        return false;
    }
}
