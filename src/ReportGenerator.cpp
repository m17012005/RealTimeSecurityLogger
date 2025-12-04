#include "ReportGenerator.h"
#include <fstream>

void ReportGenerator::save(const std::string &msg) {
    std::ofstream out("../reports/security_report.txt", std::ios::app);
    out << msg << "\n";
    out.close();
}
