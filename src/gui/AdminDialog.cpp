#include "AdminDialog.h"
#include "../file_handling/FileWriter.h"
#include "../file_handling/Delete.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <string>

AdminDialog::AdminDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Admin Panel");

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *addQuestionLabel = new QLabel("Add Question:", this);
    layout->addWidget(addQuestionLabel);

    questionInput = new QLineEdit(this);
    questionInput->setPlaceholderText("Enter question");
    layout->addWidget(questionInput);

    answerInput = new QLineEdit(this);
    answerInput->setPlaceholderText("Enter answer");
    layout->addWidget(answerInput);

    categoryCombo = new QComboBox(this);
    categoryCombo->addItems({"history", "movie", "science", "sport", "geography"});
    layout->addWidget(categoryCombo);

    QPushButton *addButton = new QPushButton("Add Question", this);
    layout->addWidget(addButton);

    QLabel *removeQuestionLabel = new QLabel("Remove Question:", this);
    layout->addWidget(removeQuestionLabel);

    removeIdInput = new QLineEdit(this);
    removeIdInput->setPlaceholderText("Enter question ID");
    layout->addWidget(removeIdInput);

    QPushButton *removeButton = new QPushButton("Remove Question", this);
    layout->addWidget(removeButton);

    connect(addButton, &QPushButton::clicked, this, &AdminDialog::onAddQuestionClicked);
    connect(removeButton, &QPushButton::clicked, this, &AdminDialog::onRemoveQuestionClicked);
}

void AdminDialog::onAddQuestionClicked() {
    QString question = questionInput->text().trimmed();
    QString answer = answerInput->text().trimmed();
    QString category = categoryCombo->currentText();

    if (question.isEmpty() || answer.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter both question and answer.");
        return;
    }

    FileWriter fileWriter;
    if (fileWriter.addQuestion(category.toStdString(), question.toStdString(), answer.toStdString())) {
        QMessageBox::information(this, "Success", "Question added successfully.");
        questionInput->clear();
        answerInput->clear();
    } else {
        QMessageBox::warning(this, "Error", "Failed to add question.");
    }
}

void AdminDialog::onRemoveQuestionClicked() {
    QString idStr = removeIdInput->text().trimmed();
    QString category = categoryCombo->currentText();

    if (idStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a question ID.");
        return;
    }

    bool ok;
    int id = idStr.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Invalid question ID.");
        return;
    }

    Delete deleteObj;
    if (deleteObj.removeQuestion(category.toStdString(), id)) {
        QMessageBox::information(this, "Success", "Question removed successfully.");
        removeIdInput->clear();
    } else {
        QMessageBox::warning(this, "Error", "Failed to remove question.");
    }
}