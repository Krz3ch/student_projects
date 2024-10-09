# Benchmarki if, else if, switch

Celem tego zadania jest porównanie szybkości działania instrukcji if, else if oraz switch, gdy są używane do oceny wartości elementów w wektorze.

## Opis funkcji

Oto funkcje używane do porównania wydajności:

- **ifCheck**: Funkcja ta iteruje przez wszystkie elementy wektora vec i zlicza, ile z nich jest większych od zera, mniejszych od zera oraz równych zeru przy użyciu instrukcji if.

- **ifElseCheck**: Ta funkcja działa podobnie do ifCheck, ale wykorzystuje instrukcje if-else if, co pozwala na bardziej efektywne wykluczanie kolejnych przypadków podczas przetwarzania elementów wektora.

- **switchCheck**: W tej funkcji instrukcja switch jest używana do oceny wartości elementów w wektorze, w zależności od tego, czy są one większe, mniejsze czy równe zeru.


## Kod
Oto funkcje sprawdzajace:
```cpp
void ifCheck(vector<int> vec) {
    int less = 0;
    int greater = 0;
    int equal = 0;

    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] > 0) {
            greater++;
        }
        if(vec[i] < 0) {
            less++;
        }
        if(vec[i] == 0) {
            equal++;
        }
    }
}

void ifElseCheck(vector<int> vec) {
    int less = 0;
    int greater = 0;
    int equal = 0;

    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] > 0) {
            greater++;
        } else if(vec[i] < 0) {
            less++;
        } else if(vec[i] == 0) {
            equal++;
        }
    }
}

void switchCheck(vector<int> vec) {
    int less = 0;
    int greater = 0;
    int equal = 0;

    for(int i = 0; i < vec.size(); i++) {
        switch(vec[i] > 0 ? 1 : vec[i] < 0 ? -1 : 0) {
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
```

To wykonywane testy:
```cpp
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
```

## Działanie i wyniki
Każdy test został przeprowadzony na tej samej globalnej zmiennej checkerGlobal, która zawiera 1 000 000 losowych wartości. Funkcje przechodzą przez wszystkie elementy wektora i zliczają wartości dodatnie, ujemne i równe zeru. Wyniki benchmarków pokazują czas potrzebny na wykonanie każdej z funkcji i umożliwiają porównanie wydajności pomiędzy różnymi konstrukcjami warunkowymi.
![image](https://github.com/user-attachments/assets/e8e5eb32-e2e1-4a1e-ae66-9d48eac9cc50)



## Wniosek
Wynik ukazuje że funkcja spradzająca za pomocą switch jest najbardziej wydajna
