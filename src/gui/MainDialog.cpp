#include "MainDialog.h"
#include "AdminDialog.h"
#include "GameDialog.h"
#include "../core/HighScoreManager.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainDialog::MainDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Trivial Pursuit");

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *nameLabel = new QLabel("Enter your name:", this);
    layout->addWidget(nameLabel);

    nameInput = new QLineEdit(this);
    layout->addWidget(nameInput);

    playButton = new QPushButton("Play Game", this);
    layout->addWidget(playButton);

    adminButton = new QPushButton("Admin", this);
    layout->addWidget(adminButton);

    highScoresButton = new QPushButton("High Scores", this);
    layout->addWidget(highScoresButton);

    connect(playButton, &QPushButton::clicked, this, &MainDialog::onPlayClicked);
    connect(adminButton, &QPushButton::clicked, this, &MainDialog::onAdminClicked);
    connect(highScoresButton, &QPushButton::clicked, this, &MainDialog::onHighScoresClicked);
}

void MainDialog::onPlayClicked() {
    QString playerName = nameInput->text().trimmed();
    if (playerName.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter your name.");
        return;
    }

    GameDialog gameDialog(playerName, this);
    gameDialog.exec();
}

void MainDialog::onAdminClicked() {
    AdminDialog adminDialog(this);
    adminDialog.exec();
}

void MainDialog::onHighScoresClicked() {
    HighScoreManager highScoreManager;
    auto highScores = highScoreManager.getHighScores();

    QString scoreText = "High Scores:\n\n";
    for (const auto& score : highScores) {
        scoreText += QString("%1: %2\n").arg(QString::fromStdString(score.first)).arg(score.second);
    }

    QMessageBox::information(this, "High Scores", scoreText);
}