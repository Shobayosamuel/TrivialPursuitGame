#pragma once
#include <string>
#include <random>

class GameFunctions {
public:
    int rollDice(int min, int max);
    bool checkAnswer(const std::string& userAnswer, const std::string& correctAnswer);

private:
    std::random_device rd;
    std::mt19937 gen{rd()};

    std::string prepareStringForComparison(const std::string& str);
};