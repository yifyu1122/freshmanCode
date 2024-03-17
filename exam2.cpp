#include<iostream>
#include <stdlib.h>
#include <time.h>
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

void game1()
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
	}

}


void game2()
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
	else if(computerNumber<yourNumber)
		cout << "YOU WIN!" << endl << endl;
	else if(computerNumber==yourNumber)
	{
		if(computerFlower>yourFlower)
		{
			cout << "YOU WIN!" << endl << endl;
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
	int sel;

	while(1)
	{
		sel=menu(sel);
		if(sel==0)
		{
			cout << "你選擇離開"<< endl ;
			break;
		} 
		else if(sel==1)
			game1();
		else if(sel==2)
			game2();
		else
			cout << "輸入錯誤，重選"<< endl<< endl  ;	
	}
}

/*game2能寫出來真是奇蹟，還好我回家弄撲克牌弄了兩個多禮拜，
把那個10點半的程式生出來，10點半的程式甚至比這個更複雜
我當時看不懂題目就真的上網找網頁遊戲親自對戰 
網路上的範例花好久時間才勉強消化成自己的版本 
我還去翻高中講義複習struct怎麼寫，還好沒考
把程式寫成這樣因為我實在想不到其他方法
我在結尾打這串應該會沒事吧
之後寒假應該會練習寫1A2B抽鬼牌之類的程式
因為聽其他學校的學姐說很簡單
希望我真的能生出來*/ 
