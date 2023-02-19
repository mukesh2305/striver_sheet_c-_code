#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data ;
	Node *next; // because of this we called this structure , self refrencing structure
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/////////////////////////////////////////////////////////
// sorted index in the circular linkedList
void sorted_ind_node(Node** head, int data) {
	Node *temp = new Node(data);

	if (head == NULL) return;

	if (data < (*head)->data) {
		temp->next = *head;
		*head = temp;
		return;
	}
	// 1st -----------> way to do things
	// Node *curr = *head, *prev;
	// while (curr->next != NULL && curr->data < data) {
	// 	prev = curr;
	// 	curr = curr->next;
	// }

	// if(curr->next == NULL) {
	// 	curr->next = temp;
	// 	return;
	// }
	// prev->next = temp;
	// temp->next = curr;


	// 2nd -----------> way to do things
	Node *curr = *head;
	while (curr->next != NULL && curr->next->data < data)
		curr = curr->next;

	temp->next = curr->next;
	curr->next = temp;
}


///////////////////////////////////////////////////
// find the middle of linked list
// if => even than find second middle

void find_middle(Node *head) {
	if (head == NULL) return;
	int cnt = 0;

	Node *curr;
	for (curr = head; curr != NULL; curr = curr->next) cnt++;

	curr = head;
	for (int i = 0; i < cnt / 2; i++)
		curr = curr->next;
	cout << curr->data;

}

// efficient approach
void find_middle1(Node *head) {
	if (head == NULL) return;
	Node *slow = head, *fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << slow->data << endl;
}
// 10 20 30 40 50

/////////////////////////////////////////////////////
// find nth node from the end of the linked list
// 10 20 30 40 50   n = 2 out = 40
void end_nth_node(Node *head, int n) {
	if (head == NULL) return;
	int cnt = 0;
	Node *curr;
	for (curr = head ; curr != NULL; curr = curr->next) cnt++;

	if (n > cnt) return;
	int c = cnt - n + 1;
	cout << c << endl;
	curr = head;
	for (int i = 1; i < c; i++) { // run only 3 times
		curr = curr->next;
	}
	cout << curr->data << endl;
// 10 20 30 40 50
}

// two pointer
// efficient solution
void end_nth_node1(Node *head, int n) {
	if (head == NULL) return;
	int cnt = 0;
	Node* curr;
	for ( curr = head; curr != NULL; curr = curr->next) {
		if (cnt == n) break;
		cnt++;
	}

	Node *slow = head, *fast = curr;
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	cout << slow->data << endl;
}

////////////////////////////////////////////////////
// reverse singly linked list
void reverse_linkedList(Node *head) {
	Node *next = NULL, *prev = NULL;
	Node *curr = head;
	while (curr->next != NULL ) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;

	curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
}

// recursive reverse of linked list

Node * reverse_linkedList1(Node* head) {
	if (head == NULL || head->next == NULL) return head;
	Node* p = reverse_linkedList1(head->next);
	head->next->next = head;
	head->next = NULL;
	return p;

}

Node * reverse_linkedList2(Node* curr, Node * prev) {
	if (curr == NULL) return prev;
	Node * next = curr->next;
	curr->next = prev;
	return reverse_linkedList2(next, curr);
}

void printList(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}
// 10 20 30 40 50
//////////////////////////////////////////////////////////////
// remove duplicate from sorted singly linked list
set<int> remove_duplicate(Node* head) {
	Node *curr = head;
	set<int> st;
	while (curr != NULL) {
		st.insert(curr->data);
		curr = curr->next;
	}
	return st;

}

Node* remove_duplicate1(Node * head) {
	if (head == NULL) return NULL;
	Node *curr = head;
	while (curr->next != NULL) {
		if (curr->data == curr->next->data) {
			Node *temp = curr->next;
			curr->next = curr->next->next;
			free(temp);
		} else curr = curr->next ;
	}

	cout << endl;
	return head;
}

/////////////////////////////////////////////////////////////
// reverse a linked list with size k

Node* reverseK(Node* head, int k)
{
	// base case
	if (!head)
		return NULL;
	Node* curr = head;
	Node* next = NULL;
	Node* prev = NULL;
	int cnt = 0;

	/*reverse first k nodes of the linked list */
	while (curr != NULL && cnt < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		cnt++;
	}

	if (next != NULL)
		head->next  = reverseK(next, k);

	return prev;
}

