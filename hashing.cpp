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

//////////////////////////////////////////////////////////////
// Count Distinct Elements

void solve_distinct_element() {
	int arr[] = {15, 12, 13, 12, 13, 13, 18};
	int n = sizeof(arr) / sizeof(arr[0]);

	map<int, int> mp;
	for (auto it : arr) {
		mp[it];
	}

	for (auto it : mp) {
		cout << it.first << endl;
	}
}

//////////////////////////////////////////
// frequency of array element

void solve_frequency() {
	int arr[] = {15, 12, 13, 12, 13, 13, 18};
	int n = sizeof(arr) / sizeof(arr[0]);

	map<int, int> mp;
	for (auto it : arr) mp[it]++;
	for (auto it : mp)  cout << it.first << " : " << it.second << endl;
}

////////////////////////////////////////////////////
// intersection of 2 unsorted array

void solve_intersection() {
	vector<int> a = {10, 15, 20, 15, 30, 30, 5};
	vector<int> b = { 30, 5, 30, 80};

	map<int, int> mp;
	for (auto it : a) {
		mp[it]++;
	}

	for (auto it : b) {
		if (mp.find(it) == mp.end()) {
			mp[it]++;
		} else {
			mp[it] = 0;
		}
	}

	int cnt = 0;
	for (auto it : mp) {
		if (it.second == 0) {
			cout << it.first << " ";
			cnt++;
		}
	}

	cout << endl << " number of intersection is : " << cnt << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Union of two unsorted arrays

void solve_union() {
	vector<int> a  = {15, 20, 5, 15};
	vector<int> b  = {15, 15, 15, 20, 10};

	map<int, int> mp;

	for (auto it : a) mp[it];
	for (auto it : b) mp[it];


	cout << mp.size() << endl;
}
////////////////////////////////////////////////////////////////////
// Pair with given sum in unsorted array

void solve_pair_given_sum() {
	vector<int> a = {3, 2, 8, 15, -8};
	int sum = 17;

	// first method

	// map<int, int> mp;
	// for (auto it : a) mp[it];
	// for (auto i : a) {
	// 	int t = sum - i;
	// 	if (mp.find(t) != mp.end()) {
	// 		cout << "{ " << i << " , " << t << " } " << endl;
	// 		break;
	// 	}
	// }


	// secondd method
	map<int, bool> mp;
	for (auto n : a) {
		if (mp.find(sum - n) != mp.end()) {
			pair<int, int> p = make_pair(n, sum - n);
			cout << p.first  << " " << p.second << endl;
			break;
		}
		mp[n] = true;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
// Subarray with zero sum
// naive approach
// TC O(N^2)
bool is0subarray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int curr_sum = 0;
		for (int j = i; j < n; j++) {
			curr_sum += arr[j];
			if (curr_sum == 0)
				return true;
		}
	}
	return false;
}

// optimal approach
bool is0subarray1(int arr[], int n) {
	unordered_set<int> st;
	int pre_sum = 0;
	for (int i = 0; i < n; i++) {
		pre_sum += arr[i];
		if (st.find(pre_sum) != st.end())
			return true;
		if (pre_sum == 0)
			return true;
		st.insert(pre_sum);
	}
	return false;
}
void solve_is0subarray() {
	// int arr[] = {1, 4, 13, -3, -10, 5};
	int arr[] = {10 , -10};
	int n = sizeof(arr) / sizeof(arr[0]);

	// cout << is0subarray(arr, n);
	cout << is0subarray1(arr, n);
}

////////////////////////////////////////////////////////////////
// 560. Subarray Sum Equals K
int subarraySum(vector<int>& nums, int k) {
	int n = nums.size();
	int sum = 0, res = 0;
	unordered_map<int, int> m;
	m[0] = 1;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
		if (m.count(sum - k)) res += m[sum - k];
		m[sum]++;
	}
	return res;
}
void solve_subarraySum() {
	vector<int> nums = {5, 8, -4, -4, 9, -2, 2};
	int k = 0;
	cout << subarraySum(nums, k);
}

//////////////////////////////////////////////////////////////////////////
// Longest subarray with given sum
// --------------> naive apporach
int longest_subarray(vector<int> & nums, int k) {
	int n = nums.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		int cur_sum = 0;
		for (int j = i; j < n; j++) {
			cur_sum += nums[j];
			if (cur_sum == k)
				res = max(res, j - i + 1);
		}
	}
	return res;
}

// --------------> optimal approach
int longest_subarray1(vector<int> & nums, int k) {
	int n = nums.size();
	int pre_sum = 0, res = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		pre_sum += nums[i];
		if (pre_sum == k) res = i + 1;

		if (m.find(pre_sum) == m.end())
			m.insert({pre_sum, i});

		if (m.find(pre_sum - k) != m.end())
			res = max(res, i - m[pre_sum - k]);
	}
	return res;
}
void solve_longest_subarray() {
	// vector<int> nums = {5, 8, -4, -4, 9, -2, 2};
	vector<int> nums = {1, 4, 3, 3, 5, 5};
	// vector<int> nums = { -13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
	int k = 15;
	// cout << longest_subarray(nums, k);
	cout << longest_subarray1(nums, k);
}

//////////////////////////////////////////////////////////////////
// Longest Subarray with equal number of 0s and 1s

// brutforce approach
int lon_sub_0s_1s_eq(vector<int> & nums) {
	int n = nums.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		int c0 = 0, c1 = 0;
		for (int j = i; j < n; j++) {
			if (nums[j] == 0) c0++;
			else c1++;
			if (c0 == c1) res = max(res, j - i + 1);
		}
	}
	return res;
}

