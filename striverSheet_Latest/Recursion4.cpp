#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

////////////////////////////////////////////////////////////////////////////////
// [49]. => Subset Sums
// link  => https://practice.geeksforgeeks.org/problems/subset-sums2234/1


// TC: O(2^N)
// SC: O(2^N)
void subsetSums_helper(int ind, vector<int> & arr, vector<int> & ans, int n, int sum) {
	if (ind == n) {
		ans.push_back(sum);
		return;
	}

	subsetSums_helper(ind + 1, arr , ans, n, sum + arr[ind]);
	subsetSums_helper(ind + 1, arr , ans, n, sum);
	// sum += arr[ind];
	// subsetSums_helper(ind + 1, arr , ans, n, sum);
	// sum -= arr[ind];
	// subsetSums_helper(ind + 1, arr , ans, n, sum);
}
vector<int> subsetSums(vector<int> arr, int n) {
	vector<int> ans;
	subsetSums_helper(0, arr, ans, n, 0);
	sort(ans.begin(), ans.end());
	return ans;
}

void solve_subsetSums() {
	int n = 2;
	vector<int> arr = {2, 3};
	for (auto i : subsetSums(arr, n)) cout << i << " ";
}

////////////////////////////////////////////////////////////////////////////////
// [50]. => 90. Subsets II
// link  => https://leetcode.com/problems/subsets-ii/

// TC: O(n log n + n * 2^n) = O(n * 2^n)
// SC:  O(2^n)
void subset(int ind, set<vector<int>> & res, vector<int> & val, vector<int> & nums, int n) {
	if (ind == n) {
		res.insert(val); // O(n)
		return;
	}

	val.push_back(nums[ind]);
	// pick it
	subset(ind + 1, res, val, nums, n);

	val.pop_back();
	// not pick
	subset(ind + 1, res, val, nums, n);

}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	set<vector<int>> res;
	vector<vector<int>> ans;
	vector<int> val;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	subset(0, res, val, nums, n);

	for (auto i : res) {
		ans.push_back(i);
	}
	return ans;
}


// 2nd Approach
// TC: O(2^n)
// SC: O(2^n)
void subset1(int ind, vector<vector<int>> & ans, vector<int> & val, vector<int> & nums, int n) {
	if (ind == n) {
		ans.push_back(val);
		return;
	}

	val.push_back(nums[ind]);
	subset1(ind + 1, ans, val, nums, n);
	val.pop_back();
	while ((ind + 1 < n) && (nums[ind] == nums[ind + 1])) ind += 1;
	subset1(ind + 1, ans, val, nums, n);
}

