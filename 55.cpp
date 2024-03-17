#include<iostream>
#include<string.h>
using namespace std;

int mymenu(int sel)
{
	cout << "選單" << endl;
	cout << "\t增加學生資料"<< endl;
	cout << "\t查詢學生資料(輸入姓名做查詢)"<< endl;
	cout << "\t顯示班級成績單查詢資料"<< endl;
	cout << "\t離開"<< endl;
	cout << "請選一個數字(1,2,3,4)"<< endl ;
	cin >> sel; 
	return sel;
}
bool compChar(char a[], char b[]) {
	return strcmp(a, b) == 0;
}

int main()
{
	int sel,
		midscore=0,
		finscore=0;
	char name[20],
		 name2[20];
	while(1)
	{
		sel=mymenu(sel);
		if(sel==4)
		{
			cout << "謝謝使用，敬請指教"<< endl ;
			break;
		} 
		else if(sel==1)
		{
			cout << "你選擇新增資料"<< endl<< endl  ;
			cout << "請輸入姓名（長度為20）："<< endl;
			cin.ignore();
		    cin.getline(name, 20);
			cout << "請輸入期中考成績"<< endl;
			cin >> midscore;
			cout << "請輸入期末考成績"<< endl;
			cin >> finscore;	
		} 
			
		else if(sel==2)
		{
			cout << "請輸入姓名（長度為20）："<< endl;
			cin.ignore();
		    cin.getline(name2, 20);
		    if (compChar(name, name2)) 
		    {
		    	cout << "姓名:"<< name2 <<endl ;
		    	cout << "期中成績:"<< midscore <<endl ;
		    	cout << "期末成績:"<< finscore <<endl ;
			}
		        
			else 
		        cout << "查無此人"<< endl  ;
	    }
		else if(sel==3)
			cout << "你選擇修改資料"<< endl<< endl  ;
		else
			cout << "輸入錯誤，重選"<< endl<< endl  ;	
	}
}

