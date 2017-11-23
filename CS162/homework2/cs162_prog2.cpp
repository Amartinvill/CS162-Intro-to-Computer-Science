/*
Angel Martinez
Homework 2

Purpose:
The purpose of this assigment is to get a better enderstanding of arrays of characters, 
and practince more with loops and if statements, as well as the functions.

Steps:
step one: make a fuction to uppercase characters
		i. can be use to upper case some conditions in the assignments.
step two: make a function to return the number of cases in a character array
step three: make a function that returns true or false
		i. can be use to repetition
step four: make a fuction that compares two words
		i. can be use to take two words and see if the have the same content
*/
#include <iostream> 
using namespace std;

//prototypes
char to_upper(char letter);
bool again();
int  str_compare(char word1[], char word2[]);
void menu(char phrase[]);
int length( char letter[]);
void prompt(const char prompt[], char phrase[], int SIZE);
void toupper_first_letter(char phrase[]);
void toupper_all_first_letters( char phrase[]);
void toupper_all_letters(char phrase[]);
void caps_after_ponctuation(char phrase[]);
void comp_arrays(char word1[], char word2[]);
//constans
const int SIZE = 131;

int main()
{
	char phrase[SIZE];
	char word1[SIZE];
	char word2[SIZE];
	char response = 'Y';
	do
	{
		prompt("Enter a phrase no more than 131 characters: ",phrase,SIZE);
		menu(phrase); //display a menu of the first three conditions
		cout<<phrase << endl<<endl;
		prompt("Enter a phase with '.' or '!' or '?' and no more than 130 characters: ",phrase,SIZE);
		caps_after_ponctuation(phrase);
		cout <<phrase << endl;
		cout<<endl<< endl;
		comp_arrays(word1,word2);
	}while(again()); // will do this everytime they enter 'y'.

  return 0;
}

void caps_after_ponctuation(char phrase[])// capitalize the first word after an '!', a '?' and '.'.
{
	for(int i=0;i<length(phrase);++i)
	{ 
		if(phrase[i]=='.' || phrase[i]=='!' || phrase[i]=='?')
		{
			for(++i;phrase[i]==' ';++i); 
			phrase[i]=to_upper(phrase[i]);
		}
	}
}

void toupper_all_letters(char phrase[])// will upper al the letters
{
	for(int i=0; i<length(phrase); ++i)
		phrase[i] = to_upper(phrase[i]);
}

void toupper_all_first_letters( char phrase[])// will upper the first letter after a space.
{
	phrase[0] = to_upper(phrase[0]);
	for(int i=0; phrase[i]!='\0'; ++i)
	{
		if(phrase[i] == ' ')
			phrase[i+1] = to_upper(phrase[i+1]);
	}
}

void toupper_first_letter(char phrase[])// will upper the first letter of the phrase.
{
	phrase[0] = to_upper(phrase[0]);

}

void prompt(const char prompt[], char phrase[], int SIZE)// i can use this multiple times
{
	cout <<prompt;
	cin.get(phrase,SIZE,'\n');
	cin.ignore(100,'\n');
	
}

bool again()//i can use this multipletime to repeate thigs
{
	char response;
	cout <<"Again? (Y/N): ";
	cin>> response;
	cin.ignore(100,'\n');
	if('Y' == to_upper(response))
		return true;
	return false;
}

int  str_compare(char word1[], char word2[])
{
	int i;
	for(i = 0; word1[i]!='\0' && word2[i]!='\0' && word1[i] == word2[i]; ++i);// loops untill they each phase hits the '\0' and are equal to each other.
	return word1[i]-word2[i];

}

void comp_arrays(char word1[], char word2[])
{
	cout<<"Enter two word to see if the have the same context"<< endl;
	cout<<"Enter first word: ";
	cin.get(word1,SIZE,'\n');
	cin.ignore(100,'\n');
	toupper_all_letters(word1);
	cout<<"Enter second word: ";
	cin.get(word2,SIZE,'\n');
        cin.ignore(100,'\n');
        toupper_all_letters(word2);
	if(str_compare(word1,word2)==0)
		cout<<"The words you enter match!"<< endl;
	else
		cout<<"The words you enter do not match."<< endl;
	

}
void menu(char phrase[]) // displays a menu
{
	int response;
	cout<<"Enter '1' to capitalize only the first letter" <<endl;
	cout<<"Enter '2' to capitalize the first letter in each word"<<endl;
	cout<<"Enter '3' to capitalize each letter" << endl <<endl;
	
	cout <<"What do you wish to do? ";
	cin>> response;
	cin.ignore(100,'\n');
	
	if(response == 1)
		toupper_first_letter(phrase);
	else if(response == 2)
		toupper_all_first_letters(phrase);
	else if(response == 3)
		toupper_all_letters(phrase);
	else 
		cout <<"Invalid number!!" << endl<< endl;	
}

int length(char letter[])
{
	int count = 0;
	for(; letter[count]!='\0'; ++count);
	

  return count;
}

char to_upper(char letter) //will uppercase character arrays
{
	if(letter >= 'a' && letter <='z') 
		letter = letter - 32;
	return letter;
}
