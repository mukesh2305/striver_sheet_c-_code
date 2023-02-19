#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
	int front , rear, size;
	unsigned capacity;
	int *arr;
};

Queue* createQueue(unsigned capacity) {
	Queue *queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	queue->rear = capacity - 1;
	queue->arr = new int[(queue->capacity * sizeof(int))];
	return queue;
}

int isFull(Queue *queue) {
	return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue) {
	return (queue->size == 0);
}

void enqueue(Queue *queue, int item) {
	if (isFull(queue)) return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->arr[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << item << " enqueued to queue\n";
}

int dequeue(Queue *queue) {
	if (isEmpty(queue)) return INT_MIN;
	int item = queue->arr[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item ;
}

int front(Queue *queue) {
	if (isEmpty(queue)) return INT_MIN;
	return queue->arr[queue->front];
}
int rear(Queue *queue) {
	if (isEmpty(queue)) return INT_MIN;
	return queue->arr[queue->rear];
}


void solve_Queue() {
	Queue* queue = createQueue(1000);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	cout << dequeue(queue)
	     << " dequeued from queue\n";

	cout << "Front item is "
	     << front(queue) << endl;
	cout << "Rear item is "
	     << rear(queue) << endl;
}

/////////////////////////////////////////////
// queue in stl
void solve_queue_stl() {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
}

////////////////////////////////////
// implement stack using queue

struct Stack {
	queue<int> q1, q2;
	int curr_size;

public:
	Stack()
	{
		curr_size = 0;
	}
// q1 =>
// q2 => 15 10 5
// q =>
	void push(int x)
	{
		curr_size++;

		// Push x first in empty q2
		q2.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{

		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
		curr_size--;
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size()
	{
		return curr_size;
	}
};

void solve_stack() {
	Stack s;
	s.push(10);
	s.push(5);
	s.push(15);
	s.push(20);

	cout << "current size: " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << "current size: " <<  s.size() << endl;
}

////////////////////////////////////////
// reverse queue
void reverse_queue(queue<int> &q ) {
	if (q.empty()) return;
	int x = q.front();
	q.pop();
	reverse_queue(q);
	q.push(x);
}

void reverse_queue1(queue<int> &q ) {
	stack<int> s;
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}

	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}

void solve_reverse_queue() {
	queue<int> q;
	q.push(12);
	q.push(5);
	q.push(15);
	q.push(20);
	// 	while (!q.empty()) {
	// 	cout << q.front() << " ";
	// 	q.pop();
	// }
	// cout << endl;
	// reverse_queue(q);
	reverse_queue1(q);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}

/////////////////////////////////////////////////////
// Generate numbers with given digits
// Given a number n, print first n number(in increasing order) such that all these numbers have digits in set {5, 6}
void printFirstN(int n) {
	queue<string> q;

	q.push("5");
	q.push("6");


	for (int i = 0; i < n; i++) {
		string curr = q.front();
		cout << curr << " ";
		q.pop();
		q.push(curr + "5");
		q.push(curr + "6");
	}
}

void solve_printFirstN () {
	int n = 5;
	printFirstN(n);
}
int main() {
	// solve_Queue();
	// solve_queue_stl();
	// solve_stack();
	// solve_reverse_queue() ;
	solve_printFirstN ();
}