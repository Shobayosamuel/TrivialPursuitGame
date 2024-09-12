#pragma once
#include <string>
#include <vector>

class HighScoreManager {
public:
    void addScore(const std::string& playerName, int score);
    std::vector<std::pair<std::string, int>> getHighScores();
    void clearHighScores();
};