#ifndef LOGMONITOR_H
#define LOGMONITOR_H

#include <string>
#include <fstream>

class LogMonitor {
public:
    std::ifstream file;

    LogMonitor(const std::string &path);
    std::string getNewLine();
};

#endif
