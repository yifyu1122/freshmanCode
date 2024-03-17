#include<iostream>
using namespace std;


float f(int x) 
{
    if (x == 0) 
	{
        return 1.0;
    } 
	else 
	{
		//f(x)=1*(1/2)*(2/3)*...*(x/(x+1))
        return 1.0 * x / (x + 1) * f(x - 1);
    }
}

int main() {
    int x;

    cout << "½Ğ¿é¤Jxªº­È¡G";
    cin >> x;

    cout << "f(" << x << ") = " << f(x) << endl;

}
