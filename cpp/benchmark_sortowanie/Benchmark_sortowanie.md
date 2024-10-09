# Benchmarki sortowań
Celem tego zadania jest porównanie szybkości sortowania "quickSort" i bąbelkowego oraz wskazanie które z tych sortowań jest szybsze.

## Opis sortowań

- **bubbleSort**: Sortowanie to polega na ciągłym porównywaniu dwóch sąsiadujących elementów i zamienianiu ich kolejności jeżeli docelowo są źle ustawione.

- **quickSort**: Sortowanie to polega na ustaleniu pivota ( w tym przypadku środka wektora ) i podzieleniu naszego wektora na dwie części. Następnie każda wartość wektora jest sprawdzana z tym pivotem i w zależności czy jest mniejsza lub większa od niego jest przestawiana na daną stronę pivota, do vectorów left lub right. Na końcu wektory te są z powrotem łączone do wektora startowego tworząc prawidłowy układ.

## Kod
Oto opisane sortowania:
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

Oto wykonywane testy:
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

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(vecGlobal); // Sortujemy wektor

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}
```

## Działanie i wyniki
Każdy test został przeprowadzony na tym samym wektorze zawierającym 10000 liczb. Wektor ten jest zmienną globalną aby oba testy były wykonywane na tych samych danych i wynik był jak najbardziej wiarygodny.

**Rezultat:**
| Typ Sortowania | quickSort | quickSort |
|----------------|-----------|-----------|
| Czas działania | 12ms      | 498ms     |


Przedstawiony wynik ukazuje prawidłowy wynik jakim jest ogromna przewaga czasowa quickSort nad bubbleSort (12ms do 498ms). Przedstawiony wynik jest jednakże niezauważalny przy kompilacji, ponieważ oba sortowania są wykonywane w czasie około 0.5 sekundy.

### Zrzut ekranu przedstawiający wynik
![obraz](https://github.com/user-attachments/assets/10dd2cb6-fb4f-457e-8b7d-1869ec128d16)
