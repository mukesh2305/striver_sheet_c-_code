#include <bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


#define fastio()         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD              1000000007
#define MOD1             998244353
#define INF              1e18
#define nl               "\n"
#define pb               push_back
#define ppb              pop_back
#define setbits(x)       __builtin_popcountll(x);
#define zerobits(x)      __builtin_ctzll(x);
#define ps(x, y)         fixed<<setprecision(y)<<x
#define mp 				 make_pair
#define ff 				 first
#define ss               second
#define PI               3.141592653589793238462
#define sz(x)           ((int)(x).size())
#define all(x)          (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " ; _print(x); cerr << "\n";
#else
#define debug(x)
#endif


#ifndef ONLINE_JUDGE
#define LA(x, n) cerr << #x << " ";_print(x, n);     cerr << "\n";
#endif

void debug_code() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
}

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(int a, int b) {
	ll a0 = a;
	ll b0 = b;
	return a0 * b0 / __gcd(a0, b0);
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
int searchInSorted(int arr[], int n, int x)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == x)
			return mid;
		else if (arr[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

// 1,1,1,1,1,0,0,0
// 0,0,0,1,1,1,1,1
// first index of 1
int countOnes(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != 1)
		{
			return i;
		}
	}

	return 0;
}

///////////////////////////////////////////////

