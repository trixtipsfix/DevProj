#include "DevProj.h"
#include "Developer.h"
#include "Project.h"
#include <limits>
#include <conio.h>

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
