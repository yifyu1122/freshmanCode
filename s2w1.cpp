#include<iostream>
using namespace std;

int main()
{
	int c = 1,s,n=5;
	int a[10]; //���=>�j�p 
	int *b; //���Ы�����ܼ� ��=>��} 
	b = &c; //&���}�B��l 
	cout << b << endl; //16�i��  c����}
	cout << &c << endl; //c����}
	cout << *b << endl; //1 *�����B��} indirect operator 
	
	
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
