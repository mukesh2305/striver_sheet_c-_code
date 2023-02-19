#include <bits/stdc++.h>
using namespace std;
#define nl "\n";

int insert_ele(int arr[], int n, int x, int cap, int pos)
{
	if (n == cap)
		return n;
	int index = pos - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i])
		{
			arr[i + 1] = arr[i];
		}
		if (i == index)
		{
			arr[i] = x;
			break;
		}
	}

	return (n + 1);
}

int delete_ele(int arr[], int n, int ele)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == ele)
			break;
	}
	if (n == i)
		return -1;
	for (int j = i; j < n; j++)
	{
		arr[j] = arr[j + 1];
	}
	return 1;
}
// largest element in the array
int max_element(int arr[], int n)
{
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > mx)
			mx = arr[i];
	}
	return mx;
}

// /////////////////////////////////////////
//  second largest element
int mx_2(int arr[], int n)
{
	int mx = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];

	int second_max = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] != mx)
			if (arr[i] > second_max)
				second_max = arr[i];
	return second_max;
}

// 2nd way to find out 2nd largest

int second_largest(int arr[], int n)
{
	int largest = 0;
	int second = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > largest)
		{
			second = largest;
			largest = arr[i];
		}
		else if (arr[i] > second && arr[i] != largest)
		{
			second = arr[i];
		}
	}
	return second;
}

// ////////////////////////////////////////
// check if arrray is sorted or not
bool sorted_or_not(int arr[], int n)
{
	if (n == 1 || n == 0)
		return true;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void solve_sorted_or_not()
{
	int arr[5] = {1, 2, 5, 5, 5};
	if (sorted_or_not(arr, 5))
	{
		cout << " sorted " << nl;
	}
	else
		cout << " not sorted " << nl;
}

/////////////////////////////////////////////////
// reverse array
bool reverse_array(int arr[], int n, int i)
{
	if (i >= n / 2)
		return true;
	swap(arr[i], arr[n - 1 - i]);
	return reverse_array(arr, n, i + 1);
}

void solve_reverse()
{
	int arr[5] = {1, 2, 5, 5, 5};
	if (reverse_array(arr, 5, 0))
		for (int i = 0; i < 5; i++)
			cout << arr[i] << " ";
}

void solve_iterative_reverse()
{
	int arr[5] = {1, 2, 5, 5, 5};
	int n = 5;
	for (int i = 0; i <= n / 2; i++)
	{
		swap(arr[i], arr[n - 1 - i]);
	}

	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
}
/////////////////////////////////////////////////
//  remove duplicate from sorted array
void remove_duplicate(int arr[], int n)
{

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != arr[i + 1])
		{
			arr[j] = arr[i];
			j++;
		}
	}
}
void solved_remove_duplicate()
{
	int arr[5] = {1, 2, 5, 5};
	int n = 5;
	remove_duplicate(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

// //////////////////////////////////////////
// push all the zeros to the end of the array but order of array does not desturb
void zero_at_last(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			arr[j] = arr[i];
			j++;
		}
	}

	for (int i = j; i < n; i++)
		arr[i] = 0;
}

void zero_at_last1(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			swap(arr[i], arr[j]);
			j++;
		}
	}
}

