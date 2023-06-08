/*
Name: Mirza Areeb Baig
Reg. ID: 211034
Date: 23/10/2022
*/

#include <iostream>  // input output stream
#include <iomanip>  // using setw()[Set Width] method
#include <conio.h>  // using getch()[Get character] function
#include <limits>   // input validation purposes
using namespace std; // standard namespace

// Generic template for prettifying the output on the console
template<typename T> void printElement(T t, const int& width){
    cout << left << setw(width) << setfill(' ') << t;
}

// Project Node Class
class Project{
	// Data Members
	int Project_ID, DurationDays, Cost, Status;
	// Pointer to next Node
	Project *next = NULL;
	
public:
	// Project Parameterized constructor
	Project(int project_ID,int durationDays,int cost,int status){
		Project_ID = project_ID;
		DurationDays = durationDays; 
		Cost = cost;
		Status = status;
	}
	
	// getting the next pointer 
	Project* GetNextProj(){
		return next;
	}
	
	// giving developer, the access to the private data members
	friend class Developer;
	
};

class Developer{
	private:
		// Data Members of Developer
		int Developer_ID;
		string Name;
		int Specialization;
		int Project_Count;
		
		// static variable for counting the number of developers
		static int Dev_Count;
		
		// Connecting circular linked list of project
		Project *head = NULL;
		Project *tail = NULL;
		
		// Pointer to Next and Previous node for making doubly linked list of developer
		Developer *next = NULL;
		Developer *prev = NULL;

	public:
		// Parameterized Constructor of Developer Node
		Developer(int devID, string name, int specialization){
			Developer_ID =  devID;
			Name = name;
			Specialization = specialization;
			Project_Count = 0;
		}
		
		// Giving private member access to DevProj Class
		friend class DevProj;
		
		// Adding Project 
		void Add_Project(int project_ID,int durationDays,int cost,int status){
			Project* tmp = new Project(project_ID,durationDays,cost,status);
			if (head == NULL){  // if the list is empty
				head = tmp;
				tail = tmp;
				tail->next = head;
			}
			else{               // if the list is not empty
				tmp->next = head;
				tail->next = tmp;
				head = tmp;
			}
			Project_Count++; // incrementing project count
		}
		
		// Getting the head node of Project  (latest project)
		Project* HeadProj(){
			return head;
		}
		
		// Searching project in the list using its ID
		Project* Search_Project(int ProjID){
			Project* tempProj = head;
			int count = 0;
			if (tempProj == NULL || Project_Count <= 0){  // if the projects list is empty
				return NULL;
			}
			else{  // and if its not
				while (tempProj != NULL && count++ < Project_Count){  // traversing through all the projects using project count
					if (tempProj->Project_ID == ProjID){
						return tempProj;
					}
					tempProj = tempProj->next;
				}
				return NULL;
			}
		}
		
		// Printing the Project
		void Print_Project(Project * temp){  
			cout<<"\n========================================\n";
			cout<<"\tProject Details";
			cout<<"\n========================================\n";
			
			printElement("ID:", 20);
			printElement(temp->Project_ID, 20);
			cout<<endl;
			printElement("Duration(days):", 20);
			printElement(temp->DurationDays, 20);
			cout<<endl;
			printElement("Cost:", 20);
			printElement(temp->Cost, 20);
			cout<<endl;
			printElement("Status:", 20);
			switch(temp->Status){
				case 1:
					printElement("Completed!", 20);
					break;
				case 2:
					printElement("In Progress!", 20);
					break;
				case 3:
					printElement("Cancelled!", 20);
					break;
				default:
					cout<<"N/A";
			}
			cout<<"\n========================================\n";
		}
};

int Developer::Dev_Count;


class DevProj{
	Developer *head = NULL, *tail = NULL;
	public:
		
		// Adding developer to our doubly linked list
		void Add_Developer(int developer_ID, string name, int specialization){
			Developer *dev = new Developer(developer_ID, name, specialization);
			Developer* temp = head;
			if (temp == NULL){  // if the list is empty
				head = dev;
				tail = dev;
			}
			else{				// if it's not
				dev->next = head;
				head->prev = dev;
				head = dev;
			}
		}
		
		// getting the developer head node [Recently Added Developer]
		Developer * getHead(){
			return head;
		}
		
		// Moving to the next developer if it is present
		Developer* getNext(Developer *temp){
			if (temp->next == NULL){ // if it is the last developer
				cout<<"Error: This is the last developer in the list\n";
				return temp;
			}
			// otherwise
			return temp->next;
		}
		
		// Moving to the previous developer if it is present
		Developer* getPrev(Developer *temp){
			if (temp->prev == NULL){  // if it is the first developer in the list
				cout<<"Error: This is the first developer in the list\n";
				return temp;
			}
			//otherwise
			return temp->prev;
		}
		
