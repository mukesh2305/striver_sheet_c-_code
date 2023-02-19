#include <bits/stdc++.h>
using namespace std;
// binary search
////////////////////////////////
// find Ele
int findEle(int arr[], int n, int x) {
	int l = 0, h = n - 1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (arr[mid] == x) return mid;

		else if (arr[mid] < x) l = mid + 1;

		else h = mid - 1;
	}
	return -1;
}

void solve_findEle() {
	int arr[] = {1, 2, 5, 7, 3};
	int x = 2;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findEle(arr, n , x);
}

/////////////////////////////////////////////////////////
// Given array of duplicates
// find out first occurence of x
// with => ans
int firstOccurence(int arr[], int n , int x) {
	int l = 0, h = n - 1;
	int ans = -1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		// if element find , then go left to find first occurence of element
		if (arr[mid] == x) {
			ans = mid;
			h = mid - 1;
		}
		else if (arr[mid] < x) l = mid + 1;
		else h = mid - 1;
	}
	return ans;
}

// without ans => variable
int firstOccurence1(int arr[], int n , int x) {
	int l = 0, h = n - 1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		// if element find , then go left to find first occurence of element
		if (arr[mid] == x) {
			h = mid - 1;
		}
		else if (arr[mid] < x) l = mid + 1;
		else h = mid - 1;
	}
	if (arr[l] != x) return -1;
	return l;
}

void solve_firstOccurence() {
	int arr[] = {1, 2, 2, 2, 3, 4, 4, 4, 5};
	int x = 6;
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << firstOccurence(arr, n , x);
	cout << firstOccurence1(arr, n , x);
}

////////////////////////////////////////////////////////
// Given array of duplicates
// find out last occurence of x
// with => ans variable
int lastOccurence(int arr[], int n, int x) {
	int l = 0, h = n - 1;
	int ans = -1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (arr[mid] == x) {
			ans = mid;
			l = mid + 1;
		}
		else if (arr[mid] < x) l = mid + 1;
		else h = mid - 1;
	}
	return ans;
}

// without => ans variable
int lastOccurence1(int arr[], int n, int x) {
	int l = 0, h = n - 1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (arr[mid] == x) {
			l = mid + 1;
		}
		else if (arr[mid] < x) l = mid + 1;
		else h = mid - 1;
	}
	if (arr[h] != x) return -1;
	return h;
}
void solve_lastOccurence() {
	int arr[] = {1, 2, 2, 2, 3, 4, 4, 4, 5};
	int x = 2;
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << lastOccurence(arr, n , x);
	cout << lastOccurence1(arr, n , x);
}


///////////////////////////////////////////////////////////////////
// lower bound of x
// first ele that is >= x (is lower bound of x)
// arr[] = {1, 3, 5, 7, 9, 10} x = 7 lowBound = 7
// arr[] = {1, 3, 5, 7, 9, 10} x = 6 lowBound = 7
// arr[] = {1, 3, 5, 7, 9, 10} x = 4 lowBound = 5
// arr[] = {1, 3, 5, 7, 9, 10} x = 11 lowBound = -1(not found)
// inbuilt method
int lowerBound(int arr[], int n, int x) {
	// give you the  index
	// inbuilt method
	int lb = lower_bound(arr + 0, arr + n, x) - arr;
	return lb;
}

int lowerBound1(int arr[], int n , int x) {
	int l = 0, h = n - 1;
	int ans = -1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (arr[mid] >= x) {
			ans = mid;
			h = mid - 1;
		}
		else if (arr[mid] < x)
			l = mid + 1;

	}
	return ans;
}

void solve_lowerBound() {
	int arr[] = {1, 3, 4, 6, 8, 8, 10, 12, 13};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 7;
	// cout << lowerBound(arr, n , x);
	cout << lowerBound1(arr, n , x);
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// upper bound of x
// first ele that is > x (is lower bound of x)
// arr[] = {1, 3, 5, 7, 9, 10} x = 7 upperBound = 9
// arr[] = {1, 3, 5, 7, 9, 10} x = 6 upperBound = 7
// arr[] = {1, 3, 5, 7, 9, 10} x = 4 upperBound = 5
// arr[] = {1, 3, 5, 7, 9, 10} x = 11 upperBound = -1(not found)
int upperBound(int arr[], int n, int x) {
	// first ele that is > x (is lower bound of x)
	int ub = upper_bound(arr + 0, arr + n, x) - arr;
	return ub;
}
int upperBound1(int arr[], int n, int x) {
	int l = 0, h = n - 1;
	int ans = -1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (arr[mid] <=  x)
			l = mid + 1;
		else if (arr[mid] > x) {
			ans = mid;
			h = mid - 1;
		}
	}
	return ans;
}

