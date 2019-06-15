
#include <iostream>
#include <windows.h>

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
		cout << "node: " << tmp << " data: " << tmp->data << " Previous: " << tmp->previous << " Next: " << tmp->next << endl << endl;
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



/*
void add_node(node** head, int index, int data)
{
	// 0 node situation
	if (*head == nullptr)
	{
		*head = new node;
		(*head)->data = data;
		(*head)->next = nullptr;
		(*head)->previous = nullptr;
		return;
	}
	
	// more than one node
	//node* temp1 = *head;
	int traverse = 0;

	while (*head != nullptr)
	{

		if (index == traverse)
		{
			node* temp2 = *head;
			node* temp1 = (*head)->previous;
			*head = new node;
			(*head)->data = data;
			(*head)->next = temp2;
			(*head)->previous = temp1;
			(*head)->next->previous = (*head);
			(*head)->previous->next = (*head);
			return;
		}

		*head = (*head)->next;
		++traverse;
	}
	// index is out of bound, just push the item at the end of the list
	push_node(head, data);
	return;
}


void remove_node(node** head, int data)
{
	// no node situation
	if (*head == nullptr)
	{
		cout << "Nothing to Delete" << endl;
		return;
	}
	// single node situation
	if ((*head)->next == nullptr)
	{
		if((*head)->data == data)
			delete *head;
		return;
	}
	// more than one node situation
	node* temp1 = *head;
	node* temp2 = (*head)->next;

	while (temp2 != nullptr)
	{
		// if data found
		if (temp2->data == data)
		{
			// remove node and return
			temp1 = temp2->next;
			delete temp2;
			return;
		}
		temp1 = temp2;
		temp2 = temp2->next;
	}
	// no match found, return
	return;

}
*/