// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 5

/////////////////////////////////////////////////////
// Function to find maximum sum submatrix
// brutforce method O(n ^ 6)
void SubmatrixSum( vector<vector<int> > matrix) {
	int n = matrix.size();
	int sumSubmatrix = 0;

	for (int t = 0; t < n; t++) {
		for (int l = 0; l < n; l++) {
			for (int b = t; b < n; b++) {
				for (int r = l; r < n; r++) {
					for (int i = t; i <= b; i++) {
						for (int j = l; j <= r; j++) {
							sumSubmatrix += matrix[i][j];
						}
					}
				}
			}
		}
	}

	cout << sumSubmatrix;
}

// optimal solution O(n*m);
void SubmatrixSum1(vector<vector<int>> matrix) {
	int n = matrix.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Number of ways to choose
			//from  top-left elements
			int top_left = (i + 1) * (j + 1);

			//from bottom-right elements
			int bottom_right = (n - i) * (n - j);
			sum += (top_left * bottom_right * matrix[i][j]);  // matrix[i][j] => element value

		}
	}
	cout << sum << endl;
}
void solve_SubmatrixSum() {
	vector<vector<int> > matrix = {
		{ 1, 1 },
		{ 1, 1 },
	};

	// SubmatrixSum(matrix);
	SubmatrixSum1(matrix);
}

//////////////////////////////////////////////////////
void prefSumProcess(int mat[M][N], int aux[M][N]) {
	// Copy first row of mat[][] to aux[][]
	for (int i = 0; i < N; i++)
		aux[0][i] = mat[0][i];

	// Do column wise sum
	for (int i = 1; i < M; i++)
		for (int j = 0; j < N; j++)
			aux[i][j] = mat[i][j] + aux[i - 1][j];

	// Do row wise sum
	for (int i = 0; i < M ; i++)
		for (int j = 1; j < N; j++)
			aux[i][j] += aux[i][j - 1];
}

// A O(1) time function to compute sum of submatrix
// between (tli, tlj) and (rbi, rbj) using aux[][]
// which is built by the preprocess function

int sumQuery(int aux[M][N], int tli, int tlj, int rbi, int rbj) {
	// result is now sum of elements between (0, 0) and
	// (rbi, rbj)

	int res = aux[rbi][rbj];

	// remove elements btween (0, 0) and (tli - 1, rbj)
	if (tli > 0)
		res = res - aux[tli - 1][rbj];

	// Remove elements between (0, 0) and (rbi, tlj-1)
	if (tlj > 0)
		res = res - aux[rbi][tlj - 1];

	// Add aux[tli-1][tlj-1] as elements between (0, 0)
	// and (tli-1, tlj-1) are subtracted twice
	if (tli > 0 && tlj > 0)
		res = res + aux[tli - 1][tlj - 1];
	return res;
}

void solve_sumQuery() {
	int mat[M][N] = {{1, 2, 3, 4, 6},
		{5, 3, 8, 1, 2},
		{4, 6, 7, 5, 5},
		{2, 4, 8, 9, 4}
	};
	int aux[M][N];

	prefSumProcess(mat, aux);
	int tli = 2, tlj = 2, rbi = 3, rbj = 4;
	cout << "\nQuery1: " << sumQuery(aux, tli, tlj, rbi, rbj);

	tli = 0, tlj = 0, rbi = 1, rbj = 1;
	cout << "\nQuery2: " << sumQuery(aux, tli, tlj, rbi, rbj);

	tli = 1, tlj = 2, rbi = 3, rbj = 3;
	cout << "\nQuery3: " << sumQuery(aux, tli, tlj, rbi, rbj);
}



////////////////////////////////////////////////////
// serach in row and col wise sorted matrix
void search(vector<vector<int>> mat, int x, int R , int C)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (mat[i][j] == x)
			{
				cout << "Found at (" << i << ", " << j << ")";

				return;
			}
		}
	}

	cout << "Not Found";
}

