#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>

class AdminDialog : public QDialog {
    Q_OBJECT

public:
    AdminDialog(QWidget *parent = nullptr);

private slots:
    void onAddQuestionClicked();
    void onRemoveQuestionClicked();

private:
    QLineEdit *questionInput;
    QLineEdit *answerInput;
    QComboBox *categoryCombo;
    QLineEdit *removeIdInput;
};