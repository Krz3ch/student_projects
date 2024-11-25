# Wyliczanie wymiarów schodów

## 1. Działanie
**Program służy do wyliczania wysokości, szerokości oraz ilości schodów potrzebnych do przejścia z piętra A na piętro B z uwzględnieniem ergonomicznej wysokości schodów wynosząceh 150-170 mm oraz ergonomicznej głębokości wynoszącej minimum 290 mm. W przypadku, gdy liczba schodów będzie bardzo niska, program może zwrócić niergonomiczną wysokość stopnia, gdyż podzielenie tak małej wysokości jest niepotrzebne.**

## 2. Funkcjonalność
Aplikacja przyjmuje 2 parametry: Lk ( Szerość klatki ) oraz Hk ( wysokość klatki ). \
Po obliczeniach program zwraca:
- ile stopni potrzeba do przejścia między piętrem A, a piętrem B
- wysokość każdego stopnia podana w milimetrach
- głębokość każdego stopnia podana w milimetrach

## 3. Klasa Stairs
```cpp
class Stairs
{
public:
    int stepHeight;
    int stepLength;
    int stepCount;
    bool canBeMade = false;
    Stairs(int height, int length, int count, bool isOk) : stepHeight(height), stepLength(length), stepCount(count), canBeMade(isOk) {}
};
```
Klasa Stairs przechowuje informacje o schodach, takie jak wysokość pojedynczego stopnia, jego długość, liczba stopni oraz czy schody mogą zostać wykonane. Zawiera cztery publiczne atrybuty: stepHeight, stepLength, stepCount i canBeMade, które są inicjalizowane w konstruktorze. Konstruktor przyjmuje cztery argumenty: wysokość, długość, liczbę stopni oraz informację o możliwości wykonania schodów, co pozwala na tworzenie obiektów reprezentujących schody z określonymi parametrami.

## 4. Funkcja makeStairs

```cpp
Stairs makeStairs(int kHeight, int kLength) {

    int stairsCount = 0, stairsHeight, stairsLength, test;

    for (int i = 150; i < 170; i++) {
        if (kHeight % i == 0) {
            test = kHeight / i;
            stairsCount = test;
            break;
        }
    }

    if (stairsCount == 0) {
        if (round(kHeight / 150) == 0) {
            stairsCount = 1;
        }
        else {
            stairsCount = round(kHeight / 150);
        }
    }

    stairsHeight = kHeight / stairsCount;
    stairsLength = kLength / stairsCount;

    if (stairsLength < 290) {
        return Stairs(0, 0, 0, false);
    }

    return Stairs(stairsHeight, stairsLength, stairsCount, true);
};
```
Funkcja makeStairs oblicza wymiary schodów na podstawie wprowadzonych danych: wysokości i szerokości klatki schodowej. Najpierw stara się znaleźć liczbę stopni, dzieląc wysokość przez wartości od 150 do 170. Jeśli nie znajdzie odpowiedniego dzielnika, ustawia liczbę stopni na zaokrągloną wartość dzielenia przez 150. Następnie oblicza wysokość i długość stopnia. Jeśli długość stopnia jest mniejsza niż 290, zwraca obiekt Stairs z zerowymi wartościami i zwraca flagę false, informując, że schody nie mogą zostać wykonane. W przeciwnym razie zwraca obiekt Stairs z obliczonymi wartościami oraz flagą true, oznaczając, że schody mogą zostać wykonane.

## 5. Main

```cpp
int main()
{
    int uX, uY;

    while (true) {
        cout << "Podaj wysokosc klatki: ";
        cin >> uY;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Dane nie sa prawidlowe. Wpisz ponownie. \n";
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Podaj szerokosc klatki: ";
        cin >> uX;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Dane nie sa prawidlowe. Wpisz ponownie. \n";
        }
        else {
            break;
        }
    }

    Stairs stairs = makeStairs(uY, uX);

    if (stairs.canBeMade) {
        cout << stairs.stepCount << ", " << stairs.stepHeight << ", " << stairs.stepLength << endl;
    }
    else {
        cout << "Schody nie moga zostac wykonane." << endl;
    }

    return 0;

}
```
Funkcja main pobiera od użytkownika dane o wysokości i szerokości klatki schodowej, sprawdzając poprawność wprowadzonych wartości. Po uzyskaniu prawidłowych danych wywołuje funkcję makeStairs, która oblicza wymiary schodów. Jeśli schody mogą zostać wykonane, program wypisuje liczbę stopni, wysokość i długość stopnia. W przeciwnym razie wyświetla komunikat, że schody nie mogą zostać zbudowane. Program kończy działanie po wypisaniu odpowiedniego komunikatu.

## 6. Testy

Testy są wykonywane aby sprawdzić, czy po wprowadzeniu danych wymiarów klatki schodowej do funkcji, zwracany wynik będzie oddawany w prawidłowy sposób i czy schody mogą zostać wykonane. Wykonano 5 testów, a oto 3 z nich:

**Test 1**
```cpp
TEST(StairTest, StairTestEins) {
    Stairs stairs = makeStairs(600, 1200);

    ASSERT_EQ(stairs.canBeMade, true);
    EXPECT_EQ(stairs.stepCount, 4);
    EXPECT_EQ(stairs.stepHeight, 150);
    EXPECT_EQ(stairs.stepLength, 300);
}
```

**Test 2**
```cpp
TEST(StairTest, StairTestZwei) {
    Stairs stairs = makeStairs(2500, 7423);

    ASSERT_EQ(stairs.canBeMade, true);
    EXPECT_EQ(stairs.stepCount, 16);
    EXPECT_EQ(stairs.stepHeight, 156);
    EXPECT_EQ(stairs.stepLength, 463);
}
```

**Test 3**
```cpp
TEST(StairTest, StairTestDrei) {
    Stairs stairs = makeStairs(27000, 18180);

    ASSERT_EQ(stairs.canBeMade, false);
    EXPECT_EQ(stairs.stepCount, 0);
    EXPECT_EQ(stairs.stepHeight, 0);
    EXPECT_EQ(stairs.stepLength, 0);
}
```
### Oto wyniki testów przedstawione w tabeli


| NAZWA TESTU              | StairTestEins | StairTestZwei | StairTestDrei |
|--------------------------|---------------|---------------|---------------|
| WPROWADZONA WYSOKOŚĆ     | 600           | 2500          | 27000         |
| WPROWADZONA SZERKOŚĆ     | 1200          | 7423          | 18180         |
| CZY MOŻNA WYKONAĆ SCHODY | TAK           | TAK           | NIE           |
| ZWRÓCONA WARTOŚĆ         | TAK           | TAK           | NIE           |
| OCZEKIWANA ILOŚĆ         | 4             | 16            | 0             |
| ZWRÓCONA ILOŚĆ           | 4             | 16            | 0             |
| OCZEKIWANA WYSOKOŚĆ      | 150           | 156           | 0             |
| ZWRÓCONA WYSOKOŚĆ        | 150           | 156           | 0             |
| OCZEKIWANA DŁUGOŚĆ       | 300           | 463           | 0             |
| ZWRÓCONA DŁUGOŚĆ         | 300           | 463           | 0             |
