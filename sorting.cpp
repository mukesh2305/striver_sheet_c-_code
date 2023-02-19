#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////////
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

///////////////////////////////////////////////////////////
struct point {
	int x, y;
};

// 2d arrray
bool my_comp(point p1, point p2) {
	return p1.x < p2.x;
}
void stl() {

	int arr[] = {1, 2, 5, 4, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n); // ascending order sorting
	for (auto it : arr) cout << it << " ";
	cout << endl;
	sort(arr, arr + n, greater<int>()); // decending order sorting
	for (auto it : arr) cout << it << " ";
	cout << endl << endl;


	point arr1[] = {{3, 10}, {2, 8}, {5, 4}};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	sort(arr1, arr1 + n1, my_comp); // sort function internally using "Quick sort"
	for (auto i : arr1) cout << i.x << " " << i.y << endl;

	/////////////////////////////////////////////
	// stable sorting algoritham
	// arr[] = {("anil", 50), ("ayan", "80"), ("piyush", 50), ("ramesh", 80)};
	// after sorting using stable sorting algo
	// arr[] = {("anil", 50), ("piyush", 50),("ayan", "80"),("ramesh", 80)};
	// after sorting using unstable sorting algo
	// arr[] = { ("piyush", 50), ("anil", 50),("ramesh", 80),("ayan", "80")};

	// Example
	//  stable Algo : Bubble sort, Insertion sort, Merge sort
	// unstable Algo: selection sort, QuickSort, Heap sort
}
////////////////////////////////////////////////////////
// -----> bubble sort
// 1st approach
void bubble_sort(int arr[], int n) {
	bool swapped;
	for (int ro = 1; ro < n; ro++) {
		for (int i = 0; i < (n - ro); i++) {
			if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
			swapped = true;
		}
		if (swapped == false) break;
	}
}

