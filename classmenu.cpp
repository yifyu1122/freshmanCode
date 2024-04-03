#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<cstring>
using namespace std;

class MENU{
	private:
		int select;
		int score;
	public:
		void show(){
		   cout << "Score: "<< score <<endl;
			cout << "============================" << endl;
			cout << "||   Menu for Simulation  ||" << endl;
			cout << "||   1. Game 1            ||"<< endl;
			cout << "||   2. Game 2            ||"<< endl; 
			cout << "||   0. Exit              ||"<< endl;
			cout << "||   Please Select One    ||"<< endl ;
			cout << "============================" << endl;
		}
		void sel(){
			cin >> select;
		}
		int showSelect(){
			return select;
		}
		void storeScore(int a){
			if(a==0){
				score++;
			}
			else if(a==1){
				score += 2;
			}
		}
		MENU(){
			select = 1;
			score = 0;
		}
};



void game1(MENU &m)
{
	int computer=0,player=0;
	srand(time(NULL));
	
	computer=rand()%6+1;
	player=rand()%6+1;
	
	if(computer==player)
	{
		cout << "Computer rolls " << computer << endl;
		cout << "You roll " << player << endl;
		cout << "EVEN!" << endl << endl;
		m.storeScore(0);
	}
	else if(computer>player)
	{
		cout << "Computer rolls " << computer << endl;
		cout << "You roll " << player << endl;
		cout << "YOU LOSE!" << endl << endl;
	}
	else if(computer<player)
	{
		cout << "Computer rolls " << computer << endl;
		cout << "You roll " << player << endl;
		cout << "YOU WIN!" << endl << endl;
		m.storeScore(1);
	}

}


void game2(MENU &m)
{
	int remainingCards[52];
    string suits[] = {"�®�", "����", "����", "���"};
    string numbers[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    srand(time(NULL));
    
    //�T�O���ǥ��T�Ϊ� 
	for (int i = 0; i < 52; i++)
        remainingCards[i] = i;
    
    // �~�P=�H��=�D�`�D�`���� 
    for (int i = 0; i < 52; i++)
    {
        int swap_index = rand() % 52;
        swap(remainingCards[i], remainingCards[swap_index]);
    }

    // ���P=�C���I�s���|��s 
	int c = remainingCards[0],
		yourFlower = c / 13, // ���
        yourNumber = c % 13; // �Ʀr
        
        cout << "Your card " << suits[yourFlower] << " " << numbers[yourNumber] << endl; 
 
    
    c = remainingCards[1];
	int	computerFlower = c / 13, // ���
        computerNumber = c % 13; // �Ʀr
    cout << "Computer card "  << suits[computerFlower] << " " << numbers[computerNumber] << endl; 
    
    if(computerNumber>yourNumber)
    	cout << "YOU LOSE!" << endl << endl;
	else if(computerNumber<yourNumber){
		cout << "YOU WIN!" << endl << endl;
		m.storeScore(1);
	}
		
	else if(computerNumber==yourNumber)
	{
		if(computerFlower>yourFlower)
		{
			cout << "YOU WIN!" << endl << endl;
			m.storeScore(1);
		}
		else if(computerFlower<yourFlower)
		{
			cout << "YOU LOSE!" << endl << endl;
		}
		else
			cout << "�{���g���F�A�֥h��bug" << endl << endl;
	}
	else
			cout << "�{���g���F�A�֥h��bug" << endl << endl;
}

int main()
{
	MENU m;
	int sel;

	while(m.showSelect())
	{
		m.show();
		m.sel();
		sel=m.showSelect();
		switch(m.showSelect()){
			case 0:
				cout << "�A������}"<< endl ;
				break;	
			case 1:
				game1(m);
				break;	
			case 2:
				game2(m);
				break;	
			default:
				cout << "��J���~�A����"<< endl;
				break;
		}				
	}
}
