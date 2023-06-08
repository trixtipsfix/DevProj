#include "DevProj.h"
#include <iostream>
#include <iomanip>
using namespace std;


// Adding developer to our doubly linked list
void DevProj::Add_Developer(int developer_ID, string name, int specialization){
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
Developer* DevProj::getHead(){
	return head;
}

// Moving to the next developer if it is present
Developer* DevProj::getNext(Developer *temp){
	if (temp->next == NULL){ // if it is the last developer
		cout<<"Error: This is the last developer in the list\n";
		return temp;
	}
	// otherwise
	return temp->next;
}

// Moving to the previous developer if it is present
Developer* DevProj::getPrev(Developer *temp){
	if (temp->prev == NULL){  // if it is the first developer in the list
		cout<<"Error: This is the first developer in the list\n";
		return temp;
	}
	//otherwise
	return temp->prev;
}

// search developer from the list
Developer* DevProj::Search_Developer(int DEV_ID){
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
void DevProj::View_Developer(Developer *temp){
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
Developer* DevProj::Search_Project_Dev(int ProjID){
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
void DevProj::Print_Developer(Developer * temp){
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
