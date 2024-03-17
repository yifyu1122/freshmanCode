#include<iostream>
using namespace std;

int main()
{
	int c = 1,s,n=5;
	int a[10]; //整數=>大小 
	int *b; //指標型整數變數 值=>住址 
	b = &c; //&取址運算子 
	cout << b << endl; //16進位  c的住址
	cout << &c << endl; //c的住址
	cout << *b << endl; //1 *間接運算址 indirect operator 
	
	
	for(int i=0;i<10;i++)
	{
		a[i]=i;
		cout << a[i] << endl;
		*(a+i)=i;
		cout << *(a+i) << endl;
	}
	s=1;
	for(int i=1;i<n+1;i++)
		s=s*i;
}