void search1(vector<vector<int>> mat, int x, int R, int C)
{
	int i  = 0, j = C - 1;

	while (i < R && j >= 0)
	{
		if (mat[i][j] == x)
		{
			cout << "Found at (" << i << ", " << j << ")";

			return;
		}
		else if (mat[i][j] > x)
		{
			j--;
		}
		else
		{
			i++;
		}
	}

	cout << "Not Found";
}


void  solve_search()
{
	vector<vector<int>> arr = {{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 35, 45},
		{32, 33, 39, 50}
	};
	int x = 29;
	int R = arr.size();
	int C = arr[0].size();
	// search(arr, x, R , C);
	search1(arr, x, R , C);
}

////////////////////////////////////////////////////////////////
// 1582. Special Positions in a Binary Matrix
int numSpecial(vector<vector<int>> &mat) {
	int n = mat.size(), m = mat[0].size();
	int ans = 0;
	vector<int> row(n, 0), col(m , 0);

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			row[i] += mat[i][j];
			col[j] += mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
				ans++;
			}
		}
	}
	return ans;
}

void solve_numSpecial() {
	vector<vector<int>> mat = {
		{1, 0, 0},
		{0, 0, 1},
		{1, 0, 0}
	};
	cout << numSpecial(mat);

}

/////////////////////////////////////////////////////
// 2022. Convert 1D Array Into 2D Array
vector<vector<int>> construct2DArray(vector<int> &arr, int m , int n) {
	if (n * m != arr.size()) return {};
	vector<vector<int>> a(m, vector<int> (n));
	for (int i = 0; i < arr.size(); i++) {
		a[i / n][i % n] = arr[i];
	}
	return a;
}
void solve_construct2DArray() {
	vector<int> arr = {1, 2, 3, 4, 1, 2, 3, 4, 5, 1};
	int m = 2, n = 5;
	vector<vector<int>> vec = construct2DArray(arr, m , n);
	for (auto x : vec) {
		for (auto t : x) cout << t << " ";
		cout << endl;
	}
}

////////////////////////////////////////////////////
//  304. Range Sum Query 2D - Immutable
vector<vector<int>> sum;
void NumMatirx(vector<vector<int>> &matrix) {
// prefix sum of matrix
	int row = matrix.size();
	int col = matrix[0].size();
// Copy first row of mat[][] to aux[][]
	sum = move(vector<vector<int>> (row, vector<int> (col)));
	for (int i = 0; i < col; i++)
		sum[0][i] = matrix[0][i];

// col wise prfix sum
	for (int i = 1; i < row ; i++) {
		for (int j = 0; j < col; j++) {
			sum[i][j] = matrix[i][j] + sum[i - 1][j];
		}
	}

// row wise prefix sum
	for (int i = 0; i < row; i++) {
		for (int j = 1; j < col; j++) {
			sum[i][j] +=  sum[i][j - 1];
		}
	}
}
int sumRegion(int row1, int col1, int row2, int col2) {
	int total = sum[row2][col2];
	if (row1 > 0)
		total  = total - sum[row1 - 1][col2];
	if (col1 > 0)
		total = total - sum[row2][col1 - 1];
	if (row1 > 0 && col1 > 0) {
		total = total + sum[row1 - 1][col1 - 1];
	}
	return total;
}

void solve_sumRegion() {
	vector<vector<int>> matrix = {{1, 2, 3, 4, 6},
		{5, 3, 8, 1, 2},
		{4, 6, 7, 5, 5},
		{2, 4, 8, 9, 4}
	};

	NumMatirx(matrix);
	int row1 = 2, col1 = 2, row2 = 3, col2 = 4;
	cout << "\nQuery1: " << sumRegion( row1, col1, row2, col2);

	row1 = 0, col1 = 0, row2 = 1, col2 = 1;
	cout << "\nQuery2: " << sumRegion( row1, col1, row2, col2);

	row1 = 1, col1 = 2, row2 = 3, col2 = 3;
	cout << "\nQuery3: " << sumRegion( row1, col1, row2, col2);
}

