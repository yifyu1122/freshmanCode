#include<iostream>
using namespace std;

void exchange(int &x, int &y,int &z)
{
    if(x<y)
    {
        int t = x;
  		x = y;
  		y = t;
    }
    if(y<z)
    {
        int t = y;
  		y = z;
  		z = t;
    }
    if(x<y)
    {
        int t = x;
  		x = y;
  		y = t;
    }
}
//int &x: x is a reference to an integer. 

int main()
{
	int a, b, c;
    cout << "Please input a." << endl; 
    cin >> a;
    cout << "Please input b."<< endl;
    cin >> b;
    cout << "Please input c."<< endl;
    cin >> c;

    exchange(a, b, c);

    cout<< "a=" << a << endl; 
    cout<< "b=" << b << endl; 
    cout<< "c=" << c << endl; 
}

