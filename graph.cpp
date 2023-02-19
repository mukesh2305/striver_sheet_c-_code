#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

//////////////////////////////////////////////////////////

//  1 => // Flood fill Algorithm
//  ref : https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

// 2 => 733. Flood Fill =>  leetcode

////////////////////////////////////////////////
// Undirected Graph Representations using Adjacency Matrix

void solve_graph_adjacency_matrix() { // this is very costly operation
	int n , m;
	cin >> n >> m;
	// adjacency matrix for undirected graph
	// time complexity: O(n)
	// space complexity : O(n ^ n)
	int adj[n + 1][n  + 1];

	// assign 0 to all first
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++)
			adj[i][j] = 0;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1; // 1 is weight of edge
		adj[v][u] = 1; // this statement will be removed in case of directed graph
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) cout << adj[i][j] << " ";
		cout << endl;
	}
}

void solve_graph_adjacency_list() {
	// time complexity: O(n)
	// space complexity : O(2 * m(edges))
	// we are creating array of 6 size;

	// in directed graph space complexity => O(m (edges)) // we are not consuming 2 edgs

	int n , m ;
	cin >> n >>  m;

	vector<int> adj[n + 1]; // adjacency list

	for (int i = 0; i < m ; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // this statement will be removed in case of directed graph
	}

// print
	for (int i = 0; i < n + 1; i++) {
		cout << "\n Adjacency list of vertex " << i
		     << "\n head ";
		for (auto x : adj[i]) cout << x << " ";
		cout << endl;
	}
}

void solve_graph_adjacency_list_with_weight() {
	int n , m ;
	cin >> n >>  m;

	vector<pair<int, int>> adj[n + 1]; // adjacency list

	for (int i = 0; i < m ; i++) {
		int u , v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // this statement will be removed in case of directed graph
	}
}
/////////////////////////////////////////////////////
// G-4. What are Connected Components ?
///////////////////////////////////////////////////////////////////
// G-5. Breadth-First Search (BFS) | C++
// Function to return Breath First Traversal of given graph.
// TC O(N) + O(2E)
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
	// V vertices/Node
	int vis[V] = {0}; // 0 based graph
	vis[0]  = 1;
	queue<int> q;
	q.push(0);

	vector<int> bfs;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		bfs.push_back(node);

		for (auto it : adj[node]) { // this will run O(2E) edges
			if (!vis[it]) {
				vis[it] = 1;
				q.push(it);
			}
		}
	}
	return bfs;
}

void addEdge_bfs(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printAns_bfs(vector<int> &ans) {
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}
void solve_bfsOfGraph() {
	vector<int> adj[6];

	addEdge_bfs(adj, 0, 1);
	addEdge_bfs(adj, 1, 2);
	addEdge_bfs(adj, 1, 3);
	addEdge_bfs(adj, 0, 4);

	vector<int> ans = bfsOfGraph(5, adj); // 5 is total nodes => 0 1 2 3 4 // start from 0
	printAns_bfs(ans);
}

///////////////////////////////////////////////////////////////////////////////////////////
// G-6. Depth-First Search (DFS) | C++

// SC O(N) + O(N) + O(N)  = O(N)
// TC O(N) + O(2E) // time complexity for undirected graph
// TC O(N) + O(E) // time complexity for directed graph
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
	vis[node] = 1;
	ls.push_back(node);

	// traverse all its neighbours
	for (auto it : adj[node]) {
		if (!vis[it])
			dfs(it, adj, vis, ls);
	}
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
	int vis[V] = {0};
	int start = 0; // 0 based indexing

	// create list to store dfs
	vector<int> ls;

	// call dfs for starting node
	dfs(start, adj, vis, ls);
	return ls;
}
void addEdge_dfs(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printAns_dfs(vector<int> &ans) {
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}
void solve_dfsOfGraph() {
	vector<int> adj[6];

	addEdge_dfs(adj, 0, 2);
	addEdge_dfs(adj, 2, 4);
	addEdge_dfs(adj, 0, 1);
	addEdge_dfs(adj, 0, 3);

	vector<int> ans = dfsOfGraph(5, adj); // 5 is total nodes => 0 1 2 3 4 // start from 0
	printAns_dfs(ans);
}

/////////////////////////////////////////////////////////////////////////////////////
// G-7. Number of Provinces | C++
// Number of Provinces
// link => https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

void dfs_for_province(int node, int vis[], vector<int> adjLs[]) {
	vis[node] = 1;

	for (auto it : adjLs[node])
		if (!vis[it])
			dfs_for_province(it, vis, adjLs);
}

// SC => O(N){VIS array} + O(N){recursion stack space}
// TC => O(N) + O(V + 2 * E) // nearly O(N) time complexity // V -> vertices/node  E -> edge
int numberOfProvince(vector<vector<int>> adj, int V) {
	// convert adj matrix  into adj list

	vector<int> adjLs[V];

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (adj[i][j] == 1 && i != j) {
				// cout << i << " " << j <<  endl;
				adjLs[i].push_back(j);
				adjLs[j].push_back(i);
			}
		}
	}

	// cout << "ennnnnnnnnn" << endl << endl;


	// cout << " this ";
	// for (int i = 0; i < V; i++) {
	// 	cout << endl <<  "start " << i << " -> ";
	// 	for (auto it : adjLs[i] ) cout << it << " ";

	// }
	// cout << " end" << endl;

	int vis[V] = {0};
	int cnt = 0;

	for (int  i = 0; i < V; i++) {
		if (vis[i] == 0) {
			cnt++;
			dfs_for_province(i, vis, adjLs);
		}
	}
	return cnt;
}

void solve_numberOfProvince() {
	vector<vector<int>> adj = {
		{1, 0, 1},
		{0, 1, 0},
		{1, 0, 1}
	};

	int V = 3;
	cout << numberOfProvince(adj, V);
}

//////////////////////////////////////////////////////////////////////////////
// G-8. Number of Islands | Number of Connected Components in Matrix | C++
//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
// 	TC O(N^2)
// 	SC O(N^2)
void dfs_numsIslands(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int n, int m) {
	vis[row][col] = 1;
	queue<pair<int, int>> q;
	q.push({row, col});

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		// visit all the in the all the 8 direction
		for (int deltarow = -1; deltarow <= 1; deltarow++) {
			for (int deltacol = -1; deltacol <= 1; deltacol++) {
				int nrow = row + deltarow; // neibhghour row => all 8 direction
				int ncol = col + deltacol; // neibhghour col => all 8 direction
				if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
					vis[nrow][ncol] = 1;
					q.push({nrow, ncol});
				}
			}
		}
	}
}
int numIslands(vector<vector<char>> &grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> vis(n , vector<int> (m , 0));

	int cnt = 0;
	for (int row = 0; row < n ; row++) {
		for (int col = 0; col < m ; col ++) {
			if (!vis[row][col] && grid[row][col] == '1') {
				cnt++;
				dfs_numsIslands(row, col, vis, grid, n , m);
			}
		}
	}
	return cnt;
}
void solve_numIslands() {
	vector<vector<char>> grid = {{'0', '1'}, {'1', '0'}, {'1', '1'}, {'1', '0'}};
	cout << numIslands(grid);
}

///////////////////////////////////////////////////////////////////////
// G-9. Flood Fill Algorithm | C++
//link =>  https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm

