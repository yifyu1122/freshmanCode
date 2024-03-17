#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



int main()
{
	int MAX_CARDS = 10; // 假設最多只會要 10 張牌
    int NUMBER_OF_CARDS = 52;
    int remainingCards[NUMBER_OF_CARDS];
    string suits[] = {"黑桃", "紅心", "梅花", "方塊"};
    string numbers[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    cout << "10點半遊戲開始" << endl;

    for (int i = 0; i < NUMBER_OF_CARDS; i++)
        remainingCards[i] = i;

    // 洗牌
    srand(time(NULL));
    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        int swap_index = rand() % NUMBER_OF_CARDS;
        swap(remainingCards[i], remainingCards[swap_index]);
    }

    // 開始遊戲
    double yourPoints = 0;
    double computerPoints = 0;

    // 存儲每次獲得的牌的信息
    string yourCards[MAX_CARDS];    // 假設最多只會要 10 張牌
    string computerCards[MAX_CARDS]; // 假設最多只會要 10 張牌

    // 你先發一張牌
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

    cout << "玩家你：" << yourCards[0] << " 點數" << yourPoints << " 電腦莊家 X" << endl;

    // 玩家要牌
    char choice;
    int yourCardCount = 1; // 記錄牌的張數

    do
    {
        cout << "是否繼續要牌？是按(y/Y)否按(n/N) ";
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

            cout << "玩家你：";
            for (int i = 0; i < yourCardCount; ++i)
            {
                cout << yourCards[i] << " ";
            }
            cout << "點數" << yourPoints << " 電腦莊家 X" << endl;

            if (yourPoints > 10.5)
            {
                cout << "可惜你輸了" << endl;
                exit(0);
            }
        }
    } while (choice == 'y' || choice == 'Y');

    // 莊家開始要牌
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

    cout << "玩家你：";
    for (int i = 0; i < yourCardCount; ++i)
    {
        cout << yourCards[i] << " ";
    }
    cout << "點數" << yourPoints << " 電腦莊家 ：" << computerCards[0] << " 點數" << computerPoints << endl;

    int computerCardCount = 1; // 記錄牌的張數

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

        cout << "玩家你：";
            for (int i = 0; i < yourCardCount; ++i)
            {
                cout << yourCards[i] << " ";
            }
            cout << "點數" << yourPoints << " 電腦莊家 :";
        for (int i = 0; i < computerCardCount; ++i)
        {
            cout << computerCards[i] << " ";
        }
        cout << "點數" << computerPoints << endl;

        if (computerPoints > 10.5)
        {
            cout << "恭喜你贏了" << endl;
            exit(0);
        }

    } while (computerPoints <= 10.5 && computerPoints <= yourPoints);

    // 判斷勝負
    if (computerPoints > yourPoints)
        cout << "可惜你輸了" << endl;
    else if (computerPoints < yourPoints)
        cout << "恭喜你贏了" << endl;
    else
        cout << "平局，點數相同！" << endl;

    return 0;
}

