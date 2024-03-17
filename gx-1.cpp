#include<iostream>
using namespace std;

/*設計一個遞迴函式g(x)＝1+2+3+…+(x-1)+x，x為正整數。
另外設計主函式main()，可輸入x得值，
並呼叫函式g(x)，將計算結果輸出。*/

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
	cout << "遞迴函式g(x)＝1+2+3+…+(x-1)+x計算機" << endl;
	cout << "請輸入x" << endl;
	cin >> x; 
	if (x<1)
		cout << "不符格式";
	else
		cout << "g(" << x << ")=" << g(x);  
}
