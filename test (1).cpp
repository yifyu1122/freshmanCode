#include <iostream>
using namespace std;

int f(int &a)
{
	a=10;
	return a;
}    

int main()
{
	int b=1;
	f(b);
	cout << b;
}