int solve_upperBound() {
	int arr[] = {1, 3, 4, 6, 8, 8, 10, 12, 13};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 8;
	cout << upperBound(arr, n , x);
	// cout << upperBound1(arr, n , x);
}

//////////////////////////////////////////////////////
// Given x, find number of occurence of x
int freqOfEle(int arr[], int n, int x) {
	// 1 3 5 7 7 7 10
	// 1st way
	// int ans = lastOccurence(arr, n , x) - firstOccurence(arr, n ,  x) + 1;
	// return ans;

	// 2way
	int lb = lower_bound(arr + 0, arr + n, x) - arr;
	int ub = upper_bound(arr + 0, arr + n, x) - arr;
	if (arr[lb] != x) return 0;
	return ub - lb;
}

void solve_freqOfEle() {
	int arr[] = {1, 3, 5, 7, 7, 7, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 7;
	cout << freqOfEle(arr, n , x);
}
//////////////////////////////////////////////
// Given Number n = 26 wanted to find integer sqrt(26) = 5
// i = 1 to i = 26
int sqroot(int n) {
	int l = 1, h = n;
	int ans = 1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (mid * mid <= n) {
			ans = mid;
			l = mid + 1;
		}
		else h = mid - 1;
	}
	return ans;
}

void solve_sqroot() {
	int n = 65;
	cout << sqroot(n);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////
// medium problem on leetcode
// 153. Find Minimum in Rotated Sorted Array
int findMin(vector<int>& nums) {
	int n = nums.size();
	int l = 0, h = n - 1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (nums[mid] < nums[h])
			h = mid;
		else l = mid + 1;
	}
	return nums[h]; // nums[l - 1]
}

int findMin1(vector<int>& nums) {
	int n = nums.size();
	int l = 0, h = n - 1;
	while (l < h) {
		int mid = l + (h - l) / 2;
		if (nums[mid] < nums[h])
			h = mid;
		else l = mid + 1;
	}
	return nums[l];
}

void solve_findMin() {
	vector<int> nums = { 7, 8, 9, 1, 2, 3, 4, 5, 6};
	// cout << findMin(nums);
	cout << findMin1(nums);
}

////////////////////////////////////////////////////////////
//154. Find Minimum in Rotated Sorted Array II
// they may containts DUPLICATES
int findMinII(vector<int>& nums) {
	int n = nums.size();
	int l = 0, h = n - 1;
	while (l < h) {
		int mid = l + (h - l) / 2;
		if (nums[mid] < nums[h])
			h = mid;
		else if (nums[mid] > nums[h])
			l = mid + 1;
		else h--;
	}
	return nums[l];
}


void solve_findMinII() {
	vector<int> nums = {2, 2, 2, 0, 1};
	cout << findMinII(nums);
}

/////////////////////////////////////////////////////////
// 33. Search in Rotated Sorted Array
int search(vector<int>& nums, int target) {
	int n = nums.size();
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (nums[mid] == target) return mid;

		// if the left part is sorted
		if (nums[mid] >= nums[lo]) {
			// either ele lies in the left part or not
			if (target >= nums[lo] && target <= nums[mid])
				hi = mid - 1;
			else
				lo = mid + 1;
		} else {
			// either ele lies in the right part or not
			if (target >= nums[mid] && target <= nums[hi])
				lo = mid + 1;
			else
				hi = mid - 1;
		}
	}
	return -1;
}

void solve_search() {
	vector<int> nums = {3, 3, 4, 7, 1, 1, 2, 2};
	int target = 3;
	cout << search(nums, target);
}

//////////////////////////////////////////////////////////////
// 162. Find Peak Element
int findPeakElement(vector<int>& nums) {
	int n = nums.size();
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (nums[mid] > nums[mid + 1])
			hi = mid;
		else lo = mid + 1;
	}
	return lo;
}
void solve_findPeakElement() {
	vector<int> nums = {1, 2, 3, 1};
	cout << findPeakElement(nums);
}

////////////////////////////////////////////////////////////////
// 209. Minimum Size Subarray Sum
// find the length of subarray such that sum >= target
int minSubArrayLen(int target, vector<int>& nums) {
	int i = 0, j = 0;
	int sum = 0;
	int mn = INT_MAX;
	while (j < nums.size()) {
		sum += nums[j];
		while (sum >= target) {
			mn = min(mn, j - i + 1 );
			sum -= nums[i];
			i++;
		}
		j++;
	}
	return mn == INT_MAX ? 0 : mn;
}

