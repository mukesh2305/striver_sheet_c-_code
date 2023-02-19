#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////
// gcd of two number
// TC O(mn(a, b))
int gcd1(int a, int b) {
	int mn = min(a, b);
	for(int i = mn; i >= 1; i--) {
		if(a % i == 0 && b % i == 0) return i;
	}
}
// Efficient Approach for GCD
int gcd2(int a, int b) {
	if(a == 0) return b;
	return gcd2(b % a, a);
}
void solve_gcd() {
	int a = 8, b = 4;
	// cout << gcd1(a, b);
	cout << gcd2(a, b);
}
/////////////////////////////////////////////////////////
// 1979. Find Greatest Common Divisor of Array
int findGCD(vector<int>& nums) {
	int mn = INT_MAX;
	int mx = INT_MIN;

	for (int i = 0; i < nums.size(); i++) {
		mx = max(mx, nums[i]);
		mn = min(mn, nums[i]);
	}

	int ans = 1;
	for (int i = 1; i <= mx; i++) {
		if (mx % i == 0 && mn % i == 0) {
			ans = max(ans, i);
		}
	}
	return ans;
}
int findGCD1(vector<int>& nums) {
	int mn = INT_MAX;
	int mx = INT_MIN;

	for (int i = 0; i < nums.size(); i++) {
		mx = max(mx, nums[i]);
		mn = min(mn, nums[i]);
	}
	int mxDiv = gcd2(mx, mn);
	return mxDiv;
}
int solve_findGCD() {
	// vector<int> nums = {2, 5, 6, 9, 10};
	vector<int> nums = {7, 5, 6, 8, 3};
	// cout << findGCD(nums);
	cout << findGCD1(nums);
}

/////////////////////////////////////////////////
// 728. Self Dividing Numbers

// 1st approach
bool digitCheck(int n) {
	int digit = 0;
	int num = n;
	while (n != 0) {
		digit = n % 10;
		if (digit > 0 && num % digit == 0) {
			n = n / 10;
			continue;
		} else return false;
	}
	return true;
}
vector<int> selfDividingNumbers(int left, int right) {
	vector<int> ans;
	for (int i = left; i <= right ; i++) {
		if (i < 10) ans.push_back(i);
		else {
			if (i % 10 == 0) continue;
			if (digitCheck(i)) {
				ans.push_back(i);
			}
		}
	}
	return ans;
}

// 2nd approach
bool isSelfDividing(int num) {
  int n = num;
  while (n > 0) {
    int digit = n % 10;
    // If the number is not divisible by the digit, or if the digit is zero, return false
    if (digit == 0 || num % digit != 0) {
      return false;
    }
    n /= 10;
  }
  // Return true if all digits were checked
  return true;
}

vector<int> selfDividingNumbers1(int left, int right) {
  vector<int> res;
  for (int i = left; i <= right; i++) {
    if (isSelfDividing(i)) {
      res.push_back(i);
    }
  }
  return res;
}

void solve_selfDividingNumbers() {
	int left = 1, right = 22;
	// vector<int> ans = selfDividingNumbers(left, right);
	vector<int> ans = selfDividingNumbers1(left, right);
	for (auto it : ans) cout << it << " ";
}

////////////////////////////////////////////////////////
// 1512. Number of Good Pairs
int numIdenticalPairs(vector<int>& nums) {
	unordered_map<int, int> cnt;
	int res = 0;
	for (auto n : nums)
		res += cnt[n]++;
	return res;
}
int numIdenticalPairs1(vector<int>& nums) {
	int n = nums.size();
	int count = 0;
	unordered_map<int, int> mp;
	// for(int i = 0; i<n; i++)
	//     for(int j = i+1; j <n;j++)
	//         if(nums[i] == nums[j]) count++;
	for ( int i = 0; i < n; i++) {
		mp[nums[i]]++;
	}

	// pair = n * (n - 1) / 2
	// (1 : 3)  // 3 * ( 3 - 1) = 6 / 2 = 3
	// (2 : 1)  // 1 * (1 - 1 ) = 0 / 2 = 0
	// (3 : 2) // 2 * (2 - 1) = 2 / 2 = 1
	for (auto it : mp) {
		count = count + (it.second * (it.second - 1)) / 2 ;
	}
	return count;

}

void solve_numIdenticalPairs() {
	vector<int> nums = {1, 2, 3, 1, 1, 3};

	// cout << numIdenticalPairs(nums);
	cout << numIdenticalPairs1(nums);
}

