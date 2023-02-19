#include <bits/stdc++.h>
#define ll long long
using namespace std;
///////////////////////////////////
void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
////////////////////////////////////////////////////
// [1].   => 73. Set Matrix Zeroes
// Link => https://leetcode.com/problems/set-matrix-zeroes/


// 1st Approach
// TC O(N * M)
// SC O(N) + O(M) => for set
void setZeros(vector<vector<int>> & matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    set<int> si;
    set<int> sj;

    // store index of row and column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                si.insert(i);
                sj.insert(j);
            }
        }
    }

    // make zero si rows
    for (auto it : si) {
        for (int i = 0; i < m; i++) {
            matrix[it][i] = 0;
        }
    }

    // make zero sj colums
    for (auto it : sj) {
        for (int j = 0; j < n; j++) {
            matrix[j][it] = 0;
        }
    }
}

// 2nd Approach
// TC O(N * M );
// SC O(1)

void setZeros1(vector<vector<int>> & matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    bool firstRow = false;
    bool firstCol = false;

    // check if first row and column should be set to zero
    // 1st col
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstCol  = true;
            break;
        }
    }

    // 1st row
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRow = true;
            break;
        }
    }

    // Mark rows and columns to be set to zero on left  and top
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // set rows and columns to be zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set first row and column to zero if needed
    if (firstRow) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstCol) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

}

void solve_setZeros() {
    vector<vector<int>> matrix = {
        {1, 1, 1}, {1, 0, 1}, {1, 1, 1}
    };
    // setZeros(matrix);
    setZeros1(matrix);
    for (auto i : matrix) {
        for (auto x : i) cout << x << " ";
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////////////
// [2]. => 118. Pascal's Triangle

// link => https://leetcode.com/problems/pascals-triangle/
// TC O(N * N)
// SC O(N * N)
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    for (int i = 0; i < numRows; i++) {
        vector<int> row;
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                row.push_back(1);
            } else {
                row.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
            }
        }
        triangle.push_back(row);
    }
    return triangle;
}
void solve_generate() {
    int numRows = 5;
    for (auto i : generate(numRows)) {
        for (auto x : i) cout << x << " ";
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////////
// [3]. => 31. Next Permutation
// link => https://leetcode.com/problems/next-permutation/

void nextPermutation(vector<int> & nums) {
    // 1 3 5 4 2
    int n = nums.size();
    int pos = -1;

    // 1st step =>  if i + 1 is greater than i element, that's we are start from n - 2 postion because than we find i + 1
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pos = i;
            break;
        }
    }

    // If no such index exists, the permutation is the last permutation.
    if (pos == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // 2nd step => check any element is greater then position element
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] > nums[pos]) {
            swap(nums[i], nums[pos]);
            break;
        }
    }

    // 3rd step =>     // Reverse the sequence from nums[pos + 1] to its final element.
    sort(nums.begin() + pos + 1, nums.end());
}
void solve_nextPermutation() {
    // vector<int> nums = {1, 2, 3};
    vector<int> nums = {1, 3, 5, 4, 2};
    nextPermutation(nums);
    for (auto i : nums) cout << i << " ";
}

//////////////////////////////////////////////////////////////
// [4].  => 53. Maximum Subarray => (Kadane's Algo)
// link => https://leetcode.com/problems/maximum-subarray/description/
// BrutForce Approach
// TC O(N * N)
int maxSubArray(vector<int> & nums) {
    int mx = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            mx = max(mx, sum);
        }
    }
    return mx;
}

// optimal Approach using => (Kadane's Algo)
// TC O(N)
int maxSubArray1(vector<int> & nums) {
    int mx = INT_MIN;
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        mx = max(mx, sum);
        if (sum < 0) sum = 0;
    }
    return mx;
}

void solve_maxSubArray() {
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    // cout << maxSubArray(nums) << endl;
    cout << maxSubArray1(nums) << endl;
}

///////////////////////////////////////////////
// [5]. => 75. Sort Colors (without using inbuilt sorting method)
// link => https://leetcode.com/problems/sort-colors/description/

