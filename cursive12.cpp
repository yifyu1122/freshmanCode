#include<iostream>
using namespace std;


int f(int x) 
{
    if (x == 0 || x == 1) 
        return 1;
	else 
        return f(x - 1) + f(x - 2);
}

int main() {
    int x;
	cout << "���px��0��1�A���G��1" << endl;
	cout << "�_�h���G��f(x-1)+f(x-2)" << endl;
    cout << "�п�Jx���ȡG";
    cin >> x;

    cout << "f(" << x << ") = " << f(x) << endl;

}
