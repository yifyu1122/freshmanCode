#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class MENU{
	private:
		int select, select2;
	public:
		void show(){
			cout << "==========================" << endl
			     << "||       _.MENU._       ||" << endl
			     << "||----------------------||" << endl
			     << "||1. Insert Data        ||" << endl
			     << "||2. Search Data        ||" << endl
			     << "||3. Delete Data        ||" << endl
			     << "||4. Print Transcript   ||" << endl
			     << "||5. Modify Data        ||" << endl
			     << "||0. Exit               ||" << endl
			     << "||   Please Select One  ||" << endl
			     << "==========================" << endl;
		}
		void show2(){
			cout << "============================" << endl
    			 << "||      SEARCH BY...?     ||" << endl
			     << "||------------------------||" << endl
			     << "||1. Number               ||" << endl
			     << "||2. Name                 ||" << endl
			     << "||3. Prg Score            ||" << endl
			     << "||4. Cmp Score            ||" << endl
			     << "||0. Return to Main Menu  ||" << endl
			     << "||   Please Select One    ||" << endl
			     << "============================" << endl;
		}
		void show3(){
			cout << "============================" << endl
    			 << "||        MODIFY...?      ||" << endl
			     << "||------------------------||" << endl
			     << "||1. Name                 ||" << endl
			     << "||2. Prg Score            ||" << endl
			     << "||3. Cmp Score            ||" << endl
			     << "||0. Return to Main Menu  ||" << endl
			     << "||   Please Select One    ||" << endl
			     << "============================" << endl;
		}
		void sel(){
			cin >> select;
			if(cin.fail()){
			    cout << "Input error, redirect to option 1." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                select = 1;
			}
		}
		int showSelect(){
			return select;
		}
		void sel2(){
			cin >> select2;
			if(cin.fail()){
			    cout << "Input error, redirect to option 1." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                select2 = 1;
			}
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
		int readTotalScore(){
		    return prg + cmp;
		}
		void writePtr(node *b){
			ptr = b;
		}
		node *readPtr(){
			return ptr;
		}	
	private:
		int no, prg, cmp;
		node *ptr;
		char name[10];
};

int inputForm(node* temp) {
    int prg, cmp;
    char name[10];
    
    cout << "Please enter name:" << endl;
    cin.ignore();
    cin.getline(name, 10);
    if (cin.fail()) {
        cout << "INPUT ERROR: NAME TOO LONG!!!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return 0;
    }
    temp->writeName(name);
    cout << "Please enter prg score:" << endl;
    cin >> prg;
    if (cin.fail()) {
        cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return 0;
    }
    temp->writePrg(prg);
    cout << "Please enter cmp score:" << endl;
    cin >> cmp;
    if (cin.fail()) {
        cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return 0;
    }
    temp->writeCmp(cmp);
    cout << "Added Successfully!" << endl;
    return 1;
}



void printNode(node *temp){
	     cout << "Name: " 
		 << temp->readName() << endl
		 << "Number: " 
	 	 << temp->readNo()   << endl
		 << "Prg Score: " 
		 << temp->readPrg()  << endl
		 << "Cmp Score: " 
		 << temp->readCmp()  << endl
		 << "Total Score: " 
		 << temp->readTotalScore()  << endl
	     << "================" << endl;
}

bool mycompare(node *front, node *rear){
    return front->readTotalScore()
           > rear->readTotalScore();
}

void printSortList(node *temp){
    if(temp==NULL){
		cout << "Database is NULL!" << endl;
		return;
	}
	else if(temp->readPtr() == NULL){
	    cout << "================" << endl
	         << "Rank: 1" << endl;
        printNode(temp);
        return;
    }
    
    node *times = temp;
    int count = 0, srank = 0, rank = 1;
    while(times!=NULL){
        count++;
        times = times->readPtr();
    }
    times = temp;
    
    node *nodes[count];
    for(int i=0; i<count; i++){
        nodes[i] = times;
        times = times->readPtr();
    }
    sort(nodes, nodes+count, mycompare);
    cout << "================" << endl;
    for(int i=0; i<count; i++) {
        cout << "Rank: " << rank << endl;
        if(i < count - 1) {
            if (nodes[i]->readTotalScore() > nodes[i+1]->readTotalScore()){
                rank += srank + 1;
                srank = 0;
            }
            else if (nodes[i]->readTotalScore() == nodes[i+1]->readTotalScore()){
                srank++;
            }
        }
		printNode(nodes[i]);
    }
}

