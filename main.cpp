#include <iostream>

#include "FlagManager.h"

void listTasks() {
    std::cout << "Task 1" << std::endl;
    std::cout << "Task 2" << std::endl;
    std::cout << "Task 3" << std::endl;
}

void printUsage() {
    std::cout << "Usage:" << std::endl;
    std::cout << std::endl;
    std::cout << "--list\t\tList all the tasks!" << std::endl;
    std::cout << "--add\t\tCreate a new task!" << std::endl;
    std::cout << "--remove\tRemove a new task!" << std::endl;
}

int main(int argc, char *argv[]) {
    FlagManager flagManager;

    flagManager.addFlag("--help", printUsage);
    flagManager.addFlag("--list", listTasks);

    if (argc == 2) {
        if (!flagManager.runFlag(argv[1])) {
            printUsage();
        }
    } else {
        printUsage();
    }

    return 0;
}