// iterative method
//utility function to find length of the list
int lengthOfLinkedList(Node* head) {
	int length = 0;
	while (head != NULL) {
		++length;
		head = head->next;
	}
	return length;
}

Node *reverseK1(Node *head, int k) {
	if (head == NULL || k == 1) return head;

	Node *dummy = new Node(0);
	dummy->next = head;

	Node *cur = dummy, *nex = dummy, *pre = dummy;

	int cnt = 0;
	while (cur->next != NULL) {
		cur = cur->next;
		cnt++;
	}

	cout << cur->data << endl;

	while (cnt >= k) {
		cout << endl << " this -------------------" << endl ;
		cur = pre->next; cout << " cur " << cur->data << endl;
		nex = cur->next; cout << " nex " << nex->data << endl;
		for (int i = 1 ; i < k; i++) {
			cur->next = nex->next; // 30
			nex->next = pre->next; // 10
			pre->next = nex; // 20
			nex = cur->next;
		}
		pre = cur;
		cnt -= k;
	}
	return dummy->next;
}

Node* reverseK2(Node *head, int k) {
	Node *curr = head, *prevFirst = NULL;
	bool isFirstPass = true;
	while (curr != NULL) {
		Node* first = curr, *prev = NULL;
		int cnt = 0;
		while (curr != NULL && cnt < k) {
			Node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			cnt++;
		}

		if (isFirstPass) {
			// cout << " prev " << prev->data << endl;
			head = prev;
			isFirstPass = false;
		} else {
			// cout << " prev " << prev->data << endl;
			prevFirst->next = prev;

		}
		// cout << " first " << first->data << endl;
		prevFirst = first;
	}
	return head;
	// 10 20 30 40 50
}

//////////////////////////////////////////////
// Detect loop
bool isLoop(Node *head) {
	Node *temp = new Node(0);
	Node *curr = head;
	while (curr != NULL) {
		if (curr->next == NULL) return false;
		// cout << curr->data << endl;
		if (curr->next == temp) {
			// cout << curr->next->data << " " << temp->data << endl;
			return true;
		}
		Node* curr_next = curr->next;
		curr->next = temp;
		curr = curr_next;
	}
	return false;
}

bool isLoop1(Node *head) {
	unordered_set<Node*> st;
	for (Node* curr = head; curr != NULL; curr = curr->next) {
		if (st.find(curr) != st.end()) return true;
		st.insert(curr);
	}
	return false;
}

// using slow and fast pointer detect loop
bool isLoop2(Node *head) {
	Node *slow_p = head,  *fast_p = head;
	while (fast_p != NULL && fast_p->next != NULL) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p) return true; // this condition used in thelast because
		// starting both slow and fast pointer value is same so it always give yes as ans, that why we use this condition in the last
	}
	return false;
}
//      curr
// 10|0 20|0 30|0 40|0 50|0
//  curr_next = 2
// curr->next = 0


// detection loop in the linked list extention problem
// delete and remove loop in the linked list
void LoopDel(Node * head) {
	Node *slow = head,  *fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) break;
	}

	if (slow != fast) return;
	slow = head;

	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}

	fast->next = NULL;

	printList(head);
}

/////////////////////////////////////////////////////
// deleteNode but not given head pointer
void deleteNode_notGivenHead(Node *ptr) {
	Node *temp = ptr->next;
	ptr->data = temp->data;
	ptr->next = temp->next;
	free(temp);
}
void solve_deleteNode_notGivenHead() {
	Node *head = new Node(10);
	head->next = new Node(20);
	Node *ptr = new Node(30);
	head->next->next = ptr;
	head->next->next->next = new Node(50);
	deleteNode_notGivenHead(ptr);
	printList(head);
}

