#include "FileReader.h"
#include <fstream>
#include <sstream>

std::vector<std::pair<std::string, std::string>> FileReader::readQuestionsAndAnswers(const std::string& filename) {
    std::vector<std::pair<std::string, std::string>> questionsAndAnswers;
    std::ifstream file(filename);
    std::string line;

    // Skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, question, answer;

        std::getline(ss, id, ',');
        std::getline(ss, question, ',');
        std::getline(ss, answer, ',');

        questionsAndAnswers.emplace_back(question, answer);
    }

    return questionsAndAnswers;
}