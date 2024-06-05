#include<iostream>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<string>
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
			     << "||4. Print Data         ||" << endl
			     << "||5. Purchase           ||" << endl
			     << "||6. Ship               ||" << endl
			     << "||0. Exit               ||" << endl
			     << "||   Please select one  ||" << endl
			     << "==========================" << endl;
		}
		void writeselect(int sel){
			select = sel;
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

class Merch{	
	public:
		void writeNo(int data){
			no = data;
		}
		void writeName(string data){
			name = data;
		}
		void writePrice(int data){
			price = data;
		}
		void writeStock(int data){
			stock = data;
		}
		int readNo(){
			return no;
		}
		string readName(){
			return name;
		}
		int readPrice(){
			return price;
		}
		int readStock(){
			return stock;
		}
		Merch(){
			price = 0;
			stock = 0;
		}
	protected:
		int no, price, stock;
		string name;
};

class Food: public Merch{	
	public:
		void writeDate(float data){
			date = data;
		}
		int readDate(){
		    return date;
		}
		void writePtr(Food *b){
			ptr = b;
		}
		Food *readPtr(){
			return ptr;
		}	
		
		// constructor
		Food(){
			date = 0;
			ptr = NULL;
		}
	protected:
		int date;
		Food *ptr;
};

class List {
	Food *head = NULL,
		 *temp, *front, *rear;
	
	
	public:
		List(){
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
		
		void printNode(Food *temp){
			cout << setw(10) << temp->readNo()  
			     << setw(23) << temp->readName() 
				 << setw(8) << temp->readDate()  
				 << setw(9) << temp->readPrice()  
				 << setw(9) << temp->readStock()  << endl;
		}	

		void insert(Food *temp) {
		    char name[20];
		    int price, stock, date;
		    
			if (isEmpty()) {
			    Food *rear = head;
			    Food *front = NULL;   
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
    
		    // Enter 
		    cout << "Please enter price:" << endl;
		    cin >> price;
		    // Error text
		    if (intCheck()){
		    	return;
			}
		    temp->writePrice(price);
		    
		    // Enter 
		    cout << "Please enter stock:" << endl;
		    cin >> stock;
		    // Error text
		    if (intCheck()) {
		    	return;
			}
		    temp->writeStock(stock);
		    
		    // Enter 
		    cout << "Please enter due date:" << endl;
		    cin >> date;
		    // Error text
		    if (intCheck()) {
		    	return;
			}
		    temp->writeDate(date);
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
				if(name == rear->readName()) {
					cout <<  "|| Number ||         Name        || Date || Price || Stock ||" << endl ;
		        	printNode(rear);
		        	flag++; // Flag increase when merch is found
		        	if(rear == NULL) {
		        		break;
					} 						
		        }
		        rear = rear->readPtr();		
			}
			
			// Print while none is found
			if(rear==NULL) {
				if(!isEmpty()) {
					cout << "Merch doesn't exist!�]Database is NULL!�^" << endl;
				}
				else if(flag==0) { // If flag is 0, none merch is found. Therefore, merch doesn't exist.
					cout << "Merch doesn't exist!" << endl;	
				}  
			} 			
		}
		
		void del(){
			int num;
			cout << "Which merch to delete? Please enter number:" << endl;
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
				
		void printSortList(){
			temp = head;
			if(isEmpty()){
				while(temp!=NULL) {
			    	cout << "|| Number ||         Name        || Date || Price || Stock ||" << endl;
			    	cout << setw(10) << temp->readNo()  
				     << setw(23) << temp->readName() 
					 << setw(8) << temp->readDate()  
					 << setw(9) << temp->readPrice()  
					 << setw(9) << temp->readStock()  << endl;
			    	if(temp==NULL) {
			    		break;
			        }
			        temp = temp->readPtr();		
				}
			}
			else {  // When head is empty
				cout << "NO MERCH!" << endl;
				return;
			}
			
		}
		
		void purchase(){
			int num, add;
			cout << "Which merch to purchase? Please enter product number and how many to purchase:" << endl;
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
			        	//find merch
			        	cin >> add;
			        	if(intCheck()) {
						    return;
						}
						rear->writeStock(rear->readStock() + add);
						cout << "Successfully purchase.";
						break;
			        }
			        front = rear;
			        rear = rear->readPtr();
			        
			        // Data doesn't exist
					if (rear == NULL) {
						cout << "Merch doesn't exist. Can't be purchase." << endl;
						break;
					}							
				}
			}
			else{
				cout << "The stocking is empty. Merch doesn't exist. Can't be purchase." << endl;
				return;
			}
		}
		
		void ship(){
			int num, sub;
			cout << "Which merch to ship? Please enter product number and how many to ship:" << endl;
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
			        	//find merch
			        	cin >> sub;
			        	if(intCheck()) {
						    return;
						}
						if (sub > rear->readStock()){
							cout << "The stocking is not enough to be shipped." << endl;
						}
						else{
							rear->writeStock(rear->readStock() - sub);
							cout << "Successfully shipped.";
						}
						break;
			        }
			        front = rear;
			        rear = rear->readPtr();
			        
			        // Data doesn't exist
					if (rear == NULL) {
						cout << "Merch doesn't exist. Can't be shipped." << endl;
						break;
					}							
				}
			}
			else{
				cout << "The stocking is empty. Merch doesn't exist. Can't be shipped." << endl;
				return;
			}
		}
		
		void output(ofstream &file){
			temp = head;
			if(isEmpty()){
			    Food *times = temp;
			    int count = 0;
			    
			    // Calculate the amount of node in list
			    while(times!=NULL){
			        count++;
			        times = times->readPtr();
			    }
			    times = temp;
			    

			    Food nodes[count];
			    for(int i=0; i<count; i++){
			        nodes[i] = *times;
			        times = times->readPtr();
			    }
		   
			    for (int i=0; i<count; i++) {
					file << nodes[i].readNo()
						 << " " << nodes[i].readDate() 
						 << " " << nodes[i].readPrice()
						 << " " << nodes[i].readStock() 
						 << " " << nodes[i].readName()  << endl;
			    }
			}
			else {  // When head is empty
				return;
			}		
		}
		Food *readfile(){
			Food *tail = NULL;
			string na;
			int no, date, price, stock;
			ifstream input("product.txt");
			if (!input) {
                cerr << "product.txt doesn't exist" << endl;
                return 0;
            }
			while (input >> no >> date >> price >> stock){				
				input.ignore();
				getline(input, na);
				Food *temp = new Food;
				temp->writeName(na);
				temp->writeNo(no);
				temp->writeDate(date);
				temp->writePrice(price);
				temp->writeStock(stock);
		        
				if (head == NULL) {
		            head = temp;
		            tail = temp;
		        } 
				else {
		            tail->writePtr(temp);
		            tail = temp;
		        }
			}
			input.close();
			return head;
		}
};

int main() {
	MENU m;
	int sel, num;
	Food *temp1;
	List L1;
	L1.readfile();
    ofstream file;
	file.open("product.txt");
	
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
				L1.output(file);
				file.close();
				break;	
				
			case 1: // Insertion
				temp1 = new Food;
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
				
			case 2: // Search
				L1.search();
				break;
                
			case 3: // Deletion
				L1.del();
				break;
				
			case 4: // Print List Data
				L1.printSortList();
				break;
				
			case 5: // Purchase
				L1.purchase();
				break;
			
			case 6: // Ship
				L1.ship();
				break;		
				
			default: // Error Text
				cerr << "Insert error!"<< endl;	
				break;			
		}
	}
	return 0;
}
