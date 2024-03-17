#include <iostream>
using namespace std;

int f(int m, int n)
{
	int s1=1, s2=1 ,s3=1;
	for(int i=1;i<=m;i++)
		s1=s1*i;

	for(int i=1;i<=n;i++)
		s2=s2*i;
		
	for(int i=1;i<=(m-n);i++)
		s3=s3*i;
	
	return s1/s2/s3;
}

int main()
{
	int m, n;
	cout << "歡迎來到Cm取n計算機"<<endl;
	cout << "請輸入m"<<endl;
	cin >> m;
	cout << "請輸入n"<<endl;
	cin >> n;
	if (m>=n && m>0 && n>=0)
		cout << "C" << m << "取" << n << "=" << f(m,n);
	else
		cout <<"WRONG FORMAT!!!";
}
