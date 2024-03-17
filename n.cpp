#include<iostream>
using namespace std;

int main()
{
	int n,flag=49;
	int carry=0;
	int a[50]={0};
	cout << "n¶¥¼h¼Æ¡G" << endl;
	cin >> n;
	a[0]=1;
	for(int i = 1; i <= n; i++)
	{                                                   
		for(int j = 0; j < 50; j++)
		{	
			a[j]=a[j]*i+carry;
			carry=a[j]/10;
			a[j]=a[j]%10;		
		}		
	}
	for (int i = 49; i >= 0; i--)
		if(a[i]!=0) 
		{
			flag=i; 
			break;
		}	
		
	for (int i = flag; i >= 0; i--)
		cout << a[i];  
}
