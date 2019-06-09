/*
Hamed Mirlohi
Implementing Doubly Linked List
*/

#include "doublyLL.h"

int main()
{

	short selection;
	int	dataInput;
	int index;
	node* head = nullptr;

	while (true)
	{
		populate_menu();
		cout << "Enter your choice: ";
		cin >> selection;

		switch (selection)
		{
		case(ADD):
			cout << "Enter data: ";
			cin >> dataInput;
			cout << "Enter position index: ";
			cin >> index;
			add_node(&head,index,dataInput);
			break;
		case(PUSH):
			cout << "Enter data: ";
			cin >> dataInput;
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
		case(EXIT):
			exit(0);
			break;
		default:
			cout << "Bad Input" << endl;
		}
		display_node(head);
	}
}