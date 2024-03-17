#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int NUMBER_OF_CARDS = 52;
	int remainingCards[NUMBER_OF_CARDS];
    string suits[] = {"黑桃", "紅心", "梅花", "方塊"};
    string numbers[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
    cout << "請輸入你所需的撲克牌" << endl;

    for (int i = 0; i < NUMBER_OF_CARDS; i++)
        remainingCards[i] = i;

    cout << "請輸入數字: ";
    int n;
    cin >> n;

    cout << "你拿到以下的牌: " << endl;

    // 洗牌.
    srand(time(NULL));
    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        int swap_index = rand() % NUMBER_OF_CARDS;
        swap(remainingCards[i], remainingCards[swap_index]);
    }

    // 拿牌
    for (int i = 0; i < n; i++)
    {
        if (i >= NUMBER_OF_CARDS)
        {
            cout << "牌發完了。" << endl;
            break;
        }

        int c = remainingCards[i];
        int flower = c / 13; // 花色
        int number = c % 13; // 數字

        cout << "  " << suits[flower] << " " << numbers[number] << endl;
    }

    cout << endl;
}

