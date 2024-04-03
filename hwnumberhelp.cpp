#include<iostream>
#include<cstring>
using namespace std;

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
	cin.get();
	cin.getline(name, 20);
	temp -> writeName(name);
	cout <<"Please input prg score"<<endl;
	cin >> prg;
	temp -> writePrg(prg);
	cout <<"Please input cmp score"<<endl;
	cin >> cmp;
	temp -> writeCmp(cmp);
}


void printList(node *temp){
	cout << "head : " << endl;
	while(temp != NULL){
		cout << "Number: " 
			 << temp -> readNo() 
			 << " Name: " 
			 << temp -> readName() 
			 << " Prg Score: " 
			 << temp -> readPrg() 
			 << " Cmp Score: " 
			 << temp -> readCmp() 
			 << endl;
		temp = temp -> readPtr();
	}
	cout << "==" << endl;
}

int main(){
	node *head = NULL;
	node *temp;
	node *front;
	node *rear;
	int num;
	while(1){
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
		else{
			cout << "Number out of range" << endl;
			break;
		}
		    
	printList(head);
	}
}