void solve_at_last()
{
	int arr[] = {1, 4, 5, 0, 0, 0, 3, 3, 0, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	// zero_at_last(arr, n);
	zero_at_last1(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
////////////////////////////////////////////////////
//  left rotate array  1111111111
void rotate_left(int arr[], int n)
{
	int temp = arr[0];
	for (int i = 0; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;
}

void solve_left_rotate()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	rotate_left(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

/////////////////////////////////////////////////////////////
//  left rotate by d times 222222222222222
void left_rotate_times(int arr[], int n)
{
	int temp = arr[0];
	for (int i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	arr[n - 1] = temp;
}

void solve_left_rotate_times()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int times = 2;
	while (times--)
	{
		rotate_left(arr, n);
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
// optimal way to solve this left rotate problem/////////////////33333333333333333
void left_rotate_times_1(int arr[], int n, int times)
{
	vector<int> vec; // taking o(times) auxilary space
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < times)
			vec.push_back(arr[i]);
		else
		{
			arr[j] = arr[i];
			j++;
		}
	}

	for (int i = 0; i < j; i++)
		arr[j + i] = vec[i];
}

void solve_left_rotate_times_1()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int times = 22;
	int rem = times % n;
	left_rotate_times_1(arr, n, rem);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
//////////////////////////////////////// 4444444444444444444
//  find soultion for left shift that does not take O(1) auxilary space;
void reverse_func(int arr[], int low, int high)
{
	while (low < high)
		swap(arr[low++], arr[high--]);
}

void left_rotate_optimal_space_time(int arr[], int n, int times)
{
	// 1 2 3 4 5
	// 2 1 5 4 3
	// 3 4 5 1 2 

	reverse_func(arr, 0, times - 1);
	reverse_func(arr, times, n - 1);
	reverse_func(arr, 0, n - 1);
}

void solve_optimal_spce_times()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int times = 22;
	int rem = times % n;
	left_rotate_optimal_space_time(arr, n, rem);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

////////////////////////////////////////////////////////////
// leader in the array 111111111111111111111
// leader => element in the array whose right not single element is greater that element that leader elment in the array
vector<int> leader(int arr[], int n)
{
	// 7, 10, 4, 3, 6, 5, 2
	vector<int> lead;
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] <= arr[j])
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
			lead.push_back(arr[i]);
	}
	return lead;
}

void solve_leader()
{
	int arr[] = {7, 10, 4, 10, 6, 5, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> lead = leader(arr, n);
	for (auto it : lead)
		cout << it << " ";
}

/////////////// leader array 2 (optimal solution)
// 22222222222222222222222
void leader1(int arr[], int n)
{
	int curr = arr[n - 1];
	cout << curr << " ";
	for (int i = n - 2; i >= 0; i--)
	{
		if (curr < arr[i])
		{
			curr = arr[i];
			cout << curr << " ";
		}
	}
}
void solve_leadder1()
{
	int arr[] = {7, 10, 4, 10, 6, 5, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	leader1(arr, n);
}

//////////////////////////////////////////////
// 11111111111111111
// maximum diffrence between 2 array element
int diff_2_arrayele(int arr[], int n)
{
	int mxDf = arr[1] - arr[0];
	for (int i = 1; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			mxDf = max(mxDf, arr[j] - arr[0]);
	return mxDf;
	// return df;
}

void solve_diff()
{
	int arr[] = {2, 3, 10, 6, 4, 8, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << diff_2_arrayele(arr, n);
}

// 22222222222222222
//  2nd way optimal way for maximum diffrence
int diff_2_optimal(int arr[], int n)
{
	int mx = arr[1] - arr[0];
	int mn = arr[0];
	for (int j = 1; j < n; j++)
	{
		mx = max(mx, arr[j] - mn);
		mn = min(mn, arr[j]);
	}
	return mx; // this is mx diffrnece from array
}

void solve_diff_optimal()
{
	int arr[] = {2, 3, 10, 6, 4, 8, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << diff_2_arrayele(arr, n);
}
////////////////////////////////////////////////////
// count the frequency of the sorted array
void count_freq(int arr[], int n)
{
	int freq = 1, i = 1;
	while (i < n)
	{
		while (i < n && arr[i] == arr[i - 1])
		{
			freq++;
			i++;
		}
		cout << "{" << arr[i - 1] << " , " << freq << " } " << endl;
		i++;
		freq = 1;
	}

	if (n == 1 || arr[n - 1] != arr[n - 2])
		cout << "{" << arr[n - 1] << " , " << 1 << " } " << endl;
}
void count_freq1(int arr[], int n)
{
	int intial = arr[0];
	if (n == 0)
		return;
	if (n == 1)
		cout << "{" << arr[0] << " , " << 1 << " } " << endl;

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (intial != arr[i])
		{
			cout << "{" << arr[i - 1] << " , " << cnt << " } " << endl;
			intial = arr[i];
			cnt = 1;
		}
		else
			cnt++;
	}
	cout << "{" << arr[n - 1] << " , " << cnt << " } " << endl;
}

void solve_freq()
{
	int arr[] = {10, 10, 10, 20, 30, 30};
	int n = sizeof(arr) / sizeof(arr[0]);
	count_freq(arr, n);
}

// frequency of element in the unsorted array
void freq_unsorted(int arr[], int n)
{
	int mx = 0;
	for (int i = 0; i < n; i++)
		mx = max(mx, arr[i]);

	int freq[mx + 1] = {0};
	for (int i = 0; i < n; i++)
		freq[arr[i]]++;

	for (int i = 0; i < mx + 1; i++)
		if (freq[i] != 0)
			cout << i << "->" << freq[i] << nl;
}

void solve_freq_unsorted()
{
	int arr[] = {1, 10, 2, 2, 1, 5, 15, 12, 12, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	freq_unsorted(arr, n);
}
/////////////////////////////////////////////
//  stock bye and sell naive approach

int stock(int arr[], int n)
{
	// 1 5 3 8 12
	int profit = 0;
	int sell;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			sell = arr[i];
		}
		else
		{
			if (sell < arr[i])
			{
				profit += arr[i] - sell;
				sell = arr[i];
			}
			else
			{
				sell = arr[i];
			}
		}
	}
	return profit;
}
//  another approach to solve problem
int stock1(int arr[], int n)
{
	int profit = 0;
	for (int i = 1; i < n; i++)
		if (arr[i] > arr[i - 1])
			profit += (arr[i] - arr[i - 1]);
	return profit;
}

void solve_stock()
{
	int arr[] = {1, 5, 3, 1, 2, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << " profit " << stock(arr, n);
	cout << " profit " << stock1(arr, n);
}
//////////////////////////////////////////////////
//  max water hold
// 111111111111111111111 naive approach O(n^2)
int max_water(int arr[], int n)
{
	int res = 0;
	for (int i = 1; i < n; i++)
	{
		int left = arr[i];
		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);

		int right = arr[i];
		for (int j = i + 1; j < n; j++)
			right = max(right, arr[j]);

		res = res + min(left, right) - arr[i];
	}

	return res;
}

void solve_max_water()
{
	int arr[] = {3, 0, 2, 0, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << max_water(arr, n);
}

// 222222222222222 approach O(n) //  /////////// space complexity o(n) + o(n)
int max_water1(int arr[], int n)
{
	int left[n];
	int right[n];
	int res = 0; // water store in unit

	left[0] = arr[0];
	for (int i = 1; i < n - 1; i++)
		left[i] = max(left[i - 1], arr[i]);

	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], arr[i]);

	// for(int i = 1 ; i < n -1; i++) {
	// 	int var = min(left[i - 1], right[i + 1]);
	// 	if(var > arr[i]) water += var - arr[i];
	// }

	for (int i = 1; i < n - 1; i++)
		res = res + min(left[i], right[i]) - arr[i];
	return res;
}

void solve_max_water1()
{
	int arr[] = {3, 0, 2, 0, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << max_water1(arr, n);
}
// if array is increasing or decreasing order than max water collection is 0

// //////////////////////////////////////////////
//  maximum consecutive 1's in the sigle array
int max_one(int arr[], int n)
{
	// 0 1 1 0 1 0
	int mx = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			cnt = 0;
		else
		{
			cnt++;
			mx = max(mx, cnt);
		}
	}

	return mx;
}

void solve_max_one()
{
	int arr[] = {0, 1, 1, 1, 0, 1, 1, 0};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << max_one(arr, n);
}

/////////////////////////////////////////////////
// maximum sum of subarray naive approach
int maxSum_subArray(int arr[], int n)
{
	int res = arr[0];
	for (int i = 0; i < n; i++)
	{
		int curr = 0;
		for (int j = i; j < n; j++)
		{
			curr += arr[j];
			res = max(res, curr);
		}
	}

	return res;
}

int maxSum_subArray1(int arr[], int n, int i, int sum, int mx)
{
	if (i == n)
		return mx;
	sum = sum + arr[i];
	mx = max(mx, sum);
	if (sum < 0)
		sum = 0;
	return maxSum_subArray1(arr, n, i + 1, sum, mx);
}

void solve_maxSum_subArray()
{
	// int arr[] = {2, 3, -8, 7, -1, 2, 3};
	// int arr[] = {1, 2, 3};
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};

	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << maxSum_subArray(arr, n);
	cout << maxSum_subArray1(arr, n, 0, 0, 0);
}

void solve_max_sum()
{
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int mx = arr[0];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + arr[i];
		mx = max(mx, sum);
		if (sum < 0)
			sum = 0;
	}

	cout << sum << endl;
}

//  alterante subarray of even and odd
void solve_alternat_even_add()
{
	// int arr[] = {10, 12, 14, 7, 8};
	int arr[] = {10, 12, 7, 8, 8, 7, 8, 5};
	// int arr[] = {7, 10, 13, 14};
	int n = sizeof(arr) / sizeof(arr[0]);

	// int res = 0;

	// brutforce approach------------------ O(n^2)
	// for (int i = 0; i < n ; i++) {
	// 	int curr = 1;
	// 	for (int j = i + 1; j < n ; j++) {
	// 		if ((arr[j] % 2 == 0 && arr[j -1] % 2 != 0 ) ||
	// 		        (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0)
	// 		   ) curr++;
	// 		else break;
	// 	}
	// 	res = max(res, curr);
	// }

	// optimal approach+++++++++++++++++O(n);

	int res = 1;
	int curr = 1;
	for (int i = 1; i < n; i++)
	{
		if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) ||
			(arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
		{
			curr++;
			res = max(res, curr);
		}
		else
			curr = 1;
	}
	cout << res << endl;
}

///////////////////////////////////////////////
// maximum sum of circular subArray
// 111111111111111111111111 Time Complexity O(n^2);
int max_circular_subArray_sum(int arr[], int n)
{
	int res = arr[0];

	for (int i = 0; i < n; i++)
	{
		int curr_sum = arr[i];
		int curr_max = arr[i];
		for (int j = 1; j < n; j++)
		{
			int index = (i + j) % n;
			curr_sum += arr[index];
			curr_max = max(curr_max, curr_sum);
		}
		res = max(res, curr_max);
	}

	return res;
}

// 2222222222222222222222222222222   cadenza alogirithem ( maximum sum of normal subArray is obtained by cadenza algorithem)
int cadenza_algo(int arr[], int n)
{

	/* if all the element in the array are -ve than peak max value from the array */
	int mx = *max_element(arr, arr + n);
	if (mx < 0)
		return mx;

	int arr_sum = 0; // original array sum
	int kd_sum = 0;
	int kd_mx_sum = 0;

	for (int i = 0; i < n; i++)
	{
		arr_sum += arr[i];

		kd_sum += arr[i];
		kd_mx_sum = max(kd_mx_sum, kd_sum);
		if (kd_sum < 0)
			kd_sum = 0;
	}

	int cir_sum = 0;	// inverted sum of subArray
	int cir_mx_sum = 0; // max sum of inverted subArray array

	for (int i = 0; i < n; i++)
	{

		cir_sum += (-1 * arr[i]);
		cir_mx_sum = max(cir_mx_sum, cir_sum);
		if (cir_sum < 0)
			cir_sum = 0;
	}
	int circular_sum = arr_sum - (-1 * cir_mx_sum);
	int res = max(kd_mx_sum, circular_sum);
	return res;
}
void solve_circular()
{
	// int arr[] = { 2, 1, -5, 4, -3, 1, -3, 4, -1};
	// int arr[] = { 10, 5, -5};
	int arr[] = {-2, -3, -4};
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << max_circular_subArray_sum(arr, n ) << endl;
	// this cadenza_algo is efficient method to count the sum of circular subarray
	cout << cadenza_algo(arr, n) << endl;
}

/////////////////////////////////////////////////
// majority of element (element that is apper more than half of size of array(n)) than return index of that element
// brutforce mehtod to count majority of element------------
void majority_element1(int arr[], int n)
{
	int flag = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = i + 1; j < n; j++)
			if (arr[i] == arr[j])
				cnt++;
		if (cnt > n / 2)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 0)
		cout << -1;
	for (int j = 0; j < n; j++)
		if (arr[i] == arr[j])
			cout << j << " ";
}
void majority_element(int arr[], int n)
{
	//  8 1 3 8 8
	int mx = INT_MIN;
	for (int i = 0; i < n; i++)
		mx = max(mx, arr[i]);

	int freq[mx + 1] = {0};

	for (int i = 0; i < n; i++)
		freq[arr[i]]++;

	int mx_ele = INT_MIN;
	int mx_index = 0;
	for (int i = 0; i < mx + 1; i++)
		if (mx_ele < freq[i])
		{
			mx_ele = freq[i];
			mx_index = i;
		}

	if (arr[mx_index] > n / 2)
	{
		for (int i = 0; i < n; i++)
			if (mx_index == arr[i])
				cout << i << " ";
	}
	else
	{
		cout << -1 << nl;
		return;
	}
}

