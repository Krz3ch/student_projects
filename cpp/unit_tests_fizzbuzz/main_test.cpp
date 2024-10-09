// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"


TEST(FizzBuzzTests, Buzz) {
	string wynik = fizzBuzz(10);
	EXPECT_EQ(wynik, "Buzz");
}

TEST(FizzBuzzTests, Fizz) {
	string wynik = fizzBuzz(9);
	EXPECT_EQ(wynik, "Fizz");
}

TEST(FizzBuzzTests, FizzBuzz) {
	string wynik = fizzBuzz(15);
	EXPECT_EQ(wynik, "FizzBuzz");
}


// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

