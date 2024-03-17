#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int NUMBER_OF_CARDS = 52;
	int remainingCards[NUMBER_OF_CARDS];
    string suits[] = {"�®�", "����", "����", "���"};
    string numbers[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
    cout << "�п�J�A�һݪ����J�P" << endl;

    for (int i = 0; i < NUMBER_OF_CARDS; i++)
        remainingCards[i] = i;

    cout << "�п�J�Ʀr: ";
    int n;
    cin >> n;

    cout << "�A����H�U���P: " << endl;

    // �~�P.
    srand(time(NULL));
    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        int swap_index = rand() % NUMBER_OF_CARDS;
        swap(remainingCards[i], remainingCards[swap_index]);
    }

    // ���P
    for (int i = 0; i < n; i++)
    {
        if (i >= NUMBER_OF_CARDS)
        {
            cout << "�P�o���F�C" << endl;
            break;
        }

        int c = remainingCards[i];
        int flower = c / 13; // ���
        int number = c % 13; // �Ʀr

        cout << "  " << suits[flower] << " " << numbers[number] << endl;
    }

    cout << endl;
}

