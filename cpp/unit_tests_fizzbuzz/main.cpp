#include <iostream>
#include "functions.cpp"

using namespace std;

int main() {
	srand(time(0));
	int i = (rand() % 100) + 1;
	cout<<i<<endl;
	cout<< fizzBuzz(i)<<endl;
	return 0;
}

