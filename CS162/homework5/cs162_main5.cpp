#include "cs162_list5.h"
using namespace std;
int main()
{
	char event_name[SIZE];
	char response = 'n';
	int num;
	int count = 0;
	Event_planner planner;
	
	//do this while user still wants to add to list and  count < 20
	do
	{
		planner.Insert_data();
		cout<<"Do you wish to add to the agenda again (y/n): ";
		cin>>response;
		cin.ignore(100,'\n');
		response = tolower(response);
	}while('y'==response && count < 20);
	cout<<"*** Enter 1 for display none flagged events"<<endl;
	cout<<"*** Enter 2 for display flagged events"<<endl<<endl;
	
	cout<<"Choose an option: ";
	cin>>num;
	if(num==1)
	{
		planner.Display_all_events();
	}
	else if(num==2)
	{	
		planner.Display_flagged();
		cout<<"Would you like to delete a flagged event (y/n); ";
		cin>>response;
		cin.ignore(100,'\n');
		response=tolower(response);
		if('y'==response)
		{
			cout<<"Enter event to remove: ";
			cin.get(event_name,SIZE,'\n');
			cin.ignore(100,'\n');
			event_name[0] = tolower(event_name[0]);
			if(planner.Event_complete(event_name))
				planner.Display_flagged();

		}
	}	
	
        return 0;
}

