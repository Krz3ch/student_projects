# Benchmarki if, else if, switch
Celem tego zadania jest porównanie szybkości if, else if oraz switcha

## Opis funkcji
Oto funkcje testowe używane do porównania:

- **ifCheck**: Funkcja ta sprawdza kolejne wartości zmiennej `checker` za pomocą sekwencji instrukcji `if`.
  
- **ifElseCheck**: Tutaj do sprawdzenia wartości zmiennej używane są instrukcje `if-else if`, co pozwala wykluczać kolejne przypadki w miarę poruszania się przez listę warunków.

- **switchCheck**: Funkcja korzysta z instrukcji `switch`, aby porównać wartość zmiennej z różnymi przypadkami (ang. cases).


## Kod
Oto funkcje sprawdzajace:
```cpp
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

# Działanie i wyniki
Każdy test został przeprowadzony na tej samej zmiennej globalnej o wartosci 10. Każda z funkcji przechodziła po kolei od 1 do 10 i sprawdzała czy zmienna jest jej równa. Funkcja kończyła działanie gdy liczba będzie równa liczbie 10. Jest to tak zrobione aby funkcja przeszła po każdej liczbie i wykonywała się jak najdłużej. Wynikiem przedstawionego benchmarka jest: 
![image](https://github.com/user-attachments/assets/d8e234c4-c1f4-4df6-b576-dcf55f8dae09)

