#include<iostream>
using namespace std;

int menu(int sel)
{
	cout << "===============選單===============" << endl;
	cout << "||\t\t\t\t||"<< endl;
	cout << "||\t1.新增資料\t\t||"<< endl;
	cout << "||\t2.查詢資料\t\t||"<< endl;
	cout << "||\t3.修改資料\t\t||"<< endl;
	cout << "||\t0.離開\t\t\t||"<< endl;
	cout << "||\t\t\t\t||"<< endl;
	cout << "=================================="<< endl ;
	cout << "請選一個數字"<< endl ;
	cin >> sel; 
	return sel;
}

int main()
{
	int sel;

	while(1)
	{
		sel=menu(sel);
		if(sel==0)
		{
			cout << "你選擇離開"<< endl ;
			break;
		} 
		else if(sel==1)
			cout << "你選擇新增資料"<< endl<< endl  ;
		else if(sel==2)
			cout << "你選擇查詢資料"<< endl<< endl  ;
		else if(sel==3)
			cout << "你選擇修改資料"<< endl<< endl  ;
		else
			cout << "輸入錯誤，重選"<< endl<< endl  ;	
	}
}
 
