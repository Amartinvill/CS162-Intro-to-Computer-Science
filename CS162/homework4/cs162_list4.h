
/*
Angel Martinez
Homework assigment 4 

Purpose:

The porpuse of this assignment is to affiliate using pointers 
and dynamically allocating arrays. Also this will help us practice
more with the concept of classes and structures.

Steps:
1. Create constuctors
  a. for the class event planner
  b. for the struct agenda
2. create a distructor for the class event planner since im allocating new memory
3. write a function to ask the user to enter the folowing information:
  a. the event
  b. the term
  c. the year when it will be happening
  d. the event information 
  e. the plan b incase the the first event can't happen
  f. and any other optional information that the user what to add.
	i. this information will be added dinamically by using new to 
	have just the right size in memory
4. write a function to display all the arrays
5. write a function to find an event in the list
6. write a menu function to allowed the user to choose from different options
  a. write a function to display the names of the event so that the user can pick form 
     one of them when finding a perticular packege
  b. write a function to display just that packege mentioned
    
*/
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

 
//Constants
const int SIZE = 181; //temporary fix size

struct agenda
{
	agenda();
	
 	char * event;
        char * term;
        int year;
        char * event_info;
        char * plan_b;
        char * optional_info;

};


class Event_planner
{
	public: 
		Event_planner(); //constructor
		~Event_planner(); //destructor
		void New_event();
		void Display_all();
		bool Find_event(char event_name[]);
		void Display_tittle();
		void Show_event(char event_name[]);
		void Menu();
	private:
		agenda * planner; //planner is a pointer to my agenda structure.
		int count;
		char event_name[SIZE];
};
