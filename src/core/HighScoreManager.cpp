#include "HighScoreManager.h"
#include <fstream>
#include <algorithm>

const std::string HIGH_SCORE_FILE = "../resources/high_scores.csv";

void HighScoreManager::addScore(const std::string& playerName, int score) {
    std::ofstream file(HIGH_SCORE_FILE, std::ios::app);
    file << playerName << "," << score << "\n";
}

std::vector<std::pair<std::string, int>> HighScoreManager::getHighScores() {
    std::vector<std::pair<std::string, int>> scores;
    std::ifstream file(HIGH_SCORE_FILE);
    std::string line;

    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string name = line.substr(0, commaPos);
            int score = std::stoi(line.substr(commaPos + 1));
            scores.emplace_back(name, score);
        }
    }

    std::sort(scores.begin(), scores.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    if (scores.size() > 10) {
        scores.resize(10);
    }

    return scores;
}

void HighScoreManager::clearHighScores() {
    std::ofstream file(HIGH_SCORE_FILE, std::ios::trunc);
}