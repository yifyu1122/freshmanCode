#include<iostream>
using namespace std;

struct Point
{
    float x, y;
};

int main()
{
    Point A[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        cout << "請輸入x座標：";
        cin >> A[i].x;
        cout << "請輸入y座標：";
        cin >> A[i].y;
    }

    cout << "ABC重心座標=("  << (A[0].x + A[1].x + A[2].x) / 3
         << "," << (A[0].y + A[1].y + A[2].y) / 3 << ")";

    return 0;
}

