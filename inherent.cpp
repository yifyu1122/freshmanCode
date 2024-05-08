#include<iostream>
#include<cstring>
#include<iomanip>
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
		void show2(){
			cout << "==========================" << endl
			     << "||       _.MENU._       ||" << endl
			     << "||----------------------||" << endl
			     << "||1. CS Student         ||" << endl
			     << "||2. PE Student         ||" << endl
			     << "==========================" << endl;
		}
		void writeselect(int sel){
			select = sel;
		}
		void writeselect2(int sel){
			select2 = sel;
		}
		int readselect(){
			return select;
		}	
		int readselect2(){
			return select2;
		}
		
		// constructor
		MENU(){
			select = 1;
			select2 = 1;
		}
	private:
		int select, select2;
};

// Create a class called STNODE to store student's data
class ST{	
	public:
		void writeNo(int data){
			no = data;
		}
		void writeName(char data[20]){
			strcpy(name, data);
		}
		int readNo(){
			return no;
		}
		char *readName(){
			return name;
		}
	protected:
		int no;
		char name[20];
};

class STNODE1: public ST{	
	public:
		void writeEng(int data){
			eng = data;
		}
		void writeCmp(int data){
			cmp = data;
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
		void writePtr(STNODE1 *b){
			ptr = b;
		}
		STNODE1 *readPtr(){
			return ptr;
		}	
		
		// constructor
		STNODE1(){
			eng = 0;
			cmp = 0;
			ptr = NULL;
		}
	protected:
		int eng, cmp;
		STNODE1 *ptr;
};

class STNODE2: public ST{	
	public:
		void writeRun(int data){
			run = data;
		}
		int readRun(){
			return run;
		}
		void writePtr(STNODE2 *b){
			ptr = b;
		}
		STNODE2 *readPtr(){
			return ptr;
		}	
		
		// constructor
		STNODE2(){
			run= 0;
			ptr = NULL;
		}
	protected:
		int run;
		STNODE2 *ptr;
};

class linkedList{
	STNODE1 *head = NULL,
		   *temp, *front, *rear;
	
	
	public:
		linkedList(){
			head = NULL;
		}
		
		bool isEmpty(){
			return head;
		}
		
		int nameCheck(){
			if (cin.fail()) {
		        cerr << "INPUT ERROR: NAME TOO LONG!!!" << endl;
		        cin.clear();
		        cin.ignore(1000, '\n');
		        return 1;
		    }
		    else
		        return 0;
		}
		
		int intCheck(){
			if (cin.fail()) {
		        cerr << "INPUT ERROR: NOT INTEGER!!!" << endl;
		        cin.clear();
		        cin.ignore(1000, '\n');
		        return 1;
		    }
		    else
		        return 0;
		}
		
		void printNode(STNODE1 *temp){
			cout << "Name: " 
				 << setw(20) << temp->readName() << endl
				 << "Number: " 
				 << setw(18) << temp->readNo()   << endl
				 << "Eng Score: " 
				 << setw(15) << temp->readEng()  << endl
				 << "Cmp Score: " 
				 << setw(15) << temp->readCmp()  << endl
				 << "Total Score: " 
			  	 << setw(13) << temp->readTotalScore()  << endl
				 << "==========================" << endl;
		}	

		void insert(STNODE1 *temp) {
		    char name[20];
		    int eScore, cScore;
		    
			if (isEmpty()) {
			    STNODE1 *rear = head;
			    STNODE1 *front = NULL;   
			    if(temp->readNo() < head->readNo()) { // Sort the number
	    		    temp->writePtr(head);
	    		    head = temp;
	    		} 
	    		else{
			        while(rear != NULL && temp->readNo() > rear->readNo()) { // Sort the number
			            front = rear;
	    		        rear = rear->readPtr();
			        }
			        if(rear != NULL && temp->readNo() == rear->readNo()) { //Number already exist
			        	cout << "Number already exist!" << endl;
			        	return;
					}
					else { // insert node
						temp->writePtr(rear);
	               		front->writePtr(temp);
					}		        
	    		}	
			}
			else { // EMPTY
	    	    temp->writePtr(head);
		        head = temp;
			}
			cout << "Please enter name:" << endl;
		    cin.ignore();
		    cin.getline(name, 20);
		    // Error text
		    if (nameCheck()){
		    	return;
			}
		    temp->writeName(name);
    
		    // Enter English Score
		    cout << "Please enter eng score:" << endl;
		    cin >> eScore;
		    // Error text
		    if (intCheck()){
		    	return;
			}
		    temp->writeEng(eScore);
		    
		    // Enter Cmp Score
		    cout << "Please enter cmp score:" << endl;
		    cin >> cScore;
		    // Error text
		    if (intCheck()) {
		    	return;
			}
		    temp->writeCmp(cScore);
		    cout << "Added Successfully!" << endl;
		}
		
