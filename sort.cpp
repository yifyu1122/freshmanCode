#include<iostream>
using namespace std;

#define N 6

// Global array initialization
int a[N] = {5, 8, 6, 4, 1, 2};

// Function prototypes
//void bubble(int n);
//void sort(int n);
//void insert(int n);
void bubble(int n)
{
    cout << "\n��w�ƧǪk";
    int i, j, b, t = 0, C = 0, flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            C++;
            if (a[j] > a[j + 1])
            {
                flag = 1;
                b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
                t++;
            }
        }
        cout << "\n";
        for (j = 0; j < n; j++)
            cout << a[j] << " ";
        if (flag == 0)
        {
            break;
        }
    }

    cout << "\n�@���" << C << "���A��" << t << "�� ";
}

void sort(int n)
{
    cout << "\n��ܱƧǪk";
    int i, j, temp, min;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        cout << "\n��" << i + 1 << "���Ƨǫ�:";
        for (j = 0; j < n; j++)
            cout << a[j] << " ";
    }
}

void insert(int n)
{
    cout << "\n���J�ƧǪk";
    int i, j, key;
    for (i = 0; i < n; i++)
    {
        key = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (key < a[j])
            {
                a[j + 1] = a[j];
            }
            else
                break;
        }
        a[j + 1] = key;
        cout << "\n��" << i + 1 << "���Ƨǫ�:";
        for (j = 0; j < n; j++)
            cout << a[j] << " ";
    }
}

int main()
{
    // Commented out the input loop since the array is already initialized
    // for (int i = 0; i < N; i++)
    //     cin >> a[i];

    cout << "��J���Ʀr:\n";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";

    cout << "\n";
    bubble(N);
    cout << "\n";
    sort(N);
    cout << "\n";
    insert(N);

    return 0;
}