void solve_buble_sort() {
	int arr[] = {2, 4, 1, 7, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (auto it : arr) cout << it << " ";
	cout << endl;
	bubble_sort(arr, n);
	for (auto it : arr) cout << it << " ";
	cout << endl;
}

////////////////////////////////////////////////
//  it optimize memory
// selection sort algo
//  unstable algo => because order of same element may change

int min_ind(int arr[], int n , int k) {
	int mn = INT_MAX;
	int ind = -1;
	for (int i = k; i < n ; i++) {
		if (mn > arr[i]) {
			mn = arr[i];
			ind = i;
		}
	}
	return ind;
}
void selection_sort(int arr[], int n) {
	for (int i = 0; i < (n - 1); i++) {
		int ind = min_ind(arr, n , i);
		swap(arr[i], arr[ind]);
	}
}
void solve_selection_sort() {
	int arr[] = {2, 4, 1, 7, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (auto it : arr) cout << it << " ";
	cout << endl;
	selection_sort(arr, n);
	for (auto it : arr) cout << it << " ";
	cout << endl;

}

///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//  insertion sort // stable algo
//  TC => O(n^2)
void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n ; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp ) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
void solve_insertion_sort() {
	int arr[] = {2, 4, 1, 7, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (auto it : arr) cout << it << " ";
	cout << endl;
	insertion_sort(arr, n);
	for (auto it : arr) cout << it << " ";
	cout << endl;
}

////////////////////////////////////////////////////////////////
// merge two list sorted // divide and conquer approach
// merging for 2 list
/*
   arr   brr     crr
i<-2   	 5->j    2
   8   	 9       5
   15  	 12      8
   18  	 17      9
                 12
                 15
                 17
                 18
*/
int* merge_method(int arr[], int a , int brr[], int b) {
	int *crr = new int[a + b];
	int i = 0, j = 0, k = 0;

	while (i < a && j < b) {
		if (arr[i] < brr[j]) crr[k++] = arr[i++];
		else crr[k++] = brr[j++];
	}

	// some remaning element in  the arr List
	for (; i < a; i++) crr[k++] = arr[i];

	// some remaning element in  the brr List
	for (; j < b; j++) crr[k++] = brr[j];
	return crr;
}

// merging for more than 2 list
int* merge_more_list(int arr[], int a, int brr[], int b, int crr[], int c, int drr[], int d) {
	int *one = merge_method(arr, a, brr, b);
	int *two = merge_method(crr, c, drr, d);
	int *final = merge_method(one, a + b, two , c + d);
	return final;
}
void solve_merge_more_list() {
	int arr[] = {4, 6, 12};
	int brr[] = {3, 5, 9};
	int crr[] = {8, 10, 16};
	int drr[] = {2, 4, 18};
	int a = sizeof(arr) / sizeof(arr[0]);
	int b = sizeof(brr) / sizeof(brr[0]);
	int c = sizeof(crr) / sizeof(crr[0]);
	int d = sizeof(drr) / sizeof(drr[0]);
	int *final = merge_more_list(arr, a, brr, b , crr, c, drr, d);
	for (int i = 0; i < (a + b + c + d); i++) cout << final[i] << " ";
}

//////////////////////////////////////////////////////////////
// / TC O(n logn); // merge sort is suitable for linked list
// merge sort can sort large size data using external merging technique
//  merge sort is stable
// require extra space => not in place sort

void merge(int arr[], int lo, int mid, int hi) {
	int i = lo, j = mid + 1, k = lo;
	int brr[100];
	while (i <= mid && j <= hi) {
		if (arr[i] < arr[j]) brr[k++] = arr[i++];
		else brr[k++] = arr[j++];
	}
	for (; i <= mid ; i++) brr[k++] = arr[i];
	for (; j <= hi ; i++) brr[k++] = arr[j];

	for (int i = lo ; i <= hi ; i++) arr[i] = brr[i];
}

void merge_sort(int arr[], int lo , int hi) {
	if (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		merge_sort(arr, lo, mid);
		merge_sort(arr, mid + 1, hi);
		merge(arr, lo, mid, hi);
	}
}

void solve_merge_sort() {
	int arr[] = {2, 4, 1, 7, 0, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (auto it : arr) cout << it << " ";
	cout << endl;
	insertion_sort(arr, n);
	for (auto it : arr) cout << it << " ";
	cout << endl;
}

////////////////////////////////////////////////////////////
// insertion of 2 soerted array
void intersection_array(int arr[], int a, int brr[], int b, set<int> &st) {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b ; j++) {
			if (arr[i] == brr[j]) {
				st.insert(arr[i]); break;
			}
		}
}
void intersection_array1(int arr[], int a, int brr[], int b, set<int> &st) {
	for (int i = 0; i < a; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) continue;
		for (int j = 0; j < b ; j++) {
			if (arr[i] == brr[j]) {
				st.insert(arr[i]); break;
			}
		}
	}
}
// 3rd approach using merge sort function merge this optimal approach
//  this is used in the sorted array
void intersection_array2(int arr[], int a, int brr[], int b, set<int> &st) {
// int A[] = {3, 5, 10, 10, 10, 15, 15, 20};
	// int B[] = { 5, 10, 10, 15,30};
	int i = 0, j = 0;
	while (i < a && j < b) {
		if (i > 0 && arr[i] == arr[i - 1]) {
			i++;
			continue;
		}

		if (arr[i] < brr[j]) i++;
		else if (arr[i] > brr[j]) j++;
		else if (arr[i] == brr[i]) {
			cout << arr[i] << " ";
			i++, j++;
		}
	}
}
void solve_intersection_array() {
	int arr[] = {3, 5, 10, 10, 10, 15, 15, 20};
	int brr[] = {5, 10, 10, 10, 15, 30};
	int a = sizeof(arr) / sizeof(arr[0]);
	int b = sizeof(brr) / sizeof(brr[0]);
	set<int> st;
	// intersection_array(arr, a, brr, b, st);
	// intersection_array1(arr, a, brr, b, st);
	intersection_array1(arr, a, brr, b, st);
	for (auto a : st) cout << a << " ";
}

////////////////////////////////////////////////////////////////////////
// union of two sorted array
// 1st approach => TC => O(mx) // SC O(mx);
void union_array1(int arr[], int a, int brr[], int b ) {
// int arr[] = {3, 5, 10, 10, 10, 15, 15, 20};
// int brr[] = { 5, 10, 10, 15,30};

	int mx = arr[a - 1] > brr [b - 1] ? arr[a - 1] : brr[b - 1];
	int fq[mx + 1] = {false};

	for (int i = 0; i < a; i++) fq[arr[i]] = true;
	for (int i = 0; i < b; i++) fq[brr[i]] = true;

	for (int i = 0; i < mx + 1; i++) if (fq[i] == true) cout << i << " ";
}


void union_array2(int arr[], int a, int brr[], int b ) {
// int arr[] = {3, 5, 10, 10, 10, 15, 15, 20};
// int brr[] = { 5, 10, 10, 15,30};
	int i = 0, j = 0;
	while ( i < a && j < b) {
		if (i > 0 && arr[i] == brr[i - 1]) {
			i++;
			continue;
		}

		if (j > 0 && arr[j] == brr[j - 1]) {
			j++;
			continue;
		}

		if (arr[i] < brr[j]) {
			cout << arr[i] << " ";
			i++;
		} else if (brr[j] > arr[i]) {
			cout << brr[j] << " ";
			j++;
		}  else if (arr[i] == brr[j]) {
			cout << arr[i] << " ";
			i++, j++;
		}
	}

	// print reamaning elements
	while (i < a) cout << arr[i++] << " ";
	while (j < b) cout << arr[j++] << " ";
}

void solve_union_array() {
	// int arr[] = {3, 5, 10, 10, 10, 15, 15, 20, 21, 22, 23, 41};
	// int brr[] = { 5, 10, 10, 15, 30, 31, 32, 41};
	int arr[] = { 1, 2, 2, 4, 5, 6 };
	int brr[] = { 2, 3, 5, 7 };

	int a = sizeof(arr) / sizeof(arr[0]);
	int b = sizeof(brr) / sizeof(brr[0]);
	// union_array1(arr, a, brr, b);
	union_array1(arr, a, brr, b);
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
//  count of inversion in the array
// 1ST appraoch => O(N^2) TC
// called inversion
// if i < j and arr[i] > arr[j]

int inversion(int arr[], int n) {
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n ; j++)
			if (arr[i] > arr[j]) res++;
	return res ;
}

int inversion1(int arr[], int n) {
	int cnt = 0;
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		if (arr[lo] > arr[hi]) {
			cnt++;
		}
		if (lo == hi - 1) {
			hi--;
			lo = 0;
		}  else lo++;
	}
	return cnt;
}

