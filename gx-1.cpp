#include<iostream>
using namespace std;

/*�]�p�@�ӻ��j�禡g(x)��1+2+3+�K+(x-1)+x�Ax������ơC
�t�~�]�p�D�禡main()�A�i��Jx�o�ȡA
�éI�s�禡g(x)�A�N�p�⵲�G��X�C*/

int g(int x)
{
	if(x==1)
		return 1;
	else
		return g(x-1) + x;
}
 
int main()
{
	int x;
	cout << "���j�禡g(x)��1+2+3+�K+(x-1)+x�p���" << endl;
	cout << "�п�Jx" << endl;
	cin >> x; 
	if (x<1)
		cout << "���Ů榡";
	else
		cout << "g(" << x << ")=" << g(x);  
}
