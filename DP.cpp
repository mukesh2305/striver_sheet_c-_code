#include <bits/stdc++.h>
#define ll long long
using namespace std;
/////////////////////////////////////////////////
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/////////////////////////////////////////////////////////////////////////
// DP 1. Introduction to Dynamic Programming | Memoization | Tabulation | Space Optimization Techniques

// Fibonaci Number
// 0 1 1 2 3 5 8 13 21 .....

// TC O(N)
// SC O(N) (this is stack space) + O(N) (to this for array)
// 1 => memorization formate
int fibo_dp(int n, vector<int> & dp) {
	if (n <= 1) return n;

	if (dp[n] != -1) return dp[n];

	return dp[n] = fibo_dp(n - 1, dp) + fibo_dp(n - 2, dp);
}

void solve_fibo_dp() {
	int n = 5;
	vector<int> dp(n + 1, -1);
	cout << fibo_dp(n , dp);
}

// 2 => using tabulation
// TC => O(N)
// SC => O(N)
int fibo_dp_tab(int n, vector<int> & dp) {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n ; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}

// 2 => optimized tablutaion
// TC => O(N)
// SC => O(1)
int fibo_dp_tab1(int n) {
//ind// 0 1 2 3 4 5
	// 0 1 1 2 3 5
	// eg : n = 2, prev1 = 1, prev2 = 0

	int prev2 = 0;
	int prev1 = 1;
	for (int i = 2 ; i <= n ; i++) {
		int ans = prev1 + prev2;
		prev2 = prev1;
		prev1 = ans;
	}
	return prev1;
}
void solve_fibo_dp_tab() {
	int n = 5;
	vector<int> dp(n + 1, -1);
	// cout << fibo_dp_tab(n , dp);
	cout << fibo_dp_tab1(n);
}


/////////////////////////////////////////////////////////////////////////////////
// DP 2. Climbing Stairs | Learn How to Write 1D Recurrence Relations
// this fibonaci
long long mod = 1000000007;
int helper(int n, vector<int> & dp) {
	if (n <= 1) return 1;

	if (dp[n] != -1) return dp[n];

	return dp[n] = (helper(n - 1, dp) + helper(n - 2, dp)) % mod;
}
int countDistinctWays(int nStairs) {
	int n = nStairs;
	vector<int> dp(n + 1, -1);
	return helper(n , dp);
}

void solve_countDistinctWays() {
	int nStairs = 3;
	cout << countDistinctWays(nStairs);
}

/////////////////////////////////////////////////////////////////////////
// DP 3. Frog Jump | Dynamic Programming | Learn to write 1D DP

// memorization approach
// TC O(N)
// SC O(N) + O(N)
int frog_f(int ind, vector<int> & heights, vector<int> & dp) {
	if (ind == 0) return 0;
	if (dp[ind] != -1) return dp[ind];

	int left = frog_f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
	int right = INT_MAX; // 1 2 3 4 5
	if (ind > 1) {
		right = frog_f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
	}

	return dp[ind] = min(left , right);
}
int frogJump(int n, vector<int> &heights) {
	vector<int> dp(n + 1, -1);
	// n - 1 is the last index of array
	return frog_f(n - 1, heights, dp);
}

// tabulation approach
// TC O(N)
// SC O(N)
int frogJump_tabulation(int n, vector<int> & heights) {
	vector<int> dp(n + 1, -1);
	dp[0] = 0;
	for (int ind = 1; ind < n; ind++) {
		int FS = dp[ind - 1] + abs(heights[ind] - heights[ind - 1]);
		int SS = INT_MAX;
		if (ind > 1)
			SS = dp[ind - 2] + abs(heights[ind] - heights[ind - 2]);
		dp[ind] = min(FS, SS);
	}

	return dp[n - 1];
}

void solve_forgJump() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n ;
		vector<int> heights;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			heights.push_back(val);
		}
		// cout << frogJump(n , heights) << endl;
		cout << frogJump_tabulation(n , heights) << endl;
	}
}

///////////////////////////////////////////////////////////////////
// DP 4. Frog Jump with K Distance | Lecture 3 Follow Up Question
// TC O(N * K)
// SC O(N) + O(N)
// memorization approach
int frog_f_2(int ind, int k, vector<int> & heights, vector<int> & dp) {
	if (ind == 0) return 0;
	if (dp[ind] != -1) return dp[ind];

	int minSteps = INT_MAX;
	for (int j = 1; j <= k; j++) {
		if (ind - j >= 0) {
			int jump = frog_f_2(ind - j, k, heights, dp) + abs(heights[ind] - heights[ind - j]);
			minSteps = min(minSteps, jump);
		}
	}
	return dp[ind] = minSteps;
}


int frogJump_2(int n, int k , vector<int> & heights) {
	vector<int> dp(n + 1, -1);
	return frog_f_2(n - 1, k, heights, dp);
}

// tabulation approach
// TC O(N * K)
// SC O(N)
int frogJump_2_tabulation(int n, int k, vector<int> & heights) {
	vector<int> dp(n + 1, -1);
	dp[0] = 0;

	for (int ind = 1; ind < n; ind++) {

		int minSteps = INT_MAX;

		for (int j = 1; j <= k; j++) {

			if (ind - j >= 0) {
				int jump = dp[ind - j] + abs(heights[ind] - heights[ind - j]);
				// cout << jump << " ";
				minSteps = min(minSteps, jump);
			}
		}
		// cout << " min " << minSteps << endl;
		dp[ind] = minSteps;
	}
	return dp[n - 1];
}
void solve_forgJump_2() {
	int n, k;
	cin >> n >> k;
	vector<int> heights;
	for (int i = 0; i < n ; i++) {
		int val;
		cin >> val;
		heights.push_back(val);
	}
	// cout << frogJump_2(n , k , heights);
	cout << frogJump_2_tabulation(n , k , heights);
}

//////////////////////////////////////////////////////////////////////////////////////
// DP 5. Maximum Sum of Non-Adjacent Elements | House Robber | 1-D | DP on Subsequences
// TC O(N)
// SC O(N) + O(N)
// memorization approach
int f_max_memo(int ind , vector<int> & nums, vector<int> & dp) {
	if (ind == 0) return nums[ind];
	if (ind < 0) return 0;

	if (dp[ind] != -1) return dp[ind];

	int pick = nums[ind] + f_max_memo(ind - 2, nums, dp); // we are not picking adjcent indx that's why ind - 2
	int notPick = 0 + f_max_memo(ind - 1, nums, dp);

	return dp[ind] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums) {
	int n = nums.size();
	vector<int> dp(n + 1, -1);
	return f_max_memo(n - 1, nums, dp);
}

// TC O(N)
// SC O(N)
// tabulation approach
int f_max_tab(int n , vector<int> & nums, vector<int> & dp) {
	dp[0] = nums[0];

	for (int ind = 1; ind < n; ind++) {
		// int pick = nums[ind] + dp[ind - 2];

		int pick = nums[ind] ;
		if (ind > 1)
			pick += dp[ind - 2]; // to handle -ve handle;

		int notPick = 0 + dp[ind - 1];

		dp[ind] = max(pick, notPick);
	}

	return dp[n - 1];
}
int maximumNonAdjacentSum_tabulation(vector<int> & nums) {
	int n = nums.size();
	vector<int> dp(n + 1, -1);
	return f_max_tab(n, nums, dp);
}
void solve_maximumNonAdjacentSum() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n ;
		vector<int> nums;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			nums.push_back(val);
		}
		cout << maximumNonAdjacentSum(nums) << endl;
		// cout << maximumNonAdjacentSum_tabulation(nums) << endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
// DP 6. House Robber 2 | 1D DP | DP on Subsequences
// this problem is same as above problem
// TC O(N)
// SC O(N) + O(N)
// memorization approac
long long int f_rob_memo(int ind, vector<int> & nums, vector<int> & dp) {
	if (ind == 0) return nums[ind];
	if (ind < 0) return 0;
	if (dp[ind] != -1) return dp[ind];
	long long int pick = nums[ind] + f_rob_memo(ind - 2 , nums, dp);
	int long long notPick = 0 + f_rob_memo(ind - 1, nums, dp);
	return dp[ind] = max(pick, notPick);
}
int houseRobber(vector<int>& nums) {
	int n = nums.size();
	if (n == 1) return nums[0];
	vector<int> temp1, temp2;

	for (int i = 0; i < n ; i++) {
		if (i != 0) temp1.push_back(nums[i]);
		if (i != n - 1) temp2.push_back(nums[i]);
	}

	vector<int> dp((int)temp1.size(), -1);

	long long int ans1 = f_rob_memo((int)temp1.size() - 1, temp1, dp);
	for (int i = 0; i < (int)temp1.size(); i++) dp[i] = -1;
	long long int ans2 = f_rob_memo((int)temp2.size() - 1, temp2, dp);
	return max(ans1, ans2);
}

// we can also do tabulation
// if we have time than
// optimized space approach
long long int f_rob_optimize(vector<int> & nums) {
	int n = nums.size();
	long long int prev1 = nums[0];
	long long int prev2 = 0;

	for (int ind = 1; ind < n ; ind++) {
		long long int pick = nums[ind];
		if (ind > 1) pick += prev2;
		int long long  notPick = 0 + prev1;

		long long int curi = max(pick, notPick);
		prev2 = prev1;
		prev1 = curi;
	}
	return prev1;
}
long long int houseRobber_optimized(vector<int> & nums) {
	int n = nums.size();
	vector<int> temp1, temp2;
	if (n == 1) return nums[0];

	for (int i = 0; i < n ; i++) {
		if (i != 0)  temp1.push_back(nums[i]);
		if (i != n - 1)  temp2.push_back(nums[i]);
	}

	long long int ans1 = f_rob_optimize(temp1);
	long long int ans2 = f_rob_optimize(temp2);
	return max(ans1, ans2);
}
void solve_houseRobber() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n ;
		vector<int> valueInHouse;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			valueInHouse.push_back(val);
		}
		// cout << houseRobber(valueInHouse) << endl;
		cout << houseRobber_optimized(valueInHouse) << endl;
	}
}

