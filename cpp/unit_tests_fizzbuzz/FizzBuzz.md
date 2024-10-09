# Test FizzBuzz
Celem tego projektu jest wykonanie prostej funkcji FizzBuzz a potem przetestowanie jej

## Opis funkcji

- **fizzBuzz**: Funkcja ta sprawdza czy element jest podzielny przez 3, 5 lub obie liczby. W przypadku różnych wyników funkcja zwraca:
	- FizzBuzz -> gdy liczba jest podzielna przez 3 i 5,
 	- Fizz -> gdy liczba jest podzielna przez 3,
  	- Buzz -> gdy liczba jest podzielna przez 5.

## Kod
Oto funkcja fizzBuzz:
```cpp
string fizzBuzz (int a)
{
	if(a%3 == 0 && a%5 == 0){
		return "FizzBuzz";
	}else if(a%3 == 0){
		return "Fizz";
	}else if(a%5 == 0){
		return "Buzz";
	}
	return "Brak";
}
```

Oto wykonywane testy:
```cpp
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
```

## Działanie testów
Testy sprawdzają czy funkcja zwróci poprawne wartości.

Wyniki testów:

| Test               | Buzz      |    Fizz   | FizzBuzz   |
|--------------------|-----------|-----------|------------|
| Wpisana wartość    |    10     |     9     |     15     | 
| Oczekiwana wartość |  "Buzz"   |  "Fizz"   | "FizzBuzz" |
| Zwrócona wartość   |  "Buzz"   |  "Fizz"   | "FizzBuzz" |
| Wynik testu        | pozytywny | pozytywny | pozytywny  |

### Zrzut ekranu przedstawiający wynik
![image](https://github.com/user-attachments/assets/78505fbe-8ca6-4a51-b2e2-77e9dc41046a)