// using more's algo
void majority_element_more(int arr[], int n)
{
	int res = 0, count = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[res] == arr[i])
			count++;
		else
			count--;

		if (count == 0)
		{
			res = i;
			count = 1;
		}
	}

	count = 0;

	for (int i = 0; i < n; i++)
		if (arr[res] == arr[i])
			count++;

	if (count > n / 2)
	{
		for (int i = 0; i < n; i++)
			if (arr[res] == arr[i])
				cout << i << " ";
	}
	else
		cout << -1 << endl;
}

void solve_majority_element()
{
	int arr[] = {8, 1, 8, 3, 8, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	// majority_element1(arr, n);
	// cout << nl;
	// majority_element(arr, n);
	// cout << nl;
	majority_element_more(arr, n);
}

//////////////////////////////
// Minimum Consecutive Flips
/* Given a binary array, we need to find the minimum of number of
 group flips to make all array elements same.  In a group flip,
 we can flip any set of consecutive 1s or 0s.*/

void minimum_consecutive_flip(int arr[], int n)
{
	// group of 1
	int group_1 = 0;
	int flag = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			flag = 0;
		else
		{
			if (flag == 0)
			{
				group_1++;
				flag = 1;
			}
		}
	}

	// group of 0
	flag = 0;
	int group_0 = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 1)
			flag = 0;
		else
		{
			if (flag == 0)
			{
				group_0++;
				flag = 1;
			}
		}
	}

	int mx = group_1 < group_0 ? 1 : 0;
	if (mx)
		cout << "group of " << 1 << " is minmum times apper" << endl;
	else
		cout << "group of " << 0 << " is minimum times appers" << endl;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == mx)
			arr[i] = !arr[i];
		cout << arr[i] << " ";
	}
}
// only print frm i to j like this one who has minimum number of group
void minimum_consecutive_flip1(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			if (arr[i] != arr[0])
				cout << " from " << i << " to ";
			else
				cout << (i - 1) << endl;
		}
	}

	if (arr[n - 1] != arr[0])
		cout << (n - 1) << endl;
}

