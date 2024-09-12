#include "GameSetup.h"
#include "../file_handling/FileReader.h"
#include <iostream>

GameSetup::GameSetup(const std::string& name, int lives, int questions)
    : playerName(name), maxLives(lives), maxQuestions(questions),
      currentLives(lives), score(0), questionsAnswered(0) {
    categories = {"history", "movie", "science", "sport", "geography"};
    FileReader fileReader;
    for (const auto& category : categories) {
        allQuestions.push_back(fileReader.readQuestionsAndAnswers("../resources/questions/" + category + ".csv"));
    }
}

void GameSetup::start() {
    FileReader fileReader;
    std::vector<std::string> categories = {"history", "movie", "science", "sport", "geography"};
    std::vector<std::vector<std::pair<std::string, std::string>>> allQuestions;

    for (const auto& category : categories) {
        allQuestions.push_back(fileReader.readQuestionsAndAnswers("../resources/questions/" + category + ".csv"));
    }

    int score = 0;
    int livesLeft = maxLives;
    int questionsAnswered = 0;

    while (livesLeft > 0 && questionsAnswered < maxQuestions) {
        int categoryIndex = gameFunctions.rollDice(0, categories.size() - 1);
        auto& categoryQuestions = allQuestions[categoryIndex];

        if (categoryQuestions.empty()) {
            continue;
        }

        int questionIndex = gameFunctions.rollDice(0, categoryQuestions.size() - 1);
        auto questionPair = categoryQuestions[questionIndex];

        std::cout << "Category: " << categories[categoryIndex] << std::endl;
        std::cout << "Question: " << questionPair.first << std::endl;

        std::string userAnswer;
        std::cout << "Your answer: ";
        std::getline(std::cin, userAnswer);

        if (gameFunctions.checkAnswer(userAnswer, questionPair.second)) {
            std::cout << "Correct!" << std::endl;
            score++;
        } else {
            std::cout << "Incorrect. The correct answer was: " << questionPair.second << std::endl;
            livesLeft--;
        }

        categoryQuestions.erase(categoryQuestions.begin() + questionIndex);
        questionsAnswered++;

        std::cout << "Score: " << score << " | Lives left: " << livesLeft << std::endl << std::endl;
    }

    std::cout << "Game Over!" << std::endl;
    std::cout << "Final Score: " << score << " out of " << questionsAnswered << std::endl;
}

std::pair<std::string, std::string> GameSetup::rollAndGetQuestion() {
    int categoryIndex = gameFunctions.rollDice(0, categories.size() - 1);
    auto& categoryQuestions = allQuestions[categoryIndex];

    if (categoryQuestions.empty()) {
        return {"No more questions in this category", categories[categoryIndex]};
    }

    int questionIndex = gameFunctions.rollDice(0, categoryQuestions.size() - 1);
    currentQuestion = categoryQuestions[questionIndex];
    categoryQuestions.erase(categoryQuestions.begin() + questionIndex);

    return {currentQuestion.first, categories[categoryIndex]};
}

bool GameSetup::checkAnswer(const std::string& answer) {
    questionsAnswered++;
    bool isCorrect = gameFunctions.checkAnswer(answer, currentQuestion.second);

    // Debugging output
    std::cout << "User answer: " << answer << std::endl;
    std::cout << "Correct answer: " << currentQuestion.second << std::endl;
    std::cout << "Is correct: " << (isCorrect ? "Yes" : "No") << std::endl;

    if (isCorrect) {
        score++;
        return true;
    } else {
        currentLives--;
        return false;
    }
}

bool GameSetup::isGameOver() const {
    return currentLives <= 0 || questionsAnswered >= maxQuestions;
}

int GameSetup::getScore() const {
    return score;
}

int GameSetup::getLives() const {
    return currentLives;
}

std::string GameSetup::getPlayerName() const {
    return playerName;
}