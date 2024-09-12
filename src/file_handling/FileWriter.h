#pragma once
#include <string>

class FileWriter {
public:
    bool addQuestion(const std::string& category, const std::string& question, const std::string& answer);
};