#ifndef EVENTPARSER_H
#define EVENTPARSER_H

#include <string>

struct SecurityEvent {
    std::string message;
    bool isValid = false;
};

class EventParser {
public:
    SecurityEvent parseLine(const std::string &line);
};

#endif