// 1st Approach
// TC O(N)
void sortColors(vector<int> & nums) {
    int lo = 0, hi = nums.size() - 1, mid = 0;
    while (mid <= hi) {
        if (nums[mid] == 0) {
            swap(nums[lo], nums[mid]);
            lo++, mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else if (nums[mid] == 2) {
            swap(nums[mid], nums[hi]);
            hi--;
        }
    }
}

// 2nd Approach
// TC O(N)

void sortColors1(vector<int> & nums) {
    int red = 0, white = 0, blue = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] == 0) red++;
        else if (nums[i] == 1) white++;
        else if (nums[i] == 2) blue++;
    }

    for (int i = 0; i < red; i++)
        nums[i] = 0; //  red;
    for (int i = red; i < red + white; i++)
        nums[i] = 1; // white
    for (int i = red + white; i < nums.size(); i++)
        nums[i] = 2; // blue
}

void solve_sortColors() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    // sortColors1(nums);
    sortColors(nums);
    for (auto i : nums) cout << i << " ";
}

/////////////////////////////////////////////////////////////////////////////////////
// [6]. => 121. Best Time to Buy and Sell Stock
// link => https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// TC O(N ^ 2)
int maxProfit(vector<int> & prices) {
    int mxProfit = 0;
    int curr = 0;
    int n = prices.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            curr = prices[j] - prices[i];
            mxProfit = max(mxProfit, curr);
        }
    }
    return mxProfit;
}

// TC O(N)
int maxProfit1(vector<int> & prices) {
    int mxProfit = 0;
    int minPrice = prices[0];
    int n = prices.size();
    int currProfit = 0;
    for (int i = 1; i < n; i++) {
        currProfit = prices[i] - minPrice; // prices[i] =>maximum byuing prices
        mxProfit = max(mxProfit, currProfit);
        minPrice = min(minPrice, prices[i]); // minimum buying prices
    }
    return mxProfit;
}

void solve_maxProfit() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // cout << maxProfit(prices);
    cout << maxProfit1(prices);
}

///////////////////////// Array Part - || ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// [7]. => 48. Rotate Image
// link => https://leetcode.com/problems/rotate-image/

// TC O(N * N)
// SC O(N * N)
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> temp(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[j][n - i - 1] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

// TC O(N * N)
// SC O(1)
void rotate1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
void solve_rotate() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    // rotate(matrix);
    rotate1(matrix);
    for (auto i : matrix) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////////////////
// [8]. => 56. Merge Intervals
// link => https://leetcode.com/problems/merge-intervals/

// Time Complexity: O(NlogN) + O(N). O(NlogN) for sorting and O(N) for traversing through the array.
// Space Complexity: O(N) to return the answer of the merged intervals.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < (int)intervals.size(); i++) {
        if (merged.empty() || merged.back()[1] < intervals[i][0]) {
            vector<int> v = { intervals[i][0], intervals[i][1] };
            merged.push_back(v);
        } else {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }
    return merged;
}

