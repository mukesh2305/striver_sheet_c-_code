#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////
//  Traping rain water problem
// 1st approach => Time Complexity O(n^2)
int trapping_rain_water(int arr[], int n) {
	int res = 0;
	for (int i = 1; i < n ; i++) {
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

// 2nd approach => Time Complexity O(n) => space complexity => O(n)

int trapping_rain_water1(int arr[], int n) {
	int left[n];
	int right[n];
	int res = 0;

	left[0] = arr[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], arr[i]);

	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], arr[i]);

	for (int i = 0; i < n; i++)
		res = res + max(0, min(left[i], right[i]) - arr[i]); // if value is negative than we use max
	return res;
}

// 3rd approach => Time complexity O(n)
int trapping_rain_water2(int arr[], int n) {
	int left = 0, right = 0;
	int i = 0, j = n - 1;
	int res = 0;

	while (i < j) {
		left = max(left, arr[i]);
		right = max(right, arr[j]);

		if (left < right) {
			res += (left - arr[i]);
			i++;
		} else {
			res += (right - arr[j]);
			j--;
		}
	}
	return res;
}


void solve_trapping_rain_water() {
	int arr[] = {3, 0, 0, 2, 0, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << trapping_rain_water(arr, n);
	// cout << trapping_rain_water1(arr, n);
	cout << trapping_rain_water2(arr, n);
}

/////////////////////////////////////////////////
//  modules
int modulo(int arr[], int n) {
	int res = 0;
	for (int i = 0; i < n ; i++) {
		int mx = 0;
		for (int j = i + 1; j < n ; j++) {
			mx = max(mx,  abs(arr[i] - arr[j]) + abs(i - j));
		}
		res = max(res, mx);
	}
	return res;
}

int modulo1(int arr[], int n) {
	int A = INT_MIN;
	int B = INT_MAX;
	int C = INT_MIN;
	int D = INT_MAX;
	for (int i = 0; i < n ; i++) {
		//i > j
		A = max(A, arr[i] + i);
		B = min(B, arr[i] + i);

		// j > i
		C = max(C, arr[i] - i);
		D = min(D, arr[i] - i);

	}
	int res = max(A - B, C - D);
	return res;
}

int whiteBox1(int s1,  int arr[], int n) {
	int mx = INT_MIN, mn = INT_MAX;

	for (int i = 0; i < n; i++) {
		mx = max(mx, s1 *arr[i] + i);
		mn = min(mn, s1 * arr[i] + i);
	}
	return mx - mn;
}
int modulo2(int arr[], int n) {
	int res = 0;
	res = max(res, whiteBox1(1,  arr, n));
	res = max(res, whiteBox1(-1,  arr, n));
	return res;
}


void solve_module() {
	int arr[] = {1, 15, 13, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << modulo(arr, n);
	// cout << modulo1(arr, n);
	cout << modulo2(arr, n);
}


/////////////////////////////////////////////////////////////////////
// sprial problem
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> sol(n , vector<int>(n));
	int a = 0, b = n;
	int cnt = 1;

	while (a < b) {
		int i = a, j = a;

		while (j < b)
			sol[i][j++] = cnt++;

		j--, i++;

		while (i < b)
			sol[i++][j] = cnt++;

		i--, j--;

		while (j >= a)
			sol[i][j--] = cnt++;

		j++, i--;
		while (i > a)
			sol[i--][j] = cnt++; 
		a++, b--;
	}

	return sol;

}

// 2nd approach
vector<vector<int>> generateMatrix1(int n) {
	int cnt = 1, l = 0, r = n - 1, t = 0, b = n - 1;
	vector<vector<int>> sol(n, vector<int>(n));

	while (l <= r && t <= b) {
		for (int i = l ; i <= r ; i++) // left to right
			sol[t][i] = cnt++;
		t++;

		for (int i = t; i <= b; i++) // top to bottom
			sol[i][r] = cnt++;
		r--;

		for (int i = r; i >= l; i--) // right to left
			sol[b][i] = cnt++;
		b--;

		for (int i = b; i >= t; i--) // bottom to top
			sol[i][l] = cnt++;
		l++;
	}
	return sol;
}

void solve_generateMatrix() {
	int n = 3;
	// vector<vector<int>> vec = generateMatrix(n);
	vector<vector<int>> vec = generateMatrix1(n);
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
}



////////////////////////////////////////////////////////////////////
// 164. Maximum Gap
int maximumGap(vector<int>& nums) {
	int res = INT_MIN;
	sort(nums.begin(), nums.end());
	for (int i = 1; i < (int)nums.size(); i++)
		res = max(res , abs(nums[i] - nums[i - 1]));
	return res;
}

void solve_maximumGap() {
	vector<int> nums = {3, 6, 9, 1};
	cout << maximumGap(nums);
}


/////////////////////////////////////////////////////////////////
// 1131. Maximum of Absolute Value Expression
int whiteBox(int s1, int s2, vector<int> &arr1, vector<int> &arr2) {
	int mx = INT_MIN, mn = INT_MAX;

	for (int i = 0; i < (int)arr1.size(); i++) {
		mx = max(mx, s1 * arr1[i] + s2 * arr2[i] + i);
		mn = min(mn, s1 * arr1[i] + s2 * arr2[i] + i);
	}

	return mx - mn;
}
int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
	int res = 0;
	res = max(res, whiteBox(1, 1, arr1, arr2));
	res = max(res, whiteBox(-1, -1, arr1, arr2));
	res = max(res, whiteBox(1, -1, arr1, arr2));
	res = max(res, whiteBox(-1, 1, arr1, arr2));
	return res;
}