// optimal approach
int lon_sub_0s_1s_eq1(vector<int> & nums) {
	// if we change 0 with -1 than problem becomes find longest subArray with 0 sum
	for (auto & i : nums) if (i == 0) i = -1;
	int n = nums.size();
	int pre_sum = 0, res = 0;
	unordered_map<int, int> m;
	int k = 0;
	for (int i = 0; i < n; i++) {
		pre_sum += nums[i];
		if (pre_sum == k) res = i + 1;

		if (m.find(pre_sum) == m.end())
			m.insert({pre_sum, i});

		if (m.find(pre_sum - k) != m .end())
			res = max(res, i - m[pre_sum - k]);
	}
	return res;
}

void solve_lon_sub_0s_1s_eq() {
	vector<int> nums = {1, 0, 1, 1, 1, 0, 0};
	// cout << lon_sub_0s_1s_eq(nums);
	cout << lon_sub_0s_1s_eq1(nums);
}

///////////////////////////////////////////////////////////////////////////////////////
// Longest common span with same sum in binary array
// TC => O(N * 2);
int maxCommon(vector<int> & a1 , vector<int> & a2) {
	int n = a1.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		int sum1 = 0, sum2 = 0;
		for (int j = i; j < n; j++) {
			sum1 += a1[j];
			sum2 += a2[j];
			if (sum1 == sum2) res = max(res, j - i + 1);
		}
	}
	return res;
}

// TC => O(N)
int maxCommon1(vector<int> & a1, vector<int> & a2) {
	int n = a1.size();
	vector<int> temp(n);
	for (int i = 0; i < n; i++)
		temp[i]  = a1[i]  - a2[i];
	return longest_subarray1(temp, 0);
}

void solve_maxCommon() {
	vector<int> a1 = {0, 1, 0, 0, 0, 0};
	vector<int> a2 = {1, 0, 1, 0, 0, 1};
	// cout << maxCommon(a1, a2);
	cout << maxCommon1(a1, a2);
}

///////////////////////////////////////////////////////////////
// Longest Consecutive Subsequence
// TC O(nlogn)
int longest_subsequnce(vector<int> & arr) {
	sort(arr.begin(), arr.end());
	int n = arr.size();
	int res = 1, curr = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1] + 1)
			curr++;
		else if (arr[i] != arr[i - 1]) {
			res = max(res, curr);
			curr = 1 ;
		}
	}
	return max(res, curr);
}


// optimal approach
int longest_subsequnce1(vector<int> & arr) {
	int n = arr.size();
	unordered_set<int> s;
	int res = 0;

	for (int i = 0; i < n; i++) s.insert(arr[i]);

	for (int i = 0; i < n; i++) {
		if (s.find(arr[i] - 1) == s.end()) {
			int curr = 1;
			while (s.find(curr + arr[i]) != s.end())
				curr++;
			res = max(res, curr);
		}
	}
	return res;
}

void solve_longest_subsequnce() {
	vector<int> arr = {1, 9, 3, 4, 2, 10, 13};
	cout << longest_subsequnce(arr);
	// cout << longest_subsequnce1(arr);
}

///////////////////////////////////////////////////////////////////////////////////
// Count Distinct Elements In Every Window

// naive approach
void count_distinct_window(vector<int> & arr, int k)
{
	int n = arr.size();
	for (int i = 0; i <= n - k; i++) {
		int count = 0;
		for (int j = 0; j < k; j++) {
			bool flag = false;
			for (int p = 0; p < j; p++) {
				if (arr[i + j] == arr[i + p])
				{
					flag = true; break;
				}
			}
			if (flag == false)count++;

		}
		cout << count << " ";
	}
}


// optimal approach
vector<int> count_distinct_window1(vector<int> & arr, int k) {
	int i = 0, j = 0;
	unordered_map<int, int> mp;
	vector<int> vec;
	while (j < arr.size()) {
		mp[arr[j]]++;
		if (k == j - i + 1) {
			vec.push_back(mp.size());
			mp[arr[i]]--;
			if (mp[arr[i]] == 0) {
				mp.erase(arr[i]);
			}
			i++;
		}
		j++;
	}
	return vec;
}

void solve_count_distinct_window() {
	vector<int> arr = {10, 20, 20, 10, 30, 40, 10};
	int k = 4;
	count_distinct_window(arr, k);
	// for (auto i : count_distinct_window1(arr, k)) cout << i << " ";
}

////////////////////////////////////////////////////////////////
// More than n/k Occurences
// TC O(N)
vector<int> printByK(vector<int> & arr, int k) {
	int n = arr.size();
	int t = n / k;

	vector<int> vec;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) mp[arr[i]]++;
	for (auto i : mp) {
		if (i.second > t)
			vec.push_back(i.first);
	}

	return vec;
}


void solve_printByK() {
	vector<int> arr = {30, 10, 20, 20, 10, 20, 30, 30};
	int k = 4;
	for (auto i : printByK(arr, k)) cout << i << " ";
}
int main() {
	init_code();

	// solve_distinct_element();
	// solve_frequency();
	// solve_intersection();
	// solve_union();
	// solve_pair_given_sum();
	// solve_pair_given_sum();
	// solve_is0subarray();
	// solve_subarraySum();
	// solve_longest_subarray();
	// solve_lon_sub_0s_1s_eq();
	// solve_maxCommon();
	// solve_longest_subsequnce();
	// solve_count_distinct_window();
	solve_printByK();
}