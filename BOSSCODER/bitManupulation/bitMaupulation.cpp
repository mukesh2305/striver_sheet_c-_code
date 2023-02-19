#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////
// Check whether K-th bit is set or not
bool checkKthBit(int n, int k)
{
	if (((n >> k) & 1)) return true ;
	else false;
}

bool checkKthBit1(int n, int k)
{
	// cout << (n & (1 << k)) << endl;
	if ((n & (1 << k))) return true ; // 4 same
	else false;
}
void solve_checkKthBit() {
	int n = 4, k = 2;
	// cout << checkKthBit(n , k);
	cout << checkKthBit1(n , k);
}
////////////////////////////
// find least singnificant bit that is set
int leastSignificantBit(int n) {
	int cnt = 1;
	while (n != 0) {
		if (n & 1) return cnt;
		n = n >> 1;
		cnt++;
	}
	return cnt;
}

void solve_leastSignificantBit() {
	int n = 11;
	cout << leastSignificantBit(n);
}
//////////////////////////////////////////////
// every element is apper twise find element that apper onece
int findEle(int arr[], int n) {
	int ans = 0;
	for (int i = 0; i < n ; i++) {
		ans = ans ^ arr[i];
	}
	return ans;
}

void solve_findEle() {
	int arr[] = {1, 2, 3, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findEle(arr, n);
}

/////////////////////////////////////////////////
// given array in ecery number apper tharise expect one
int findEle1(int arr[], int n) {
	// HASHMAP => 1st approach => TC O(n) SC O(n)
	// SORTING => 2nd approach => TC O(nlog(n))

	// bitApproach => 3rd approach => TC O(1);
	// string ans = "";
	int ans = 0;
	for (int i = 0 ; i < 32; i++) {
		int cnt = 0;
		int x = (1 << i);
		for (int j = 0; j < n ; j++) {
			int temp = arr[j];
			if ((temp & x)) cnt++;
		}
		// if(cnt % 3 == 1) ans += '1';
		// else ans += '0';
		if (cnt % 3 == 1) ans |= x;
	}
	// reverse(ans.begin(), ans.end());
	// return (int)ans;
	return ans;
}

void solve_findEle1() {
	int arr[] = {1, 2, 2, 1, 3 , 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findEle1(arr, n);
}

//////////////////////////////////////////
// 260. Single Number III
vector<int> singleNumber(vector<int>& nums) {
	long  XOR = 0;
	for (auto num : nums) XOR ^= num;
	long lastSetBit = XOR & -XOR;
	int first = 0, second = 0;
	for (int num : nums) {
		if ((num & lastSetBit) == lastSetBit) first ^= num;
		else second ^= num;
	}
	return {(int)first, (int)second};
}

void solve_singleNumber() {
	vector<int> nums = {1, 1, 3, 5, 7, 6, 3, 6};
	vector<int> ans =  singleNumber(nums);
	for (int i : ans) cout << i << endl;
}
////////////////////////////////////////////////////
// given A[n] ans k find a pair of element whose xor = k , A[i] ^ A[J] = k
// brutforce 2 loop O(n^2)
// [3, 4, 5, 6, 7, 8]
// a ^ b = k
// a ^ a ^ b = a ^ k
// 7   5   2
// b = a ^ k
// 7 ^ 5 = 2
// 5 ^ 7 = 2
// 2 ^ 5 = 7
// 2 ^ 7 = 5

// ref BOSSCODER bitmanupulation video
vector<int> findEle2(vector<int> nums, int k) {
	map<int, int> mp;
	for (auto num : nums) mp[num]++;
	for (auto num : nums) {
		int val = num ^ k;
		// cout << num << " " << val << endl;
		if (mp.find(val) != mp.end()) return {(int)num, (int)val};
	}
	return {};
}
void solve_findEle2() {
	vector<int> nums = {3, 5, 6, 7, 8};
	vector<int> ans = findEle2(nums, 2);
	for (auto it : ans) cout << it << " ";
}

//////////////////////////////////////////////////////////
// 190. Reverse Bits
// ref => https://www.youtube.com/watch?v=-5z9dimxxmI
uint32_t reverseBits(uint32_t n) {
	if (n <= 0) return 0;

	uint32_t ans  = 0;
	// 0000 // 0100
	for (int i = 0; i < 32; i++) {
		ans <<= 1; // left shift
		// ans = ans | (n & 1);
		if (n & 1) ans++;
		n >>= 1; // right shift
	}
	return ans;
}

void solve_reverseBits() {
	uint32_t n = 5;
	cout << reverseBits(n);
}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////
// Sum of bit differences among all pairs // geeks for Geeks
// TC O(n^2 * logn)
int sumBitDifference(vector<int> &arr, int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < n ; j++) {
			int x = arr[i] ^ arr[j];
			int cnt = 0;

			//1st way
			// logn
			// cnt = 1;
			// while (x != 0) {
			// 	if (x & 1) cnt++;
			// 	x = x >> 1;
			// }

			//2nd way
			// logn
			while (x != 0) {
				x = (x & (x - 1));
				cnt++;
			}
			res +=  cnt;

			//3rd way
			// bitset<32> bt(x);
			// res += bt.count();
			// cout << bt.count() << " i " << i << " j " << j << endl;
			// cout << " i " << i << " j " << j << endl;

		}
	}

	return res;
}



