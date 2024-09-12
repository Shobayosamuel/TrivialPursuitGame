#pragma once
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

class MainDialog : public QDialog {
    Q_OBJECT

public:
    MainDialog(QWidget *parent = nullptr);

private slots:
    void onPlayClicked();
    void onAdminClicked();
    void onHighScoresClicked();

private:
    QLineEdit *nameInput;
    QPushButton *playButton;
    QPushButton *adminButton;
    QPushButton *highScoresButton;
};