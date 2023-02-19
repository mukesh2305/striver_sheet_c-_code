#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////
// reverse array
void rev_arr(int arr[], int n, int i) {
	if (i > n / 2) return;
	swap(arr[i], arr[n - i - 1]);
	i++;
	rev_arr(arr, n, i);
}

void rev_arr1(int arr[], int l, int r) {
	if (l > r) return;
	swap(arr[l++], arr[r--]);
	rev_arr1(arr, l , r);
}
void solve_rev_arr() {
	int arr[] = {1, 4, 3, 2, 5}; // reverse array
	int n = sizeof(arr) / sizeof(arr[0]);
	// rev_arr(arr, n, 0);
	rev_arr1(arr, 0, n - 1);

	for (auto it : arr) cout << it << " ";
}

////////////////////////////////////////
// binary search

int binarySearch(int arr[], int l , int h, int key) {
	if (l > h) return -1;
	int m = (l + h) / 2;
	if (arr[m] == key ) return m;
	else if (arr[m] > key) return binarySearch(arr, l, m - 1, key);
	else if (arr[m] < key) return binarySearch(arr, m + 1, h, key);
}
void solve_binarySearch() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 5;
	cout <<  binarySearch(arr, 0, n - 1, key);
}

//////////////////////////////////////////
// isPalidrome

bool isPalidrome(string str, int l, int h) {
	if (l > h) return true;
	if (str[l] != str[h]) return false;
	return isPalidrome(str, l + 1, h - 1);
}

void solve_isPalidrome() {
	string str = "mukkum";
	int n = str.length();
	cout << isPalidrome(str, 0, n - 1);
}

///////////////////////////////////////////
// subsequece or subset of array
void subSequenceOfArray(int i , vector<int> &v, int arr[], int n) {
	// Time Complexity: 0(2^n * n)
	// Space Complexity: 0(n)

	if (i == n) {
		// print statement taking O(n) time
		for (auto it : v) cout << it << " ";
		cout << endl;
		return;
	}
	v.push_back(arr[i]);
	// pick it
	subSequenceOfArray(i + 1, v, arr, n);
	v.pop_back();
	// not pick
	subSequenceOfArray(i + 1, v, arr, n);
}

