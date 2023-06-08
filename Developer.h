#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "Project.h"
#include <iostream>
using namespace std;

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
		Developer(int devID, string name, int specialization);
		
		// Giving private member access to DevProj Class
		friend class DevProj;
		
		// Adding Project 
		void Add_Project(int project_ID,int durationDays,int cost,int status);
		
		// Getting the head node of Project  (latest project)
		Project* HeadProj();
		
		// Searching project in the list using its ID
		Project* Search_Project(int ProjID);
		
		// Printing the Project
		void Print_Project(Project * temp);
};

#endif
