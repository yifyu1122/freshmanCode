#include<iostream>
#include<string.h> // For strcpy function
using namespace std;

// Function to swap the values of two character arrays
void swap_array(char a[], char b[]) 
{
    char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int main() 
{
    char str1[20], str2[20];

    // Input two strings
    cout << "請輸入第一個字串（長度為20）：";
    cin.getline(str1, 20);

    cout << "請輸入第二個字串（長度為20）：";
    cin.getline(str2, 20);

    // Output the original strings
    cout << "交換前的字串1：" << str1 << endl;
    cout << "交換前的字串2：" << str2 << endl;

    // Call the swap_array function to swap the values
    swap_array(str1, str2);

    // Output the swapped strings
    cout << "交換後的字串1：" << str1 << endl;
    cout << "交換後的字串2：" << str2 << endl;
}