/////////////////////////////////////////////////////////////////////////////
// DP 7. Ninja's Training | MUST WATCH for 2D CONCEPTS 🔥 | Vacation | Atcoder | 2D DP
// memorization approach
// TC O(N * 4) * 3
// TC O(N) + O(N * 4)
int f_nin_memo(int day, int last, vector<vector<int>> & points, vector<vector<int>> & dp) {


	if (day == 0) {
		int maxi = 0;
		for (int task = 0; task <= 2; task++) {
			if (task != last) {
				maxi = max(maxi, points[0][task]);
			}
		}
		return dp[day][last] = maxi;
	}

	if (dp[day][last] != -1) return dp[day][last];

	int maxi = 0;
	for (int task = 0; task <= 2; task ++) {
		if (task != last) {
			int activity = points[day][task] + f_nin_memo(day - 1, task, points, dp);
			maxi = max(maxi, activity);
		}
	}

	return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> & points) {
	vector<vector<int>> dp(n, vector<int> (4, -1));
	return f_nin_memo(n - 1, 3, points, dp);
}

// tabulation approach
// TC O(N * 4) * 3
// TC O(N * 4)

int ninjaTraining_tabulation(int n, vector<vector<int>> & points) {
	vector<vector<int>> dp(n , vector<int> (4 , -1));

	dp[0][0] = max(points[0][1], points[0][2]);
	dp[0][1] = max(points[0][0], points[0][2]);
	dp[0][2] = max(points[0][0], points[0][1]);
	dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

	for (int day  = 1; day < n; day++) {
		for (int last = 0; last < 4; last++) {
			// dp[day][last] = 0;
			int maxi = 0;
			for (int task = 0; task <= 2 ; task++) {
				if (task != last) {
					int activity = points[day][task] + dp[day - 1][task];
					// dp[day][last] = max(dp[day][last], activity);
					maxi = max(maxi, activity);
				}
			}
			dp[day][last] = maxi;
		}
	}
	return dp[n - 1][3];
}


void solve_ninjaTraining() {
	// N * 3 matrix is given
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n ;
		vector<vector<int>> points;
		for (int i = 0; i < n; i++) {
			vector<int> temp;
			for (int j = 0; j < 3; j++) {
				int val;
				cin >> val;
				temp.push_back(val);
			}
			points.push_back(temp);
		}
		// cout << ninjaTraining(n , points) << endl;
		cout << ninjaTraining_tabulation(n , points) << endl;
	}
}

////////////////////////////////////////////////////////////////////////////
// DP 8. Grid Unique Paths | Learn Everything about DP on Grids | ALL TECHNIQUES 🔥
// TC O(m * n)
// SC  O((n - 1) + (m - 1)) + O(n * m)
int f_uni(int i, int j, vector<vector<int>> & dp) {
	if (i == 0 && j == 0) return 1;
	if (i < 0 || j < 0) return 0;

	if (dp[i][j] != -1) return dp[i][j];
	int up = f_uni(i - 1, j, dp);
	int left = f_uni(i, j - 1, dp);
	return dp[i][j] = up + left;

}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m , vector<int> (n , -1));
	return f_uni(m - 1, n - 1, dp);
}

// tabulation approach
// TC O(m * n)
// SC O(n * m)
int f_uni_tab(int m, int n, vector<vector<int>> & dp) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) dp[0][0] = 1;
			else {
				int up = 0, left = 0;
				if (i > 0)
					up = dp[i - 1][j];
				if (j > 0)
					left = dp[i][j - 1];
				dp[i][j] = up + left ;
			}
		}
	}

	return dp[m  - 1][n - 1];
}
int uniquePaths_tabulation(int m, int n) {
	vector<vector<int>> dp(m , vector<int> (n , -1));
	return f_uni_tab(m, n, dp);
}


void solve_uniquePaths() {
	// N * 3 matrix is given
	int t;
	cin >> t;

	while (t--) {
		int m , n ;
		cin >> m >> n;
		// cout << uniquePaths(m , n) << endl;
		cout << uniquePaths_tabulation(m , n) << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// DP 9. Unique Paths 2 | DP on Grid with Maze Obstacles
// 63. Unique Paths II
int f_uni_obs(int i, int j, vector<vector<int>> & mat, vector<vector<int>> & dp) {
	// if(i>= 0 && j>= 0 && maze[i][j]==-1) return 0;

	if (i == 0 && j == 0 && mat[i][j] != -1) return 1;
	if (i < 0 || j < 0  || mat[i][j] == -1) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int up = f_uni_obs(i - 1, j, mat, dp);
	int left = f_uni_obs(i, j - 1, mat, dp);

	return dp[i][j] = up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &mat) {
	int m = mat.size();
	int n = mat[0].size();
	vector<vector<int>> dp(m , vector<int> (n , -1));
	return f_uni_obs(m - 1, n - 1, mat, dp);
}

//tabulation_approach
int uniquePathsWithObstacles_tabulation(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();
	vector<vector<int>> dp(m , vector<int> (n , -1));
	// return f(m - 1, n - 1, obstacleGrid, dp);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n ; j++) {
			if ( i == 0 && j == 0 && mat[i][j] != -1) dp[i][j] = 1;
			else {
				int up = 0, left = 0;
				if (i > 0 && mat[i][j] != -1)
					up = dp[i - 1][j];
				if (j > 0 && mat[i][j] != -1)
					left = dp[i][j - 1];
				dp[i][j] = up + left ;
			}
		}
	}
	return dp[m - 1][n - 1];
}

void solve_uniquePathsWithObstacles() {
	vector<vector<int>> mat = {
		{0, 0, 0},
		{0, -1, 0},
		{0, 0, 0}
	};
	cout << uniquePathsWithObstacles(mat);
	// cout << uniquePathsWithObstacles_tabulation(mat);
}

////////////////////////////////////////////////////////////
// DP 10. Minimum Path Sum in Grid | Asked to me In Microsoft Internship Interview | DP on GRIDS

// TC O(N * M)
// SC O(N * M) + O(path length) => and path length = (m - 1) + (n - 1)
int f_min_memo(int i, int j , vector<vector<int>> & grid, vector<vector<int>> & dp) {
	if (i == 0 && j == 0) return grid[0][0];
	if (i < 0 || j < 0) return 1e9;

	if (dp[i][j] != -1) return dp[i][j];

	int up = grid[i][j] + f_min_memo(i - 1, j, grid, dp);
	int left = grid[i][j] + f_min_memo(i, j - 1, grid, dp);

	return dp[i][j] = min(up, left);
}
int minSumPath(int m , int n, vector<vector<int>> &grid) {
	vector<vector<int>> dp(m , vector<int> (n , -1));
	return f_min_memo(m - 1, n - 1, grid, dp);
}


// tabulation approach
// TC O(N * M)
// SC O(N * M)
int f_min_tab(int m, int n , vector<vector<int>> & grid, vector<vector<int>> & dp) {
	for (int i = 0; i < m ; i++) {
		for (int j = 0; j < n ; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = grid[0][0];
			}
			else {
				int up = 1e9, left = 1e9;
				if (i > 0)
					up = grid[i][j] + dp[i - 1][j];
				if (j > 0)
					left = grid[i][j] + dp[i][j - 1];
				dp[i][j] = min(up, left);
			}
		}
	}

	return dp[m - 1][n - 1];
}
int minSumPath_tabulation(int m , int n, vector<vector<int>> &grid) {
	vector<vector<int>> dp(m , vector<int> (n , -1));
	return f_min_tab(m, n, grid, dp);
}

void solve_minSumPath() {

	vector<vector<int>> grid = {
		{5, 9, 6},
		{11, 5, 2}
	};

	int m = grid.size();
	int n = grid[0].size();
	// cout << minSumPath(m , n , grid);
	cout << minSumPath_tabulation(m , n , grid);
}


///////////////////////////////////////////////////////////////////////////////////
// DP 11. Triangle | Fixed Starting Point and Variable Ending Point | DP on GRIDS
// this problem is related
// fix starting point ---> and variable(not fixed) ending point
// memorization approach
// TC O(N)
// SC O(N * N) + O(N) => (this is recursion stack space)
int f_mpath_memo(int i, int j, int n, vector<vector<int>> & triangle, vector<vector<int>> & dp) {
	if (i == n - 1) return triangle[i][j];

	if (dp[i][j] != -1) return dp[i][j];

	int down = triangle[i][j] + f_mpath_memo(i + 1, j, n , triangle, dp);
	int diagonal = triangle[i][j] + f_mpath_memo(i + 1, j + 1, n , triangle, dp);

	return dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n) {
	// in this problem we are starting from top (i, j) = (0, 0)
	vector<vector<int>> dp(n , vector<int> (n , -1));
	return f_mpath_memo(0, 0, n, triangle, dp);
}


// tabulation approach
// TC O(N)
// SC O(N * N)
int f_mpath_tab(int n, vector<vector<int>> & triangle, vector<vector<int>> & dp) {
	for (int j = 0; j < n ; j++) {
		dp[n - 1][j] = triangle[n - 1][j];
	}

	for (int i = n - 2; i >= 0; i--) {
		// cout << i <<  " => ";
		for (int j = i; j >= 0; j--) {
			// cout << j << " ";
			int down = triangle[i][j] + dp[i + 1][j];
			int diagonal = triangle[i][j] + dp[i + 1][j + 1];

			dp[i][j] = min(down, diagonal);
		}
		// cout << endl;
	}

	return dp[0][0];
}
int minimumPathSum_tabulation(vector<vector<int>>& triangle, int n) {
	// in this problem we are starting from top (i, j) = (0, 0)
	vector<vector<int>> dp(n , vector<int> (n , -1));
	return f_mpath_tab(n, triangle, dp);
}
void solve_minimumPathSum() {
	vector<vector<int> > triangle = {
		{1},
		{2, 3},
		{3, 6, 7},
		{8, 9, 6, 10}
	};

	int n = triangle.size();

	// cout << minimumPathSum(triangle, n);
	cout << minimumPathSum_tabulation(triangle, n);
}

////////////////////////////////////////////////////////////////////////
// DP 12. Minimum/Maximum Falling Path Sum | Variable Starting and Ending Points | DP on Grids
// this problem is related
// variable starting point ---> and variable(not fixed) ending point
// TC O(N * M)
// SC O(N * M) + O(N)
int getMaxiUtil(int i, int j, int m, vector<vector<int>> & mat, vector<vector<int>> & dp) {
	if (j < 0 || j >= m) return -1e9;
	if (i == 0) return mat[0][j];

	if (dp[i][j] != -1) return dp[i][j];

	int up = mat[i][j] + getMaxiUtil(i - 1, j, m , mat, dp);
	int leftDigonal = mat[i][j] + getMaxiUtil(i - 1, j - 1, m , mat, dp);
	int rightDigonal = mat[i][j] + getMaxiUtil(i - 1, j + 1, m , mat, dp);

	return dp[i][j] = max(up, max(leftDigonal, rightDigonal));
}
int getMaxPathSum(vector<vector<int>> & mat) {
	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dp(m , vector<int> (n, -1));

	int maxi = INT_MIN;

	for (int j = 0; j < n ; j++) {
		int ans = getMaxiUtil(m - 1, j, n, mat, dp);
		maxi = max(maxi, ans);
	}

	return maxi;
}


