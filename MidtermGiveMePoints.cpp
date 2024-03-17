#include <iostream>
using namespace std;

int main()
{
	int n,j;
	float sum=0.0;
	cout  <<"Please enter an integer. Then enter the integers according to the integer you entered."<< endl;
	cin >>n;
	if(n>0)
	{
		for(int i=0;i<n;i++)
		{
			cin >>j;
			sum=sum+j;
		}
		cout  << "The sum is " << sum << "." << endl;
		cout  << "The average is " << sum/n << "." << endl;		
	}
	else
	cout  << "WRONG FORMAT!!!" << endl;	
}
