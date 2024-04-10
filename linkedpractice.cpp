#include<iostream>
#include<cstring>
using namespace std;

class MENU{
	private:
		int select, select2;
	public:
		void show(){
			cout << "==========================" << endl;
			cout << "||       _.MENU._       ||" << endl;
			cout << "||----------------------||"<< endl;
			cout << "||1. Insert Data        ||"<< endl;
			cout << "||2. Search Data        ||"<< endl;
			cout << "||3. Delete Data        ||"<< endl;
			cout << "||4. Print Transcript   ||"<< endl;
			cout << "||0. Exit               ||"<< endl;
			cout << "||   Please Select One  ||"<< endl ;
			cout << "==========================" << endl;
		}
		void show2(){
			cout << "==========================" << endl;
			cout << "||     SEARCH BY...?    ||" << endl;
			cout << "||----------------------||"<< endl;
			cout << "||1. Number             ||"<< endl;
			cout << "||2. Name               ||"<< endl;
			cout << "||3. Prg Score          ||"<< endl;
			cout << "||4. Cmp Score          ||"<< endl;
			cout << "||0. Return to Main Menu||"<< endl;
			cout << "||   Please Select One  ||"<< endl ;
			cout << "==========================" << endl;
		}
		void sel(){
			cin >> select;
		}
		int showSelect(){
			return select;
		}
		void sel2(){
			cin >> select2;
		}
		int showSelect2(){
			return select2;
		}
		MENU(){
			select = 1;
			select2= 1;
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
	cout <<"Please enter name:"<<endl;
	cin >> name;
	temp -> writeName(name);
	cout <<"Please enter prg score:"<<endl;
	cin >> prg;
	temp -> writePrg(prg);
	cout <<"Please enter cmp score:"<<endl;
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

void printAllList(node *temp){
	if(temp==NULL){
			cout << "Database is NULL!" << endl;
	}
	while(temp!=NULL){
		printList(temp);
		temp = temp -> readPtr();
	}
	
}

int printAllName(char data[10], node *head, node *front, node *rear){
	int flag = 0;
	rear = head;
    front = NULL;
    while(rear!=NULL){
		if(strcmp(data, rear->readName()) == 0){
        	printList(rear);
        	flag++;
        	if(rear==NULL){
        		break;
			} 						
        }
		front=rear;
        rear=rear->readPtr();		
	}
	if(rear==NULL){
		if(head==NULL){
			cout << "Database is NULL!" << endl;
		}
		else if(flag==0){
			cout << "Data not in list!" << endl;	
		}  
	} 	
	return flag;
}

int main(){
	MENU m;
	int sel, flag=0, count=0;
	node *head = NULL;
	node *temp;
	node *front;
	node *rear;
	int num, pScore, cScore;
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
				cout <<"Please enter a number:"<<endl;
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
				        	cout << "Number already exist!" << endl;
						}
						else{
							inputForm(temp);
							temp -> writePtr(rear);
		               		front->writePtr(temp);
						}		        
		    		}
				}
				else
					cout << "Number out of range!" << endl;		
				break;	
			case 2:
				m.show2();
				m.sel2();
				sel=m.showSelect2();
				switch(m.showSelect2()){
					case 0:
						cout << "You choose to return to main menu."<< endl ;
						break;	
					case 1:
						cout << "Please enter a number:"<< endl ;
						cin >> num;
					    rear = head;
					    front = NULL;
					    while(rear!=NULL){
							if(num == rear->readNo()){
					        	printList(rear);
					        	flag++;
					        	if(rear==NULL){
					        		break;
								} 						
					        }
							front=rear;
					        rear=rear->readPtr();		
						}
						if(rear==NULL){
							if(head==NULL){
								cout << "Database is NULL!" << endl;
					    		break;
							}
							else if(flag==0){
								cout << "Data not in list!" << endl;	
								flag = 0;
							}  
				    	} 		
						break;	
					case 2:
						cout <<"Please enter name:"<<endl;
						cin >> name;
					    printAllName(name, head, front, rear);		
						break;	
					case 3:	
						cout <<"Please enter prg score:"<<endl;
						cin >> pScore;
					    rear = head;
					    front = NULL;
					    while(rear!=NULL){
							if(pScore == rear->readPrg()){
					        	printList(rear);
					        	flag++;
					        	if(rear==NULL){
					        		break;
								} 						
					        }
							front=rear;
					        rear=rear->readPtr();		
						}
						if(rear==NULL){
							if(head==NULL){
								cout << "Database is NULL!" << endl;
					    		break;
							}
							else if(flag==0){
								cout << "Data not in list!" << endl;	
								flag = 0;
							}  
				    	} 			
						break;
					case 4:	
						cout <<"Please enter cmp score:"<<endl;
						cin >> cScore;
					    rear = head;
					    front = NULL;
					    while(rear!=NULL){
							if(cScore == rear->readCmp()){
					        	printList(rear);
					        	flag++;
					        	if(rear==NULL){
					        		break;
								} 						
					        }
							front=rear;
					        rear=rear->readPtr();		
						}
						if(rear==NULL){
							if(head==NULL){
								cout << "Database is NULL!" << endl;
					    		break;
							}
							else if(flag==0){
								cout << "Data not in list!" << endl;	
								flag = 0;
							}  
				    	} 			
						break;
					default:
						cout << "Insert error!"<< endl;	
						break;
				}
				break;
			case 3:
				cout << "Which student to delete? Please enter name:" << endl;
				cin >> name;
				count = printAllName(name, head, front, rear);
				if(count>1){
					cout << "The name is repeated, please enter the number to delete:" << endl;
					cin >> num;
					rear = head;
				    front = NULL;
				    while(rear!=NULL){
						if (num == rear->readNo() && strcmp(name, rear->readName()) == 0){
				        	//delete node
				        	rear = rear->readPtr();
				        	front -> writePtr(rear);
							cout << "Data deleted!" << endl;
							break;						
				        }
				        else if(num == rear->readNo() && strcmp(name, rear->readName()) != 0){
				        	cout << "The number you entered, isn't in the list of names." << endl;
				        	break;
						}
						else{
							cout << "Data not in list!" << endl;
						}
						front=rear;
				        rear=rear->readPtr();		
					}
				}
				else if(count==1){
					rear = head;
				    front = NULL;
				    while(rear!=NULL){
						if(strcmp(name, rear->readName()) == 0){
				        	//delete node
				        	rear=rear->readPtr();
				        	front -> writePtr(rear);
							cout << "Data deleted!" << endl;
							break;						
				        }
						front=rear;
				        rear=rear->readPtr();		
					}
				}
				break;
			case 4:
				printAllList(head);
				break;
			default:
				cout << "Insert error!"<< endl;	
				break;			
		}
	}
}
		    
	
