#include<iostream>
using namespace std;

int menu(int sel)
{
	cout << "   Menu for Simulation" << endl;
	cout << "1. Game 1"<< endl;
	cout << "2. Game 2"<< endl;
	cout << "0. Exit"<< endl;
	cout << "   Please Select one"<< endl ;
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
			cout << "Game 1 ���椤"<< endl<< endl  ;
		else if(sel==2)
			cout << "Game 2 ���椤"<< endl<< endl  ;
		else
			cout << "��J���~�A����"<< endl<< endl  ;	
	}
}