// count sqrt of number
// 1 2 3 4 5
long long int floorSqrt(long long int x)
{
	int lo = 1;
	int hi = x;
	long long int ans = 1;

	while (lo <= hi)
	{
		long long mid = lo + (hi - lo) / 2;
		long long sq = mid * mid;

		if (sq <= x)
		{
			ans = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	return ans;
}

// brutforce approach
long long int floorSqrt1(long long int x)
{
	if (x == 1)
		return 1;
	int ans = 1;
	int i = 1;
	while (i * i <= x)
	{
		ans++;
		i++;
	}

	return ans;
}

///////////////////////////////////////////
// 3,1,3,3,2
int majorityElement1(int arr[], int n)
{
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		if (mx < arr[i])
			mx = arr[i];
	}

	int fq[mx + 1] = {0};
	for (int i = 0; i < n; i++)
	{
		fq[arr[i]]++;
	}
	for (int i = 0; i < mx + 1; i++)
	{
		if (fq[i] > n / 2)
		{
			return i;
		}
	}
	return -1;
}

//  first occurence
int first_occurence(int arr[], int n, int x) {
	int l = 0, h = n - 1;
	while (l <= h) {
		int m = l + (h - l ) / 2;
		if (arr[m] == x) {
			if (m == 0 || arr[m - 1] != x) return m;
			else h = m - 1;
		}
		else if (arr[m] < x) l = m + 1;
		else h = m - 1;
	}
	return -1;
}

////////////////////////////////////////
// peak element
// 1st approach
int peak_element(int arr[], int n) {
	int l = 0, h = n - 1;
	while (l <= h) {
		int m = l + (h - l) / 2;
		if ((m == 0 || arr[m - 1] <= arr[m]) && (m == n - 1 || arr[m + 1] <= arr[m]))
			return m;
		else if (m > 0 && arr[m - 1] >= arr[m]) h = m - 1;
		else l = m + 1;
	}
	return -1;
}

//2nd approach
int peak_element1(int arr[], int n) {
	int l = 0, h = n - 1;
	while (l < h ) {
		int m = l + (h - l) / 2;
		if (arr[m] > arr[m + 1]) h = m;
		else l = m + 1;
	}

	return l;
}


//  floor in a sorted array
int findFloor(long long int arr[], int N, long long int x) {
	int l = 0, h = N - 1;
	if (x >= arr[h]) return h;
	if (x == arr[l]) return l;
	if (x < arr[l]) return -1;
	while (l <= h) {
		int m = l + (h - l ) / 2;
		if (arr[m] > x) h = m - 1;
		else  l = m + 1;
	}
	if (l == x) return l;
	return l - 1;
}

int findFloor1(long long int arr[], int n, long long int x) {
	ll l = 0, h = n - 1;
	ll ans = -1;
	while (l <= h ) {
		int m = l + (h - l) / 2;
		if (arr[m] <= x) {
			ans = m;
			l = m + 1;
		} else h =  m - 1;
	}

	return ans;
}

// 9. Minimum Number in a sorted rotated
// 2,3,4,5,6,7,8,9,10,1
int minNumber(int arr[] , int n) {
	int l = 0, h = n - 1;
	while (l < h) {
		int m = l + (h - l ) / 2;
		cout << " m " << m << endl;
		if (arr[m] > arr[h]) {
			l = m + 1;
		} else {
			// 34 7 18 26
			h = m;
		}
	}

	return arr[h];
	// return arr[l];
}

/////////////////////////////////////////////////////////
// 10. Two Repeated Elements

int fact(int n)
{
	return (n == 0) ? 1 : n * fact(n - 1);
}
vector<int> printRepeating1(int arr[], int size)
{
	int S = 0; /* S is for sum of elements in arr[] */
	int P = 1; /* P is for product of elements in arr[] */
	int x, y; /* x and y are two repeating elements */
	int D; /* D is for difference of x and y, i.e., x-y*/
	int n = size - 2, i;

	/* Calculate Sum and Product of all elements in arr[] */
	for (i = 0; i < size; i++)
	{
		S = S + arr[i];
		P = P * arr[i];
	}

	S = S - n * (n + 1) / 2; /* S is x + y now */
	P = P / fact(n);   /* P is x*y now */

	D = sqrt(S * S - 4 * P); /* D is x - y now */

	x = (D + S) / 2;
	y = (S - D) / 2;

	vector<int> vec;
	vec.push_back(x);
	vec.push_back(y);
	return vec;
}


// 2nd approach
vector<int> printRepeating(int arr[], int n) {
	int repPos[n + 1] = {0};
	int j = 1;
	unordered_map<int, int> mp;
	for (int i = 0; i < n + 2; i++) {
		mp[arr[i]]++;
		if (repPos[arr[i]] == 0) {
			repPos[arr[i]] = j;
			j++;
		}
	}

	vector<int> vec;
	for (auto it : mp) {
		if (it.second > 1) vec.push_back(it.first);
	}
	int a = repPos[vec[0]], b = repPos[vec[1]];
	int n1 = vec[0], n2 = vec[1];
	if (a < b) { // 3 > 4
		vec[0] = n1;
		vec[1] = n2;
	} else {
		vec[0] = n2;
		vec[1] = n1;
	}
	return vec;


}

vector<int> printRepeating2(int arr[], int size)
{
	unordered_set<int>s;
	vector<int> vec;
	for (int i = 0; i < size; i++)
	{
		if (s.empty() == false && s.find(arr[i]) != s.end())
			vec.push_back(arr[i]);
		s.insert(arr[i]);
	}
	return vec;

}

////////////////////////////////////
// 11. Roof Top
int maxStep(int A[], int N)
{
	// A[] = {1,2,2,3,2}
	int cnt = 0;
	int mx = 0;
	for (int i = 1; i < N ; i++) {
		if (A[i] > A[i - 1]) {
			cnt++;
			mx = max(mx, cnt);
		} else {
			cnt = 0;
		}
	}
	return mx;
}

/////////////////////
//  12. Maximum Water Between Two Buildings
int maxWater(int arr[], int n) {
	int low = 0, high = n - 1;
	int gap , mx = 0, mn ;
	while (low < high) {
		//  {2,1,3,4,6,5}
		mn = min(arr[low], arr[high]);
		gap = mn * (high - low - 1);
		mx = max(mx, gap);

		if (arr[low] < arr[high]) low++;
		else high--;
	}
	return mx;
}

// ////////////////////////////
// {1,2,3,4,5}
// Output: 6
// 13. Smallest Positive missing number
int missingNumber(int arr[], int n)
{
	sort(arr, arr + n);
	int mx = arr[n - 1];

	int flag = 0;
	int ans = -1;
	for (int i = mx - 1; i >= 1; i--) {
		int low = 0, high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] ==  i) {
				flag = 1;
				break;
			}
			else if (arr[mid] < i) low = mid + 1;
			else high = mid - 1;
		}
		if (flag == 0) ans = i;
	}

	if (ans == -1 ) ans = mx + 1;
	return ans;
}

int missingNumber1(int arr[], int n) {
	map<int, bool> mp;

	for (int i = 0; i <= n + 1; i++) mp[i] = false;
	debug(mp);

	for (int i = 0; i < n ; i++) mp[arr[i]] = true;
	debug(mp);

	for (int i = 0; i <= n + 1; i++) {
		if (mp[i] == false) {
			return i;
		}
	}
	return -1;

}

