#include <bits/stdc++.h>
using namespace std;

void solve_shift(int A[], int I, int N, int E)
{
	// for(int i = N - 1 ; i>=0; i--) {
	// 	if(i == I) {
	// 		A[i] = E;
	// 		break;
	// 	} else {
	// 		A[i] = A[i - 1];
	// 	}
	// }

	for (int i = N - 1; i > I; i--)
		A[i] = A[i - 1];
	A[I] = E;
}

void solve_mean_median()
{
	int N = 4;
	int A[] = {2, 8, 3, 4};
	int S = 0;
	for (int x : A)
		S += x;
	cout << " mean " << (S / N) << endl;

	sort(A, A + N);
	if (N & 1)
		cout << " median " << A[N / 2] << endl;
	else
	{
		int n = N / 2;
		cout << " median " << floor((A[n - 1] + A[n]) / 2) << endl;
	}
}

// max and second max
vector<int> largestAndSecondLargest(int n, int arr[])
{
	int max = INT_MIN, max2 = INT_MIN;

	vector<int> V;

	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	V.push_back(max);
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (max2 < arr[i] && arr[i] != max)
		{
			flag = 1;
			max2 = arr[i];
		}
	}
	if (flag == 0)
		max2 = -1;
	V.push_back(max2);
	return V;
}

// maximum for every adjucent pair in the array
void maximumAdjacent(int N, int arr[])
{
	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			cout << arr[i] << " ";
		else
		{
			cout << arr[i + 1] << " ";
		}
	}
}

void reverseInGroups(vector<long long> &arr, int n, int k)
{
	for (int i = 0; i < n; i += k)
	{
		int l = i;
		int h = min(i + k - 1, n - 1);
		while (l < h)
		{
			swap(arr[l++], arr[h--]);
		}
	}
}

// rotate array
void rotateArr(int arr[], int d, int n)
{
	int M = d % n;
	for (int i = 1; i <= M; i++)
	{
		int temp = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = temp;
	}
}

// second method roatate array
// auxilary space we are use is O(d);
void rotateArr1(int arr[], int d, int n)
{
	vector<int> V;
	int M = d % n;
	// 1 2 3 4 5
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < M)
			V.push_back(arr[i]);
		else
		{
			arr[j] = arr[i];
			j++;
		}
	}

	for (int i = 0; i < j; i++)
	{
		arr[j + i] = V[i];
	}
}

// auxilary space O(1) and TC O(n);
void reverse_func(int arr[], int l, int h)
{
	while (l <= h)
		swap(arr[l++], arr[h--]);
}
void rotateArr2(int arr[], int d, int n)
{
	d = d % n;
	reverse_func(arr, 0, d - 1);
	reverse_func(arr, d, n - 1);
	reverse_func(arr, 0, n - 1);
}

/////////////////////////////////////////////////
// minimum adjucent diffrence in the circular array
int minAdjDiff(int arr[], int n)
{
	int mn = INT_MAX;
	for (int i = 1; i < n; i++)
	{
		int x = abs(arr[i] - arr[i - 1]);
		mn = min(mn, x);
	}

	mn = min(mn, abs(arr[0] - arr[n - 1]));
	return mn;
}

///////////////////////////////////////
// maximum occuring in the range
// 2, 1, 2
// 5, 2, 9
// taking most time this not optimal solution
int maxOccured(int L[], int R[], int n)
{
	int RMX = INT_MIN;

	for (int i = 0; i < n; i++)
		RMX = max(RMX, R[i]);
	int A[RMX + 1] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = L[i]; j <= R[i]; j++)
		{
			A[j]++;
		}
	}

	int val = -1;
	int mx = INT_MIN;
	for (int i = 0; i < RMX + 1; i++)
	{
		if (mx < A[i])
		{
			mx = A[i];
			val = i;
		}
	}
	return val;
}

