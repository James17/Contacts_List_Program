/*
 * Author: Braeden Mathieson
 * Created: Fall semester 2019
 * Contents of file: main file, menu of program
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()

#include "../Project_3/Contact_functions.h"
using namespace std;

int main()
{
	Contact *head;
	int position;
	char decision;

	head = Read();
	//cout << "Read is done \n";

	cout<<"Welcome to contacts!\n";
	cout<<"What would you like to do?\n";
	cout<<"Enter the letter for your decision \n\n";

	while(true)
	{
		cout<<"Menu:\n";
		cout<<"  [R]ead   [W]rite  [S]how   [I]nsert\n";
		cout<<"  [D]elete [U]pdate [T]oggle [Q]uit\n\n";
		cin>>decision; cin.ignore();
		decision = tolower(decision);

		switch(decision)
		{
			case 'r':
				head = Read();
				cout << "Read is done. \n";
				break;
			case 'w':
				Write(head);
				cout << "Write is done. \n";
				break;
			case 's':
				Show(head);
				cout << "Show is done. \n";
				break;
			case 'i':
				cout<<"Insert contact at what position? \n";
				cin>>position; cin.ignore();
				head = Insert(head, position);
				cout<<"Insert is done. \n";
				break;
			case 'd':
				cout<<"Delete contact at what position? \n";
				cin>>position; cin.ignore();
				head = Delete(head, position);
				cout<<"Delete is done. \n";
				break;
			case 'u':
				cout<<"Update contact at what position? \n";
				cin>>position; cin.ignore();
				head = Update(head, position);
				cout<<"Update is done. \n";
				break;
			case 't':
				cout<<"Toggle ICE at what position \n";
				cin>>position; cin.ignore();
				Toggle(head, position);
				cout<<"Toggle is done \n";
				break;
			case 'q':
				Quit();
				break;
			default:
				break;
		}
	}
	return 0;
}
