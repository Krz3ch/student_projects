# Benchmarki sortowań
Celem tego zadania jest porównanie szybkości sortowania "quickSort" i bąbelkowego.

## Kod
Oto oba sortowania:
```cpp
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
```

To wykonywane testy:
```cpp
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
```

# Działanie i wyniki
Każdy test został przeprowadzony na tym samym wektorze z 1000 liczb w środku za pomocą zmiennej globalnej aby uniknąć nieprawidłowości.
Przedstawiony poniżej zrzut ekranu ukazuje prawidłowy wynik jakim jest ogromna przewaga czasowa quicksorta nad sortowaniem bąbelkowym (12ms do 498ms). Oczywiście jest to niezauważalne gdyż testy zostały przeprowadzone małej liczbie danych
![obraz](https://github.com/user-attachments/assets/10dd2cb6-fb4f-457e-8b7d-1869ec128d16)