// another solution for same problem
// using prifix sum
int maxOccured1(int L[], int R[], int n, int maxx)
{
	// Your code here
	vector<int> ocrr(maxx + 2, 0);
	for (int i = 0; i < n; i++)
	{
		ocrr[L[i]]++;
		ocrr[R[i] + 1]--;
	}

	int mxm = ocrr[0];
	int ans = 0;
	for (int i = 1; i < maxx + 2; i++)
	{
		ocrr[i] += ocrr[i - 1];

		if (mxm < ocrr[i])
		{
			mxm = ocrr[i];
			ans = i;
		}
	}
	return ans;
}

/////////////////////////////////////
// 11. Wave Array
void convertToWave(int n, vector<int> &arr)
{
	for (int i = 0; i < n - 1; i += 2)
		swap(arr[i], arr[i + 1]);
}

// ///////////////////////////////////////////
// 12. Frequencies of Limited Range Array
void frequencyCount1(vector<int> &arr, int N, int P)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < N; i++)
	{
		mp[arr[i]]++;
	}

	for (int i = 1; i <= N; i++)
	{
		arr[i - 1] = mp[i];
	}
}

void frequencyCount(vector<int> &arr, int N, int P)
{
	int mx = max(P, N);
	int freq[mx + 1] = {0};
	for (int i = 0; i < N; i++)
	{
		freq[arr[i]]++;
	}

	for (int i = 0; i < mx; i++)
	{
		arr[i] = freq[i + 1];
	}
}
////////////////////////////////////////////
// 13. Equilibrium Point
int equilibriumPoint1(long long A[], int N)
{
	int i = 0, j = N - 1;
	long leftSum = A[0];
	long rightSum = A[N - 1];

	if (i == j)
		return 1;

	while (i < j)
	{
		if (leftSum < rightSum)
		{
			i++;
			leftSum += A[i];
		}
		else if (rightSum < leftSum)
		{
			j--;
			rightSum += A[j];
		}

		if (leftSum == rightSum)
		{
			if (i + 1 == j - 1)
				return i + 2; // in the context of index start from 1
			else
			{
				i++;
				leftSum += A[i];
				j--;
				rightSum += A[j];
			}
		}
	}

	return -1;
}

// 2nd approach
int equilibriumPoint2(long long A[], int N)
{
	int AR[N] = {0};
	AR[-1] = 0;

	for (int i = 0; i < N; i++)
		AR[i] = AR[i - 1] + A[i];

	for (int i = 0; i < N; i++)
	{
		if (AR[i - 1] == AR[N - 1] - AR[i])
			return i + 1;
	}

	return -1;
}

// 3rd approach
int equilibriumPoint(long long A[], int N)
{
	if (N == 1)
		return 1;
	if (N == 2)
		return -1;

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i++)
		sum1 += A[i];

	for (int i = 0; i < N; i++)
	{
		sum2 += A[i];
		if (sum1 == sum2)
			return i + 1;
		sum1 -= A[i];
	}
	return -1;
}

///////////////////////////////////////////////
// 14. Leaders in an array
vector<int> leaders(int a[], int n)
{
	int mx = a[n - 1];
	vector<int> V;
	V.push_back(a[n - 1]);
	if (n == 1 || n == 2)
		return V;
	for (int i = n - 2; i >= 0; i--)
	{
		if (mx <= a[i])
		{
			mx = a[i];
			V.push_back(mx);
		}
	}
	int l = 0;
	int h = V.size() - 1;
	while (l <= h)
		swap(V[l++], V[h--]);
	return V;
}

/////////////////////////////////////////////////////
// 15. Smallest Positive missing number
int missingNumber1(int arr[], int n)
{
	int mx = INT_MIN;
	for (int i = 0; i < n; i++)
		mx = max(mx, arr[i]);

	int flag = 0;
	int number = -1;
	for (int i = mx - 1; i >= 1; i--)
	{
		flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == arr[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			number = i;
		}
	}

	if (number == -1)
	{
		number = mx + 1;
	}

	return number;
}

