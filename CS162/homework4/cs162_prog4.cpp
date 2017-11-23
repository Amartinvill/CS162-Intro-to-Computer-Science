

#include "cs162_list4.h"
using namespace std;

//constroctors

Event_planner::Event_planner()
{
	planner = new agenda[20];
	count = 0;
}


agenda::agenda() //constuctor for the struct
{
	event =NULL;
	term = NULL;
	year = 0;
	event_info = NULL;
	plan_b = NULL;
	optional_info = NULL;

}
//destrustor
Event_planner::~Event_planner()
{
	if(planner)
	 delete[] planner;

}
//obtaining the user's unformation
void Event_planner::New_event()
{

	char temp[SIZE];
		cout <<"Enter the type of event: ";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
		temp[0] = toupper(temp[0]); //uppercase the first letter of the event
		planner[count].event = new char[strlen(temp)+1]; //just the right of memory
		strcpy(planner[count].event,temp); //copying what was in temp now to the name of the information

		cout <<"Enter the term when this will accur: ";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
        	planner[count].term = new char[strlen(temp)+1];
        	strcpy(planner[count].term,temp);

		cout <<"Enter the year when this will be happening: ";
		cin>> planner[count].year;
		cin.ignore(100,'\n');

		cout <<"Enter information about it: ";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
		planner[count].event_info = new char[strlen(temp)+1];
		strcpy(planner[count].event_info,temp);
		
		cout <<"Contengencies? ";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
        	planner[count].plan_b = new char[strlen(temp)+1];
        	strcpy(planner[count].plan_b,temp);
		
		cout<<"Enter optional information: ";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
		planner[count].optional_info = new char[strlen(temp)+1];
		strcpy(planner[count].optional_info,temp);
		++count;
}

//Display all function 
void Event_planner::Display_all()
{
	for(int i = 0; i < count; ++i)// to go through all the events
 	{
		cout << "Event: " << planner[i].event << endl;
		cout << "Term: " << planner[i].term << endl;
		cout << "Year: " << planner[i].year <<endl;
		cout << "Event Information: " <<planner[i].event_info << endl;
		cout << "Contengencies: " << planner[i].plan_b << endl;
		cout << "Optional information: " <<planner[i].optional_info <<endl<<endl; 
	}

}
void Event_planner::Display_tittle() // this funtion will display the names of the event
{
	for(int i=0; i < count; ++i) //will go through all of them
	{ 
		cout <<"Event Name: "<<planner[i].event <<endl;
	}
	cout<<endl<<endl;
}

bool Event_planner::Find_event(char event_name[])//this function will return true if the event is in the list
{
	for(int i=0; i<count; ++i)
	{
		if(strcmp(planner[i].event,event_name) == 0)
			return true;
	}
  return false;

}
void Event_planner::Show_event(char event_name[])// this function wiil display the specific event ask by the user
{
	for (int i = 0; i < count; ++i)
	{
		if(strcmp(planner[i].event,event_name)==0)
		{
			cout << "Event: " << planner[i].event << endl;
			cout << "Term: " << planner[i].term << endl;                              
			cout << "Year: " << planner[i].year <<endl;                               
			cout << "Event Information: " <<planner[i].event_info << endl;            
			cout << "Contengencies: " << planner[i].plan_b << endl;                   
			cout << "Optional information: " <<planner[i].optional_info <<endl<<endl;	
		}
	}
}

//Option Menu function
void Event_planner::Menu()
{
	//local variables
	char response[SIZE]; 
	cout <<endl;
	cout <<"What whould you like to do?" << endl <<endl;
	cout <<"* To display all enter 'ALL' "<< endl; // option one
	cout <<"* To display a certain event enter 'ONE' "<< endl << endl; //option two
	cout <<"Enter your option: ";
	cin.get(response,SIZE,'\n');

	cin.ignore(100,'\n');

	for(int i=0; i<strlen(response)+1; ++i) //incase they enter lower case letter
		response[i]= toupper(response[i]); //this will upper case the word

	if(strcmp(response,"ONE")==0)// if they choose one then
	{
		cout<<"List: " <<endl; // it will display the list of name of events
		Display_tittle(); // so they can just look the them and choose out of one of the tittles
	
		cout <<"What event would you like do be displayed: ";
		cin.get(event_name,SIZE,'\n');
		cin.ignore(100,'\n');
		event_name[0]=toupper(event_name[0]);
		if(Find_event(event_name)) // if the event is in the list
		Show_event(event_name); //display the event and its information
		else
			if(!Find_event(event_name))// if its false the it will display this message
				cout<<"item not in the agenda";	

	}

	if(strcmp(response,"ALL")==0)// if they choose all they all will be displayed
        	Display_all();
}
		
