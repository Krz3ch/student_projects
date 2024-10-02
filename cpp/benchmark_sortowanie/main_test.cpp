#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

using namespace std;
// Funkcja sortująca wektor za pomocą QuickSort

//Stworzony wektor globalny aby oba testy korzystaly z tych samych danych
vector<int> vecGlobal(10000); // Tworzymy wektor z 10000 losowymi liczbami


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

void quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

// Test wydajności sortowania QuickSort
TEST(BenchmarkTest, QuickSortBenchmark) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(vecGlobal); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}


TEST(BenchmarkTest, BubbleSortBenchmark) {
    //std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    //std::generate(vec.begin(), vec.end(), std::rand);

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(vecGlobal); // Sortujemy wektor

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

