#include "GameFunctions.h"
#include <algorithm>
#include <cctype>

int GameFunctions::rollDice(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

bool GameFunctions::checkAnswer(const std::string& userAnswer, const std::string& correctAnswer) {
    return prepareStringForComparison(userAnswer) == prepareStringForComparison(correctAnswer);
}

std::string GameFunctions::prepareStringForComparison(const std::string& str) {
    std::string result = str;

    // Convert to lowercase
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    // Remove leading and trailing whitespace
    result.erase(0, result.find_first_not_of(" \t\n\r\f\v"));
    result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);

    // Remove all punctuation and special characters
    result.erase(std::remove_if(result.begin(), result.end(),
                                [](unsigned char c){ return std::ispunct(c) || !std::isalnum(c); }),
                 result.end());

    return result;
}