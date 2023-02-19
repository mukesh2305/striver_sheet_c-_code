
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};
Node* insertAtEmpty(Node *last, int data) {
	// if last is not null then list is not empty, so return
	if (last != NULL) return last;

	// allocate memory for node
	Node *temp =  new Node(data);
	last = temp;

	// create the link
	last->next = temp;
	return last;
}

Node* insertAtBegin(Node *last, int data) {
	
	// if list is empty then add the node by calling insertInEmpty
	if (last == NULL) return insertAtEmpty(last, data);

	// else create new node
	Node *temp = new Node(data);

	temp->next = last->next;
	last->next = temp;
	return last;
}


void printList(Node* head)
{
	Node* temp = head;
	if (head != NULL) {
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}

	cout << endl;
}

/* Function to delete a given node from the list */
void deleteNode(Node** head, int key)
{
	
	// If linked list is empty
	if (*head == NULL)
		return;
		
	// If the list contains only a single node
	if((*head)->data==key && (*head)->next==*head)
	{
		free(*head);
		*head=NULL;
		return;
	}
	
	Node *last=*head,*d;
	
	// If head is to be deleted
	if((*head)->data==key)
	{
		
		// Find the last node of the list
		while(last->next!=*head)
			last=last->next;
			
		// Point last node to the next of head i.e.
		// the second node of the list
		last->next=(*head)->next;
		free(*head);
		*head=last->next;
	return;
	}
	
	// Either the node to be deleted is not found
	// or the end of list is not reached
	while(last->next!=*head&&last->next->data!=key)
	{
		last=last->next;
	}
	
	// If node to be deleted was found
	if(last->next->data==key)
	{
		d=last->next;
		last->next=d->next;
		free(d);
	}
	else
		cout<<"no such keyfound";
	}

/* Driver code */
int main()
{
	/* Initialize lists as empty */
	Node* last = NULL;

	/* Created linked list will be 2->5->7->8->10 */
	last = insertAtEmpty(last, 2);
	last = insertAtBegin(last, 5);
	last = insertAtBegin(last, 7);
	last = insertAtBegin(last, 8);
	last = insertAtBegin(last, 10);

	cout << "List Before Deletion: ";
	printList(last);

	deleteNode(&last, 5);

	cout << "List After Deletion: ";
	printList(last);

	return 0;
}

// This is code is contributed by rathbhupendra
