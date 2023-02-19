#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////
// serach element in the sorted array
// return index of that element
// 1st approach => iterating way
int serach_element(int arr[], int n, int key)
{
	int l = 0;
	int h = n - 1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (arr[m] == key)
			return m;

		else if (arr[m] < key)
			l = m + 1;
		else
			h = m - 1;
	}
	return -1;
}

// 2nd approach => recusive way
int serach_element1(int arr[], int n, int key, int l, int h)
{
	if (l > h)
		return -1;
	int m = l + (h - l) / 2;
	if (arr[m] == key)
		return m;
	else if (arr[m] < key)
		return serach_element1(arr, n, key, m + 1, h);
	else
		return serach_element1(arr, n, key, l, m - 1);
}

///////////////////////////////////////////////////
// first occurence of element index
// 1st approach => iterative
int first_occurence(int arr[], int n, int key)
{
	int l = 0;
	int h = n - 1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (arr[m] == key)
		{
			if (m == 0 || arr[m - 1] != key)
				return m;
			else
				h = m - 1;
		}

		else if (arr[m] < key)
			l = m + 1;
		else
			h = m - 1;
	}
}

// 2nd approach => recursive
int first_occurence1(int arr[], int n, int key, int l, int h)
{
	if (l > h)
		return -1;
	int m = l + (h - l) / 2;
	if (arr[m] == key)
	{
		if (m == 0 || arr[m - 1] != key)
			return m;
		else
			return first_occurence1(arr, n, key, l, m - 1);
	}
	else if (arr[m] < key)
		return first_occurence1(arr, n, key, m + 1, h);
	else
		return first_occurence1(arr, n, key, l, m - 1);
}

// 3rd approach => iterative with ans
int first_occurence2(int arr[], int n, int key)
{
	int l = 0;
	int h = n - 1;
	int ans = -1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (arr[m] == key)
		{
			ans = m;
			h = m - 1;
			continue;
		}

		if (arr[m] < key)
			l = m + 1;
		else
			h = m - 1;
	}
	return ans;
}

/////////////////////////////////////////////////
//  last occurence in the sorted array
// 1st approach => iterative approach
int last_occurence(int arr[], int n, int key)
{
	int l = 0;
	int h = n - 1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (arr[m] == key)
		{
			if (m == n - 1 || arr[m + 1] != key)
				return m;
			else
			{
				l = m + 1;
			}
		}
		else if (arr[m] < key)
			l = m + 1;
		else
		{
			h = m - 1;
		}
	}

	return -1;
}

// 2nd approach => recursive approach
int last_occurence1(int arr[], int n, int key, int l, int h)
{
	if (l > h)
		return -1;
	int m = l + (h - l) / 2;
	if (arr[m] == key)
	{
		if (m == n - 1 || arr[m + 1] != key)
			return m;
		else
			return last_occurence1(arr, n, key, m + 1, h);
	}
	else if (arr[m] < key)
		return last_occurence1(arr, n, key, m + 1, h);
	else
		return last_occurence1(arr, n, key, l, m - 1);
}

// 3rd approach => iterative with ans
int last_occurence2(int arr[], int n, int key)
{
	int l = 0;
	int h = n - 1;
	int ans = -1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (arr[m] == key)
		{
			ans = m;
			l = m + 1;
			continue;
		}

		if (arr[m] < key)
			l = m + 1;
		else
			h = m - 1;
	}
	return ans;
}

/////////////////////////////////////////////////////
//  count the occurence of element in the sorted array
// first approach
int count_total_occurence(int arr[], int n, int key)
{
	int first = first_occurence(arr, n, key);
	if (first == -1)
		return 0;
	else
		return last_occurence(arr, n, key) - first + 1;
}

// second approach
int count_total_occurence1(int arr[], int n, int key)
{
	int ind = serach_element(arr, n, key);
	if (ind == -1)
		return 0;

	// count element on the left side
	int cnt = 1;
	int l = ind - 1;
	while (l >= 0 && arr[l] == key)
		cnt++, l--;

	// count element on the right side
	int r = ind + 1;
	while (r < n && arr[r] == key)
		cnt++, r++;

	return cnt;
}