///////////////////////////////////////////////////////
// 1281. Subtract the Product and Sum of Digits of an Integer
int subtractProductAndSum(int n) {
	int pro = 1;
	int sum = 0;
	int temp = n;
	while (temp != 0) {
		int val  = temp % 10;
		pro *= val;
		sum += val;
		temp /= 10;
	}
	return pro - sum;
}

void solve_subtractProductAndSum() {
	int n = 234;
	cout << subtractProductAndSum(n);
}
//////////////////////////////////////////////
//// 1688. Count of Matches in Tournament
int numberOfMatches(int n) {
	int match = 0;
	int sum = 0;
	while (n != 1) { // n = 2 (team are reamning than go inside the loop // if 1 team is reamaning than stop the loop)
		if (n & 1) {
			match = ((n - 1) / 2);
			sum += match;
			n = match + 1;
		} else {
			match = (n / 2);
			sum += match;;
			n = match;
		}
	}
	return sum;
}

void solve_numberOfMatches() {
	int n = 7;
	cout << numberOfMatches(n);
}
////////////////////////////////////////////////////
// 485. Max Consecutive Ones
int findMaxConsecutiveOnes(vector<int>& nums) {
	int n = nums.size();
	int mx = 0;
	unordered_map<int, int> m;
	for (int x : nums) {
		if (x == 1) ++m[1];
		else m[1] = 0;
		mx = max(m[1], mx);
	}
	return mx;
}

int findMaxConsecutiveOnes1(vector<int>& nums) {
	int count = 0;
	int res = 0;
	for (int i : nums){
		if (i == 1)count++;
		else count = 0;
		res = max(res, count);
	}
	return res;
}

void solve_findMaxConsecutiveOnes() {
	vector<int> nums = {1, 1, 0, 1, 1, 1};
	// cout << findMaxConsecutiveOnes(nums);
	cout << findMaxConsecutiveOnes1(nums);
}

//////////////////////////////////////////////////////////
// Largest number that divides x and is co-prime with y
// 1 : a divides x i.e. x % a = 0
// 2 : a and y are co-prime i.e. gcd(a, y) = 1
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

// function to find largest
// coprime divisor
int cpFact(int x, int y)
{
	while (gcd(x, y) != 1) {
		x = x / gcd(x, y);
	}
	return x;
}
void solve_cpFact() {
	int x = 15;
	int y = 3;
	cout << cpFact(x, y);
}

//////////////////////////////////////////////////
// 470. Implement Rand10() Using Rand7()
// int rand10() {
// 	int res  = 41;
// 	//The highest number res can be is 49.
// 	//The range of 41-49 is not a group of 10 which would make the randomization tilted towards nums 1-9
// 	//Discard any results that are 41 - 49 and reroll
// 	while (res > 40) {
// 		res = rand7() + (rand7() - 1) * 7;
// 	}
// 	// % 10 would return a 0 if res - 1 is divisible by 10. Offset by adding 1 to return range to 1 - 10 instead of 0 - 9
// 	return res = 1 + ((res - 1) % 10);
// }

// int rand10a() {
// 	return (rand7() * rand7() * rand7() * rand7() * rand7() * rand7()  ) % 11;
// }

////////////////////////////////////////////////////////////////
// 1390. Four Divisors
int sumFourDivisors(vector<int>& nums) {
	int sum = 0, cnt = 0;
	int mx = 0;
	for (auto n : nums) {
		sum = 0, cnt = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				cnt++;
				sum += i;
				if (i != n / i) {
					cnt++;
					sum += (n / i);
				}
			}
		}
		if (cnt == 4) mx += sum;
	}
	return mx;
}
void solve_sumFourDivisors() {
	// vector<int> nums = {21, 3, 7};
	vector<int> nums = {21, 21};
	cout << sumFourDivisors(nums);
}

//////////////////////////////////////////////////////////////
// Total number of divisors for a given number
int divisor(int n) {
	int cnt = 0;
	for (int i = 1 ; i * i <= n; i++) {
		if (n % i == 0) {
			cnt++;
			if (i != n / i) cnt++;
		}
	}
	return cnt;
}
void solve_divisior() {
	// int n = 25;
	int n = 24;
	cout << divisor(n);
}
//////////////////////////////////////////////
// 1185. Day of the Week
string dayOfTheWeek(int day, int month, int year)
{
	int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string dayName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int sum = 4;
	for (int i = 1971; i < year; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
		{
			sum += 366;
		}
		else
		{
			sum += 365;
		}
	}
	for (int i = 1; i < month; i++)
	{
		if (i == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
			sum += 1;
		}
		sum += months[i];
	}
	sum += day;

	return dayName[sum % 7];

}

