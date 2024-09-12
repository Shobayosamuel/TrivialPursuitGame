#pragma once

#include <string>
#include <vector>
#include <utility>
#include "../core/GameFunctions.h"

class GameSetup {
public:
    GameSetup(const std::string& name, int lives = 3, int questions = 10);
    void start();
    std::pair<std::string, std::string> rollAndGetQuestion();
    bool checkAnswer(const std::string& answer);
    bool isGameOver() const;
    int getScore() const;
    int getLives() const;
    std::string getPlayerName() const;

private:
    std::string playerName;
    int maxLives;
    int maxQuestions;
    int currentLives;
    int score;
    int questionsAnswered;
    GameFunctions gameFunctions;
    std::vector<std::string> categories;
    std::vector<std::vector<std::pair<std::string, std::string>>> allQuestions;
    std::pair<std::string, std::string> currentQuestion;
};

