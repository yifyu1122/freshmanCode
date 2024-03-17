#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	float count1=0,count2=0,count3=0,count4=0,count5=0,count6=0;
	srand(time(NULL));
	for(int i=0;i<1000;i++)
	{
		int j;
		j=rand()%6+1;
		cout << "dice: " << j << endl;
        if (j==1)
        {
        	count1++;
        }
        else if(j==2)
        {
        	count2++;
		}
		else if(j==3)
        {
        	count3++;
		}
		else if(j==4)
        {
        	count4++;
		}
		else if(j==5)
        {
        	count5++;
		}
		else if(j==6)
        {
        	count6++;
		}
	}
	cout << "1: " << count1/1000 << endl;
	cout << "2: " << count2/1000 << endl;
	cout << "3: " << count3/1000 << endl;
	cout << "4: " << count4/1000 << endl;
	cout << "5: " << count5/1000 << endl;
	cout << "6: " << count6/1000 << endl;
}
