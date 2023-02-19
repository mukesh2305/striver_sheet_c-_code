#include <bits/stdc++.h>
using namespace std;

struct myStack_arr {
	int *arr;
	int cap;
	int top;

	myStack_arr(int c) {
		cap = c;
		arr = new int[cap];
		top = -1;
	}

	void push(int x) {
		if (top == cap - 1) {
			cout << " stack is full" << endl;
			return;
		}
		top++;
		arr[top] = x;
	}

	int pop() {
		if (top == -1) {
			cout << " stack is empty" << endl;
			return INT_MIN;
		}
		int res = arr[top];
		top--;
		return res;
	}

	int peek() {
		if (top == -1) {
			cout << "stack is empty" << endl;
			return INT_MIN;
		}
		return arr[top];
	}

	int size() {
		return top + 1;
	}

	bool isEmpty() {
		return top = -1;
	}


};

void solve_myStack_arr() {
	myStack_arr s(5);
	s.push(5);
	s.push(10);
	s.push(20);
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << s.peek() << endl;
	cout << s.isEmpty() << endl;
}
//////////////////////////////////////////////////////
// using vector

struct myStack_vector {
	vector<int> v;

	void push(int x) {
		v.push_back(x);
	}

	int pop() {
		int res = v.back();
		v.pop_back();
		return res;
	}

	int peek() {
		return v.back();
	}

	int size() {
		return v.size();
	}

	bool isEmpty() {
		return v.empty();
	}

};
void solve_myStack_vector() {
	myStack_vector s;
	s.push(5);
	s.push(10);
	s.push(20);
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << s.peek() << endl;
	cout << s.isEmpty() << endl;
}
////////////////////////////////////////////////////
// linked list emplementation of stack
struct Node {
	int data;
	Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

struct myStack_linkeList {
	Node *head;
	int sz;

	myStack_linkeList() {
		head = NULL;
		sz = 0;
	}

	void push(int x) {
		Node *temp = new Node(x);
		temp->next = head;
		head = temp;
		sz++;
	}

	int pop() {
		if (head == NULL) {
			cout << "Stack is Empty" << endl;
			return INT_MAX;
		}
		int res = head->data;
		Node *temp = head;
		head = head->next;
		free(temp);
		sz--;
		return res;
	}
	int peek() {
		if (head == NULL) {cout << "Stack is Empty" << endl; return INT_MAX;}
		return head->data;
	}
	int size() {
		return sz;
	}
	bool isEmpty() {
		return head == NULL;
	}
};

void solve_myStack_linkeList() {
	myStack_linkeList s;
	s.push(5);
	s.push(10);
	s.push(20);
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << s.peek() << endl;
	cout << s.isEmpty() << endl;
}



/////////////////////////////////////////////////////
// stck in c++ STL

void solve_stack_STL() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.push(5);
	cout << s.top() << endl;


	cout << endl << endl;
	while (s.empty() == false) {
		cout << s.top() << endl;
		s.pop();
	}
}

////////////////////////////////////////////////////////
// balace parenthesis

bool matching(char a, char b) {
	return (
	           (a == '(' && b == ')') ||
	           (a == '[' && b == ']') ||
	           (a == '{' && b == '}')
	       );
}

bool isBalanced(string str) {
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			s.push(str[i]);
		else {
			if (s.empty() == true) return false;
			else if (matching(s.top(), str[i]) == false) return false;
			else s.pop();
		}
	}

	return (s.empty() == true);
}

void solve_isBalanced() {
	string str = "{()}[]";

	if (isBalanced(str))
		cout << "Balanced";
	else
		cout << "Not Balanced";
}

//////////////////////////////////////////////////
// discusses the problem of implementation of Two stacks in a single array.


// Divide the space in two halves
struct twoStacks {
	int *arr;
	int cap;
	int top1, top2;

	twoStacks(int n) {
		cap = n;
		arr = new int[n];
		top1 = n / 2 + 1;
		top2 = n / 2;
	}

	void push1(int x) {
		if (top1 > 0) {
			top1--;
			arr[top1] = x;
		} else {
			cout << "Stack Overflow  By element :" << x << endl;
			return;
		}
	}

	void push2(int x) {
		if (top2 < cap - 1) {
			top2++;
			arr[top2] = x;
		} else {
			cout << "Stack Overflow  By element :" << x << endl;
			return;

		}
	}

