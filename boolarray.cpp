#include<iostream>
using namespace std;
//檢查陣列是否一致的程式

bool compArray(int a[5], int b[5]) 
{
    for (int i = 0; i < 5; i++) 
        if (a[i] != b[i]) 
            return false;  
    return true; 
}

int main() 
{
    int array1[5], array2[5];

    cout << "請輸入第一個陣列的五個整數：";
    for (int i = 0; i < 5; i++)
        cin >> array1[i];

    cout << "請輸入第二個陣列的五個整數：";
    for (int i = 0; i < 5; i++) 
        cin >> array2[i];

    if (compArray(array1, array2)) 
        cout << "兩個陣列相等。\n";
    else
        cout << "兩個陣列不相等。\n";
    
}