// tabulation approach
// TC O(N * M)
// SC O(N * M)
int getMaxPathSum_tabulation(vector<vector<int>> & mat) {
	int m = mat.size();
	int n = mat[0].size();
	vector<vector<int>> dp(m , vector<int> (n, -1));

	// Initializing first row - base condition
	for (int j = 0; j < n; j++) {
		dp[0][j] = mat[0][j];
	}

	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int up = mat[i][j] + dp[i - 1][j];

			int leftDigonal = mat[i][j];
			if (j - 1 >= 0) leftDigonal += dp[i - 1][j - 1];
			else leftDigonal += -1e9;

			int rightDigonal = mat[i][j];
			if (j + 1 < n) rightDigonal += dp[i - 1][j + 1];
			else rightDigonal += -1e9;

			dp[i][j] = max(up, max(leftDigonal, rightDigonal));
		}
	}

	int maxi = INT_MIN;
	for (int j = 0; j < n; j++) {
		maxi = max(maxi, dp[m - 1][j]);
	}

	return maxi;
}
void solve_getMaxPathSum() {
	vector<vector<int> > mat = {
		{1, 2, 10, 4},
		{100, 3, 2, 1},
		{1, 1, 20, 2},
		{1, 2, 2, 1}
	};

	// cout << getMaxPathSum(mat);
	cout << getMaxPathSum_tabulation(mat);
}

/////////////////////////////////////////////////////////////////////////////////
// DP 13. Cherry Pickup II | 3D DP Made Easy | DP On Grids
// fixed starting point , variable ending point

// TC O(N * M * M)
// SC O(N * M * M) + O(N)
int maxChocoUtil(int i , int j1, int j2, int n , int m, vector<vector<int>> &grid, vector<vector<vector<int>>> & dp) {
	if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

	// base condition
	if (i == n - 1) {
		if (j1 == j2) return grid[i][j1];
		else return grid[i][j1] + grid[i][j2];
	}

	if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

	int maxi = INT_MIN;
	for (int di = -1; di <= 1; di++) {
		for (int dj = -1 ; dj <= 1; dj++) {
			int ans;
			if (j1 == j2)
				ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n , m, grid, dp);
			else
				ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n , m, grid, dp);
			maxi = max(maxi, ans);
		}
	}
	return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
	vector<vector<vector<int>>> dp(n , vector<vector<int>> (m , vector<int> (m , -1)));
	return maxChocoUtil(0, 0, m - 1, n , m, grid, dp);
}


// tabulation approach
// TC O(N * M * M)
// SC O(N * M * M) + O(N)
int maximumChocolates_tabulation(int n, int m, vector<vector<int>> &grid) {
	vector<vector<vector<int>>> dp(n , vector<vector<int>> (m , vector<int> (m , -1)));

	// Base Condition
	for (int j1 = 0; j1 < m ; j1++) {
		for (int j2 = 0; j2 < m ; j2++) {
			if (j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
			else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
		}
	}

	//Outer Nested Loops for travering DP Array
	for (int i = n - 2; i >= 0; i--) {
		for (int j1 = 0; j1 < m; j1++) {
			for (int j2 = 0; j2 < m; j2++) {
				int maxi = -1e8;

				// Inner nested loops to try out 9 optioins
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1 ; dj++) {
						int ans;

						if (j1 == j2) ans = grid[i][j1];
						else ans = grid[i][j1] + grid[i][j2];

						if ((j1 + di < 0 || j1 + di >= m)  || (j2 + dj < 0 || j2 + dj >= m))
							ans += -1e8;
						else
							ans += dp[i + 1][j1 + di][j2 + dj];

						maxi = max(ans, maxi);
					}
				}
				dp[i][j1][j2] = maxi;
			}
		}
	}
	return dp[0][0][m - 1];
}

void solve_maximumChocolates() {
	vector<vector<int> > grid = {
		{2, 3, 1, 2},
		{3, 4, 2, 2},
		{5, 6, 3, 5},
	};

	int n = grid.size();
	int m = grid[0].size();

	// cout << maximumChocolates(n, m, grid);
	cout << maximumChocolates_tabulation(n, m, grid);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////// Dp on Subsequences/subsets /////////////////////////////////////////
// DP 14. Subset Sum Equals to Target | Identify DP on Subsequences/subsets and Ways to Solve them
// Subsequences/subsets => defi => any contigous/ non-contigious part of the array is known as Subsequences/subsets
// Subsequences => [1, 2, 3] => so 1, 3 is contigious and following order
//              => 3, 1 is not contigious so it it not Subsequence

// subset => might are might not follow order

// [1, 2, 3] => 2, 3 => is follow order so we called subsequnce and we can also called subArray

// TC O(N * K)
// SC O(N * K) + O(N)
bool subsetSumUtil(int ind, int target, vector<int> & arr, vector<vector<int>> & dp) {
	if (target == 0)
		return true;
	// return dp[ind][target] = true;
	if (ind == 0)
		return (arr[0] == target);
	// return dp[ind][target] = (arr[0] == target);

	if (dp[ind][target] != -1) return dp[ind][target];

	bool notPick = subsetSumUtil(ind - 1, target, arr, dp);
	bool pick = false;
	if (arr[ind] <= target)
		pick = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

	return dp[ind][target] = pick || notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
	return subsetSumUtil(n - 1, k , arr, dp);

}

// tabulation approach
// TC O(N * K)
// SC O(N * K)
bool subsetSumToK_tabulation(int n, int k, vector<int> &arr) {
	vector<vector<bool>> dp(n, vector<bool> (k + 1, false));

	// base condition
	for (int i = 0; i < n ; i++) dp[i][0] = true;
	if (arr[0] <= k) dp[0][arr[0]] = true;

	for (int ind = 1; ind < n ; ind++) {
		for (int target = 1; target <= k; target++) {
			bool notPick = dp[ind - 1][target];

			bool pick = false;
			if (arr[ind] <= target)
				pick = dp[ind - 1][target - arr[ind]];
			dp[ind][target] = pick || notPick;
		}
	}

	return dp[n - 1][k];
}

void solve_subsetSumToK() {
	vector<int> arr = {1, 2, 3, 4};
	int k = 4;
	int n = arr.size();

	// if (subsetSumToK(n, k, arr))
	if (subsetSumToK_tabulation(n, k, arr))
		cout << "Subset with given target found";
	else
		cout << "Subset with given target not found";
}

/////////////////////////////////////////////////////////////////////////////////
// DP 15. Partition Equal Subset Sum | DP on Subsequences
// if total sum is odd than division is not possible in 2 equal sum

// TC O(N * K)
// SC O(N * K) + O(N)
bool canPartition(vector<int> &arr, int n)
{
	int totSum  = 0;
	for (int i = 0; i < n ; i++) totSum += arr[i];
	// if odd totsum than return false
	if (totSum % 2) return false;

	int target = totSum / 2;
	// this is using memorization
	return subsetSumToK(n , target, arr);
	//you can use tabulation also
	// return subsetSumToK_tabulation(n , target, arr);
}

void  solve_canPartition() {
	vector<int> arr = {2, 3, 3, 3, 4, 5};
	int n = arr.size();

	if (canPartition(arr, n))
		cout << "The Array can be partitioned into two equal subsets";
	else
		cout << "The Array cannot be partitioned into two equal subsets";
}

////////////////////////////////////////////
// Dp 16. Partition A Set Into Two Subsets With Minimum Absolute Sum Difference | DP on Subsequences
// this is memorization approach
// we can use tabulation approach also
int minSubsetSumDifference(vector<int>& arr, int n) {
	int totSum = 0;
	for (int i = 0; i < n; i++) totSum += arr[i];

	vector<vector<int>> dp (n, vector<int> (totSum + 1, -1));

	for (int i = 0; i <= totSum; i++) {
		bool dummy = subsetSumUtil(n - 1, i, arr, dp);
	}

	int mn = 1e9;
	for (int i = 0; i <= totSum; i++) {
		if (dp[n - 1][i] == true) {
			int s1 = i;
			int s2 = totSum - i;
			int diff = abs(s1 - s2);
			mn = min(mn , diff );
		}
	}
	return mn;
}

void solve_minSubsetSumDifference() {
	vector < int > arr = {1, 2, 3, 4};
	int n = arr.size();

	cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);
}

///////////////////////////////////////////////////////////////////////////
// DP 17. Counts Subsets with Sum K | Dp on Subsequences
int findWaysUtil(int ind, int target, vector<int> & arr, vector<vector<int>> & dp) {
	if (target == 0) return 1; // if array does not containt 0 than this use
	if (ind == 0) return arr[0] == target;

	// if array containt 0 or not containt than this use
	// if (ind == 0) {
	// 	if (target == 0 && arr[0] == 0) return 2;
	// 	if (target == 0 || target == arr[0]) return 1;
	// 	return 0;
	// }

	if (dp[ind][target] != -1) return dp[ind][target];

	int notPick = findWaysUtil(ind - 1, target, arr, dp);
	int pick = 0;
	if (arr[ind] <= target)
		pick = findWaysUtil(ind - 1, target - arr[ind], arr, dp);
	return dp[ind][target] = notPick + pick;
}
int findWays(vector<int> &num, int k) {
	int n = num.size();
	vector<vector<int>> dp(n , vector<int> (k + 1, -1));
	return findWaysUtil(n - 1, k, num, dp);
}

// tabulation approach
int findWays_tabulation(vector<int> & num, int k) {
	int n = num.size();

	vector<vector<int>> dp(n , vector<int> (k + 1, 0));

	for (int i = 0; i < n; i++) dp[i][0] = 1;
	if (num[0] <= k) dp[0][num[0]] = 1;

	for (int ind = 1; ind < n ; ind++) {
		for (int target = 1; target <= k ; target++) {
			int notPick = dp[ind - 1][target];

			int pick = 0;
			if (num[ind] <= target)
				pick = dp[ind - 1][target - num[ind]];

			dp[ind][target] = notPick + pick;
		}
	}

	return dp[n - 1][k];
}
void solve_findWays() {
	vector<int> arr = {1, 2, 2, 3};
	int k = 3;
	// cout << "The number of subsets found are " << findWays(arr, k);
	cout << "The number of subsets found are " << findWays_tabulation(arr, k);
}