//////////////////////////////////////////////////
// 328. Odd Even Linked List
// refLink =>  https://www.youtube.com/watch?v=_VHInOZbp6A
Node* oddEvenList(Node* head) {
	Node *oddh = NULL, *evenh = NULL, *oddt = NULL, *event = NULL;
	int cnt = 1;
	for (Node *curr = head; curr != NULL; curr = curr->next) {
		if (cnt % 2 == 0) {
			if (evenh == NULL) {
				evenh = curr;
				event = curr;
			}
			else {
				event->next = curr;
				event = event->next;
			}
		} else {
			if (oddh == NULL) {
				oddh = curr;
				oddt = curr;
			} else {
				oddt->next = curr;
				oddt = oddt->next;
			}
		}
		cnt++;
	}

	if (oddh == NULL) return evenh;
	if (evenh == NULL) return oddh;
	// // first odd after even
	oddt->next = evenh;
	event->next = NULL;
	return oddh;

	// first even after odd
	// event->next = oddh;
	// oddt->next = NULL;
	// return evenh;
}

void solve_oddEvenList() {
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	head = oddEvenList(head);
	printList(head);

}

////////////////////////////////////////////////////////////////
// intersection point of 2 linkedList
int getIntersection(Node *head1, Node *head2) {
	unordered_set<Node*> st;
	Node *curr = head1;
	while (curr != NULL) {
		st.insert(curr);
		curr = curr->next;
	}

	curr  = head2;
	while (curr != NULL) {
		if (st.find(curr) != st.end())
			return curr->data;
		curr = curr->next;
	}
	return -1;
}

// 2nd approach
int getCount(Node *head) {
	Node *curr = head;
	int count = 0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}
int _getIntersection1(int d, Node *head1, Node *head2) {
	Node *curr1 = head1;
	Node *curr2 = head2;

	for (int i = 0; i < d; i++) {
		if (curr1 == NULL) return -1;
		curr1 = curr1->next;
	}

	while (curr1 != NULL && curr2 != NULL) {
		if (curr1 == curr2)
			return curr1->data;

		curr1 = curr1->next;
		curr2 = curr2->next;
	}

	return -1;
}
int getIntersection1(Node *head1, Node *head2) {
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d;
	if (c1 > c2) {
		d = c1 - c2;
		return _getIntersection1(d, head1, head2);
	} else {
		d = c2 - c1;
		return _getIntersection1(d, head2, head1);
	}
}
void solve_getIntersection() {
	/*
		Creation of two linked lists

		1st 3->6->9->15->30
		2nd 10->15->30

		15 is the intersection point
	*/

	Node* newNode;

	Node* head1 = new Node(10);

	Node* head2 = new Node(3);

	newNode = new Node(6);
	head2->next = newNode;

	newNode = new Node(9);
	head2->next->next = newNode;

	newNode = new Node(15);
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node(30);
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	// cout << getIntersection(head1, head2);
	cout << getIntersection1(head1, head2);
}

/////////////////////////////////////////////
// pairwiseSwap
void pairwiseSwap(Node * head) {
	Node *curr = head;
	while (curr != NULL && curr->next != NULL) {
		swap(curr->data, curr->next->data);
		curr = curr->next->next;
	}
}

Node* pairwiseSwap1(Node * head) {
	Node *curr = head, *prevFirst = NULL;
	bool isFirstPass = true;
	while (curr != NULL) {
		Node *first = curr, *prev = NULL;
		int cnt = 0;
		while (curr != NULL && cnt < 2) {
			Node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			cnt++;
		}

		if (isFirstPass) {
			head = prev;
			isFirstPass = false;
		} else {
			prevFirst->next = prev;
		}

		prevFirst = first;
	}
	return head;
}

///////////////////////////////////////////////////////////
// 138. Copy List with Random Pointer
// clone linked list
struct node {
	int data;
	node *next, *random;
	node(int d) {
		data = d;
		next = random = NULL;
	}
};

// using extra space
node* copyRandomList(node* head) {
	unordered_map<node*, node*> cl;
	for (node *curr = head; curr != NULL; curr = curr->next)
		cl[curr] = new node(curr->data);


	for (node *curr = head ; curr != NULL; curr = curr->next) {
		cl[curr]->next = cl[curr->next];
		cl[curr]->random = cl[curr->random];
	}
	return cl[head];
}