void solve_merge() {
    vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    for (auto i : merge(intervals)) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////////////////
// [9]. => 88. Merge Sorted Array
// link => https://leetcode.com/problems/merge-sorted-array/
//sorted in non-decreasing order

// Time complexity: O(n*log(n))+O(n)+O(n)
// Space Complexity: O(n)
void merge_sorted_array(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    vector<int> nums3(n + m);
    int k = 0;
    for (int i = 0; i < n; i++) {
        nums3[k++] = nums1[i];
    }

    for (int i = 0; i < m; i++) {
        nums3[k++] = nums2[i];
    }

    sort(nums3.begin(), nums3.end());
    k = 0;
    for (int i = 0; i < n; i++) {
        nums1[i] = nums3[k++];
    }

    for (int i = 0; i < m; i++) {
        nums2[i] = nums3[k++];
    }
}

// Time complexity: O(n*logm)
// Space Complexity: O(1)
void merge_sorted_array1(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    int k = n + m - 1;
    for ( int i = 0; i < n; i++) {
        if (nums2.size() > 0 ) {
            if (nums1[i] > nums2[0]) {
                swap(nums1[i], nums2[0]);
            }
            sort(nums2.begin(), nums2.end());
        }
    }
    int j = 0;
    for (int i = n; i <= k; i++) {
        nums1[i] = nums2[j++];
    }
}

// Time complexity: O(n + m)
// Space Complexity: O(1)
void merge_sorted_array2(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    int i = n - 1, j = m - 1, k = n + m - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
void solve_merge_sorted_array() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int n = 3;
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    cout << "Before merge:" << endl;
    for (int i = 0; i < (int)nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    // merge_sorted_array(nums1, m, nums2, n);
    // merge_sorted_array1(nums1, n, nums2, m);
    merge_sorted_array2(nums1, n, nums2, m);
    cout << "After merge:" << endl;
    for (int i = 0; i < (int)nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
}


///////////////////////////////////////////////////////////////////////////
// [10]. => 287. Find the Duplicate Number
// link => https://leetcode.com/problems/find-the-duplicate-number/

// TC O(N ^ 2)
// SC O(1)
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                flag = true;
                break;
            }
        }
        if (flag == true) return nums[i];
    }
    return -1;
}

// Time Complexity:O(Nlogn + N)
int findDuplicate1(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) return nums[i];
    }
    return -1;
}



// Time Complexity:O(N)
// Space Complexity: O(N)
int findDuplicate2(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(nums[i]) == mp.end()) mp[nums[i]]++;
        else return nums[i];
    }
    return -1;
}

// TC O(N)
// TC O(1)
// "Floyd's Tortoise and Hare" algorithm
int findDuplicate3(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow]; // move 1 step
        fast = nums[nums[fast]]; // move 2 steps
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
void solve_findDuplicate() {
    vector<int> nums = {1, 3, 4, 2, 2};
    // cout << findDuplicate(nums); cout << endl;
    // cout << findDuplicate1(nums); cout << endl;
    // cout << findDuplicate2(nums); cout << endl;
    cout << findDuplicate3(nums); cout << endl;
}

///////////////////////////////////////////////////////////////////////////
// [11]. => Missing and repeating numbers
// link => https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

pair<int, int> missingAndRepeating(vector<int> &nums, int n) {
    unordered_map<int, int> freq;
    int mis, rep;
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) mis = i;
        else if (freq[i] > 1) rep = i;
    }
    pair<int, int> p;
    p.first = rep;
    p.second = mis;
    return p;
}

pair<int, int>  missingAndRepeating1(vector<int> & nums, int n) {
    int sum = 0, square_sum = 0;
    int total_sum = (n * (n + 1)) / 2;
    int total_square_sum = (n * (n + 1) * (2 * n + 1)) / 6;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        square_sum += (nums[i] * nums[i]);
    }

    int S  = total_sum - sum;
    int P = total_square_sum - square_sum;
    int mis = (S + P / S) / 2;
    int rep = mis - S;

    pair<int, int> p;
    p.first = rep;
    p.second = mis;
    return p;
}

void solve_missingAndRepeating() {
    vector<int> nums = {3, 1, 2, 5, 3};
    int n = nums.size();
    // pair<int, int> p = missingAndRepeating(nums, n);
    pair<int, int> p = missingAndRepeating1(nums, n);
    cout << " {repating : " <<  p.first << ", missing : " << p.second << " } " << endl;
}

//////////////////////////////////////////////////////////////////////////
// [12]. => Count Inversions
// link => https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


// TC => O(nlog(n))
void merge(long long arr[], long long temp[], int left, int mid, int right, long long int & cnt)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left ; i <= right ; i++)
        arr[i] = temp[i];
}

void merge_Sort(long long arr[], long long temp[], int left, int right, long long int & cnt)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;

        merge_Sort(arr, temp, left, mid, cnt);
        merge_Sort(arr, temp, mid + 1, right, cnt);
        merge(arr, temp, left, mid, right, cnt);
    }

}