// ref  => https://www.youtube.com/watch?v=L_fIn5TM3mM
// TC O(32 * n) => O(n) => // 32 is constant we cannot count
int sumBitDifference1(vector<int> &arr, int n) {
	long res = 0;

	for (int i = 0; i < 32; i++) {
		long cntOn = 0; // count of on last bit

		for (int val : arr)
			if ((val & (1 << i)) != 0) cntOn++;

		long  cntOff = arr.size() - cntOn; // count of off last bit
		long diff = cntOn * cntOff * 2;
		res += diff;
	}

	return res;
}

void solve_sumBitDifference() {
	vector<int> arr = {1, 2, 3};
	int n = arr.size();
	cout << sumBitDifference(arr, n);
	// cout << sumBitDifference1(arr, n);
}


///////////////////////////////////////////////////////////////////////////////////
// https://www.geeksforgeeks.org/check-whether-an-array-can-be-made-0-by-splitting-and-merging-repeatedly/

// Check whether an Array can be made 0 by splitting and merging repeatedly

/*
If any element in the array is even then it can be made 0.
 	Split that element in two equal parts of arr[i]/2 and arr[i]/2.
 	XOR of two equal numbers is zero. Therefore this strategy makes an element 0.

If any element is odd. Split it into two parts: 1 and arr[i]-1.
 	Since arr[i]-1 is even, it can be made 0 by the above strategy.
  	Therefore an odd element can reduce its size to 1.
  	Two odd elements can, therefore, be made 0 by following the above strategy and finally XOR them (i.e. 1) as 1 XOR 1 = 0.
  	Therefore if the number of odd elements in the array is even, then the answer is possible.
 	Otherwise, an element of value 1 will be left and it is not possible to satisfy the condition.
*/
string solve_0(vector<int> &arr) {
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++)
		if (arr[i] % 2 == 1) cnt++;

	if (cnt % 2 == 0) return " YES \n";
	else return " NO \n";
}

void solve_solve_0() {
	vector<int> arr = { 9, 17};
	cout << solve_0(arr);
}

////////////////////////////////////////////////////////////////
// 1310. XOR Queries of a Subarray
// naive solution
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
	vector<int> vec;
	for (int i = 0; i < queries.size(); i++) {
		int res = 0;
		for (int j = queries[i][0] ; j <= queries[i][1]; j++) {
			res ^= arr[j];
		}
		vec.push_back(res);
	}
	return vec;
}

// optimal solution
vector<int> xorQueries1(vector<int>& arr, vector<vector<int>>& queries) {
	vector<int> pref{0}, ans; // pref[0] = 0;

	for (auto num : arr)
		pref.push_back(num ^ pref.back());

	for (auto q : queries) ans.push_back(pref[q[0]] ^ pref[q[1] + 1]);
	return ans;
}
void solve_xorQueries() {
	vector<int>  arr = {1, 3, 4, 8};
	vector<vector<int>> queries = {
		{0, 1}, {1, 2}, {0, 3}, {3, 3}
	};

	// for(auto it : xorQueries(arr, queries)) cout << it << " ";
	for (auto it : xorQueries1(arr, queries)) cout << it << " ";
}

/////////////////////////////////////////////
// 477. Total Hamming Distance
// ref  => https://www.youtube.com/watch?v=L_fIn5TM3mM
// TC O(32 * n) => O(n) => // 32 is constant we cannot count
int totalHammingDistance(vector<int> &nums) {
	long res = 0;
	for (int i = 0; i < 32; i++) {
		long cntOn = 0; // count of on last bit

		for (int val : nums)
			if ((val & (1 << i)) != 0) cntOn++;

		long  cntOff = nums.size() - cntOn; // count of off last bit
		long diff = cntOn * cntOff;
		res += diff;
	}
	return res;
}

void solve_totalHammingDistance() {
	vector<int> nums = {4, 14, 2};
	cout << totalHammingDistance(nums);
}

/////////////////////////////////////////////////////
// 74. Search a 2D Matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int r = matrix.size();
	int c = matrix[0].size();
	int i = 0, j =  c - 1;
	while (i < r && j >= 0) {
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target)
			j--;
		else i++;
	}
	return false;
}


void solve_searchMatrix() {
	vector<vector<int>> matrix = {
		{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}
	};
	int target = 3;
	cout << searchMatrix(matrix, target);
}
int main() {
	// solve_checkKthBit();
	// solve_leastSignificantBit();
	// solve_findEle();
	// solve_findEle1();
	// solve_singleNumber();
	// solve_findEle1() ;
	// solve_findEle2() ;
	// solve_reverseBits();
	// solve_sumBitDifference();
	// solve_solve_0();
	// solve_xorQueries();
	// solve_totalHammingDistance();
	solve_searchMatrix();
}