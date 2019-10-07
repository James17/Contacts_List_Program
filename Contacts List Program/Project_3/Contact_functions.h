/*
 * Author: Braeden Mathieson
 * Created: Fall semester 2019
 * Contents of file: data structure and function prototypes
 */

#ifndef PROJECT_3_CONTACT_FUNCTIONS_H_
#define PROJECT_3_CONTACT_FUNCTIONS_H_

#include <iostream>
#include <string>
using namespace std;

	struct Contact{
		string name;
		string number;
		string email;
		bool ice;
		Contact *next_address;
	};

Contact *Read();
void Write(Contact *head);
void Show(Contact *head);
Contact *Insert(Contact *head, int position);
Contact *Delete(Contact *head, int position);
Contact *Update(Contact *head, int position);
void Toggle(Contact *head, int position);
void Quit();

#endif /* PROJECT_3_CONTACT_FUNCTIONS_H_ */
