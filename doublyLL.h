
#include <iostream>

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
	// one node only

	if (head->next == nullptr)
	{
		cout << "node: " << head << " data: " << head->data << endl << endl;
		return;
	}

	// more than one node
	while (head != nullptr)
	{
		cout << "node: " << head << " data: " << head->data << " Previous: " << head->previous << " Next: " << head->next << endl << endl;
		head = head->next;
	}
}

void push_node(node** head, int data)
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
	// 1 node situation
	if ((*head)->next == nullptr)
	{
		(*head)->next = new node;
		(*head)->next->next = nullptr;
		(*head)->next->data = data;
		(*head)->next->previous = *head;
		return;
	}
	// more than 1 node situation
	node* temp = *head;
	while (temp->next != nullptr)
	{
		temp = temp->next;		// go to the next node
	}
	// now we are at the end of the list
	temp->next = new node;
	temp->next->next = nullptr;
	temp->next->data = data;
	temp->next->previous = temp;
	return;
}

void pop_node(node** head)
{
	// no node situation
	if (*head == nullptr)
	{
		cout << "nothing to pop" << endl;
		return;
	}
	// 1 node
		
	if ((*head)->next == nullptr)
	{
		delete *head;
		return;
	}
	// more than 1 node
	node* temp = *head;
	*head = (*head)->next;
	delete temp;
}
