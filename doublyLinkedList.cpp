#include <bits/stdc++.h>
using namespace std;

// Node structure

struct Node {
	int data;
	Node *next;
	Node *prev;
};

class LinkedList {
private :
	Node* head;
public :
	LinkedList() {
		head = NULL;
	}

	// add new element at the end of the list
	void push_back(int ele) {
		Node* newNode = new Node();
		newNode->data = ele;
		newNode->next = NULL;
		newNode->prev = NULL;

		if (head == NULL) {
			head = newNode;
		}
		else {
			Node *temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
			newNode->prev = temp;
		}
	}

	// delte 
	//display the content of the list
	void printList() {
		Node *temp = head;
		if (temp != NULL) {
			cout << " The List Containts : ";
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}

			cout << endl ;
		} else {
			cout << " The List is empty.\n";
		}
	}

};

int main() {
	LinkedList List;
	List.push_back(10);
	List.push_back(20);
	List.push_back(30);

	List.printList();

}