/////////////////////////////////////////////////////////////////////////
// DP 18. Count Partitions With Given Difference | Dp on Subsequences
int m = (int)1e9 + 7;

int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
                        <int>> &dp) {

	if (ind == 0) {
		if (target == 0 && arr[0] == 0)
			return 2;
		if (target == 0 || target == arr[0])
			return 1;
		return 0;
	}

	if (dp[ind][target] != -1)
		return dp[ind][target];

	int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);

	int taken = 0;
	if (arr[ind] <= target)
		taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

	return dp[ind][target] = (notTaken + taken) % m;
}

int countPartitions(int d, vector<int>& arr) {
	int n = arr.size();
	int totSum = 0;
	for (int i = 0; i < arr.size(); i++) {
		totSum += arr[i];
	}

	//Checking for edge cases
	if (totSum - d < 0) return 0;
	if ((totSum - d) % 2 == 1) return 0;

	int s2 = (totSum - d) / 2;

	vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
	return countPartitionsUtil(n - 1, s2, arr, dp);
}

// tabulation approach
int count_tab(vector<int> &num, int tar) {
	int n = num.size();

	vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

	if (num[0] == 0) dp[0][0] = 2; // 2 cases -pick and not pick
	else dp[0][0] = 1;  // 1 case - not pick

	if (num[0] != 0 && num[0] <= tar) dp[0][num[0]] = 1; // 1 case -pick

	for (int ind = 1; ind < n; ind++) {
		for (int target = 0; target <= tar; target++) {

			int notTaken = dp[ind - 1][target];

			int taken = 0;
			if (num[ind] <= target)
				taken = dp[ind - 1][target - num[ind]];

			dp[ind][target] = (notTaken + taken) % mod;
		}
	}
	return dp[n - 1][tar];
}

int countPartitions_tabulation(int n, int d, vector<int>& arr) {
	int totSum = 0;
	for (int i = 0; i < n; i++) {
		totSum += arr[i];
	}

	//Checking for edge cases
	if (totSum - d < 0 || (totSum - d) % 2 ) return 0;

	return count_tab(arr, (totSum - d) / 2);
}

void solve_countPartitions() {
	vector<int> arr = {5, 2, 6, 4};
	int d = 3;
	int n = arr.size();
	// cout << "The number of subsets found are " << countPartitions(d, arr);
	cout << "The number of subsets found are " << countPartitions_tabulation(n , d, arr);
}

/////////////////////////////////////////////////////////////////////////////////////
// DP 19. 0 / 1 Knapsack | Recursion to Single Array Space Optimised Approach | DP on Subsequences
// memorization approach
// TC O(N * W)
// SC O(N * W) + O(N)
int knapsackUtil(vector<int> & weight, vector<int> & value, int ind, int maxWeight, vector<vector<int>> & dp) {
	if (ind == 0) {
		if (weight[0] <= maxWeight) return value[0];
		else return 0;
	}

	if (dp[ind][maxWeight] != -1) return  dp[ind][maxWeight];

	int notPick = 0 + knapsackUtil(weight, value, ind - 1, maxWeight, dp);
	int pick = INT_MIN;
	if (weight[ind] <= maxWeight)
		pick = value[ind] + knapsackUtil(weight, value, ind - 1, maxWeight - weight[ind], dp);

	return dp[ind][maxWeight] = max(notPick, pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n , vector<int> (maxWeight + 1, -1));
	return knapsackUtil(weight, value, n - 1, maxWeight, dp);
}

// tabulation approach
// TC O(N * W)
// SC O(N * W)
int knapsack_tabulation(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n , vector<int> (maxWeight + 1, -1));

	// Base Condition
	for (int i = weight[0]; i <= maxWeight; i++)
		dp[0][i] = value[0];

	for (int ind = 1; ind < n; ind++) {
		for (int cap = 0; cap <= maxWeight; cap++) {
			int notPick = 0 + dp[ind - 1][cap];

			int pick = INT_MIN;
			if (weight[ind] <= cap)
				pick = value[ind] + dp[ind - 1][cap - weight[ind]];

			dp[ind][cap] = max(notPick, pick);
		}
	}

	return dp[n - 1][maxWeight];
}

void solve_knapsack() {
	vector<int> weight = {1, 2, 4, 5};
	vector<int> value = {5, 4, 8, 6};
	int maxWeight = 5;

	int n = value.size();
	// cout << "The Maximum value of items, thief can steal is " << knapsack(weight, value, n, maxWeight);
	cout << "The Maximum value of items, thief can steal is " << knapsack_tabulation(weight, value, n, maxWeight);
}

/////////////////////////////////////////////////////////////////////////////////
// DP 20. Minimum Coins | DP on Subsequences | Infinite Supplies Pattern
int minimumElementsUtils(vector<int> & arr, int ind, int target, vector<vector<int>> & dp) {
	if (ind == 0) {
		if (target % arr[0] == 0) return target / arr[0];
		return 1e9;
	}

	if (dp[ind][target] != -1) return dp[ind][target];

	int notPick =  0 + minimumElementsUtils(arr, ind - 1, target, dp);
	int pick = 1e9;

	if (arr[ind] <= target)
		pick = 1 + minimumElementsUtils(arr, ind, target - arr[ind], dp);
	return min(notPick, pick);
}
int minimumElements(vector<int> &arr, int target) {
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (target + 1, -1));
	int ans = minimumElementsUtils(arr, n - 1, target, dp);
	if (ans >= 1e9) return -1;
	return ans;
}


// tabulation approach
int minimumElements_tabulation(vector<int> &arr, int target) {
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (target + 1, -1));

	for (int i = 0; i <= target; i++) {
		if (i % arr[0] == 0) dp[0][i] = i / arr[0];
		else dp[0][i] = 1e9;
	}

	for (int ind = 1; ind < n ; ind++) {
		for (int T = 0; T <= target; T++) {
			int notPick = 0 + dp[ind - 1][T];
			int pick = 1e9;

			if (arr[ind] <= T)
				pick = 1 + dp[ind][T - arr[ind]];

			dp[ind][T] = min(notPick, pick);
		}
	}

	int ans = dp[n - 1][target];
	if (ans >=  1e9) return -1;
	else return ans;
}

void solve_minimumElements() {
	vector<int> arr = {1, 2, 3};
	int Target = 7;

	// cout << "The minimum number of coins required to form the target sum is "
	//      << minimumElements(arr, Target);

	cout << "The minimum number of coins required to form the target sum is "
	     << minimumElements_tabulation(arr, Target);
}

//////////////////////////////////////////////////////////////////////////////
// DP 21. Target Sum | DP on Subsequences
int countPartitionsUtil1(int ind, int target, vector<int>& arr, vector<vector
                         <int>> &dp) {

	if (ind == 0) {
		if (target == 0 && arr[0] == 0)
			return 2;
		if (target == 0 || target == arr[0])
			return 1;
		return 0;
	}

	if (dp[ind][target] != -1)
		return dp[ind][target];

	int notTaken = countPartitionsUtil1(ind - 1, target, arr, dp);

	int taken = 0;
	if (arr[ind] <= target)
		taken = countPartitionsUtil1(ind - 1, target - arr[ind], arr, dp);

	return dp[ind][target] = (notTaken + taken);
}

int countPartitions1(int d, vector<int>& arr) {
	int n = arr.size();
	int totSum = 0;
	for (int i = 0; i < arr.size(); i++) {
		totSum += arr[i];
	}

	//Checking for edge cases
	if (totSum - d < 0) return 0;
	if ((totSum - d) % 2 == 1) return 0;

	int s2 = (totSum - d) / 2;

	vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
	return countPartitionsUtil1(n - 1, s2, arr, dp);
}
int targetSum(int n, int target, vector<int>& arr) {
	return countPartitions1(target, arr);
}

void solve_targetSum() {
	vector<int> arr = {1, 2, 3, 1};
	int target = 3;

	int n = arr.size();
	cout << "The number of ways found is " << targetSum(n, target, arr);
}


////////////////////////////////////////////////////////////////////////////
// DP 22. Coin Change 2 | Infinite Supply Problems | DP on Subsequences
long countWaysToMakeChangeUtil(vector<int> & arr, int ind, int target, vector<vector<long>> & dp) {
	if (ind == 0)
		return (target % arr[0] == 0);

	if (dp[ind][target] != -1)
		return dp[ind][target];

	long notPick = countWaysToMakeChangeUtil(arr, ind - 1, target, dp);
	long pick = 0;
	if (arr[ind] <= target)
		pick = countWaysToMakeChangeUtil(arr, ind, target - arr[ind], dp);

	return dp[ind][target] = notPick + pick;
}
long countWaysToMakeChange(vector<int> & arr, int n, int target) {
	vector<vector<long>> dp(n , vector<long> (target + 1, -1));
	return countWaysToMakeChangeUtil(arr, n - 1, target, dp);
}

void solve_countWaysToMakeChange() {
	vector<int> arr = {1, 2, 3};
	int target = 4;

	int n = arr.size();

	cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target);
}

////////////////////////////////////////////////////////////////////
// DP 23. Unbounded Knapsack | 1-D Array Space Optimised Approach

// Time Complexity: O(N*W)
// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).
int unboundedKnapsackUtil(vector<int> & weight, vector<int> & value, int ind, int w, vector<vector<int>> & dp) {
	if (ind == 0)
		return ((int)(w / weight[0])) * value[0];

	if (dp[ind][w] != -1) return dp[ind][w];

	int notPick = 0 + unboundedKnapsackUtil(weight, value, ind - 1, w, dp);
	int pick = INT_MIN;
	if (weight[ind] <= w)
		pick = value[ind] + unboundedKnapsackUtil(weight, value, ind,  w - weight[ind],  dp);

	return dp[ind][w] = max(notPick, pick);
}
int unboundedKnapsack(int n, int w, vector<int> &value, vector<int> &weight) {
	vector<vector<int>> dp(n , vector<int> (w + 1, -1));
	return unboundedKnapsackUtil(weight, value, n - 1, w, dp);
}