// 2nd approach
int missingNumber2(int arr[], int n)
{
	sort(arr, arr + n);
	int mx = arr[n - 1];

	int flag = 0;
	int number = -1;

	for (int i = mx - 1; i >= 1; i--)
	{
		flag = 0;
		int l = 0, h = n - 1;
		while (l <= h)
		{
			int m = l + (h - l) / 2;
			if (arr[m] == i)
			{
				flag = 1;
				break;
			}
			if (arr[m] < i)
				l = m + 1;
			else
				h = m - 1;
		}
		if (flag == 0)
		{
			number = i;
		}
	}

	if (number == -1)
	{
		number = mx + 1;
	}

	return number;
}

// 3rd approach
int missingNumber3(int arr[], int n)
{
	map<int, bool> mp;

	for (int i = 0; i <= n + 1; i++)
	{
		mp[i] = false;
	}
	// for(auto x : mp) cout << x.first << " => " << x.second << endl;
	for (int i = 0; i < n; i++)
	{
		mp[arr[i]] = true;
	}
	// for(auto x : mp) cout << x.first << " => " << x.second << endl;

	for (int i = 1; i <= n + 1; i++)
	{
		if (mp[i] == false)
		{
			return i;
		}
	}
}

// 4rd approach
int missingNumber4(int arr[], int n)
{
	sort(arr, arr + n);
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == cnt)
			cnt++;
	}
	return cnt;
}

////////////////////////////////////////////////////////////
// 16. Rearrange Array Alternately
// TC => O(N) SC => O(N)
void rearrange(long long int *arr, int n)
{
	int l = 0;
	int h = n - 1;
	vector<int> vec;

	while (l < h)
	{
		vec.push_back(arr[h]);
		vec.push_back(arr[l]);
		h--;
		l++;
	}

	for (int i = 0; i < n; i++)
		arr[i] = vec[i];
}

// TC => O(N) SC => O(1)
void rearrange1(long long int *arr, int n)
{
	int h = n - 1;
	int l = 0;
	int max = (int)arr[n - 1] + 1;
	// if take module of smaller number with big number than it
	// give value it self
	// eg : 4 % 5 = 4

	// divident = Quotient * divisor + reminder
	for (int i = 0; i < n; i++)
	{
		// Max element is at even position
		if (i % 2 == 0)
		{
			arr[i] = arr[i] + (arr[h] % max) * max;
			h--;
		}
		// Min element is at odd position
		else
		{
			arr[i] = arr[i] + (arr[l] % max) * max;
			l++;
		}
	}
	// Here we are diving the whole array to get right output
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i] / max; // give rearrange number
		// arr[i] = arr[i] % max // give orignal number
	}
}
// ///////////////////////////////////////
// 17. Rearrange an array with O(1) extra space
void arrange(long long *arr, int n)
{
	// TC => O(N) SC => O(N)
	long long vec[n];
	for (int i = 0; i < n; i++)
	{
		int temp = arr[arr[i]];
		vec[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = vec[i];
	}
}
void arrange1(long long arr[], int n)
{
	// TC => O(N) SC => O(1)
	int mx = *max_element(arr, arr + n) + 1;
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i] + (arr[arr[i]] % mx) * mx;
		// devident = reminder+ Quotient * divisor
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] /= mx;
	}
}
///////////////////////////////////////////
// 18. Maximum Index
//  1st approach
int maxIndexDiff1(int A[], int N)
{
	// TC => O(N) SC => O(N)
	vector<int> V;
	int l = 0;
	int h = N - 1;
	while (l <= h)
	{
		if (A[l] <= A[h])
		{
			V.push_back(h - l);
			l = 0;
			h--;
		}
		else
		{
			l++;
		}
	}
	return *max_element(V.begin(), V.end());
}

// 2nd approach this is more optimal approach in the space complexity wise
int maxIndexDiff(int A[], int N)
{
	// TC => O(N) SC => O(1)
	// vector<int> V;
	int mx = INT_MIN;
	int l = 0;
	int h = N - 1;
	int cnt = 0;
	while (l <= h)
	{
		cnt++;
		if (A[l] <= A[h])
		{
			mx = max(mx, h - l);
			l = 0;
			h--;
		}
		else
		{
			l++;
		}
	}
	return mx;
}

