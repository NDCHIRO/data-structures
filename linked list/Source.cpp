#include <iostream>
#include <string>
using namespace std;

int counter = 0;
struct Node
{
	string data;
	int count ;
	Node* next;
};


Node* head = new Node;

bool checkHeadExists(Node* node)
{
	if (node != NULL)
		return 1; //head exists
	else
		return 0; //head does not exist
}

void insertAtBegin(string data)
{
	Node* newNode = new Node;
	if (!checkHeadExists(head))
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	newNode->data = data;
	newNode->count = counter++;
}

//as its a single linked list so we have to go from head to the last node to remove it
void removeLast(Node* head)
{	//if list is empty
	if (!checkHeadExists(head))
		cout << "list is already empty, nothing to be removed" << endl;
	else
	{
		Node* firstPtr = head;
		Node* secondPtr = head;
		while (firstPtr->next != NULL)
		{
			secondPtr = firstPtr;
			firstPtr = firstPtr->next;
		}
		//if there is only 1 node n the list which is the head
		if (firstPtr == head)
		{
			head = NULL;
			firstPtr = NULL;
			secondPtr = NULL;

		}
		secondPtr->next = NULL;
		firstPtr = NULL;
	}
}

void printList(Node* head)
{
	Node* tempNode = head;
	if (!checkHeadExists(head))
	{
		cout << "list is empty" << endl;
		return;
	}
	//print until the current ptr is null
	while (tempNode != NULL)
	{
		cout << "data: " << tempNode->data << " count: " << tempNode->count << endl;
		tempNode = tempNode->next;
	}

}

int main()
{
	head->count = counter++;
	head->data = "hallo0";
	head->next = NULL;

	insertAtBegin("hallo1");
	insertAtBegin("hallo2");
	insertAtBegin("hallo3");
	printList(head);
	cout << "-----------remove------------" << endl;
	removeLast(head);
	printList(head);
}