#include<iostream>
using namespace std;

class node{
	public:
		void writeNo(int data){
			no = data;
		}
		int readNo(){
			return no;
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
};

void printList(node *temp){
	cout << "head -> ";
	while(temp!=NULL){
		cout<< temp->readNo() << " -> ";
		temp = temp -> readPtr();
	}
	cout << "||" << endl;
}

int main(){
	node *head = NULL;
	node *temp;
	node *front=NULL;
	node *rear;
	int num;
	while(1){
		temp = new node;
		cout <<"Please input number"<<endl;
		cin >> num;
		if(num > 0){
		    temp -> writeNo(num);
		    rear = head;
		    front = NULL;
		    if(head==NULL|| num <= head->readNo()){
    		    temp -> writePtr(head);
    		    head = temp;
    		}
    		else{
		        while(rear!=NULL && num>=rear->readNo()){
		            front=rear;
    		        rear=rear->readPtr();
		        }
		        temp -> writePtr(rear);
                front->writePtr(temp);
    		}
		}
		else
		    break;
	printList(head);
	}
}
