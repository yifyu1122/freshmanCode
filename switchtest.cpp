#include <iostream>
using namespace std;
 
int main ()
{
   int grade;
   cin >> grade;
 
   switch(grade)
   {
   case 90 ... 100 :
    	cout << "�X��" << endl; 
    	break;
   case 80 ... 89 :
   		cout << "���x" << endl;
   		break;
   case 60 ... 79 :
		cout << "��_�@��C" << endl;
    	break;
   
   default :
    	cout << "���aŪ�ѤT�Ӥ�" << endl;
   }
 
   return 0;
}
