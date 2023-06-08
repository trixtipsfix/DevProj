#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <iomanip>
using namespace std;

// Generic template for prettifying the output on the console
template<typename T> void printElement(T t, const int& width){
    cout << left << setw(width) << setfill(' ') << t;
}

class Project{
	// Data Members
	int Project_ID, DurationDays, Cost, Status;
	// Pointer to next Node
	Project *next = NULL;
	
public:
	// Project Parameterized constructor
	Project(int project_ID,int durationDays,int cost,int status);
	
	// getting the next pointer 
	Project* GetNextProj();
	
	// giving developer, the access to the private data members
	friend class Developer;
	
};

#endif
