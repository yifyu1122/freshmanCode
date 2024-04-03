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
    string suits[] = {"黑桃", "紅心", "梅花", "方塊"};
    string numbers[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    srand(time(NULL));
    
    //確保順序正確用的 
	for (int i = 0; i < 52; i++)
        remainingCards[i] = i;
    
    // 洗牌=隨機=非常非常公平 
    for (int i = 0; i < 52; i++)
    {
        int swap_index = rand() % 52;
        swap(remainingCards[i], remainingCards[swap_index]);
    }

    // 拿牌=每次呼叫都會刷新 
	int c = remainingCards[0],
		yourFlower = c / 13, // 花色
        yourNumber = c % 13; // 數字
        
        cout << "Your card " << suits[yourFlower] << " " << numbers[yourNumber] << endl; 
 
    
    c = remainingCards[1];
	int	computerFlower = c / 13, // 花色
        computerNumber = c % 13; // 數字
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
			cout << "程式寫錯了，快去修bug" << endl << endl;
	}
	else
			cout << "程式寫錯了，快去修bug" << endl << endl;
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
				cout << "你選擇離開"<< endl ;
				break;	
			case 1:
				game1(m);
				break;	
			case 2:
				game2(m);
				break;	
			default:
				cout << "輸入錯誤，重選"<< endl;
				break;
		}				
	}
}
