#include <bits/stdc++.h>
using namespace std;

////////////////////////
// Find first set bit
unsigned int getFirstSetBit(int n)
{
	int cnt = 1;
	while (n != 0) {
		if (n & 1)  return cnt;
		n = n >> 1;
		cnt++;
	}
}

void solve_getFirstSetBit() {
	int n = 18;
	cout << getFirstSetBit(n);
}


////////////////////////////////
// Rightmost different bit
int posOfRightMostDiffBit(int m, int n)
{
	int cnt = 1;
	if (m == n) return -1;
	while (n > 0 || m > 0) {
		if ((n % 2) != (m % 2)) return cnt;
		cnt++;
		m = m >> 1;
		n = n >> 1;
	}
	return -1;
}

int posOfRightMostDiffBit1(int m, int n) {
	if (m == n) return -1;
	int x = m ^ n; // only diffrence bit remains remains
	int cnt = 1;
	// m = 11 => 1 0 1 1
	// n = 9  => 1 0 0 1
	// -----------------
	// m ^ n => 0 0 1 0 // when diffrent bit comes than ans is only come 1 in xor operation
	while (x != 0) {
		if (x & 1) return cnt;
		cnt++;
		x = x >> 1;
	}
	return -1;

}
void solve_posOfRightMostDiffBit() {
	int m = 11 , n = 9;
	// cout << posOfRightMostDiffBit(m, n);
	cout << posOfRightMostDiffBit1(m, n);
}

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


/////////////////////////////////////////
// Count total set bits from 1 to n
int countSetBits(int n)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) { // O(nlogn)
		int j = i;
		while (j != 0) {
			if (j & 1) cnt++;
			j = j >> 1;
		}
	}
	return cnt;
}

// ref => https://www.youtube.com/watch?v=g6OxU-hRGtY (papcoding youtube channel)
int largestPowerOf2(int n) {
	int x = 0;
	while ((1 << x) <= n) x++;
	return x - 1;
}
int countSetBits1(int n) {
	if (n == 0) return 0;
	int x = largestPowerOf2(n);
	int bitsetUpto2raiseTox  = (1 << (x - 1)) * x;
	// reaning bit from 2 raiseto power x to n
	int reamaningBit = n - (1 << x) + 1;
	int rest = n - (1 << x);
	int ans = bitsetUpto2raiseTox + reamaningBit + countSetBits1(rest);
	return ans;
}

void solve_countSetBits() {
	int n = 4;
	// cout << countSetBits(n);
	cout << countSetBits1(n);
}
////////////////////////////////////////////
// Bit Difference
int countBitsFlip(int a, int b) {
	int x = a ^ b;
	int cnt = 0;
	while (x != 0) {
		if (x & 1 ) cnt++;
		x = x >> 1;
	}
	return cnt;
}

int countBitsFlip1(int a, int b) {
	int x = a ^ b;
	int cnt = 0;
	while (x != 0) {
		cnt = cnt + (x & 1);
		x = x >> 1;
	}
	return cnt;
}

int countBitsFlip2(int a, int b) {
	int x = a ^ b;
	int cnt = 0;
	while (x != 0) {
		// cout << x << " " << (x - 1) << endl;
		x = x & (x - 1);
		// cout << "x " << x << endl;
		cnt++;
	}
	return cnt;
}

void solve_countBitsFlip() {
	int a = 10, b = 20;
	// cout << countBitsFlip(a, b);
	// cout << countBitsFlip1(a, b);
	cout << countBitsFlip2(a, b);
}

/////////////////////////////////////////////////
//  Number is sparse or not
bool isSparse(int n) {
	int cnt = 0;
	while (n != 0) {
		if (n & 1) cnt++;
		else cnt = 0;
		if (cnt > 1) return false;
		n = n >> 1;
	}
	return true;
}

bool isSparse1(int n) {
	return ((n & (n >> 1)) == 0);
}
void solve_isSparse() {
	int n = 16;
	// cout << isSparse(n);
	cout << isSparse1(n);
}

////////////////////////////////////////////////////////
// Longest Consecutive 1's
int maxConsecutiveOnes(int N) {
	int cnt = 0;
	int mx = 0;
	while (N != 0) {
		if (N & 1) cnt++;
		else cnt = 0;
		mx = max(mx, cnt);
		N = N >> 1;
	}
	return mx;
}

int maxConsecutiveOnes1(int N) {
	int cnt = 0;
	while (N != 0) {
		N = (N & (N >> 1));
		cnt++;
	}
	return cnt;
}
void solve_maxConsecutiveOnes() {
	int n = 14;
	// cout << maxConsecutiveOnes(n);
	cout << maxConsecutiveOnes1(n);
}
////////////////////////////////////////////
int greyConverter(int n)
{
	return (n ^ (n >> 1));
}

int solve_greyConverter() {
	int n = 7;
	cout << greyConverter(7);
}

