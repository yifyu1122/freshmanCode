#include<iostream>
using namespace std;

int menu(int sel)
{
	cout << "===============���===============" << endl;
	cout << "||\t\t\t\t||"<< endl;
	cout << "||\t1.�s�W���\t\t||"<< endl;
	cout << "||\t2.�d�߸��\t\t||"<< endl;
	cout << "||\t3.�ק���\t\t||"<< endl;
	cout << "||\t0.���}\t\t\t||"<< endl;
	cout << "||\t\t\t\t||"<< endl;
	cout << "=================================="<< endl ;
	cout << "�п�@�ӼƦr"<< endl ;
	cin >> sel; 
	return sel;
}

int main()
{
	int sel;

	while(1)
	{
		sel=menu(sel);
		if(sel==0)
		{
			cout << "�A������}"<< endl ;
			break;
		} 
		else if(sel==1)
			cout << "�A��ܷs�W���"<< endl<< endl  ;
		else if(sel==2)
			cout << "�A��ܬd�߸��"<< endl<< endl  ;
		else if(sel==3)
			cout << "�A��ܭק���"<< endl<< endl  ;
		else
			cout << "��J���~�A����"<< endl<< endl  ;	
	}
}
 
