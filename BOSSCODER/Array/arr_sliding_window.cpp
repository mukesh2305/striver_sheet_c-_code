#include <bits/stdc++.h>
using namespace std;

// sliding window 1 apporoach
//  return maximum sum of 3 size of subArray
int sliding_window_max_SUM(int arr[], int n, int window_size)
{
	int sum = 0;
	int cnt = 0;
	int mx = INT_MIN;

	// total iteration of for loop is (2 *n + 1);
	for (int i = 0; i < n; i++)
	{
		if (cnt == window_size)
		{
			cnt = 0;
			i -= 2;
			mx = max(mx, sum);
			sum = 0;
		}

		cnt++;
		sum += arr[i];
	}

	mx = max(mx, sum);
	return mx;
}

// sliding window 2nd apporoach
//  return maximum sum of 3 size of subArray
// total teration of for loop is n => timeComplexity O(n);

int sliding_window_max_SUM_1(int arr[], int n, int window_size)
{
	int sum = 0;
	int mx = INT_MIN;
	int cnt = 0;
	int rep;

	for (int i = 0, j = 0; i < n; i++)
	{
		rep = arr[j];
		if (cnt == window_size)
		{
			cnt -= 1;
			mx = max(mx, sum);
			sum -= rep;
			j++;
			rep = arr[j];
		}
		cnt++;
		sum += arr[i];
	}

	mx = max(mx, sum);
	return mx;
}

// sliding window 3 approach same as above just little change in the code
int sliding_window_max_SUM_2(int arr[], int n, int k)
{
	int sum = 0;
	int mx = INT_MIN;
	int i = 0, j = 0;

	while (j < n)
	{
		sum += arr[j];
		if (j - i + 1 < k)
			j++;
		else if (j - i + 1 == k)
		{
			mx = max(mx, sum);
			sum -= arr[i];
			i++;
			j++;
		}
	}

	return mx;
}
//////////////////////////////////////////////////////

// 12, -1, -7, 8, -15, 30, 13, 28
void first_negative_in_every_window(int A[], int n, int k, vector<int> &output)
{
	int i = 0, j = 0;
	vector<int> Q;
	while (j < n)
	{
		if (A[j] < 0)
			Q.push_back(A[j]);
		if (j - i + 1 < k)
			j++;
		else if (j - i + 1 == k)
		{
			if (Q.size() == 0)
				output.push_back(0);
			else
			{
				output.push_back(Q.front());
				if (A[i] == Q.front())
					Q.erase(Q.begin());
			}
			i++;
			j++;
		}
	}
}

//////////////////////////////////////////////////
// count occurence of anagrams in the string
// f o r x x o f r x d o r f

int count_occurence(string s, string w)
{
	unordered_map<char, int> mp;
	int ans = 0;

	// storing the occurence of string in the map
	for (auto c : w)
		mp[c]++;

	int cnt = mp.size();
	int k = w.size();

	int i = 0, j = 0;

	while (j < s.size())
	{

		// calculation part
		if (mp.find(s[j]) != mp.end())
		{
			mp[s[j]]--;
			if (mp[s[j]] == 0)
				cnt--;
		}

		// windows length not achive yet
		if (j - i + 1 < k)
			j++;
		else if (j - i + 1 == k)
		{

			// finding ans
			if (cnt == 0)
				ans++;

			if (mp.find(s[i]) != mp.end())
			{
				mp[s[i]]++;
				if (mp[s[i]] == 1)
					cnt++;
			}

			// sliding windows
			i++;
			j++;
		}
	}

	return ans;
}
void solve_count_occurence()
{
	string word = "aaba";
	string str = "aabarraaba";
	cout << count_occurence(str, word);
}

// return amximum subarray using sliding window
void max_subArray(int arr[], int n, vector<int> &MA, int k)
{
	int i = 0, j = 0;

	int mx = INT_MIN;
	if (k > n)
	{
		MA.push_back(*max_element(arr, arr + n));
		return;
	}

	while (j < n)
	{
		if (j - i + 1 < k)
		{
			mx = max(mx, arr[j]);
			j++;
		}
		else if (j - i + 1 == k)
		{
			// MA.push_back(*max_element(arr + i , arr + j + 1));
			mx = max(mx, arr[j]);
			MA.push_back(mx);

			// this condition is used when first value in the array is max element
			if (mx == arr[i])
				mx = max(arr[i + 1], arr[i + 2]);

			// slide the window
			i++;
			j++;
		}
	}
}

void solve_max_subArray()
{
	// int arr[] = {1 , 3, -1, -3, 5, 3, 6, 7};
	int arr[] = {1, 5, 3, 7, 8, -1, 10};
	// int arr[] = {10, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> MA;

	max_subArray(arr, n, MA, 3);
	for (auto it : MA)
		cout << it << " ";
}

////////////////////////////////////////////////////////////////////////
// variable size sliding window
// calculate largest sliding window whose sum is k

int largest_subArray1(int A[], int N, int k)
{
	vector<int> L;
	int i = 0, j = 0;
	int sum = 0;
	int mx_len = 0;
	int mx = INT_MIN;
	while (j < N)
	{
		L.push_back(A[j]);
		sum += A[j];
		// if sum is = k then do operation
		if (sum > k)
		{
			sum -= L.front();
			L.erase(L.begin());
		}
		if (sum == k)
		{
			int l = L.size();
			mx = max(mx, l);
			sum -= L.front();	// first element minus from sum
			L.erase(L.begin()); // also remove first element from the vector L
		}
		j++;
	}
	if (mx < 0)
		mx = -1;

	return mx;
}