void dfs_floodFill(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans,
                   int iniColor, int newColor, int deltaRow[], int deltaCol[]) {

	ans[row][col] = newColor;
	int n = image.size();
	int m = image[0].size();
	for (int i = 0; i < 4; i++) {
		int nrow = row + deltaRow[i];
		int ncol = col + deltaCol[i];
		if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
		        image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
			dfs_floodFill(nrow, ncol, image, ans, iniColor, newColor, deltaRow , deltaCol);
		}
	}
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
	int iniColor = image[sr][sc];
	vector<vector<int>> ans = image;
	int deltaRow[] = { -1, 0, +1, 0};
	int deltaCol[] = {0, +1, 0, -1};
	dfs_floodFill(sr, sc, image, ans, iniColor, newColor, deltaRow, deltaCol);
	return ans;
}
void solve_floodFill() {
	vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	int sr = 1, sc = 1, newColor = 2;
	for (auto i : floodFill(image, sr, sc, newColor)) {
		for (auto x : i) cout << x << " ";
		cout << endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
// G-10. Rotten Oranges | C++
// we are required minimum time , so it goes in the same time all for direction so we are using BFS algo
// link => https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

// TC O(N * M)
// SC O(N * M)

int orangeRotting(vector<vector<int>> &grid) {
	int n = grid.size();
	int m = grid[0].size();

	// {{row, col}, time}
	queue<pair<pair<int, int>, int>> q;
	int vis[n][m];
	int cntFresh = 0; // check how many fresh oranges in the grid
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			if (grid[i][j] == 2) {
				q.push({{i, j}, 0});
				vis[i][j] = 2;
			} else {
				vis[i][j] = 0;
			}

			if (grid[i][j] == 1) cntFresh++;
		}
	}

	int cnt = 0; // check how many fresh oranges are rotten
	int mxTime = 0;
	int deltaRow[] = { -1, 0, +1, 0};
	int deltaCol[] = {0, +1, 0, -1};

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int time = q.front().second;
		q.pop();

		mxTime = max(mxTime, time);
		for (int i = 0; i < 4; i++) {
			int nrow = row + deltaRow[i];
			int ncol = col + deltaCol[i];
			if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
				q.push({{nrow, ncol}, time + 1});
				vis[nrow][ncol] = 2;
				cnt++;
			}
		}
	}

	if (cnt != cntFresh) return -1; // if any fresh is remaning in the grid to rotten then return -1
	return mxTime;
}
void solve_orangeRotting() {
	vector<vector<int>> grid = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
	cout << orangeRotting(grid);
}

////////////////////////////////////////////////////////////////////////////////
// G-11. Detect a Cycle in an Undirected Graph using BFS | C++

// TC O(N + 2E) + O(N)
// TC O(N)

bool detectBFS(int src, vector<int> adj[], int vis[]) {
	vis[src] = 1;

	// {src, parent} 1 -> 2 // 1 = parent and  2 = src
	queue<pair<int, int>> q;
	q.push({src, -1}); // parent is -1 for first node

	while (!q.empty()) {
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();

		for (auto adjNode : adj[node]) {
			if (!vis[adjNode]) {
				vis[adjNode] = 1;
				q.push({adjNode, node});
			} else {
				// if adjacent node is visited and is not it's own parent node
				if (parent != adjNode) {
					// yes it is a cycle
					return true;
				}
			}
		}
	}
	return false;

}
bool isCycleBFS(int V, vector<int> adj[]) {
	int vis[V] = {0};

	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			if (detectBFS(i, adj, vis)) return true;
		}
	}
	return false;
}
void solve_isCycle_BFS() {
	int V = 5;
	// int E = 5;
	vector<int> adj[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
	bool ans = isCycleBFS(V, adj);
	if (ans)
		cout << "1\n";
	else
		cout << "0\n";// } Driver Code Ends
}

////////////////////////////////////////////////////////////////////////////////
// G-12. Detect a Cycle in an Undirected Graph using DFS | C++
bool detectDFS(int src, int parent, vector<int> adj[], int vis[]) {
	vis[src] = 1;

	for (auto adjNode : adj[src]) {
		if (!vis[adjNode]) {
			if (detectDFS(adjNode, src, adj, vis) == true)
				return true;
		} else {
			if (parent != adjNode) return true;
		}
	}
	return false;
}
bool isCycleDFS(int V, vector<int> adj[]) {
	int vis[V] = {0};
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			if (detectDFS(i, -1, adj, vis)) return true;
		}
	}
	return false;
}
void solve_isCycle_DFS() {
	int V = 5;
	// int E = 5
	vector<int> adj[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
	bool ans = isCycleDFS(V, adj);
	if (ans)
		cout << "1\n";
	else
		cout << "0\n";// } Driver Code Ends
}

////////////////////////////////////////////////////////////////////////
// G-13. Distance of nearest cell having 1 | 0/1 Matrix

vector<vector<int>> nearest(vector<vector<int>> &grid) {
	int n = grid.size();
	int m = grid[0].size();

	int vis[n][m];
	vector<vector<int>> dis(n, vector<int> (m , 0));

	// {{row, col}, steps}
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			if (grid[i][j] == 1) {
				vis[i][j] = 1;
				q.push({{i, j}, 0});
			}  else {
				vis[i][j] = 0;
			}
		}
	}

	int deltaRow[] = { -1, 0, +1, 0};
	int deltaCol[] = { 0, +1, 0, -1};
	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int steps = q.front().second;
		q.pop();

		dis[row][col] = steps;

		for (int i = 0; i < 4; i++) {
			int nrow = row + deltaRow[i];
			int ncol = col + deltaCol[i];
			if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0) {
				vis[nrow][ncol] = 1;
				q.push({{nrow, ncol}, steps + 1});
			}
		}
	}
	return dis;
}
void solve_nearest() {
	vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
	for (auto it : nearest(grid)) {
		for (auto x : it) cout << x << " ";
		cout << endl;
	}
}

/////////////////////////////////////////////////////////////////////////////
// G-14. Surrounded Regions | Replace O's with X's | C++
// link => https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
// TC O(N) + O(N * M) * 4
// SC O(N * M)

void dfs_fill(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int deltarow[], int deltacol[]) {
	vis[row][col] = 1;
	int n = mat.size();
	int m = mat[0].size();

	for (int i = 0; i < 4 ; i++) {
		int nrow = row + deltarow[i];
		int ncol = col + deltacol[i];
		if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
			dfs_fill(nrow, ncol, vis, mat, deltarow, deltacol);
		}
	}
}
vector<vector<char>> fill(int n , int m , vector<vector<char>> &mat) {
	vector<vector<int>> vis(n , vector<int> (m , 0));
	int deltarow[] = { -1, 0, +1, 0};
	int deltacol[] = {0, +1, 0, -1};
// 1 : mark first last row and col who containt O and connected O to vis so we cannot convert that to X
	// traverse first row and last row
	for (int j = 0; j < m; j++) {

		// first row
		if (!vis[0][j] && mat[0][j] == 'O') {
			dfs_fill(0, j, vis, mat, deltarow, deltacol);
		}

		// last row
		if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
			dfs_fill(n - 1, j, vis, mat, deltarow, deltacol);
		}
	}

	// traverse first col and last col
	for (int i = 0; i < n; i++) {

		// first col
		if (!vis[i][0] && mat[i][0] == 'O') {
			dfs_fill(i, 0, vis, mat, deltarow, deltacol);
		}

		// last col
		if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
			dfs_fill(i, m - 1, vis, mat, deltarow, deltacol);
		}
	}

// 2 : mark all not visited O into X
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			if (!vis[i][j] && mat[i][j] == 'O') {
				vis[i][j] = 1;
				mat[i][j] = 'X';
			}
		}
	}
	return mat ;
}
void solve_fill() {
	int n = 5, m = 4;
	vector<vector<char>> mat = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
		{'X', 'X', 'O', 'O'}
	};
	for (auto it : fill(n, m , mat)) {
		for (auto x : it) cout << x << " ";
		cout << endl;
	}
}

///////////////////////////////////////////////////////////
// G-15. Number of Enclaves | Multi-source BFS | C++
// link => https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
int numberOfEnclaves(vector<vector<int>> &grid) {
	// {row , col}
	queue<pair<int, int>> q;
	int n = grid.size();
	int m = grid[0].size();

	int vis[n][m] = {0};
// 1 : mark first last row and col who containt O and connected O to vis so we cannot convert that to X

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			// first and last row and col
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
				if (grid[i][j] == 1) {
					vis[i][j] = 1;
					q.push({i, j});
				}
			}
		}
	}

	int deltarow[] = { -1, 0, +1, 0};
	int deltacol[] = {0, +1, 0, -1};
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrow = row + deltarow[i];
			int ncol = col + deltacol[i];
			if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
				vis[nrow][nrow] = 1;
				q.push({nrow, ncol});
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			if (!vis[i][j] && grid[i][j] == 1) cnt++;
		}
	}
	return cnt;
}
void solve_numberOfEnclaves() {
	vector<vector<int>> grid = {
		{0, 0, 0, 0},
		{1, 0, 1, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0}
	};
	cout << numberOfEnclaves(grid);
}

