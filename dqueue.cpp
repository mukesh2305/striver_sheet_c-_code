#include <bits/stdc++.h>
using namespace std;

void solve_dqueue() {
	deque<int> dq = {10, 20, 30};
	dq.push_front(5);
	dq.push_back(35);

	for (auto i : dq) cout << i << " ";
	cout << endl;
	cout << dq.front() << " " << dq.back() << endl;
}

void solve_dqueue1() {
	deque<int> dq = {10, 20, 30};
	auto it = dq.begin();
	dq.insert(it, 20);

	dq.pop_front();
	dq.pop_back();
	for (auto it : dq) cout << it << " ";

}

void solve_dqueue2() {
	deque<int> dq = {10, 20, 5, 30};

	auto it = dq.begin();

	it = dq.insert(it, 7);

	it = dq.insert(it, 2, 3);

	it = dq.erase(it + 1);

	cout << (*it) << endl;

	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
}

////////////////////////////////////////////////////
void solve_dqueue3() {
	struct myds {
		deque<int> dq;
		void insertMin(int x) {
			dq.push_front(x);
		}

		void insertMax(int x) {
			dq.push_back(x);
		}

		int getMin() {
			return dq.front();
		}

		int getMax() {
			return dq.back();
		}

		int extractMin() {
			int x = dq.front();
			dq.pop_front();
			return x;
		}

		int extractMax() {
			int x = dq.back();
			dq.pop_back();
			return x;
		}
	};



	struct myds ds;

	ds.insertMin(10);
	ds.insertMax(15);
	ds.insertMin(5);

	int x = ds.extractMin();
	cout << x << endl;

	x = ds.extractMax();
	cout << x << endl;

	ds.insertMin(8);
}
//We are given an array and a number k, we need to find maximums of all subarrays of size k.

void maximum_arr(int arr[], int k, int n) {
	// 10, 8, 5, 12, 15, 7, 6
	 int j, max;
    for (int i = 0; i <= n - k; i++) {
        max = arr[i];
        for (j = 1; j < k; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}

void solve_maximum_arr() {
	int arr[] = {10, 8, 5, 12, 15, 7, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	maximum_arr(arr, 3, n);
}
int main() {
	// solve_dqueue();
	// solve_dqueue1();
	// solve_dqueue2() ;
	// solve_dqueue3() ;
	solve_maximum_arr();
}