long long int inversionCount(long long arr[], long long  N)
{
    long long int cnt = 0;
    long long int temp[N];
    merge_Sort(arr, temp, 0, N - 1, cnt);
    return cnt;
}


void solve_inversionCount() {
    long long arr[] = {3, 2, 1};
    long long n = 3;
    cout << inversionCount(arr, n);
}

/////////////////////////////////////////////////////////////////////////////////////
// [13]. => 74. Search a 2D Matrix
// link =>  https://leetcode.com/problems/search-a-2d-matrix/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();
    int i = 0, j = c - 1;
    while (i < r && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else i++;
    }
    return false ;
}

void solve_searchMatrix() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int  target = 3;
    if (searchMatrix(matrix, target)) cout << " Yes " << endl;
    else cout << " No " << endl;
}

//////////////////////////////////////////////////////////////////////////
// [14]. => 50. Pow(x, n)
// link =>  https://leetcode.com/problems/powx-n/
double myPow(double x, int n) {
    double ans = 1.0;
    long long num = n;
    if (num < 0) num = -1 * num;

    while (num) {
        if (num % 2) { // odd
            ans = ans * x;
            num = num - 1;
        } else { // even
            x  = x * x;
            num = num / 2;
        }
    }

    if (n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}

void solve_myPow() {
    int x = 2.00000, n = 10;
    cout << myPow(x, n);
}

//////////////////////////////////////////////////////////////////////////
// [15]. => 169. Majority Element
// link =>  https://leetcode.com/problems/majority-element/

int majorityElement(vector<int> & nums) {
    int cnt = 0;
    int majority = -1;
    for (auto num : nums) {
        if (cnt == 0) {
            majority = num;
        }

        if (num == majority)
            cnt++;
        else
            cnt--;
    }
    return majority;
}


int majorityElement1(vector<int> & nums) {
    int cnt = 0;
    int majority = -1;
    int maxCount = 0;
    unordered_map<int, int> freq;
    for (auto num : nums) {
        freq[num]++;
        if (freq[num] > maxCount) {
            maxCount = freq[num];
            majority = num;
        }
    }
    return majority;
}
void solve_majorityElement() {
    vector<int> nums = {3, 2, 3};
    cout << majorityElement(nums) << endl;
    // cout << majorityElement1(nums);
}

//////////////////////////////////////////////////////////////////////////
// [16]. => 229. Majority Element II
// link =>  https://leetcode.com/problems/majority-element-ii/description/

// TC o(n)
// SC O(1) // only 2 majority element so it is fixed
vector<int> majorityElementII(vector<int> & nums) {
    vector<int> res;
    int n = nums.size();

    int c1 = 0, c2 = 0, m1 = 0, m2 = 1; // initialize counters c1, c2 and majority elements m1, m2

    for (int i = 0; i < n; i++) {
        if (nums[i] == m1) c1++; // if current element is m1, increment c1
        else if (nums[i] == m2) c2++; // if current element is m2, increment c2
        else if (c1 == 0) m1 = nums[i], c1 = 1; // if c1 is 0, set current element as m1 and increment c1
        else if (c2 == 0) m2 = nums[i], c2 = 1; // if c2 is 0, set current element as m2 and increment c2
        else c1--, c2--; // decrement both c1 and c2
    }

    c1 = c2 = 0; // reset counter
    for (int i = 0; i < n; i++) {
        if (nums[i] == m1) c1++; // count the occurrences of m1
        else if (nums[i] == m2) c2++; // count the occurrences of m2
    }

    if (c1 > n / 3) res.push_back(m1); // if m1 appears more than n/3 times, add it to result
    if (c2 > n / 3) res.push_back(m1); // if m2 appears more than n/3 times, add it to result
    return res;
}

// TC O(n)
// SC O(n)
vector<int> majorityElementII1(vector<int>& nums) {
    unordered_map<int, int> map;
    vector<int> res;
    for (auto num : nums) {
        map[num]++;
    }
    for (auto it : map) {
        if (it.second > nums.size() / 3) {
            res.push_back(it.first);
        }
    }
    return res;
}

void solve_majorityElementII1() {

}

//////////////////////////////////////////////////////////////////////////
// [17]. => 62. Unique Paths
// link =>  https://leetcode.com/problems/unique-paths/

// TC O(m * n)
// SC O(m * n)
int f_uni(int i, int j, vector<vector<int>> & dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];
    int up = f_uni(i - 1, j, dp);
    int left = f_uni(i, j - 1, dp);
    return dp[i][j] = up + left;
}