void solve_dayOfTheWeek() {
	int day = 31, month = 8, year = 2019;
	cout << dayOfTheWeek(day, month, year);
}
/////////////////////////////////////////////////////////////////////////////
// 836. Rectangle Overlap
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
	int x1 = 0, x2 = 2, y1 = 1, y2 = 3;

	//this condition checks if the rec2 is inside rec1

	if (
	    ( rec2[x1] < rec1[x2] && rec2[x2] > rec1[x1])
	    &&
	    ( rec2[y1] < rec1[y2] && rec2[y2] > rec1[y1] ) ) {
		return true;
	}
	else
		return false;
}
void solve_isRectangleOverlap() {
	vector<int> rec1 = {0, 0, 2, 2};
	vector<int> rec2 = {1, 1, 3, 3};
	cout << isRectangleOverlap(rec1, rec2);
}

/////////////////////////////////////////////////
// 168. Excel Sheet Column Title
string convertToTitle(int c) {
	string k;
	while (c != 0)
	{
		c--;
		k += char((c % 26) + 65);
		c = c / 26;
	}
	reverse(k.begin(), k.end());
	return k;
}


void solve_convertToTitle() {
	int c = 701;
	cout << convertToTitle(c) << endl;
}
////////////////////////////////////////////////////////////
//=====> from rand6() to rand7();
// int rand9() {
// 	int x = rand6();
// 	int y = rand6();
// 	int v = (x - 1) * 6 + y;
// 	return v % 9 + 1;
// }

// => 2nd approach for rand10() from rand7();
// int rand10() {
// 	int row, col, idx;
// 	do {
// 		row = rand7();
// 		col = rand7();
// 		idx = col + (row - 1) * 7;
// 	} while (idx > 40);
// 	return 1 + (idx - 1) % 10;
// }
//=====> from rand5() to rand7();
// int rand9() {
// 	int x = rand6();
// 	int y = rand6();
// 	int v = (x - 1) * 6 + y;
//  if(v >= 22) return rand7(); // because of unequal distrubution // ref => math1 bosscoder lectures
// 	return v % 9 + 1;
// }

////////=> from big to small => eg => from rand5() to rand3()
// int rand3();
// {
// 	int x = rand5();
// 	if (x > 3) return rand3();
// 	return x % 3 + 1;
// }

////////////////////////////////////////////////////////
// GCD and HCF is same thing
int GCD(int a, int b) {
	int mx = 0;
	for (int i = 1; i <= min(a, b); i++)
		if (a % i == 0 && b % i == 0)
			mx =  i;
	return mx;
}

// ref => bosscoder TC => O(log(max(a,b)))
int GCD1(int a, int b) {
	// a => rem
	// b => divisor
	if (a == 0) return b;
	return GCD1(b % a, a);
}

void solve_GCD() {
	int a = 4 , b = 16;
	// cout << GCD(a, b);
	cout << GCD1(a, b);
}

///////////////////////////////////////////////////////////
// gcd(a, b, c) = gcd(gcd(a, b), c) = gcd(gcd(a, c), b) = gcd(gcd(b , c), a) // saem thing
// gcd of array
int gcdOfArray(vector<int> arr) {
	int ans = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		ans = GCD1(arr[i], ans);
		if (ans == 1) return 1;
	}
	return ans;
}

void solve_gcdOfArray() {
	vector<int> arr = {4, 15, 14, 6};
	cout << gcdOfArray(arr);
}

//////////////////////////////////////////////////////////////////
// subsquence => continuious / non-continues
/////////////////////////////////////////////////
// totoal divisor count is even or odd
string countDivisorEvenOrOdd(int n) {
	int x = (int)sqrt(n);
	if (x * x == n) return "odd";
	return "even";
}

void solve_countDivisorEvenOrOdd() {
	int n = 24;
	cout << countDivisorEvenOrOdd(n);
}

