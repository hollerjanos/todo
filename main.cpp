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

    FlagManager flagManager;
    flagManager.addFlag("--help", printUsage);
    flagManager.addFlag("--list", [&](){taskManager.printTasks();});
    flagManager.addFlag("--add", [&](){taskManager.add();});

    if (argc == 2) {
        if (!flagManager.runFlag(argv[1])) {
            printUsage();
        }
    } else {
        printUsage();
    }

    return 0;
}
