#include<iostream>
using namespace std;

/* �]�p�@�Ө禡 void swap_array( int a[ ], int b[ ], int n)�A
�i�洫��ۦP���װ}�C�]��ơ^���ȡA�䤤�Ѽ�n�N��}�C�����סC
�t�~�]�p�D�禡main()�A�i��J��Ӫ��׬�n����ư}�C�A
n�i�q��L��J�A��n<=50�C�çQ�Ϋe�z���禡�洫��ȡA�N�洫�ᵲ�G��X�C*/ 

void swap_array(int a[ ], int b[ ], int n)
{
	for (int i = 0; i < n; i++) 
		swap (a[i],b[i]);
}
int main()
{
	int n;
	
	cout << "�洫��ۦP���װ}�C�]��ơ^����" << endl;
	cout << "�п�J����(����<=50)" << endl;
	cin >> n;
	int array1[n], array2[n];
	if (n<=50)
	{		
		cout << "�п�J�Ĥ@�Ӱ}�C��" << n << "�Ӿ�ơG" << endl;
	    for (int i = 0; i < n; i++)
	        cin >> array1[i];
	
	    cout << "�п�J�ĤG�Ӱ}�C��" << n << "�Ӿ�ơG" << endl;
	    for (int i = 0; i < n; i++) 
	        cin >> array2[i];
	    swap_array(array1, array2, n);
	    
	    cout << "�Ĥ@�Ӱ}�C�G";
	    for(int i=0;i<n;i++)
			cout << array1[i] << " ";
			
		cout << "�ĤG�Ӱ}�C�G";
		for(int i=0;i<n;i++)
			cout << array2[i] << " ";
	}
	else
		cout << "���׻�<=50"; 
}