void solve_unboundedKnapsack() {
	vector<int> weight = {2, 4, 6};
	vector<int> value = {5, 11, 13};
	int W = 10;

	int n = weight.size();

	cout << "The Maximum value of items, thief can steal is " <<
	     unboundedKnapsack(n, W, value, weight);
}

/////////////////////////////////////////////////////////////////////////////////////////
// DP 24. Rod Cutting Problem | 1D Array Space Optimised Approach
int cutRodUtil(vector<int> & price, int ind, int n, vector<vector<int>> & dp) {
	if (ind == 0) return (n * price[0]);
	if (dp[ind][n] != -1) return dp[ind][n];

	int notPick = 0 + cutRodUtil(price, ind - 1, n, dp);
	int pick = INT_MIN;
	int roadLength = ind + 1;
	if (roadLength <= n)
		pick = price[ind] + cutRodUtil(price, ind , n - roadLength, dp);
	return dp[ind][n] = max(notPick, pick);
}
int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n , vector<int> (n + 1, -1));
	return cutRodUtil(price, n - 1, n, dp);
}

void solve_cutRod() {
	vector<int> price = {2, 5, 7, 8, 10};
	int n = price.size();

	cout << "The Maximum price generated is " << cutRod(price, n);
}

///////////////////////////////////////////////////////////////////////////
/////////////////// dp on string /////////////////////////////////////////
// Dp 25. Longest Common Subsequence | Top Down | Bottom-Up | Space Optimised | DP on Strings
// eg : abc => a, b, c, ab, bc, ac, abc
// here ac is not consicutive but mantaning the order so it is subsequnce
// subsequnce can be or can not be consecutive but maintaning the order


// int lcsUtil(string & s1, string & s2, int ind1, int ind2, vector<vector<int>> &dp) {
// 	if(ind1 < 0 || ind2 < 0 ) return 0 ;
// 	if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

// 	if(s1[ind1] == s2[ind2])
// 		return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
// 	else
// 		return dp[ind1][ind2] = 0 + max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
// }


// here we printing length of longest common subsequnce
// TC O(N * M)
// TC O(N * M) + (N + M)
int lcsUtil(string & s1, string & s2, int ind1, int ind2, vector<vector<int>> &dp) {
	if (ind1 < 0 || ind2 < 0) return 0;
	if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

	int ans = 0;
	if (s1[ind1] == s2[ind2])
		ans = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
	else
		ans = 0 + max(lcsUtil(s2, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
	return ans;
}
int lcs(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n , vector<int> (m, -1));
	return lcsUtil(s1, s2, n - 1, m - 1 , dp);
}


// tabulation approach
// TC O(N * M)
// TC O(N * M) + (N + M)
int lcs_tabulation(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();


	// here we are doing shofting of index
	vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
	for (int i = 0; i <= n ; i++) {
		dp[i][0] = 0;
	}

	for (int j = 0; j <= m ; j++) {
		dp[0][j] = 0;
	}

	for (int ind1 = 1; ind1 <= n; ind1++) {
		for (int ind2 = 1; ind2 <= m; ind2++) {
			int ans = 0;
			if (s1[ind1 - 1] == s2[ind2 - 1])
				ans = 1 + dp[ind1 - 1][ind2 - 1];
			else
				ans = 0 + max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
			dp[ind1][ind2] = ans;
		}
	}

	return dp[n][m];
}


void solve_lcs() {
	string s1 = "acd";
	string s2 = "ced";
	// cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
	cout << "The Length of Longest Common Subsequence is " << lcs_tabulation(s1, s2);
}
///////////////////////////////////////////////////////////////////////////////
// DP 26. Print Longest Common Subsequence | Dp on Strings
// here we are printing longest common subsequnces


string lcs_string(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();


	// here we are doing shofting of index
	// vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
	vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
	for (int i = 0; i <= n ; i++) {
		dp[i][0] = 0;
	}

	for (int j = 0; j <= m ; j++) {
		dp[0][j] = 0;
	}

	for (int ind1 = 1; ind1 <= n; ind1++) {
		for (int ind2 = 1; ind2 <= m; ind2++) {
			int ans = 0;
			if (s1[ind1 - 1] == s2[ind2 - 1])
				ans = 1 + dp[ind1 - 1][ind2 - 1];
			else
				ans = 0 + max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
			dp[ind1][ind2] = ans;
		}
	}

	int len =  dp[n][m];
	int i = n;
	int j = m;
	string str = "";
	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			str += s1[i - 1];
			i--;
			j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else j--;
	}

	reverse(str.begin(), str.end());

	return str;
}
void solve_lcs_string() {
	string s1 = "acd";
	string s2 = "ced";
	cout << "The Length of Longest Common Subsequence is => " << lcs_string(s1, s2);
}

////////////////////////////////////////////////////////////////////////////////////
// DP 27. Longest Common Substring | DP on Strings 🔥
// substring always in consecutive order
// abc => a, b, c, ab, bc => like this is called substring
int lcs_memo(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp) {
	if (ind1 < 0 || ind2 < 0) {
		return 0;
	}

	if (dp[ind1][ind2] != -1) {
		return dp[ind1][ind2];
	}

	int ans = 0;
	if (s1[ind1] == s2[ind2]) {
		ans = 1 + lcs_memo(s1, s2, ind1 - 1, ind2 - 1, dp);
	} else {
		ans = 0;
	}

	return dp[ind1][ind2] = ans;
}

int longest_common_substring(string &s1, string &s2) {
	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n, vector<int>(m, -1));

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, lcs_memo(s1, s2, i, j, dp));
			//cout << " i => " << i  << " j => " << j << " ans " << ans << endl;
		}
	}

	return ans;
}

// tabulation approach
int longest_common_substring_tabulation(string & s1, string & s2 ) {

	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				int val = 1 + dp[i - 1][j - 1];
				dp[i][j] = val;
				ans = max(ans, val);
			}
			else
				dp[i][j] = 0;
		}
	}

	return ans;

}


void solve_longest_common_substring() {
	string s1 = "abcjklp";
	string s2 = "acjkp";
	// cout << "The Length of Longest Common Substring is " << longest_common_substring(s1, s2);
	cout << "The Length of Longest Common Substring is " << longest_common_substring_tabulation(s1, s2);
}

//////////////////////////////////////////////////////////////////////////
// DP 28. Longest Palindromic Subsequence

// memorization_approach 1
int longestPalindromeSubsequence(string s) {
	int n = s.length();
	vector<vector<int>>  dp(n , vector<int> (n , -1));

	// l => left, r => right
	function<int(int, int)> helper = [&](int l, int r) {
		if (l > r) return 0;
		if (l == r) return 1;
		if (dp[l][r] != -1) return dp[l][r];

		int ans = 0;
		if (s[l] == s[r])
			ans = 2 + helper(l + 1, r  - 1);
		else
			ans = 0 + max(helper(l + 1 , r), helper(l , r - 1));

		return dp[l][r] = ans;
	};

	return helper(0, n - 1);
}

// memorization_approach 2
// aab baa
int longestPalindromeSubsequence1(string s) {
	string t = s;
	reverse(s.begin(), s.end());
	int n = s.length();
	vector<vector<int>>  dp(n , vector<int> (n , -1));

	function<int(int, int)> helper = [&](int ind1, int ind2) {
		if (ind1 <  0 || ind2 < 0) return 0;
		if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

		int ans = 0;
		if (s[ind1] == t[ind2])
			ans = 1 + helper(ind1 - 1, ind2  - 1);
		else
			ans = 0 + max(helper(ind1 - 1 , ind2), helper(ind1 , ind2 - 1));

		return dp[ind1][ind2] = ans;
	};

	return helper(n - 1, n - 1);
}

// tabulation approach 1
int longestPalindromeSubseq_tabulation(string s) {
	int n = s.length();
	vector<vector<int>> dp(n, vector<int>(n, -1));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i > j)
				dp[i][j] = 0;
			else if (i == j)
				dp[i][j] = 1;
			else {
				if (s[i] == s[j])
					dp[i][j] = 2 + dp[i + 1][j - 1];
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[0][n - 1];
}

// tabulation approach 2
int longestPalindromeSubseq_tabulation1(string s) {
	string t = s;
	reverse(s.begin(), s.end());
	int n = s.size();
	// here we are doing shifting of index Approach -> 1
	// vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
	// for (int i = 0; i <= n ; i++) {
	// 	dp[i][0] = 0;
	//     dp[0][i] = 0;
	// }

	// we don't need this because we have same string we have just n length we does not have m length
	// for (int j = 0; j <= n ; j++) {
	// 	dp[0][j] = 0;
	// }

	// here we are doing shifting of index Approach -> 2
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

	for (int ind1 = 1; ind1 <= n; ind1++) {
		for (int ind2 = 1; ind2 <= n; ind2++) {
			int ans = 0;
			if (s[ind1 - 1] == t[ind2 - 1])
				ans = 1 + dp[ind1 - 1][ind2 - 1];
			else
				ans = 0 + max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
			dp[ind1][ind2] = ans;
		}
	}

	return dp[n][n];
}

void solve_longestPalidromeSubsequnce() {
	string s = "bbbacbcab";
	// cout<<"The Length of Longest Palindromic Subsequence is "<< longestPalindromeSubsequence(s);
	// cout<<"The Length of Longest Palindromic Subsequence is "<< longestPalindromeSubsequence1(s);
	// cout<<"The Length of Longest Palindromic Subsequence is "<< longestPalindromeSubseq_tabulation(s);
	cout << "The Length of Longest Palindromic Subsequence is " << longestPalindromeSubseq_tabulation1(s);
}

////////////////////////////////////////////////////////////////////////////
// DP 29. Minimum Insertions to Make String Palindrome
// hard => leetcode => 1312. Minimum Insertion Steps to Make a String Palindrome
int minInsertions(string s) {
	int n = s.size();
	int k = longestPalindromeSubsequence(s);
	return n - k;
}

void solve_minInsertions() {
	string s = "abcaa";
	cout << "The Minimum insertions required to make string palindrome: " <<
	     minInsertions(s);
}

/////////////////////////////////////////////////////////////////////////////////////
// DP 30. Minimum Insertions/Deletions to Convert String A to String B

int canYouMake(string &str1, string &str2) {
	int n = str1.size();
	int m = str2.size();

	int k = lcs(str1, str2);
	return (n - k) + (m - k);
}

void solve_canYouMake() {
	string str1 = "abcd";
	string str2 = "anc";

	cout << "The Minimum operations required to convert str1 to str2: " <<
	     canYouMake(str1, str2);
}

