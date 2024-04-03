#include<iostream>
#include<cstring>
using namespace std;

class MENU{
	private:
		int select;
	public:
		void show(){
			cout << "==========================" << endl;
			cout << "||   Menu for Simulation||" << endl;
			cout << "||1. Insert data        ||"<< endl;
			cout << "||2. Search data        ||"<< endl;
			cout << "||0. Exit               ||"<< endl;
			cout << "||   Please Select one  ||"<< endl ;
			cout << "==========================" << endl;
		}
		void sel(){
			cin >> select;
		}
		int showSelect(){
			return select;
		}
		MENU(){
			select = 1;
		}
};

class node{	
	public:
		void writeNo(int data){
			no = data;
		}
		void writeName(char data[10]){
			strcpy(name, data);
		}
		void writePrg(int data){
			prg = data;
		}
		void writeCmp(int data){
			cmp = data;
		}
		int readNo(){
			return no;
		}
		char *readName(){
			return name;
		}
		int readPrg(){
			return prg;
		}
		int readCmp(){
			return cmp;
		}
		void writePtr(node *b){
			ptr = b;
		}
		node *readPtr(){
			return ptr;
		}	
	private:
		int no;
		node *ptr;
		char name[10];
		int prg;
		int cmp;
};

void inputForm(node*temp){
	int prg,cmp;
	char name[10];
	cout <<"Please input name"<<endl;
	cin >> name;
	temp -> writeName(name);
	cout <<"Please input prg score"<<endl;
	cin >> prg;
	temp -> writePrg(prg);
	cout <<"Please input cmp score"<<endl;
	cin >> cmp;
	temp -> writeCmp(cmp);
}


void printList(node *temp){
	cout << "============" << endl;
	cout << "Name: " 
		 << temp -> readName() << endl
		 << "Number: " 
	 	 << temp -> readNo()   << endl
		 << "Prg Score: " 
		 << temp -> readPrg()  << endl
		 << "Cmp Score: " 
		 << temp -> readCmp()  << endl;
	cout << "============" << endl;
}

int main(){
	
	MENU m;
	int sel;
	node *head = NULL;
	node *temp;
	node *front;
	node *rear;
	int num;
	char name[10];

	while(m.showSelect())
	{
		m.show();
		m.sel();
		sel=m.showSelect();
		switch(m.showSelect()){
			case 0:
				cout << "You choose to leave."<< endl ;
				break;	
			case 1:
				cout <<"Please input number"<<endl;
				cin >> num;
				if(num > 0){
				    temp = new node;
				    temp -> writeNo(num);
				    rear = head;
				    front = NULL;
				    if(head==NULL){
				    	inputForm(temp);
		    		    temp -> writePtr(head);
		    		    head = temp;
		    		}
		    		else if(num < head->readNo()){
		    			inputForm(temp);
		    		    temp -> writePtr(head);
		    		    head = temp;
		    		} 
		    		else{
				        while(rear!=NULL && num>rear->readNo()){
				            front=rear;
		    		        rear=rear->readPtr();
				        }
				        if(rear!=NULL && num == rear->readNo()){
				        	cout << "Number already exist" << endl;
						}
						else{
							inputForm(temp);
							temp -> writePtr(rear);
		               		front->writePtr(temp);
						}		        
		    		}
				}
				else
					cout << "Number out of range" << endl;
								
				break;	
				
			case 2:
				cout <<"Please input name"<<endl;
				cin >> name;
			    rear = head;
			    front = NULL;
			    while(rear!=NULL){
					if(strcmp(name, rear->readName()) == 0){
			        	printList(rear);
			        	break;					
			        }
					front=rear;
			        rear=rear->readPtr();		
				}
				if(rear==NULL){
					if(head==NULL){
						cout << "Database is NULL" << endl;
			    		break;
					}
						cout << "Data not in list" << endl;  
		    	} 			
				break;			
			default:
				cout << "Insert error"<< endl;				
		}
	}
}
		    
	
