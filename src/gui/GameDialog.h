#pragma once
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../core/GameSetup.h"

class GameDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameDialog(const QString& playerName, QWidget *parent = nullptr);

private slots:
    void onRollClicked();
    void onAnswerSubmitted();

private:
    void updateLabels();
    void endGame();

    GameSetup gameSetup;
    QLabel *categoryLabel;
    QLabel *questionLabel;
    QLineEdit *answerInput;
    QPushButton *rollButton;
    QPushButton *submitButton;
    QLabel *scoreLabel;
    QLabel *livesLabel;
};