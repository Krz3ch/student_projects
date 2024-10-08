#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

using namespace std;
// Funkcja sortująca wektor za pomocą QuickSort

vector<int> checkerGlobal(100000);

//(rand()%10) + 1;

void ifCheck(vector<int> vec)
	{
		int less = 0;
		int greater = 0;
		int equal = 0;

		for(int i = 0; i<vec.size(); i++)
		{
			if(vec[i] > 0)
			{
				greater++;
			}

			if(vec[i] < 0)
			{
				less++;
			}

			if(vec[i] == 0)
			{
				equal++;
			}
		}
	}


void ifElseCheck(vector<int> vec)
	{

		int less = 0;
		int greater = 0;
		int equal = 0;

		for(int i = 0; i<vec.size(); i++)
		{
			if(vec[i] > 0)
			{
				greater++;
			}
			else if(vec[i] < 0)
			{
				less++;
			}
			else if(vec[i] == 0)
			{
				equal++;
			}
		}
	}


void switchCheck(vector<int> vec)
	{
		int less = 0;
		int greater = 0;
		int equal = 0;

		for(int i = 0; i<vec.size(); i++)
		{
			switch(vec[i] > 0 ? 1 : vec[i] < 0 ? -1 : 0)
			{
				case 1:
					greater++;
					break;
				case -1:
					less++;
					break;
				case 0:
					equal++;
					break;
			}
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

