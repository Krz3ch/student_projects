# Benchmarki sortowań
Celem tego zadania jest porównanie szybkości sortowania bąbelkowe na wektorze o losowych liczbach oraz na wektorze o tych samych wartościach

## Opis sortowań

- **bubbleSort**: Sortowanie to polega na ciągłym porównywaniu dwóch sąsiadujących elementów i zamienianiu ich kolejności do docelowego ustawienia od najmniejszej do najwiekszej lub odwrotnie.

## Kod
Oto sortowanie bubbleSort:
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

```

Oto wykonywane testy:
```cpp

TEST(BenchmarkTest, BubbleSortRandom) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(vecGlobal); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}


TEST(BenchmarkTest, BubbleSortSame) {

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(vecGlobal2); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}
```

## Działanie i wyniki

Testy zostały przeprowadzone na tym samym sortowaniu bubbleSort, lecz na różnych wektorach: vecGlobal i vecGlobal2

**Rezultat:**
| Typ Sortowania | bubbleSortRandom | bubbleSortSame |
|----------------|------------------|----------------|
| Czas działania | 815ms            | 488ms          |


Przedstawiony wynik ukazuje, że sortowanie samych jedynek jest prawie 2 razy szybsze od sortowania losowo generowanych liczb.
