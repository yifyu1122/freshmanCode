#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d ,t;

    cout << "Please input a." << endl; 
    cin >> a;
    cout << "Please input b."<< endl;
    cin >> b;
    cout << "Please input c."<< endl;
    cin >> c;
    cout << "Please input d."<< endl;
    cin >> d;
    
    for(int i=0;i<=4;i++)
    {
    	if(a<b)
	    {
	        t=b;
	        b=a;
	        a=t;
	    }
	    if(b<c)
	    {
	        t=b;
	        b=c;
	        c=t;
	    }
	    if(c<d)
	    {
	        t=d;
	        d=c;
	        c=t;
	    }
	}
   

    cout<< "a=" << a << endl; 
    cout<< "b=" << b << endl; 
    cout<< "c=" << c << endl; 
    cout<< "d=" << d << endl; 
    
}