///////////////////////////////////////////
// n is prime or not
bool isPrime(int n) {
	if (n == 1 || n == 0) return false;
	if (n == 2 || n == 3 ) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve_isPrime() {
	int n = 7;
	if (isPrime(n)) cout << "prime number" << endl;
	else cout << "not a prime number" << endl;
}

///////////////////////////////////////////////
// non-negative number array find pairs that is divisiable by m
int pairCount(vector<int> arr, int m) {
	int cnt = 0;
	for (int i = 0; i < arr.size() ; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			int val = arr[i] + arr[j] ;
			if (val % m == 0) cnt ++;
		}
	}
	return cnt;
}

int pairCount1(vector<int> arr, int m) {
	map<int, int> mp;
	int ans = 0;
	// 2 2 1 3 1 3
	for (int i = 0; i < arr.size(); i++) {
		int rem = arr[i] % m;
		if (rem != 0)
			ans += mp[m - rem];
		else ans += mp[0];
		mp[rem]++;
		// for(auto it : mp) cout << " { " << it.first << " , " << it.second << " } " <<  endl;
		// cout << " rem " << rem << " " << " ans " << ans << endl<< endl;
	}
	return ans;
}

void solve_pairCount() {
	// vector<int> arr = {2, 2, 1, 7, 5, 3};
	vector<int> arr = {1, 2 , 3, 4, 5};
	// 1 2 2 3 5 7
	// cout << pairCount(arr, 4);
	cout << pairCount1(arr, 2);
}

////////////////////////////////////////////////////
// 2183. Count Array Pairs Divisible by K
long long countPairs(vector<int>& nums, int k) {
	long long ans = 0;
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++)
	{
		int num1 = __gcd(nums[i], k);
		// int needed_num = k / gcd;
		// cout << " gcd " << gcd << " needed_num " << needed_num << endl;
		for (auto num2 : m)
		{
			if (num1 * num2.first % k  == 0)
				ans += num2.second;
		}
		m[num1]++;

	}

	return ans;
}

void solve_countPairs() {
	vector<int> nums = {1, 2, 3, 4, 5};
	cout << countPairs(nums, 2);
}
/////////////////////////////////////////////////////////////
// 62. Unique Paths
long long uniquePaths(int m, int n) {
	vector<vector<long long>> vec(m, vector<long long>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0) {
				vec[i][j] = 1;
			}
			else {
				vec[i][j] = vec[i][j - 1] + vec[i - 1][j];
			}
		}
	}
	return vec[m - 1][n - 1];
}
int f_uni(int i, int j, vector<vector<int>> & dp) {
	if (i == 0 && j == 0) return 1;
	if (i < 0 || j < 0) return 0;

	if (dp[i][j] != -1) return dp[i][j];
	int up = f_uni(i - 1, j, dp);
	int left = f_uni(i, j - 1, dp);
	return dp[i][j] = up + left;
}
int uniquePaths1(int m, int n) {
	vector<vector<int>> dp(m , vector<int> (n , -1));
	return f_uni(m - 1, n - 1, dp);
}

void solve_uniquePaths() {
	int m = 3, n = 2;
	// cout << uniquePaths(m , n);
	cout << uniquePaths1(m , n);
//  1   1
// --- ---
//  1   2
// --- ---
//  1   3
// --- ---
}
///////////////////////////////////////////////////
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
	// Calculate area for Each reactangels
	int areaA = (ax2 - ax1) * (ay2 - ay1); // length * width
	int areaB = (bx2 - bx1) * (by2 - by1); // length * width

	// Calculate Overlap area length
	int left = max(bx1, ax1);
	int right = min(bx2, ax2);

	// Calculate Overlap area width
	int bottom = max(ay1, by1);
	int top = min(ay2, by2);

	// find if there is any overlap area
	int overlap = 0;
	if (right > left && top > bottom) {
		overlap = (right - left) * (top - bottom);
	}
	return areaA + areaB - overlap;
}

void solve_computeArea() {
	int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
	cout << computeArea( ax1 , ay1 , ax2 , ay2 , bx1 , by1 , bx2 , by2 );
}

//////////////////////////////////////////
// 1497. Check If Array Pairs Are Divisible by k
bool canArrange(vector<int>& arr, int k) {
	map<int, int> mp;
	int n = (int)arr.size();
	for (auto a : arr) mp[(a % k + k) % k]++;
	if (mp[0] % 2 == 1) return false;
	for (int i = 1; i < k ; i++) if (mp[i] != mp[ k - i]) return false;
	return true;
}

void solve_canArrange() {
	vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
	int k = 5;
	cout << canArrange(arr, k);
}