//////////////////////////////////////////////////////////////////////////////////////
// G-16. Number of Distinct Islands | Constructive Thinking + DFS | C++
// link => https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
// TC => O(n * m * log(n * m)   + (n * m  * 4))
// SC => O(n * m)
void dfs_count_dist_islands(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0 ) {
	// row0 and col0 are the intial(bas) points for every islands
	vis[row][col] = 1;
	vec.push_back({row - row0, col - col0});

	int n = grid.size();
	int m = grid[0].size();

	int deltarow[] = { -1, 0, +1, 0};
	int deltacol[] = {0, +1, 0, -1};

	for (int i = 0; i < 4; i++) {
		int nrow = row + deltarow[i];
		int ncol = col + deltacol[i];
		if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
			dfs_count_dist_islands(nrow, ncol, vis, grid, vec, row0, col0);
		}
	}

}
int countDistinctIslands(vector<vector<int>> &grid) {
	int n = grid.size();
	int m = grid[0].size();

	set<vector<pair<int, int>>> st;
	vector<vector<int>> vis(n, vector<int> (m , 0));
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && grid[i][j] == 1) {
				vector<pair<int, int>> vec;
				dfs_count_dist_islands(i, j, vis, grid, vec, i, j);
				st.insert(vec);
			}
		}
	}

	return st.size();
}
void solve_countDistinctIslands() {
	vector<vector<int>> grid = {
		{1, 1, 0, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 1, 1},
		{0, 0, 0, 1, 1}
	};
	cout << countDistinctIslands(grid);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// G-17. Bipartite Graph | BFS
// link => https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

// linear graph with no cycle are always Biaprtite grph
// any graph with even cycle length can also be bipartite graph
//- any graph with odd cycle length can not be bipartite
bool check_bipartite_bfs(int start, int V, vector<int> adj[], int color[]) {
	queue<int> q;
	q.push(start);
	color[start] = 0; // 0 and 1 are color we are starting with 0

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto adjNode : adj[node]) {
			if (color[adjNode] == -1) {
				color[adjNode] = !color[node]; // color with opposite node
				q.push(adjNode);
			} else if (color[adjNode] == color[node]) {
				return false;
			}
		}
	}

	return true;
}
// same as BFS Time complexity it takes
bool isBipartite_bfs(int V, vector<int> adj[]) {
	int color[V];
	for (int i = 0; i < V; i++) color[i] = -1;

	// this for loop if for multiple components
	for (int i = 0; i < V; i++) {
		if (color[i] == -1) {
			if (check_bipartite_bfs(i, V, adj, color) == false)
				return false;
		}
	}
	return true;
}
void solve_isBipartite_bfs() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];
	for (int i = 0; i < E; i++) {
		int u, v ;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool ans = isBipartite_bfs(V, adj);
	if (ans) cout << "1\n";
	else cout << "0\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
// G-17. Bipartite Graph | DFS
// link => https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

// linear graph with no cycle are always Biaprtite grph
// any graph with even cycle length can also be bipartite graph
//- any graph with odd cycle length can not be bipartite

bool check_bipartite_dfs(int node, int col, vector<int> adj[], int color[]) {
	color[node] = col;

	for (auto adjNode : adj[node]) {
		if (color[adjNode] == -1) {
			if (check_bipartite_dfs(adjNode, !col, adj, color) == false)
				return false;
		} else {
			if (color[adjNode] == col)
				return false;
		}
	}

	return true;
}

// same as DFS Time complexity it takes
bool isBipartite_dfs(int V, vector<int> adj[]) {
	int color[V];
	for (int i = 0; i < V; i++) color[i] = -1;

	// this for loop if for multiple components
	for (int i = 0; i < V; i++) {
		if (color[i] == -1) {
			if (check_bipartite_dfs(i, 0, adj, color) == false)
				return false;
		}
	}
	return true;
}
void solve_isBipartite_dfs() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];
	for (int i = 0; i < E; i++) {
		int u, v ;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool ans = isBipartite_dfs(V, adj);
	if (ans) cout << "1\n";
	else cout << "0\n";
}

///////////////////////////////////////////////////////////////////////////////////
// G-19. Detect cycle in a directed graph using DFS
bool dfs_isCyclic_directed(int node, int vis[], int pathVis[], vector<int> adj[]) {
	vis[node] = 1;
	pathVis[node] = 1;

	// traverse for adjNodes
	for (auto it : adj[node]) {
		// when the node is not visited
		if (!vis[it]) {
			if (dfs_isCyclic_directed(it, vis, pathVis, adj) == true)
				return true;
		}
		// if the node has been previously visited
		// but it has to be visited on the same path
		else if (pathVis[it] == 1)
			return true;
	}
	pathVis[node] = 0;
	return false;
}
bool isCyclic_directed(int V, vector<int> adj[]) {
	int vis[V] = {0};
	int pathVis[V] = {0};

	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			if (dfs_isCyclic_directed(i, vis, pathVis, adj) == true)
				return true;
		}
	}
	return false;
}
void solve_isCyclic_directed() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];

	for (int i = 0; i < V; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	cout << "output : " <<  isCyclic_directed(V, adj);
}

//////////////////////////////////////////////////////////////////////////////////////////
// G-20. Find Eventual Safe States - DFS
// directed graph
// 0 based graph => meand node start with 0 to V - 1
// Terminal node = outgoing edge are 0
// safe node = all the path goes to Terminal node

// any node which part of the cycle can and connect to cycle never be safe node
// any one who leades to cycle can never be a safe node

//////////////////// approach1 /////////////////////////////////////
bool dfs_eventualSafeNodes(int node, int vis[], int pathVis[], int check[], vector<int> adj[]) {
	vis[node] = 1;
	pathVis[node] = 1;
	check[node] = 0;

	// traverse for adjacent nodes
	for (auto it : adj[node]) {
		// when the node is not visited
		if (!vis[it]) {
			if (dfs_eventualSafeNodes(it, vis, pathVis, check, adj) == true) {
				check[node] = 0;
				return true;
			}
		}
		// if the node has been previously visited
		//  but it has to be visited on the same path
		else if (pathVis[it] == 1) {
			check[node] = 0;
			return true;
		}
	}

	check[node] = 1;
	pathVis[node] = 0;
	return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
	int vis[V] = {0};
	int pathVis[V] = {0};
	int check[V] = {0};
	vector<int> safeNodes;

	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs_eventualSafeNodes(i, vis, pathVis, check , adj);
		}
	}

	for (int i = 0; i < V; i++) {
		if (check[i] == 1) safeNodes.push_back(i);
	}
	return safeNodes;
}

/////////////////////////// 2nd approach /////////////////////////////
bool dfs_eventualSafeNodes1(int node, int vis[], int pathVis[], int check[], vector<int> adj[]) {
	vis[node] = 1;
	pathVis[node] = 1;
	check[node] = 0;

	// traverse for adjacent nodes
	for (auto it : adj[node]) {
		// when the node is not visited
		if (!vis[it]) {
			if (dfs_eventualSafeNodes1(it, vis, pathVis, check, adj) == true) {
				// check[node] = 0;
				return true;
			}
		}
		// if the node has been previously visited
		//  but it has to be visited on the same path
		else if (pathVis[it] == 1) {
			// check[node] = 0;
			return true;
		}
	}

	check[node] = 1;
	pathVis[node] = 0;
	return false;
}
vector<int> eventualSafeNodes1(int V, vector<int> adj[]) {
	int vis[V] = {0};
	int pathVis[V] = {0};
	int check[V] = {0};
	vector<int> safeNodes;

	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs_eventualSafeNodes1(i, vis, pathVis, check , adj);
		}
	}

	for (int i = 0; i < V; i++) {
		if (check[i] == 1) safeNodes.push_back(i);
	}
	return safeNodes;
}


/////////////////////////// 3nd approach //////////////////////////////////
bool dfs_eventualSafeNodes2(int node, int vis[], int pathVis[], vector<int> adj[]) {

	vis[node] = 1;
	pathVis[node] = 1;
	// check[node] = 0;
	// traverse for adjacent nodes
	for (auto it : adj[node]) {
		// when the node is not visited
		if (!vis[it]) {
			if (dfs_eventualSafeNodes2(it, vis, pathVis, adj) == true) {
				// check[node] = 0;
				return true;
			}
		}
		// if the node has been previously visited
		//  but it has to be visited on the same path
		else if (pathVis[it] == 1) {
			// // check[node] = 0;
			return true;
		}
	}

	// check[node] = 1;
	pathVis[node] = 0;
	return false;
}
vector<int> eventualSafeNodes2(int V, vector<int> adj[]) {
	int vis[V] = {0};
	int pathVis[V] = {0};
	// int check[V] = {0};
	vector<int> safeNodes;

	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs_eventualSafeNodes2(i, vis, pathVis, adj);
		}
	}

	for (int i = 0; i < V; i++) {
		if (pathVis[i] == 0) safeNodes.push_back(i);
	}
	return safeNodes;
}

