#pragma once
#include <string>
#include <vector>

class FileReader {
public:
    std::vector<std::pair<std::string, std::string>> readQuestionsAndAnswers(const std::string& filename);
};