		// search developer from the list
		Developer* Search_Developer(int DEV_ID){
			Developer * temp = head;
			
			while(temp != NULL){ // if the list is not empty
				if (temp->Developer_ID == DEV_ID){ // if the ID matches
					return temp;
				}
				// otherwise
				temp = temp->next;
			}
			// if it is empty
			cout<<"Sorry! No Developer Found with this ID\n";
			return NULL;
		}
		
		// Displaying Developer
		void View_Developer(Developer *temp){
			Developer* tmp = temp;
			if (tmp == NULL){
				cout<<"Sorry! No Developer Record Available.\n";
			}
			else{
					Print_Developer(tmp);
					
					if (tmp->head == NULL){
						cout<<"Sorry! No Project Available for this Developer\n";
					}
					else{
						tmp->Print_Project(tmp->head);
					}
			}
		}
		
		// Search for a specific project using its ID. Then returning its developer address
		Developer* Search_Project_Dev(int ProjID){
			Developer* tempDev = head;
			
			if (tempDev == NULL){
				cout<<"Sorry! No Developer Available\n";
			}
			else{
				while(tempDev != NULL){
					if (tempDev->Search_Project(ProjID) != NULL){
						Print_Developer(tempDev);
						tempDev->Print_Project(tempDev->Search_Project(ProjID));
						return tempDev;
					}
					tempDev = tempDev->next;
				}
				return NULL;
			}
		}
		
		// Printing Any Developer
		void Print_Developer(Developer * temp){
			cout<<"\n========================================\n";
			cout<<"\tDeveloper Details";
			cout<<"\n========================================\n";
			printElement("ID:", 20);
			printElement(temp->Developer_ID, 20);
			cout<<endl;
			printElement("Name:", 20);
			printElement(temp->Name, 20);
			cout<<endl;
			printElement("Specialization:", 20);
			switch(temp->Specialization){
				case 1:
					printElement("Web", 20);
					break;
				case 2:
					printElement("Mobile", 20);
					break;
				case 3:
					printElement("Desktop", 20);
					break;
				default:
					printElement("N/A", 20);
			}
			cout<<endl;
			printElement("No. of Project:", 20);
			printElement(temp->Project_Count, 20);
			cout<<endl;
		}
		
};

// Main Menu To Display First
void MainMenu(){
	cout<<"\t========================\n";
	cout<<"\t[> Welcome to DevProj <]\n";
	cout<<"\t========================\n";
	cout<<" Please choose a command:\n";
	cout<<" d - Add a developer\n";
	cout<<" p - Add a project\n";
	cout<<" s - Search for a developer\n";
	cout<<" t - Search for a project\n";
	cout<<" v - View developers\n";
	cout<<" f - Show next developer\n";
	cout<<" r - Show previous developer\n";
	cout<<" n - Show next project\n";
	cout<<" e - exit\n";
}

int validate_int(){
	int input = 0;
	bool valid = false;
	do
    {
        cout << flush;
        cin >> input;
        if (cin.good()){
            //everything went well, we'll get out of the loop and return the value
            valid = true;
            return input;
            
        }
        else{
            //something went wrong, we reset the buffer's state to good
            cin.clear();
            //and empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input; Please re-enter." << endl;
        }
        input = 0;
    } while (!valid);
}

// Developer specialization menu
void Specs(){
	cout<<"\tChoose Specialization\n";
	cout<<"1) Web\n";
	cout<<"2) Mobile\n";
	cout<<"3) Desktop\n";
	cout<<"=> ";
}

// Project status menu
void Status(){
	cout<<"\tChoose Project Status\n";
	cout<<"1) Completed\n";
	cout<<"2) In Progress\n";
	cout<<"3) Cancelled\n";
	cout<<"=> ";
}

