#include<iostream>
#include<string.h>
using namespace std;

int mymenu(int sel)
{
	cout << "���" << endl;
	cout << "\t�W�[�ǥ͸��"<< endl;
	cout << "\t�d�߾ǥ͸��(��J�m�W���d��)"<< endl;
	cout << "\t��ܯZ�Ŧ��Z��d�߸��"<< endl;
	cout << "\t���}"<< endl;
	cout << "�п�@�ӼƦr(1,2,3,4)"<< endl ;
	cin >> sel; 
	return sel;
}
bool compChar(char a[], char b[]) {
	return strcmp(a, b) == 0;
}

int main()
{
	int sel,
		midscore=0,
		finscore=0;
	char name[20],
		 name2[20];
	while(1)
	{
		sel=mymenu(sel);
		if(sel==4)
		{
			cout << "���¨ϥΡA�q�Ы���"<< endl ;
			break;
		} 
		else if(sel==1)
		{
			cout << "�A��ܷs�W���"<< endl<< endl  ;
			cout << "�п�J�m�W�]���׬�20�^�G"<< endl;
			cin.ignore();
		    cin.getline(name, 20);
			cout << "�п�J�����Ҧ��Z"<< endl;
			cin >> midscore;
			cout << "�п�J�����Ҧ��Z"<< endl;
			cin >> finscore;	
		} 
			
		else if(sel==2)
		{
			cout << "�п�J�m�W�]���׬�20�^�G"<< endl;
			cin.ignore();
		    cin.getline(name2, 20);
		    if (compChar(name, name2)) 
		    {
		    	cout << "�m�W:"<< name2 <<endl ;
		    	cout << "�������Z:"<< midscore <<endl ;
		    	cout << "�������Z:"<< finscore <<endl ;
			}
		        
			else 
		        cout << "�d�L���H"<< endl  ;
	    }
		else if(sel==3)
			cout << "�A��ܭק���"<< endl<< endl  ;
		else
			cout << "��J���~�A����"<< endl<< endl  ;	
	}
}

