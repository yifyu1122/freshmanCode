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
		cout << "���n�òq(���n�òq�A�òq�ڥi�O�|�ͮ�)\n\n";
	} 
	else if(a==4) 
	{
		cout << "���O�s�A���n�A�òq�F��\a\n\n";
	} 
	else if(a==5) 
	{
		cout << "�ڤw�gĵ�i�L�A�F��\n�A�U���ڴN�����A���F\a\n\n";
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
		cout << "�A�[�o�@�U�A�A�i�H���쪺!\n\n";
	}
	else if(a==6)
	{
		cout << "�S���Y�A�S���Y�A���H�q�F����8���~�q���O\n\n";
	}
	else if(a>8 && a<=10) 
	{
		cout << "�A�|���|�q�o���I�[�ڡA�p�G�O�ڴN�������F\n\n";
	}
}
void e2(int a)
{
	if(a==6)
	{
		cout << "�A�[�o�@�U�A�A�i�H���쪺!\n\n";
	}
	else if(a==9||a==12||a==15)
	{
		cout << "�S���Y�A�S���Y�A���H�����q�F20���O\n\n";
	}
	else if(a>20 && a<=40) 
	{
		cout << "�n���n�h�X�����`�Ҧ��O?\n�o�̦��G�ä��A�X�A\n\n";
	}
}
void e3(int a)
{
	if(a==6||a==9||a==12)
	{
		cout << "�A�[�o�@�U�A�A�i�H���쪺!\n\n";
	}
	else if(a==15||a==20||a==25)
	{
		cout << "�S���Y�A�S���Y�A�]���Ҧ��q�o����[�O���`��\n\n";
	}
	else if(a>30 && a<=60) 
	{
		cout << "�n���n�h�X�����`�Ҧ��O?\n�o�̦��G�ä��A�X�A\n\n";
	}
}
void hmm(int a)
{
	cout << "�q�F"<<a<<"����\n";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".\n";
	Sleep(1000);
	cout << "�c... �ٺ�i�H��\n";
}
int main() 
{
	int Ans,Guess,Min=0,Max=100,count=0,error,ans,max=1000,S,ANS,MAX=10000;
	char s[20];
	srand(time(NULL));
	Ans=rand()%101;	
	ans=rand()%1001;	
	ANS=rand()%10001;
	cout << "�п�J���a�ʺ١G\n";
	cin >> s;	
	cout << "�w��"<<s<<"�C���׷��K�X\n";	
	cout << "\n=================�׷��K�X=================\n";
	cout << "||\t\t\t\t\t||\n";
	cout << "||\t\t1.���`�Ҧ�\t\t||\n";
	cout << "||\t\t2.�x���Ҧ�\t\t||\n";
	cout << "||\t\t3.�]���Ҧ�\t\t||\n";
	cout << "||\t\t4.�h�X�C��\t\t||\n";
	cout << "||\t\t\t\t\t||\n";
	cout << "==========================================\n";
	cout << "�п�J�A����ܡG";
	cin >> S;
	cout << "\n";	
	if(S==1)
	{
		while(1) 
		{
			cout << Min << " ~ " << Max << "�q�@�ӼƦr\n\n";			
			cin >> Guess;			
			count++;
			if(Guess>=Min && Guess<=Max)
			{			
				if(Guess==Ans) 
				{
					cout << "Bingo!\n\n";
				    if(count<=5)
				    {
				    	cout << "�`�@�q�F" << count << "���A�u���O�W�żF�`��!\n";
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
						cout << "�q�F" << count << "���A��򨺻�[�ڡA�ڳ��w�g�q������F�C\n";
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
			cout << Min << " ~ " << max << "�q�@�ӼƦr\n\n";			
			cin >> Guess;			
			count++;
			if(Guess>=Min && Guess<=max)
			{	
				if(Guess==ans) 
				{
					cout << "Bingo!\n\n";
				    	if(count<=10)
					{
						cout << "�`�@�q�F" << count << "���A�u�F�`\n";
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
						cout << "�q�F" << count << "���A�S����󪺧A�ٯu�O�O�ڨتA�O\n";
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
			cout << Min << " ~ " << MAX << "�q�@�ӼƦr\n\n";			
			cin >> Guess;			
			count++;
			if(Guess>=Min && Guess<=MAX)
			{			
				if(Guess==ANS) 
				{
					cout << "Bingo!\n\n";
				    	if(count<=10)
					{
						cout << "�`�@�q�F" << count << "���A�A�O��򰵨쪺�A�]�ӼF�`�F�a!\n�G�M�O�׷��K�X�j�v\n\n";
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
						cout << "�q�F" << count << "���A�S����󪺧A�ٯu�O�O�ڨتA�O\n\n";
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
		cout << "�P�§A���C��!";	
	}	
	else
		cout << "�S��" << S << "���ﶵ�ABYE BYE�I�I";
	return 0;
}
