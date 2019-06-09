/*
Hamed Mirlohi
Implementing Doubly Linked List
*/

#include "doublyLL.h"

int main()
{

	short selection;
	int	dataInput;
	node* head = nullptr;

	while (true)
	{
		populate_menu();
		cout << "Enter your choice: ";
		cin >> selection;

		if (selection == EXIT)
			exit(0);

		if (selection != POP)
		{
			cout << "Enter data: ";
			cin >> dataInput;
		}

		switch (selection)
		{
		case(ADD):
			//add_node(index);
			break;
		case(PUSH):
			push_node(&head, dataInput);
			break;
		case(REMOVE):
			//remove_node(index);
			break;
		case(POP):
			pop_node(&head);
			break;
		case(SEARCH):
			//search_node()
			break;
		default:
			cout << "Bad Input" << endl;
		}
		display_node(head);
	}
}