// 3rd approach using merge sort


int countAndMerge(int low, int mid , int high, int arr[], int temp[]) {
	int cnt = 0;
	int i = low, j = mid , k = low;
	while (i <= mid - 1 && j <= high) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
			cnt += mid - i ;
		}
	}
	while (i <= mid - 1) {
		temp[k++] = arr[i++];
	}
	while (j <= high) {
		temp[k++] = arr[j++];
	}
	for (int i = low; i <= high; i++) {
		arr[i] = temp[i];
	}
	return cnt;
}
int inversion2(int lo, int hi , int arr[], int brr[]) {
	int mid , res = 0;
	if (lo < hi) {
		mid = lo + (hi - lo) / 2;
		res += inversion2(lo, mid, arr, brr);
		res += inversion2(mid + 1, hi, arr, brr);
		res += countAndMerge(lo, mid + 1, hi , arr, brr);
	}
	return res;
}
void solve_inversion() {
	int arr[] = {2, 4, 1, 3, 5};
	// int arr[] = {6, 5, 4, 3, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << inversion(arr, n);
	// cout << inversion1(arr, n);
	int brr[n];
	cout << inversion2(0, n - 1, arr, brr);
}


/////////////////////////////////////////////////
// Quick sort (Divide and conqure algo)
//  10 16 8 12 15 6 3 9 5 in
//  pivot = 10
// partion in the quicksort

//  naive partition algorithem
//  stable algorithem // but not efficient

