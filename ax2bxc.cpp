#include<iostream>
#include<math.h>
using namespace std;
/*�]�p�@�ӵ{���A
�i�Ѥ@���G����{����x^2+Bx+c=0�A
�䤤�ϡA�СA�ѧ�����ơC
�Y�榳��ڡA��Xx�o�ȡG�Yx�L��ڡA
��X"�L��"�C�N�{���s��exam1.cpp�C*/

int main()
{
	int a, b, c, d;
	cout << "�w��Ө�@���G����{��(ax^2+bx+c=0)�Ѯڭp���" << endl;
	cout << "�п�Ja" << endl;
	cin >> a;
	cout << "�п�Jb" << endl;
	cin >> b;
	cout << "�п�Jc" << endl;
	cin >> c;
	cout << "�A��J���{���O" << a << "x^2+" << b << "x+" << c << "=0" << endl;
	d = (b * b) - (4 * a * c);
	if (d == 0)
	{
		cout << "���ڣ�" << endl;
		cout << "x = " <<  (- b + sqrt(d))/ (2 * a); 
	}
	else if (d < 0)
		cout << "�L��";
	else
	{
		cout << "����Ӯ�";
		cout << "x = " <<  (- b + sqrt(d))/ (2 * a) << " or " << (- b - sqrt(d))/ (2 * a); 
	}
		
}
