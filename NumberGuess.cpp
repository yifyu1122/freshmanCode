#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

void star(int a)
{
	int i,j;
	for(j=1;j<=a-1;j++)
		{
			for(i=1;i<=a-j+1;i++)
			{
				cout << " ";
			}
			for(i=1;i<=j;i++)
			{
				cout << " *";
			}
			cout << "\n";	
		}
		for(j=1;j<=a;j++)
		{
			for(i=1;i<=j;i++)
			{
				cout << " ";
			}
			for(i=1;i<=a-j+1;i++)
			{
				cout << " *";
			}
			cout << "\n";	
		}
}
int err(int a)
{
	if(a<=3)
	{
		cout << "不要亂猜(不要亂猜，亂猜我可是會生氣的)\n\n";
	} 
	else if(a==4) 
	{
		cout << "不是叫你不要再亂猜了嗎\a\n\n";
	} 
	else if(a==5) 
	{
		cout << "我已經警告過你了喔\n再下次我就不給你玩了\a\n\n";
	} 
	else
	{
		exit(0);
	} 
}
void e1(int a)
{
	if(a==3)
	{
		cout << "再加油一下，你可以做到的!\n\n";
	}
	else if(a==6)
	{
		cout << "沒關係，沒關係，有人猜了足足8次才猜中呢\n\n";
	}
	else if(a>8 && a<=10) 
	{
		cout << "你會不會猜得有點久啊，如果是我就直接放棄了\n\n";
	}
}
void e2(int a)
{
	if(a==6)
	{
		cout << "再加油一下，你可以做到的!\n\n";
	}
	else if(a==9||a==12||a==15)
	{
		cout << "沒關係，沒關係，有人足足猜了20次呢\n\n";
	}
	else if(a>20 && a<=40) 
	{
		cout << "要不要退出玩正常模式呢?\n這裡似乎並不適合你\n\n";
	}
}
void e3(int a)
{
	if(a==6||a==9||a==12)
	{
		cout << "再加油一下，你可以做到的!\n\n";
	}
	else if(a==15||a==20||a==25)
	{
		cout << "沒關係，沒關係，魔王模式猜得比較久是正常的\n\n";
	}
	else if(a>30 && a<=60) 
	{
		cout << "要不要退出玩正常模式呢?\n這裡似乎並不適合你\n\n";
	}
}
void hmm(int a)
{
	cout << "猜了"<<a<<"次嗎\n";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".\n";
	Sleep(1000);
	cout << "呃... 還算可以啦\n";
}
int main() 
{
	int Ans,Guess,Min=0,Max=100,count=0,error,ans,max=1000,S,ANS,MAX=10000;
	char s[20];
	srand(time(NULL));
	Ans=rand()%101;	
	ans=rand()%1001;	
	ANS=rand()%10001;
	cout << "請輸入玩家暱稱：\n";
	cin >> s;	
	cout << "歡迎"<<s<<"遊玩終極密碼\n";	
	cout << "\n=================終極密碼=================\n";
	cout << "||\t\t\t\t\t||\n";
	cout << "||\t\t1.正常模式\t\t||\n";
	cout << "||\t\t2.困難模式\t\t||\n";
	cout << "||\t\t3.魔王模式\t\t||\n";
	cout << "||\t\t4.退出遊戲\t\t||\n";
	cout << "||\t\t\t\t\t||\n";
	cout << "==========================================\n";
	cout << "請輸入你的選擇：";
	cin >> S;
	cout << "\n";	
	if(S==1)
	{
		while(1) 
		{
			cout << Min << " ~ " << Max << "猜一個數字\n\n";			
			cin >> Guess;			
			count++;
			if(Guess>=Min && Guess<=Max)
			{			
				if(Guess==Ans) 
				{
					cout << "Bingo!\n\n";
				    if(count<=5)
				    {
				    	cout << "總共猜了" << count << "次，真的是超級厲害的!\n";
						star(3);
						break;
					}
					else if(count>=6 && count<=9)
					{
						hmm(count);
						break;
					}						
					else
					{
						cout << "猜了" << count << "次，怎麼那麼久啊，我都已經猜完兩輪了。\n";
						break;
					}		
				} 
				else if(Guess>Ans) 
				{
					Max=Guess;
					e1(count);
				}
				else 
				{
					Min=Guess;
					e1(count);
				}					
			}
			else
			{
				error++;
				err(error);
			}					
		}
	system("PAUSE");
	} 	
	else if(S==2)
	{
		while(1) 
		{
			cout << Min << " ~ " << max << "猜一個數字\n\n";			
			cin >> Guess;			
			count++;
			if(Guess>=Min && Guess<=max)
			{	
				if(Guess==ans) 
				{
					cout << "Bingo!\n\n";
				    	if(count<=10)
					{
						cout << "總共猜了" << count << "次，真厲害\n";
						star(5);
						break;	
					}
					else if(count>=10 && count<=30)
					{
						hmm(count);
						break;
					}
					else
					{
						cout << "猜了" << count << "次，沒有放棄的你還真是令我佩服呢\n";
						break;
					}							
				} 
				else if(Guess>ans) 
				{
					max=Guess;
					e2(count);
				} 
				else 
				{
					Min=Guess;
					e2(count);
				}					
			}
			else
			{
				error++;
				err(error);
			}				
		}
	system("PAUSE");
	}	
	else if(S==3)
	{
		while(1) 
		{
			cout << Min << " ~ " << MAX << "猜一個數字\n\n";			
			cin >> Guess;			
			count++;
			if(Guess>=Min && Guess<=MAX)
			{			
				if(Guess==ANS) 
				{
					cout << "Bingo!\n\n";
				    	if(count<=10)
					{
						cout << "總共猜了" << count << "次，你是怎麼做到的，也太厲害了吧!\n果然是終極密碼大師\n\n";
						star(10);
						break;	
					}
					else if(count>=10 && count<=30)
					{
						hmm(count);
						break;
					}
					else
					{
						cout << "猜了" << count << "次，沒有放棄的你還真是令我佩服呢\n\n";
						break;
					}							
				} 
				else if(Guess>ANS) 
				{
					MAX=Guess;
					e3(count);
				} 
				else 
				{
					Min=Guess;
					e3(count);
				}					
			}
			else
			{
				error++;
				err(error);
			}				
		}
	system("PAUSE");
	}
	else if(S==4)
	{
		cout << "感謝你的遊玩!";	
	}	
	else
		cout << "沒有" << S << "的選項，BYE BYE！！";
	return 0;
}
