#include<iostream>
#include<math.h>
using namespace std;
/*設計一個程式，
可解一元二次方程式Ａx^2+Bx+c=0，
其中Ａ，Ｂ，Ｃ均為整數。
若Ｘ有實根，輸出x得值：若x無實根，
輸出"無解"。將程式存為exam1.cpp。*/

int main()
{
	int a, b, c, d;
	cout << "歡迎來到一元二次方程式(ax^2+bx+c=0)解根計算機" << endl;
	cout << "請輸入a" << endl;
	cin >> a;
	cout << "請輸入b" << endl;
	cin >> b;
	cout << "請輸入c" << endl;
	cin >> c;
	cout << "你輸入的程式是" << a << "x^2+" << b << "x+" << c << "=0" << endl;
	d = (b * b) - (4 * a * c);
	if (d == 0)
	{
		cout << "重根ㄟ" << endl;
		cout << "x = " <<  (- b + sqrt(d))/ (2 * a); 
	}
	else if (d < 0)
		cout << "無解";
	else
	{
		cout << "有兩個根";
		cout << "x = " <<  (- b + sqrt(d))/ (2 * a) << " or " << (- b - sqrt(d))/ (2 * a); 
	}
		
}