void solve_eventualSafeNodes() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];
	// V => count of total number of verticis
	// E => count of total number of edges

	for (int i = 0; i < E; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	// for(auto it : eventualSafeNodes(V, adj))
	// 	cout << it << " ";

	// cout << endl ;
	// for(auto it : eventualSafeNodes1(V, adj))
	// 	cout << it << " ";

	cout << endl ;
	for (auto it : eventualSafeNodes2(V, adj))
		cout << it << " ";
}

/////////////////////////////////////////////////////////////////////////////////////////
// G-21. Topological Sort Algorithm | DFS
// it apply on any graph which directed acyclic graph(DAG) => any directed graph which does not have cycle
// Topological sorting : linear orddering of vertices such that if there is edge between u and v , u apperas before v
// 5 -> 0
// 4 -> 0
// 5 -> 2
// 2 -> 3
// 3 -> 1
// 4 -> 1
// 5 4 2 3 1 0 => this is topologycal sorting
// 4 5 2 3 1 0 => this is also valid topological sorting algo

// in cycle topologycal sorting is not possible
void dfs_topsort(int node, int vis[], stack<int> & st, vector<int> adj[]) {
	vis[node] = 1;

	for (auto it : adj[node]) {
		if (!vis[it])
			dfs_topsort(it, vis, st, adj);
	}

	st.push(node);
}
vector<int> topsort(int V, vector<int> adj[]) {
	int vis[V] = {0};
	stack<int> st;

	for (int i = 0; i < V; i++) {
		if (!vis[i])
			dfs_topsort(i, vis, st, adj);
	}


	vector<int> ans;
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}
void solve_topsort() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];
	for (int i = 0; i < E; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (auto it : topsort(V, adj)) cout << it << " ";
	// this is vector that written by topsort // after this it will check by GeeksforGeeks and if it is topsort than it will return 1; if not than return 0
}

/////////////////////////////////////////////////////////////////////////////////
// G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS
// topologycal sort using kahn's algo
// topologycal sort only workes in the directed graph
// indegree :=> number of incoming edge to the node is called indegree

// 1 : figure out indgree of all the nodes
// 2 : insert all the node who have indgree 0 into the queue
// 3 : take thame out of the queue & just reduce the indgree of adjcent nodes
// TC O(V + E)
vector<int> topsort_kahns(int V, vector<int> adj[]) {
	int indgree[V] = {0};

	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			indgree[it]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indgree[i] == 0) q.push(i);
	}

	vector<int> topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		topo.push_back(node);

		for (auto it : adj[node]) {
			indgree[it]--;
			if (indgree[it] == 0) q.push(it);
		}
	}

	return topo;
}
void solve_topsort_kahns() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];
	for (int i = 0; i < V; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (auto it : topsort_kahns(V, adj)) cout << it << " ";
	// this is vector that written by topsort // after this it will check by GeeksforGeeks and if it is topsort than it will return 1
	// if not than return 0
}

///////////////////////////////////////////////////////////////////////////////////////////////
// G-23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm | BFS
// same problem G : 19, just using difffrent algorithem
// toposort only applicable in directed acyclic graph
// if toposort algo store elements in the vector it has less total number of nodes than it has cycle , if element in the vector and V
// verticies size are same than it does ot have cycle

bool isCyclic_directed_kahns(int V, vector<int> adj[]) {
	int indegree[V] = {0};

	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	int cnt = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cnt++;

		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0) q.push(it);
		}
	}

	if (cnt == V) return false; // if cnt == V than it does not have cycle
	return true; // less than V count than it has cycle
}
void solve_isCyclic_directed_kahns() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];

	for (int i = 0; i < V; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	cout << "output : " <<  isCyclic_directed_kahns(V, adj);

}

/////////////////////////////////////////////////////////////////////////////
// G-24. Course Schedule I and II | Pre-requisite Tasks | Topological Sort
// topological sort possible when it is directed ACyclic graph(DAG)
// 1 0 // in order to perform task 0 you should have perform task 1 => 1 0
// 2 1 // in order to perform task 1 you should have perform task 2 => 2 1 0
// 3 2 // in order to perform task 2 you should have perform task 3 => 3 2 1 0  // this is final
// total => 3 2 1 0

bool isPossible(int V, vector<pair<int, int>> & prerequisites) {
	vector<int> adj[V];

	for (auto it : prerequisites) {
		adj[it.first].push_back(it.second);
	}

	int indegree[V] = {0};

	for (int i = 0; i < V; i++) {
		for (auto it : adj[i])
			indegree[it]++;
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	int cnt = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cnt++;

		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}

	if (cnt == V) return true;
	return false;
}

void solve_isPossible() {
	int V = 4; // vertices(Nodes)
	// int E = 3; // Edges
	vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 1}};
	// vector<pair<int, int>> prerequisites =  {{1, 0}, {0, 1}};
	cout << isPossible(V, prerequisites) << endl;
}

// Course Schedule => Geeks for Geeks
vector<int> findOrder(int V, vector<vector<int>> pre) {
	vector<int> adj[V];
	for (auto it : pre) {
		adj[it[1]].push_back(it[0]);
	}

	int indg[V] = {0};
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			indg[it]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);

		for (auto it : adj[node]) {
			indg[it]--;
			if (indg[it] == 0)
				q.push(it);
		}
	}

	if ((int)topo.size() == V) return topo;
	return {};
}
void solve_findOrder() {
	int V = 2;
	// int E = 1;
	vector<vector<int>> prerequisites = {{1, 0}};
	for (auto it : findOrder(V, prerequisites)) cout << it << " ";
}

///////////////////////////////////////////////////////////////////////////////////////////
// G-25. Find Eventual Safe States - BFS - Topological Sort
// same problem that is above done but htis time using topologykal sort and BFS
// 1 : reverse all the edges int the directed Graph
vector<int> eventualSafeNodes_toposort(int V, vector<int> adj[]) {
	vector<int> adjRev[V]; // reverse all the edges
	int indegree[V] = {0};

	for (int i = 0; i < V; i++) {
		// i -> it // original
		// it -> i // after reverse
		for (auto it : adj[i]) {
			adjRev[it].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		// find out terminal node(node whose indegree is 0)
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> safeNodes;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		safeNodes.push_back(node);

		for (auto it : adjRev[node]) {
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}

	sort(safeNodes.begin(), safeNodes.end());
	return safeNodes;
}
void solve_eventualSafeNodes_toposort() {
	int V, E;
	cin >> V >> E;

	vector<int> adj[V];
	// V => count of total number of verticis
	// E => count of total number of edges

	for (int i = 0; i < E; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	cout << endl ;
	for (auto it : eventualSafeNodes_toposort(V, adj))
		cout << it << " ";
}

/////////////////////////////////////////////////////////////////////////////////
// G-26. Alien Dictionary - Topological Sort
// we are creating directed graph on the basis of Alien Dictonary
vector<int> toposort_findOrder_Alien(int V, vector<int> adj[]) {
	int indegree[V] = {0};
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	vector<int> topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);

		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}


	return topo;
}
string findOrder_Alien(string dict[], int N, int K) {
	vector<int> adj[K];
	for (int i = 0; i < N - 1; i++) {
		string s1 = dict[i];
		string s2 = dict[i + 1];
		int len = min((int)s1.size(), (int)s2.size());
		for (int i = 0; i < len; i++) {
			if (s1[i] != s2[i]) {
				adj[s1[i] - 'a'].push_back(s2[i] - 'a'); // we are making directed Graph // we are converting in to 0 and 1
				break;
			}
		}
	}

	vector<int> topo = toposort_findOrder_Alien(K, adj);
	string ans = "";
	for (auto it : topo) {
		ans = ans + char(it + 'a');
	}

	return ans;
}
void solve_findOrder_Alien() {
	int N = 5, K = 4; // N = is the size of dict // k = is number of verticies (V)
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	cout << findOrder_Alien(dict, N, K);
}

/////////////////////////////////////////////////////////////////////////////////
// G-27. Shortest Path in Directed Acyclic Graph - Topological Sort // DFS // DAG(Diected Acyclic Graph)
// 1 : Do a Topo sort on the graph
// 2 : Take a ndoe out of the stack & relaxation of the edges (Keep on updateing the distance array)
void toposort_dfs_shortestPath(int node, vector<pair<int, int>> adj[], int vis[], stack<int> & st) {
	vis[node] = 1;

	for (auto it : adj[node]) {
		int v = it.first;
		if (!vis[v]) {
			toposort_dfs_shortestPath(v, adj, vis, st);
		}
	}

	st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> & edges) {
	vector<pair<int, int>>  adj[N]; // N is the number for Vertices(Nodes);
	for (int i = 0; i < M; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		int wt = edges[i][2];
		adj[u].push_back({v, wt});
	}

	// find the topo sort using dfs in directed Acyclic Graph
	// O(N + M) // this is dfs timcomplexity
	int vis[N] = {0};
	stack<int> st;
	// this is components wise dfs // that's  why we are using for loop
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			toposort_dfs_shortestPath(i, adj, vis, st);
		}
	}

	// step2 to do a distance thing
	vector<int> dist(N);
	// fill dis vector with infinity
	for (int i = 0; i < N; i++) dist[i] = 1e9;
	dist[0] = 0; // graph start with 0 , so first vector always has 0 distance
	// O(N + M) // take time complexityfor stack and for inside the stack
	while (!st.empty()) {
		int node = st.top();
		st.pop();

		for (auto it : adj[node]) {
			int v = it.first;
			int wt = it.second;

			if (dist[node] + wt < dist[v]) {
				dist[v] = dist[node] + wt;
			}
		}
	}

	for (int i = 0; i < N; i++)
		if (dist[i] == 1e9)
			dist[i] = -1; // if distance is unrcheable than return -1;
	return dist;

}
void solve_shortestPath() {
	int n = 6, m = 7; // M is the number of edges
	vector<vector<int>> edges = {
		{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}
	};
	for (auto it : shortestPath(n, m, edges))
		cout << it << " ";
}

