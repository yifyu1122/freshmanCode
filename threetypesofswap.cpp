#include <iostream>
using namespace std;

void ex1(int a, int b)
{
	int t;
	t=a;
	a=b;
	b=t;
	//called/passing by value
}
void ex2(int &a, int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
	//called/passing by reference
}
void ex3(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
	//called/passing by address
}

int main()
{
	int x,y;
	x=0;
	y=1;
	for(int i=0;i<10;i++)
	{
		ex3(&x,&y);
		cout << x<<" "<<y<<endl;
	}
	
}
