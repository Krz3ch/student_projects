#include <iostream>
#include "gtest/gtest.h"
#include "Stairs.cpp"

TEST(StairTest, StairTestEins) {
    Stairs stairs = makeStairs(600, 1200);

    ASSERT_EQ(stairs.canBeMade, true);
    EXPECT_EQ(stairs.stepCount, 4);
    EXPECT_EQ(stairs.stepHeight, 150);
    EXPECT_EQ(stairs.stepLength, 300);
}

TEST(StairTest, StairTestZwei) {
    Stairs stairs = makeStairs(2500, 7423);

    ASSERT_EQ(stairs.canBeMade, true);
    EXPECT_EQ(stairs.stepCount, 16);
    EXPECT_EQ(stairs.stepHeight, 156);
    EXPECT_EQ(stairs.stepLength, 463);
}

TEST(StairTest, StairTestDrei) {
    Stairs stairs = makeStairs(27000, 18180);

    ASSERT_EQ(stairs.canBeMade, false);
    EXPECT_EQ(stairs.stepCount, 0);
    EXPECT_EQ(stairs.stepHeight, 0);
    EXPECT_EQ(stairs.stepLength, 0);
}

TEST(StairTest, StairTestVier) {
    Stairs stairs = makeStairs(10001, 20002);

    ASSERT_EQ(stairs.canBeMade, true);
    EXPECT_EQ(stairs.stepCount, 66);
    EXPECT_EQ(stairs.stepHeight, 151);
    EXPECT_EQ(stairs.stepLength, 303);
}

TEST(StairTest, StairTestFunf) {
    Stairs stairs = makeStairs(200, 300);

    ASSERT_EQ(stairs.canBeMade, true);
    EXPECT_EQ(stairs.stepCount, 1);
    EXPECT_EQ(stairs.stepHeight, 200);
    EXPECT_EQ(stairs.stepLength, 300);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
