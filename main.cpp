#include <iostream>

#include "FlagManager.h"
#include "TaskManager.h"

void printUsage() {
    std::cout << "Usage:" << std::endl;
    std::cout << std::endl;
    std::cout << "--list\t\tList all the tasks!" << std::endl;
    std::cout << "--add\t\tCreate a new task!" << std::endl;
    std::cout << "--remove\tRemove a new task!" << std::endl;
}

int main(int argc, char *argv[]) {
    TaskManager taskManager;
    taskManager.addTask("Test1", "Leiras 1");
    taskManager.addTask("Test2", "Leiras 2");
    taskManager.addTask("Test3", "Leiras 3");

    FlagManager flagManager;
    flagManager.addFlag("--help", printUsage);
    flagManager.addFlag("--list", [&](){taskManager.printTasks();});

    if (argc == 2) {
        if (!flagManager.runFlag(argv[1])) {
            printUsage();
        }
    } else {
        printUsage();
    }

    return 0;
}