void printList(node *temp) {
    while(temp!=NULL) {
        cout << "================" << endl;
    	printNode(temp);
    	if(temp==NULL) {
    		break;
        }
        temp = temp->readPtr();		
	}
}

int printAllName(char data[10], node *head, node *front, node *rear) {
	int flag = 0;
	rear = head;
    front = NULL;
    while(rear!=NULL) {
		if(strcmp(data, rear->readName()) == 0) {
        	printNode(rear);
        	flag++;
        	if(rear==NULL) {
        		break;
			} 						
        }
		front = rear;
        rear = rear->readPtr();		
	}
	if(rear==NULL) {
		if(head==NULL) {
			cout << "Database is NULL!" << endl;
		}
		else if(flag==0) {
			cout << "Data not in list!" << endl;	
		}  
	} 	
	return flag;
}


int main() {
	MENU m;
	int sel, num, pScore, cScore, 
	    flag = 0, count = 0;
	node *head = NULL;
	node *temp, *front, *rear;
	char name[10];

	while(m.showSelect()) {
		m.show();
		m.sel();
		sel=m.showSelect();
		switch(m.showSelect()) {
			case 0:
				cout << "You choose to leave." << endl ;
				break;	
			case 1:
				cout << "Please enter a number:" <<endl;
				cin >> num;
				if(cin.fail()){
			    	cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
				if(num > 0){
				    temp = new node;
				    temp->writeNo(num);
				    rear = head;
				    front = NULL;
				    if(head == NULL){
				    	if(inputForm(temp)) {
				    	    temp->writePtr(head);
		    		        head = temp;
				    	}
		    		    
		    		}
		    		else if(num < head->readNo()) {
		    			if(inputForm(temp)) {
    		    		    temp->writePtr(head);
    		    		    head = temp;
		    			}
		    		} 
		    		else{
				        while(rear != NULL && num > rear->readNo()) {
				            front = rear;
		    		        rear = rear->readPtr();
				        }
				        if(rear != NULL && num == rear->readNo()) {
				        	cout << "Number already exist!" << endl;
						}
						else {
							if(inputForm(temp)) {
    							temp->writePtr(rear);
    		               		front->writePtr(temp);
							}
						}		        
		    		}
				}
				else
					cout << "Number out of range!" << endl;		
				break;	
			case 2:
				m.show2();
				m.sel2();
				sel = m.showSelect2();
				switch(m.showSelect2()) {
					case 0:
						cout << "You choose to return to main menu." << endl;
						break;	
					case 1:
						cout << "Please enter a number:" << endl;
						cin >> num;
						if(cin.fail()) {
						    cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            break;
                        }
					    rear = head;
					    front = NULL;
					    while(rear != NULL) {
							if(num == rear->readNo()) {
					        	printNode(rear);
					        	flag++;
					        	if(rear == NULL) {
					        		break;
								} 						
					        }
							front = rear;
					        rear = rear->readPtr();		
						}
						if(rear == NULL) {
							if(head == NULL) {
								cout << "Database is NULL!" << endl;
					    		break;
							}
							else if(flag == 0) {
								cout << "Data not in list!" << endl;	
								flag = 0;
							}  
				    	} 		
						break;	
					case 2:
						cout << "Please enter name:" << endl;
						cin.ignore();
                        cin.getline(name, 10);
                        
                        if (cin.fail()) {
                            cout << "INPUT ERROR: NAME TOO LONG!!!" << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                        } 
                        else {
                            printAllName(name, head, front, rear);		
                        }
                        break;
					case 3:	
						cout << "Please enter prg score:" << endl;
						cin >> pScore;
					    rear = head;
					    front = NULL;
					    while(rear != NULL) {
							if(pScore == rear->readPrg()) {
					        	printNode(rear);
					        	flag++;
					        	if(rear == NULL) {
					        		break;
								} 						
					        }
							front = rear;
					        rear = rear->readPtr();		
						}
						if(rear == NULL) {
							if(head == NULL) {
								cout << "Database is NULL!" << endl;
					    		break;
							}
							else if(flag == 0) {
								cout << "Data not in list!" << endl;	
								flag = 0;
							}  
				    	} 			
						break;
					case 4:	
						cout << "Please enter cmp score:" << endl;
						cin >> cScore;
					    rear = head;
					    front = NULL;
					    while(rear != NULL) {
							if(cScore == rear->readCmp()) {
					        	printNode(rear);
					        	flag++;
					        	if(rear == NULL) {
					        		break;
								} 						
					        }
							front = rear;
					        rear = rear->readPtr();		
						}
						if(rear == NULL) {
							if(head == NULL) {
								cout << "Database is NULL!" << endl;
					    		break;
							}
							else if(flag == 0) {
								cout << "Data not in list!" << endl;	
								flag = 0;
							}  
				    	} 			
						break;
					default:
						cout << "Insert error!" << endl;	
						break;
				}
				break;
			case 3:
			    printList(head);
				cout << "Which student to delete? Please enter name:" << endl;
				cin.ignore();
				cin.getline(name, 10);
				
				if(cin.fail()) {
				    cout << "INPUT ERROR: NAME TOO LONG!!!" << endl;
				    cin.clear();
				    cin.ignore(1000, '\n');
				    break;
				}
				
			    count = printAllName(name, head, front, rear);
				if(count > 1){
					cout << "There's more than one student called " << name  
					<< ", \nplease enter the student's number to delete:" << endl;
					cin >> num;
					rear = head;
				    front = NULL;
				    while(rear!=NULL) {
						if (num == rear->readNo() && strcmp(name, rear->readName()) == 0) {
				        	//delete node
				        	rear = rear->readPtr();
				        	front->writePtr(rear);
							cout << "Data deleted!" << endl;
							break;						
				        }
				        else if(num == rear->readNo() && strcmp(name, rear->readName()) != 0) {
				        	cout << "The number you entered, isn't in the list of names." << endl;
				        	break;
						}
						else if(rear==NULL) {
							cout << "Data not in list!" << endl;
						}
						front = rear;
				        rear = rear->readPtr();		
					}
				}
				else if(count == 1) {
					rear = head;
				    front = NULL;
				    while(rear!=NULL) {
						if(strcmp(name, rear->readName()) == 0) {
				        	// delete node
				        	if(rear->readPtr() == NULL) {
				        	    head = NULL;
				        	    cout << "Data deleted!" << endl;
						    	break;
				        	}
				        	else{
				        	    rear = rear->readPtr();
				            	front->writePtr(rear);
							    cout << "Data deleted!" << endl;
							    break;	
				        	}
				        }
						front = rear;
				        rear = rear->readPtr();		
					}
				}
				break;
			case 4:
				printSortList(head);
				break;
			case 5:
			    printList(head);
			    cout << "Which student's data to modify? Please enter number:" << endl;
				cin >> num;
				
				if(cin.fail()) {
				    cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
				rear = head;
			    front = NULL;
			    if(head == NULL) {
			        cout << "Database is NULL!" << endl;
		    		break;
			    }
			    else{
    			    while(rear != NULL) {
    			        if(num == rear->readNo()) {
    			        	printNode(rear);
    			        	// Ask which to modify?
    			        	cout << "Which data to modify?" << endl;
    			        	m.show3();
            				m.sel2();
            				sel = m.showSelect2();
            				switch(m.showSelect2()) {
            					case 0:
            						cout << "You choose to return to main menu." << endl;
            						break;	
            					case 1:
            						cout << "Please enter name:" << endl;
            						cin.ignore();
                                    cin.getline(name, 10);
                                    
                                    if (cin.fail()) {
                                        cout << "INPUT ERROR: NAME TOO LONG!!!" << endl;
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                    } 
                                    else {
                                        rear->writeName(name);	
                					    cout << "Modify Success!" << endl;
                                    }
            						break;	
            					case 2:	
            						cout << "Please enter prg score:" << endl;
            						cin >> pScore;
            						if(cin.fail()) {
            						    cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        break;
            						}
            					    rear->writePrg(pScore);	
            					    cout << "Modify Success!" << endl;
            						break;
            					case 3:	
            						cout << "Please enter cmp score:" << endl;
            						cin >> cScore;
            						if(cin.fail()) {
            						    cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        break;
            						}
            					    rear->writeCmp(cScore);	
            					    cout << "Modify Success!" << endl;
            						break;
            					default:
            						cout << "Insert error!"<< endl;	
            						break;
            				}
    						break;						
    					}
    					front = rear;
    			        rear = rear->readPtr();	
    			        if(rear == NULL) {
    						cout << "Data not in list!" << endl;
    						break;
    					}
					}
				}
			    break;
			default:
				cout << "Insert error!"<< endl;	
				break;			
		}
	}
}