/////////////////////////////////////////////////////////////////////////////////////
// G-28. Shortest Path in Undirected Graph with Unit Weights // undirected Graph(UG)
vector<int> shortestPath_unit_weight(vector<vector<int>> & edges, int N , int M, int src) {
	vector<int> adj[N];

	for (auto it : edges) {
		adj[it[0]].push_back(it[1]);
		adj[it[1]].push_back(it[0]);
	}

	vector<int>  dist(N);
	for (int i = 0; i < N; i++) dist[i] = 1e9;
	dist[src] = 0;
	queue<int> q;
	q.push(src);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto it : adj[node]) {
			if (dist[node] + 1 < dist[it]) {
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}

	for (int i = 0; i < N; i++)
		if (dist[i] == 1e9)
			dist[i] = -1;
	return dist;
}
void solve_shortestPath_unit_distance() {
	int n = 9, m = 10;
	vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4 , 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
	int src = 0;
	for (auto it : shortestPath_unit_weight(edges, n , m, src))
		cout << it << " ";
}

/////////////////////////////////////////////////////////////////////////
// G-29. Word Ladder - I | Shortest Paths
int wordLadderlength(string startWord, string targetWord, vector<string> & wordList) {
	// {word, steps}
	queue<pair<string, int>> q;
	q.push({startWord, 1});
	unordered_set<string> st(wordList.begin(), wordList.end());
	st.erase(startWord); // remove from the set when we push inside the queue


	// TC O(N * word.length * 26 * log N)
	// SC O(N + N)
	while (!q.empty()) {
		string word = q.front().first;
		int steps = q.front().second;
		q.pop();
		if (word == targetWord) return steps;

		// word = hat
		//  time taken by this for loop is in the below line
		//  word.length * 26 * log N
		for (int i = 0; i < word.size(); i++) {
			char original = word[i]; // store original character
			for (char ch = 'a'; ch <= 'z'; ch++) {
				word[i] = ch;
				//if exists in the set
				if (st.find(word) != st.end()) { // if word present than erse that word from the set and push inside the queue
					st.erase(word);
					q.push({word, steps + 1});
				}
			}

			word[i] = original;
		}
	}

	return 0;
}
void solve_wordLadderLength() {
	vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
	string startWord = "der", targetWord = "dfs";
	cout << wordLadderlength(startWord, targetWord, wordList);
}


/////////////////////////////////////////////////////////////////////////////
// G-30. Word Ladder - 2 | Shortest Paths
// naive approach // optimal approach at G-31
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> & wordList) {
	// Push all values of wordList into a set
	// to make deletion from it easier and in less time complexity.
	unordered_set<string> st(wordList.begin(), wordList.end());

	// Creating a queue ds which stores the words in a sequence which is
	// required to reach the targetWord after successive transformations.
	queue<vector<string>> q;

	// BFS traversal with pushing the new formed sequence in queue
	// when after a transformation, a word is found in wordList.
	q.push({beginWord});

	// A vector defined to store the words being currently used
	// on a level during BFS.
	vector<string> usedOnLevel;
	usedOnLevel.push_back(beginWord);
	int level = 0;

	// vector to store the resultant transformation of sequences.
	vector<vector<string>> ans;

	while (!q.empty()) {
		vector<string> vec = q.front();
		q.pop();

		// Now, erase all words that have been
		// used in the previous levels to transform

		if (vec.size() > level) {
			level++;
			for (auto it : usedOnLevel) {
				// cout <<  " songs " << it << endl ;
				st.erase(it);
			}
		}

		string word = vec.back();

		// store the answers if the end word matches with target word
		if (word == endWord) {
			// the first sequence where we reachd end
			if (ans.size() == 0) {
				ans.push_back(vec);
			} else if (ans[0].size() == vec.size()) {
				ans.push_back(vec);
			}
		}

		for (int i = 0; i < word.size(); i++) {
			char original = word[i];
			for (char ch = 'a'; ch <= 'z'; ch++) {
				word[i] = ch;
				if (st.count(word) > 0) {
					// Check if the word is present in the wordList and
					// push the word along with the new sequence in the queue.
					vec.push_back(word);
					q.push(vec);

					// mark as visited on the level
					usedOnLevel.push_back(word);
					vec.pop_back();
				}
			}

			word[i] = original;
		}
	}

	return ans;
}

// comparator function to sort the ans
bool comp(vector<string> a, vector<string> b) {
	string x = "", y = "";
	for (string i : a)
		x += i;
	for (string i : b)
		y += i;
	return x < y;
}
void solve_findSequences() {
	vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
	string beginWord = "der", endWord = "dfs";
	vector<vector<string>> ans =  findSequences(beginWord, endWord, wordList);
	if (ans.size() == 0)
		cout << -1 <<  endl;
	else {
		// sort(ans.begin(), ans.end(), comp);
		for (auto it : ans) {
			for (auto i : it) cout << i << " ";
			cout << endl;
		}
	}

}
//////////////////////////////////////////////////////////////////////////
// G-31. Word Ladder - 2 | Optimised Approach for Leetcode
// this problem will be same as above , don't do this approach for interview , above is proper approach

///////////////////////////// Dijkastra's algorithem /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
// G-32. Dijkstra's Algorithm - Using Priority Queue - C++ - Part 1
// undirected graph
// TC O(E * logV)
vector<int> dijkstra(int V, vector<vector<int>> adj[], int s) {
	// min heap
	priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<int> dist(V);
	for (int i = 0; i < V; i++) dist [i] = 1e9;

	dist[s] = 0;
	// {weight, node}
	pq.push({0, s});

	while (!pq.empty()) {
		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();


		for (auto it : adj[node]) {
			int adjNode = it[0];
			int edgeWeight = it[1];

			if (dis + edgeWeight < dist[adjNode]) {
				dist[adjNode] = dis + edgeWeight;
				pq.push({dist[adjNode], adjNode});
			}
		}
	}
	return dist;
}

void solve_dijkstra() {
	// int V, E;
	// cin >> V >> E;
	// vector<vector<int>> adj[V];
	// int i = 0;

	// while(i++ < E) {
	// 	int u , v, w;
	// 	vector<int> t1, t2;
	// 	t1.push_back(v);
	// 	t2.push_back(w);
	// 	adj[u].push_back(t1);

	// 	t2.push_back(u);
	// 	t2.push_back(w);
	// 	adj[v].push_back(t2);
	// }

	// int s;
	// cout << s;
	int V = 2;
	vector<vector<int>> adj[] = {
		{{1, 9}}, {{0, 9}}
	};
	int s = 0;
	for (auto it : dijkstra(V, adj, s))
		cout << it << " ";
	cout << endl;
}

/////////////////////////////////////////////////
// G-33. Dijkstra's Algorithm - Using Set - Part 2
vector<int> dijkstra_set(int V, vector<vector<int>> adj[], int s) {
	set<pair<int, int>> st;
	vector<int> dist(V, 1e9);

	// {weight, node}
	st.insert({0, s});
	dist[s] = 0;

	while (!st.empty()) {
		auto it = *(st.begin());
		int dis = it.first;
		int node = it.second;
		st.erase(it);

		for (auto it : adj[node]) {
			int adjNode = it[0];
			int edgeWeight = it[1];

			if (dis + edgeWeight < dist[adjNode]) {
				if (dist[adjNode] != 1e9)
					st.erase({dist[adjNode], adjNode});

				dist[adjNode] = dis + edgeWeight;
				st.insert({dist[adjNode], adjNode});
			}
		}
	}

	return dist;
}

