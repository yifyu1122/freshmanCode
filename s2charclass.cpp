#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int a, b, c;
	char S[20], t[20];
	cout << "Please input a, b, and some line.\n";
	cin >> a >> b;
	cin.get();
	cin.getline(S, 20);
	for(int i=0; i<19; i++)
		t[i] = S[i];
		strcpy(t, S);
		
	cout << a << b << S << strcmp(t, S);
	//cin.getline(goal, length);
//ABC	ABC	0
//abc	ABC	1
//ABC	abc	-1
//к№ем	abc	1	
//2     1   1
}