	int pop1() {
		if (top1 <= cap / 2) {
			int x = arr[top1];
			top1++;
			return x;
		} else {
			cout << " stack UnderFlow" << endl;
			exit(1);
		}
	}

	int pop2() {
		if (top2 >= cap / 2 + 1 ) {
			int x = arr[top2];
			top2--;
			return x;
		} else {
			cout << " stack UnderFlow" << endl;
			exit(1);
		}
	}
};

//A space efficient implementatio
struct twoStacks1 {
	int *arr;
	int cap;
	int top1, top2;

	twoStacks1(int n) {
		cap = n;
		arr = new int[n];
		top1 = -1;
		top2 = cap;
	}

	void push1(int x) {
		if (top1 < top2 - 1) {
			top1++;
			arr[top1] = x;
		} else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	void push2(int x) {
		if (top1 < top2 - 1) {
			top2--;
			arr[top2] = x;
		} else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	int pop1() {
		if (top1 >= 0) {
			int x = arr[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	int pop2() {
		if (top2 < cap) {
			int x = arr[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};

void solve_twoStacks() {
	// twoStacks ts(5);
	twoStacks1 ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is: " << ts.pop1() << endl;
	ts.push2(40);
	cout << "Popped element from stack2 is: " << ts.pop2() << endl;
}

////////////////////////////////////////////////////////////////////////
// Given an array of distinct integers, find the closest (positive wise) greater on left of every element.
// If there is no greater element on l;eft, then print -1


void printPrevGreater(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				cout << arr[j] << " ";
				break;
			}
		}

		if (j == -1) cout << -1 << " ";
	}
}

void printPrevGreater1(int arr[], int n) {
	stack<int>s;
	s.push(arr[0]);
	for (int i = 0; i < n; i++) {
		while (s.empty() == false && s.top() <= arr[i]) {
			s.pop();
		}
		int pg = s.empty() ? -1 : s.top();
		cout << pg << " ";
		s.push(arr[i]);
	}
}

void solve_printPrevGreator() {
	int arr[] = {20, 30, 10, 5, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	// printPrevGreater(arr, n);
	printPrevGreater1(arr, n);
}


/////////////////////////////////////////////
void printNextGreater(int arr[], int n) {
	for (int i = 0; i < n; i++) {

		bool flag = false;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) {
				cout << arr[j] << " ";
				flag = true;
				break;
			}
		}

		if (flag == false) cout << -1 << " ";
	}
}

vector<int>  printNextGreater1(int arr[], int n) {
	vector<int> v;
	stack<int>s;
	s.push(arr[n - 1]);
	v.push_back(-1);
	for (int i = n - 2; i >= 0; i--) {
		while (s.empty() == false && s.top() <= arr[i]) {
			s.pop();
		}
		int ng = s.empty() ? -1 : s.top();
		v.push_back(ng);
		s.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	return v;
}

void solve_printNextGreator() {
	int arr[] = {10, 15, 20, 25};
	int n = sizeof(arr) / sizeof(arr[0]);
	// printNextGreater(arr, n); cout << endl;
	for (auto it : printNextGreater1(arr, n)) cout << it << " ";
}

/////////////////////////////////////////////////////////////////////
// print span
void printSpan(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int span = 1;
		for (int j = i - 1; i >= 0 && arr[j] <= arr[i]; j--) span++;
		cout << span << " ";
	}
}

//  60   20       40      35      30      50      70      65
//  0    1        2       3       4       5       6       7
//  (1)  (1-0)    (2-0)   (3-2)  (4-3)    (6 -0)  (7 +1)  (8-7)

void printSpan1(int arr[], int n) {
	stack<int> s ;
	s.push(0);
	cout << 1 << " ";
	for (int i = 1; i < n; i++) {
		while (s.empty() == false && arr[s.top()] <= arr[i]) {
			s.pop();
		}
		int span = s.empty() ? i + 1 : i - s.top();
		cout << span << " ";
		s.push(i);
	}
}
void solve_printSpan() {
	int arr[] = {18, 12, 13, 14, 11, 16};
	int n = 6;
	// printSpan(arr, n);
	printSpan1(arr, n);
}


int main() {
	// solve_myStack_arr();
	// solve_myStack_vector();
	// solve_myStack_linkeList();
	// solve_stack_STL();
	// solve_isBalanced();
	// solve_twoStacks();
	// solve_printPrevGreator();
	// solve_printNextGreator();
	solve_printSpan();
}