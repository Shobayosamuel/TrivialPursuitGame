#include <gtest/gtest.h>
#include "../../src/core/GameFunctions.h"

TEST(GameFunctionsTest, RollDice) {
    GameFunctions gf;
    int result = gf.rollDice(1, 6);
    EXPECT_GE(result, 1);
    EXPECT_LE(result, 6);
}

TEST(GameFunctionsTest, CheckAnswer) {
    GameFunctions gf;
    EXPECT_TRUE(gf.checkAnswer("Paris", "paris"));
    EXPECT_TRUE(gf.checkAnswer("New York", "new york"));
    EXPECT_FALSE(gf.checkAnswer("London", "Paris"));
}