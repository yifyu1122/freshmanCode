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
    cout << "�п�J�Ĥ@�Ӧr��]���׬�20�^�G";
    cin.getline(str1, 20);

    cout << "�п�J�ĤG�Ӧr��]���׬�20�^�G";
    cin.getline(str2, 20);

    // Output the original strings
    cout << "�洫�e���r��1�G" << str1 << endl;
    cout << "�洫�e���r��2�G" << str2 << endl;

    // Call the swap_array function to swap the values
    swap_array(str1, str2);

    // Output the swapped strings
    cout << "�洫�᪺�r��1�G" << str1 << endl;
    cout << "�洫�᪺�r��2�G" << str2 << endl;
}