void solve_dijkstra_set() {
	// int V, E;
	// cin >> V >> E;
	// vector<vector<int>> adj[V];
	// int i = 0;

	// while(i++ < E) {
	// 	int u , v, w;
	// 	vector<int> t1, t2;
	// 	t1.push_back(v);
	// 	t2.push_back(w);
	// 	adj[u].push_back(t1);

	// 	t2.push_back(u);
	// 	t2.push_back(w);
	// 	adj[v].push_back(t2);
	// }

	// int s;
	// cout << s;
	int V = 2;
	vector<vector<int>> adj[] = {
		{{1, 9}}, {{0, 9}}
	};
	int s = 0;
	for (auto it : dijkstra_set(V, adj, s))
		cout << it << " ";
	cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////
// G-34. Dijkstra's Algorithm - Why PQ and not Q, Intuition, Time Complexity Derivation - Part 3
// this is explation of how priority queue has time complexity of O(E logN);

//////////////////////////////////////////////////////////////////////////////////////////////
// G-35. Print Shortest Path - Dijkstra's Algorithm
// Shortest Path in Weighted undirected graph
vector<int> shortestPath_dijkstara(int n, int m, vector<vector<int>> &edges) {
	// n // is total number of vertices(nodes)V
	vector<pair<int, int>> adj[n + 1];
	// making graph using adjency list
	for (auto it : edges) {
		adj[it[0]].push_back({it[1], it[2]});
		adj[it[1]].push_back({it[0], it[2]});
	}

	//  min heap
	// {dis, node}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n + 1, 1e9), parent(n + 1);
	for (int i =  1 ; i <= n ; i++) parent[i] = i;
	dist[1] = 0; // 1 based graph
	pq.push({0, 1});
	while (!pq.empty()) {
		auto it = pq.top();
		int dis = it.first;
		int node = it.second;
		pq.pop();

		for (auto it :  adj[node]) {
			int adjNode = it.first;
			int edW = it.second;

			if (dis + edW < dist[adjNode]) {
				dist[adjNode] = dis + edW;
				pq.push({dist[adjNode], adjNode});
				parent[adjNode] = node;
			}
		}
	}

	if (dist[n] == 1e9) return { -1};
	vector<int> path;
	int node = n ;
	while (parent[node] != node) {
		path.push_back(node);
		node = parent[node];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	return path;
}

void solve_shortestPath_dijkstra() {
	int n = 5, m = 6;
	vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
	for (auto it : shortestPath_dijkstara(n, m, edges))
		cout << it << " ";
	cout << endl;
}

//////////////////////////////////////////////////////////////////////////////
// G-36. Shortest Distance in a Binary Maze(Dijkstra)
// Shortest Distance in a Binary Maze
// Note : we do note need priority queue to figure out the minimul distance , because we have unit(1) distance in the every direction
int shortestpath_binary_maze(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
	queue<pair<int, pair<int, int>>> q;
	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> dist(n , vector<int> (m , 1e9));
	dist[source.first][source.second] = 0;
	q.push({0, {source.first, source.second}});
	int dr[] = { -1, 0, +1, 0};
	int dc[] = {0, +1, 0, -1};

	while (!q.empty()) {
		auto it = q.front();
		int dis = it.first;
		int r = it.second.first;
		int c = it.second.second;
		q.pop();

		for (int i = 0; i < 4 ; i++) {
			int newr = r + dr[i];
			int newc = c + dc[i];
			if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {
				dist[newr][newc] = dis + 1;
				if (newr == destination.first && newc == destination.second) return dis + 1;
				q.push({dis + 1, {newr, newc}});
			}
		}
	}
	if (source.first == destination.first && source.second == destination.second)
		return 0;

	return -1;
}
void solve_shortestpath_binary_maze() {
	vector<vector<int>> grid = {
		{1, 1, 1, 1},
		{1, 1, 0, 1},
		{1, 1, 1, 1},
		{1, 1, 0, 0},
		{1, 0, 0, 1}
	};
	pair<int, int> source = {0, 1};
	pair<int, int> destination = {2, 2};

	cout << shortestpath_binary_maze(grid, source, destination) << endl;
}

////////////////////////////////////////////////////////////////////////////
// G-37. Path With Minimum Effort => // we are using dijkstra
// TC O(N logV)
// TC O(n * m * 4 log(n *  m))
int MinimumEffort(vector<vector<int>> &heights) {
	// min heap
	// {diff, {row, col}}
	priority_queue< pair<int, pair<int, int>>,
	                vector< pair<int, pair<int, int>> >,
	                greater< pair<int, pair<int, int>> > > pq;
	int n = heights.size();
	int m = heights[0].size();

	vector<vector<int>> diff(n , vector<int> (m , 1e9));
	diff[0][0] = 0;
	pq.push({0, {0, 0}});

	int dr[] = { -1, 0, +1, 0};
	int dc[] = {0, +1, 0, -1};

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int dif = it.first;
		int row = it.second.first;
		int col = it.second.second;

		if (row == n - 1 && col == m - 1) return dif;

		for (int i = 0; i < 4; i++) {
			int newr = row + dr[i];
			int newc = col + dc[i];

			if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
				int newEfforts = max(abs(heights[row][col] - heights[newr][newc]), dif);
				if (newEfforts < diff[newr][newc]) {
					diff[newr][newc] = newEfforts;
					pq.push({newEfforts, {newr, newc}});
				}
			}
		}
	}
	return 0; // unrechable
}
void solve_MinimumEffort() {
	vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
	cout << MinimumEffort(heights);
}

////////////////////////////////////////////////////////////////
// G-38. Cheapest Flights Within K Stops // Dijkstra but modified version
// grpah is directed
// TC O(E) => E is the total number of edges
int CheapestFLight(int n, vector<vector<int>> & flights, int src, int dst, int k) {
	vector<pair<int, int>> adj[n];

	for (auto it : flights) {
		adj[it[0]].push_back({ it[1], it[2] });
	}

	// {stops, {node, dist}}
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {src, 0}});

	vector<int> dist(n , 1e9);
	dist[src] = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		int stops = it.first;
		int node = it.second.first;
		int cost = it.second.second;

		for (auto it : adj[node]) {
			int adjNode = it.first;
			int edW  = it.second;

			if (cost + edW  < dist[adjNode] && stops <= k) {
				dist[adjNode] = cost + edW;
				q.push({stops + 1, {adjNode, cost + edW}});
			}
		}
	}

	if (dist[dst] == 1e9) return -1;
	return dist[dst];
}

void solve_CheapestFLight() {
	int n = 4;
	vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
	int src = 0;
	int dst = 3;
	int k = 1;
	cout << CheapestFLight(n, flights, src, dst, k);
}

//////////////////////////////////////////////////////////////////////////
// G-39. Minimum Multiplications to Reach End // using (Dijkstra Algo)
// TC O(mod * N) => hypothetical time complexity but in real sense it is way lesser than that
int minimumMultiplications(vector<int> & arr, int start, int end) {
	queue<pair<int, int>> q;
	// {start, steps}
	q.push({start, 0});
	int mod = 100000;
	vector<int> dist(mod, 1e9);
	dist[start] = 0;
	while (!q.empty()) {
		int node = q.front().first;
		int steps = q.front().second;
		q.pop();

		for (auto it : arr) {
			int num = (it * node) % mod;
			if (steps + 1  < dist[num]) {
				dist[num] = steps + 1;
				if (num == end) return steps + 1;
				q.push({num , steps  + 1});
			}
		}
	}
	return -1;
}
void solve_minimumMultiplications() {
	vector<int>  arr =  {2, 5, 7};
	int start = 3, end = 30;
	cout << minimumMultiplications(arr, start, end);
}