void naivePartion(int lo , int hi, int arr[], int p) {
	// 3 8 6 12 10 7
	int temp[hi - lo + 1], ind = 0;
	for (int i = lo ; i <= hi ; i++)
		if (arr[i] <= arr[p] && i != p)
			temp[ind++] = arr[i];

	temp[ind++] = arr[p];
	for (int i = lo ; i <= hi ; i++)
		if (arr[i] >  arr[p])
			temp[ind++] = arr[i];

	for (int i = lo; i <= hi; i++)
		arr[i] = temp[i - lo];
}
void solve_naivepPartion() {
	int arr[] = {5, 13, 6, 9, 12, 11, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	naivePartion(0, n - 1, arr, 3);
	for (int a : arr) cout << a << " ";
}

//////////////////////////////////////////////////
// lomoto partition
// pivot element is alway last element
int lomoto_partition(int arr[], int lo , int hi) {
	int pivot = arr[hi]; // pivot is last element
	int i = lo - 1;
	//  10, 80, 30 , 90, 40, 50, 70
	//  10, 30, 40 , 50, 80, 90, 70
	//  10, 30, 40 , 50, 80, 70, 90


	for (int j = lo; j <= hi - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[hi]);
	return (i + 1);
}


void solve_lomoto_partition() {
	int arr[] = {10, 80, 30 , 90, 40, 50, 70};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << lomoto_partition(arr, 0, n - 1) << endl;
	for (auto it : arr) cout << it << " ";
}

//////////////////////////////////////////////
// quick sort using lomoto partition
void lometoPartition_quickSort(int arr[], int l, int h) {
	if (l < h) {
		int j = lomoto_partition(arr, l , h);
		lometoPartition_quickSort(arr, l, j - 1);
		lometoPartition_quickSort(arr, j + 1, h);
	}
}

void solve_lometoPartition_quickSort() {
	int arr[] = {10 , 16 , 8 , 12 , 15 , 6 , 3 , 9 , 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// quick_sort(arr, 0, n - 1);
	lometoPartition_quickSort(arr, 0, n - 1);
	for (int k = 0; k < n; k++) cout << arr[k] << " ";
}
///////////////////////////////////////////////
// hoare partion // most used partiton also
int hoare_partiton(int arr[], int lo, int hi) {
	int p = arr[lo]; // 10
	int i = lo , j = hi + 1;
	// for (int k = 0; k < lo + hi + 1; k++) cout << arr[k] << " "; cout << endl;
	while (i < j) {

		do {
			i++;
		} while (arr[i] <= p); // arr[i] > p then stop

		do {
			j--;
		} while (arr[j] > p); // arr[j] <= p then stop

		if (i < j) swap(arr[i], arr[j]);
	}
	swap(arr[lo], arr[j]);
	return j;
}

void solve_hoare_partition() {
	int arr[] = {10 , 16 , 8 , 12 , 15 , 6 , 3 , 9 , 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << hoare_partiton(arr, 0, n - 1);
	cout << endl;
	for (int k = 0; k < n; k++) cout << arr[k] << " ";
}

//////////////////////////////////////////
// Time complexity of quicksort will be
// best case TC O(nlogn) // this is not possible every time
// worst case TC O(n^2)
// 1 . alway set middle element as pivot
// 2 . select Random element as pivot

// quick is recursive algorithem so it use Stack in the memory
//  best case => logn to worst case => n // stack size it take
void quick_sort(int arr[], int lo, int hi) {
	if (lo < hi) {
		int j = hoare_partiton(arr, lo, hi);
		quick_sort(arr, lo , j);
		quick_sort(arr, j + 1, hi);
	}
}
void quick_sort_tail(int arr[], int lo, int hi) {
Begin:
	if (lo < hi) {
		int j = hoare_partiton(arr, lo, hi);
		quick_sort(arr, lo , j);
		lo = j + 1;
		goto Begin; // this how we handle tail recursion so it will not take extra space
	}
}

void solve_quick_sort() {
	int arr[] = {10 , 16 , 8 , 12 , 15 , 6 , 3 , 9 , 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// quick_sort(arr, 0, n - 1);
	quick_sort_tail(arr, 0, n - 1);
	for (int k = 0; k < n; k++) cout << arr[k] << " ";
}

// ///////////////////////////////////////////////
// in unsorted array findout kth smallest element in the unsorted array
// naive approach // TC O(nlogn )

int kthSmallestEle(int arr[], int n , int k) {
	sort(arr, arr + n);
	return arr[k - 1];
}

// optimal approach
int kthSmallestEle1(int arr[], int n , int k) {
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int j = lomoto_partition(arr, lo, hi);
		if (j == k - 1) return arr[j];
		else if (j > k - 1) hi = j - 1;
		else if (j < k - 1) lo = j + 1;
	}
	return -1;
}
void solve_kthSmallestEle() {
	int arr[] = {10, 5, 30, 12};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	// cout << kthSmallestEle(arr, n , k);
	cout << kthSmallestEle1(arr, n , k);
}

////////////////////////////////////////////////////
// minimum diffrence in the array
// TC O(n2)

int min_diff(int arr[], int n) {
	// 1 8 12 5 18
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n ; j++)
			mn = min(mn, abs(arr[i] - arr[j]));
	}
	return mn;
}


// TC O(nlogn)
int min_diff1(int arr[], int n) {
	// 2 3 4 7 9 12 56
	sort(arr, arr + n);
	int mn = INT_MAX;
	for (int i = 1; i < n; i++) {
		mn = min(mn, arr[i] - arr[i - 1]);
	}
	return mn;
}
void solve_min_dff() {
	// 1 8 12 5 18
	int arr[] = {1, 8, 12, 5, 18};
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << min_diff(arr, n);
	cout << min_diff1(arr, n);
}

//////////////////////////////////////
// chocalate prooblem minimum diffrence
int chocolate_diff(int arr[], int n , int m) {
	if (m > n ) return -1;
	sort(arr , arr + n);
	int res = arr[m - 1] - arr[0];

	for (int i = 1; (i + m - 1) < n ; i++)
		res = min(res , arr[i + m - 1] - arr[i]);
	return res;
}

void solve_chocalate() {
	int arr[] = {7, 3, 2, 4, 9, 12, 56};

	int n = sizeof(arr) / sizeof(arr[0]);
	int m  = 3;
	cout << chocolate_diff(arr, n , m);
}

///////////////////////////////////////////////////////////////
// sort the array with 2 types of elements
// 1> =>  segrigation +ve and -ve
// Sort an Array with two types of elements
// naive solution 1 :

void segregatePosNegative1(int arr[], int n) {
	int ans[n], i = 0;
	for (int j = 0; j < n ; j++) {
		if (arr[j] < 0) {
			ans[i] = arr[j];
			i++;
		}
	}

	for (int j = 0; j < n ; j++) {
		if (arr[j] >= 0) {
			ans[i] = arr[j];
			i++;
		}
	}

	for (int j = 0; j < n; j++) arr[j] = ans[j];
}

// -ve values on the left side and +ve values on the right side
// TC O(n)
void segregatePosNegative2(int arr[], int n) {
	int i = -1;
	for (int j = 0; j < n ; j++) {
		if (arr[j] < 0) {
			i++;
			swap(arr[i], arr[j]);
			// cout << i << " " <<  j << endl;
		}
	}
}

// -ve values on the left side and +ve values on the right side using hoare partision
// TC O(n)
// 2 type of element
void segregatePosNegative3(int arr[], int n) {
	// int arr[] = {15, -3, -2, 18};
	int i = -1, j = n;
	while (i < j) {
		do {
			i++;
		} while (arr[i] < 0);

		do {
			j--;
		} while (arr[j] >= 0);

		if (i < j) swap(arr[i], arr[j]);
	}
}

void solve_segregatePosNegative1() {
	int arr[] = {15, -3, -2, 18};
	int n = sizeof(arr) / sizeof(arr[0]);
	// segregatePosNegative1(arr, n);
	// segregatePosNegative2(arr, n);
	segregatePosNegative3(arr, n);
	for (auto it : arr) cout << it << " ";
}


///////////////////////////////////////////////////////
// sort element with 3 types of elements
//  sort and array of 0 and 1 and 2
// naive solution

void sort012(int arr[], int n) {
	int i = 0, ans[n];
	for (int j = 0; j < n; j++) {
		if (arr[j] == 0) {
			ans[i] = arr[j];
			i++;
		}
	}

	for (int j = 0; j < n; j++) {
		if (arr[j] == 1) {
			ans[i] = arr[j];
			i++;
		}
	}

	for (int j = 0; j < n; j++) {
		if (arr[j] == 2) {
			ans[i] = arr[j];
			i++;
		}
	}

	for (int j = 0; j < n; j++) arr[j] = ans[j];
}
void sort012_1(int arr[], int n) {
	int lo = 0, hi = n - 1, mid = 0;
	while (mid <= hi) {
		if (arr[mid] == 0) {
			swap(arr[lo], arr[mid]);
			lo++, mid++;
		} else if (arr[mid] == 1) mid++;
		else if (arr[mid] == 2) {
			swap(arr[mid], arr[hi]);
			hi--;
		}
	}
}

void solve_sort012() {
	// sort 3 element sorting 0, 1 and 2
	int arr [] = {0, 1, 1, 2, 0, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	// sort012(arr, n);
	sort012_1(arr, n);
	for (auto it : arr) cout << it << " ";
}

/////////////////////////////////////////////////////////
void interval(vector<pair<int, int>> v) {
	vector<pair<int, int> > res;
	res.push_back(v[0]);
	// 1,3  2,4  5,7  6,8
	for (int i = 1; i < (int)v.size(); i++) {
		if (res[res.size() - 1].second >= v[i].first) {
			res[res.size() - 1].second = max(res[res.size() - 1].second, v[i].second);
		} else {
			res.push_back(v[i]);
		}
	}
	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}
}

void solve_interval() {
	vector<pair<int, int>> v =  { {1, 3} , {2, 4},  {5, 7},  {6, 8} };
	sort(v.begin(), v.end());
	interval(v);

}
////////////////////////////////////////////////////////////
// meeting maximum people in the meeting
int max_people(int arr[], int dep[], int n) {
	sort(arr, arr + n);
	sort(dep, dep + n);
	int i = 1, j = 0, curr = 1, res = 1;
	while (i < n && j < n) {
		if (arr[i] <= dep[j]) curr++, i++;
		else curr--, j++;
		res = max(res, curr);
	}
	return res;
}
void solve_max_people() {
	// int arr[] = {900, 600, 700};
	// int dep[] = {1000, 800, 730};
	int arr[] = {800, 700, 600, 500};
	int dep[] = {840, 820, 830, 530};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << max_people(arr, dep, n);
}

////////////////////////////////////////////////////////////////////////////////
// heap sort
void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1; // for o indexing
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest]) largest = l;

	if (r < n && arr[r] > arr[largest]) largest = r;

	if (largest != i ) {
		swap(arr[i], arr[largest]);
		heapify(arr, n , i);
	}

}
void buildHeap(int arr[], int n) {
	for (int i = n / 2  - 1; i >= 0; i--)
		heapify(arr, n , i);
}

