#include <iostream>
using namespace std;

int f(int n)
{
	int s=1;
	for(int i=1;i<=n;i++)
		s=s*i;
	return s;
	//���h -> fast
}
int ff(int n)
{
	if(n>1)
		return(n*f(n-1));
	else
		return 1;
	//���j�禡 Recursive function -> slow
}


int main()
{
	int n;
	cout << "�п�J���h��"<<endl;
	cin >> n;
	cout << n << "!=" << f(n);
}