bool blackBox(vector<int> & nums, int target, int mid) {
	int sum = 0;
	for (int i = 0; i < mid ; i++) sum += nums[i];
	int maxi = sum;
	int l = 0, r = mid;
	while (r < nums.size()) {
		sum -= nums[l];
		l++;

		sum += nums[r];
		r++;


		maxi = max(maxi, sum);
	}
	return maxi >= target;
}
int minSubArrayLen1(int target, vector<int>& nums) {
// 2 3 1 2 4 3 => target = 7
// 1 2 3 4 5 6  => ans is between 1 to 7 // length
// minLength = 1, maxLength = 6
// lo = 1, hi = 6

// maximum subarray sum of k
// 2 3 1 2 4 3   // k = 4
// 2 + 3 + 1 + 2 = 8
// 8 + 4 - 2 = 10
// 10 + 3 - 3 = 10
// max sum = 10
//  if k is length for than ans is greater than 7 then we can also find ans in the 5 and 6 length  also
// so we have to decrease length so we can find optimal ans

// TC (n * logn) // logn for binary search and n for blackBox
	int lo = 1, hi = nums.size() ;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (blackBox(nums, target, mid) == true) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	if (blackBox(nums, target, lo)) return lo;
	else return 0;

}

void solve_minSubArrayLen() {
	// vector<int> nums = {1, 2, 3, 4, 5};
	vector<int> nums = {2, 3, 1, 2, 4, 3};
	int target = 7;
	// cout << minSubArrayLen(target, nums);
	cout << minSubArrayLen1(target, nums) << endl;
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///////////////////////////////////////////////////////////////////////////////////
// hard problems on binary search
// 1283. Find the Smallest Divisor Given a Threshold
int findSumAfterDiv(vector<int> &nums, int mid) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += (nums[i] / mid);
		// for celing add 1
		// 5/ 2, we will add 2 on the line 419, but we need to add 3 , hence add 1 more
		if (nums[i] % mid != 0) sum += 1;
	}
	return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
	// TC => O(n * log(max(n)))
	// looking to find divisor so, sum <= threshold
	int lo = 1, hi = *max_element(nums.begin(), nums.end());
	int ans = hi; // because we find always ans, so if we not find any than high is always ans
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (findSumAfterDiv(nums, mid) <= threshold) {
			ans = mid;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	return ans;

}

int smallestDivisor1(vector<int>& nums, int threshold) {
	// looking to find divisor so, sum <= threshold
	int lo = 1, hi = *max_element(nums.begin(), nums.end());
	// int ans = hi; // because we find always ans, so if we not find any than high is always ans
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (findSumAfterDiv(nums, mid) <= threshold) {
			hi = mid;
		} else lo = mid + 1;
	}
	return lo;

}

void solve_smallestDivisor() {
	vector<int> nums = {1, 2, 5, 9};
	int threshold = 6;
	// cout << smallestDivisor(nums, threshold);
	cout << smallestDivisor1(nums, threshold);
}

