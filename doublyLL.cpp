/*
Hamed Mirlohi
Implementing Doubly Linked List
*/

#include "doublyLL.h"

int main()
{

	short selection;
	int dataInput;
	node* head = nullptr;

	while (true)
	{
		populate_menu();
		cout << "Enter your choice: ";
		cin >> selection;

		if (selection == 9)
			exit(0);

		if (selection != 4)
		{
			cout << "Enter data: ";
			cin >> dataInput;
		}

		switch (selection)
		{
		case(1):
			//add_node(index);
			break;
		case(2):
			push_node(&head, dataInput);
			break;
		case(3):
			//remove_node(index);
			break;
		case(4):
			pop_node(head);
			break;
		case(5):
			//search_node()
			break;
		default:
			cout << "Bad Input" << endl;

		}
		display_node(head);
	}
}