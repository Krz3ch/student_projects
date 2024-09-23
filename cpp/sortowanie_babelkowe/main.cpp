#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> tab = {3, 2, 5, 4, 3, 6, 1, 2, 5, 2, 1, 45, 12, 3, 1, 12, 2, 3 ,1};

	//cout<<sizeof(tab)/sizeof(int);

	int n;

	for(int i = 0; i<tab.size(); i++)
	{
		cout<<tab[i]<<", ";
	}

	cout<<"\n";
	for(int i = 0; i<tab.size(); i++)
	{
		for(int j = 0; j<(tab.size() - 1); j++)
		{
			if(tab[j] > tab[j+1])
			{
				n = tab[i];
				tab[i] = tab[j];
				tab[j] = n;
			}
		}
	}

	for(int i = 0; i<tab.size(); i++)
	{
		cout<<tab[i]<<", ";
	}

	return 0;
}
