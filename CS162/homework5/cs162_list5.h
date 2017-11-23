/*
ANGEL MARTINEZ
Homework 5

Porpuse:
	The porpuse of this assigment is to get better at dealing with linear link list 
	and dynamically allocating memory. 
	I will be using some of the code form assigment 4 to modefy it into linear link list
	in order to complete this assigment.
Steps:

1:
	create an extra struct for a node pointer
	create a next pointer variable to be used for LLL
2:
	add a new fuctions to work with in lll for the flagged events
	this  fuction that takes  the information and then  puts it in a LLL
	for every flagged event 
3: 
	modefy the information enter to ether go in the none flagged or flagged events
4:
	display a menu do work eith just flagged events or other

5:
 	aske the user if they want to delete a flaggle event, if so, delete 
	that event
6: 
	display all event if they don't want to work only with flagged events

*/


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE = 131; //temporary size

struct Agenda
{
        Agenda();
	void New_event();
	void Dispaly();	
	char * event;
        int year;
	char * month;
	int  day;
        char * event_info;
};

struct node
{
       	Agenda inventory;
        node * next;

};


class Event_planner
{
        public: 
                Event_planner();
                ~Event_planner();
		void Insert_LLL(Agenda & To_add); // a wrapper so in main i can have the information used by the data members
		void Insert_data(); //an array of agendas 
		void Insert_LLL(node * & head, Agenda & To_add); //inserting into a LLL
		void Display_flagged(); // display only flagged events
		void Display_all_events(); //will display all events 
		bool Event_complete(char event_name[]);	// if the user desires to delete a flagged event they can do so
        private:
		Agenda planner[20];

		node * head;
		int count;
};

 