/////////////////////////////////////////////////////////////
// 769. Max Chunks To Make Sorted // ref papcoding // (medium leetcode problem)
int maxChunksToSorted(vector<int>& arr) {
	int mx = INT_MIN, ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		mx = max(mx, arr[i]);
		if (mx == i) ans++;
	}
	return ans;
}
void solve_maxChunksToSorted() {
	// vector<int> arr = {4,3,2,1,0};
	vector<int> arr = {1, 0, 2, 3, 4};
	cout << maxChunksToSorted(arr);
}

////////////////////////////////////////////////////////////
// 768. Max Chunks To Make Sorted II (Hard problem in leetcode)
// ref papcoding(https://www.youtube.com/watch?v=GxTo3agdnjs)
int maxChunksToSorted1(vector<int>& arr) {
	// 1 : generate right min
	vector<int> rmin(arr.size() + 1);
	rmin[arr.size()] = INT_MAX; // max value in the c++
	for (int i = arr.size() - 1; i >= 0; i--) {
		rmin[i] = min(rmin[i + 1], arr[i]);
	}

	// iterate on array and manage left max as well as count chunks
	int lmax = INT_MIN;
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		lmax = max(lmax, arr[i]);
		if (lmax <= rmin[i + 1]) cnt++;
	}
	return cnt;
}

void solve_maxChunksToSorted1() {
	// vector<vector<int>> arr = {
	// 	{1,2,3},
	// 	{4,5,6},
	// 	{7,8,9}
	// };
	vector<int> arr = {5, 4, 3, 2, 1};
	cout << maxChunksToSorted1(arr);
}

//////////////////////////////////////////////////////
// 867. Transpose Matrix
vector<vector<int>> transpose(vector<vector<int>>& arr) {
	int row  = arr.size();
	int col = arr[0].size();
	vector<vector<int>> ans(col, vector<int> (row));
	for (int i = 0; i < row ; i++) {
		for (int j = 0; j < col ; j++) {
			ans[j][i] = arr[i][j];
		}
	}
	return ans;
}

void solve_transpose() {
	vector<vector<int>> arr = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	vector<vector<int>> ans = transpose(arr);
	for (auto a : ans) {
		for (auto x : a) cout << x << " ";
		cout << endl;
	}
}

////////////////////////////////////////////
// 1351. Count Negative Numbers in a Sorted Matrix
int countNegatives(vector<vector<int>>& grid) {
	int row = 0, col = grid[0].size() - 1, cnt = 0;
	while (row < grid.size() && col >= 0) {
		if (grid[row][col] < 0) {
			col--;
			cnt = cnt + grid.size() - row;
		} else row++;
	}

	return cnt;
}

int countNegatives1(vector<vector<int>>& grid) {

	int row = 0, col = grid[0].size() - 1, cnt = 0;
	while (row < grid.size() && col >= 0) {
		if (grid[row][col] < 0) {
			col--;
			cnt++;
			if (col < 0) {
				row++;
				col = grid[0].size() - 1;
			}
		} else {
			row++;
			col = grid[0].size() - 1;
		}
	}

	return cnt;
}
void solve_countNegatives() {
	// vector<vector<int>> grid = {
	// 	{4, 3, 2, -1},
	// 	{3, 2, 1, -1},
	// 	{1, 1, -1, -2},
	// 	{ -1, -1, -2, -3}
	// };
	vector<vector<int>> grid = {
		{3, 2},
		{ -3, -3},
		{ -3, -3},
		{ -3, -3}
	};
	// cout << countNegatives(grid);
	cout << countNegatives1(grid);
}

//////////////////////////////////////////////////////////
// 566. Reshape the Matrix
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
	int m = mat.size(), n = mat[0].size();
	if (m * n != r * c) return mat;

	vector<vector<int>> ans(r, vector<int> (c));
	for (int i = 0; i < m * n; i++) {
		ans[i / c][i % c] = mat[i / n][i % n];
	}
	return ans;
}

