#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

using namespace std;

//Stworzony wektor globalny aby oba testy korzystaly z tych samych danych
vector<int> vecGlobal(10000); // Tworzymy wektor z 10000 losowymi liczbami
vector<int> vecGlobal2(10000, 1); // Wektor z 10000 numerami 1


void bubbleSort(std::vector<int>& vec)
	{
		int n;

		for(int i=0; i<vec.size(); i++)
		{
			for(int j = 0; j<(vec.size() - 1); j++)
			{
				if(vec[j] > vec[j+1])
				{
					n = vec[j+1];
					vec[j+1]= vec[j];
					vec[j] = n;
				}
			}
		}
	}


// Test wydajności sortowania BubbleSort z losowymi liczbami
TEST(BenchmarkTest, BubbleSortRandom) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(vecGlobal); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

// Test wydajności sortowania BubbleSort z samymi jedynkami
TEST(BenchmarkTest, BubbleSortSame) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(vecGlobal2); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

int main(int argc, char **argv) {
    srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    generate(vecGlobal.begin(), vecGlobal.end(), std::rand);
    

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

