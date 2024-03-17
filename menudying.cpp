#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

// 學生結構
struct Student 
{
    string name;
    int midtermScore;
    int finalScore;
};

// 計算總成績的函式
double calculateTotalScore(int midterm, int final) 
{
	return midterm * 0.4 + final * 0.6;
}
    

// 新增學生資料的函式
void addStudent(Student* students, int &count) 
{
    if (count < 100) 
	{  // 假設最多只有100位學生
        cout << "請輸入學生姓名： ";
        cin >> students[count].name;
        cout << "請輸入期中考成績： ";
        cin >> students[count].midtermScore;
        cout << "請輸入期末考成績： ";
        cin >> students[count].finalScore;
        count++;
    } 
	else 
        cout << "學生資料已滿，無法新增更多學生。" << endl;
}

// 查詢學生資料的函式
void searchStudent(const Student* students, int count) 
{
    string searchName;
    cout << "請輸入欲查詢的學生姓名： ";
    cin >> searchName;

    for (int i = 0; i < count; i++) 
	{
        if (students[i].name == searchName) 
		{
            cout << "學生姓名: " << students[i].name << endl;
            cout << "期中考成績: " << students[i].midtermScore << endl;
            cout << "期末考成績: " << students[i].finalScore << endl;
            cout << "總成績: " << calculateTotalScore(students[i].midtermScore, students[i].finalScore) << endl;
        }
    }
    cout << "查無此人" << endl;
}

// 顯示班級成績單的函式
// 顯示班級成績單的函式
void displayClassReport(Student* students, int count) 
{
    // 冒泡排序，按總成績從高至低排序
    for (int i = 0; i < count - 1; i++) 
	{
        for (int j = 0; j < count - i - 1; j++) 
		{
            if (calculateTotalScore(students[j].midtermScore, students[j].finalScore) <
                calculateTotalScore(students[j + 1].midtermScore, students[j + 1].finalScore)) 
                swap(students[j], students[j + 1]);
        }
    }

    cout << "班級成績單：" << endl;
    cout << "姓名 期中成績 期末成績 總成績" << endl;
    for (int i = 0; i < count; i++) 
	{
        cout << students[i].name << "\t" << students[i].midtermScore << "\t" << students[i].finalScore << "\t"
             << calculateTotalScore(students[i].midtermScore, students[i].finalScore) << endl;
    }
}
int mymenu(int choice)
{
	cout << "選單" << endl;
	cout << "\t增加學生資料"<< endl;
	cout << "\t查詢學生資料(輸入姓名做查詢)"<< endl;
	cout << "\t顯示班級成績單查詢資料"<< endl;
	cout << "\t離開"<< endl;
	cout << "請選一個數字(1,2,3,4)"<< endl ;
	cin >> choice; 
	return choice;
}
int main() 
{
    Student students[100];  // 假設最多只有100位學生
    int count = 0,
		choice;

    while (true) 
	{
		choice=mymenu(choice);
        switch (choice) 
		{
            case 1:
                addStudent(students, count);
                break;
            case 2:
                searchStudent(students, count);
                break;
            case 3:
                displayClassReport(students, count);
                break;
            case 4:
                cout << "謝謝使用，敬請指教！" << endl;
                return 0;
            default:
                cout << "輸入無效，請重新輸入。" << endl;
        }
    }
}

