#include<iostream>
#include<stdlib.h> 
#include<time.h>   
using namespace std;

long long generateRandomNumber() 
{
    long long randomNumber = 0;
    for (int i = 0; i < 15; i++) 
        randomNumber = randomNumber * 10 + rand() % 10;
    return randomNumber;
}

int main() {
    srand(time(NULL));

    long long num1 = generateRandomNumber();
    long long num2 = generateRandomNumber();

    long long sum = num1 + num2;

    cout << "�Ĥ@���H���ơG" << num1 << endl;
    cout << "�ĤG���H���ơG" << num2 << endl;
    cout << "��Ӽƪ��M�G" << sum << endl;

}