int uniqPaths(int m , int n) {
    vector<vector<int>> dp(m , vector<int> (n , -1));
    return f_uni(m - 1, n - 1, dp);
}

void solve_uniqPaths() {
    int m = 3, n = 7;
    cout << uniqPaths(m, n);
}


//////////////////////////////////////////////////////////////////////////
// [18]. => 493. Reverse Pairs
// link  => https://leetcode.com/problems/reverse-pairs/

// TC O(n * n)
// SC O(1)
int reversePairs(vector<int> & arr) {
    int Pairs = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > 2 * arr[j]) Pairs++;
        }
    }
    return Pairs;
}


// TC O(n logn)
// SC O(n)
void f_merge(vector<int> & nums, int lo, int mid, int hi, int & cnt) {
    int j = mid + 1;
    for (int i = 0; i <= mid; i++) {
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

    for (int i = 0; i <= hi; i++) nums[i] = temp[i - lo];
}

void mergeSort_rev(vector<int> & nums, int lo, int hi, int & cnt) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergeSort_rev(nums, lo, mid, cnt);
    mergeSort_rev(nums, mid + 1, hi, cnt);
    f_merge(nums, lo, mid, hi, cnt);
}
int reversePairs1(vector<int> & nums) {
    int cnt = 0;
    mergeSort_rev(nums, 0, nums.size() - 1, cnt);
    return cnt;
}
void solve_reversePairs() {
    // vector<int> nums = {1, 3, 2, 3, 1};
    vector<int> nums = {2, 4, 3, 5, 1};
    cout << reversePairs(nums);
}

//////////////////////////////////////////////////////////////////////////
// [19]. => 1. Two Sum
// link  => https://leetcode.com/problems/two-sum/description/

// TC O(n * n)
// TC O(1)
vector<int> twoSum(vector<int> & nums, int target) {
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}
// TC O(n)
// SC O(n)
vector<int> twoSum1(vector<int> & nums, int target) {
    unordered_map<int, int> m;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int c = target - nums[i];
        if (m.find(c) != m.end()) {
            res.push_back(m[c]);
            res.push_back(i);
        }
        m[nums[i]] = i;
    }
    return res;
}

void solve_twoSum() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    vector<int> ans1 = twoSum1(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    cout << ans1[0] << " " << ans1[1] << endl;
}

////////////////////////////////////////////////////////////////////////////////
// [20]. => 18. 4Sum
// link  => https://leetcode.com/problems/4sum/

//  TC O(n ^ 4)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int k = j + 1; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target && i != j && i != k && i != l && j != k && j != l && k != l) {
                        vector<int> quadruplet = {nums[i] , nums[j] , nums[k] , nums[l]};
                        sort(quadruplet.begin(), quadruplet.end());
                        if (find(res.begin(), res.end(), quadruplet) == res.end()) {
                            res.push_back(quadruplet);
                        }
                    }
                }
            }
        }
    }
    return res;
}

