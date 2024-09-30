#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<float>& vec)
	{
		int n;

		cout<<"\n";

		for(int i = 0; i<vec.size(); i++)
		{
			for(int j = 0; j<(vec.size() - 1); j++)
			{
				if(vec[j] > vec[j+1])
				{
					n = vec[j+1];
					vec[j+1] = vec[j];
					vec[j] = n;
				}
			}
		}
	}


void printOut(vector<float>& vec)
	{
		for(int i = 0; i<vec.size(); i++)
		{
			cout<<vec[i]<<", ";
		}

	}

int main(){
	int l;
	cout<<"Podaj ilosc liczb w wektorze jaka chcesz wpisac: ";
	cin>>l;

	cout<<"Podaj po kolei liczby jakie ma zawierac twoj wektor:"<<endl;

	float temp;

	vector<float> vec;
	for(int i = 0; i<l; i++)
	{
		cin>>temp;
		vec.push_back(temp);
	}

	//vector<int> tab = {3, 2, 5, 4, 3, 6, 1, 2, 5, 2, 1, 45, 12, 3, 1, 12, 2, 3 ,1};

	//cout<<sizeof(tab)/sizeof(int);
	cout<<"Nieposortowana tablica: ";

	printOut(vec);

	bubbleSort(vec);

	cout<<"Posortowana tablica: ";

	printOut(vec);
	return 0;
}