void solve_subSequenceOfArray() {
	int arr[] = {1, 3, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> v;
	subSequenceOfArray(0, v, arr, n);
}

////////////////////////////////////////////////////////
// print the subset whose sum is divisible by k
void subSequenceOfArray_k(int i , vector<int> &v, int arr[], int n, int sum, int k) {
	if (i == n) {
		// if (v.size() != 0 && sum % k == 0) {
		if (v.size() != 0 && sum % k == 0) {
			for (auto it : v) cout << it << " ";
			cout << endl;
		}
		return;
	}

	v.push_back(arr[i]);
	sum += arr[i];
	subSequenceOfArray_k(i + 1, v, arr, n, sum, k);
	v.pop_back();
	sum -= arr[i];
	subSequenceOfArray_k(i + 1, v, arr, n, sum, k);
}
void solve_subSequenceOfArray_k() {
	// int arr[] = {1, 3, 2};
	int arr[] = { 2, 3, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> v;
	int sum = 0, k = 3;
	subSequenceOfArray_k(0, v, arr, n, sum , k);
}

////////////////////////////////////////////////////////
// count the subset whose sum is divisible by k
void subSequenceOfArray_k_count(int i , int arr[], int n, int sum, int k, int &cnt) {
	if (i == n) {
		if (sum % k == 0) cnt += 1;
		return;
	}

	sum += arr[i];
	subSequenceOfArray_k_count(i + 1, arr, n, sum, k, cnt);
	sum -= arr[i];
	subSequenceOfArray_k_count(i + 1, arr, n, sum, k, cnt);
}
int  subSequenceOfArray_k_count1(int i , int arr[], int n, int sum, int k) {
	// Time Complexity O(2^n)
	// Space Complexity O(n)
	if (i == n) {
		if (sum % k == 0) return 1;
		else return 0;
	}

	sum += arr[i];
	int l = subSequenceOfArray_k_count1(i + 1, arr, n, sum, k);
	sum -= arr[i];
	int r = subSequenceOfArray_k_count1(i + 1, arr, n, sum, k);
	return l + r;
}

void solve_subSequenceOfArray_k_count() {
	int arr[] = {1, 3, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> v;
	int sum = 0, k = 3;
	int cnt = 0;
	// subSequenceOfArray_k_count(0, arr, n, sum , k, cnt);
	// cout << cnt - 1 << endl; // we are doing cnt - 1 because empty subset also do cnt++ and add +1 to it that's why
	int count = subSequenceOfArray_k_count1(0, arr, n, sum , k);
	cout << count - 1 << endl; // we are doing cnt - 1 because empty subset also do cnt++ and add +1 to it that's why
}

////////////////////////////////////////////
// print the subsets(repeating) whose sum = 4 ,
int countSubsetWhoseSum(int ind, int sum, int arr[], int n) {
	// if(sum == 0) return 1;
	if (ind == n) {
		if (sum == 0) return 1;
		return 0;
	}

	int left = 0, right = 0;

	// when can you pick particular index
	// if particular index value arr[ind] <= sum
	if (arr[ind] <= sum) {
		// sum wil be decrease
		sum -= arr[ind];
		left = countSubsetWhoseSum(ind, sum, arr, n);

		// restore sum
		sum += arr[ind];
	}

	// non pick, means move to the next index
	right = countSubsetWhoseSum(ind + 1, sum , arr, n);
	return left + right;
}

void solve_countSubsetWhoseSum() {
	int arr[] = {1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 2;
	cout << countSubsetWhoseSum(0, sum, arr, n);
}

///////////////////////////////////////////////////////////////////////////
// matrix recursion // go in 2 direstion right and down
// we wil be given n * m matrix
// we are allowed to move RIGHT R -> , we are allowed to moce DOWN D
// RIGHT R and DOWN D
// Eg : 3 * 2 matrix
// possible ways could be
// R D D , D D R, D R D // print all 3 paths

// TC => 2^(m * n)
void findPaths(int i , int j, int n , int m, string s) {
	// we have cross bounderies
	if (i >= n || j >= m) return;
	if (i == n - 1 && j == m - 1) {
		cout << s << endl;
		return;
	}

	s += 'D';
	findPaths(i + 1, j, n , m, s);
	s.pop_back();

	s += 'R';
	findPaths(i , j + 1, n , m , s);
	s.pop_back();
}

void solve_findPaths() {
	int n = 3, m = 2;
	string s = "";
	findPaths(0, 0, n , m , s);
}
//////////////////////////////////////////////////
// rate and maze

void findPaths1(int i , int j, int n , int m, string s, vector<vector<int>> &vis) {
	// we have cross bounderies
	if (i >= n || j >= m || i < 0 || j < 0 || vis[i][j] == 1) return;
	if (i == n - 1 && j == m - 1 ) {
		cout << s << endl;
		return;
	}

	vis[i][j] = 1;
	s += 'D';
	findPaths1(i + 1, j, n , m, s, vis);
	s.pop_back();

	s += 'R';
	findPaths1(i , j + 1, n , m , s, vis);
	s.pop_back();

	s += 'U';
	findPaths1(i - 1 ,  j, n , m , s, vis);
	s.pop_back();

	s += 'L';
	findPaths1(i , j - 1, n , m , s, vis);
	s.pop_back();

	vis[i][j] = 0;

}

// small optimization
//    i     j
// D  +1   +0
// R  +0   +1
// U  -1   +0
// L  +0   -1

// string dir => "DRUL";
// di => {+1, +0, -1, +0}
// dj => {+0, +1, +0, -1}

string dir = "DRUL";
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
void findPaths11(int i , int j, int n , int m, string s, vector<vector<int>> &vis) {
	// we have cross bounderies
	if (i >= n || j >= m || i < 0 || j < 0 || vis[i][j] == 1) return;
	if (i == n - 1 && j == m - 1 ) {
		cout << s << endl;
		return;
	}

	vis[i][j] = 1;

	for (int x = 0; x < 4; x++) {
		s += dir[x];
		findPaths11(i + di[x], j + dj[x], n  , m , s, vis);
		s.pop_back();
	}
	vis[i][j] = 0;

}


void solve_findPaths1() {
	int n = 3, m = 2;
	string s = "";
	// visited array of m * n
	vector<vector<int>> vis(n , vector<int> (m , 0));
	// findPaths1(0, 0, n , m , s, vis);
	findPaths11(0, 0, n , m , s, vis);
}
///////////////////////////////////////////////////////////
// count paths
string dir1 = "DRUL";
int di1[] = {1, 0, -1, 0};
int dj1[] = {0, 1, 0, -1};
int countPaths(int i , int j, int n , int m, vector<vector<int>> &vis) {
	// we have cross bounderies
	if (i >= n || j >= m || i < 0 || j < 0 || vis[i][j] == 1) return 0;
	if (i == n - 1 && j == m - 1 ) {
		return 1;
	}

	vis[i][j] = 1;
	int cnt = 0;
	for (int x = 0; x < 4; x++) {
		cnt += countPaths(i + di1[x], j + dj1[x], n  , m ,  vis);
	}
	vis[i][j] = 0;
	return cnt;
}

void solve_countPths() {
	int n = 3, m = 2;
	// visited array of m * n
	vector<vector<int>> vis(n , vector<int> (m , 0));
	// findPaths1(0, 0, n , m , s, vis);
	cout << countPaths(0, 0, n , m , vis);
}

/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// Rat in a Maze Problem - I(Geeks for Geeks)
void rate(int i, int j, int n , int m, string str,
          vector<vector<int>> &mt, vector<string> &ans, string dir, int di[], int dj[]) {
	if (i >= n || j >= m || i < 0 || j < 0 || mt[i][j] == 0) return;
	if (i == n - 1 && j == m - 1) {
		ans.push_back(str);
		return;
	}

	mt[i][j] = 0 ;
	for (int x = 0; x < 4; x++) {
		str += dir[x];
		rate(i + di[x], j + dj[x], n , m, str, mt, ans, dir, di, dj);
		str.pop_back();
	}

	mt[i][j] = 1;
}
vector<string> findPathRate(vector<vector<int>> &mt, int n) {
	// Your code goes here
	vector<string> ans ;
	int m = mt[0].size();
	string str;
	int i = 0, j = 0;
	string dir = "UDLR";
	int di[] = { -1, 1, 0, 0};
	int dj[] = {0, 0, -1, 1};
	rate(i, j, n, m , str,  mt, ans, dir, di, dj);
	return ans;
}

void solve_findPathRate() {
	int n = 4;
	vector<vector<int>> mt = {{1, 0, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 0, 0},
		{0, 1, 1, 1}
	};
	for (auto it : findPathRate(mt, n)) cout << it << endl;
}

/////////////////////////////////////////////////////////////////////////////
// print single subsequence that some is divisible by sum
bool singleSubSquence(int ind, vector<int> &ds, int arr[], int n, int sum, int k) {
	if (ind == n) {
		if (sum % k == 0) {
			for (auto it : ds) cout << it << " ";
			return true;
		}
		return false;
	}

	ds.push_back(arr[ind]);
	sum += arr[ind];
	if (singleSubSquence(ind + 1, ds, arr, n , sum, k) == true) 
		return true;

	ds.pop_back();
	sum -= arr[ind];
	
	if (singleSubSquence(ind + 1, ds, arr, n, sum, k ) == true)
		return true;
}

void solve_singleSubSequnce() {
	int arr[] = {3, 4};
	int k = 7;
	vector<int> ds;
	int n = sizeof(arr) / sizeof(arr[0]);
	singleSubSquence(0, ds, arr, n , 0, k);
}
//////////////////////////////////////////////////////////////////////////////
// NQuence problem
// print single valid configuration

// 1 => every row has 1 queen
// 2 => every column has 1 queen
// 3 => no queen should attack each other
bool isSafe(int row, int col, vector<vector<int>>& mat, int n) {
	// row--, col--
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (mat[i][j] == 1) return false;

	// col--, row
	for (int i = row, j = col; i >= 0 && j >= 0; i, j--)
		if (mat[i][j] == 1) return false;

	// row++, col--
	for (int i = row, j = col; i < n && j >= 0; i++, j--)
		if (mat[i][j] == 1) return false;

	return true;
}
bool NQueen(int col, vector<vector<int>> &mat, int n) {
	if (col == n) {
		for (int i = 0; i < n; i++) {
			for (int  j = 0; j < n ; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		return true;
	}


	/// for row
	for (int row = 0; row < n; row++) {
		if (isSafe(row, col, mat, n) == true) {
			mat[row][col] = 1;
			if (NQueen(col + 1, mat, n) == true) return true;
			mat[row][col] = 0;
		}
	}

	return false;
}

void solve_NQueen() {
	int n = 4;
	vector<vector<int>> mat(n , vector<int> (n , 0));
	NQueen(0, mat, n);
}
///////////////////////////////////////////////////////////////////
// print all the combination of Nqueen
// 1 => every row has 1 queen
// 2 => every column has 1 queen
// 3 => no queen should attack each other
bool isSafe1(int row, int col, vector<vector<int>> &sols, int n) {
	// row--, col--
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (sols[i][j] == 1) return false;

	// col--, row
	for (int i = row, j = col; i >= 0 && j >= 0; i, j--)
		if (sols[i][j] == 1) return false;

	// row++, col--
	for (int i = row, j = col; i < n && j >= 0; i++, j--)
		if (sols[i][j] == 1) return false;

	return true;
}
void solve(vector<vector<int>> & sols, int col, int n) {
	if (col == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n ; j++) cout << sols[i][j] << " " ;
			cout << endl;
		}
		cout << endl << endl;
		return;
	}
	for (int row = 0; row < n; row++) {
		if (isSafe1(row, col, sols, n) == true) {
			sols[row][col] = 1;    // Queen placed on a valid cell
			solve(sols, col + 1, n);    // Exploring next row
			sols[row][col] = 0;    // Backtracking to get all possible solutions
		}
	}
}
void solve_NQueen1() {
	int n = 4;
	vector<vector<int>> sols(n, vector<int> (n , 0)); // 2D vector of strings to store the solutions=
	solve(sols, 0, n);
}

/////////////////////////////////////////////////////////////
// 46. Permutations
void solve(int ind, vector<int> &nums, vector<vector<int>> &ans) {
	if (ind == nums.size()) {
		ans.push_back(nums);
		return;
	}

	for (int j = ind; j < nums.size(); j++) {
		swap(nums[ind], nums[j]);
		solve(ind + 1, nums, ans);
		swap(nums[ind], nums[j]);
	}
}
void permute(vector<int>& nums) {
	vector<vector<int>> ans;
	solve(0, nums, ans);
	for (auto it1 : ans) {
		for (auto it : it1) cout << it << " ";
		cout << endl;
	}
}

void solve_permute() {
	vector<int> nums = {1, 2, 3};
	permute(nums);
}


/////////////////////////////////////////////////////////
// 47. Permutations II // unique permutaion
void solve_1(int ind, vector<int> &nums, vector<vector<int>> &ans) {
	if (ind == nums.size()) {
		ans.push_back(nums);
		return;
	}

	unordered_set<int> st;
	for (int j = ind; j < nums.size(); j++) {
		if (st.count(nums[j]) == 1) continue;

		st.insert(nums[j]);

		swap(nums[ind], nums[j]);
		solve_1(ind + 1, nums, ans);
		swap(nums[ind], nums[j]);
	}
}
void permute_1(vector<int>& nums) {
	vector<vector<int>> ans;
	solve_1(0, nums, ans);
	for (auto it1 : ans) {
		for (auto it : it1) cout << it << " ";
		cout << endl;
	}
}

void solve_permute_1() {
	vector<int> nums = {1, 1, 2};
	permute_1(nums);
}

///////////////////////////////////////////////////////////////
// joseph

// tower of honai

//permutaion of string is lexicographycal order

////////////////////////////////////////////////////////////////////////
// what is n bit gray code
// -> every integer in the inclusive reange(0, 2^n - 1)
// -> the first intger is 0
// -> An intger appers no more than once in the sqequence
// -> the binary representaion of every bit of adjecent integer
//    differs by exactly one bit
//    ex : 00 and 01 are differe
// -> the binary representaion of first and last integer differs
//      by exactly one bit
//    ex : for n = 2
/*
	1 =>	00                          00
	2 =>	01                          01
	3 =>	10                          11
	4 =>	11                          10

			invalid                     valid gray code
			gray code
*/

// n = 2 => for 2^n -1 = 3;
// 0 1 2 3

// -> steps 1 = original list for (n - 1)[0 and 1]
// eg1 : /* 0 => 00
/* 1 => 01  */
// -> setps 2 => reverse the eg1:
// eg2 :
// this reverse of eg1
/*
1 => 01
0 => 00
*/

// -> setp 3 => change left most 0 to 1

/*
n = 2


=> step1- n = 1
00
01

=>step2 - reverse
01
00

=> step3 - change left most bit to 1 in the reverse
11
10

=> step4 - add step1 and setp2
00
01
11
10

//////////////////////////////now do for n = 2
00
01  => add zeros to left
11
10

000
001 => change left most bit to 1
011
010

// final output
100
101
111
110


*/
// ref = https://www.youtube.com/watch?v=KOD2BFauQbA
/*
[0, 1] // 1
[
	00  01
	11  10
]  // 2
[
	000 001 011 010
	110 111 101 100
]
*/
vector<string> generate_greyCode(int n) {
	if (n == 1) {
		vector<string> baseAns;
		baseAns.push_back("0");
		baseAns.push_back("1");
		return baseAns;
	}
	vector<string> recAns = generate_greyCode(n - 1);
	vector<string> mainAns;

	for (int i = 0; i < recAns.size(); i++) {
		string rstr = recAns[i];
		mainAns.push_back("0" + rstr);
	}


	for (int i = recAns.size() - 1; i >= 0; i--) {
		string rstr = recAns[i];
		mainAns.push_back("1" + rstr);
	}
	return mainAns;
}

void solve_generate_greyCode() {
	int n = 3;
	vector<string> vec = generate_greyCode(n);
	for (auto it : vec) cout << it << endl;
}
////////////////////////////////////////////////////////////////////////////////////
//  90. Subsets II

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<vector<int>> res = {{}};
	vector<int> curr;
	int size;

	for (auto num : nums) {
		size = res.size();
		for (int i = 0; i < size;  i++) {
			curr = res[i];
			curr.push_back(num);
			if (find(res.begin(), res.end() , curr) == res.end()) {
				res.push_back(curr);
			}

		}
	}

	return res;
}


void subset(int i, vector<vector<int>> &ans, vector<int> &val, vector<int> &nums, int n) {

	if (i == n) {
		ans.push_back(val);
		return;
	}
	val.push_back(nums[i]);
	// pick it
	subset(i + 1, ans , val, nums, n);
	val.pop_back();
	// not pick
	while (i + 1 < n && nums[i] == nums[i + 1]) i += 1;
	subset(i + 1, ans , val, nums, n);
}
vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> val;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	subset(0, ans, val, nums, n);
	return ans;
}

void solve_subsetsWithDup() {
	vector<int> nums = {1, 2, 2};
	// for (auto it : subsetsWithDup(nums)) {
	for (auto it : subsetsWithDup1(nums)) {
		for (auto a : it)
			cout << a << " ";
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////
// 39. Combination Sum

void cal_subset(int i, vector<vector<int>> &ans, vector<int> &vec, vector<int>& candidates, int target, int n) {
	if (i == n) {
		if ( target == 0 ) {
			ans.push_back(vec);
		}
		return;
	}

	if (candidates[i] <= target) {
		vec.push_back(candidates[i]);
		target -= candidates[i];
		cal_subset(i, ans, vec, candidates, target, n );
		vec.pop_back();
		target += candidates[i];
	}
	cal_subset(i + 1 , ans, vec, candidates, target, n );

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> vec;
	int n = candidates.size();
	cal_subset(0, ans, vec , candidates, target, n);
	return ans;
}

void solve_combinationSum() {
	vector<int> candidates = {2, 3, 6, 7};
	int target = 7;
	for (auto it : combinationSum(candidates , target)) {
		for (auto a : it) cout << a << " ";
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////
void cal_subset1(int ind, vector<vector<int>> &ans, vector<int> &vec, vector<int>& candidates, int target, int n) {
	if ( target == 0 ) {
		ans.push_back(vec);
		return;
	}


	for (int i = ind ; i < n ; i++) {
		if (i > ind && candidates[i]  == candidates[i - 1]) continue;
		if (candidates[i] > target) break;

		vec.push_back(candidates[i]);
		cal_subset1(i + 1, ans, vec, candidates, target - candidates[i], n);
		vec.pop_back();
	}

}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> vec;
	int n = candidates.size();
	sort(candidates.begin(), candidates.end());
	cal_subset1(0, ans, vec , candidates, target, n);
	return ans;
}
void solve_combinationSum2() {
	vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;
	for (auto it : combinationSum2(candidates , target)) {

		for (auto a : it) cout << a << " ";
		cout << endl;
	}
}

//////////////////////////////////////////////////
// 131. Palindrome Partitioning
bool isPalidrome1(string s, int l , int h) {
	while (l <= h ) if (s[l++] != s[h--]) return false;
	return true;
}
void func(int ind, string s, vector<vector<string>> &ans, vector<string> &path) {
	if (ind == s.size()) {
		ans.push_back(path);
		return;
	}

	for (int i = ind; i < s.size(); i++) {
		if (isPalidrome1(s, ind, i)) {
			path.push_back(s.substr(ind, i - ind + 1));
			func(i + 1, s, ans, path);
			path.pop_back();
		}
	}

}
vector<vector<string>> partition(string s) {
	vector<vector<string>> ans;
	vector<string> path;
	func(0, s, ans, path);
	return ans;
}

void void_partition() {
	string s = "aabb";
	for (auto vec : partition(s)) {
		cout << " [ ";
		for (auto str : vec) cout << str << " ";
		cout << " ] ";
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////
// 22. Generate Parentheses
void addingPair(vector<string> &ans, string str, int n, int m) {
	if (n == 0 && m == 0) {
		ans.push_back(str);
		return;
	}
	if (n > 0) addingPair(ans, str + "(", n - 1, m + 1);
	if (m > 0) addingPair(ans, str + ")",  n, m - 1);
}
vector<string> generateParenthesis(int n) {
	vector<string> ans;
	addingPair(ans, "", n, 0); // n = rightPairCount, m = RightPairCount
	return ans;
}

void solve_generateParenthesis() {
	int n = 3;
	for (auto it : generateParenthesis(n))cout << it << endl;
}

////////////////////////////////////
// generate_greyCode another approach
// return integer value not string
// 89. Gray Code


vector<string> generate(int n) {
	if (n == 1) return {"0", "1"};

	vector<string> recAns = generate(n - 1);
	vector<string> mainAns;

	for (int i = 0; i < recAns.size(); i++) {
		string str = recAns[i];
		mainAns.push_back("0" + str);
	}

	for (int i = recAns.size() - 1; i >= 0; i--) {
		string str = recAns[i];
		mainAns.push_back("1" + str);
	}
	return mainAns;
}
vector<int> grayCode(int n) {
	vector<string> res = generate(n);
	vector<int> ans;
	for (auto i : res) {
		ans.push_back(stoi(i, 0, 2));
	}
	return ans;
}

void solve_grayCode() {
	int n = 3;
	for (auto i : grayCode(n)) cout << i << endl;
}

////////////////////////////////////////////////////////////
// 17. Letter Combinations of a Phone Number
void phone_comb(string digits, string output, string mapping[], vector<string> &ans, int ind) {
	if (ind == digits.length()) {
		ans.push_back(output);
		return;
	}

	int num = digits[ind] - '0';
	string val = mapping[num];

	for (int i = 0; i < val.length(); i++) {
		output.push_back(val[i]);
		phone_comb(digits, output, mapping, ans, ind + 1);
		output.pop_back();
	}
}
vector<string> letterCombinations(string digits) {
	vector<string> ans;
	if (digits.length() == 0) return ans;
	string output;
	string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	phone_comb(digits, output, mapping, ans, 0);
	return ans;
}

void solve_letterCombinations() {
	string digits = "23";
	for (auto it : letterCombinations(digits)) cout << it << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////
// 216. Combination Sum III
// taking much  time => TC 0(2^n)
void solve(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int target, int k, int sum) {
	if (ind == nums.size()) {
		if (temp.size() == k && sum == target)
			ans.push_back(temp);
		return;
	}

	temp.push_back(nums[ind]);
	sum += nums[ind];
	solve(ind + 1, nums, ans, temp, target , k, sum);
	temp.pop_back();
	sum -= nums[ind];
	solve(ind + 1, nums, ans, temp, target , k, sum);

}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<int> nums;

	for (int i = 1; i <= 9; i++) nums.push_back(i);
	vector<vector<int>> ans;
	vector<int> temp;
	int target = n;
	solve(0, nums, ans, temp, target, k, 0);
	return ans;
}

// 2nd approach
void solve_1(vector<vector<int>> &ans, vector<int> &temp, int target, int k, int start , int end) {
	if (target == 0 && temp.size() == k) {
		ans.push_back(temp);
		return;
	}

	for (int i = start; i <= end; i++) {
		temp.push_back(i);
		solve_1(ans, temp, target - i, k , i + 1 , end);
		temp.pop_back();
	}
}
vector<vector<int>> combinationSum3_1(int k, int n) {
	int start = 1, end = n - k; // 1 to  n - k
	vector <vector<int>> ans;
	vector<int> temp;
	int target = n;
	solve_1(ans, temp, target, k, start , end);
	return ans;
}

void solve_combinationSum3() {
	int k = 3, n = 9;
	for (auto i : combinationSum3(k, n)) {
		// for (auto i : combinationSum3_1(k, n)) {
		for (auto it : i) cout << it << " ";
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////
// 494. Target Sum
int solve_targetSum(int i, vector<int> &nums, int target, int count) {
	if (i >= nums.size()) {
		if (count == target) return 1;
		return 0;
	}

	int left = solve_targetSum(i + 1, nums, target, count + nums[i]);
	int right = solve_targetSum(i + 1, nums, target, count - nums[i]);
	return (left + right);
}
int findTargetSumWays(vector<int>& nums, int target) {
	return solve_targetSum(0, nums, target, 0);
}

void solve_findTargetSumWays() {
	vector<int> nums = {1, 1, 1, 1, 1};
	int target = 3;
	cout << findTargetSumWays(nums, target);
}

/////////////////////////////////////////////////////////
// 784. Letter Case Permutation
void child_letterCase(int i , vector<string> &ans, string &s) {
	if (i == s.length()) {
		ans.push_back(s);
		return;
	}

	// save intial value
	char c = s[i];
	cout << " c " << c << " ";
	//  path1: toggle lower/upper case
	s[i] = islower(c) ? toupper(c) : tolower(c);
	child_letterCase(i + 1, ans, s);

	if (isalpha(c)) {

		// path2 : same same char in the string
		s[i] = c;
		child_letterCase(i + 1, ans, s);
	}
}
vector<string> letterCasePermutation(string s) {
	vector<string> ans;
	child_letterCase(0, ans, s);
	return ans;
}

//////////////// 2nd approach
void add(char c, int pos, vector<string> &ans, int &cnt) {
	int i = 0;
	while (i < cnt) {
		string x = ans[i];
		x[pos] = c;
		ans.push_back(x);
		i++;
	}
	cnt += cnt;
}


vector<string> letterCasePermutation1(string s) {
	vector<string> ans;
	int cnt = 1;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	ans.push_back(s);

	for (int i = 0; i < s.length(); i++)
		if (isalpha(s[i]))
			add(toupper(s[i]), i, ans, cnt);
	return ans;
}
void solve_letterCasePermutation() {
	string s = "a1B2";
	cout << endl;
	for (auto it : letterCasePermutation(s)) cout << it << endl;
	// for (auto it : letterCasePermutation1(s)) cout << it << endl;
}

//////////////////////////////////////////////////
// Number of paths
// ref => https://practice.geeksforgeeks.org/problems/number-of-paths0926/1
// ref => https://www.youtube.com/watch?v=sLuKQ9mZFz0
long long  numberOfPaths(int m, int n)
{
	if (m == 1 || n == 1) return 1;
	return numberOfPaths(m , n - 1) + numberOfPaths(m - 1, n);
}

long long  numberOfPaths1(int m, int n)
{
	vector<vector<int>> mat(m , vector<int> (n , 1));

	for (int i = 1; i < m ; i++) {
		for (int j = 1; j < n ; j++) {
			mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
		}
	}
	return mat[m - 1][n - 1];

}

long long  numberOfPaths2(int m, int n)
{
	// 1 1 1
	// [1, 3, 6]
	vector<int> dp(n , 1); // 1 1 1
	for (int i = 0; i < m - 1 ; i++) {
		for (int j = 1; j < n ; j++) { // 0 1, 0 2
			dp[j] += dp[j - 1];
			// cout << dp[j]  << " dp[j]  " << j << " j " << i << " i " << endl;
		}
		// cout << " this new " << endl;
	}
	//start // 1 1 1
	// i = 0 => // 1 2 3
	// i = 1 => // 1 3 6 
	return dp[n - 1];

}

void solve_numberOfPaths() {
	int m = 4 , n = 4;
	// cout << numberOfPaths(m , n);
	// cout << numberOfPaths1(m , n);
	cout << numberOfPaths2(m , n);
}


int main() {
	// solve_rev_arr();
	// solve_binarySearch();
	// solve_isPalidrome();
	// solve_subSequenceOfArray();
	// solve_subSequenceOfArray_k();
	// solve_subSequenceOfArray_k_count();
	// solve_countSubsetWhoseSum();
	// solve_findPaths();
	// solve_findPaths1();
	// solve_findPathRate();
	// solve_countPths();
	// solve_singleSubSequnce();
	// solve_NQueen();
	// solve_NQueen1();
	// solve_permute();
	// solve_permute_1();
	// solve_generate_greyCode();
	// solve_subsetsWithDup();
	// solve_combinationSum();
	// solve_combinationSum2();
	// void_partition();
	// solve_generateParenthesis();
	// solve_grayCode() ;
	// solve_letterCombinations();
	// solve_combinationSum3();
	// solve_findTargetSumWays();
	// solve_letterCasePermutation();
	solve_numberOfPaths();
}