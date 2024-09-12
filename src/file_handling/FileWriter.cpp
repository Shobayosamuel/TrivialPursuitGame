#include "FileWriter.h"
#include <fstream>

bool FileWriter::addQuestion(const std::string& category, const std::string& question, const std::string& answer) {
    std::string filename = "../resources/questions/" + category + ".csv";
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        return false;
    }

    // Get the last ID
    std::ifstream readFile(filename);
    std::string line;
    int lastId = 0;
    while (std::getline(readFile, line)) {
        lastId++;
    }

    file << lastId + 1 << "," << question << "," << answer << "\n";
    return true;
}