void subset2(int ind, vector<vector<int>> & ans, vector<int> & val, vector<int> & nums, int n) {
	ans.push_back(val);
	for (int i = ind; i < n; i++) {
		if (i != ind && nums[i] == nums[i - 1]) continue;
		val.push_back(nums[i]);
		subset2(i + 1, ans, val, nums, n);
		val.pop_back();
	}
}
vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> val;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	// subset1(0, ans, val, nums, n);
	subset2(0, ans, val, nums, n);
	return ans;
}
void solve_subsetsWithDup() {
	vector < int > nums = {1, 2, 2};
	// vector < vector < int >> ans = subsetsWithDup(nums);
	vector < vector < int >> ans = subsetsWithDup1(nums);

	for (auto i : ans) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
// [51]. => 39. Combination Sum
// link  => https://leetcode.com/problems/combination-sum/

// TC O(2^t * k) // where t is the target, k is the average length
// SC O(k*x) // k is the average length and x is the no. of combinations
void cal_subset(int ind, vector<vector<int>> & ans, vector<int> & vec, vector<int> & candidates, int target, int n) {
	if (ind == n) {
		if (target == 0) {
			ans.push_back(vec);
		}
		return;
	}

	if (candidates[ind] <= target) {
		vec.push_back(candidates[ind]);
		target -= candidates[ind];
		cal_subset(ind, ans, vec, candidates, target, n);
		vec.pop_back();
		target += candidates[ind];
	}
	cal_subset(ind + 1, ans, vec, candidates, target, n);
}

void cal_subset1(int ind, vector<vector<int>> & ans, vector<int> & vec, vector<int> & candidates, int target, int n) {
	if (target == 0) {
		ans.push_back(vec);
		return;
	}

	for (int i = ind; i < candidates.size(); i++) {
		if (candidates[i] <= target) {
			vec.push_back(candidates[i]);
			cal_subset1(i, ans, vec, candidates, target - candidates[i], n);
			vec.pop_back();
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> vec;
	int n = candidates.size();
	// cal_subset(0, ans, vec, candidates, target, n);
	cal_subset1(0, ans, vec, candidates, target, n);
	return ans;
}

void solve_combinationSum() {
	vector<int> candidates = {2, 3, 6, 7};
	int target = 7;
	for (auto i : combinationSum(candidates, target)) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
// [52]. => 40. Combination Sum II
// link  => https://leetcode.com/problems/combination-sum-ii/

// Time Complexity:O(2^n*k)
// Reason: Assume if all the elements in the array are unique then the no. 
// of subsequence you will get will be O(2^n). 
// we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds

// Space Complexity:O(k*x)
// Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
void cal_subset_Func(int ind, vector<vector<int>> & ans, vector<int> & vec, vector<int> & candidates, int target, int n) {
	if(target == 0) {
		ans.push_back(vec);
		return;
	}

	for(int i = ind; i < n; i++) {
		if(i != ind && candidates[i] == candidates[i - 1]) continue;
		if(candidates[i] <= target) {
			vec.push_back(candidates[i]);
			cal_subset_Func(i + 1, ans, vec, candidates, target - candidates[i], n);
			vec.pop_back();
		}
	}
}
vector<vector<int>> combinationSum2(vector<int> & candidates, int target) {
	vector<vector<int>> ans;
	vector<int> vec;
	int n = candidates.size();
	sort(candidates.begin(), candidates.end());
	cal_subset_Func(0, ans, vec, candidates, target, n);
	return ans;
}

void solve_combinationSum2() {
	vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;
	for (auto i : combinationSum2(candidates, target)) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
// [53]	. => 131. Palindrome Partitioning
// link  => https://leetcode.com/problems/palindrome-partitioning/

bool isPalindrome(string & s, int low, int high) {
	while(low <= high) {
		if(s[low++] != s[high--])  return false;
	}
	return true;
}
void func_part(int ind, string & s, vector<string> & path, vector<vector<string>> & res) {
	if(ind == s.size()) {
		res.push_back(path);
		return;
	}

	for(int i = ind; i < s.size(); i++) {
		if(isPalindrome(s, ind, i)) {
			path.push_back(s.substr(ind, i - ind + 1));
			func_part(i + 1, s, path, res);
			path.pop_back();
		}
	}
}
vector<vector<string>> partition(string s){
	vector<vector<string>> res;
	vector<string> path;
	func_part(0, s, path, res);
	return res;
}

void solve_partition() {
	string s = "aab";
	for(auto i : partition(s)) {
		for(auto j : i) cout << j << " ";
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
// [54]	. => 60. Permutation Sequence
// link  => https://leetcode.com/problems/permutation-sequence/

string getPermutation(int n, int k) {
	int fact = 1;
	vector<int> numbers;
	for(int i = 1; i < n; i++) {
		fact = fact * i;
		numbers.push_back(i);
	}
	numbers.push_back(n);
	k = k - 1; // 0 based indexing
	string ans = "";
	while(true) {
		ans = ans + to_string(numbers[k / fact]);
		numbers.erase(numbers.begin() + k / fact);
		if(numbers.size() == 0) break;
		k = k % fact;
		fact = fact / numbers.size();
	}
	return ans;
}

void solve_getPermutation() {
	int n = 3, k = 3;
	cout << getPermutation(n , k );
}
int main() {
	init_code();

	// solve_subsetSums(); // 49
	// solve_subsetsWithDup(); // 50
	// solve_combinationSum(); // 51
	// solve_combinationSum2(); // 52
	// solve_partition();// 53
	solve_getPermutation(); // 54
}