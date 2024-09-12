#include <gtest/gtest.h>
#include "../../src/file_handling/Delete.h"
#include "../../src/file_handling/FileReader.h"

TEST(DeleteTest, RemoveQuestion) {
    Delete del;
    FileReader fr;

    auto beforeQuestions = fr.readQuestionsAndAnswers("../resources/questions/history.csv");
    int lastId = beforeQuestions.size();

    bool result = del.removeQuestion("history", lastId);
    EXPECT_TRUE(result);

    auto afterQuestions = fr.readQuestionsAndAnswers("../resources/questions/history.csv");
    EXPECT_EQ(afterQuestions.size(), beforeQuestions.size() - 1);
}