// withour using extra space;
node* copyRandomList1(node *head) {
	if (!head) return NULL;

	// copy List
	for (node *curr = head; curr != NULL; curr = curr->next->next) {
		node *copy = new node(curr->data);
		copy->next = curr->next;
		curr->next = copy;
	}

	// hadle random pointer
	for (node *curr = head; curr != NULL; curr = curr->next->next) {
		curr->next->random = (curr->random) ? curr->random->next : NULL;
	}

	// separate original linked list
	node *ans = head->next;
	node *temp = head->next;

	while (head) {
		head->next = temp->next;
		head = head->next;
		if (!head) break;
		temp->next = head->next;
		temp = temp->next;
	}
	return ans;
}
void print(node *head) {
	node *ptr = head;
	while (ptr) {
		cout << "Data = " << ptr->data << ", Random  = " << ptr->random->data << endl;
		ptr = ptr->next;
	}
}
void solve_copyRandomList() {
	node* head = new node(10);
	head->next = new node(5);
	head->next->next = new node(20);
	head->next->next->next = new node(15);
	head->next->next->next->next = new node(20);

	head->random = head->next->next;
	head->next->random = head->next->next->next;
	head->next->next->random = head;
	head->next->next->next->random = head->next->next;
	head->next->next->next->next->random = head->next->next->next;

	cout << "Original list : \n";
	print(head);

	cout << "\nCloned list : \n";
	// node *cloned_list = copyRandomList(head);
	node *cloned_list = copyRandomList1(head);
	print(cloned_list);

}

////////////////////////////////////////
// LRU caache
class cnode {
public :
	int key;
	int val;
	cnode *prev;
	cnode *next;

	cnode(int k, int v) {
		key = k;
		val = v;
		prev = next = NULL;
	}
};

class LRUCache {
public:
	unordered_map<int, cnode*> mp;
	int cap , cnt;
	cnode *head, *tail;

	LRUCache(int c) {
		cap = c;
		head = new cnode(0, 0);
		tail = new cnode(0, 0);
		head->next = tail;
		tail->prev = head;
		head->prev = NULL;
		tail->next = NULL;
		cnt = 0;
	}