///////////////////////////////////////////////////////////////////////////////////////
// DP 31. Shortest Common Supersequence | DP on Strings
// leetcode =>  1092. Shortest Common Supersequence
#include <bits/stdc++.h>

using namespace std;

string shortestSupersequence(string s1, string s2) {

	int n = s1.size();
	int m = s2.size();

	vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= m; i++) {
		dp[0][i] = 0;
	}

	for (int ind1 = 1; ind1 <= n; ind1++) {
		for (int ind2 = 1; ind2 <= m; ind2++) {
			if (s1[ind1 - 1] == s2[ind2 - 1])
				dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
			else
				dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
		}
	}

	int len = dp[n][m];
	int i = n;
	int j = m;

	int index = len - 1;
	string ans = "";

	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			ans += s1[i - 1];
			index--;
			i--;
			j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			ans += s1[i - 1];
			i--;
		} else {
			ans += s2[j - 1];
			j--;
		}
	}

	//Adding Remaing Characters - Only one of the below two while loops will run

	while (i > 0) {
		ans += s1[i - 1];
		i--;
	}
	while (j > 0) {
		ans += s2[j - 1];
		j--;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}


void solve_shortestSupersequence() {
	string s1 = "brute";
	string s2 = "groot";
	cout << "The Longest Common Supersequence is " << shortestSupersequence(s1, s2);
}

///////////////////////////////////////////////////////////////////////////////////////
// DP 32. Distinct Subsequences | 1D Array Optimisation Technique 🔥
// 115. Distinct Subsequences

// memorization approach 1 => using simple function
int numDistinctUtil(string & s1, string & s2, int ind1, int ind2 , vector<vector<int>> & dp) {
	if (ind2 < 0) return 1;
	if (ind1 < 0) return 0;

	if (dp[ind1][ind2] !=  -1)
		return dp[ind1][ind2];

	int ans = 0;
	if (s1[ind1] == s2[ind2]) {
		int leaveOne = numDistinctUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
		int stay = numDistinctUtil(s1, s2, ind1 - 1, ind2, dp);
		ans = leaveOne + stay;
	} else {
		ans = numDistinctUtil(s1, s2, ind1 - 1, ind2, dp);
	}

	return dp[ind1][ind2] = ans;
}
int numDistinct(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n , vector<int> (m , -1));
	return numDistinctUtil(s1, s2, n  - 1, m   - 1 , dp);
}

// same as above memorization approach 1 => using lambada function
int numDistinct1(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();
	vector<vector<int>> dp(n , vector<int> (m , -1));

	function<int(int, int)> helper = [&](int ind1, int ind2) {
		if (ind2 < 0) return 1;
		if (ind1 < 0) return 0;

		if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

		int ans = 0;

		if (s1[ind1] == s2[ind2]) {
			int leaveOne = helper(ind1 - 1, ind2 - 1);
			int stay = helper(ind1 - 1, ind2);
			ans = leaveOne + stay;
		} else {
			ans = helper(ind1 - 1, ind2);
		}
		return dp[ind1][ind2] = ans;
	};

	return helper(n - 1, m - 1);
}
void solve_numDistinct() {
	string s1 = "babgbag";
	string s2 = "bag";

	// cout << "The Count of Distinct Subsequences is "
	//      << numDistinct(s1, s2);

	cout << "The Count of Distinct Subsequences is "
	     << numDistinct1(s1, s2);
}
//////////////////////////////////////////////////////////////////////////////////////////////
// DP 33. Edit Distance
// 72. Edit Distance
// memorization approach 1
int editDistanceUtil(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
	if (i < 0) return j + 1; // to insert => operation required is j + 1
	if (j < 0) return i + 1; // to delete => operation required is i + 1

	if (dp[i][j] != -1) return dp[i][j];

	int ans = 0;
	if (s1[i] == s2[j]) {
		// if both the character are match then we don't have to do any operation we just have to move to next in both s1 and s2
		ans = 0 + editDistanceUtil(s1, s2, i - 1, j - 1, dp);
	} else {
		ans = 1 + min(
		          editDistanceUtil(s1, s2, i - 1, j - 1, dp), // if we are at character we have to replace the string
		          min(
		              editDistanceUtil(s1, s2, i - 1, j, dp), // if we are at character that character does not match then we have to move in s1, and delete that character
		              editDistanceUtil(s1, s2, i, j - 1, dp) // if we are at character that character does not match then we have to move in s1, and insert that character
		          )
		      );
	}

	return dp[i][j] = ans;
}

int editDistance(string& s1, string& s2) {
	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n, vector<int>(m, -1));
	return editDistanceUtil(s1, s2, n - 1, m - 1, dp);
}

// memorization approach using lambada function 2
int editDistance1(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();
	vector<vector<int>> dp(n , vector<int> (m , -1));

	function<int(int, int)>  f = [&](int i, int j) {
		if (i < 0) return j + 1;
		if (j < 0) return i + 1;
		if (dp[i][j] != -1) return dp[i][j];
		int ans = 0;
		if (s1[i] == s2[j]) ans = 0 + f(i - 1, j - 1);
		else ans = 1 + min(f(i - 1, j - 1), min(f(i - 1, j), f(i, j - 1)));
		return dp[i][j] = ans;
	};
	return f(n - 1, m - 1);
}

// memorization approach using lambada function 3
int editDistance2(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();
	vector<vector<int>> dp(n , vector<int> (m , false));
	auto f = [&](int i, int j, auto && f) {
		if (i < 0) return j + 1;
		if (j < 0) return i + 1;
		if (dp[i][j] != -1) return dp[i][j];
		int ans = 0;
		if (s1[i] == s2[j]) ans = 0 + f(i - 1, j - 1, f);
		else ans = 1 + min(f(i - 1, j - 1, f), min(f(i - 1, j, f), f(i, j - 1, f)));
		return dp[i][j] = ans;
	};
	return f(n - 1, m - 1, f);
}
void solve_editDistance() {
	string s1 = "horse";
	string s2 = "ros";

	cout << "The minimum number of operations required is: " << editDistance(s1, s2);
}

////////////////////////////////////////////////////////////////////////////////////////////
// DP 34. Wildcard Matching 🔥
// leetcode => 44. Wildcard Matching
// ?. -> matches single character
// * -> matches with sequences of length 0 or more
// TC O(N * M) + O(N + M)
bool isMatch(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();

	vector<vector<bool>> dp(n , vector<bool> (m , -1));

	function<bool(int, int)> helper = [&](int i, int j) -> bool {
		// base condition
		// 1. both strings are exacusted
		if (i < 0 && j < 0) return true;
		// 2. if s1 is exacuted and s2 is not exacusted
		if (i < 0 && j >= 0) return false;

		// 3. if s2 is exacusted and s1 has all the stars(*)
		if (j < 0 && i >= 0) {
			for (int ind = 0; ind < i; ind++) {
				if (s1[ind] != '*')
					return false;
			}
			return true;
		}

		if (dp[i][j] != -1) return dp[i][j];

		if (s1[i] == s2[j] || s1[i] == '?')
			return dp[i][j] = helper(i - 1, j - 1);
		else  {
			if (s1[i] == '*')
				return helper(i - 1, j) || helper(i, j - 1);
			else
				return false;
		}
	};

	return helper(n - 1, m - 1);
}

void solve_isMatch() {
	string S1 = "ab*cd";
	string S2 = "abdefcd";
	if (isMatch(S1, S2))
		cout << "String S1 and S2 do match";
	else cout << "String S1 and S2 do not match";
}

///////////////////////////////// DP on Stocks ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// DP 35. Best Time to Buy and Sell Stock | DP on Stocks 🔥
int maxProfit(vector<int>& prices) {
	int maxProfit = 0;
	int mini = prices[0];

	for (int i = 1; i < prices.size(); i++) {
		int currProfit  = prices[i] - mini;
		maxProfit = max(maxProfit, currProfit);
		mini = min(mini, prices[i]);
	}

	return maxProfit;
}

void solve_maxProfit() {
	vector<int> prices  = {7, 1, 5, 3, 6, 4};
	cout << "The maximum profit by selling the stock is " << maxProfit(prices);
}

//////////////////////////////////////////////////////////////////////////////////
// DP 36. Buy and Sell Stock - II | Recursion to Space Optimisation

int maxProfit1(vector<int> & prices, int n) {
	vector<vector<int>> dp(n , vector<int> (2, -1)); // 0(sell) or 1(buy)

	function<int(int , int)> solve = [&](int ind, int buy) {
		if (ind == n) return 0; // when no stockes are reamaning for byu so no profit
		if (dp[ind][buy] != - 1) return dp[ind][buy];

		int profit = 0;
		// 1 for buy
		if (buy == 1) {
			profit = max(-prices[ind] + solve(ind + 1, 0), 0 + solve(ind + 1, 1));
		} else {
			// buy = 0 // 0 for sell
			profit = max(prices[ind] + solve(ind + 1, 1), 0 + solve(ind + 1, 0));
		}
		return dp[ind][buy] = profit;
	};

	return solve(0, 1);
}
void solve_maxProfit1() {
	vector<int> prices  = {7, 1, 5, 3, 6, 4};
	cout << "The maximum profit that can be generated is " << maxProfit1(prices, (int)prices.size());
}

///////////////////////////////////////////////////////////////////////////////////////////
// DP 37. Buy and Sell Stocks III
// leetcode => 123. Best Time to Buy and Sell Stock III
int maxProfit2(vector<int>& prices) {
	int n = prices.size();
	vector<vector<vector<int>>> dp(n , vector<vector<int>> (2, vector<int> (3, -1)));

	function<int(int, int, int)> solve = [&](int ind, int buy, int cap) {
		if (ind == n || cap == 0) return 0;
		if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

		int profit;
		// 1 for buy
		if (buy == 1) {
			profit = max(-prices[ind] + solve(ind + 1, 0, cap), 0 + solve(ind + 1, 1, cap));
		} else {
			// buy = 0 // 0 for sell
			profit = max(prices[ind] + solve(ind + 1, 1, cap - 1), 0 + solve(ind + 1, 0, cap));
		}

		return dp[ind][buy][cap] = profit;
	};

	return solve(0, 1, 2);
}
void solve_maxProfit2() {
	vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
	int n = prices.size();
	cout << "The maximum profit that can be generated is " << maxProfit2(prices);
}

