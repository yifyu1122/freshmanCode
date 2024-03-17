#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



int main()
{
	int MAX_CARDS = 10; // ���]�̦h�u�|�n 10 �i�P
    int NUMBER_OF_CARDS = 52;
    int remainingCards[NUMBER_OF_CARDS];
    string suits[] = {"�®�", "����", "����", "���"};
    string numbers[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    cout << "10�I�b�C���}�l" << endl;

    for (int i = 0; i < NUMBER_OF_CARDS; i++)
        remainingCards[i] = i;

    // �~�P
    srand(time(NULL));
    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        int swap_index = rand() % NUMBER_OF_CARDS;
        swap(remainingCards[i], remainingCards[swap_index]);
    }

    // �}�l�C��
    double yourPoints = 0;
    double computerPoints = 0;

    // �s�x�C����o���P���H��
    string yourCards[MAX_CARDS];    // ���]�̦h�u�|�n 10 �i�P
    string computerCards[MAX_CARDS]; // ���]�̦h�u�|�n 10 �i�P

    // �A���o�@�i�P
    int cardIndex = 0;
    int yourCard = remainingCards[cardIndex++];
    int yourFlower = yourCard / 13;
    int yourNumber = yourCard % 13;

    if (yourNumber == 0)
        yourPoints += 1; // Ace is 1 in this case
    else if (yourNumber >= 1 && yourNumber <= 9)
        yourPoints += yourNumber + 1; // Increment by 1 for numbers 2 to 10
    else
        yourPoints += 0.5; // For J, Q, K

    yourCards[0] = suits[yourFlower] + " " + numbers[yourNumber];

    cout << "���a�A�G" << yourCards[0] << " �I��" << yourPoints << " �q�����a X" << endl;

    // ���a�n�P
    char choice;
    int yourCardCount = 1; // �O���P���i��

    do
    {
        cout << "�O�_�~��n�P�H�O��(y/Y)�_��(n/N) ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            int nextCard = remainingCards[cardIndex++];
            int nextFlower = nextCard / 13;
            int nextNumber = nextCard % 13;

            if (nextNumber == 0)
                yourPoints += 1; // Ace is 1 in this case
            else if (nextNumber >= 1 && nextNumber <= 9)
                yourPoints += nextNumber + 1; // Increment by 1 for numbers 2 to 10
            else
                yourPoints += 0.5; // For J, Q, K

            yourCards[yourCardCount++] = suits[nextFlower] + " " + numbers[nextNumber];

            cout << "���a�A�G";
            for (int i = 0; i < yourCardCount; ++i)
            {
                cout << yourCards[i] << " ";
            }
            cout << "�I��" << yourPoints << " �q�����a X" << endl;

            if (yourPoints > 10.5)
            {
                cout << "�i���A��F" << endl;
                exit(0);
            }
        }
    } while (choice == 'y' || choice == 'Y');

    // ���a�}�l�n�P
    int computerCard = remainingCards[cardIndex++];
    int computerFlower = computerCard / 13;
    int computerNumber = computerCard % 13;
    if (computerNumber == 0)
        computerPoints += 1; // Ace is 1 in this case
    else if (computerNumber >= 1 && computerNumber <= 9)
        computerPoints += computerNumber + 1; // Increment by 1 for numbers 2 to 10
    else
        computerPoints += 0.5; // For J, Q, K

    computerCards[0] = suits[computerFlower] + " " + numbers[computerNumber];

    cout << "���a�A�G";
    for (int i = 0; i < yourCardCount; ++i)
    {
        cout << yourCards[i] << " ";
    }
    cout << "�I��" << yourPoints << " �q�����a �G" << computerCards[0] << " �I��" << computerPoints << endl;

    int computerCardCount = 1; // �O���P���i��

    do
    {
        int computerCard = remainingCards[cardIndex++];
        int computerFlower = computerCard / 13;
        int computerNumber = computerCard % 13;

        if (computerNumber == 0)
            computerPoints += 1; // Ace is 1 in this case
        else if (computerNumber >= 1 && computerNumber <= 9)
            computerPoints += computerNumber + 1; // Increment by 1 for numbers 2 to 10
        else
            computerPoints += 0.5; // For J, Q, K

        computerCards[computerCardCount++] = suits[computerFlower] + " " + numbers[computerNumber];

        cout << "���a�A�G";
            for (int i = 0; i < yourCardCount; ++i)
            {
                cout << yourCards[i] << " ";
            }
            cout << "�I��" << yourPoints << " �q�����a :";
        for (int i = 0; i < computerCardCount; ++i)
        {
            cout << computerCards[i] << " ";
        }
        cout << "�I��" << computerPoints << endl;

        if (computerPoints > 10.5)
        {
            cout << "���ߧAĹ�F" << endl;
            exit(0);
        }

    } while (computerPoints <= 10.5 && computerPoints <= yourPoints);

    // �P�_�ӭt
    if (computerPoints > yourPoints)
        cout << "�i���A��F" << endl;
    else if (computerPoints < yourPoints)
        cout << "���ߧAĹ�F" << endl;
    else
        cout << "�����A�I�ƬۦP�I" << endl;

    return 0;
}

