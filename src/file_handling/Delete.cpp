#include "Delete.h"
#include <fstream>
#include <sstream>
#include <vector>

bool Delete::removeQuestion(const std::string& category, int id) {
    std::string filename = "../resources/questions/" + category + ".csv";
    std::ifstream inFile(filename);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string idStr;
        std::getline(iss, idStr, ',');
        if (std::stoi(idStr) != id) {
            lines.push_back(line);
        }
    }

    inFile.close();

    if (lines.size() == 0) {
        return false;
    }

    std::ofstream outFile(filename, std::ios::trunc);
    for (const auto& l : lines) {
        outFile << l << "\n";
    }

    return true;
}