// 3rd approach reamaning

//////////////////////////////////////////////
// count 1's in the binary array
int countOnes(int arr[], int n)
{
	int l = 0, h = n - 1;
	int key = 1;
	int cnt = 0;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (arr[m] == key)
		{
			if (m == 0 || arr[m - 1] != key)
			{
				cnt = m;
				break;
			}
			else
			{
				h = m - 1;
			}
		}
		else if (arr[m] == 0)
		{
			l = m + 1;
		}
	}

	// find index of first occurence n - firstOcuurence index;
	return n - cnt;
}

// ////////////////////////////////////////////
// sqrt og number
//  1st approach // linear approach
int sqrtNumber(int x)
{
	int i = 1;
	while (i * i <= x)
	{
		i++;
	}

	return (i - 1);
}
//  14
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14
//  2nd approach
int sqrtNumber2(int x)
{
	int l = 1, h = x, ans = -1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		int mul = m * m;
		if (mul == x)
			return m;
		else if (mul > x)
			h = m - 1;
		else
		{
			l = m + 1;
			ans = m;
		}
	}
	return ans;
}

// 3rd approach
int sqrtNumber1(int x)
{
	int l = 1, h = x, ans = 1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (m * m <= x)
		{
			ans = m;
			l = m + 1;
		}
		else
			h = m - 1;
	}
	return ans;
}

////////////////////////////////////////////////
// search element in the infinite size array
int serach_element_infinite(int arr[], int n, int key)
{
	int i = 0;
	while (true)
	{
		if (arr[i] == key)
			return i;
		else if (arr[i] > key)
			return -1;
		i++;
	}
}

// 2nd approach
int binary_search(int arr[], int n, int key, int low, int high)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
int serach_element_infinite1(int arr[], int n, int key)
{
	int low = 0;
	int high = 1;
	while (arr[high] < key)
	{
		low = high;
		high *= 2;
	}
	return binary_search(arr, n, key, low, high);
}

