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
	node *next;
	node *tmp;
	next = head;
	int num,
		counter = 0,
		update = 0;
	while(1){
		temp = new node;
		cout <<"Please input number"<<endl;
		cin >> num;
		if(num>update){
		    temp -> writeNo(num);
    		temp -> writePtr(next);
    		update = num;
    		if(counter!=0){
    		    tmp = head;
    		    for(int i=1;i<counter;i++){
            		tmp = tmp -> readPtr();
    	        }
    		    tmp -> writePtr(temp);
    		    counter++;
    		}
    		if(counter==0){
    		    head = temp;
    		    counter++;
    		}