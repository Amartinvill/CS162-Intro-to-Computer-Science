#include "cs162_list5.h"
using namespace std;

//constroctors
Event_planner::Event_planner()
{ 
	count = 0; 
        head =NULL;
}

Agenda::Agenda() //constuctor for the struct
{
	event =NULL;
	year = 0;
	month = NULL;
	day = 0;
	event_info = NULL;

}

//destructor
Event_planner::~Event_planner()
{
	node * temp;
        while(head!=NULL)
        {
		temp = head;
		head = head->next;
		delete [] temp->inventory.event; //deleting new node
                delete [] temp->inventory.month; //deleting new node
                delete [] temp->inventory.event_info; //deleting new node
	}
}
//ask the user for information
void Agenda::New_event()
{

	char temp[SIZE];
		cout <<"Enter the type of event: ";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
		temp[0] = toupper(temp[0]); //uppercase the first letter of the event
		event = new char[strlen(temp)+1]; //just the right of memory
		strcpy(event,temp); //copying what was in temp now to the name of the information

		cout <<"Enter the year when this will be happening: ";
		cin>> year;
		cin.ignore(100,'\n');

		cout <<"Enter the month: ";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
		month = new char[strlen(temp)+1];
		strcpy(month,temp);

		cout <<"Enter date: ";
		cin >> day;
		cin.ignore(100,'\n');		

		cout <<"Enter information about it: ";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
		event_info = new char[strlen(temp)+1];
		strcpy(event_info,temp);
}
//adding flagged events into a LLL
void Event_planner::Insert_data()
{
	char response = 'n';
	planner[count].New_event();
	cout<<"Do you add make this a flagg event (y/n): ";
	cin>>response;
	response=tolower(response);
	if('y'==response)
		Insert_LLL(planner[count]);
	++count;

}
void Event_planner::Insert_LLL(Agenda & To_add)
{
	// a wrapper so that the stuff in the private can be access such as head.
	Insert_LLL(head, To_add);
}

void Event_planner::Insert_LLL(node * & head, Agenda & To_add)//inserting into a LLL.
{
	if (!head)
	{
		head = new node;
		head->inventory.event = new char[ strlen(To_add.event) +1];
		strcpy(head->inventory.event,To_add.event);
		head->inventory.year = To_add.year;
		head->inventory.month= new char[strlen(To_add.month) +1];
		strcpy(head->inventory.month,To_add.month);
		head->inventory.day= To_add.day;
		head->inventory.event_info= new char[strlen(To_add.event_info) +1];
		strcpy(head->inventory.event_info,To_add.event);
	
		

		head->next = NULL;
		return;
	}
	
	Insert_LLL(head->next, To_add);
	
}
//displays all events
void Event_planner::Display_all_events()
{
	for(int i = 0; i < count; ++i)// to go through all the events
	{
		cout << "Event: " << planner[i].event << endl;
		cout << "Year: " << planner[i].year <<endl;
		
		cout << "Month: " << planner[i].month <<endl;
		
		cout << "Date: " << planner[i].day <<endl;
		cout << "Event Information: " <<planner[i].event_info << endl;
		
		
	}
}
//displays only flagged events
void Event_planner::Display_flagged()
{
	node * current = head;

	if(!head)return; // if there is nothing on the list do nothing
	while(current!=NULL)// else display all 
	{
		cout<<"Flagged event Name: "<<current->inventory.event<<endl;
		cout<<"Year: "<<current->inventory.year<<endl;
		cout<<"Month: "<<current->inventory.month<<endl;
		cout<<"Date: "<<current->inventory.day<<endl;
		cout<<"Description: "<<current->inventory.event_info<<endl;
		current=current->next;
	}
}
//remove from flagged list
bool Event_planner::Event_complete(char event_name[])
{
	node * current = head;
	node * previous = current;
	if(!head)return false;
	
	if (strcmp(head->inventory.event,event_name)==0)
	{
		current = current->next;
		delete head;
		head = current;
		return true;
	}

	while(current!=NULL)
	{
	
		if(strcmp(current->inventory.event,event_name)==0)
		{
			previous->next=current->next;
			delete current;
			return true;
		}
		previous = current;
		current=current->next;
	}
    return false;
}