////////////////////////////////////////////////////////////////////////////////////
// DP 38. Buy and Stock Sell IV
// leetcode => 188. Best Time to Buy and Sell Stock IV
// Time Complexity: O(N*2*3)
// Space Complexity: O(N*2*K) + O(N)
int maxProfit3(int k, vector<int>& prices) {
	int n = prices.size();
	vector<vector<vector<int>>> dp(n , vector<vector<int>> (2, vector<int> (k + 1, -1)));

	function<int(int, int, int)> solve = [&](int ind, int buy, int k) {
		if (ind == n || k == 0) return 0;
		if (dp[ind][buy][k] != -1) return dp[ind][buy][k];

		int profit;
		// 1 for buy
		if (buy == 1) {
			profit = max(-prices[ind] + solve(ind + 1, 0, k), 0 + solve(ind + 1, 1, k));
		} else {
			// buy = 0 // 0 for sell
			profit = max(prices[ind] + solve(ind + 1, 1, k - 1), 0 + solve(ind + 1, 0, k));
		}

		return dp[ind][buy][k] = profit;
	};

	return solve(0, 1, k);
}
void solve_maxProfit3() {
	vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
	int k = 2;
	cout << "The maximum profit that can be generated is " << maxProfit3(k, prices);
}

///////////////////////////////////////////////////////////////
// DP 39. Buy and Sell Stocks With Cooldown | Recursion to Space Optimisation
// leetcode => 309. Best Time to Buy and Sell Stock with Cooldown
// Time Complexity: O(N*2)
// Space Complexity: O(N*2) + O(N)
int maxProfit4(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n , vector<int> (2, -1)); // 0(sell) or 1(buy)

	function<int(int , int)> solve = [&](int ind, int buy) {
		if (ind >= n) return 0; // when no stockes are reamaning for byu so no profit
		if (dp[ind][buy] != - 1) return dp[ind][buy];

		int profit = 0;
		// 1 for buy
		if (buy == 1) {
			profit = max(-prices[ind] + solve(ind + 1, 0), 0 + solve(ind + 1, 1));
		} else {
			// buy = 0 // 0 for sell
			profit = max(prices[ind] + solve(ind + 2, 1), 0 + solve(ind + 1, 0));
		}
		return dp[ind][buy] = profit;
	};

	return solve(0, 1); // 1 = buy , we are starting with buying
}
void solve_maxProfit4() {
	// vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
	vector<int> prices = {4, 9, 0, 4, 10};
	cout << "The maximum profit that can be generated is " << maxProfit4(prices);
}

/////////////////////////////////////////////////////////////////////////////////////////
// DP 40. Buy and Sell Stocks With Transaction Fee | Recursion to Space Optimisation
// lettcode => 714. Best Time to Buy and Sell Stock with Transaction Fee
int maxProfit5(vector<int>& prices, int fee) {
	int n = prices.size();
	if (n == 0) return 0;
	vector<vector<int>> dp(n , vector<int> (2, -1)); // 0(sell) or 1(buy)

	function<int(int , int)> solve = [&](int ind, int buy) {
		if (ind == n) return 0; // when no stockes are reamaning for byu so no profit
		if (dp[ind][buy] != - 1) return dp[ind][buy];

		int profit = 0;
		// 1 for buy
		if (buy == 1) {
			profit = max(-prices[ind] + solve(ind + 1, 0), 0 + solve(ind + 1, 1));
		} else {
			// buy = 0 // 0 for sell
			profit = max(prices[ind] - fee + solve(ind + 1, 1), 0 + solve(ind + 1, 0));
		}
		return dp[ind][buy] = profit;
	};

	return solve(0, 1); // 1 = buy , we are starting with buying
}

void solve_maxProfit5() {
	vector<int> prices = {1, 3, 2, 8, 4, 9};
	int fee = 2;
	cout << "The maximum profit that can be generated is " << maxProfit5(prices, fee);
}

////// Longest increasing subsequence //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// DP 41. Longest Increasing Subsequence | Memoization
// leetcode => 300. Longest Increasing Subsequence
// Time Complexity: O(N*N)
// Space Complexity: O(N*N) + O(N)
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> dp(n , vector<int> (n + 1, -1)); // shifting of cordinates

	function<int(int, int)> solve = [&](int ind, int prev_ind) {
		if (ind == n) return 0; // there no index are remaning so, length does not count
		if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

		int not_pick = 0 + solve(ind + 1, prev_ind); // not pick

		int pick = 0 ;
		if (prev_ind == -1 || nums[ind] > nums[prev_ind])
			pick = 1 + solve(ind + 1, ind); // pick condition and store max  length

		return dp[ind][prev_ind + 1] = max(not_pick, pick);
	};
	return solve(0, -1); // first index does not have prev_ind that's why -1
}

void solve_lengthOfLIS() {
	vector<int> nums = {3, 2, 3};
	cout << "The length of the longest increasing subsequence is "
	     << lengthOfLIS(nums);
}


///////////////////////////////////////////////////////////////////////////
// DP 42. Longest Increasing Subsequence
///////////////////////////////////////////////////////////////////////////////
// DP 43. Longest Increasing Subsequence | Binary Search | Intuition
// TC O(N * logN)
// SC O(N)
int lengthOfLIS_binary(vector<int> & nums) {
	vector<int> temp;
	temp.push_back(nums[0]);
	int len = 1;
	for (int i = 1; i < (int)nums.size(); i++) {
		if (nums[i] > temp.back()) {
			temp.push_back(nums[i]);
			len++;
		} else {
			int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
			temp[ind] = nums[i];
		}
	}

	// return temp.size();
	return len;
}
void solve_lengthOfLIS_binary() {
	vector<int> nums = {3, 2, 3};
	cout << "The length of the longest increasing subsequence is "
	     << lengthOfLIS_binary(nums);
}

///////////////////////////////////////////////////////////////////////////////////////////
// DP 44. Largest Divisible Subset | Longest Increasing Subsequence
// leetcode => 368. Largest Divisible Subset
// subset are diffrent from subsequnces
// sub are not following any order
// ref link => https://www.youtube.com/watch?v=Wv6DlL0Sawg
vector<int> largestDivisibleSubset(vector<int>& nums) {
	int n = nums.size();
	vector<int> ans;
	if (n == 0) return ans;

	sort(nums.begin(), nums.end());

	int max = 1;
	vector<int> dp(n + 1, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
				dp[i] = 1 + dp[j];
				if (max < dp[i])
					max = dp[i];
			}
		}
	}

	// now push the answer LTS
	int prev = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == max && (prev % nums[i] == 0 || prev == -1)) {
			ans.push_back(nums[i]);
			max -= 1;
			prev = nums[i];
		}
	}

	return ans;
}
void solve_largestDivisibleSubset() {
	vector<int> nums = {1, 16, 7, 8, 4};
	vector<int> ans = largestDivisibleSubset(nums);
	cout << " The longest divisible subset elements are: ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}

/////////////////////////////////////////////////////////////
// DP 45. Longest String Chain | Longest Increasing Subsequence | LIS
// leetcode => 1048. Longest String Chain
bool compare(string& s1, string& s2) {
	if (s1.size() != s2.size() + 1) return false;

	int first = 0;
	int second = 0;

	while (first < s1.size()) {
		if (second < s2.size() && s1[first] == s2[second]) {
			first ++;
			second ++;
		}
		else first ++;
	}
	return first == s1.size() && second == s2.size();
}

int longestStrChain(vector<string>& arr) {

	int n = arr.size();

	//sort the array wise length of string in ascending order
	sort(arr.begin(), arr.end(), [](string & s1, string & s2) {
		return s1.size() < s2.size();
	});

	vector<int> dp(n + 1, 1);

	int maxi = 1;

	for (int i = 1; i < n; i++) {

		for (int j = 0; j < i; j ++) {

			if (compare(arr[i], arr[j]) && 1 + dp[j] > dp[i]) {
				dp[i] = 1 + dp[j];
				if (dp[i] > maxi)
					maxi = dp[i];
			}
		}
	}
	return maxi;
}

void solve_longestStrChain() {
	vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
	cout << " The length of the longest string chain is : " << longestStrChain(words);
}

//////////////////////////////////////////////////////////////////////////////////
// DP 46. Longest Bitonic Subsequence | LIS
// Bitonic => meaning increasing and descreasing subsequnces || just be increasing subsequnces || just be descreasing subsequnces
int longestBitonicSequence(vector<int>& arr, int n) {
	vector<int> dp1(n , 1);

	for (int i = 1; i < n ; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && 1 + dp1[j] > dp1[i]) {
				dp1[i] = 1 + dp1[j];
			}
		}
	}

	vector<int> dp2(n , 1);
	for (int i = n - 2; i >= 0 ; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i] && 1 + dp2[j] > dp2[i]) {
				dp2[i] = 1 + dp2[j];
			}
		}
	}

	int maxi = 0;
	for (int i = 0; i < n ; i++)
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	return maxi;
}

void solve_longestBitonicSequence() {
	vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
	int n = arr.size();

	cout << "The length of the longest bitonic subsequence is "
	     << longestBitonicSequence(arr, n);
}


///////////////////////////////////////////////////////////////////////////////////
// DP 47. Number of Longest Increasing Subsequences
//leetcode => 673. Number of Longest Increasing Subsequence
int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n , 1);
	vector<int> ct(n , 1);

	int maxi = 0;
	for (int i = 1; i < n ; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i] && 1 + dp[j] > dp[i]) {
				dp[i] = 1 + dp[j];
				//inherit
				ct[i] = ct[j];
			} else if (nums[j] < nums[i] && 1 + dp[j] == dp[i]) {
				//increase the count
				ct[i] = ct[i] + ct[j];
			}
		}

		maxi = max(maxi, dp[i]);
	}


	int nos = 0;
	for (int i = 0; i < n ; i++)
		if (dp[i] == maxi)
			nos += ct[i];
	return nos;
}

void solve_findNumberOfLIS() {
	vector<int> nums = {1, 5, 4, 3, 2, 6, 7, 2};

	cout << "The count of LIS is "
	     << findNumberOfLIS(nums);
}

////////////////////////////// Partition dp ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// DP 48. Matrix Chain Multiplication | MCM | Partition DP Starts 🔥

// 1: start with entire block/array
// 2: Try all partition => run a loop to try all partition
// 3: return the best possible 2 partition
//  0   1   2   3    4
// [10, 20, 30, 40 , 50] => f(1, 4) => return min maultiplication to multiply matrix 1 to matrix 4
//      A   B   C    D