/////////////////////////////////////////////////////////////////////////////
// G-40. Number of Ways to Arrive at Destination
// problem related undirected graph
int countPaths(int n, int m , vector<vector<int>> & roads) {
	//n = number of vertices(V) or Nodes(N)
	// m = numbers of Edges(E)

	// zero base indexing graph
	vector<pair<int, int>> adj[n];
	for (auto it : roads) {
		adj[it[0]].push_back({it[1], it[2]});
		adj[it[1]].push_back({it[0], it[2]});
	}

	// {dist, node} // min heap
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
	pq.push({0, 0});

	vector<int> dist(n , 1e9), ways(n , 0);
	dist[0] = 0;
	ways[0] = 1;
	int mod = (int)(1e9 + 7);

	while (!pq.empty()) {
		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (auto it : adj[node]) {
			int adjNode = it.first;
			int edW = it.second;

			// this is first time i am coming with
			// this short of distance
			if (dis + edW < dist[adjNode]) {
				dist[adjNode] = dis + edW;
				pq.push({dis + edW, adjNode});
				ways[adjNode] = ways[node];
			} else if (dis + edW == dist[adjNode]) {
				ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
			}
		}
	}

	return ways[n - 1] % mod;
}
void solve_countPaths() {
	int n = 7, m = 10;
	vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
	cout << countPaths(n , m , edges);
}

//////////////////////////////////////////////////////////////////////////////
// G-41. Bellman Ford Algorithm // used to find shortest path
// Dijkstra alogo fails when graph has -ve numbers, it is goes for TLE
// 1 => why N - 1 iteration? => 0 index is alrady has 0 value so, remaning values are N - 1
// 2 => how to detect negative cycles
//   -> on Nth iteration , the relaxation will be done, and if ths dist[] arrays will be reduces, then negative cycle exists
vector<int> bellman_ford(int V, vector<vector<int>> & edges, int s) {
	vector<int> dist(V, 1e8);
	dist[s] = 0;
	for (int i = 0; i < V - 1 ; i++) {
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}

	// Nth relataxation to check  negative cycles
	for (auto it : edges) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			return { -1};
		}
	}
	return dist;

}
void solve_bellman_ford() {
	vector<vector<int>> edges = {{0, 1, 9}};
	int V = 2;
	int S = 0;
	for (auto it : bellman_ford(V, edges, S )) cout << it << " ";
}

/////////////////////////////////////////////////////////////////////////////////
// G-42. Floyd Warshall Algorithm
// G-42 and G-43 we are not doning we don't need to know this algo

////////////////////////////////////////// Minum Spanning Tree(MST) //////////////////////////////////////////////////////
// G-44. Minimum Spanning Tree - Theory
// defi of MST => a tree in which have N nodes and N - 1 edges and all nodes are reachable from each other
// from graph we can develop multiple spanning Tree , but tree which has minimum sum which is MST.

//////////////////////////////////////////////////////
// G-45. Prim's Algorithm - Minimum Spanning Tree

// 1st version to return MST
vector<pair<int, int>>  spanningTree(int V, vector<vector<int>> adj[]) {
	priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

	vector<int> vis(V, 0);

	// {wt, node, parent}
	pq.push({0, {0, -1}});

	vector<pair<int, int>> MST;
	int sum = 0;
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int  wt = it.first;
		int node = it.second.first;
		int parent = it.second.second;

		if (vis[node] == 1 ) continue;

		//add it to the MST
		MST.push_back({parent, node});
		vis[node] = 1;
		sum += wt;

		for (auto it : adj[node]) {
			int adjNode = it[0];
			int edW = it[1];

			if (!vis[adjNode]) {
				pq.push({edW, {adjNode, node}});
			}
		}
	}

	cout << " sum " << sum << endl;

	return MST;
}


// 2nd version to return sum of MST
// TC O(E log E + E log E) = O(E log E)
int spanningTree_sum(int V, vector<vector<int>> adj[]) {

	// min heap using priority_queue
	priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> > pq;
	pq.push({0, 0})	; // {wt, node}
	vector<int> vis(V, 0);
	int sum = 0;

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int wt = it.first;
		int node = it.second;

		if (vis[node] == 1) continue;
		vis[node] = 1;
		sum += wt;

		for (auto it : adj[node]) {
			int adjNode = it[0];
			int edW = it[1];

			if (!vis[adjNode]) {
				pq.push({edW, adjNode});
			}
		}
	}

	return sum;
}
void solve_spanningTree() {
	// vector<vector<int>> adj[] = { {0, 1, 5}, {1, 2, 3}, {0, 2,  1} };
	int V, E;
	cin >> V >> E;
	vector<vector<int>> adj[V];
	int i = 0;
	while (i++ < E ) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	// for (auto it : spanningTree(V, adj)) cout << it.first << " " << it.second << endl;
	cout << spanningTree_sum(V, adj);
}


/////////////////////////////// Disjoint Set //////////////////////////////////////////////
// G-46. Disjoint Set | Union by Rank | Union by Size | Path Compression
// Disjoint Set are Generally used int dynamin Graph
// 1. finding parent
// 2. Union  -> (this union is done with 2 methods => 1. rank 2. size)


// union(u, v)
// 1. find ultimate parent of (u and v => pu  and pv)
// 2. find rank of pu and pv(pu and pv are ultimate parent)
// 3. connect smaller rank to larger rank always

// TC O(4 alpha)

class DisjointSet {
public:
	vector<int> rank, size, parent;
	DisjointSet(int n) {
		rank.resize(n + 1, 0); // we need n + 1 , it is work both in 0 and 1 based graph
		size.resize(n + 1); // we need n + 1 , it is work both in 0 and 1 based graph
		parent.resize(n + 1);
		for (int i = 0; i <= n ; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}


	// find ultimate parent
	// this path comparession
	int findUPar(int node) {
		if (node == parent[node])
			return node;

		return parent[node] = findUPar(parent[node]);
	}

	void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		// they are belonging to the same components
		if (ulp_u == ulp_v) return;

		// if thery are not belonging to the same components
		if (rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		} else if (rank[ulp_v] < rank[ulp_u]) {
			parent[ulp_v] = ulp_u;
		} else {
			// if both are same
			parent[ulp_u] = ulp_v;
			rank[ulp_u]++;
		}
	}

	void unionBySize(int u , int v)  {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if (ulp_u == ulp_v) return;
		if (size[ulp_u] <  size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		} else {
			// both = and greater than case will be same resolved in this
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
	}
};

void solve_DisjointSet() {
	DisjointSet ds(7);
	ds.unionByRank(1, 2);
	ds.unionByRank(2, 3);
	ds.unionByRank(4, 5);
	ds.unionByRank(6, 7);
	ds.unionByRank(5, 6);

	// if 3 and 7 belongs to the same parent
	if (ds.findUPar(3) == ds.findUPar(7))
		cout << " same\n";
	else
		cout << " Not Same\n";

	ds.unionByRank(3, 7);
	if (ds.findUPar(3) == ds.findUPar(7))
		cout << " same\n";
	else
		cout << " Not Same\n";
}

////////////////////////////////////////////////
// G-47. Kruskal's Algorithm - Minimum Spanning Tree
// krusukal's Algo is used to find MST(minimum spanning Tree)

int spanningTree_kruskal_algo(int V, vector<vector<int>> adj[]) {
	vector< pair<int, pair<int, int>> > edges;
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			int adjNode = it[0];
			int wt = it[1];
			int node = i;

			edges.push_back({wt, {node, adjNode}});
		}
	}

	DisjointSet ds(V);
	sort(edges.begin(), edges.end());
	int mstWt = 0;

	for (auto it : edges) {
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;

		if (ds.findUPar(u) != ds.findUPar(v)) {
			mstWt += wt;
			ds.unionBySize(u, v);
		}
	}

	return mstWt;
}

void solve_spanningTree_kruskal_algo() {
	int V, E;
	cin >> V >> E;
	vector<vector<int>> adj[V];
	int i = 0;
	while (i++ < E ) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	cout << spanningTree_kruskal_algo(V, adj);
}

///////////////////////////////////////////////////////////////
// G-48. Number of Provinces - Disjoint Set
int numProvinces_Disjoint_set(vector<vector<int>> adj, int V) {
	DisjointSet ds(V);

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (adj[i][j] == 1) {
				ds.unionBySize(i, j);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < V; i++) {
		if (ds.parent[i] == i)
			cnt++;
	}
	return cnt;
}
void solve_numProvinces_Disjoint_set() {
	vector<vector<int>> adj = {
		{1, 0, 1},
		{0, 1, 0},
		{1, 0, 1}
	};

	cout << numProvinces_Disjoint_set(adj, 3);

}

