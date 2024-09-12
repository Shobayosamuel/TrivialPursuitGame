#include "GameDialog.h"
#include "../core/HighScoreManager.h"
#include <QVBoxLayout>
#include <QMessageBox>

GameDialog::GameDialog(const QString& playerName, QWidget *parent)
    : QDialog(parent), gameSetup(playerName.toStdString(), 3, 10) {
    setWindowTitle("Trivial Pursuit Game");

    QVBoxLayout *layout = new QVBoxLayout(this);

    categoryLabel = new QLabel(this);
    layout->addWidget(categoryLabel);

    questionLabel = new QLabel(this);
    layout->addWidget(questionLabel);

    answerInput = new QLineEdit(this);
    layout->addWidget(answerInput);

    rollButton = new QPushButton("Roll Dice", this);
    layout->addWidget(rollButton);

    submitButton = new QPushButton("Submit Answer", this);
    layout->addWidget(submitButton);
    submitButton->setEnabled(false);

    scoreLabel = new QLabel(this);
    layout->addWidget(scoreLabel);

    livesLabel = new QLabel(this);
    layout->addWidget(livesLabel);

    connect(rollButton, &QPushButton::clicked, this, &GameDialog::onRollClicked);
    connect(submitButton, &QPushButton::clicked, this, &GameDialog::onAnswerSubmitted);

    updateLabels();
}

void GameDialog::onRollClicked() {
    auto [question, category] = gameSetup.rollAndGetQuestion();
    categoryLabel->setText(QString("Category: %1").arg(QString::fromStdString(category)));
    questionLabel->setText(QString::fromStdString(question));
    rollButton->setEnabled(false);
    submitButton->setEnabled(true);
    answerInput->clear();
    answerInput->setFocus();
}

void GameDialog::onAnswerSubmitted() {
    QString answer = answerInput->text().trimmed();
    if (answer.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter an answer.");
        return;
    }

    bool correct = gameSetup.checkAnswer(answer.toStdString());
    if (correct) {
        QMessageBox::information(this, "Result", "Correct answer!");
    } else {
        QMessageBox::warning(this, "Result", "Incorrect answer.");
    }

    updateLabels();

    if (gameSetup.isGameOver()) {
        endGame();
    } else {
        rollButton->setEnabled(true);
        submitButton->setEnabled(false);
    }
}

void GameDialog::updateLabels() {
    scoreLabel->setText(QString("Score: %1").arg(gameSetup.getScore()));
    livesLabel->setText(QString("Lives: %1").arg(gameSetup.getLives()));
}

void GameDialog::endGame() {
    QMessageBox::information(this, "Game Over", QString("Final Score: %1").arg(gameSetup.getScore()));
    HighScoreManager highScoreManager;
    highScoreManager.addScore(gameSetup.getPlayerName(), gameSetup.getScore());
    accept();
}