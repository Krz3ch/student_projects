# Test FizzBuzz
Celem tego projektu jest wykonanie prostej funkcji FizzBuzz a potem przetestowanie jej

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

To wykonywane testy:
```cpp
TEST(mojagrupatestow, mojtest1) {
	string wynik = fizzBuzz(10);
	EXPECT_EQ(wynik, "Buzz");
}

TEST(mojagrupatestow, mojtest2) {
	string wynik = fizzBuzz(9);
	EXPECT_EQ(wynik, "Fizz");
}

TEST(mojagrupatestow, mojtest3) {
	string wynik = fizzBuzz(15);
	EXPECT_EQ(wynik, "FizzBuzz");
}
```

## Działanie i wynik
Funkcja sprawdza czy dana liczba jest podzielna przez 3, 5 lub obie liczby i zależnie od wyniku zwraca dane słowo. Testy sprawdzają czy ta funkcja działa poprawnie
Wyniki testów:
![image](https://github.com/user-attachments/assets/6d9ca0d4-c65d-4b49-8a54-13de21644eda)

