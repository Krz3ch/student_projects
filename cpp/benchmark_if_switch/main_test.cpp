#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

using namespace std;
// Funkcja sortująca wektor za pomocą QuickSort

int checkerGlobal =  10;
//(rand()%10) + 1;

int ifCheck(int checker)
	{
		if(checker == 1){
			return 1;}

		if(checker == 2){
			return 2;}

		if(checker == 3){
			return 3;}

		if(checker == 4){
			return 4;}

		if(checker == 5){
			return 5;}

		if(checker == 6){
			return 6;}

		if(checker == 7){
			return 7;}

		if(checker == 8){
			return 8;}

		if(checker == 9){
			return 9;}

		if(checker == 10){
			return 10;}

	}


int ifElseCheck(int checker)
	{
		if(checker == 1){
			return 1;
		}else if(checker == 2){
			return 2;
		}else if(checker == 3){
			return 3;
		}else if(checker == 4){
			return 4;
		}else if(checker == 5){
			return 5;
		}else if(checker == 6){
			return 6;
		}else if(checker == 7){
			return 7;
		}else if(checker == 8){
			return 8;
		}else if(checker == 9){
			return 9;
		}else if(checker == 10){
			return 10;
		}

	}


int switchCheck(int checker)
	{
		switch(checker)
		{
			case 1:
				return 1;

			case 2:
				return 2;

			case 3:
				return 3;

			case 4:
				return 4;

			case 5:
				return 5;

			case 6:
				return 6;

			case 7:
				return 7;

			case 8:
				return 8;

			case 9:
				return 9;

			case 10:
				return 10;
		}
	}


TEST(BenchmarkTest, ifBenchmark) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    ifCheck(checkerGlobal);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sprawdzania: " << elapsed_seconds.count() << "s\n";
}


TEST(BenchmarkTest, ifElseBenchmark) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    ifElseCheck(checkerGlobal);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sprawdzania: " << elapsed_seconds.count() << "s\n";
}


TEST(BenchmarkTest, switchBenchmark) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    switchCheck(checkerGlobal);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sprawdzania: " << elapsed_seconds.count() << "s\n";
}


int main(int argc, char **argv) {
    cout<<checkerGlobal<<endl;

    cout<<ifCheck(checkerGlobal)<<endl;

    cout<<ifElseCheck(checkerGlobal)<<endl;

    cout<<switchCheck(checkerGlobal)<<endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

