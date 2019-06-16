/*
Hamed Mirlohi
Implementing Doubly Linked List
*/

#include "doublyLL.h"

int main()
{

	int selection;	// menu select
	int	dataInput;		// user data
	int index;			// in case of adding node/data
	node* head = nullptr;

	while (true)
	{
		populate_menu();
		cout << "Enter your choice: ";
		cin >> selection;

		while (cin.fail())
		{
			cout << "not a number" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> selection;
		}
		

		switch (selection)
		{
		case(ADD):
			cout << "Enter data: ";
			cin >> dataInput;
			cout << "Enter position index: ";
			cin >> index;
			head = add_node(head,index,dataInput);
			break;
		case(PUSH):
			cout << "Enter data: ";
			cin >> dataInput;
			head = push_node(head, dataInput);
			break;
		case(REMOVE):
			cout << "Enter data: ";
			cin >> dataInput;
			head = remove_node(head, dataInput);
			break;
		case(POP):
			head = pop_node(head);
			break;
		case(SEARCH):
			cin >> dataInput;
			index = search_node(head, dataInput);
			if(index > -1)
				cout << purple << dataInput << " is located in index: " << index << white << endl << endl;
			break;
		case(EXIT):
			exit(0);
			break;
		default:
			cout << "Bad Input" << endl;
		}
		display_node(head);
	}
}