int matrixMultiplication(vector<int> &arr, int n) {
	int i = 1;
	int j = n - 1;
	vector<vector<int>> dp(n , vector<int> (n , -1));

	function<int(int, int)> f = [&](int i, int j) {
		// base condition
		if (i == j) return 0;
		if (dp[i][j] != -1) return dp[i][j];

		int mini = INT_MAX;

		// partition loop
		for (int k = i; k <= j - 1; k++) {
			int ans = arr[i - 1] * arr[k] * arr[j] + f(i, k) + f(k + 1, j);
			mini = min(mini, ans);
		}
		return dp[i][j] = mini;
	};

	return f(i, j);
}

void solve_matrixMultiplication() {
	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();
	cout << "The minimum number of operations is " << matrixMultiplication(arr, n);
}

//////////////////////////////////////////////////////////////////////
// DP 49 same as 48
////////////////////////////////////////////////////////
// DP 50. Minimum Cost to Cut the Stick
// leetcode => 1547. Minimum Cost to Cut a Stick

// Time Complexity: O(N*N*N)
// Space Complexity: O(N*N) + O(N)
int minCost(int n, vector<int>& cuts) {
	// n = length of stick
	int c = cuts.size();
	vector<vector<int>> dp(c + 1, vector<int> (c + 1, -1));
	// modify the cuts array
	cuts.push_back(n);
	cuts.insert(cuts.begin(), 0);
	sort(cuts.begin(), cuts.end());


	function<int(int, int)> f = [&](int i, int j) {
		if (i > j) return 0;
		if (dp[i][j] != -1) return dp[i][j];

		int mini = INT_MAX;
		for (int ind = i; ind <= j; ind++) {
			int ans = cuts[j + 1] - cuts[i - 1] + f(i, ind - 1) + f(ind + 1, j);
			mini = min(mini, ans);
		}
		return dp[i][j] = mini;
	};

	return f(1, c);
}

void solve_minCost() {
	vector<int> cuts = {3, 5, 1, 4};
	int n = 7;
	cout << "The minimum cost incurred: " << minCost(n, cuts);
}

/////////////////////////////////////////////////////////////////////////////////////
// DP 51. Burst Balloons | Partition DP

// TC O(N * N * N)
// SC O(N*N) + O(N)
int maxCoins(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
	nums.push_back(1);
	nums.insert(nums.begin(), 1);

	function<int(int, int)> f = [&](int i, int j) {
		if (i > j) return 0;
		if (dp[i][j] != -1) return dp[i][j];

		int maxi = INT_MIN;
		for (int ind = i; ind <= j; ind++) {
			int ans = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind - 1) + f(ind + 1, j);
			maxi = max(maxi, ans);
		}
		return dp[i][j] = maxi;
	};
	return f(1, n);
}

void solve_maxCoins() {
	vector<int> nums = {3, 1, 5, 8};
	cout << "maximum coins you can collect by bursting the balloons wisely is = " <<  maxCoins(nums);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// DP 52. Evaluate Boolean Expression to True | Partition DP
int evaluateExp(string & exp) {
	ll mod = 1000000007;
	int n = exp.size();
	vector<vector<vector<ll>>> dp(n , vector<vector<ll>> (n , vector<ll> (2, -1)));

	function<ll(int, int, int)> f = [&](int i, int j, int isTrue) -> ll  {
		if (i > j) return 0;
		if (i == j) {
			if (isTrue) return exp[i] == 'T';
			else return exp[i] == 'F';
		}
		if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
		ll ways = 0;
		for (int ind = i + 1; ind <= j - 1; ind += 2) {
			ll lT = f(i, ind - 1, 1);
			ll lF = f(i, ind - 1, 0);
			ll rT = f(ind + 1, j, 1);
			ll rF = f(ind + 1, j, 0);

			if (exp[ind] == '&') {
				if (isTrue) ways = (ways + (rT * lT) % mod) % mod;
				else ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
			} else if (exp[ind] == '|') {
				if (isTrue) ways = (ways + (rT * lT) % mod + (rT * lF) % mod + (rF * lT) % mod) % mod;
				else ways = (ways + (rF * lF) % mod) % mod;
			} else {
				// True  =>  T * F = T , F * T = T
				// False =>  F * F = F , T * T = F
				if (isTrue) ways = (ways + (rT * lF) % mod + (rF * lT) % mod) % mod;
				else ways = (ways + (rF * lF) % mod + (rT * lT) % mod) % mod;
			}
		}

		return dp[i][j][isTrue] = ways;
	};

	return f(0, n - 1, 1);
}

void solve_evaluateExp() {
	string exp = "T&T";
	cout << evaluateExp(exp);
}

////////////////////////////////////////////////////////////////////////////////////////////
// DP 53. Palindrome Partitioning - II | Front Partition 🔥
// leetcode => 132. Palindrome Partitioning II
// TC O(N ^ 2)
// SC O(N) + O(N)
bool isPalidrome(int i, int j, string & s) {
	while (i <= j) {
		if (s[i++] != s[j--]) return false;
	}
	return true;
}
int minCut(string s) {
	int n = s.size();
	vector<int> dp(n , -1);

	function<int(int)> f = [&](int i) {
		if (i == n) return 0;

		if (dp[i] != -1) return dp[i];

		int minCost = INT_MAX;
		for (int j = i; j < n; j++) {
			if (isPalidrome(i, j, s)) {
				int cost = 1 + f(j + 1);
				minCost = min(minCost, cost);
			}
		}

		return dp[i] = minCost;
	};
	return f(0) - 1; // A | B | C | => so we have to remove third partition because it is not possible to do partition if string is not reaming at last
}

void solve_minCut() {
	string s = "aab";
	cout << minCut(s);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// DP 54. Partition Array for Maximum Sum | Front Partition 🔥
// leetcode => 1043. Partition Array for Maximum Sum
int maxSumAfterPartitioning(vector<int>& arr, int k) {
	int n = arr.size();
	vector<int> dp(n, -1);

	function<int(int)> f = [&](int ind) {
		if (ind == n) return 0;
		if (dp[ind] != -1) return dp[ind];
		int len = 0;
		int maxi = INT_MIN;
		int maxAns = INT_MIN;

		for (int j = ind; j < min(ind + k, n); j++) {
			len++;
			maxi = max(maxi, arr[j]);
			int sum = len * maxi + f(j + 1);
			maxAns = max(maxAns, sum);
		}
		return dp[ind] = maxAns;
	};
	return f(0);
}

void solve_maxSumAfterPartitioning() {
	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;
	cout << maxSumAfterPartitioning (arr, k);
}

/////////////////////////////////////////////////////////////
// 84. Largest Rectangle in Histogram
// Brute Force Approach to find largest rectangle area in Histogram
// Time Complexity: O(N*N )
// Space Complexity: O(1)
int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		int minHights = INT_MAX;
		for (int j = i; j < n; j++) {
			minHights = min(minHights, heights[j]);
			maxArea = max(maxArea, minHights * (j - i + 1));
		}
	}

	return maxArea;
}

// optimal solution
// Time Complexity: O( N )
// Space Complexity: O(3N) where 3 is for the stack, left small array and a right small array
int largestRectangleArea1(vector<int>& heights) {
	int n = heights.size();
	stack<int> st;
	int leftSmaller[n], rightSmaller[n];
	for (int i = 0; i < n; i++) {
		while (!st.empty() && heights[st.top()] >= heights[i]) {
			st.pop();
		}

		if (st.empty()) leftSmaller[i] = 0;
		else leftSmaller[i] = st.top() + 1;
		st.push(i);
	}

	// clear the stack to be re-used
	while (!st.empty())
		st.pop();

	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && heights[st.top()] >= heights[i]) {
			st.pop();
		}

		if (st.empty()) rightSmaller[i] = n - 1;
		else rightSmaller[i] = st.top() - 1;
		st.push(i);
	}

	int maxArea = 0;
	for (int i = 0; i < n; i++)
		maxArea = max(maxArea, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));
	return maxArea;
}

void solve_largestRectangleArea() {
	vector<int>  heights = {2, 1, 5, 6, 2, 3};
	// cout << largestRectangleArea(heights);
	cout << largestRectangleArea1(heights);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
// DP:55 Maximum Rectangle Area with all 1's | DP on Rectangle
// DP:56

int main() {
	init_code();

	// solve_fibo_dp();
	// solve_fibo_dp_tab();
	// solve_countDistinctWays();
	// solve_forgJump();
	// solve_forgJump_2();
	// solve_maximumNonAdjacentSum();
	// solve_houseRobber();
	// solve_ninjaTraining();

	// -------------- Grid problems ----------
	// solve_uniquePaths();
	// solve_uniquePathsWithObstacles();
	// solve_minSumPath();
	// solve_minimumPathSum();
	// solve_getMaxPathSum();
	// solve_maximumChocolates();

	// -------------- dp on Subsequneces ----------------
	// solve_subsetSumToK();
	// solve_canPartition();
	// solve_minSubsetSumDifference();
	// solve_findWays();
	// solve_countPartitions();
	// solve_knapsack();
	// solve_minimumElements();
	// solve_targetSum();
	// solve_countWaysToMakeChange();
	// solve_unboundedKnapsack();
	// solve_cutRod();

	// -------------------- dp on substring ----------------------------
	// solve_lcs();
	// solve_lcs_string();
	// solve_longest_common_substring
	// solve_minInsertions();
	// solve_canYouMake();
	// solve_shortestSupersequence();
	// solve_numDistinct();
	// solve_editDistance();
	// solve_isMatch();


	//-------------------- by ans sell stcoks -------------------------
	// solve_maxProfit();
	// solve_maxProfit1();
	// solve_maxProfit2();
	// solve_maxProfit3();
	// solve_maxProfit4();
	// solve_maxProfit5();

	// -------------------- Longest increasing subsequence -------------
	// solve_lengthOfLIS();
	// solve_lengthOfLIS_binary();
	// solve_largestDivisibleSubset();
	// solve_longestStrChain();
	// solve_longestBitonicSequence();
	// solve_findNumberOfLIS();

	// ------------------------ MCM DP | Partition DP ----------------------
	// solve_matrixMultiplication();
	// solve_minCost();
	// solve_maxCoins();
	// solve_evaluateExp();
	// solve_minCut();
	// solve_minCut();
	// solve_maxSumAfterPartitioning();

	// -------------------- histograme -----------------------------
	solve_largestRectangleArea();
}

