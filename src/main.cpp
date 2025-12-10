#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "EventParser.h"

using namespace std;

string readLastLine() {
    ifstream file("/var/log/auth.log");
    string line, last;

    if (!file.is_open()) return "";

    while (getline(file, line)) {
        last = line;
    }

    return last;
}

int main() {
    EventParser parser;

    cout << "=== Simple Real-Time OS Security Logger ===\n";
    cout << "Program started\n";
    string previous = "";

    while (true) {
        string last = readLastLine();

        if (last != "" && last != previous) {
            SecurityEvent e = parser.parseLine(last);

            if (e.isValid) {
                cout << e.message << endl;
            }

            previous = last;
        }

        sleep(1);
    }

    return 0;
}

