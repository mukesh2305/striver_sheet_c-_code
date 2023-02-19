#include <bits/stdc++.h>
#define ll long long
using namespace std;
/////////////////////////////////////////////////
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

///////////////////////////////////////////////////////////////////////////
// 628. Maximum Product of Three Numbers
int maximumProduct(vector<int> & nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	// for(auto x : nums) cout << x << " "; cout << endl;
	int mx_product = nums[n - 1] * nums[n - 2] * nums[n - 3];
	// cout << mx << endl;
	if (nums[0] < 0 && nums[1]) {
		mx_product  = max(mx_product, nums[0] * nums[1] * nums[n - 1]);
	}
	return mx_product;
}

void solve_maximumProduct() {
	vector<int> nums = { -1, -2, -3, 1};
	cout << maximumProduct(nums);
}

///////////////////////////////////////////////////////////////////////
// Maximize Toys
// link => https://practice.geeksforgeeks.org/problems/maximize-toys0331/1?category=
int toyCount(int n , int k, vector<int> & arr) {
	sort(arr.begin(), arr.end());
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (k - arr[i] >= 0) {
			count++;
			k -= arr[i];
		} else {
			break;
		}
	}
	return count;
}

void solve_toyCount() {
	int n = 7, k = 50;
	vector<int> arr = {1, 12, 5, 111, 200, 1000, 10};
	cout << toyCount(n , k, arr);
}

/////////////////////////////////////////////////////////////////////////
// Minimum Operations || Greedy-3 || Placement Preparation Series || Optimized || GFG||
// Minimum Operations
int minOperation(int n) {
	vector<int> dp(n + 1, -1);

	function<int(int)> f = [&](int n) {
		// base case: 0 can be reached in 0 operations
		if (n == 0) return 0;
		if (dp[n] != -1) return dp[n];
		// Try doubling the previous number
		int double_prev = INT_MAX;
		if (n % 2 == 0) {
			double_prev = 1 + f(n / 2);
		}

		// Try adding one to the previous number
		int add_one =  1 + f(n - 1);

		// Return the minimum number of operations
		return dp[n] = min(double_prev, add_one);
	};

	return f(n);
}

// using greedy approach
int minOperation_greedy(int n) {
	int operations = 0;
	while (n > 0) {
		// Try doubling the number if possible
		if (n % 2 == 0) {
			n /= 2;
		} else {
			n--;
		}
		operations++;
	}
	return operations;
}

void solve_minOperation() {
	int n = 4;
	// cout << minOperation(n);
	cout << minOperation_greedy(n);
}

/////////////////////////////////////////////////////////////////////////
// Majority Element || Greedy-4 || Placement Preparation Series || Optimized || GFG||
int majorityElement(vector<int> & nums) {
	// Use a hash map to count the frequency of each element
	unordered_map<int, int> counts;
	for (int num : nums) {
		counts[num]++;
	}
	// Find the element that appears more than n / 2 times
	int majority = -1;
	for (auto it : counts) {
		int num = it.first;
		int count = it.second;
		if (count > (int)nums.size() / 2) {
			majority = num;
			break;
		}
	}
	return majority;
}
// The idea behind the Boyer-Moore Majority Vote Algorithm
// is to maintain a count of the current majority element,
// and update the count as we traverse the array.

int majorityElement1(vector<int> & nums) {
	int count = 0;
	int majority = -1;

	for (auto num : nums) {
		if (count == 0)
			majority = num;

		count += (num == majority) ? 1 : -1;
	}

	return majority;
}
void solve_majorityElement() {
	vector<int> nums = {3, 2, 3};
	// cout << majorityElement(nums);
	cout << majorityElement1(nums);
}
int main() {
	init_code();

	// solve_maximumProduct();
	// solve_toyCount();
	solve_minOperation();
}