/////////////////////////////////////////////
// 19. Trapping Rain Water
long long trappingWater(int arr[], int n)
{
	int l[n];		   // left
	int r[n];		   // right
	long long res = 0; // water store in unit

	l[0] = arr[0];
	for (int i = 1; i < n; i++)
		l[i] = max(l[i - 1], arr[i]);

	r[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		r[i] = max(r[i + 1], arr[i]);

	for (int i = 1; i < n; i++)
		res = res + min(l[i], r[i]) - arr[i];
	return res;
}

////////////////////////////////////////////
// // 20. Stock buy and sell
vector<vector<int>> stockBuySell(vector<int> A, int n)
{
	vector<vector<int>> days;
	int buyDay = 0, sellDay = -1;
	for (int i = 1; i < n; i++)
	{
		// 4 2 2 2 4
		// 100, 180, 260, 310, 40, 535, 695
		if (A[i] > A[i - 1])
		{
			sellDay = i;
			if (i == n - 1 && sellDay > buyDay)
			{
				vector<int> d;
				d.push_back(buyDay);
				d.push_back(sellDay);
				days.push_back(d);
			}
		}
		else
		{
			if (sellDay > buyDay)
			{
				vector<int> d;
				d.push_back(buyDay);
				d.push_back(sellDay);
				days.push_back(d);
			}
			buyDay = i;
		}
	}
	return days;
}

//////////////////////////////////////////////
// 21. Check if array is sorted and rotated
bool checkRotatedAndSorted(int arr[], int num)
{
	if (num == 1)
		return false;

	int cnt = 0;
	//  3 4 1 2
	for (int i = 1; i < num; i++)
	{
		if (arr[0] < arr[num - 1])
		{
			if (arr[i] > arr[i - 1])
				cnt++;
		}
		else if (arr[0] > arr[num - 1])
		{
			if (arr[i] < arr[i - 1])
				cnt++;
		}
	}
	return cnt == 1;
	// Your code here
	// int count = 0;
	// for (int i = 0; i < num - 1; i++) {
	// 	if (arr[0] < arr[num - 1]) {
	// 		if (arr[i] < arr[i + 1]) count++;
	// 	}
	// 	else if (arr[0] > arr[num - 1]) {
	// 		if (arr[i] > arr[i + 1]) count++;
	// 	}
	// }
	// return count == 1;
}

// 22. Kadane's Algorithm
long long maxSubarraySum(int arr[], int n)
{
	long long sum = 0;
	long long mx = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		mx = max(mx, sum);
		if (sum < 0)
			sum = 0;
	}

	return mx;
}

////////////////////////////////////////////
// 23. Longest Subarray Of Evens And Odds
int maxEvenOdd(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			arr[i] = 0;
		}
		else
			arr[i] = 1;
	}

	// 74 80 8 13 37 49 20 6
	// 0 0  0 1 1 1 0 0
	int cnt = 1; // 0 0 0 1 0 0
	int mx = INT_MIN;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] != arr[i + 1])
		{
			cnt++;
			mx = max(mx, cnt);
		}
		else
		{
			mx = max(mx, cnt);
			cnt = 1;
		}
	}
	return mx;
}

//////////////////////////////////////
// 24. Max Circular Subarray Sum
int circularSubarraySum(int arr[], int n)
{
	//  check if all the values are -ve than return max value form this
	int mx = *max_element(arr, arr + n);
	if (mx < 0)
		return mx;
	/////////////////////////////////////////////////

	int arr_sum = 0;
	int kd_sum = 0;
	int kd_mx = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		arr_sum += arr[i];
		kd_sum += arr[i];
		kd_mx = max(kd_mx, kd_sum);
		if (kd_sum < 0)
			kd_sum = 0;
	}

	int cir_sum = 0;
	int cir_mx = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		cir_sum += (-1 * arr[i]);
		cir_mx = max(cir_mx, cir_sum);
		if (cir_sum < 0)
			cir_sum = 0;
	}

	int circular_sum = arr_sum - (-1 * cir_mx); // we are multipy cir_mx with -1 because we have inverted array
	return max(circular_sum, kd_mx);
}

// ////////////////////////////////////////////////////
// Game of Chocolates