int main(){
	DevProj devs; // Creating List of Developers
	system("color a");  // Changing foreground color
	char option;
	bool first = 1;   // to validate the first display
	Developer *tempDevHead = devs.getHead();   // getting the head node for displaying developers
	Developer *tempDev = devs.getHead();       // getting the head node to traverse forward and reverse in the list
	Project* tempProj;
	int ids = 1, projID = 1, specs, status, cost, durations;   // creating variables for getting input
	
	Developer* SearchedDev;
	while(true){
		
		MainMenu();  // Displaying Main Menu
		option = getch();
		int searchID;
		
		while(!isalpha(option)){
			cout<<"Error: Invalid Command\n";
			option = getch();
		}
		system("cls");string name;
		switch(option){
			case 'd':  // d -- Add a developer
				
				// Getting Data
				cout<<"\t==================\n";
				cout<<"\t Adding Developer\n";
				cout<<"\t==================\n";
				cout<<" Provide Developer ID: ";
				ids = validate_int();
				cout<<" Provide Developer Name: ";
				cin.clear();
				cin.ignore();
				getline(cin, name);
				Specs();
				specs = validate_int();
				while(specs < 1 || specs > 3){
					cout<<"Error: Invalid Option Selected\n";
					specs = validate_int();
				}
				
				// Creating Developer by Passing Data
				devs.Add_Developer(ids, name,specs);
				// updating temp variables for later use
				tempDev = devs.getHead();
				tempProj = tempDev->HeadProj();
				cout<<"\n[*] Success! Developer Added Successfully! [*]\n\n";
				
				system("pause");
				break;
				
			case 'p':  // p -- Add a project
				cout<<"\t================\n";
				cout<<"\t Adding Project \n";
				cout<<"\t================\n";
				cout<<" Provide Developer ID: ";
				searchID = validate_int();
				SearchedDev = devs.Search_Developer(searchID);
				tempDev = SearchedDev;
				if (SearchedDev != NULL){
					cout<<" Provide Project ID: ";
					projID = validate_int();
					cout<<" Provide Duration (days): ";
					durations= validate_int();
					cout<<" Provide Total Cost $: ";
					cost = validate_int();
					Status();
					status = validate_int();
					while(status < 1 || status > 3){
						cout<<" Error: Invalid Option Selected\n";
						specs = validate_int();
					}
					SearchedDev->Add_Project(projID, durations, cost, status);
					
					devs.View_Developer(SearchedDev);
				}
				else{
					cout<<"Sorry! No developer found with this ID\n";
				}
				system("pause");
				break;
				
			case 's': // s - Search for a developer
				cout<<"\t==================\n";
				cout<<"\t Search Developer \n";
				cout<<"\t==================\n";
				cout<<" Enter Developer ID: ";
				searchID = validate_int();
				SearchedDev = devs.Search_Developer(searchID);
				tempDev = SearchedDev;
				devs.View_Developer(SearchedDev);
				system("pause");
				break;
				
			case 't': // t - Search Project
				int projID;
				cout<<"\t================\n";
				cout<<"\t Search Project \n";
				cout<<"\t================\n";
				cout<<"Enter Project ID: ";
				projID = validate_int();
				SearchedDev = devs.Search_Project_Dev(projID);
			
				if (SearchedDev == NULL){
					cout<<"Sorry! No Project Found with this ID\n";
				}
				system("pause");
				break;
				
			case 'v':  // v - View Developer
				cout<<"\t===================\n";
				cout<<"\t Developer Display\n";
				cout<<"\t===================\n";
				if (devs.getHead() != NULL)
					devs.View_Developer(devs.getHead());
				else
					cout<<"Sorry! The Record is Empty\n";
				
				first = 0;
				tempDev = devs.getHead();
				system("pause");
				break;

			case 'f':  // Show next developer
				cout<<"\t================\n";
				cout<<"\t Next Developer\n";
				cout<<"\t================\n";
				if (tempDev != NULL){
					tempDev = devs.getNext(tempDev);
					devs.View_Developer(tempDev);
				}
				else if (first == 1){
					if (devs.getHead() != NULL)
						devs.View_Developer(devs.getHead());
					else
						cout<<"Sorry! The Record is Empty\n";
					first = 0;
					tempDev = devs.getHead();
				}
				else{
					cout<<"Error: No Record Present\n";
				}
				system("pause");
				break;
			
			case 'r': // Show Previous Developer
				cout<<"\t====================\n";
				cout<<"\t Previous Developer \n";
				cout<<"\t====================\n";
				if (tempDev != NULL){
					tempDev = devs.getPrev(tempDev);
					devs.View_Developer(tempDev);
				}
				else{
					cout<<"Error: No Developer Record Available\n";
				}
				system("pause");
				break;
				
			case 'n':  // Show Next Project
				cout<<"\t==============\n";
				cout<<"\t Next Project \n";
				cout<<"\t==============\n";
				if (tempDev != NULL){
					tempProj = tempDev->HeadProj();
					if (tempProj != NULL){
						tempDev->Print_Project(tempProj);
						tempProj = tempProj->GetNextProj();
					}
					else{
						cout<<"No Project Done by this developer\n";
					}
				}
				else{
					cout<<"No Developer Available!\n";
				}
				system("pause");
				break;
					
			case 'e': // Exiting 
				cout<<"Thanks for using :)\n";
				exit(1);
				
			default: // At Last
				cout<<"Error: Invalid Command\n";
				system("pause");
		}
		system("cls"); // Clearing the Console Output
	}
	
	return 0;
}