void heap_sort(int arr[], int n) {
	buildHeap(arr, n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void solve_heap_sort() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

//////////////////////////////////////////////////////////
// counting sort

void counting_sort(int arr[], int n) {
	int mn = INT_MAX, mx = INT_MIN;
	for (int i = 0; i < n ; i++) {
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
	}
	int range = mx - mn + 1;

	int fq[range] = {0};

	for (int i = 0; i < n ; i++)
		fq[arr[i] - mn]++;

	int k = 0;
	for (int i = 0; i < range; i++) {
		for (int j = 0; j < fq[i]; j++) {
			arr[k++] = i + mn;
		}
	}

	for (int i = 0; i < n ; i++) cout << arr[i] << " ";
}


void counting_sort_1(int arr[], int n) {
	int mn = INT_MAX, mx = INT_MIN;
	for (int i = 0; i < n ; i++) {
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
	}
	int range = mx - mn + 1;
	int fq[range] = {0};

	for (int i = 0; i < n ; i++) fq[arr[i] - mn]++;

	// convert fq array into the prefix sum array
	for (int i = 1; i < mx - mn + 1; i++) fq[i] = fq[i] + fq[i - 1];

	int ans[n] = {0};

	for (int i = n - 1; i >= 0; i--) {
		int val = arr[i];
		int pos = fq[val - mn];
		int ind = pos - 1 ;
		ans[ind] = val;
		fq[val - mn]--;
	}

	for (int i = 0; i < n; i++) arr[i] = ans[i];

	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

void solve_counting_sort() {
	int arr[] = {9, 6, 3, 5, 3, 4, 3,  6, 9, 6, 4, 6, 5, 8, 9, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	// counting_sort(arr, n);
	counting_sort_1(arr, n);
}

//////////////////////////////////////////////////////////////
void radix_sort(int arr[], int n) {
	int mx = INT_MIN; // get max number to know number of digits

	for (int i = 0; i < n ; i++) mx = max(mx, arr[i]);


	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number

	// for (int exp = 1 ; mx / exp > 0 ; exp *= 10)
	// 	counting_sort_1(arr, n , exp);
}

void solve_radix_sort() {
	int arr[] = {123, 99, 88, 225, 88, 128};
	int n = sizeof(arr) / sizeof(arr[0]);
	radix_sort(arr, n);
	for (int it : arr) cout << it << " ";
}

////////////////////////////////////////////////////////////////////
// question from bosscoder
// 493. Reverse Pairs
int reversePairs(vector<int>& nums) {
	int cnt = 0;
	for (int i = 0; i < (int)nums.size() ; i++)
		for (int j = i + 1; j < (int)nums.size() ; j++)
			if (nums[i] > 2 * nums[j]) cnt++;
	return cnt;
}

////////// 2nd approach
int merge_rev(vector<int> &nums, int lo, int mid, int hi) {
	int cnt = 0;
	int j = mid + 1;
	// 2, 4, 3, 5, 1

	for (int i = lo; i <= mid; i++) {
		while (j <= hi && nums[i] > 2LL * nums[j]) j++;
		cnt += (j - (mid + 1));
	}

	vector<int> temp;
	int left = lo, right = mid + 1;
	while (left <= mid && right <= hi) {
		if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
		else temp.push_back(nums[right++]);
	}

	while (left <= mid) temp.push_back(nums[left++]);

	while (right <= hi) temp.push_back(nums[right++]);

	for (int i = lo; i <= hi; i++) nums[i] = temp[i - lo];
	return cnt;
}
int mergeSort_rev(vector<int> &nums, int lo, int hi) {
	if (lo >= hi) return 0;
	int mid = (lo + hi) / 2;
	int inv  = mergeSort_rev(nums, lo, mid);
	inv  += mergeSort_rev(nums, mid + 1, hi);
	inv  += merge_rev(nums, lo, mid,  hi);
	return inv;
}
int reversePairs1(vector<int> &nums) {
	return mergeSort_rev(nums, 0 , nums.size() - 1);
}
void solve_reversePairs() {
	// vector<int> nums = {1, 3, 2, 3, 1};
	vector<int> nums = {2, 4, 3, 5, 1};
	// cout << reversePairs(nums);
	cout << reversePairs1(nums);
}

////////////////////////////////////
// 315. Count of Smaller Numbers After Self
vector<int> countSmaller(vector<int>& nums) {

	vector<int> temp;
	for (int i = 0; i < nums.size(); i++) {
		int cnt = 0;
		for (int j = i + 1; j < nums.size(); j++)
			if (nums[i] > nums[j]) cnt++;
		temp.push_back(cnt);
	}
	return temp;
}


// optimal approach
void _merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right) {
	vector<pair<int, int>> temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right) {

		if (v[i].first <= v[j].first) {
			temp[k++] = v[j++];
		}

		else {

			count[v[i].second] += right - j + 1;
			temp[k++] = v[i++];

		}

	}


	while (i <= mid) {
		temp[k++] = v[i++];
	}

	while (j <= right) {
		temp[k++] = v[j++];
	}

	for (int i = left; i <= right; i++) {
		v[i] = temp[i - left];
	}

}

void _mergeSort(vector<int> &count, vector<pair<int, int>> &v, int left, int right) {


	if (left < right) {
		int mid = left + (right - left) / 2;
		_mergeSort(count, v, left, mid);
		_mergeSort(count, v, mid + 1, right);
		_merge(count, v, left, mid, right);
	}

}

vector<int> _countSmaller(vector<int>& nums) {
	int n = nums.size();
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		pair<int, int> p;
		p.first = nums[i];
		p.second = i;
		v[i] = p;
	}


	vector<int> count(n, 0);
	_mergeSort(count, v, 0, n - 1);
	return count;

}

void solve_countSmaller() {
	vector<int> nums = {5, 2, 6, 1};
	// for (auto it : countSmaller(nums)) cout << it << " ";
	for (auto it : _countSmaller(nums)) cout << it << " ";
}

int main() {
	init_code();
	// stl();
	// solve_buble_sort();
	// solve_selection_sort();
	// solve_insertion_sort();
	// solve_merge_more_list();
	// solve_merge_sort();
	// solve_intersection_array();
	// solve_union_array();
	// solve_inversion();
	// solve_naivepPartion();
	// solve_lomoto_partition();
	// solve_lometoPartition_quickSort();
	// solve_hoare_partition();
	// solve_quick_sort();
	// solve_kthSmallestEle();
	// solve_min_dff();
	// solve_chocalate();
	// solve_segregatePosNegative1();
	// solve_sort012();
	// solve_interval();
	// solve_max_people();
	// solve_heap_sort();
	// solve_counting_sort();
	// solve_radix_sort();
	// solve_reversePairs();
	solve_countSmaller();
}