//////////////////////////////////////////////////////////////////
//G-49. Number of Operations to Make Network Connected - DSU
//Connecting the graph => GeeksForGeeks Problem
int Connecting_Graph(int n , vector<vector<int>> & edge) {
	DisjointSet ds(n);
	int cntExtraEdges = 0;
	for (auto it : edge) {
		int u = it[0];
		int v = it[1];
		if (ds.findUPar(u) == ds.findUPar(v)) {
			cntExtraEdges++;
		} else {
			ds.unionBySize(u, v);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n ; i++)
		if (ds.parent[i] == i)
			cnt++;

	int ans = cnt - 1;
	if (cntExtraEdges >= ans) return ans;
	return -1;
}
void  solve_Connecting_Graph() {
	int n = 4;
	int m = 3;
	vector<vector<int>> edge = {
		{0, 1},
		{0, 2},
		{1, 2}
	};

	cout << Connecting_Graph(n , edge);
}

//////////////////////////////////////////////////////////////////////////
// G-50. Accounts Merge - DSU => we are using disjoint set data structure
vector<vector<string>> accountMerge(vector<vector<string>> & accounts) {
	int n = accounts.size();
	DisjointSet ds(n);
	unordered_map<string, int> mapMailNode;
	for (int i = 0; i < n ; i++) {
		for (int j = 1; j < accounts[i].size() ; j++) {
			string mail = accounts[i][j];
			if (mapMailNode.find(mail) == mapMailNode.end()) {
				mapMailNode[mail] = i;
			} else {
				ds.unionByRank(i, mapMailNode[mail]);
			}
		}
	}

	vector<string> mergedMail[n];

	for (auto it : mapMailNode) {
		string mail = it.first;
		int node = ds.findUPar(it.second);
		mergedMail[node].push_back(mail);
	}

	vector<vector<string>> ans ;

	for (int i = 0; i < n ; i++) {
		if (mergedMail[i].size() == 0) continue;
		sort(mergedMail[i].begin(), mergedMail[i].end());
		vector<string> temp;
		temp.push_back(accounts[i][0]);
		for (auto it : mergedMail[i]) {
			temp.push_back(it);
		}
		ans.push_back(temp);
	}
	return ans;
}
void solve_accountMerge() {
	int n = 4;
	vector<vector<string>> accounts = {
		{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
		{"John", "johnsmith@mail.com", "john00@mail.com"},
		{"Mary", "mary@mail.com"},
		{"John", "johnnybravo@mail.com"}
	};
	for (auto it : accountMerge(accounts)) {
		for (auto i : it)
			cout << i << " ";
		cout << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////
//G-51. Number of Islands - II - Online Queries - DSU
// using DisjointSet
vector<int> numberOfIslands_DisjointSet(int n , int m, vector<vector<int>> &operators) {
	DisjointSet ds(n * m);
	int vis[n][m];
	memset(vis, 0, sizeof vis);
	int cnt = 0;
	vector<int> ans;

	for (auto it : operators) {
		int row = it[0];
		int col = it[1];
		if (vis[row][col] == 1) {
			ans.push_back(cnt);
			continue;
		}
		vis[row][col] = 1;
		cnt++;

		int dr[] = { -1, 0, 1, 0};
		int dc[] = {0, 1, 0, -1};
		for (int i = 0; i < 4; i++) {
			int adjr = row + dr[i];
			int adjc = col + dc[i];
			if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m) {
				if (vis[adjr][adjc] == 1) {
					int nodeNo = row * m + col;
					int adjNodeNo = adjr * m + adjc;
					if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
						cnt--;
						ds.unionBySize(nodeNo, adjNodeNo);
					}

				}
			}
		}
		ans.push_back(cnt);
	}
	return ans;
}

void solve_numberOfIslands_DisjointSet() {
	int n = 4;
	int m = 5;
	int k = 4;
	vector<vector<int>> operators = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};

	for (auto it : numberOfIslands_DisjointSet(n , m , operators))
		cout << it << " ";
}

/////////////////////////////////////////////////////////////////////////////
// G-52. Making a Large Island - DSU
bool isValid(int n , int newr, int newc) {
	return newr >= 0 && newr < n && newc >= 0 && newc < n;
}
int MaxConnection(vector<vector<int>> & grid) {
	int n = grid.size();
	DisjointSet ds(n * n);

	// step1
	for (int row = 0; row < n ; row++) {
		for (int col = 0; col < n ; col++) {
			if (grid[row][col] == 0) continue;
			int dr[] = { -1, 0, 1, 0};
			int dc[] = {0, 1, 0, -1};
			for (int i = 0; i < 4; i++) {
				int newr = row + dr[i];
				int newc = col + dc[i];
				if (isValid(n , newr, newc) && grid[newr][newc] == 1) {
					int nodeNo = row * n + col;
					int adjNodeNo = newr * n + newc;
					ds.unionBySize(nodeNo, adjNodeNo);
				}
			}
		}
	}

	// step2
	int mx = 0;
	for (int row = 0; row < n ; row++) {
		for (int col = 0; col < n ; col++) {
			if (grid[row][col] == 1) continue;
			int dr[] = { -1, 0, 1, 0};
			int dc[] = {0, 1, 0, -1};
			set<int> components;
			for (int i = 0; i < 4; i++) {
				int newr = row + dr[i];
				int newc = col + dc[i];
				if (isValid(n , newr, newc) && grid[newr][newc] == 1) {
					components.insert(ds.findUPar(newr * n + newc));
				}
			}

			int totalSize = 0;
			for (auto it : components) {
				totalSize += ds.size[it];
			}
			mx = max(mx , totalSize + 1);
		}
	}

	// if all the 1's are available in the grid
	for (int cellNo = 0; cellNo < n * n ; cellNo++) {
		mx = max(mx, ds.size[ds.findUPar(cellNo)]);
	}
	return mx;
}
void solve_MaxConnection() {
	vector<vector<int>> grid = {{1, 1}, {0, 1}};
	cout << MaxConnection(grid);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//G-53. Most Stones Removed with Same Row or Column - DSU
int maxRemove(vector<vector<int>> & stones, int n) {
	int maxRow = 0;
	int maxCol = 0;
	for (auto it : stones) {
		maxRow = max(maxRow, it[0]);
		maxCol = max(maxCol, it[1]);
	}

	DisjointSet ds(maxRow + maxCol + 1);
	unordered_map<int, int> stoneNodes;
	for (auto it : stones) {
		int nodeRow = it[0];
		int nodeCol = it[1] + maxRow + 1;
		ds.unionBySize(nodeRow, nodeCol);
		stoneNodes[nodeRow] = 1;
		stoneNodes[nodeCol] = 1;
	}

	// for(auto it : stoneNodes) cout << it.first << " " << it.second << endl;
	int cnt = 0;
	for (auto it : stoneNodes) {
		if (ds.findUPar(it.first) == it.first) {
			cnt++;
		}
	}
	return n - cnt;
}
void solve_maxRemove() {
	int n = 6;
	vector<vector<int>> stones = {{0, 0} , {0, 1}, {1, 0} , {1, 2} , {2, 1} , {2, 2}};
	cout << maxRemove(stones, n);
}



int main() {
	init_code();
	// solve_graph_adjacency_matrix();
	// solve_graph_adjacency_list();
	// solve_bfsOfGraph();
	// solve_dfsOfGraph();
	// solve_numberOfProvince();
	// solve_numIslands();
	// solve_floodFill();
	// solve_orangeRotting();
	// solve_isCycle_BFS();
	// solve_isCycle_DFS();
	// solve_nearest();
	// solve_fill();
	// solve_numberOfEnclaves();
	// solve_countDistinctIslands();
	// solve_isBipartite_bfs();
	// solve_isBipartite_dfs();
	// solve_isCyclic_directed();
	// solve_eventualSafeNodes();
	// solve_topsort();
	// solve_topsort_kahns();
	// solve_isCyclic_directed_kahns();
	// solve_isPossible();
	// solve_findOrder();
	// solve_eventualSafeNodes_toposort();
	// solve_findOrder_Alien();
	// solve_shortestPath();
	// solve_shortestPath_unit_distance();
	// solve_wordLadderLength();
	// solve_findSequences();
	// solve_dijkstra();
	// solve_dijkstra_set();
	// solve_shortestPath_dijkstra();
	// solve_shortestpath_binary_maze();
	// solve_MinimumEffort();
	// solve_CheapestFLight();
	// solve_minimumMultiplications();
	// solve_minimumMultiplications();
	// solve_countPaths();
	// solve_bellman_ford();
	// solve_shortest_distance()
	// solve_spanningTree();
	// solve_DisjointSet();
	// solve_spanningTree_kruskal_algo();
	// solve_numProvinces_Disjoint_set();
	// solve_Connecting_Graph();
	// solve_accountMerge();
	// solve_numberOfIslands_DisjointSet();
	// solve_MaxConnection();
	solve_maxRemove();
}
