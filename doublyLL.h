
#include <iostream>
#include "ConsoleColor.h"

using namespace std;

enum MODES
{
	ADD = 1,
	PUSH,
	REMOVE,
	POP,
	SEARCH,
	EXIT = 9,
};

struct node
{
	int data;
	node* next;
	node* previous;
};

void populate_menu()
{
	cout << "1. Add Node: " << endl;
	cout << "2. Push Node: " << endl;
	cout << "3. Remove Node: " << endl;
	cout << "4. Pop Node:" << endl;
	cout << "5. Search: " << endl;
	cout << "9. Exit" << endl;
}

void display_node(node* head)
{
	// no nodes to display
	if(head == nullptr)
	{
		cout << "Nothing to Display\n" << endl;
		return;
	}
	// one node or more

	node* tmp = head;
	while (tmp != nullptr)
	{
		cout << red << "node: " << tmp << blue <<" data: " << tmp->data << yellow << " Previous: " << tmp->previous <<
			green << " Next: " << tmp->next << endl << endl << white;
		tmp = tmp->next;
	}
}

node* push_node(node* head, int data)
{
	// 0 node situation
	if (head == nullptr)			
	{
		head = new node;
		head->data = data;
		head->next = nullptr;
		head->previous = nullptr;
		return head;
	}
	
	// 1 or more than 1 node situation
	node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;		// go to the next node
	}

	// now we are at the end of the list
	node* tmp2 = tmp;
	tmp = new node;
	tmp->data = data;
	tmp->next = nullptr;
	tmp->previous = tmp2;
	tmp2->next = tmp;

	return head;
}

node* pop_node(node* head)
{
	// no node situation
	if (head == nullptr)
	{
		cout << "nothing to pop" << endl;
		return nullptr;
	}

	// 1 node situation
	if (head->next == nullptr)
	{
		delete head;
		return nullptr;
	}
	// more than 1 node
	node* temp = head;
	head = head->next;
	delete temp;
	return head;
}




node* add_node(node* head, const int index, const int data)
{
	// 0 node situation
	if (head == nullptr)
	{
		head = push_node(head, data);
		return head;
	}

	// index 0 situation
	if (index == 0)
	{
		node* temp = head;
		head = new node;
		head->data = data;
		head->next = temp;
		head->previous = nullptr;
		head->next->previous = head;
		return head;
	}
	// search for index
	uint16_t count = 0;
	node* tmp = head;
	while (tmp != nullptr)
	{
		if (count == index)
		{
			node* tempRewind = tmp->previous;
			node* tempForward = tmp;
			tmp = new node;
			tmp->data = data;
			tmp->previous = tempRewind;
			tmp->next = tempForward;
			tmp->previous->next = tmp;
			tempForward->previous = tmp;
			return head;
		}
		++count;
		tmp = tmp->next;
	}
	// forced to add to the end the list
	head = push_node(head, data);
	return head;
}

// remove node depending on give data
node* remove_node(node* head, int data)
{
	// no node situation
	if (head == nullptr)
	{
		cout << "Nothing to Delete" << endl;
		return nullptr;
	}
	// single node situation
	if (head->next == nullptr)
	{
		// the single node is the target, blank LLL return nullptr
		if (head->data == data)
		{
			delete head;
			return nullptr;
		}
		// no data match, nothing to change
		return head;
	}

	// more than one node situation
	node* tmp = head;
	
	while (tmp != nullptr)
	{
		if (tmp->data == data)
		{
			// last node situation
			if (tmp->next == nullptr)
			{
				tmp->previous->next = nullptr;
				delete tmp;
				return head;
			}
			else if (tmp->previous == nullptr)
			{
				// update head since we are deleting the first element
				head = head->next;
				head->previous = nullptr;
				delete tmp;
				return head;
			}
			else
			{
				tmp->previous->next = tmp->next;
				tmp->next->previous = tmp->previous;
				delete tmp;
				return head;
			}
		}

		tmp = tmp->next;
	}

	// no match found, no change
	return head;
}