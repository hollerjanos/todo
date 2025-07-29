#include <iostream>

#include "FlagManager.h"
#include "TaskManager.h"

void print(const std::string &text = "") {
    std::cout << text << std::endl;
}

void help() {
    print("Usage: todo [OPTION]");
    print("Storing tasks for yourself!");
    print();
    print("  -l, --list           List all the tasks!");
    print("  -a, --add            Create a new task!");
    print("  -r, --remove         Remove a new task!");
    print("  -c, --close          Close an open task!");
    print("  -o, --open           Reopen an already closed task!");
}

int main(int argc, char *argv[]) {
    TaskManager taskManager;

    FlagManager flagManager;
    flagManager.addFlag("--help", help);
    flagManager.addFlag("-l", [&taskManager](){taskManager.list();});
    flagManager.addFlag("--list", [&taskManager](){taskManager.list();});
    flagManager.addFlag("-a", [&taskManager](){taskManager.add();});
    flagManager.addFlag("--add", [&taskManager](){taskManager.add();});
    flagManager.addFlag("-r", [&taskManager](){taskManager.remove();});
    flagManager.addFlag("--remove", [&taskManager](){taskManager.remove();});
    flagManager.addFlag("-c", [&taskManager](){taskManager.close();});
    flagManager.addFlag("--close", [&taskManager](){taskManager.close();});
    flagManager.addFlag("-o", [&taskManager](){taskManager.open();});
    flagManager.addFlag("--open", [&taskManager](){taskManager.open();});

    if (argc != 2 || !flagManager.runFlag(argv[1])) {
        help();
    }

    return 0;
}
