#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;

    cout << "Please input a." << endl; 
    cin >> a;
    cout << "Please input b."<< endl;
    cin >> b;
    cout << "Please input c."<< endl;
    cin >> c;
    //if c is the biggest
    if(c>a&&c>b)
    {
        d=c;
        c=a;
        a=d;
        //if c is the biggest and b the smallest
        if(c>b)
        {
            d=c;
            c=b;
            b=d;
        }
    }
    //if b is the biggest
    if(b>a&&c<a)
    {
        d=b;
        b=a;
        a=d;

    }

    cout<< "a=" << a << endl; 
    cout<< "b=" << b << endl; 
    cout<< "c=" << c << endl; 
    return 0;
}
