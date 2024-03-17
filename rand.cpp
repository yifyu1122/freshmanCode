#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	int rand();
	srand(time(NULL));
	for(int i=1;i<20;i++)
	{
		cout << "score: " << rand()%41+60 << endl;
		cout << "dice: " << rand()%6+1 << endl;
		cout << "pokerªá¦â: " << rand()%4 << endl;
		cout << "poker¼Æ¦r: " << rand()%13+1 << endl;
		cout << endl;
	}
}