bool game(int a, int b) {
	// Code Here
	if (a > b) {
		swap(a, b);
	}
	int k = b - a;
	long double d = 1 + sqrt(5);
	d /= 2;
	d *= k;
	int temp = (int)d;
	if (temp == a) {
		return 0;
	}
	return 1;
}
/////////////////////////////////////////////////
// Divide and Subtract Game
string divAndSub(int N) {
	if (N == 1 ) return "Arya";
	if (N < 5) return "Jon";

	int a[N + 1] = {0};

	for (int i = 6; i <= N; i++) {
		if (a[i / 2] == 0) a[i] = 1;
		else if (a[i - 2] == 0) a[i] = 1;

		if (a[i / 3] == 0) a[i] = 1;
		else if (a[i - 3] == 0) a[i] = 1;

		if (a[i / 4] == 0) a[i] = 1;
		else if (a[i - 4] == 0) a[i] = 1;

		if (a[i / 5] == 0) a[i] = 1;
		else if (a[i - 5] == 0) a[i] = 1;

	}

	if (a[N] == 1) return "Jon";
	else return "Arya";
}

///////////////////////////////////////////////
// Fraction Trouble
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
vector<int> LargestFraction(int n, int d) {
	int num = 0, deno = 1;
	for (int q = 10000; q >= 2; q--) {
		int p = (n * q - 1) / d;
		if (p * deno >= q * num) {
			deno = q;
			num = p;
		}
	}

	int g = gcd(num, deno);
	vector<int> ans;
	ans.push_back(num);
	ans.push_back(deno);
	return ans;
}
//////////////////////////////////////////
// joseph problem
// Find the Safe Position
int safePos2(int n, int k) {
	if (n == 1) return 1;
	int x = safePos2(n - 1, k);
	int y = ((x + k - 1 ) % n) + 1  ;
	return y;
}

// second way
void safePos1(vector<int> &vec, int index, int & ans , int k) {
	if (vec.size() == 1) {
		ans = vec[0];
		return;
	}

	index = (index + k) % vec.size();
	vec.erase(vec.begin() + index);
	safePos1(vec, index, ans, k);
}

// third approach using while loop
int safePos(int n , int k) {
	int ans = -1;
	int index = 0;
	vector<int> vec ;
	for (int i = 1; i <= n; i++) vec.push_back(i);
	k -= 1;

	while (true) {
		if (vec.size() == 1) {
			ans = vec[0];
			return ans;
		}

		index = (index + k) % vec.size();
		vec.erase(vec.begin() + index);
	}
}


// patteren seraching
bool searchPattern(string str, string pat)
{
	if (str.find(pat) != string::npos) return true;
	else return false;
}


// print patteren
void solve(int n , vector<int> &ans, bool isRepeated) {
	if (ans[ans.size() - 1] == n && ans.size() != 1) return;

	int num = ans[ans.size() - 1] ;
	if (num > 0 && !isRepeated) ans.push_back(num - 5);
	else {
		isRepeated = true;
		ans.push_back(num + 5);
	}

	solve(n , ans, isRepeated);
}
vector<int> pattern(int N) {
	vector<int> ans;
	ans.push_back(N);
	solve(N, ans, false);
	return ans;

}


//////////////////
// batting game
// WLWLLWLLWWLWWW
int betBalance(string result)
{
	// code here
	int n = result.length();
	int i = 0;
	int sum = 4;
	int bet = 1;
	while (i < n) {
		if(result[i] == 'W' && sum >= bet){
			sum += bet;
			bet = 1;
		}else if(result[i] == 'L' && sum >= bet) {
			sum -= bet;
			bet = 2 * bet;
		} else return -1;
		i++;
	}
	return sum;
}