///////////////////////
// search  element in the sorted rotated array
int sorted_roated(int arr[], int n, int key)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[low] < arr[mid])
		{
			if (key >= arr[low] && key < arr[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		else
		{
			if (key > arr[mid] && key < arr[high])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
	return -1;
}

// //////////////////////////////////
// find peak element in the array
// 1st approach
void peak_element(int arr[], int n)
{
	if (n == 1)
		cout << arr[0];
	if (arr[0] >= arr[1])
		cout << arr[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
			cout << arr[i] << endl;
	}
}

// 2nd approach
int peak_element1(int arr[], int n)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
		{
			return mid;
		}
		if (mid > 0 && arr[mid - 1] >= arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

//////////////////////////////////////////////////
// find paire whose sum = k;
// 1st approach => naieve approach
bool paire_sum1(int arr[], int n)
{
	int sum = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		sum = arr[i];
		for (int j = i + 1; j < n; j++)
		{
			sum += arr[j];
			if (sum == 17)
			{
				ans.push_back(arr[i]);
				ans.push_back(arr[j]);
				return true;
			}
			sum -= arr[j];
		}
		sum = 0;
	}
	return false;
}

// 2nd approach efficient approach
//  this approach used when array is sorted
bool paire_sum(int arr[], int n, int key)
{
	// array is sorted
	int low = 0;
	int high = n - 1;
	while (low < high)
	{
		if ((arr[high] + arr[low]) == key)
		{
			// cout << arr[low] << " " << arr[high] << endl;
			return true;
		}
		else if ((arr[low] + arr[high]) < key)
		{
			low++;
		}
		else if ((arr[low] + arr[high] > key))
		{
			high--;
		}
	}
	return false;
}

// given sorted array find triplate whose sum = key then print that triplate
// naive solution is to use 3 for loop
bool triplate_sum(int arr[], int n, int key)
{
	int low, high = n - 1;
	sort(arr, arr + n);
	//  key means sum
	for (int i = 0; i < n - 2; i++)
	{
		low = i + 1;
		while (low < high)
		{
			if (arr[i] + arr[low] + arr[high] == key)
			{
				printf("Triplet is %d, %d, %d", arr[i],
					   arr[low], arr[high]);
				return true;
			}
			else if ((arr[i] + arr[low] + arr[high]) < key)
			{
				low++;
			}
			else if ((arr[i] + arr[low] + arr[high] > key))
			{
				high--;
			}
		}
	}
	return false;
}

/////////////////////////////////////////
// given 2 sorted array and find the median of array
double median(int A[], int B[], int A_size, int B_size)
{
	vector<int> vec;
	for (int i = 0; i < A_size; i++)
	{
		vec.push_back(A[i]);
	}
	for (int i = 0; i < B_size; i++)
	{
		vec.push_back(B[i]);
	}

	sort(vec.begin(), vec.end());

	int n = vec.size();
	double ans;
	int d = n / 2;
	if (n % 2 == 0)
	{
		ans = (double)(vec[d - 1] + vec[d]) / 2;
	}
	else
	{
		ans = vec[d];
	}

	return ans;
}

// 2nd approach optimize solution for median
double median1(int A[], int B[], int A_size, int B_size)
{
	if (B_size < A_size)
		return median1(B, A, B_size, A_size);
	int low = 0, high = A_size;

	while (low <= high)
	{
		int cut1 = (low + high) >> 1;
		int cut2 = (A_size + B_size + 1) / 2 - cut1;

		int left1 = (cut1 == 0) ? INT_MIN : A[cut1 - 1];
		int left2 = (cut2 == 0) ? INT_MIN : B[cut2 - 1];

		int right1 = cut1 == A_size ? INT_MAX : A[cut1];
		int right2 = cut2 == B_size ? INT_MAX : B[cut2];

		if (left1 <= right2 && left2 <= right1)
		{
			if ((A_size + B_size) % 2 == 0)
				return (max(left1, left2) + min(right1, right2)) / 2.0;
			else
				return max(left1, left2);
		}
		else if (left1 > right2)
		{
			high = cut1 - 1;
		}
		else
		{
			low = cut1 + 1;
		}
	}
	return 0.0;
}

//////////////////////////////////
// highest freq	of element and find mx => and less than max from 0 are present in the array

int findRepating(int arr[], int n)
{
	int mx = INT_MIN;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		mp[arr[i]]++;
		mx = max(mx, arr[i]);
	}

	// this check whether all the element less than mx  is present or not
	int flag = 0;
	for (int i = mx; i >= 0; i--)
	{
		if (mp.find(mx) == mp.end())
			flag = 1;
	}

	if (flag == 1)
	{
		return 0;
	}
	else
	{
		mx = INT_MIN;
		int index = -1;
		for (auto it : mp)
		{
			if (mx < it.second)
			{
				mx = it.second;
				index = it.first;
			}
		}
		return index;
	}
}

// second solution is remaning => optimal solution

////////////////////////////////////////
// minmimum allocation striver
bool isPossible(int arr[], int pages, int students, int n) {
	int cnt = 0;
	int sumAllocates = 0;

	for(int i = 0; i < n ; i++) {
		if(sumAllocates + arr[i] > pages) {
			cnt++;
			sumAllocates = arr[i];
			if(sumAllocates > pages) return false;
		} else {
			sumAllocates += arr[i];
		}
	}

	if(cnt < students) return true;
	return false;
} 
int minimumAllocation(int arr[], int n, int students)
{
	if(students > n ) return -1;
	int low = arr[0];
	int high = 0;

	// minimum from array
	for(int i = 0; i < n ; i++) {
		high += arr[i];
		low = min(low, arr[i]);
	} 

	// binary search
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(isPossible(arr, mid, students, n) == true){
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

// Allocate Minimum Number of Pages to K students
int main()
{
	//////////////////////////////////////////////////
	// int arr[] = {10, 20, 30, 40, 40, 50, 60};
	// int key = 60;
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << serach_element(arr, n, key);
	// cout << serach_element1(arr, n , key, 0, n - 1);

	////////////////////////////////////////////////////////
	// first occurence index in the sorted array
	// int arr[] = {10, 20, 40, 40, 40, 50, 60};
	// int key = 40;
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << first_occurence(arr, n, key );
	// cout << first_occurence1(arr, n , key, 0, n-1);
	// cout << first_occurence2(arr, n , key);

	////////////////////////////////////////////
	// last occurence of sorted array
	// int arr[] = {10, 20, 40, 40, 40, 50, 60};
	// int key = 40;
	// int n = sizeof(arr) / sizeof(arr[0]);
	// // cout << last_occurence(arr, n , key);
	// // cout << last_occurence1(arr, n , key, 0, n - 1);
	// cout << last_occurence2(arr, n , key );

	//////////////////////////////////////////////
	// find occurence of number in the array
	// int arr[] = {10, 20, 40, 40, 40, 50, 60};
	// int key = 40;
	// int n = sizeof(arr) / sizeof(arr[0]);
	// // cout << count_total_occurence(arr, n , key);
	// cout << count_total_occurence1(arr, n , key);

	///////////////////////////////////////
	// count number of 1's
	// int arr[] = {1, 1, 1, 1,1};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << countOnes(arr, n);

	/////////////////////////////////////
	// sqrt of number
	// int x = 14;
	// cout << sqrtNumber(x);
	// cout << sqrtNumber1(x);

	///////////////////////////////////
	// search element in the infinite size array
	// int arr[] = {10, 20, 40, 40, 40, 50, 60};
	// int key = 10;
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << serach_element_infinite(arr, n, key);
	// cout << serach_element_infinite1(arr, n, key);

	////////////////////////////////////////
	// sorted roated array
	// int arr[] = {120, 130, 40, 50, 90, 100, 110};
	// int arr[] = {50, 90, 100, 110,120, 130, 40 };
	// int arr[] = {20, 30, 40, 50, 60, 5, 10 };
	// int key = 5;
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << sorted_roated(arr, n, key);

	///////////////////////////////////////
	// find peak element in the array
	// int arr[] = {20, 30, 40, 50, 60, 5, 10 };
	// int arr[] = {10, 20, 15, 5, 23, 90, 67 };
	// // int arr[] = {80, 70 ,60 };
	// int n = sizeof(arr) / sizeof(arr[0]);
	// // peak_element(arr, n);
	// cout << peak_element1(arr, n);

	//////////////////////////////
	// int arr[] = {3, 5, 9, 2, 8, 10, 11};
	// int arr[] = {2, 5, 8, 12, 30};
	// int arr[] = {3,  8, 13, 18};
	// int arr[] = {2, 3, 4, 8, 9, 20, 40};
	// // int arr[] = {8,4, 6};
	// int key = 14;
	// int n = sizeof(arr) / sizeof(arr[0]);
	// // cout << paire_sum(arr, n, key);
	// if (triplate_sum(arr, n , key)) {
	// 	cout << endl << " true " << endl;
	// } else cout << " false " << endl;
	// vector<int> ans = paire_sum(arr, n);
	// cout<< ans[0] << " " << ans[1] << endl ;

	// //////////////////////////////////////////////
	// find the median from the two sorted array
	// int A[] = {10, 20, 30, 40 , 50};
	// int B[] = {5, 15, 25, 35};
	// int A_size = sizeof(A) / sizeof(A[0]);
	// int B_size = sizeof(B) / sizeof(B[0]);
	// // cout << median(A, B, A_size, B_size);
	// cout << median1(A, B, A_size, B_size);

	/////////////////////////////////////////////////////
	// highest freq	of element and find mx => and less than max from 0 are present in the array
	// int arr[] = {0, 2, 1, 3, 2, 2};
	// int arr[] = {1, 2, 3, 0 , 3, 4, 5};
	// int arr[] = { 0, 0 };
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << findRepating(arr, n);

	/////////////////////////////////////////////////////////////
	//  minimum page allocation 
	int arr[] = {10, 20, 30, 40};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << minimumAllocation(arr, n, k);
}
