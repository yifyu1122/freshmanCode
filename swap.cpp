#include<iostream>
using namespace std;

#define N 6

int main()
{
    int a[N], b, flag = 0, C = 0, t = 0;
    cout << "�п�J6�ӼƦr\n";
    for (int i = 0; i < N; i++)
        cin >> a[i];
    cout << "�A��J���Ʀr�O:\n";

    for (int i = 0; i < N - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < N - i - 1; j++)
        {
            C++;
            if (a[j] > a[j + 1])
            {
                t++;
                flag = 1;
                b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
        cout << endl;
        for (int j = 0; j < N; j++)
            cout << a[j] << " ";
        if (flag == 0)
        {
            break;
        }
    }
    cout << "\n���" << C << "���A�洫" << t << "��";
    return 0;
}