/////////////////////////////////////////////////
// Subsequences of size three in an array whose sum is divisible by m
int countSub(int A[], int n, int m) {
	int sum = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n ; j++) {
			for (int k = j + 1; k < n ; k++) {
				sum = A[i] + A[j] + A[k];
				if (sum % m == 0) {
					ans++;
				}
			}
		}
	}
	return ans;
}

// optimal approach is reamaning

void solve_countSub() {
	int A[] = {1, 2, 3, 4};
	int n = sizeof(A) / sizeof(A[0]);
	cout << countSub(A, n, 3);
}

//////////////////////////////////////
long long trailingZeroes(int n) {
	// Explanation : In any factorial when a powerof(5) occur then a trailing zero increases.
	int ans = 0;
	while (n >= 5) {
		ans += n / 5;
		n = n / 5;
	}
	return ans;
}

void solve_trailingZeroes() {
	int n = 5;
	cout << trailingZeroes(n);
}

/////////////////////////////////////////////
// next permutation
// ref => https://www.youtube.com/watch?v=W9SIlE2jhBQ
// TC O(n * n)
// SC O(n)
string getPermutation(int n , int k) {
	int fact = 1;
	vector<int> numbers;
	for (int i = 1; i < n ; i++) {
		fact *= i;
		numbers.push_back(i);
	}
	numbers.push_back(n);
	string ans = "";
	k -= 1;

	while (true) {
		ans = ans + to_string(numbers[k / fact ]);
		numbers.erase(numbers.begin() + k / fact);
		if (numbers.size() == 0) break;
		k = k % fact;
		fact = fact / numbers.size();
	}
	return ans;
}

void solve_getPermutation() {
	int  n = 3, k = 3;
	cout << getPermutation(n , k);
}

////////////////////////////////////////////
// 878. Nth Magical Number
int nthMagicalNumber(int n, int a, int b) {
	int i = 2;
	int cnt = 0;
	long long  ans = 0;
	while (true) {
		if (i % a == 0 || i % b == 0) {
			cnt++;
		}
		if (cnt == n) {
			ans = i;
			break;
		}
		i++;
	}
	int m = 1000000007;
	return ans % m;

}

int nthMagicalNumber1(int n, int a, int b) {
	long  mod = 1000000007;
	long l = min(a, b), r = (long)n * min(a, b);

	// findinf GCD
	// while(B != 0) {
	// 	long tmp = A;
	// 	A = B;
	// 	B = tmp % A;
	// }

	long lcm = (a * b) / __gcd(a, b);

	while (l < r) {
		long m = l + (r - l) / 2;
		int temp = (m / a) + (m / b) - (m / lcm);
		if (temp < n) l = m + 1;
		else r  = m;
	}
	return (int)(l % mod);
}


void solve_nthMagicalNumber() {
	int n  = 3, a = 6, b = 4;
	// cout << nthMagicalNumber(n , a, b);
	cout << nthMagicalNumber1(n , a, b);
}
////////////////////////////////////////////////////////
// https://www.geeksforgeeks.org/find-nth-magic-number/
// A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5.
// First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….
int nthMagicNo(int n)
{
	int pow = 1, ans = 0;
	while(n != 0) {
		pow = pow * 5;
		if(n & 1)
			ans += pow;
		n = n >> 1; // remove bit n = n / 2;
	}
	return ans;
}

void solve_nthMagicNo() {
	int n = 5;
	cout << nthMagicNo(n);
}
int main() {
	solve_gcd();
	// solve_findGCD();
	// solve_selfDividingNumbers();
	// solve_numIdenticalPairs();
	// solve_subtractProductAndSum();
	// solve_numberOfMatches();
	// solve_findMaxConsecutiveOnes();
	// solve_cpFact();
	// solve_sumFourDivisors();
	// solve_divisior();
	// solve_dayOfTheWeek();
	// solve_isRectangleOverlap();
	// solve_convertToTitle();
	// solve_GCD();
	// solve_gcdOfArray();
	// solve_countDivisorEvenOrOdd();
	// solve_isPrime();
	// solve_pairCount();
	// solve_countPairs();
	// solve_uniquePaths();
	// solve_computeArea() ;
	// solve_canArrange();
	// solve_countSub();
	// solve_trailingZeroes();
	// solve_getPermutation();
	// solve_nthMagicalNumber();
	// solve_nthMagicNo() ;
}