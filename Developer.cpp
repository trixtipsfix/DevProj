#include "Developer.h"
#include <iostream>
using namespace std;

// Parameterized Constructor of Developer Node
Developer::Developer(int devID, string name, int specialization){
	Developer_ID =  devID;
	Name = name;
	Specialization = specialization;
	Project_Count = 0;
}

// Adding Project 
void Developer::Add_Project(int project_ID,int durationDays,int cost,int status){
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
Project* Developer::HeadProj(){
	return head;
}

// Searching project in the list using its ID
Project* Developer::Search_Project(int ProjID){
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
void Developer::Print_Project(Project * temp){  
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