void solve_minmum_consicutive_flip()
{
	int arr[] = {1, 0, 0, 1, 1, 0, 0, 1};
	// int arr[] = {1, 0};

	int n = sizeof(arr) / sizeof(arr[0]);
	// minimum_consecutive_flip(arr, n);
	minimum_consecutive_flip1(arr, n);
}

// given arr
// 	int arr[] = {7, 1, 2, 30, 10}; // sum of any element is 17
//  find array whose sum is 17

int main()
{
	// int arr[5] = {1, 3, 4};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// int cap = 3;
	// int x = 2;
	// int pos = 3;
	// cout << insert_ele(arr, n ,x, cap, pos);

	// delete element
	// int arr[5] = { 1, 2, 3 , 4, 5};
	// int ele = 3;
	// int n = sizeof(arr) / sizeof(arr[0]);
	// if (delete_ele(arr, n , ele)) for (int i = 0; i < n ; i++) cout << arr[i] << " ";
	// else cout << ele << " is not present in the array " << nl;

	// max element
	// int arr[6] = {1, 2, 3, 4, 5, 5};
	// cout << max_element(arr, 5);
	// cout << mx_2(arr,  6);
	// cout << second_largest(arr, 6);

	// solve_sorted_or_not();

	// reverse array
	// solve_reverse();
	// solve_iterative_reverse();

	// remove duplicate in the array
	// solved_remove_duplicate();

	// settle all the zeros at the last of the array without dustrubing the array arrangment
	// solve_at_last();

	//  left rotate array
	// solve_left_rotate();

	//  left roate mutiple times on the basis of times value
	// solve_left_rotate_times();
	//  optimal way to rotate mutiple times on the basis of times value
	// solve_left_rotate_times_1();

	// best optimal solution on the basis of space and times complexity;
	// O(n), O(1)(space complexity)
	// time complexity
	// O(d + n - d + n) ==> O(2n) => O(n) ==>  complexity
	// solve_optimal_spce_times();

	// find leader element of array from given array;
	// solve_leader();
	// solve_leadder1(); // optimal way to solve

	// max diff of 2 element in the array
	// solve_diff();
	// solve_diff_optimal(); // optimal solution for this diffrence problem

	// count the freq of sorted array element
	// solve_freq();

	// count freq of element in the unsorted array
	// solve_freq_unsorted();

	// sell stock
	// solve_stock();

	//  max water store poblem-----
	// solve_max_water();
	// solve_max_water1(); // optimize approach to solve max water problem

	// calcuate consecutive binary-----------------
	// solve_max_one() ;

	// max sum of subarray
	// solve_maxSum_subArray();
	// solve_max_sum();

	// odd and even subarray
	// solve_alternat_even_add();

	// max circular subArray sum
	// solve_circular();

	// majority element in the array return any index of that element
	// solve_majority_element();

	// solve_minmum_consicutive_flip;
	// solve_minmum_consicutive_flip();
	solve_max_sum();
}