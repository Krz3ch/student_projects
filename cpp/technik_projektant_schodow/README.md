# Wyliczanie wymiarów schodów

## 1. Działanie
**Program służy do wyliczania wysokości, szerokości oraz ilości schodów potrzebnych do przejścia z piętra A na piętro B z uwzględnieniem ergonomicznej wysokości schodów wynosząceh 150-170 mm oraz ergonomicznej głębokości wynoszącej 290-320mm.**

## 2. Funkcjonalność
Aplikacja przyjmuje 2 parametry: Lk ( Szerość klatki ) oraz Hk ( wysokość klatki ). \
Po obliczeniach program zwraca:
- ile stopni potrzeba do przejścia między piętrem A, a piętrem B
- wysokość każdego stopnia podana w milimetrach
- głębokość każdego stopnia podana w milimetrach

## 3. Scenariusze użytkowania

### 3.1. Scenariusz prawidłowy

1) Użytkownik uruchamia aplikację.
2) Aplikacja wyświetla komunikat, że wymagane jest podanie wymiarów w milimetrach bez przecinka oraz pyta użytkownika o podanie wymiarów szerokości oraz wysokości klatki.
3) Użytkownik podaje wymiary klatki w milimetrach.
4) Aplikacja zwraca dane do użytkownika podane w sekcji `Funkcjonalność`
5) Program kończy swoje działanie.

### 3.2. Scenariusz alternatywny

1) Użytkownik uruchamia aplikację.
2) Aplikacja wyświetla komunikat, że wymagane jest podanie wymiarów w milimetrach bez przecinka oraz pyta użytkownika o podanie wymiarów szerokości oraz wysokości klatki.
3) Użytkownik podaje co najmniej jedną wartość ujemną wymiarów klatki.
4) Aplikacja zwraca komunikat o błędnej wartości pomiarów.
5) Program ponownie pyta użytkownika o podanie wymiarów szerokości oraz wysokości klatki.
6) Użytkownik podaje prawidłowe wymiary klatki w milimetrach.
7) Aplikacja zwraca dane do użytkownika podane w sekcji `Funkcjonalność`
8) Program kończy swoje działanie.

### 3.3. Scenariusz alternatywny #2

1) Użytkownik uruchamia aplikację.
2) Aplikacja wyświetla komunikat, że wymagane jest podanie wymiarów w milimetrach bez przecinka oraz pyta użytkownika o podanie wymiarów szerokości oraz wysokości klatki.
3) Użytkownik podaje co najmniej jedną wartość zerową wymiarów klatki.
4) Aplikacja zwraca komunikat o błędnej wartości pomiarów.
5) Program ponownie pyta użytkownika o podanie wymiarów szerokości oraz wysokości klatki.
6) Użytkownik podaje prawidłowe wymiary klatki w milimetrach.
7) Aplikacja zwraca dane do użytkownika podane w sekcji `Funkcjonalność`
8) Program kończy swoje działanie.


## 4. Algorytm w C++

## 5. Wyniki

## 6. Testy