// 2nd way
int largest_subArray2(int A[], int N, int k)
{
	int i = 0, j = 0;
	int sum = 0;
	int mx = INT_MIN;
	while (j < N)
	{
		sum += A[j];


		if (sum > k)
		{
			sum -= A[i];
			i++;
		}
		else if (sum == k)
		{
			mx = max(mx, j - i + 1);
			sum -= A[i];
			i++;
		}
		j++;
	}

	if (mx < 0)
		mx =  0;
	return mx;
}

// 3rd way
int largest_subArray(int A[], int N, int k)
{
	int i = 0, j = 0;
	int sum = 0;
	int mx_len = 0;
	int mx = INT_MIN;
	while (j < N)
	{
		mx_len++;
		sum += A[j];

		if (sum > k)
		{
			sum -= A[i];
			i++;
			mx_len--;
		}
		else if (sum == k)
		{
			mx = max(mx, mx_len);
			sum -= A[i];
			mx_len--;
			i++;
		}
		j++;
	}

	if (mx < 0)
		mx = -1;
	return mx;
}

void solve_largest_subArray()
{
	int A[] = {4, 2, 1, 1, 1, 5};
	int N = sizeof(A) / sizeof(A[0]);
	int k = 5;
	cout << largest_subArray(A, N, k);
}

///////////////////////////////////////////////////////////
// longest substring which containt k unique character
int longest_substring(string S, int k)
{
	int N = S.size();
	int i = 0, j = 0;
	int mx = INT_MIN;
	map<char, int> mp;
	while (j < N) {
		mp[S[j]]++;
		if (mp.size() == k) mx = max(mx, j - i + 1);
		else if (mp.size() > k) {
			while (mp.size() > k) {
				mp[S[i]]--;
				if (mp[S[i]] == 0) mp.erase(S[i]);
				i++;
			}
		}
		j++;
	}

	return mx;
}

void solve_longest_substring() {
	string S = "aabacbebebe";
	int k = 3;
	cout << longest_substring(S, k);
}

// longest substring which containt all the unique character
int longest_subStringAllUnique(string S) {
	int i = 0 , j = 0;
	int N = S.length();
	int mx = INT_MIN;
	int flag = 0;
	map<char, int> mp;
	while (j < N) {
		mp[S[j]]++;

		if (mp.size() == (j - i + 1))
			mx = max(mx, (j - i + 1));

		else if (mp.size() < (j - i + 1)) {
			while (mp.size() < (j - i + 1)) {
				mp[S[i]]--;
				if (mp[S[i]] == 0)
					mp.erase(S[i]);
				i++;
			}
		}
		j++;
	}
	return mx;

}
void solve_longest_sibstringAllUnique() {
	string S = "peryuwwhekw";
	cout << longest_subStringAllUnique(S);
}

// pick toyes
int pick_toyes(string S) {
	int i = 0, j = 0;
	int N = S.length();
	int mx = INT_MIN;
	map<char, int> mp;
	int k = 2;
	while (j < N) {
		mp[S[j]]++;
		if (mp.size() <= k) mx = max(mx, j - i + 1);
		else if (mp.size()  > k) {
			while (mp.size() > k)
			{	mp[S[i]]--;
				if (mp[S[i]] == 0)
					mp.erase(S[i]);
				i++;
			}
		}
		j++;
	}
	return mx;
}
void solve_pick_toyes() {
	string S = "abaccab";
	cout << pick_toyes(S);
}

// find ans for minum substring of
int ans_find(string S, string W) {
	int i = 0, j = 0;
	int N = S.length();
	int mn = INT_MAX;
	map<char, int> mp;
	for (char c : W) mp[c]++;
	int cnt = mp.size(); 

	while (j < N ) {
		if (mp.find(S[j]) != mp.end()) {
			mp[S[j]]--;
			if (mp[S[j]] == 0) cnt--;
		}

		//  slide the j
		if (cnt > 0) j++;
		if (cnt == 0) {
			mn = min(mn, j - i + 1); // candidate for our Answer

			// trying to minimize the window size after getting Answer
			while (cnt == 0) {
				if (mp.find(S[i]) == mp.end()) {
					i++;
					mn = min(mn, j - i + 1); // updating ans
				} else {
					mp[S[i]]++;
					if (mp[S[i]] > 0) {
						i++;
						cnt++;
					} else {
						i++;
						mn = min(mn, j - i + 1); // updating ans
					}
				}
			}
			j++;
		}
	}
	return mn;

}
void solve_find_min() {
	string S = "totmtaptat";
	string W = "tta";
	cout << ans_find(S, W);
}
int main()
{
	// int arr[] = {2, 3, 5, 2, 9, 7, 1};
	// int arr[] = {12, -1, -7, 8, 15, 12, 13, 9};
	// int arr[] = {2, 3, 5,10, 20, 2, 9, 7, 1};
	// int arr[] = {2, 3, 5,10, 5};
	int arr[] = { -1, -1, -7, -15, -15, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout <<  sliding_window_max_SUM(arr, n, 3) << endl;
	// cout <<  sliding_window_max_SUM_1(arr, n, 3) << endl;
	// cout << sliding_window_max_SUM_2(arr, n , 3) << endl;

	// first negative number is every window size
	// vector<int> output;
	// first_negative_in_every_window(arr, n, 3, output);

	// for (auto it : output)
	// 	cout << it << " ";

	//  count occurence of anagrames in the string
	// solve_count_occurence();

	// max_subarray return
	// solve_max_subArray();

	// calculate largest sliding window whose sum is k
	// solve_largest_subArray();
	// solve_longest_substring();


	// longest substring which containt all the character as unique
	// solve_longest_sibstringAllUnique();


	// pick toyes
	// solve_pick_toyes();


	// find min character string on the basis of given Word from string
	solve_find_min();

}