// TC O(N^3) + O(N) = O(N^3)
vector<vector<int>> fourSum1(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int k = j + 1, l = n - 1;
            while (k < l) {
                ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[k] + (ll)nums[l];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    while (k < l && nums[k] == nums[k + 1]) k++;
                    while (k < l && nums[l] == nums[l - 1]) l--;
                    k++; l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    return res;
}

void solve_fourSum() {
    vector<int>  nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    // vector<vector<int>> ans = fourSum(nums, target);
    vector<vector<int>> ans = fourSum1(nums, target);
    for (auto i : ans) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////
// [21]. => 128. Longest Consecutive Sequence
// link  => https://leetcode.com/problems/longest-consecutive-sequence/

// TC O(n)
// SC O(n)
int longestConsecutive(vector<int>& nums) {
    set<int> st;
    for (auto n : nums) {
        st.insert(n);
    }

    int count = 0, mxCount = 0;
    for (auto s : st) {
        if (st.find(s - 1) != st.end()) {
            count++;
        } else {
            count = 1;
        }
        mxCount = max(mxCount, count);
    }
    return mxCount;
}


void solve_longestConsecutive() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums);
}


////////////////////////////////////////////////////////////////////////////////
// [22]. => Largest subarray with 0 sum
// link  => https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// TC O(N ^ 2)
// TSC O(1)

int maxLen(vector<int> & nums, int n) {
    int mxLen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == 0) mxLen = max(mxLen, j - i + 1);
        }
    }
    return mxLen;

}

// TC O(N)
// SC O(N)
int maxLen1(vector<int> & nums, int n) {
    unordered_map<int, int> mp; // <sum, index>
    int sum = 0;
    int mxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum == 0) {
            mxLen = max(mxLen, i + 1);
        }
        if (mp.find(sum) != mp.end()) {
            mxLen = max(mxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    return mxLen;
}

void  solve_maxLen() {
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = nums.size();
    // cout << maxLen(nums, n);
    cout << maxLen1(nums, n);
}


////////////////////////////////////////////////////////////////////////////////
// [23]. => Count number of Subarrays with Given XOR
// link  => https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// TC O(n logn) // logn for map
// SC O(n)
int subArrayXor(vector<int> & arr, int x) {
    int count = 0;
    int xorr = 0;
    map<int, int> freq;
    for (int i = 0; i < (int)arr.size(); i++) {
        xorr ^= arr[i];
        if (xorr == x) {
            count++;
        }
        int y = xorr ^ x;
        if (freq.find(y) != freq.end()) {
            count += freq[y];
        }
        freq[xorr]++;
    }
    return count;
}

void solve_subArrayXor() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int x = 6;
    cout << subArrayXor(arr, x);
}


////////////////////////////////////////////////////////////////////////////////
// [24]. => 3. Longest Substring Without Repeating Characters
// link  => https://leetcode.com/problems/longest-substring-without-repeating-characters/

// TC O(n)
// TC O(min(m , n)) // m => is size of character set, n => length of string
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_set<char> st;

    int i = 0, j = 0, mxLen = 0;
    while (j < n) {
        if (st.find(s[j]) == st.end()) {
            mxLen = max(mxLen, j - i + 1);
            st.insert(s[j]);
            j++;
        } else {
            st.erase(s[i]);
            i++;
        }
    }
    return mxLen;
}

void solve_lengthOfLongestSubstring() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
}





int main() {
    init_code();
    // solve_setZeros(); // 1
    // solve_generate(); // 2
    // solve_nextPermutation(); // 3
    // solve_maxSubArray(); // 4
    // solve_sortColors(); // 5
    // solve_maxProfit(); // 6
    // solve_rotate(); // 7
    // solve_merge(); // 8
    // solve_merge_sorted_array(); // 9
    // solve_findDuplicate(); // 10
    // solve_missingAndRepeating(); // 11
    // solve_inversionCount(); // 12
    // solve_searchMatrix(); // 13
    // solve_myPow(); // 14
    // solve_majorityElement(); // 15
    // solve_majorityElementII1(); // 16
    // solve_uniqPaths(); // 17
    // solve_reversePairs(); // 18
    // solve_twoSum(); // 19
    // solve_fourSum(); // 20
    // solve_longestConsecutive(); // 21
    // solve_maxLen(); // 22
    // solve_subArrayXor(); // 23
    solve_lengthOfLongestSubstring(); // 24
}