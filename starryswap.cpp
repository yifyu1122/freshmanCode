#include<iostream>
using namespace std;

void fSwap(int *a)
{
	for(int x=0;x<4;x++)
	{
		for(int x=0;x<4;x++)
		{
			if(*(a+x)>*(a+x+1))
				swap(*(a+x),*(a+x+1));
		}
	}
}

int main()
{
	int a[5];
	for(int i=0;i<5;i++)
	{
		cout << "Please input an integer." << endl;
		cin >> *(a+i);
	}

	fSwap(a);

	for(int i=0;i<5;i++)
	{
		cout << *(a+i) << " ";
	}
	cout << endl;
}
