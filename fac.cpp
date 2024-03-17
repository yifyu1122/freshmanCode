#include<iostream>
using namespace std;

//int Max(int a, int b);
//int Min(int a, int b);
//int fac(int N);
//int Comb(int a, int b);

int Max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int Min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int fac(int N)
{
    int i;
    for (i = N; i > 1; i--)
        N = N * (i - 1);
    return N;
}

int Comb(int a, int b)
{
    return fac(a) / (fac(a - b) * fac(b));
}

int main()
{
    int C, a, b;

//    C = Max(3, 5);
//    cout << C;
//
//    C = Max(13, 5);
//    cout << "\n" << C;
//
//    C = Min(3, 5);
//    cout << "\n" << C;
//
//    C = Min(13, 5);
//    cout << "\n" << C;

    cout << "請輸入a=";
    cin >> a;
    cout << "請輸入b=";
    cin >> b;

    C = Comb(a, b);
    cout << "C" << a << "取" << b << "=" << C;

}