//////////////////////////////////////
int grayToBinary(int n)
{
	int res = 0;
	while (n != 0) {
		res ^= n;
		// cout << " res " << res << endl;
		n = n >> 1;
	}
	return res;
}

void solve_grayToBinary() {
	int n = 4;
	cout << grayToBinary(n);
}

/////////////////////////////////////////
// Power of 2
bool isPowerofTwo(long long n) {
	if (n == 0) return false;
	if (n == 1) return true;
	int i = 1;
	int ans;
	if (n & 1) return false; // number is odd than it is false
	while (i) {
		ans = 1 << i ;
		if (ans == n) return true;
		if (ans > n) return false;
		i++;
	}
}

bool isPowerofTwo1(long long n) {
	int res  = 0;
	while (n != 0) {
		n = (n & (n - 1)); // power of 2 containt only 1 set bit that's why loop iterate only 1 time.
		res++;
	}
	if (res == 1) return true;
	return false;
}

void solve_isPowerofTwo() {
	int n = 3;
	// cout << isPowerofTwo(n);
	cout << isPowerofTwo1(n);
}

///////////////////////////////////////////////
// ref => https://www.youtube.com/watch?v=GbH8PcqKosk
// Swap all odd and even bits
unsigned int swapBits(unsigned int n) {
	int od = 0x55555555; // mask for odd -> because all the odd bit are 1
	int ev = 0xAAAAAAAA; // mask for even -> because all the even bits are 1

	int odds = (n & od); // preserve odd bits
	int evens = (n & ev); // preserve even bits

	odds <<= 1; // odd bits are became evens
	evens >>= 1; // evens bits are becams odd

	n = odds | evens; // now bits are completely shifted
	return n;
}

void solve_swapBits() {
	int n = 23;
	cout << swapBits(n);
}

///////////////////////////////////////////////////
int maxAND(int arr[], int  n) {
	int res = 0;
	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {
			int m = (arr[i] & arr[j]);
			res = max(res, m);
		}
	}

	return res;
}


int checkBit(int pattern, int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if ((pattern & arr[i]) == pattern)
			count++;
	}

	return count;
}
// Function for finding maximum AND value.
int maxAND1(int arr[], int N)
{
	int res = 0, count ;
	// take 31 bit to 0 bit , because total bit in the the number is 32
	for (int bit = 31 ; bit >= 0; bit--) {
		count = checkBit((res | (1 << bit)), arr, N);

		if (count >= 2) {
			res |= (1 << bit);
		}
	}
	return res ;
}
void solve_max_AND_value() {
	int arr[] = {4, 8, 12, 16};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxAND1(arr, n);
}

/////////////////////////////////////////
void  swap_number(int a, int b) {
	// swap two number using bitwise xor
	cout << a << " " << b << "\n" ;
	a =  a ^ b;
	b = a ^ b ;
	a = a ^ b;
	cout << a  << " " << b;
}

///////////////////////////
int print_int(int arr[], int n) {
	// evry integer occurs twise one integer occures one's so print that int
	int XOR	 = 0;
	// map<int, int> mp;
	for (int i = 0; i < n; i++) {
		// mp[arr[i]]++;
		XOR ^= arr[i];
	}
	// for (auto it : mp) {
	// 	if (it.second  == 1) cout << it.first << "\n";
	// }
	return XOR;
}

////////////////////////////////////
// find missing number from the range in the array
int find_missing_number(int arr[], int n) {
	int mx = *max_element(arr, arr + n);
	int mn = *min_element(arr, arr + n);
	int result = 0;
	for (int i = 0; i < n; i++) result ^= arr[i]; // xor all the numbers
	for (int i = mn; i <= mx; i++) result ^= i; // number that match cancel but number that not match becomes result
	return result;
}

void solve_find_missing_number() {
	// find the missing number from array
	int arr[] = { 1, 4, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << find_missing_number(arr, n);
}

//////////////////////////////////////////////
// powerset using bitwise operator
void powerset(string str, int n) {
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((i & 1 << j)) cout << str[j] << "";
		}
		cout << "\n";
	}
}

void solve_powerset( ) {
	string str = "abc";
	int n = str.length();
	powerset(str, n);
}

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
int main() {
	// solve_getFirstSetBit();
	// solve_posOfRightMostDiffBit();
	// solve_checkKthBit();
	// solve_countSetBits() ;
	// solve_countBitsFlip();
	// solve_isSparse();
	// solve_maxConsecutiveOnes();
	// solve_greyConverter();
	// solve_grayToBinary();
	// solve_isPowerofTwo();
	// solve_swapBits();
	// solve_max_AND_value();
	// solve_find_missing_number();
	// solve_powerset();
	// solve_sumBitDifference();
	// solve_solve_0();
	// solve_xorQueries();
	solve_totalHammingDistance();
}