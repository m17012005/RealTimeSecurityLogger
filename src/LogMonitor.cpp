#include "LogMonitor.h"
#include <iostream>

LogMonitor::LogMonitor(const std::string &path) {
    file.open(path);

    if (!file.is_open()) {
        std::cout << "Cannot open auth.log (run program using sudo)\n";
    } else {
        file.seekg(0, std::ios::end); // read new log lines only
    }
}

std::string LogMonitor::getNewLine() {
    std::string line;

    if (std::getline(file, line)) {
        return line;
    }
    return "";
}