// //////////////////////////////
// 14. Count only Repeated
pair<int, int> findRepeating1(int *arr, int n) {
	int mx = arr[n - 1];
	int freq[mx + 1] = {0};
	for (int i = 0; i < n ; i++)
		freq[arr[i]]++;

	pair<int, int> pr{ -1, -1};
	for (int i = 0; i < mx + 1; i++) {
		if (freq[i] > 1) {
			pr.first = i;
			pr.second = freq[i];
			break;
		}
	}


	return pr;
}

// part 2 => approach
pair<int, int> findRepeating(int *arr, int n) {
	int cnt = 0, ans = 0;
	pair<int , int > pr{ -1, -1};
	// int flag = 0;
	for (int i = 0; i < n - 2; i++) {
		if (arr[i] == arr[i + 1]) {
			// flag = 1;
			cnt++;
			ans = arr[i];
		}
	}
	// if (flag == 0) return pr;
	if (cnt == 0) return pr;
	pr.first = ans;
	pr.second = cnt + 1;
	return pr;
}

//////////////////////////////////////////
// 15. Count More than n/k Occurences
// n/k

// 1st approach
int countOccurence1(int arr[], int n, int k) {
	int mx = INT_MIN;
	for (int i = 0; i < n ; i++)
		mx = max(mx, arr[i]);

	int fq[mx + 1] = {0};
	for (int i = 0; i < n ; i++)
		fq[arr[i]]++;

	int cnt = 0;
	for (int i = 0; i < mx + 1; i++) {
		if (fq[i] > n / k ) {
			cnt++;
		}
	}

	return cnt;
}

// 2nd approach
int countOccurence(int arr[], int n, int k) {
	sort(arr, arr + n);
	int cnt = 1;
	int res = 0;
	// 2 2 4 35 35
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1]) {
			cnt++;
		}
		else if (cnt > n / k) {
			res++;
			cnt = 1;
		} else cnt = 1;
	}
	if (cnt > n / k) {
		res++;
	}
	return res;
}



////////////////////////////////////
// 16. Allocate minimum number of pages
bool isPossible(int A[], int pages, int students, int N) {
	int cnt = 0;
	int sumAllocated = 0;

	for (int i = 0; i < N; i++) {
		if (sumAllocated + A[i] > pages) {
			cnt++;
			sumAllocated = A[i];
			if (sumAllocated > pages) return false;
		} else {
			sumAllocated += A[i];
		}
	}
	if (cnt < students) return true;
	return false;
}
int findPages(int A[], int N, int M)
{
	if (M > N) return -1;
	int l = A[0];
	int h = 0;

	for (int i = 0; i < N ; i++) {
		h += A[i];
		l = min(l, A[i]);
	}

	while (l <= h) {
		int m = l + (h - l) / 2;
		if (isPossible(A, m, M, N) == true) h = m - 1;
		else l = m + 1;
	}
	return l;
}


// ///////////////////////////////////////
// 17. Subarray with given sum
vector<int> subarraySum(int arr[], int n, long long s)
{
	/*N = 5, S = 12
	A[] = {1,2,3,7,5}
	Output: 2 4*/
	int i = 0, j = 0;
	int sum = 0;

	vector<int> vec;
	if (sum == s) {
		vec.push_back(-1);
		return vec;
	}
	while (j < n) {
		sum += arr[j];
		if (sum == s) {
			vec.push_back(++i);
			vec.push_back(++j);
			return vec;
		} else if (sum > s) {
			while (sum > s) {
				sum -= arr[i];
				i++;
				if (sum == s) {
					vec.push_back(++i);
					vec.push_back(++j);
					return vec;
				}
			}
		}
		j++;
	}

	vec.push_back(-1);
	return vec;
}


