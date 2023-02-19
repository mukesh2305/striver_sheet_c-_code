#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////

struct Node {
	int data ;
	Node *next; // because of this we called this structure , self refrencing structure
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// 1st way to represent
void solve_Node() {
	Node *head = new Node(10);
	Node *temp1 = new Node(20);
	Node *temp2 = new Node(30);
	head->next = temp1;
	temp1->next = temp2;

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// 2nd way to represent
// linked list traversal
void print_linkedList(Node *head) { // here pointer variables are copied when we make function call
	// so main head variable is not modified local head variable this one is modified
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// /////////////////////////////
// traverse linked list using recursion
void recurPrrint_linkedList(Node *head) {
	if (head == NULL) return ;
	cout << head->data << " ";
	recurPrrint_linkedList(head->next);
}

// reverse the linked list
void print_linkedList1(Node *head) {
	Node *newHead = NULL;
	while (head != NULL) {
		Node *next = head->next;
		head->next = newHead;
		newHead = head;
		head = next;
	}

	while (newHead != NULL) {
		cout << newHead->data << " ";
		newHead = newHead->next;
	}

}


///////////////////////////////////////////////////////////////////////
// insertion of the beginning of singly linked list
// 10->20->30->NULL => given
// 5->10->20->30->NULL => do this

void insert_begin(Node * head) {
	Node *newNode = new Node(5);
	newNode->next = head;
	head = newNode;

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

Node* insert_begin1(Node * head, int x) {
	Node *temp = new Node(x);
	temp->next = head;
	return temp;
}
/////////////////////////////////////////////////////////
void insert_end(Node * head, int x) {
	Node *temp = new Node(x);

	if (head == NULL) return;

	Node *curr = head;

	while (curr->next != NULL)
		curr = curr -> next;
	curr->next = temp;

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// insert at particular position
///////////////////////////////////
Node* insert_pos(Node *head, int x, int pos) {
	Node *temp = new Node(x);
	if (pos == 1) {
		temp->next = head;
		return temp;
	}
	Node *curr = head;
	int i = 1;
	while (i <= pos - 2 && curr != NULL) {
		curr = curr->next;
		i++;
	}
	if (curr == NULL) return head;

	temp->next = curr->next;
	curr->next = temp;
	return head;
}

// 1 2 '1' 3 4
////////////////////////////////////////////////////////////
// singly delete first node
void delete_first(Node *head) {
	if (head != NULL) {
		Node *temp = head->next;
		head = temp;
		while (head != NULL) {
			cout << head->data << " ";
			head = head->next;
		}
	}
}
Node* delete_first1(Node *head) {
	if (head == NULL) return NULL;
	Node *temp = head->next;
	delete head;
	return temp;
}


//////////////////////////////////////////////////////
// delete last not in the singly linked list
void delete_last(Node *head) {
	if (head != NULL) {
		if (head->next == NULL) {
			delete head;
			return;
		}
		Node *curr = head;
		while (curr->next->next != NULL)
			curr = curr->next;
		delete curr->next;
		curr->next = NULL;

		while (head != NULL) {
			cout << head->data << " ";
			head = head->next;
		}
	}
}

// delete pos the node
Node* delete_pos(Node *head, int pos) {
	if (head == NULL) return NULL;

	// store head node
	Node *temp = head;

	// if head needs to be removed
	if (pos == 1) {
		head = temp->next;
		delete temp;
		return head;
	}

	// find pervious node of the node to be deleted
	int i = 1;
	while (i <= pos - 2 && temp != NULL) {
		temp = temp->next;
		i++;
	}

	// if position is more than number of nodes
	if (temp == NULL || temp->next == NULL) return temp;
	Node *next = temp->next->next;
	delete temp->next;
	temp->next = next;
	return head;
}

Node* delete_last1(Node *head) {
	if (head == NULL) return NULL;

	if (head->next == NULL) {
		delete head;
		return NULL;
	}

	Node *curr = head;
	while (curr->next->next != NULL)
		curr = curr->next;
	delete curr->next;
	curr->next = NULL;
	return head;
}

///////////////////////////////////////////////////////////
// search in the linked list recursively / interativeley
int search(Node *head, int x) {
	int cnt = 1;
	while (head != NULL) {
		if (head->data == x) return cnt;
		cnt++;
		head = head->next;
	}
	return -1;
}

int revursive_search(Node *head, int x, int cnt) {
	if (head == NULL)  return -1;
	Node *curr = head;
	if (curr->data == x) return cnt;
	return revursive_search(curr->next, x, cnt + 1);
}

int revursive_search1(Node *head, int x) {
	if (head == NULL)  return -1;

	if (head->data == x) return 1;
	else {
		int res = revursive_search1(head->next, x);
		if (res == -1) return -1;
		else return res + 1;
	}
}

// 10 20 30 40
// 1  2  3  4


void solve_Node1() {
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	head->next->next->next = new Node(40);
	// print_linkedList(head); cout << endl;
	// print_linkedList(head);
	// recurPrrint_linkedList(head);
	// print_linkedList1(head);
	// insert_begin(head);


	// ----------------------- insert at begining ---------------------------
	// head = insert_begin1(head, 5);
	// while(head != NULL) {
	// 	cout << head->data << " ";
	// 	head = head->next;
	// }


	// ----------------------- insert at position ---------------------------
	// head = insert_pos(head, 25, 7);
	// while (head != NULL) {
	// 	cout << head->data << " ";
	// 	head = head->next;
	// }

	// ------------------------- insert at the end ----------------------
	// insert_end(head, 5);

	// ------------------------- delete at the first ----------------------
	// delete_first(head);
	// head = delete_first1(head);
	// while (head != NULL) {
	// 	cout << head->data << " ";
	// 	head = head->next;
	// }

	// ------------------------- delete at the last ----------------------------
	// delete_last(head);
	// head = delete_last1(head);
	// while (head != NULL) {
	// 	cout << head->data << " ";
	// 	head = head->next;
	// }

	// ------------------------ delete between the list ---------------------------
	head = delete_pos(head, 40);
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}

	// ------------------------- search in linked recursively / iteratively --------------------
	// cout << search(head, 20) << endl;
	// cout << revursive_search(head, 50, 1) << endl;
	// cout << revursive_search1(head, 40);
}


// ************************************************************************************
///////////////////////////////////////////////////////////////////
// ----------------- doubly LinkedList -------------------------------

struct node {
	int data;
	node *prev;
	node *next;

	node(int d) {
		data = d;
		prev = NULL;
		next = NULL;
	}
};

node* push_back(node *head, int x) {
	node *newNode = new node(x);
	if (head == NULL) {
		head = newNode;
		return head;
	} else {
		node *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->prev = temp;
		return head;
	}
}

node* push_front(node *head, int data) {
	node *temp = new node(data);
	temp->next = head;
	if (head != NULL) head->prev = temp;
	return temp;
}

node *push_pos(node *head, int data, int pos) {
	node *temp = new node(data);

	if (pos == 1) {
		temp->next = head;
		if (head != NULL) head->prev = temp;
		return temp;
	}

	node *curr = head;
	int i = 1;
	while (i <= pos - 2 && curr != NULL) {
		curr = curr -> next;
		i++;
	}

	if (curr == NULL ) return head;

	node *next = curr->next;
	curr->next = temp;
	temp->prev = curr;
	temp->next = next;
	return head;
}

node *delete_pos(node *head, int data, int pos) {
	node *temp = new node(data);

	if (pos == 1) {
		temp->next = head;
		if (head != NULL) head->prev = temp;
		return temp;
	}

	node *curr = head;
	int i = 1;
	while (i <= pos - 2 && curr != NULL) {
		curr = curr -> next;
		i++;
	}

	if (curr == NULL ) return head;

	node *next = curr->next;
	curr->next = temp;
	temp->prev = curr;
	temp->next = next;
	return head;
}

node* delete_front(node *head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) return NULL;
	else {
		head = head->next;
		head->prev = NULL;
		return head;
	}
}


node* delete_back(node *head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) return NULL;
	node *curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->prev->next = NULL;
	return head;
}

void printList(node *head) {
	node *curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

/////////////////////////////////////
// reverse doubliy linked list
node * reverse_linkedList(node * head) {
	if (head == NULL || head->next == NULL) return head;
	node* prev = NULL;
	node* curr = head;
	while (curr != NULL) {
		prev = curr->prev;
		curr->prev = curr->next;
		curr->next = prev;
		curr = curr->prev;
	}
	return prev->prev;
}

void solve_node() {
	node *head = NULL;
	head = push_back(head, 10);
	head = push_back(head, 20);
	head = push_back(head, 30);
	head = push_front(head, 5);
	// print the list
	printList(head);
	head = push_pos(head, 25, 3);
	// head = delete_front(head);
	// head = delete_back(head);
	// head = reverse_linkedList(head);
	printList(head);
}


///////////////////////////////////////////////////////////////////////////////////
// -------------------------- circular singly linked list ------------------------------
struct CSnode {
	int data;
	CSnode *next;
	CSnode(int d) {
		data = d;
		next = NULL;
	}
};

CSnode* insertAtEmpty(CSnode *last, int data) {

	// if last is not null then list is not empty, so return
	if (last != NULL) return last;

	// allocate memory for node
	CSnode *temp =  new CSnode(data);
	last = temp;

	// create the link
	last->next = temp;
	return last;
}

// insert new node at the beginning of the list
CSnode* insertAtBegin(CSnode *last, int data) {
	// if list is empty then add the node by calling insertInEmpty
	if (last == NULL) return insertAtEmpty(last, data);

	// else create new node
	CSnode *temp = new CSnode(data);

	temp->next = last->next;
	last->next = temp;
	return last;
}

// insert new node at the end of the list
CSnode* insertAtEnd(CSnode *last, int data) {
	// if list is empty then add the node by calling insertInEmpty
	if (last == NULL) return insertAtEmpty(last, data);

	CSnode *temp = new CSnode(data);

	temp->next = last->next;
	last->next = temp;
	last = temp;
	return last;
}

// insert a new node in between the nodes
CSnode* insertAfterPos(CSnode *last, int data, int pos) {

	// return NULL if list is empty
	if (last == NULL) return NULL;

	CSnode *temp = new CSnode(data), *p, *ptr;
	p = last->next;
	ptr = last->next;
	// pos = 2

	// check insertion is possible or not
	int count = 1;
	while (ptr->next != last) {
		count++;
		ptr = ptr->next;
	}
	count++;
	if (count < pos) {
		cout << " out of bound " << endl;
		return last;
	}

	// insert at after
	if (count == pos) return insertAtEnd(last, data);
	if (pos == 0) return insertAtBegin(last, data);
	// insert at index
	int cnt = 1;
	while (cnt < pos) {
		p = p->next;
		cnt++;
	}

	temp->next = p->next;
	p->next = temp;
	return last;
}

// -------------- delete -------------------
//delete the node from the list

void deleteNode(CSnode** head, int key)
{

	// If linked list is empty
	if (*head == NULL)
		return;

	// If the list contains only a single node
	if ((*head)->data == key && (*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		return;
	}

	CSnode *last = *head, *d;

	// If head is to be deleted
	if ((*head)->data == key)
	{


		// Find the last node of the list
		while (last->next != *head)
			last = last->next;

		// Point last node to the next of head i.e.
		// the second node of the list
		last->next = (*head)->next;
		free(*head);
		*head = last->next;
		return;
	}

	// Either the node to be deleted is not found
	// or the end of list is not reached
	while (last->next != *head && last->next->data != key)
	{
		last = last->next;
	}

	// If node to be deleted was found
	if (last->next->data == key)
	{
		d = last->next;
		last->next = d->next;
		free(d);
	}
	else
		cout << "no such keyfound";
}

/* Driver code */
// traverse whole list
void print_list(CSnode *last) {
	// CSnode *p;
	// if (last == NULL) {
	// 	cout << " Circular singly linked list is empty  " << endl;
	// 	return;
	// }

	// p = last->next;
	// cout << p->data << endl;
	// cout << last->data << endl;
	// do {
	// 	cout << p->data << " ";
	// 	p = p->next;
	// } while (p != last->next);

	// cout << endl;

	CSnode* temp = last;
	if (last != NULL) {
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != last);
	}

	cout << endl;
}


// 0 1 2 3
void solve_CSnode() {
	CSnode *last = NULL;

	last = insertAtEmpty(last, 10);
	last = insertAtBegin(last, 5);
	last = insertAtEnd(last, 15);
	last = insertAfterPos(last, 13, 0);
	// last = insertAtPos(last, 20, 4);
	print_list(last);
	deleteNode(&last, 15);
	print_list(last);
}

//////////////////////////////////////////////////////////////////////////////////////
// ---------------------------- circular doubly linkedList ------------------------
struct cdnode {
	int data;
	cdnode *next;
	cdnode *prev;
};

// function nto insert at end
void insert_at_end(cdnode **start, int value) {
	// if the list is empty, create a single node
	// circular and doubly list
	if (*start == NULL) {
		cdnode* new_node = new cdnode;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}

	// if list is not empty
	// find last node

	cdnode *last = (*start)->prev;

	// create node dynamically
	cdnode *new_node = new cdnode;
	new_node->data = value;

	// Start is going to be next of new_node
	new_node->next = *start;

	// Make new node previous of start
	(*start)->prev = new_node;

	// Make last previous of new node
	new_node->prev = last;

	// Make new node next of old last
	last->next = new_node;
}


// Function to insert Node at the beginning
// of the List,
void insert_at_begin(cdnode** start, int value) {
	// if the list is empty, create a single node
	// circular and doubly list
	if (*start == NULL) {
		cdnode* new_node = new cdnode;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}
	struct cdnode* last = (*start)->prev;

	struct cdnode* new_node = new cdnode;
	new_node->data = value;

	// setting up previous and next of new_node
	new_node->next = *start;
	new_node->prev = last;

	// update next and previous pointer of start and last
	last->next = (*start)->prev = new_node;

	// update start pointer
	*start = new_node;

}

// Function to insert Node at the beginning
// of the List,
// user for reverse linked list
void insert_at_begin1(cdnode** start, cdnode *new_node) {
	// if the list is empty, create a single node
	// circular and doubly list
	if (*start == NULL) {
		// cdnode* new_node = new cdnode;
		// new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}
	struct cdnode* last = (*start)->prev;

	// struct cdnode* new_node = new cdnode;
	// new_node->data = value;

	// setting up previous and next of new_node
	new_node->next = *start;
	new_node->prev = last;

	// update next and previous pointer of start and last
	last->next = (*start)->prev = new_node;

	// update start pointer
	*start = new_node;
}

// Function to insert node with value as value1.
// The new node is inserted after the node with
// with value2

// val = is value after that we can insert data in the list
void insert_after(cdnode** start, int data, int val) {
	cdnode *new_node = new cdnode;
	new_node->data = data;

	// find node having val and next node of it
	cdnode *temp = *start;

	while (temp->data != val)
		temp = temp->next;

	cdnode *next = temp->next;

	// insert new_node between temp and next
	temp->next = new_node;;
	new_node->prev = temp;
	new_node->next = next;
	next->prev = new_node;
}


cdnode* reverse_doubly_linkedlist(cdnode *start) {
	if (!start) return NULL;

	cdnode* new_start = NULL;
	cdnode* temp = start, *next;

	while (temp->next != start) {
		next = temp->next;
		insert_at_begin1(&new_start, temp);
		temp = next;
	}
	insert_at_begin1(&new_start, temp);
	return new_start;
}


////////////////// delete node //////////////////////////////////
// function to delete given node from the list
void delete_node(cdnode** start, int key) {
	// if not is empty
	if (*start == NULL) return;

	// Find the required node
	// Declare two pointers and initialize them

	cdnode* curr = *start, *prev_1 = NULL;
	while (curr->data != key) {
		if (curr->next == *start) {
			cout << " \nList doesn't have node with value " << key;
			return;
		}
		prev_1 = curr;
		curr = curr->next;
	}


	// curr -> is node to delete
	// prev_1 -> node is just before curr node

	// check if node is the only node in the list
	if (curr->next == *start && prev_1 == NULL) {
		(*start) == NULL;
		free(curr);
		return;
	}

	// If list has more than one node,
	// check if it is the first node
	if (curr == *start) {
		prev_1 = (*start)->prev;
		*start = (*start)->next;

		// Adjust the pointers of prev_1 and start node
		prev_1->next = *start;
		(*start)->prev = prev_1;
		free(curr);
	}
	// check if it is the last node
	else if (curr->next == *start) {
		// Adjust the pointers of prev_1 and start node
		prev_1->next = *start;
		(*start)->prev = prev_1;
		free(curr);
	}
	else {
		// create a new Pointer, points to next of curr node
		cdnode* temp = curr->next;

		// Adjust the pointers of prev_1 and temp node
		prev_1->next = temp;
		temp->prev = prev_1;
		free(curr);
	}

}
void display(cdnode* start) {
	cdnode* temp = start;
	printf("\nTraversal in forward direction \n");
	while (temp->next != start) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ";

	// printf("\nTraversal in reverse direction \n");
	// cdnode *last = start->prev;
	// temp = last;
	// while (temp->prev != last); {
	// 	cout << temp->data << " ";
	// 	temp = temp->prev;
	// }
	// cout << temp->data << " ";
}

// 1 2 3 4

void solve_cdnode() {
	cdnode* start = NULL ;

	// 5
	// insert_at_end(&start, 5);

	// 4 -> 5
	insert_at_begin(&start, 4);

	// // // 4 -> 5 -> 6
	insert_at_end(&start, 6);

	// // // 4 -> 5 -> 6 -> 7
	insert_at_end(&start, 7);

	// // // 4 -> 5 -> 6 -> 8 -> 7
	insert_after(&start, 8, 6);

	display(start);
	delete_node(&start, 6);
	display(start);
	start = reverse_doubly_linkedlist(start);
	display(start);
}
int main() {
	// solve_Node();
	// solve_Node1();
	// solve_node();
	// solve_CSnode();
	solve_cdnode();
}