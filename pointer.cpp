#include<iostream>
using namespace std;

int main()
{
    int a, *b;

    cout << "請輸入a的值=";
    cin >> a;

    // 如果這行改成 *b; 電腦會錯亂。因為 b 的位址目前是空的
    b = &a;

    cout << "請輸入b的值=";
    cin >> *b;

    cout << "a=" << a << " b=" << *b;
    cout << "\na位址=" << &a << " b位址=" << b;

    // printf("a=%d b=%d", a, *b); //*b 就是存放位址的整數值
    // printf("\n變數a的位址=%x 變數b存放的位址=%x", &a, b);
    // b 就是指向整數變數的那個位址

    return 0;
}
