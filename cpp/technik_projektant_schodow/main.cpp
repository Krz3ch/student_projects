#include <iostream>
#include "Stairs.cpp"

using namespace std;

int main(){
	int uX, uY;

	cout<<"Podaj wysokosc klatki: "; cin>>uY;
	cout<<"Podaj szerokosc klatki: "; cin>>uX;

	Stairs stairs = makeStairs(uY, uX);

	if(stairs.canBeMade == true){
		cout<<stairs.stepCount<<", "<<stairs.stepHeight<<", "<<stairs.stepLength<<endl;
	}else{
		cout<<"Stairs cannot be made"<<endl;
	}
	return 0;
}
