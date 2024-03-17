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
	cout << "假如x為0或1，結果為1" << endl;
	cout << "否則結果為f(x-1)+f(x-2)" << endl;
    cout << "請輸入x的值：";
    cin >> x;

    cout << "f(" << x << ") = " << f(x) << endl;

}