	void deleteNode(cnode *node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	void addToHead(cnode *node) {
		node->next = head->next;
		node->next->prev = node;
		node->prev = head;
		head->next = node;
	}

	int get(int key)
	{
		if (mp[key] != NULL) {
			cnode *node = mp[key];
			int result = node->val;
			deleteNode(node);
			addToHead(node);
			cout << "Got the value : " <<
			     result << " for the key: " << key << endl;
			return result;
		}
		cout << "Did not get any value" <<
		     " for the key: " << key << endl;
		return -1;
	}

	void set(int key, int val)
	{
		cout << "Going to set the (key, " <<
		     "value) : (" << key << ", " << val << ")" << endl;
		if (mp[key] != NULL) {
			cnode *node = mp[key];
			node->val = val;
			deleteNode(node);
			addToHead(node);
		}
		else {
			cnode *node = new cnode(key, val);
			mp[key] = node;
			if (cnt < cap) {
				cnt++;
				addToHead(node);
			}
			else {
				mp.erase(tail->prev->key);
				deleteNode(tail->prev);
				addToHead(node);
			}
		}
	}
};

void solve_LRUCache() {
	LRUCache cache(2);

	// it will store a key (1) with value
	// 10 in the cache.
	cache.set(1, 10);

	// it will store a key (2) with value 20 in the cache.
	cache.set(2, 20);
	cout << "Value for the key: 1 is " << cache.get(1) << endl; // returns 10

	// removing key 2 and store a key (3) with value 30 in the cache.
	cache.set(3, 30);

	cout << "Value for the key: 2 is " <<
	     cache.get(2) << endl; // returns -1 (not found)

	// removing key 1 and store a key (4) with value 40 in the cache.
	cache.set(4, 40);
	cout << "Value for the key: 1 is " <<
	     cache.get(1) << endl; // returns -1 (not found)
	cout << "Value for the key: 3 is " <<
	     cache.get(3) << endl; // returns 30
	cout << "Value for the key: 4 is " <<
	     cache.get(4) << endl; // return 40
}

///////////////////////////////////////////////////////////////////////////////////////
// 21. Merge Two Sorted Lists => leetcode
// Merge Two sorted LinkedList
// TC => O(m + n)

// using recursion
Node* merge(Node* l1, Node* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	if (l1->data < l2->data) {
		l1->next = merge(l1->next, l2);
		return l1;
	} else {
		l2->next = merge(l1, l2->next);
		return l2;
	}
}
Node* mergeTwoList(Node * list1, Node* list2) {
	return merge(list1, list2);
}

///// using loops
Node* mergeTwoList1(Node * l1, Node* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	Node* ptr;
	if (l1->data < l2->data) {
		ptr = l1;
		l1 = l1->next;
	} else { // l2->data < l1->data
		ptr = l2;
		l2 = l2->next;
	}

	Node* curr = ptr;

	// 10 20 30 =>  l1
	// 5 25  => l2

	// till one of the list doesn't reaches NULL
	while (l1 && l2) {
		if (l1->data < l2->data) {
			curr->next = l1;
			l1 = l1->next;
		} else { // l2->data < l1->data
			curr->next = l2;
			l2 = l2->next;
		}
		curr = curr->next;
	}

	// adding remaning elements of bigger list
	if (!l1)
		curr->next = l2;
	else
		curr->next = l1 ;
	return ptr;
}

void solve_mergeTwoList() {
	Node *list1 = new Node(10);
	list1->next = new Node(20);
	list1->next->next = new Node(30);
	Node *list2 = new Node(5);
	list2->next = new Node(35);
	// printList(mergeTwoList(list1, list2));
	printList(mergeTwoList1(list1, list2));
}

//////////////////////////////////////////////////////////////////////////
// 234. Palindrome Linked List
bool isPalidrome(Node *head) {
	stack<int> st;
	Node* curr = head;
	while (curr) {
		st.push(curr->data);
		curr = curr->next;
	}

	curr = head;
	while (curr) {
		if (st.top() != curr->data) return false;
		st.pop();
		curr = curr->next;
	}

	return true;
}

/////////
Node* reverse_list(Node* head) {
	Node *curr = head, *prev = NULL, *next = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

bool isPalidrome1(Node* head) {
	if (head == NULL) return true;
	Node *slow = head, *fast = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverse_list(slow->next);
	fast = head, slow = slow->next;
	while (slow) {
		if (slow->data != fast->data) return false;
		slow = slow->next;
		fast = fast->next;
	}
	return true;
}
void solve_isPalidrome() {
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(2);
	head->next->next->next = new Node(1);
	// cout << (isPalidrome(head) ? "Yes" : "No") << endl;
	cout << (isPalidrome1(head) ? "Yes" : "No") << endl;
}
// 1 2 3 4 5 6


void solve_Node() {
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	head->next->next->next = new Node(40);
	head->next->next->next->next = new Node(50);
	// head->next->next->next->next->next = head->next;

	// sorted_ind_node(&head, 5);-------------------------------------
	// while (head->next != NULL) {
	// 	cout << head->data << " ";
	// 	head = head->next;
	// }
	// cout << head->data << " ";


	// find_middle-----------------------------
	// find_middle(head);
	// find_middle1(head);


	// nth ndoe from the end ---------------------------------
	// end_nth_node(head, 2);
	// end_nth_node1(head, 3);

	// reverse linked list--------------------------------
	// reverse_linkedList(head);

	// recursive approach 1----------------------------
	// head = reverse_linkedList1(head);
	// printList(head);
	// head = reverse_linkedList2(head, NULL);
	// printList(head);


	// remove duplicate from sorted singly linked list
	// for(auto it : remove_duplicate(head)) cout << it << " ";
	// head = remove_duplicate1(head);
	// printList(head);


	///// reverse with k size
	// head = reverseK(head, 2);
	// head = reverseK1(head, 2);
	// head = reverseK2(head, 2);
	// printList(head);


	///// detect loop
	// cout << (isLoop(head) ? " yes " : " No ");
	// cout << (isLoop1(head) ? " yes " : " No ");
	// cout << (isLoop2(head) ? " yes " : " No ");

	// remove cycle loop
	// LoopDel(head);


	// paire wise swap linked list
	// pairwiseSwap(head);
	// head = pairwiseSwap1(head);
	// printList(head);

}


int main() {
	// solve_Node();
	// solve_deleteNode_notGivenHead();
	// solve_oddEvenList();
	// solve_getIntersection();
	// solve_copyRandomList();
	// solve_LRUCache();

	////////////////////// merge two sorted linked list
	// solve_mergeTwoList();

	solve_isPalidrome();
}