void solve_maxAbsValExpr() {
	vector<int> arr1 = {1, 2, 3, 4};
	vector<int> arr2 = { -1, 4, 5, 6};
	cout << maxAbsValExpr(arr1, arr2);
}



////////////////////////////////////////////////////////////////////////////
// ASSIGMENT
// 53. Maximum Subarray
int maxSubArray(vector<int> &nums)
{
	int res = 0;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		int curr = 0;
		for (int j = i; j < (int)nums.size(); j++)
		{
			curr += nums[j];
			res = max(res, curr);
		}
	}

	return res;
}

int maxSubArray1(vector<int>& nums) {
	int mx = INT_MIN;
	int sum = 0;
	for (int i = 0; i < (int)nums.size(); i++) {
		sum += nums[i];
		mx = max(mx, sum);
		if (sum < 0) sum = 0;
	}
	return mx;
}

void solve_max_subArray() {
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubArray1(nums);
}


///////////////////////////////////////////////////////
// 73. Set Matrix Zeroes
void setZeroes(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	set<int> setI;
	set<int> setJ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			if (matrix[i][j] == 0) {
				setI.insert(i);
				setJ.insert(j);
			}
		}
	}

	// for(auto it : setI) cout << it << " it " << endl;
	// for(auto it1 : setJ) cout << it1 << " it1 " << endl;
	for (auto it : setI) {
		for (int i = 0; i < m; i++) { // m  for col when we it is row => so we have to fill whole row .
			matrix[it][i] = 0;
		}
	}
	for (auto it : setJ) {
		for (int j = 0; j < n; j++) { // n  for col we have to fill whole col => so we have to go below one by one row
			matrix[j][it] = 0;
		}
	}

}

void setZeroes1(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	vector<int>dummy_R(m, -1);
	vector<int>dummy_C(n, -1);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				dummy_R[i] = 0;
				dummy_C[j] = 0;
			}
		}
	}

	// for(int i = 0; i < m ; i++) cout << dummy_R[i] << " ";
	// cout << endl << endl ;

	// for(int i = 0; i < n ; i++) cout << dummy_C[i] << " ";
	// cout << endl << endl;


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dummy_R[i] == 0 || dummy_C[j] == 0)
				matrix[i][j] = 0;
		}
	}
}

void solve_setZeros() {
	// vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	vector<vector<int>> matrix = {{0, 1}};
	// setZeroes(matrix);
	setZeroes1(matrix);
	for (auto it : matrix) {
		for (auto it1 : it) cout << it1 << " ";
		cout << endl ;
	}
}

///////////////////////////////////////////////////////
// next permutaiton
void nextPermutation(vector<int>& nums) {
	int n = (int)nums.size();
	int pos = -1;
	// 1 3 5 4 2 => 1 4 5 3 2

	// 1 4 5 3 2 => 1 4 2 3 5
	for (int i = n - 2; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) {
			pos = i;
			break;
		}
	}

	if (pos == -1) {
		sort(nums.begin(), nums.end());
		return;
	}

	for (int i = n - 1; i >= 0; i--)
		if (nums[i] > nums[pos]) {
			swap(nums[i], nums[pos]);
			break;
		}

	sort(nums.begin() + pos + 1, nums.end()); // it reverse so it come is smallest order
}

void solve_nextPermutation() {
	vector<int> nums = {1, 2, 3};
	nextPermutation(nums);
	for (auto it : nums) cout << it << " ";
}



//////////////////////////////////////////////////
// longest sub array of non-negative numbers

int longestSubarray(int arr[], int n) {
	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < n ; i++) {
		if (arr[i] >= 0) {
			cnt++;
			mx = max(mx , cnt);
		} else {
			cnt = 0;
			mx = max(mx , cnt);
		}
	}

	return mx;
}
void solve_longestSubarray() {
	// int arr[] = {2, 3, 4, -1, -2, 1, 5, 6, 3};
	int arr[] = {1, 0, 4, 0, 1, -1, -1, 0, 0, 1, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << longestSubarray(arr, n);
}

//////////////////////////////////////////////////////
// 1572. Matrix Diagonal Sum
int diagonalSum(vector<vector<int>>& mat) {
	int p = 0, s = 0, ans = 0, n = mat.size();

	for (int i = 0; i < n; i++) {
		p += mat[i][i];
		s += mat[n - i - 1][i];
	}

	ans = p + s;
	if (n % 2 != 0) {
		ans -= mat[n / 2][n / 2];
	}

	return ans;
}



void solve_diagonalSum() {
	vector<vector<int>> mat = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	cout << diagonalSum(mat);
}
/////////////////////////////////////////////////
int  mostWordsFound(vector<string> &sentences) {
	int mx = 0;
	for (string str : sentences) {
		int cnt = 1;
		for (char it : str)
			if (it == ' ') cnt++;
		mx = max(mx, cnt);
	}
	return mx;
}

void solve() {
	vector<string> vec = {
		"alice and bob love leetcode", "i think so too", "this is great thanks very much"
	};
	cout << mostWordsFound(vec);
}
int main() {
	// solve_trapping_rain_water();
	// solve_module();
	// solve_generateMatrix();
	// solve_maximumGap();
	// solve_maxAbsValExpr();
	// solve_max_subArray();
	// solve_setZeros();
	// solve_nextPermutation();
	// solve_longestSubarray();
	// solve_diagonalSum();
	solve();
}