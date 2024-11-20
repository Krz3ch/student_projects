#include <iostream>
#include "Stairs.cpp"

using namespace std;

int main(){
	
	Stairs stairs = makeStairs(25000, 6000);

	cout<<stairs.stepCount<<", "<<stairs.stepHeight<<", "<<stairs.stepLength;
	return 0;
}
