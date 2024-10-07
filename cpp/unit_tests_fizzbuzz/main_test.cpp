// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"


TEST(mojagrupatestow, mojtest1) {
	string wynik = fizzBuzz(10);
	EXPECT_EQ(wynik, "Buzz");
}

TEST(mojagrupatestow, mojtest2) {
	string wynik = fizzBuzz(9);
	EXPECT_EQ(wynik, "Fizz");
}

TEST(mojagrupatestow, mojtest3) {
	string wynik = fizzBuzz(15);
	EXPECT_EQ(wynik, "FizzBuzz");
}


// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

