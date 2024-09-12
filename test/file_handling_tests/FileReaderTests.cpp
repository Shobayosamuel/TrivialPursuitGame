#include <gtest/gtest.h>
#include "../../src/file_handling/FileReader.h"

TEST(FileReaderTest, ReadQuestionsAndAnswers) {
    FileReader fr;
    auto result = fr.readQuestionsAndAnswers("../resources/questions/history.csv");
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result[0].first, "Who is the first president of the United States (last name only)?");
    EXPECT_EQ(result[0].second, "Washington");
}