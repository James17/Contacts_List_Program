/*
 * Author: Braeden Mathieson
 * Created: Fall semester 2019
 * Contents of file: all functions for program
 */
#include "../Project_3/Contact_functions.h"

#include <fstream> // file manipulation
#include <iomanip>

// input: n/a
// output a pointer to the head of the linked-list
// description: reads the content of the input file “contacts.txt” and builds the linked-list
Contact *Read()
{

	ifstream inFile;					// make file "object"
	inFile.open("contacts.txt");		// name file with file type (.txt)

	if (inFile.fail())			// test for fail in opening file
	{
		cout << "\nThe contacts file did not successfully open... Program Terminated\n" << endl;
		exit (1);				// exit program if failed
	}

	Contact *current, *head;
	current = new Contact;
	head = current;

	while(not(inFile.eof()))
	{
		getline(inFile, current->name);
		getline(inFile, current->number);
		getline(inFile, current->email);
		inFile >> current->ice; inFile.ignore();

//		cout<<current->name<<" " <<endl;
//		cout<<current->number<<" " <<endl;
//		cout<<current->email<<" " <<endl;
//		cout<<current->ice<<" " <<endl;

		if(not(inFile.eof()))
		{
			current->next_address = new Contact;
			current = current->next_address;
		}
		else current->next_address = NULL;

	}
	inFile.close();

	return(head);
}
// input: a pointer to the head of the linked-list
// output: void
// description: writes the content of the link-list to the output file “contacts_updated.txt”
void Write(Contact *head)
{
	ofstream outFile;
	outFile.open("contacts_updates.txt");


	Contact *current = head;

	outFile << "Contacts: \n";
	while(current != NULL)
	{
		outFile << current->name << endl;
		outFile << current->number << endl;
		outFile << current->email << endl;
		outFile << current->ice << endl;
		current = current->next_address;
	}
	//outFile << endl;
	outFile.close();
}
// input: a pointer to the head of the linked-list
// output: void
// description: displays the content of the contact list to the screen. The output should be neatly organized
void Show(Contact *head)
{
	Contact *current = head;
	int count = 1;

	cout << "Contacts: \n";
	while(current != NULL)
	{
		cout << right << setw(5) << count << "] ";
		cout << left << setw(21) << current->name;
		cout << left << setw(12) << current->number << "  ";
		cout << setw(22) << current->email;
		if(current->ice == 1) cout << "<-- Emergency Contact";
		cout << endl;
		current = current->next_address;
		count++;
	}
}
// input: a pointer to the head of the linked-list and the position to insert
// output: a pointer to the head of the linked-list
// description: prompts the user to enter the contact information and inserts this information
// in the linked-list at the position entered
Contact *Insert(Contact *head, int position)
{
	Contact *temp, *current, *previous;
	temp = new Contact;
	current = head;

	cout<<"Enter the name \n"; getline(cin, temp->name);
	cout<<"Enter the number \n"; getline(cin, temp->number);
	cout<<"Enter the email \n"; getline(cin, temp->email);
	cout<<"Enter '1' or emergency contact and '0' for not \n";
	cin >> temp->ice; cin.ignore();

	cout<<"ice is: " << temp->ice<< endl;

	if(position == 1)
	{
		temp->next_address = head;
		head = temp;
	}
	else
	{
		for(int i=1; i<position; i++)
		{
			previous = current;
			current = current->next_address;
		}
		temp->next_address = current;
		previous->next_address = temp;
	}
	return(head);
}
// input: a pointer to the head of the linked-list and the position to delete
// output: a pointer to the head of the linked-list
// description: deletes the information from the linked-list at the position entered
Contact *Delete(Contact *head, int position)
{
	Contact *current, *previous;

	current = head;

	if (position==1)
	{
		head = current->next_address;
	}
	else
	{
		for (int i=1; i<position; i++)
		{
			previous = current;
			current = current->next_address;
		}
		previous->next_address = current->next_address;
	}
	delete(current);
	return(head);
}
// input: a pointer to the head of the linked-list and the position to update
// output: a pointer to the head of the linked-list
// description: prompts the user to enter the contact information and updates
// this information in the linked-list at the position entered
Contact *Update(Contact *head, int position)
{
	Contact *temp, *traverse;
	temp = new Contact;
	traverse = head;

	cout<<"Enter the name \n"; getline(cin, temp->name);
	cout<<"Enter the number \n"; getline(cin, temp->number);
	cout<<"Enter the email \n"; getline(cin, temp->email);
	cout<<"Enter '1' or emergency contact and '0' for not \n";
	cin >> temp->ice; cin.ignore();


	for(int i=0; i<position-1; i++)
	{
		traverse = traverse->next_address;
	}
	traverse->name = temp->name;
	traverse->number = temp->number;
	traverse->email = temp->email;
	traverse->ice = temp->ice;
	return(head);
}
// input: a pointer to the head of the linked-list and the position to toggle
// output: n/a
// description: toggles (true -> false or false -> true) the ICE flag at the position entered
void Toggle(Contact *head, int position)
{
	Contact *traverse;
	traverse = head;

	for(int i=0; i<position-1; i++)
	{
		traverse = traverse->next_address;
	}
	traverse->ice == 1 ? traverse->ice = 0 : traverse->ice = 1;
}
// description: exits the program
void Quit()
{
	exit(1);
}


