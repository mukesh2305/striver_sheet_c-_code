#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

////////////////////////////////////////////////////////////////////////////////
// [43]. => N meetings in one room
// link  => https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// TC O(n logn)
// SC O(n)
struct meeting {
	int start, end, pos;
};

bool comparator(meeting m1, meeting m2) {
	if (m1.end < m2.end) return true; // it is in proper order don't sort
	else if (m1.end > m2.end) return false; // sort not in proper order
	else if (m1.pos < m2.pos) return true; // don't sort it is in proper order
	else true;
}
int maxMeetings(vector<int> & start, vector<int> & end, int n) {
	meeting meet[n];
	for (int i = 0; i < n; i++) {
		meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i + 1;
	}

	sort(meet, meet + n, comparator);

	vector<int> ans;

	int limit = meet[0].end;
	ans.push_back(meet[0].pos);

	for (int i = 1; i < n; i++) {
		if (meet[i].start > limit) {
			limit = meet[i].end;
			ans.push_back(meet[i].pos);
		}
	}

	// for (auto i : ans) cout << i << " ";
	return ans.size();
}
void solve_maxMeetings() {
	int n = 6;
	vector<int> start = {1, 3, 0, 5, 8, 5};
	vector<int> end =  {2, 4, 6, 7, 9, 9};
	cout << maxMeetings(start, end, n);
}


////////////////////////////////////////////////////////////////////////////////
// [44]. => Minimum Platforms
// link  => https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

// TC O(2 nlogn + 2n) = O(nlogn)
// SC O(1)
int findPlatform(int arr[], int dep[], int n) {
	sort(arr, arr + n); // arrival Time
	sort(dep, dep + n); // departure Time

	int plate_needed = 1, mxPaltForm = 1;
	int i = 1, j = 0; // i = for arrival, j = departure

	while (i < n && j < n) {
		if (arr[i] <= dep[j]) {
			plate_needed++;
			i++;
		} else if (arr[i] > dep[j]) {
			plate_needed--;
			j++;
		}

		if (plate_needed > mxPaltForm) {
			mxPaltForm = plate_needed;
		}
	}
	return mxPaltForm;
}

void solve_findPlatform() {
	int n = 6;
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

	cout << findPlatform(arr, dep, n);
}

////////////////////////////////////////////////////////////////////////////////
// [45]. => Job Sequencing Problem
// link  => https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

struct Job
{
	int id;  // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
};
bool sort_decending(Job a, Job b) {
	return a.profit > b.profit;
}

// TC O(n logn + n * m) = O(n * m)
// SC O(1)
vector<int> JobScheduling(Job arr[], int n) {

	sort(arr, arr + n, sort_decending);
	int maxi = arr[0].dead; // deadline
	for (int i = 1; i < n; i++) {
		maxi = max(maxi, arr[i].dead);
	}

	int slot[maxi + 1];

	for (int i = 0; i <= maxi; i++) slot[i] = -1;
	int countJobs = 0, jobProfit = 0;

	for (int i = 0; i < n; i++) {
		for (int j = arr[i].dead; j > 0; j--) {
			if (slot[j] == -1) {
				slot[j] = i;
				countJobs++;
				jobProfit += arr[i].profit;
				break;
			}
		}
	}
	return {countJobs, jobProfit};
}

void solve_JobScheduling() {
	Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
	int n = 4;
	vector<int> ans = JobScheduling(arr, n);
	cout << ans[0] << " " << ans[1];
}

////////////////////////////////////////////////////////////////////////////////
// [46]. => Fractional Knapsack
// link  => https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

struct Item {
	int value;
	int weight;
};

bool comp_decending(Item a, Item b) {
	double r1 = (double)a.value / (double)a.value;
	double r2 = (double)b.value / (double)b.value;
	return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n) {
	sort(arr, arr + n, comp_decending);

	int curWeight = 0;
	double finalValue = 0.0;

	for (int i = 0; i < n; i++) {

		if (curWeight + arr[i].weight <= W) {
			curWeight += arr[i].weight;
			finalValue += arr[i].value;
		} else {
			int remain = W - curWeight;
			finalValue += (arr[i].value / (double) arr[i].weight) * (double)remain;
			break;
		}
	}
	return finalValue;
}

void solve_fractionalKnapsack() {
	Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
	int n = 3, W = 50;
	cout << fractionalKnapsack(W, arr, n);
}


////////////////////////////////////////////////////////////////////////////////
// [47]. => Find minimum number of coins that make a given value
// link  => https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/


// TC O(V)
// SC O(1)
int minCoins(int coins[], int n, int V) {
	// sort(coins, coins + n); // neede or not neede it is depends on question
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		while (V >= coins[i]) {
			V -= coins[i];
			ans.push_back(coins[i]);
		}
	}
	// Print result
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "  ";
	cout << endl;
	return ans.size();
}

void solve_minCoins() {
	int coins[] =  {9, 6, 5, 1};
	int n = sizeof(coins) / sizeof(coins[0]);
	int V = 11;
	cout << "Minimum coins required is "
	     << minCoins(coins, n, V);
}

////////////////////////////////////////////////////////////////////////////////
// [48 == 43]. => N meetings in one room
// link  => https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


int main() {
	init_code();
	// solve_maxMeetings(); // 43
	// solve_findPlatform(); // 44
	// solve_JobScheduling(); // 45
	// solve_fractionalKnapsack(); // 46
	// solve_minCoins(); // 47
	
}