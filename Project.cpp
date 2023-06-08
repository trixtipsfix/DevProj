#include "Project.h"


// Project Parameterized constructor
Project::Project(int project_ID,int durationDays,int cost,int status){
	Project_ID = project_ID;
	DurationDays = durationDays; 
	Cost = cost;
	Status = status;
}

// getting the next pointer 
Project* Project::GetNextProj(){
	return next;
}

