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
		int operator-(node &p){
			return no+p.no;
		}
	private:
    	int no;
    	node *ptr;
};


int operator+(node &p, node &q){
	return(p.readNo()+q.readNo());
}

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
		
		cout <<"Please input number"<<endl;
		cin >> num;
		if(num > 0){
			temp = new node;
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
	cout << "*"<<(*head)+(*temp)<< endl;
	cout << "*"<<(*head)-(*temp)<< endl;
	}
	
}
