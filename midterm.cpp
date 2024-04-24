#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

// Create a class called MENU
class MENU{
	public:
		void show(){
			cout << "==========================" << endl
			     << "||       _.MENU._       ||" << endl
			     << "||----------------------||" << endl
			     << "||1. Insertion          ||" << endl
			     << "||2. Search             ||" << endl
			     << "||3. Deletion           ||" << endl
			     << "||4. Print List Data    ||" << endl
			     << "||5. Print Transcript   ||" << endl
			     << "||0. Exit               ||" << endl
			     << "||   Please select one  ||" << endl
			     << "==========================" << endl;
		}
		writeselect(int){
			cin >> select;
			if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                select = 9;
			}
		}
		int readselect(){
			return select;
		}	
		
		// constructor
		MENU(){
			select = 1;
		}
		private:
		int select, select2;
};

// Create a class called STNODE to store student's data
class STNODE{	
	public:
		void writeNo(int data){
			no = data;
		}
		void writeName(char data[20]){
			strcpy(name, data);
		}
		void writeEng(int data){
			eng = data;
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
		int readEng(){
			return eng;
		}
		int readCmp(){
			return cmp;
		}
		int readTotalScore(){
		    return eng + cmp;
		}
		void writePtr(STNODE *b){
			ptr = b;
		}
		STNODE *readPtr(){
			return ptr;
		}	
		
		// constructor
		STNODE(){
			eng = 0;
			cmp = 0;
			ptr = NULL;
		}
	private:
		int no, eng, cmp;
		STNODE *ptr;
		char name[20];
};

// Data input
int inputForm(STNODE *temp) {
    int eng, cmp;
    char name[20];
    
    // Enter name
    cout << "Please enter name:" << endl;
    cin.ignore();
    cin.getline(name, 20);
    
    // Error text
    if (cin.fail()) {
        cout << "INPUT ERROR: NAME TOO LONG!!!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return 0;
    }
    
    temp->writeName(name);
    
    // Enter English Score
    cout << "Please enter eng score:" << endl;
    cin >> eng;
    
    // Error text
    if (cin.fail()) {
        cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return 0;
    }

    temp->writeEng(eng);
    
    // Enter Cmp Score
    cout << "Please enter cmp score:" << endl;
    cin >> cmp;
    
    // Error text
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


// Print Single Node
void printNode(STNODE *temp){
	     cout << "Name: " 
		 << temp->readName() << endl
		 << "Number: " 
	 	 << temp->readNo()   << endl
		 << "Eng Score: " 
		 << temp->readEng()  << endl
		 << "Cmp Score: " 
		 << temp->readCmp()  << endl
		 << "Total Score: " 
		 << temp->readTotalScore()  << endl
	     << "================" << endl;
}

// Compare use in printSortList
bool mycompare(STNODE *front, STNODE *rear){
    return front->readTotalScore()
           > rear->readTotalScore();
}

// Print list sorted by score
void printSortList(STNODE *temp){
    if(temp==NULL){  // When head is empty
		cout << "Database is NULL!" << endl;
		return;
	}
	else if(temp->readPtr() == NULL){ // When there's only one node in list
	    cout << "================" << endl
	         << "Rank: 1" << endl;
        printNode(temp);
        return;
    }
    
    STNODE *times = temp;
    int count = 0, srank = 0, rank = 1;
    
    // Calculate the amount of dnose in list
    while(times!=NULL){
        count++;
        times = times->readPtr();
    }
    times = temp;
    
    // Copy node
    STNODE *nodes[count];
    for(int i=0; i<count; i++){
        nodes[i] = times;
        times = times->readPtr();
    }
    
    // Sort by algorithm
    sort(nodes, nodes+count, mycompare);
    
    // Print all nodes by score with ranks
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

// Print only the number in list
void printList(STNODE *temp){
	cout << "head->";
	if(temp != NULL){
		while(temp!=NULL){
			cout << temp->readNo();
			temp = temp->readPtr();
			cout << "->";
		}
	} 
	cout << "||" << endl;
}

// Print all the name when select "Search"
int printAllName(char data[20], STNODE *head, STNODE *rear) {
	int flag = 0;
	rear = head;

    
    // Print out when the name is found and rear or head isn't 0
    while(rear != NULL) {
		if(strcmp(data, rear->readName()) == 0) {
			cout << "================" << endl;
        	printNode(rear);
        	flag++; // Flag increase when student is found
        	if(rear == NULL) {
        		break;
			} 						
        }
        rear = rear->readPtr();		
	}
	
	// Print while none is found
	if(rear==NULL) {
		if(head==NULL) {
			cout << "Student doesn't exist! Database is NULL!" << endl;
		}
		else if(flag==0) { // If flag is 0, none student is found. Therefore, student doesn't exist.
			cout << "Student doesn't exist!" << endl;	
		}  
	} 	
	return flag;
}


int main() {
	MENU m;
	int sel, num, eScore, cScore, 
	    flag = 0, count = 0;
	STNODE *head = NULL,
		   *temp, *front, *rear;
	char name[20];

	// Start to loop
	while(m.readselect()) {
		cout << endl; // Leave Space
		
		m.show();  // Call the Menu
		m.writeselect(sel); // Input Selection
		
		switch(m.readselect()) {
			case 0: // Exit
				cout << "You choose to leave." << endl ;
				break;	
				
			case 1: // Insertion
				cout << "Please enter a number:" <<endl;
				cin >> num;
				
				// Error text
				if(cin.fail()){
			    	cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
                
                // If student's number isn't less than 1
				if(num > 0){
				    temp = new STNODE;
				    temp->writeNo(num);
				    rear = head;
				    front = NULL;
				    
				    if(head == NULL){ // If list is empty
				    	if(inputForm(temp)) { // If inputForm doesn't have error, it'll return 1
				    	    temp->writePtr(head);
		    		        head = temp;
				    	}
		    		    
		    		}
		    		else if(num < head->readNo()) { // Sort the number
		    			if(inputForm(temp)) { // If inputForm doesn't have error, it'll return 1
    		    		    temp->writePtr(head);
    		    		    head = temp;
		    			}
		    		} 
		    		else{
				        while(rear != NULL && num > rear->readNo()) { // Sort the number
				            front = rear;
		    		        rear = rear->readPtr();
				        }
				        if(rear != NULL && num == rear->readNo()) { //Number already exist
				        	cout << "Number already exist!" << endl;
						}
						else { // insert node
							if(inputForm(temp)) { // If inputForm doesn't have error, it'll return 1
    							temp->writePtr(rear);
    		               		front->writePtr(temp);
							}
						}		        
		    		}
				}
				else // Number < 0
					cout << "Number out of range!" << endl;		
				break;	
				
			case 2: // Search
				cout << "Please enter name:" << endl;
				cin.ignore();
                cin.getline(name, 20);
                
                // Error text
                if (cin.fail()) {
                    cout << "INPUT ERROR: NAME TOO LONG!!!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                } 
                
                // Print out all the names
            	printAllName(name, head, rear);		
                break;
                
			case 3: // Deletion
				cout << "Which student to delete? Please enter number:" << endl;
				cin >> num;
				
				// Error text
				if(cin.fail()) {
				    cout << "INPUT ERROR: NOT INTEGER!!!" << endl;
				    cin.clear();
				    cin.ignore(1000, '\n');
				    break;
				}
				
				rear = head;
			    front = NULL;
			    
			    // Database is NULL
			    if (rear == NULL) {
					cout << "Database is NULL! Data doesn't exist. Can't be deleted." << endl;
					break;
				}
	            
	            // Database isn't NULL, find number
			    while(rear!=NULL) {
					if (num == rear->readNo()) {
			        	//delete node
			        	if(rear->readPtr() == NULL && head->readPtr() == NULL) {
			        		// There's only one data
			        	    head = NULL;
			        	    cout << "Data deleted!" << endl;
					    	break;
			        	}
			        	else { 
			        		rear = rear->readPtr();
			        		if(front == NULL){
			        			// There's only two data
			        			head = rear;
			        			cout << "Data deleted!" << endl;
			        			break;
							}
							// More than two data exist
				        	front->writePtr(rear);
							cout << "Data deleted!" << endl;
							break;
						}					
			        }
			        front = rear;
			        rear = rear->readPtr();
			        
			        // Data doesn't exist
					if (rear == NULL) {
						cout << "Data doesn't exist. Can't be deleted." << endl;
						break;
					}							
				}
				break;
				
			case 4: // Print List Data
				printList(head);
				break;
				
			case 5: // Print Transcript
			    printSortList(head);
				break;
				
			default: // Error Text
				cout << "Insert error!"<< endl;	
				break;			
		}
	}
}
