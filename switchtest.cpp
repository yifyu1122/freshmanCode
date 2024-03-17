#include <iostream>
using namespace std;
 
int main ()
{
   int grade;
   cin >> grade;
 
   switch(grade)
   {
   case 90 ... 100 :
    	cout << "出國" << endl; 
    	break;
   case 80 ... 89 :
   		cout << "環台" << endl;
   		break;
   case 60 ... 79 :
		cout << "國北一日遊" << endl;
    	break;
   
   default :
    	cout << "掃地讀書三個月" << endl;
   }
 
   return 0;
}