void solve_matrixReshape() {
	vector<vector<int>> mat = {
		{1, 2},
		{3, 4}
	};
	int  r = 1, c = 4;
	vector<vector<int>> ans = matrixReshape(mat, r, c);
	for (auto a : mat) {
		for (auto x : a) cout << x << " ";
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////
// Minimum swaps required to bring all elements less than or equal to k together
// will be arr[] = {2, 1, 3, 6, 5} k = 3
// miMinimum swaps and K together (Geeks for Geeks)

// Input:  arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5
int minSwap(int ar[], int n , int k) {
	int good = 0;
	for (int i = 0; i < n; i++)
		if (ar[i] <= k) ++good;

	int bad = 0;
	for (int i = 0; i < good; i++)
		if (ar[i] > k) ++bad;

	int ans = bad;
	int i = 0, j = good;
	while (j < n) {
		if (ar[i] > k)
			--bad;
		if (ar[j] > k)
			bad++;
		ans = min(ans, bad);
		i++, j++;
	}
	return ans;
}


int minSwap1(int ar[], int n , int k) {
	int good = 0;
	for (int i = 0; i < n; i++)
		if (ar[i] <= k) ++good;


	int ans = INT_MAX;
	int i = 0, j = 0;
	int bad = 0;
	while (j < n) {
		if (ar[j] > k) bad++;

		if (j - i + 1 == good) {
			ans = min(ans, bad);
			if (ar[i] > k) bad--;
			i++;
		}
		j++;
	}
	return ans == INT_MIN ? 0 : ans;
}


void solve_minSwap() {
	// int arr[ ] = {2, 1, 5, 6, 3};
	int arr[ ] = {2, 7, 9, 5, 8, 7, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 5;
	// cout << minSwap(arr, n , k);
	cout << minSwap1(arr, n , k);
}

//////////////////////////////////////////////////////////////
// Rearrange array in alternating positive & negative items with O(1) extra space | Set 1
// Input:  arr[] = {1, 2, 3, -4, -1, 4}
// Output: arr[] = {-4, 1, -1, 2, 3, 4}


// TC  => O(n) SC => O(n)
void rearrange(int arr[], int n) {
	vector<int> VP;
	vector<int> VN;

	for (int i = 0; i < n ; i++) {
		if (arr[i] > 0)
			VP.push_back(arr[i]);
		if (arr[i] < 0)
			VN.push_back(arr[i]);
	}

	int pn = VP.size();
	int nn = VN.size ();
	int k = 0;
	for (int i = 0; i < nn; i++) {
		arr[k] = VN[i];
		k += 2;
	}
	k -= 2;
	int p = k + 1;
	k = 1;
	for (int i = 0; i < pn; i++) {
		arr[k] = VP[i];
		if (k >= p) {
			k++;
		} else k += 2 ;
	}
}

// TC  => O(n) SC => O(1)
void rearrange1(int arr[], int n) {
	int l = 0, r = n - 1;
	while (l < r) {
		if ( arr[l] > 0) {
			l++;
		} else if ( arr[r] < 0) {
			r--;
		} else swap(arr[l], arr[r]);
	}

	if (l == 0 || l == n)
		return;
	int k = 0;
	while (l < n && k < n) {
		swap(arr[k], arr[l]);
		l += 1;
		k += 2;
	}
}

void solve_rearrange() {
	int arr[] = {1, -1, -1, 4, -1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	// rearrange(arr, n);
	rearrange1(arr, n);
	for (auto it : arr) cout << it << " ";
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

	for (int i = 2; i < mx; i++) {
		if (mx % i == 0 && mn % i == 0) {
			return i;
		}
	}
	return -1;
}
int solve_findGCD() {
	vector<int> nums = {2, 5, 6, 9, 10};
	cout << findGCD(nums);
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


int main()
{
	// solve_SubmatrixSum();
	// solve_sumQuery();
	// solve_sortedSubMatrixSum();
	// solve_search();
	// solve_numSpecial();
	// solve_construct2DArray();
	// solve_sumRegion();
	// solve_maxChunksToSorted();
	// solve_maxChunksToSorted1();
	// solve_transpose();
	// solve_countNegatives();
	// solve_matrixReshape();
	// solve_diagonalSum();
	// solve_minSwap();
	// solve_rearrange();
	// solve_findGCD();
}
