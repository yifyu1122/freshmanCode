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
			cout << "�{���g���F�A�֥h��bug" << endl << endl;
	}
	else
			cout << "�{���g���F�A�֥h��bug" << endl << endl;
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
			game1();
		else if(sel==2)
			game2();
		else
			cout << "��J���~�A����"<< endl<< endl  ;	
	}
}

/*game2��g�X�ӯu�O�_�ݡA�٦n�ڦ^�a�˼��J�P�ˤF��Ӧh§���A
�⨺��10�I�b���{���ͥX�ӡA10�I�b���{���Ʀܤ�o�ӧ����
�ڷ�ɬݤ����D�شN�u���W��������C���˦۹�� 
�����W���d�Ҫ�n�[�ɶ��~�j�j���Ʀ��ۤv������ 
���٥h½�������q�Ʋ�struct���g�A�٦n�S��
��{���g���o�˦]���ڹ�b�Q�����L��k
�ڦb�������o�����ӷ|�S�Ƨa
����H�����ӷ|�m�߼g1A2B�Ⱝ�P�������{��
�]��ť��L�Ǯժ��ǩj����²��
�Ʊ�گu����ͥX��*/ 
