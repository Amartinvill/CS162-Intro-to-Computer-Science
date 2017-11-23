//Angel Martinez
//cs162 homework3

//algorythm
/*
1. Make a stuctrure
        i. add all menbers asked in the assignment
        ii. create constant variables for the size
2. Prompt the user for the event types
        i. event name,term,date,info,other info, ect. 
3. display the events
        i. create a funtion to echo the user information
                a) create an array of the structure type to be used
        ii. create a function to loop the array up to 20
                a)ask the user if the want to quit at a certain point
        iii. ask the user if they want to display events
                a) if all, create function to loop up to 20
                b) if only a cairtain type, create a function to compare what the user wants
4. make a function to load from a file 
5. make a function to write to a file
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

//size of arrays
const int EVENT = 41;
const int TERM = 21;
const int DESCRIP = 151; // description size
const int OPTIONS = 151; //conteingencies size 
const int OPTINFO = 151; //optional Information size

//structure
struct agenda
{
        char event[EVENT];
        char term[TERM];
        int year;
        char event_info[DESCRIP];
        char plan_b[OPTIONS];
        char optional_info[OPTINFO];

};

//prototypes
void read_display(agenda planner);
void read_display_all(agenda planner[], int count);                                       
void read_prompt(const char prompt[],char temp[], int size);                              
void read_planner(agenda & planner);
int read_all(agenda array[], int count);
void load_from_file(agenda planner[], int & count);
void save_in_file(agenda planner[], int count);
void display_event_asked(agenda planner[], int count);
void menu(agenda planner[], int count);

int main()
{
        int count = 0;
        agenda planner[20];
        load_from_file(planner, count);
        count  =read_all(planner, count);
        menu(planner,count);
        save_in_file(planner, count);

  return 0;
}

void menu(agenda planner[], int count) // A menu to pick one of the display options.
{
        char response[5];

        if(count>=2)
        {
                cout <<"Enter 'all' to display all events"<<endl;
                cout <<"Enter 'one' to display a particular event" <<endl;
                cout <<"Enter choice: ";
                cin.get(response,5,'\n');
                cin.ignore(100,'\n');
                for(int j=0;j!='\0';++j)
                        response[j]=tolower(response[j]);
                if(strcmp(response,"one")==0) //compares if the response equals to 'one' then pisplay event asked
                        display_event_asked(planner,count);
                else if(strcmp(response,"all")==0)// compares if the response equals to 'all' then displays all events.
                        read_display_all(planner,count);

        }
        else read_display_all(planner,count); //display event incase they only enter one.


}


void display_event_asked(agenda planner[], int count) //displays a perticular event from the user
{
        char response[31];


        cout << "What particular type of event would you like to be displayed? ";
        cin.get(response,31,'\n');
	cin.ignore(100,'\n');

        //for loop through all events
        for(int i=0; i < count; ++i)
        {
                if(strcmp(response,planner[i].event)==0) //compares of what the user is asking is in the array.
                        read_display(planner[i]);
        }

}

void load_from_file(agenda planner[], int & count)
{
        ifstream load_in; // variable
        int i = 0;
        load_in.open("planner.txt"); //  external file, where thing go in.
        if(load_in) // if the file exist do the following otherwise don't do anything.
        {
                while(!load_in.eof() && i < 20)
                {
                        load_in.get(planner[i].event,EVENT,'\t');
                        load_in.ignore(100,'\t');
                        load_in.get(planner[i].term,TERM,'\t');
                        load_in.ignore(100,'\t');
                        load_in>>planner[i].year;
                        load_in.ignore(100,'\t');
                        load_in.get(planner[i].event_info,DESCRIP,'\t');
                        load_in.ignore(100,'\t');
                        load_in.get(planner[i].plan_b,OPTIONS,'\t');
                        load_in.ignore(100,'\t');
                        load_in.get(planner[i].optional_info,OPTINFO,'\n');
                        load_in.ignore(100,'\n');
                        ++i;
                }
                load_in.close();
                load_in.clear();
        }else  // in case there is no file count should still be 0.
        {
                count = 0;
                return;
        }
        count = i-1;
}

void save_in_file(agenda planner[], int count)
{
        ofstream save_in; // variable
        save_in.open("planner.txt"); // external file name
        if(save_in)
        {
                for(int i=0; i < count; ++i)
                {
                        save_in << planner[i].event << '\t';
                        save_in << planner[i].term << '\t';
                        save_in << planner[i].year << '\t';
                        save_in << planner[i].event_info << '\t';
                        save_in << planner[i].plan_b << '\t';
                        save_in << planner[i].optional_info << '\n';
                }
        }

}

void read_prompt(const char prompt[],char temp[], int size) //shotcut to not write this over and over again.
{
        cout <<prompt;
        cin.get(temp, size, '\n');
        cin.ignore(100,'\n');

}

void read_planner(agenda & planner) // prompts the user to enter the elements in the structures.
{
        read_prompt("Enter the type of event: ",planner.event, EVENT);
        read_prompt("Enter the term when this will accur: ",planner.term, TERM);
        cout<<"Enter the year when this will be happening: ";
        cin>>planner.year;
        cin.ignore(100,'\n');
        read_prompt("Enter information about it: ", planner.event_info, DESCRIP);
        read_prompt("Contengencies? ",planner.plan_b,OPTIONS);
        read_prompt("Enter any optional Information: ", planner.optional_info, OPTINFO);
        cout << endl;

}

int read_all(agenda array[], int count) // reads array up to 20.
{
        char response = 'Y';
        for (;count < 20 && response != 'N'; ++count) // when count is less than 20 or the user wants to stop. 
        {
                cout << "Activity # " << count +1 <<endl << endl; //add one to count because the array starts counting at 0.
                read_planner(array[count]);
                if(count < 19) //when the user adds the second to last event it should ask to add activity again and not ofter the last one. 
                {
                        cout <<"Do you wish to add another activity? (Y/N): ";
                        cin >> response;
                        cin.ignore(100,'\n');
                        response = toupper(response);
                        cout << endl;
                }
        }
        return count; //return the number of arrays.
}


void read_display(agenda planner) //displays everything once
{
        cout << planner.event <<endl;
        cout << planner.term <<endl;
        cout << planner.year <<endl;
        cout << planner.event_info <<endl;
        cout << planner.plan_b <<endl;
        cout << planner.optional_info <<endl;
}
void read_display_all(agenda planner[], int count) //display all events
{
        for(int i = 0; i < count; ++i) // Display up to how many events the user entered. 
        {
                 cout << "Acivity number # " << i+1 << endl << endl;
                 read_display(planner[i]);
        }
}