		void search(){
			char name[20];
			int flag = 0;
			rear = head;
			
			cout << "Please enter name:" << endl;
			cin.ignore();
            cin.getline(name, 20);
            
            // Error text
            if (nameCheck()) {
                return;
            } 
            
            // Print out all the names
            while(rear != NULL) {
				if(strcmp(name, rear->readName()) == 0) {
					cout << "==========================" << endl;
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
				if(!isEmpty()) {
					cout << "Student doesn't exist! Database is NULL!" << endl;
				}
				else if(flag==0) { // If flag is 0, none student is found. Therefore, student doesn't exist.
					cout << "Student doesn't exist!" << endl;	
				}  
			} 			
		}
		
		void del(){
			int num;
			cout << "Which student to delete? Please enter number:" << endl;
			cin >> num;
			
			// Error text
			if(intCheck()) {
			    return;
			}
			
			rear = head;
		    front = NULL;
		    
		    if (isEmpty()) { // Database isn't NULL, find number
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
			}
			else{
				cout << "Database is NULL! Data doesn't exist. Can't be deleted." << endl;
				return;
			}
		}
		
		void printList(){
			temp = head;
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
		
		void printSortList(){
			temp = head;
			
			if(isEmpty()){
				if(temp->readPtr() == NULL){ // When there's only one node in list
				    cout << "==========================" << endl
				         <<  "Rank: " << setw(20) << "1" << endl;
			        printNode(temp);
			        return;
			    }
			    
			    STNODE1 *times = temp;
			    int count = 0, flag = 0,
			        srank = 0, rank = 1;
			    
			    // Calculate the amount of dnose in list
			    while(times!=NULL){
			        count++;
			        times = times->readPtr();
			    }
			    times = temp;
			    

			    STNODE1 nodes[count];
			    for(int i=0; i<count; i++){
			        nodes[i] = *times;
			        times = times->readPtr();
			    }
			    
			    for (int i=0; i<count; i++){
			        flag = 0;
			        for (int j=0; j<count-i-1; j++)
			            if ( nodes[j].readTotalScore() < nodes[j+1].readTotalScore()){
			                flag = 1;
			            	swap(nodes[j], nodes[j+1]);
					}
					if (flag == 0) {
					    break;
					}
			    }
			       
			   
			    // Print all nodes by score with ranks
			    cout << "==========================" << endl;
			    for(int i=0; i<count; i++) {
			        cout << "Rank: " << setw(20) << rank << endl;
			        if(i < count - 1) {
			            if (nodes[i].readTotalScore() > nodes[i+1].readTotalScore()){
			                rank += srank + 1;
			                srank = 0;
			            }
			            else if (nodes[i].readTotalScore() == nodes[i+1].readTotalScore()){
			                srank++;
			            }
			        }
					printNode(&nodes[i]);
			    }
			}
			else {  // When head is empty
				cout << "Database is NULL!" << endl;
				return;
			}
			
		}

};

class linkedList2{
	STNODE2 *head = NULL,
		   *temp, *front, *rear;
	
	
	public:
		linkedList2(){
			head = NULL;
		}
		
		bool isEmpty(){
			return head;
		}
		
		int nameCheck(){
			if (cin.fail()) {
		        cerr << "INPUT ERROR: NAME TOO LONG!!!" << endl;
		        cin.clear();
		        cin.ignore(1000, '\n');
		        return 1;
		    }
		    else
		        return 0;
		}
		
		int intCheck(){
			if (cin.fail()) {
		        cerr << "INPUT ERROR: NOT INTEGER!!!" << endl;
		        cin.clear();
		        cin.ignore(1000, '\n');
		        return 1;
		    }
		    else
		        return 0;
		}
		
		void printNode(STNODE2 *temp){
			cout << "Name: " 
				 << setw(20) << temp->readName() << endl
				 << "Number: " 
				 << setw(18) << temp->readNo()   << endl
				 << "Run Score: " 
				 << setw(15) << temp->readRun()  << endl
				 << "==========================" << endl;
		}	
		

		void insert(STNODE2 *temp) {
		    char name[20];
		    int rScore;
		    
			if (isEmpty()) {
			    STNODE2 *rear = head;
			    STNODE2 *front = NULL;   
			    if(temp->readNo() < head->readNo()) { // Sort the number
	    		    temp->writePtr(head);
	    		    head = temp;
	    		} 
	    		else{
			        while(rear != NULL && temp->readNo() > rear->readNo()) { // Sort the number
			            front = rear;
	    		        rear = rear->readPtr();
			        }
			        if(rear != NULL && temp->readNo() == rear->readNo()) { //Number already exist
			        	cout << "Number already exist!" << endl;
			        	return;
					}
					else { // insert node
						temp->writePtr(rear);
	               		front->writePtr(temp);
					}		        
	    		}	
			}
			else { // EMPTY
	    	    temp->writePtr(head);
		        head = temp;
			}
			cout << "Please enter name:" << endl;
		    cin.ignore();
		    cin.getline(name, 20);
		    // Error text
		    if (nameCheck()){
		    	return;
			}
		    temp->writeName(name);
    
		    // Enter Running Score
		    cout << "Please enter run score:" << endl;
		    cin >> rScore;
		    // Error text
		    if (intCheck()){
		    	return;
			}
		    temp->writeRun(rScore);
		    
		    cout << "Added Successfully!" << endl;
		}
		
		void search(){
			char name[20];
			int flag = 0;
			rear = head;
			
			cout << "Please enter name:" << endl;
			cin.ignore();
            cin.getline(name, 20);
            
            // Error text
            if (nameCheck()) {
                return;
            } 
            
            // Print out all the names
            while(rear != NULL) {
				if(strcmp(name, rear->readName()) == 0) {
					cout << "==========================" << endl;
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
				if(!isEmpty()) {
					cout << "Student doesn't exist! Database is NULL!" << endl;
				}
				else if(flag==0) { // If flag is 0, none student is found. Therefore, student doesn't exist.
					cout << "Student doesn't exist!" << endl;	
				}  
			} 			
		}
		
		void del(){
			int num;
			cout << "Which student to delete? Please enter number:" << endl;
			cin >> num;
			
			// Error text
			if(intCheck()) {
			    return;
			}
			
			rear = head;
		    front = NULL;
		    
		    if (isEmpty()) { // Database isn't NULL, find number
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
			}
			else{
				cout << "Database is NULL! Data doesn't exist. Can't be deleted." << endl;
				return;
			}
		}
		
		void printList(){
			temp = head;
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
		
		void printSortList(){
			temp = head;
			
			if(isEmpty()){
				if(temp->readPtr() == NULL){ // When there's only one node in list
				    cout << "==========================" << endl
				         << "Rank: " << setw(20) << "1" << endl;
			        printNode(temp);
			        return;
			    }
			    
			    STNODE2 *times = temp;
			    int count = 0, flag = 0,
			        srank = 0, rank = 1;
			    
			    // Calculate the amount of dnose in list
			    while(times!=NULL){
			        count++;
			        times = times->readPtr();
			    }
			    times = temp;
			    

			    STNODE2 nodes[count];
			    for(int i=0; i<count; i++){
			        nodes[i] = *times;
			        times = times->readPtr();
			    }
			    
			    for (int i=0; i<count; i++){
			        flag = 0;
			        for (int j=0; j<count-i-1; j++)
			            if ( nodes[j].readRun() < nodes[j+1].readRun()){
			                flag = 1;
			            	swap(nodes[j], nodes[j+1]);
					}
					if (flag == 0) {
					    break;
					}
			    }
			       
			   
			    // Print all nodes by score with ranks
			    cout << "==========================" << endl;
			    for(int i=0; i<count; i++) {
			        cout << "Rank: " << setw(20) << rank << endl;
			        if(i < count - 1) {
			            if (nodes[i].readRun() > nodes[i+1].readRun()){
			                rank += srank + 1;
			                srank = 0;
			            }
			            else if (nodes[i].readRun() == nodes[i+1].readRun()){
			                srank++;
			            }
			        }
					printNode(&nodes[i]);
			    }
			}
			else {  // When head is empty
				cout << "Database is NULL!" << endl;
				return;
			}
			
		}

};


int main() {
	MENU m;
	int sel, num, eScore, cScore, 
	    flag = 0, count = 0;
	char name[20];
	STNODE1 *temp1;
	STNODE2 *temp2;
	linkedList L1;
	linkedList2 L2;
	

	while(m.readselect()) {
		cout << endl; // Leave Space
		
		m.show();  // Call the Menu
		cin >> sel;
		if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            sel = 9;
		}
		m.writeselect(sel); // Input Selection
		
		switch(m.readselect()) {
			case 0: // Exit
				cout << "You choose to leave." << endl ;
				break;	
				
			case 1: // Insertion
				m.show2();  // Call the Menu
				cin >> sel;
				if(cin.fail()){
		            cin.clear();
		            cin.ignore(1000, '\n');
		            sel = 9;
				}
				m.writeselect2(sel); // Input Selection
				
				switch(m.readselect2()) {
					case 1: // CS
						temp1 = new STNODE1;
		    			cout << "Please enter a number:" <<endl;
		    			cin >> num;
		    			if (L1.intCheck()){
							break;
						}
						if(num > 0){
							temp1->writeNo(num);
							L1.insert(temp1);
						}
						else{
							cerr << "Number out of range!" << endl;	
						}	
						break;
					case 2: // PE
						temp2 = new STNODE2;
						int num;
		    			cout << "Please enter a number:" <<endl;
		    			cin >> num;
		    			if (L2.intCheck()){
							break;
						}
						if(num > 0){
							temp2->writeNo(num);
							L2.insert(temp2);
						}
						else{
							cerr << "Number out of range!" << endl;	
						}
						break;
					default: // Error Text
						cerr << "Insert error!"<< endl;	
						break;			
				}

				break;
			case 2: // Search
				m.show2();  // Call the Menu
				cin >> sel;
				if(cin.fail()){
		            cin.clear();
		            cin.ignore(1000, '\n');
		            sel = 9;
				}
				m.writeselect2(sel); // Input Selection
				
				switch(m.readselect2()) {
					case 1: // CS
						L1.search();
						break;
					case 2: // PE
						L2.search();
						break;
					default: // Error Text
						cerr << "Insert error!"<< endl;	
						break;			
				}
				break;
                
			case 3: // Deletion
				m.show2();  // Call the Menu
				cin >> sel;
				if(cin.fail()){
			        cin.clear();
			        cin.ignore(1000, '\n');
			        sel = 9;
				}
				m.writeselect2(sel); // Input Selection
				
				switch(m.readselect2()) {
					case 1: // CS
						L1.del();
						break;
					case 2: // PE
						L2.del();
						break;
					default: // Error Text
						cerr << "Insert error!"<< endl;	
						break;			
				}
				break;
				
			case 4: // Print List Data
				m.show2();  // Call the Menu
				cin >> sel;
				if(cin.fail()){
			        cin.clear();
			        cin.ignore(1000, '\n');
			        sel = 9;
				}
				m.writeselect2(sel); // Input Selection
				
				switch(m.readselect2()) {
					case 1: // CS
						L1.printList();
						break;
					case 2: // PE
						L2.printList();
						break;
					default: // Error Text
						cerr << "Insert error!"<< endl;	
						break;			
				}
				break;
				
			case 5: // Print Transcript	
				m.show2();  // Call the Menu
				cin >> sel;
				if(cin.fail()){
			        cin.clear();
			        cin.ignore(1000, '\n');
			        sel = 9;
				}
				m.writeselect2(sel); // Input Selection
				
				switch(m.readselect2()) {
					case 1: // CS
						L1.printSortList();
						break;
					case 2: // PE
						L2.printSortList();
						break;
					default: // Error Text
						cerr << "Insert error!"<< endl;	
						break;			
				}
				break;
				
			default: // Error Text
				cerr << "Insert error!"<< endl;	
				break;			
		}
	}
}
