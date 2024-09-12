#include <gtest/gtest.h>
#include "../../src/file_handling/FileWriter.h"
#include "../../src/file_handling/FileReader.h"

TEST(FileWriterTest, AddQuestion) {
    FileWriter fw;
    bool result = fw.addQuestion("history", "Test Question", "Test Answer");
    EXPECT_TRUE(result);

    FileReader fr;
    auto questions = fr.readQuestionsAndAnswers("../resources/questions/history.csv");
    auto lastQuestion = questions.back();
    EXPECT_EQ(lastQuestion.first, "Test Question");
    EXPECT_EQ(lastQuestion.second, "Test Answer");
}