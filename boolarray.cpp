#include<iostream>
using namespace std;
//�ˬd�}�C�O�_�@�P���{��

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

    cout << "�п�J�Ĥ@�Ӱ}�C�����Ӿ�ơG";
    for (int i = 0; i < 5; i++)
        cin >> array1[i];

    cout << "�п�J�ĤG�Ӱ}�C�����Ӿ�ơG";
    for (int i = 0; i < 5; i++) 
        cin >> array2[i];

    if (compArray(array1, array2)) 
        cout << "��Ӱ}�C�۵��C\n";
    else
        cout << "��Ӱ}�C���۵��C\n";
    
}
