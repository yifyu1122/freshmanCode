#include<iostream>
using namespace std;

int main()
{
    int a, *b;

    cout << "�п�Ja����=";
    cin >> a;

    // �p�G�o��令 *b; �q���|���áC�]�� b ����}�ثe�O�Ū�
    b = &a;

    cout << "�п�Jb����=";
    cin >> *b;

    cout << "a=" << a << " b=" << *b;
    cout << "\na��}=" << &a << " b��}=" << b;

    // printf("a=%d b=%d", a, *b); //*b �N�O�s���}����ƭ�
    // printf("\n�ܼ�a����}=%x �ܼ�b�s�񪺦�}=%x", &a, b);
    // b �N�O���V����ܼƪ����Ӧ�}

    return 0;
}
