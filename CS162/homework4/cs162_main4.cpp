#include "cs162_list4.h"


int main()
{
	int count = 0;
	char response = 'Y';
	Event_planner inventory;
	while( (response != 'N') && (count < 20))
	{
		inventory.New_event();
		cout <<"Do you wish to continue? ";// will allowed the user to stop at after they 
		cin >> response;		   // have entered an event, if that is what they wish
		cin.ignore(100,'\n');		   // to do so.
		response = toupper(response);
		++count;
	}
	inventory.Menu(); //will display the menu, in which will ask the used to choose from two options
 	

	return 0;


}