int main()
{
	// int N = 6;
	// int A[N] = {1, 2, 3, 4, 5};
	// int I = 2;
	// int E = 90;

	// // solve(A, I, N, E);
	// // for (int x : A) cout << x << " ";

	// // mean median
	// solve_mean_median();

	// print first max and second max
	// int arr[] = {2,1,2};
	// int arr[] = {1,2,3,4,5};
	// int arr[] = {10, 10, 10};
	// int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
	// vector<int> V = largestAndSecondLargest(sizeOfArray, arr);
	// for(int x : V) cout << x << " ";

	//////////////////////////////////////////////////////
	// maximumAdjacent pair in the array
	// int arr[] = {1, 2, 2, 3, 4, 5};
	// // int arr[] = {5,5};
	// int N = sizeof(arr) / sizeof(arr[0]);
	// maximumAdjacent(N, arr);

	///////////////////////////////////////////////////////
	// reverse array in the group
	// vector<long long> arr{1, 2, 3, 4, 5, 6, 7, 8};
	// // vector<long long> arr{5, 6, 8, 9};
	// int N = arr.size(),  K = 3;
	// reverseInGroups(arr, N, K);
	// for (int x : arr) cout << x << " ";

	////////////////////////////////////////////////
	// rotate array
	// int arr[] = {1, 2, 3, 4, 5};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// // rotateArr(arr,  12, n);
	// // rotateArr1(arr, 12, n); // doing using optimal way

	// // mos optimal 0(n) TC , O(1) SC
	// rotateArr2(arr, 12, n);
	// for (int x : arr) cout << x << " ";

	//////////////////////////////////////////////////
	// minimum diffrence between circular array
	// 	int arr[] = {8,-8,9,-9,10,-11,12};
	// 	int n = sizeof(arr) / sizeof(arr[0]);
	// 	cout << minAdjDiff(arr, n);

	//////////////////////////////////////////////////////////////////
	// return maximum occurence in the the both array
	// int L[] = {1, 4, 3, 1};
	// int R[] = {15, 8, 5, 4};
	// // int L[] = {1, 5, 9, 13, 21};
	// // int R[] = {15, 8, 12, 20, 30};
	// int n = sizeof(L) / sizeof(L[0]);
	// int maxx = INT_MIN;
	// for (int i = 0; i < n ; i++) {
	// 	maxx = max(maxx, R[i]);
	// }
	// cout << maxOccured1(L, R, n, maxx);

	////////////////////////////////////////////////////
	// 11. Wave Array
	// vector<int>  arr{1, 2, 3, 4, 5, 6};
	// int n = arr.size();
	// convertToWave(n , arr);
	// for (int x : arr) cout << x << " ";

	//////////////////////////////
	// 12. Frequencies of Limited Range Array
	// vector<int> arr{2, 3, 2, 3, 5};
	// // vector<int> arr{1, 1, 1, 1, 1};

	// int P = 5;
	// int N = arr.size();
	// frequencyCount(arr, N, P);
	// for (auto x : arr) cout << x << " ";

	/////////////////////////////
	// long long A[] = {1, 3, 5, 2, 2} ;
	// int N = sizeof(A) / sizeof(A[0]);
	// cout << equilibriumPoint(A, N);

	//////////////////////////////////
	// 14. Leaders in an array
	// int A[] = {16, 17, 4, 3, 5, 2};
	// int A[] = {1, 2, 3, 4, 0};
	// int A[] = {32763 , 32734 , 32722 , 32719 , 32329 , 32305 , 30705 , 29265};
	// int n = sizeof(A) / sizeof(A[0]);
	// vector<int> V = leaders(A, n);
	// for (int x : V) cout << x << " ";

	//////////////////////////////////////////////////
	// 15. Smallest Positive missing number
	// int arr[] = {1,2,3,4,5};
	// int arr[] = {37, 6, -7, 41, -23, 15, 9, -14, -18, 1, -13, -22, 25, -43, 24};
	// // int arr[] = {0,-10,1,3,-20};
	// int n = sizeof(arr) / sizeof (arr[0]);
	// cout << missingNumber(arr, n);

	//////////////////////////////////////////////////////
	// 16. Rearrange Array Alternately
	// long long arr[] = {1, 2, 3, 4, 5, 6};
	// // long long arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// rearrange(arr, n);
	// for (int x : arr) cout << x << " ";

	/////////////////////////////////////////////////
	// 17. Rearrange an array with O(1) extra space
	// long long arr[] = {4, 0, 2, 1, 3};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// arrange(arr, n);
	// for (int x : arr) cout << x << " ";

	// maxIndexDiff
	// int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
	// int arr[] = {65, 6, 74, 94, 56, 89, 9, 63, 75, 25, 34, 68, 93, 48, 16};
	// int arr[] = {97, 65, 24, 84, 10, 82, 2, 51, 1, 91, 62, 59, 80, 76, 26, 66, 11};
	// // int arr[] = {15, 86, 78, 93, 100, 6};
	// // int arr[] = {82, 63, 44, 74, 82, 99, 82};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << maxIndexDiff(arr, n);

	/////////////////////////////////////
	// 19. Trapping Rain Water
	// int arr[] = {3, 0, 0, 2, 0, 4};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << trappingWater(arr, n);

	/////////////////////////////////
	// vector<int> A = {100, 180, 260, 310, 40, 535, 695};
	// vector<int> A = {4, 2, 2, 2, 4};
	// vector<int> A = {87, 63, 92, 97, 82, 25};
	// int n = A.size();
	// vector<vector<int>> vec = stockBuySell(A, n);
	// // int row = vec.size();
	// int col = vec[0].size();
	// // for (int i = 0; i < row ; i++) {
	// // 	for (int j = 0 ; j < col; j++ ) {
	// // 		cout << vec[i][j] << " ";
	// // 	}
	// // 	cout << endl;
	// // }
	// for (vector<int> x : vec)
	// {
	// 	for (int y : x)
	// 		cout << y << " ";
	// 	cout << endl;
	// }

	//////////////////////////////////////////////
	// int arr[] = {3, 4, 1, 2};
	// // int arr[] = { 1, 2, 3};
	// // int arr[] = {3, 4, 5};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// if (checkRotatedAndSorted(arr, n))
	// 	cout << " true " << endl ;
	// else cout << " false " << endl ;

	// ///////////////////////////////
	// 22. Kadane's Algorithm

	// int arr[] = {1, 2, 3, -2, 5};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << maxSubarraySum(arr , n);
	//////////////////////////////////
	// 23. Longest Subarray Of Evens And Odds
	// int a[] = {10,12,14,7,8};
	// int a[] = {74, 80, 8, 13, 37, 49, 20, 6};
	// // int a[] = {4,6};
	// int n = sizeof(a) / sizeof(a[0]);
	// cout << maxEvenOdd(a, n);

	////////////////////////////////////
	// 24. Max Circular Subarray Sum
	// int arr[] = {8, -8, 9, -9, 10, -11, 12};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << circularSubarraySum(arr, n);

	// ////////////////////////////////////////
	// Divide and Subtract Game
	// int N = 3;
	// cout << divAndSub(N);

/////////////////////////////////////////
	// Fraction truble
	// int  n = 1, d = 8;
	// vector<int> vec = LargestFraction(n , d);
	// cout << vec[0] << " / " << vec[1] << endl;

////////////////////////////////////////
	// 1st approach
	// joseph problem
	// int n = 4, k = 2;
	// cout << safePos(n , k);

	// 2nd approach
	// int n = 4 , k = 2;
	// int ans  = -1;
	// vector<int> vec;
	// for (int i = 1; i <= n ; i++) vec.push_back(i);
	// k -= 1;
	// safePos1(vec, 0, ans, k);
	// cout << ans;


	// //////////////////////////////////////////
	// string str = "geeksforgeeks";
	// string ptn = "hii";
	// bool check = searchPattern(str, ptn);
	// if (check) cout << " present " << endl;
	// else cout << " not present " << endl;


//////////////////////////////////////////
	// pattern
	// int N = 16;
	// vector<int> vec = pattern(N);
	// for (auto x : vec) cout << x << " ";


// bate blance amount
	// string result = "WLWLLWLLWWLWWW";
	// string result = "WL";
	string result = "WLWLLWLLWWLWWW";
	// string result = "WWLWLLL";
	// string result = "WLWLLWW";
	cout << betBalance(result);
}
