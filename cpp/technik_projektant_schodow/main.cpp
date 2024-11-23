#include <iostream>
#include "Stairs.cpp"

using namespace std;

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