///////////////////////////////////////////////////
// 18. Median of Two sorted arrays
int findMedian(int arr[], int n, int brr[], int m)
{
	if (m < n)
		return findMedian(brr, m ,  arr, n);

	int l = 0, h = n;
	while (l <= h) {
		int cut1 = (l + h) >> 1;
		int cut2 = (n + m + 1) / 2 - cut1;

		int left1 = (cut1 == 0) ? INT_MIN : arr[cut1 - 1];
		int left2 = (cut2 == 0) ? INT_MIN : brr[cut2 - 1];

		int right1 = (cut1 == n) ? INT_MAX : arr[cut1];
		int right2 = (cut2 == m) ? INT_MAX : brr[cut2];

		if (left1 <= right2 && left2 <= right1) {
			if ((n + m ) % 2 == 0) {
				return (max(left1, left2) + min(right1, right2)) / 2.0;
			} else {
				return max(left1, left2);
			}
		}
		else if (left1 > right2)
		{
			h = cut1 - 1;
		}
		else
		{
			l = cut1 + 1;
		}
	}
	return 0.0;
}
int main()
{
	debug_code();
	init_code();
	// int arr[] = {1, 2, 3, 4, 6};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// int x = 6;
	// cout << searchInSorted(arr, n, x);

	// count 1's in the not-increasing array
	// int arr[] = {1,1,1,1,1,0,0,0};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << countOnes(arr, n);

	// sqrt of number
	// long long int x = 6179767;
	// cout << floorSqrt(x);
	// cout << floorSqrt1(x);

	// Majority Element
	// int arr[] = {3,1,3,3,2};
	// int arr[] = {1, 13};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << majorityElement(arr, n);

	//////////////////////////////
	// first occurence in the array
	// int arr[] = {1,1,2,2,3,4,5,5,6,7};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// int x = 2;
	// cout << first_occurence(arr, n , x);


	// find peak element in the array
	// int arr[] =  {1, 2, 3};
	// int arr[] = {20, 30, 40, 50, 60, 5, 10 };
	// int arr[] = {17,19,9,5,3,6,17,7,18,16,18,11,3,15,2};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << peak_element(arr, n);
	// cout << peak_element1(arr, n);


//////////////////////////////////
	// flor in the array
	// long long int arr[] = {1,2,8,10,11,12,19};
	// long long int arr[] = {1, 2, 8, 10, 11, 12, 19};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// long long int x = 5;
	// cout << findFloor1(arr, n , x);

//////////////////////////////////////
	// 9. Minimum Number in a sorted rotated
	// int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << minNumber(arr, n );

/////////////////////////////////////////////////
	// repeating arrray elements
	// int arr[] = {4, 2, 4, 5, 2, 3, 1};
	// int n = 2;
	// vector<int> vec = printRepeating(arr, n);
	// for(auto it : vec) cout << it << " ";
	// printRepeating(arr,  N);

	/////
	// int arr[] = {1 , 2, 2, 1};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// printRepeating2(arr, n);


	///////////////////////////////////////////
	// 11. Roof Top

	// int arr[]= {1,2,2,3,2};
	// int arr[] = {1,2,3,4};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << maxStep(arr, n);

///////////////////////////////////////////////
	// 12. Maximum Water Between Two Buildings
	// int arr[] = {2, 1, 3, 4, 6, 5};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << maxWater(arr, n);

	////////////////////////////////////////////////////
	// int arr[] = {1, 2, 3, 4, 5};
	// // int arr[] = {0, -10, 1, 3, -20};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << missingNumber1(arr, n);
	// cout << missingNumber1(arr, n);



	// //////////////////////////////////////
	// 14. Count only Repeated
	// int arr[] = {1, 2, 3, 3, 4};
	// int  n = sizeof(arr) / sizeof(arr[0]);
	// pair<int, int > pr = findRepeating(arr, n);
	// cout << pr.first << " " << pr.second << endl;

///////////////////////////////////////////////
	// 15. Count More than n/k Occurences
	// int arr[] = {3,1,2,2,1,2,3,3};
	// int arr[] = {2, 35, 35, 2, 4};
	// // int arr[] = {2,3,3,2};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// int k = 2;
	// cout << countOccurence(arr, n, k);
	// int a, b, c ;
	// cin >> a >> b >> c;
	// cout << lcm(lcm(a, b), c) << endl;

////////////////////////////////////////////////
	// 16. Allocate minimum number of pages
	// int A[] = {12, 34, 67, 90};
	// int N = sizeof(A) / sizeof(A[0]);
	// int M = 2;
	// cout << findPages(A, N, M);


///////////////////////////////////////////////
// 17. Subarray with given sum
	// int A[] = {1, 2, 3, 7, 5};
	// int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int n = sizeof(A) / sizeof(A[0]);
	// int s = 15;
	// vector<int> vec =  subarraySum(A, n , s);
	// for (auto it : vec) cout << it << " ";

///////////////////////////////////////////
	// 18. Median of Two sorted arrays
	// int arr[] = {1, 2, 3, 4, 5};
	// int brr[] = {3, 4, 5, 6, 7, 8};
	int arr[] = {1, 2};
	int brr[] = {2, 3, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = sizeof(brr) / sizeof(brr[0]);
	cout << findMedian(arr, n , brr, m);
}