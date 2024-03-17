#include<iostream>
using namespace std;

/* 設計一個函式 void swap_array( int a[ ], int b[ ], int n)，
可交換兩相同長度陣列（整數）的值，其中參數n代表陣列的長度。
另外設計主函式main()，可輸入兩個長度為n的整數陣列，
n可從鍵盤輸入，但n<=50。並利用前述的函式交換其值，將交換後結果輸出。*/ 

void swap_array(int a[ ], int b[ ], int n)
{
	for (int i = 0; i < n; i++) 
		swap (a[i],b[i]);
}
int main()
{
	int n;
	
	cout << "交換兩相同長度陣列（整數）的值" << endl;
	cout << "請輸入長度(長度<=50)" << endl;
	cin >> n;
	int array1[n], array2[n];
	if (n<=50)
	{		
		cout << "請輸入第一個陣列的" << n << "個整數：" << endl;
	    for (int i = 0; i < n; i++)
	        cin >> array1[i];
	
	    cout << "請輸入第二個陣列的" << n << "個整數：" << endl;
	    for (int i = 0; i < n; i++) 
	        cin >> array2[i];
	    swap_array(array1, array2, n);
	    
	    cout << "第一個陣列：";
	    for(int i=0;i<n;i++)
			cout << array1[i] << " ";
			
		cout << "第二個陣列：";
		for(int i=0;i<n;i++)
			cout << array2[i] << " ";
	}
	else
		cout << "長度需<=50"; 
}
