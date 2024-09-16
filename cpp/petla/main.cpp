#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ofstream wynik("wynik.txt");

	double number;
	cout<<"Choose one number ";
	cin>>number;
	wynik<<number<<endl;

	while(number>0){
		//number-=0.1;
		if(number<=7.0 || number>=10){
			wynik<<number<<endl;
		}
		number-=0.1;
	}
	wynik.close();
	return 0;
}
