#include "EventParser.h"

SecurityEvent EventParser::parseLine(const std::string &line) {
    SecurityEvent e;

    if (line.find("Failed password") != std::string::npos) {
        e.message = "Failed Login Detected";
        e.isValid = true;
    }
    else if (line.find("session opened for user root") != std::string::npos) {
        e.message = "Root Login Detected";
        e.isValid = true;
    }
    else if (line.find("sudo") != std::string::npos) {
        e.message = "sudo Command Used";
        e.isValid = true;
    }
    else if (line.find("useradd") != std::string::npos) {
        e.message = "New User Created";
        e.isValid = true;
    }

    return e;
}
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
