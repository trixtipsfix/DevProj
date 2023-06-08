#ifndef DEVPROJ_H
#define DEVPROJ_H
#include <iostream>
#include "Developer.h"
using namespace std;

class DevProj{
	Developer *head = NULL, *tail = NULL;
	public:
		
		// Adding developer to our doubly linked list
		void Add_Developer(int developer_ID, string name, int specialization);
		
		// getting the developer head node [Recently Added Developer]
		Developer * getHead();
		
		// Moving to the next developer if it is present
		Developer* getNext(Developer *temp);
		
		// Moving to the previous developer if it is present
		Developer* getPrev(Developer *temp);
		
		// search developer from the list
		Developer* Search_Developer(int DEV_ID);
		
		// Displaying Developer
		void View_Developer(Developer *temp);
		
		// Search for a specific project using its ID. Then returning its developer address
		Developer* Search_Project_Dev(int ProjID);
		
		// Printing Any Developer
		void Print_Developer(Developer * temp);
		
};
#endif