/////////////////////////////////////////////////////////////////////////////
// 410. Split Array Largest Sum
int numberOfSubArrayByKeepingLimit(vector<int> &nums, int mid, int m) {
	int cnt = 1, sum = 0;
	int limit = mid;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > limit) return false; // if ele is greater than limit than we can not split
		if (sum + nums[i] > limit) {
			cnt++;
			sum = nums[i];
		} else sum += nums[i];
	}
	return cnt <= m;
}
// TC O(n * log(sum - mx + 1))
int splitArray(vector<int>& nums, int m) {
	// [7]      	[2 5 10 8] => 7 and 25  => max = 26
	// [7 2]    	[5 10 8]   => 9 and 23 => max = 23
	// [7 2 5]  	[10 8]   => 14 and 18 =>   max = 18
	// [7 2 5 10]   [ 8]   => 24 and 8 =>      max = 25
// -----------------------------------------------------------------
	// min = 18
	int lo = *max_element(nums.begin(), nums.end()); // when m value is n then then max element become minimum sum
	int hi = 0;
	for (int i = 0; i < nums.size(); i++) hi += nums[i]; // when m = 1 then sum of all element become the minimum sum
	int ans = hi; // when we not find ans then ans is alway hi
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (numberOfSubArrayByKeepingLimit(nums, mid, m) == true) {
			ans = mid;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	return ans;
}

void solve_splitArray() {
	vector<int> nums = {7, 2, 5, 10, 8};
	int m = 2;
	cout << splitArray(nums, m);
}

///////////////////////////////////////////////////////////////////////
// 1231. Divide Chocolate
int canGetMoreThanmSubarray(vector<int> &nums, int mid, int m) {
	m = m + 1;
	int limit = mid;
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum >= limit) {
			cnt++;
			sum = 0;
		}
	}
	return cnt >= m ;
}
int findMaxChocolate(vector<int> &nums, int m) {
	int lo = 1;
	int hi = 0;
	for (int i = 0; i < nums.size(); i++) hi += nums[i];
	int ans = 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (canGetMoreThanmSubarray(nums, mid, m) == true) {
			ans = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	return ans;
}

void solve_findMaxChocolate() {
	// vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> nums = {5, 6, 7, 8, 9, 1, 2, 3, 4};
	int m = 8;
	cout << findMaxChocolate(nums, m);
}

//////////////////////////////////////////////////////////////////////
// 34. Find First and Last Position of Element in Sorted Array
vector<int> searchRange(int arr[], int n , int target) {
	int first = firstOccurence(arr, n  , target);
	int last = lastOccurence(arr , n, target);
	return {first, last};
}

void solve_searchRange() {
	int arr[] = {5, 7, 7, 8, 8, 9};
	int target = 8;
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> ans =  searchRange(arr, n, target);
	for (int x : ans) cout << x << " ";
}

/////////////////////////////////////////////////////////////////
// 540. Single Element in a Sorted Array
// xor technique, linear seach techin but this will required O(n) Time complexity
// TC O(logn)
int singleNonDuplicate(vector<int> &nums) {
	int lo = 0, hi = nums.size() - 1;
	while (lo < hi) {
		// cout << " lo " << lo << " hi " << hi << endl;
		int mid = lo + (hi - lo) / 2;
		// cout << " mid " << mid << endl;
		int delta = mid % 2 == 0 ? 1 : - 1;
		// cout << " ans " << nums[mid + delta] << " " << mid + delta  << endl << endl;
		if (nums[mid] == nums[mid + delta]) lo = mid + 1;
		else hi = mid - 1;
	}
	return nums[lo] == nums[lo - 1] ? nums[lo + 1] : nums[lo];
}

// ref => https://www.youtube.com/watch?v=nMGL2vlyJk0
int singleNonDuplicate1(vector<int> &nums) {
	int l = 0, r = nums.size() - 1;
	if (r == 0) return nums[0];
	else if (nums[0] != nums[1]) return nums[0];
	else if (nums[r] != nums[r - 1]) return nums[r];

	while (l < r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];

		if (
		    (mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
		    (mid % 2 == 0 && nums[mid] == nums[mid + 1])
		) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return -1;
}
void solve_singleNonDuplicate() {
	vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
	// cout << singleNonDuplicate(nums) << endl;
	cout << singleNonDuplicate1(nums) << endl;
}

////////////////////////////////////////////////////////////////
// 29. Divide Two Integers
// ref => https://www.youtube.com/watch?v=yYgNyxMBrak
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
int divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) return INT_MAX;
	if (dividend == INT_MIN && divisor == 1) return INT_MIN;

	long int dd = abs(dividend) , dv = abs(divisor);

	int res = 0;
	while (dv <= dd) {
		long int sum = dv, cnt = 1;
		while (sum <= dd - sum) {
			sum += sum;
			cnt += cnt;
		}
		res += cnt;
		dd -= sum;
	}
	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ) return -res;
	return res;
}

void solve_divide() {
	int dividend = 120;
	int divisor = 3;
	cout << divide(dividend, divisor);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
// 793. Preimage Size of Factorial Zeroes Function
long long checkZeros(long long n) {
	long long ans = 0;
	long long x = 5;
	while (x <= n) {
		ans += n / x;
		x *= 5;
	}
	return ans;
}

int preimageSizeFZF(int k) {
	long long lo = 0;
	long long hi = LLONG_MAX;

	while (lo <= hi) {
		long long mid = lo + (hi - lo) / 2;
		long long x = checkZeros(mid);
		if (x == k) return 5;
		else if (x > k) hi = mid - 1;
		else if (x < k) lo = mid + 1;
	}
	return 0;
}

void solve_preimageSizeFZF() {
	int k = 0;
	cout << preimageSizeFZF(k);
}

int main() {
	// solve_findEle();
	// solve_DuplicateFirstFindEle();
	// solve_DuplicateLastFindEle();
	// solve_lowerBound() ;
	// solve_upperBound();
	// solve_freqOfEle();
	// solve_sqroot();

	// medium leetcode questions
	// solve_findMin() ;
	// solve_findMinII(); // hard
	// solve_search();
	// solve_findPeakElement();
	// solve_minSubArrayLen();
	// solve_smallestDivisor();
	// solve_splitArray();
	// solve_findMaxChocolate();
	// solve_searchRange();
	// solve_singleNonDuplicate();
	// solve_divide();
	solve_preimageSizeFZF();
}
