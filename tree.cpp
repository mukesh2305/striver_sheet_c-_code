#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

// DFS => preOrder, postOder, inOrder
void preOrder(Node *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Node *root) {
	if (root == NULL) return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}
void postOrder(Node *root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

// BFS => levelOrder traversal
vector<vector<int>> levelOrder(Node *root) {
	vector<vector<int>> ans;
	if (root == NULL) return ans;
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size();
		vector<int> level;

		for (int i = 0; i < size; i++) {
			Node *node = q.front();
			q.pop();
			if (node->left != NULL) q.push(node->left);
			if (node->right != NULL) q.push(node->right);
			level.push_back(node->data);
		}
		ans.push_back(level);
	}
	return ans;
}

////////////////////// iterative way for dfs traversal ///////////////////////
vector<int> preOrder_loop(Node *root) {
	vector<int> preorder;
	if (root == NULL) return preorder;

	stack<Node*> st;
	st.push(root);

	while (!st.empty()) {
		root = st.top();
		st.pop();

		preorder.push_back(root->data);
		if (root->right != NULL) st.push(root->right);
		if (root->left != NULL) st.push(root->left);
	}
	return preorder;
}

vector<int> inOrder_loop(Node *root) {
	vector<int> inorder;
	stack<Node*> st;
	Node *node = root;

	while (true) {
		if (node != NULL) {
			st.push(node);
			node = node->left;
		} else {
			if (st.empty() == true) return inorder;
			node = st.top();
			st.pop();
			inorder.push_back(node->data);
			node = node->right;
		}
	}
	return inorder;
}


////////////
// iterative post order traversal using 2 stack
vector<int> postOrder_loop_2stack(Node * root) {
	vector<int> postorder;
	if (root == NULL) return postorder;
	stack<Node*> st1, st2;
	st1.push(root);

	while (!st1.empty()) {
		root = st1.top();
		st1.pop();
		st2.push(root);

		if (root->left != NULL) st1.push(root->left);
		if (root->right != NULL) st1.push(root->right);
	}

	while (!st2.empty()) {
		postorder.push_back(st2.top()->data);
		st2.pop();
	}

	return postorder;
}

// iterative post order traversal using 1 stack
vector<int> postOrder_loop_1stack(Node * root) {
	vector<int> postorder;

	if (root == NULL) return postorder;

	stack<Node*> st;
	while (root != NULL || !st.empty()) {

		if (root != NULL) {
			st.push(root);
			root = root->left;
		} else {
			Node *temp = st.top()->right;
			if (temp == NULL) {
				temp = st.top();
				st.pop();

				postorder.push_back(temp->data);
				while (!st.empty() && temp == st.top()->right) {
					temp = st.top();
					st.pop();
					postorder.push_back(temp->data);
				}
			} else root = temp;
		}
	}

	return postorder;
}

//////////////////////////////////////////////////////
// L14. Maximum Depth in Binary Tree | Height of Binary Tree
int maxDepth(Node *root) { // TC O(N)  // SC O(N)
	if (root == NULL) return 0;
	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);
	return 1 + max(lh, rh);
}

/// L15. Check for Balanced Binary Tree
// Blanced BT = for every node , height(left) - height(right) <= 1
// naive approach
// TC O(n ^ 2)
bool isBalanced(Node *root) {
	if (root == NULL) return true;

	int lh = isBalanced(root->left);
	int rh = isBalanced(root->right);
	if (abs(rh - lh) > 1) return false;

	bool left = isBalanced(root->left);
	bool right = isBalanced(root->right);


	if (!left || !right) return false;
	return true;
}

////// 2nd approach => optimal approach
int dfsHeight(Node * root) {
	if (root == NULL) return 0;

	int lh = dfsHeight(root->left);
	if (lh == -1) return -1;
	int rh = dfsHeight(root->right);
	if (rh == -1) return -1;

	if (abs(lh - rh) > 1) return -1;
	return max(lh , rh)  + 1;
}
bool isBalanced1(Node * root) {
	return dfsHeight(root) != -1;
}

///////////////////////////////////////////////////////
// L16. Diameter of Binary Tree
// diameter => longest path between any 2 nodes
//          => path does not need to pass via root // (it pass than ok // it can pass than ok but it is not mandetory)

int height(Node *node, int &diameter) {
	if (!node) return 0;

	int lh = height(node->left, diameter);
	int rh = height(node->right, diameter);

	diameter = max(diameter, lh + rh);

	return 1 + max(lh, rh);
}

// TC O(N)  SC O(N)
int diameterOfBinaryTree(Node * root) {
	int diameter = 0;
	height(root, diameter);
	return diameter;
}

////////////////////////////////////////////
// L17. Maximum Path Sum in Binary Tree

int maxPathDown(Node *node, int &maxi) {
	if (node == NULL) return 0;
	int left = max(0, maxPathDown(node->left, maxi));  // maxPathDown return -ve than we can take maximum and it make -ve into 0
	int right = max(0, maxPathDown(node->right, maxi));

	maxi = max(maxi, left + right + node->data);
	return max(left, right) + node->data;
}
int maxPathSum(Node *root) {
	int maxi = INT_MIN;
	maxPathDown(root, maxi);
	return maxi;
}

//////////////////////////////////////////
// L18. Check it two trees are Identical or Not
bool isSameTree(Node *p, Node *q) {
	if (p == NULL || q == NULL) return (p == q);

	return
	    (p->data == q->data) &&
	    isSameTree(p->left, q->left) &&
	    isSameTree(p->right, q->right);
}

void solve_isSameTree() {
	Node *p = new Node(1);
	p->left = new Node(2);
	p->right = new Node(3);
	p->right->left = new Node(4);
	p->right->right = new Node(5);

	Node *q = new Node(1);
	q->left = new Node(2);
	q->right = new Node(3);
	q->right->left = new Node(4);
	q->right->right = new Node(5);

	if (isSameTree(p, q)) cout << "same";
	else cout << " not same";
}


/////////////////////////////////////////////
// L19. Zig-Zag or Spiral Traversal in Binary Tree
vector<vector<int>> zigzageLevel(Node * root) {
	vector<vector<int>> result;
	if (root == NULL) return result;

	queue<Node*> q;
	q.push(root);

	bool leftToRight = true;

	while (!q.empty()) {
		int size = q.size();
		vector<int> row(size);

		for (int i = 0; i < size; i++) {
			Node *node = q.front();
			q.pop();

			// find position to fill the node's value
			int ind = leftToRight ? i : (size - 1 - i);
			row[ind] = node->data;

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}

		// after the level
		leftToRight = !leftToRight;
		result.push_back(row);
	}

	return result;
}


////////////////////////////////////////////
// L20. Boundary Traversal in Binary Tree
bool isLeaf(Node* root) {
	return !root->left && !root->right;
}
void addLeftBoundary(Node *root, vector<int> &res) {
	Node *cur = root->left;

	while (cur) {
		if (!isLeaf(cur)) res.push_back(cur->data);
		if (cur->left) cur = cur->left;
		else cur = cur->right;
	}
}

void addRightBoundary(Node *root, vector<int> &res) {
	Node *cur = root->right;
	vector<int> temp;
	while (cur) {
		if (!isLeaf(cur)) temp.push_back(cur->data);
		if (cur->right) cur = cur->right;
		else cur = cur->left;
	}

	for (int i = temp.size() - 1; i >= 0; --i)
		res.push_back(temp[i]);
}

void addLeaves(Node *root, vector<int> &res) {
	// used preorder traversal
	if (root == NULL) return;

	addLeaves(root->left, res);
	if (isLeaf(root)) res.push_back(root->data);
	addLeaves(root->right , res);
}
vector<int> printBoundary(Node *root) {
	vector<int> res;
	if (!root) return res;
	if (!isLeaf(root)) res.push_back(root->data);
	addLeftBoundary(root, res);
	addLeaves(root, res); // leaf node
	addRightBoundary(root, res);
	return res;
}


///////////////////////////////////////////////////////////
// L21. Vertical Order Traversal of Binary Tree

vector<vector<int>> verticalTraversal(Node *root) {
	map<int, map<int, multiset<int>>> nodes; // vecrtical levels multiplenodes
	queue<pair<Node*, pair<int, int>>> todo;
	todo.push({root, {0, 0}}); // node vecrtical(x) level(y)
	while (!todo.empty()) {
		auto p = todo.front();
		todo.pop();

		Node *node = p.first;  // node
		int x = p.second.first;  // vertical(x)
		int y = p.second.second; // level(y)
		nodes[x][y].insert(node->data);
		if (node->left)
			todo.push({node->left, {x - 1, y + 1}});
		if (node->right)
			todo.push({node->right, {x + 1, y + 1}});
	}

	vector<vector<int>> ans;
	for (auto p : nodes) {
		vector<int> col;
		for (auto q : p.second) {
			col.insert(col.end(), q.second.begin(), q.second.end());
		}
		ans.push_back(col);
	}
	return ans;
}


/////////////////////////////////////////////////////
// L22. Top View of Binary Tree
// TC O(N) SC O(N)
vector<int> topView(Node *root) {
	vector<int> ans;
	map<int , int> mp;
	queue< pair<Node*, int> > q;
	q.push({root, 0});

	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		Node *node = it.first;
		int line = it.second;
		if (mp.find(line) == mp.end()) mp[line] = node->data; // if not present than add

		if (node->left) q.push({node->left, line - 1});
		if (node->right) q.push({node->right, line + 1});
	}
	for (auto i : mp) ans.push_back(i.second);
	return ans;
}

/////////////////////////////////////////////////////////////
// L23. Bottom View of Binary Tree

vector<int> bottomView(Node *root) {
	vector<int> ans;
	map<int, int> mp;
	queue<pair<Node*, int>> q;
	q.push({root, 0});

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		Node *node = it.first;
		int line = it.second;

		mp[line] = node->data;

		if (node->left) q.push({node->left, line - 1});
		if (node->right) q.push({node->right, line + 1});
	}
	for (auto i : mp) ans .push_back(i.second);
	return ans;
}


////////////////////////////////////////////////////////////////
// L24 : Right/left view of Binary Tree

// recursion
void recu_rightView(Node *root, vector<int> &res, int level) {
	// preOrder => ro L R
	// in this case => ro R L
	if (root == NULL) return;

	if (res.size() == level) res.push_back(root->data);

	recu_rightView(root->right, res, level + 1);
	recu_rightView(root->left, res, level + 1);
}
vector<int> rightView(Node *root) {
	vector<int> res;
	recu_rightView(root, res, 0);
	return res;
}

//iterative
// My iterative approach
vector<int> rightView1(Node *root) {
	vector<int> res;
	if (root == NULL) return res;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node *curr = q.front();
			q.pop();
			if (i == 0) res.push_back(curr->data);
			if (curr->right != NULL) q.push(curr->right);
			if (curr->left != NULL) q.push(curr->left);
		}
	}
	return res;
}


///////////////// left view //////////////////////////
// recusion
void recu_leftView(Node *root, vector<int> &res, int level) {
	// preOrder => ro L R
	if (root == NULL) return;

	if (res.size() == level) res.push_back(root->data);

	recu_leftView(root->left, res, level + 1);
	recu_leftView(root->right, res, level + 1);
}
vector<int> leftView(Node *root) {
	vector<int> res;
	recu_leftView(root, res, 0);
	return res;
}

/// iterative approach
vector<int> leftView1(Node *root) {
	vector<int> res;
	if (root == NULL) return res;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node *curr = q.front();
			q.pop();
			if (i == 0) res.push_back(curr->data);
			if (curr->left != NULL) q.push(curr->left);
			if (curr->right != NULL) q.push(curr->right);
		}
	}
	return res;
}


/////////////////////////////////////////////////////////////////
// L25. Check for Symmetrical Binary Trees
bool isSymmetricHelp(Node *left, Node *right) {
	if (left == NULL || right == NULL) return left == right;

	if (left->data != right->data) return false;

	return
	    isSymmetricHelp(left->left, right->right) &&
	    isSymmetricHelp(left->right, right->left);
}
bool isSymmetric(Node *root) {
	return root == NULL || isSymmetricHelp(root->left, root->right);
}

void solve_isSymmetric() {
	Node *root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);

	root->right = new Node(2);
	root->right->left = new Node(4);
	root->right->right = new Node(3);
	if (isSymmetric(root)) cout << " symmetric " << endl;
	else cout << " not symmetric " << endl;
}

////////////////////////////////////////////////////
// L26. Print Root to Node Path in Binary Tree

bool getPath(Node *root, vector<int> &arr, int x) {
	if (!root) return false;

	arr.push_back(root->data);

	if (root->data == x) return true;

	if (
	    getPath(root->left, arr, x) ||
	    getPath(root->right, arr, x)
	) return true;

	arr.pop_back();
	return false;
}
vector<int> node_path(Node *root, int key) {
	// TC O(N)
	// SC O(H) // hight
	vector<int> arr;
	if (root == NULL) return arr;
	getPath(root, arr, key);
	return arr;
}

//////////////////////////////////////////////////////////////////
// L27. Lowest Common Ancestor in Binary Tree
Node* LCA(Node *root, Node *p, Node *q) {
	if (root == NULL || root == p || root == q) return root;

	Node *left = LCA(root->left, p, q);
	Node *right = LCA(root->right, p, q);

	// result
	if (left == NULL) return right;
	else if (right == NULL) return left;
	else {
		// both left and right are NULL
		return root;
	}
}

//////////////////////////////////////////////////////////
// L28. Maximum Width of Binary Tree
int widthOfBinaryTree(Node *root) {
	if (!root) return 0;
	int ans = 0;
	queue<pair<Node*, int>> q;
	q.push({root, 0});

	while (!q.empty()) {
		int sz = q.size();
		int mmin = q.front().second;
		cout << " mmin " << mmin << endl;
		int first , last;

		for (int i = 0; i < sz; i++) {
			int cur_id = q.front().second - mmin;
			cout << " cur_id " << cur_id << " ";

			Node *node = q.front().first;
			q.pop();

			if (i == 0) first = cur_id;
			if (i == sz - 1) last = cur_id;

			if (node->left) q.push({node->left, 2 * cur_id + 1});
			if (node->right) q.push({node->right, 2 * cur_id + 2});
		}
		cout << endl;

		ans = max(ans, last - first + 1);
	}
	return ans;
}

//////////////////////////////////////////////////////////
// L29. Children sum property in Binary Tree
void changeTree(Node *root) {
	if (root == NULL) return;

	int child = 0;

	if (root->left) child += root->left->data;
	if (root->right) child += root->right->data;

	if (child >= root->data) root->data = child;
	else {
		if (root->left) root->left->data = root->data;
		if (root->right) root->right->data = root->data;
	}

	changeTree(root->left);
	changeTree(root->right);

	int tot = 0;
	if (root->left) tot += root->left->data;
	if (root->right) tot += root->right->data;
	if (root->left or root->right) root->data = tot;
}

void solve_changeTree() {
	Node *root = new Node(2);
	root->left = new Node(35);
	root->left -> left = new Node(2);
	root->left -> right = new Node(3);
	root->right = new Node(10);
	root->right -> left = new Node(5);
	root->right -> right = new Node(2);

	// preOrder(root); cout << endl; // for printing
	changeTree(root);
	// preOrder(root); cout << endl; // for printing

}

/////////////////////////////////////////////////////
// ref =>  https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/

// true false => is satisty the children some property
int isSumProperty(Node *root) {
	int sum = 0;
	/* If node is NULL or it's a leaf node
		then return true */
	if (root == NULL || (root->left == NULL && root->right == NULL)) return 1;
	else {

		/* If left child is not present then 0
		is used as data of left child */
		if (root->left != NULL ) sum += root->left->data;

		/* If right child is not present then 0
		is used as data of right child */
		if (root->right != NULL ) sum += root->right->data;
	}

	return ((root->data == sum) && isSumProperty(root->left) && isSumProperty(root->right));
}

void solve_isSumProperty() {
	Node* root = new Node(10);
	root->left = new Node(8);
	root->right = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(5);
	root->right->right = new Node(2);

	// Function call
	if (isSumProperty(root))
		cout << "The given tree satisfies "
		     << "the children sum property ";
	else
		cout << "The given tree does not satisfy "
		     << "the children sum property ";

}


//////////////////////////////////////////////////////////////////
// L30. Print all the Nodes at a distance of K in Binary Tree

void markParents(Node *root, unordered_map<Node*, Node*> &parent_track) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node *cur = q.front();
		q.pop();

		if (cur->left) {
			parent_track[cur->left] = cur;
			q.push(cur->left);
		}

		if (cur->right) {
			parent_track[cur->right] = cur;
			q.push(cur->right);
		}
	}
}
vector<int> distanceK(Node *root, Node *target, int k) {
	unordered_map<Node*, Node*> parent_track; // node->parent
	markParents(root, parent_track);

	unordered_map<Node*, bool> visited;
	queue<Node*> q;
	q.push(target);
	visited[target] = true;

	int cur_level = 0;
	while (!q.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
		int sz = q.size();
		if (cur_level == k) break;
		cur_level++;

		for (int i = 0; i < sz; i++) {
			Node *curr = q.front();
			q.pop();
			if (curr->left && !visited[curr->left]) {
				q.push(curr->left);
				visited[curr->left] = true;
			}

			if (curr->right && !visited[curr->right]) {
				q.push(curr->right);
				visited[curr->right] = true;
			}

			if (parent_track[curr] && !visited[parent_track[curr]]) {
				q.push(parent_track[curr]);
				visited[parent_track[curr]] = true;
			}
		}
	}

	vector<int> result;
	while (!q.empty()) {
		Node *curr = q.front(); q.pop();
		result.push_back(curr->data);
	}
	return result;
}

void solve_distanceK() {
	Node *root = new Node(3);
	root->left = new Node(5);
	root->left->left = new Node(6);
	root->left->right = new Node(2);
	root->left->right->left = new Node(7);
	root->left->right->right = new Node(4);

	root->right = new Node(1);
	root->right->left = new Node(0);
	root->right->right = new Node(8);

	Node *target = root->left;
	for (auto it : distanceK(root, target, 2)) cout << it << " ";
}

///////////////////////////////////////////////////////////////////////////////
// L31. Minimum time taken to BURN the Binary Tree from a Node
// we are using level order traversal for burning tree(BFS)

int findMaxDistance(map<Node*, Node*> &parent_track, Node *target) {
	map<Node*, int> visited;
	queue<Node*> q;
	q.push(target);
	visited[target] = 1;

	int maxi = 0;
	while (!q.empty()) {
		int sz = q.size();
		int fl = 0;
		for (int i = 0; i < sz; i++) {
			Node *node = q.front(); q.pop();

			if (node->left && !visited[node->left]) {
				fl = 1;
				q.push(node->left);
				visited[node->left] = 1;
			}

			if (node->right && !visited[node->right]) {
				fl = 1;
				q.push(node->right);
				visited[node->right] = 1;
			}

			if (parent_track[node] && !visited[parent_track[node]]) {
				fl = 1;
				q.push(parent_track[node]);
				visited[parent_track[node]] = 1;
			}
		}
		if (fl) maxi++;
	}
	return maxi;

}

Node* bfsToMapParent(Node *root, map<Node*, Node*> &parent_track, int start) {
	queue<Node*> q;
	q.push(root);

	Node *res;
	while (!q.empty()) {
		Node *node = q.front();
		q.pop();
		if (node->data == start)  res = node;

		if (node->left) {
			parent_track[node->left] = node;
			q.push(node->left);
		}

		if (node->right) {
			parent_track[node->right] = node;
			q.push(node->right);
		}
	}

	return res;
}
int timeToBurn(Node *root, int start) {
	map<Node*, Node*> parent_track;
	Node *target = bfsToMapParent(root, parent_track, start);
	int maxi = findMaxDistance(parent_track, target);
	return maxi;
}

void solve_timeToBurn() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->left->right = new Node(7);

	root->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(6);

	cout << timeToBurn(root, 2); // burning tree start from 2(node)
}

////////////////////////////////////////////////////////////////////////////////////////////////
// L32. Count total Nodes in a COMPLETE Binary Tree
// 222. Count Complete Tree Nodes

// TC O(N)  SC O(h)
void countNodes(Node *root, int &cnt) {
	// we are doing inorder traversal
	if (root == NULL) return;
	cnt++;
	countNodes(root->left, cnt);
	countNodes(root->right, cnt);
}

// no of nodes 2 ^ 3 - 1 (if hight is 3)

int left(Node *root) {
	int hght = 0;
	while (root) {
		hght++;
		root = root->left;
	}
	return hght;
}

int right(Node *root) {
	int hght = 0;
	while (root) {
		hght++;
		root = root->right;
	}
	return hght;
}
int countNodes1(Node* root) {
	if (!root) return 0;

	int lh = left(root);
	int rh = right(root);

	if (lh == rh) return (1 << lh) - 1;
	// return 1 + countNodes1(root->left) + countNodes1(root->right);
	int leftNodes = countNodes1(root->left);
	int rightNodes = countNodes1(root->right);

	return 1 + leftNodes + rightNodes;
}

void solve_countNodes() {
	// count Nodes in the complete binary tree
	Node *root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right = new Node(3);
	root->right->left = new Node(6);

	// int cnt = 0;
	// countNodes(root, cnt);
	// cout << cnt << endl ;

	//optimal
	cout << countNodes1(root);
}


///////////////////////////////////////////////////////////////////////
// L33. Requirements needed to construct a Unique Binary Tree
// perorder & postorder never give unique binary tree
// preorder & inorder will give unique binary tree
// postorder & inorder will give unique binary tree

// L34. Construct a Binary Tree from Preorder and Inorder Traversal

Node* buildTree(vector<int> &preorder, int preStart, int preEnd,
                vector<int> &inorder, int inStart,  int inEnd, map<int, int> inMap) {

	if (preStart > preEnd  || inStart > inEnd) return NULL;

	Node *root = new Node(preorder[preStart]);

	int inRoot = inMap[root->data];
	int numsLeft = inRoot - inStart;

	root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
	                       inorder, inStart, inRoot - 1, inMap);

	root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
	                        inorder, inRoot + 1, inEnd, inMap);
	return root;
}
Node* buildTree(vector<int> &preorder, vector<int> &inorder) {
	map<int, int> inMap;

	for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;

	Node *root = buildTree(preorder, 0, preorder.size() - 1,
	                       inorder , 0, inorder.size() - 1 , inMap);

	return root;
}

void solve_buildTree() {
	vector<int> preorder = {9, 3, 15, 20, 7};
	vector<int> inorder = {3, 9, 20, 15, 7};
	Node *root = buildTree(preorder, inorder);
	inOrder(root); // to print
}

//////
// L35. Construct the Binary Tree from Postorder and Inorder Traversal

Node* buildTree1(vector<int> &postorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int, int> &mp) {
	if (ps > pe || is > ie ) return NULL;

	Node *root = new Node(postorder[pe]);
	int iRoot = mp[root->data];
	int numsLeft = iRoot - is;

	root->left = buildTree1(postorder, ps, ps + numsLeft - 1, inorder, is, iRoot - 1, mp);
	root->right = buildTree1(postorder, ps + numsLeft, pe - 1, inorder, iRoot + 1, ie, mp);
	return root;
}
Node* buildTree1(vector<int>& postorder, vector<int>& inorder) {
	map<int, int> mp;

	for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
	Node *root = buildTree1(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
	return root;
}
void solve_buildTree1() {
	vector<int> inorder = {9, 3, 15, 20, 7},
	            postorder = {9, 15, 7, 20, 3};
	Node * root = buildTree1(postorder, inorder);
	inOrder(root);
}


/////////////////////////////////////////////////////////
// L36. Serialize and De-serialize Binary Tree

// Encode your tree to a single string
string seialize(Node *root) {
	if (!root) return "";

	string s = "";
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node *curr = q.front();
		q.pop();

		if (curr == NULL) s.append("#,");
		else s.append(to_string(curr->data) + ',');

		if (curr != NULL) {
			q.push(curr->left);
			q.push(curr->right);
		}
	}
	cout << s ;
	return s;
}

// Decodes your encoded data to tree.
Node* deseialize(string data) {
	if (data.size() == 0) return NULL;

	stringstream s(data);
	string str;
	getline(s, str, ',');  // getline take one one string separated by , // eg : 1, 2, 3, 4, 5 => when we do first time getline than it take 1, 2nd time we do getline than we take 2

	Node *root = new Node(stoi(str));
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node *node = q.front();
		q.pop();

		getline(s, str, ',');
		if (str == "#") node->left = NULL;
		else {
			Node *leftNode = new Node(stoi(str));
			node->left = leftNode;
			q.push(leftNode);
		}

		getline(s, str, ',');
		if (str == "#") node->right = NULL;
		else {
			Node *rightNode = new Node(stoi(str));
			node->right = rightNode;
			q.push(rightNode);
		}

	}
	return root;
}

Node* seralize_deseralize(Node *root) {
	string data = seialize(root); cout << endl;
	return deseialize(data);
}

///////////////////////////////////////////////////////////////////////////////
// L37. Morris Traversal | Preorder | Inorder
// TC O(N) SC O(1) // does not consume extra space
// morries traversal uses thraded binary tree

// morries traversal on inOrder
vector<int> getInOrder(Node *root) {
	vector<int> inorder;
	Node *curr = root;
	while (curr != NULL) {
		if (curr->left == NULL) {
			inorder.push_back(curr->data);
			curr = curr->right;
		} else {
			Node *prev = curr->left;
			while (prev->right && prev->right != curr)
				prev = prev->right;

			if (prev->right == NULL) {
				prev->right = curr;
				curr = curr->left;
			} else { // thread already develop, so cut the thread
				prev->right = NULL;
				inorder.push_back(curr->data);
				curr = curr->right;
			}
		}
	}
	return inorder;
}

// morries traversal on preOrder
vector<int> getPreOrder(Node *root) {
	vector<int> preorder;
	Node *curr = root;
	while (curr != NULL) {
		if (curr->left == NULL) {
			preorder.push_back(curr->data);
			curr = curr->right;
		} else {
			Node *prev = curr->left;
			while (prev->right && prev->right != curr)
				prev = prev->right;

			if (prev->right == NULL) {
				prev->right = curr;
				preorder.push_back(curr->data);
				curr = curr->left;
			} else { // thread already develop, so cut the thread
				prev->right = NULL;
				curr = curr->right;
			}
		}
	}
	return preorder;
}

////////////////////////////////////////////////////////////////////////////////
// L38. Flatten a Binary Tree to Linked List | 3 Approaches
// use reverse preOrder
// preOrder =        root left right
// reversePreOrder = right left root ( we are using reverse preOrder)

// approach 1 using recursion

class Solution {
	Node *prev = NULL;
public :
	void flatten(Node *root) {
		if (root == NULL) return;

		flatten(root->right);
		flatten(root->left);

		root->right = prev;
		root->left = NULL;
		prev = root;
	}

	void flatten1(Node *root) {
		stack<Node*> st;
		if (root) st.push(root);
		while (!st.empty()) {
			Node *curr  = st.top(); st.pop();

			if (curr->right) st.push(curr->right);
			if (curr->left) st.push(curr->left);

			if (!st.empty()) curr->right = st.top();

			curr->left = NULL;
		}
	}

	void flatten2(Node *root) {
		Node *curr = root;
		Node *prev = NULL;
		while (curr) {
			if (curr->left) {
				prev = curr->left;
				while (prev->right)
					prev = prev->right;

				prev->right = curr->right;
				curr->right = curr->left;
				curr->left = NULL;
			}
			curr  = curr->right;
		}
	}

};
void solve_flatten() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);

	root->right = new Node(5);
	root->right->right = new Node(6);
	root->right->right->left = new Node(7);

	Solution obj;
	// obj.flatten(root);
	// obj.flatten1(root);
	obj.flatten2(root);
	while (root->right != NULL) {
		cout << root->data << "->";
		root = root->right;
	}
	cout << root->data << endl;


}


////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Binary Search Tree //////////////////////////////////////
// L39. Introduction to Binary Search Tree | BST  // this lecture is just explation
// L40. Search in a Binary Search Tree | BST
Node* searchBST(Node *root, int val) {
	while (root != NULL && root->data != val)
		root = val < root->data ? root->left : root->right;
	return root;
}


/////////////////////////////////////////////////////////////
// L41. Ceil in a Binary Search Tree | BST

int findCeil(Node *root, int key) {
	int ceil = -1;
	while (root) {
		if (root->data == key) return root->data;

		if (key > root->data) root = root->right;
		else {
			ceil = root->data;
			root = root ->left;
		}
	}

	return ceil;
}


/////////////////////////////////////////////////////////////
// L42. Floor in a Binary Search Tree

int findFloor(Node *root, int key) {
	int floor = -1;
	while (root) {
		if (root->data == key) return root->data;

		if (key > root->data) {
			floor = root->data;
			root = root->right;
		}
		else root = root ->left;

	}

	return floor;
}

/////////////////////////////////////////////////////////////////
// L43. Insert a given Node in Binary Search Tree
Node* insertIntoBST(Node *root, int val) {
	if (root == NULL) return new Node(val);
	Node *curr = root;

	while (true) {
		if (curr->data <= val) {
			if (curr->right) curr = curr->right;
			else {
				curr->right = new Node(val);
				break;
			}
		} else {
			if (curr->left) curr = curr->left;
			else {
				curr->left = new Node(val);
				break;
			}
		}
	}
	return root;
}
////////////////////////////////////////////////////////////////
// L44. Delete a Node in Binary Search Tree | BST
Node *findLastRight(Node *root) {
	if (root->right == NULL) return root;
	return findLastRight(root->right);
}
Node* helper(Node *root) {
	if (root->left == NULL) return root->right;
	if (root->right == NULL) return root->left;

	Node *rightChild = root->right;
	Node *lastRight = findLastRight(root->left); // lastRight in the left child of tree from given key
	lastRight->right = rightChild;
	return root->left;
}
Node* deleteNode(Node *root, int key) {
	if (root == NULL) return NULL;
	if (root->data == key) return helper(root);

	Node *dummy = root;
	while (root) {
		if (root->data > key) {
			if (root->left != NULL && root->left->data == key) {
				root->left = helper(root->left);
				break;
			} else root = root->left;
		} else {
			if (root->right != NULL && root->right->data == key) {
				root->right = helper(root->right);
				break;
			} else root = root->right;
		}
	}
	return dummy;
}

/////////////////////////////////////////////////////////////////////////////////
// L45. K-th Smallest/Largest Element in BST
// time complexity = O(N) + O(N^logN) (for sorting)
// 230. Kth Smallest Element in a BST

// if we do inorder traversal than always give sorted order
void KthSmallest(Node *root, vector<int> &vec) {
	if (root == NULL) return ;
	KthSmallest(root->left, vec);
	vec.push_back(root->data);
	KthSmallest(root->right, vec);
}

// optimal approach TC O(N)
void smallest_inorder(Node *root, int &k, int &res) {
	if (!root) return;
	smallest_inorder(root->left, k, res);
	if (--k == 0) res = root->data;
	smallest_inorder(root->right, k, res);
}
int KthSmallest1(Node *root, int k) {
	// if (root == NULL) return NULL;
	// Node *left = KthSmallest1(root->left, k);
	// if (left != NULL) return left;
	// k--;
	// if (k == 0) return root;
	// return KthSmallest1(root->right, k);
	int res = -1;
	smallest_inorder(root, k, res);
	return res;
}

Node* KthLargest(Node *root, int &k) {
	if (root == NULL) return NULL;
	Node *left = KthLargest(root->right, k);
	if (left != NULL) return left;
	k--;
	if (k == 0) return root;
	return KthLargest(root->left, k);
}

///////////////////////////////////////////////////////////////////////////
// L46. Check if a tree is a BST or BT | Validate a BST
bool isValidBST(Node *root, long mn, long mx) {
	if (root == NULL) return true;
	if (root->data >= mx || root->data <= mn) return false;
	return isValidBST(root->left, mn, root->data) && isValidBST(root->right, root->data, mx);
}
bool isValidBST(Node *root) {
	return isValidBST(root, LONG_MIN, LONG_MAX);
}

///////////////////////////////////////////////////////////////////
// L47. LCA in Binary Search Tree (lowest common ancenstore)
// TC O(logn)

// recursion
Node* LCA_BST(Node *root, Node *p, Node *q) {
	if (root == NULL) return NULL;
	int curr = root->data;
	if (curr < p->data && curr < q->data) return LCA_BST(root->right, p, q);
	if (curr > p->data && curr > q->data) return LCA_BST(root->left, p, q);
	return root;
}

// iteration
Node* LCA_BST1(Node *root, Node *p, Node *q) {
	if (p == q) return p;
	if (p == root || q == root) return root;
	Node *temp = root;
	while (temp) {
		if (temp->data < p->data && temp->data < q->data) temp = temp->right;
		else if (temp->data > p->data && temp->data > q->data) temp = temp->left;
		else return temp;
	}
	return root;
}

////////////////////////////////////////////////////////////////////////////
// L48. Construct a BST from a preorder traversal
Node* build(vector<int> &preorder, int &i, int bound) {
	if (i == preorder.size() || preorder[i] > bound) return NULL;
	Node *root = new Node(preorder[i++]);
	root->left = build(preorder, i, root->data);
	root->right = build(preorder, i, bound);
	return root;
}
Node* bstFromPreOrder(vector<int> &preorder) {
	int i = 0;
	return build(preorder, i, INT_MAX);
}

/////////////////////////////////////////////////////////////////////////////////
// L49. Inorder Successor/Predecessor in BST
int inorder_succesor(Node *root, int val) {
	int res = -1;
	vector<int> ans = inOrder_loop(root);
	// for (auto it : ans) cout << it << " ";
	// cout << endl;
	for (int i = 0; i < ans .size(); i++) {
		if (ans[i] == val) {
			i++;
			res = ans[i];
			break;
		}
	}
	return res;
}

//2nd method
int  inorder_succesor1(Node *root, int val) {
	int res = -1;
	while (root) {
		if (val >= root->data) root = root->right;
		else {
			res  = root->data;
			root = root->left;
		}
	}
	return res;
}

////////////////////////////////////////////////
// L50. Binary Search Tree Iterator | BST
// SC O(H)
// TC O(1)
class BASIterator {
private :
	stack<Node*> st;
public :
	BASIterator(Node *root) {
		pushAll(root);
	}

	// @return whether we have a next smallest number
	bool hasNext() {
		return !st.empty();
	}

	// @return the next smallest element
	int next() {
		Node *tmpNode = st.top();
		st.pop();
		pushAll(tmpNode->right);
		return tmpNode->data;
	}

private :
	void pushAll(Node *node) {
		for (; node != NULL; st.push(node), node = node->left);
	}

};

/////////////////////////////////////////////////////////////////////////////
// L51. Two Sum In BST | Check if there exists a pair with Sum K
// TC O(N)
// SC O(N)
bool twoSumBST(Node *root, int k) {
	vector<int> ans = inOrder_loop(root);
	int l = 0, h = ans.size() - 1;
	while (l < h) {
		int sum = ans[l] + ans[h];
		if (sum == k) return true;
		else if (sum > k) h--;
		else if (sum < k) l++;
	}
	return false;
}


// 2nd approach
// TC O(N)
// SC O(H) // space is optimieze compare to first approach
class twoSumBST1 {
	stack<Node*> st;
	bool reverse = true;
public:
	twoSumBST1(Node *root, bool isReverse) {
		reverse = isReverse;
		pushAll(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !st.empty();
	}

	/** @return the next smallest number */
	int next() {
		Node *tmp = st.top();
		st.pop();
		if (!reverse) pushAll(tmp->right);
		else pushAll(tmp->left);
		return tmp->data;
	}

private:
	void pushAll(Node *node) {
		for (; node != NULL; ) {
			st.push(node);
			if (reverse == true) node = node->right;
			else node = node->left;
		}
	}
};

class _Solution {
public:
	bool findTarget(Node *root, int k) {
		if (!root) return false;
		twoSumBST1 l(root, false);
		twoSumBST1 h(root, true);

		int i = l.next();
		int j = h.next();

		while (i < j) {
			if (i + j == k) return true;
			else if (i + j > k) j = h.next();
			else if (i + j < k) i = l.next();
		}
		return false;
	}
};

///////////////////////////////////////////////////////////
// L52. Recover BST | Correct BST with two nodes swapped
class BSTTree {
public:
	Node *first, *middle , *last, *prev ;
	void _inorderV(Node *root) {
		if (root == NULL) return;
		_inorderV(root->left);
		if (prev != NULL && root->data < prev->data) {
			// if this is first violation mark these two nodes as
			// 'first' ans 'middle'
			if (first == NULL) {
				first = prev;
				middle = root;
			} else {
				// if this is second voilation , mark this node as last
				last = root;
			}
		}

		// mark this node as previous
		prev = root;
		_inorderV(root->right);
	}
	void recoverTree(Node *root) {
		first = middle = last = NULL;
		prev = new Node(INT_MIN);
		_inorderV(root);
		if (first && last) swap(first->data, last->data);
		else if (first && middle) swap(first->data, middle->data);
	}
};
void solve_recoverTree() {
	Node *root = new Node(3);
	root->left = new Node(1);
	root->right  = new Node(4);
	root->right->left = new Node(2);

	inOrder(root);
	BSTTree bt;
	bt.recoverTree(root); cout << endl;
	inOrder(root);
}

////////////////////////////////////////////////////////////////
// L53. Largest BST in Binary Tree
class NodeValue {
public:
	int mxNode, mnNode , mxSize;
	NodeValue(int mnNode, int mxNode, int mxSize) {
		this->mxNode = mxNode;
		this->mnNode = mnNode;
		this->mxSize = mxSize;
	}
};

class Solution_NodeValue {
private:
	NodeValue largestBSTSubTreeHelper(Node *root) {
		// An empty tree is a BST of size 0
		if (!root)
			return NodeValue(INT_MAX, INT_MIN, 0);

		// get values from left and right subtree of current tree
		auto left = largestBSTSubTreeHelper(root->left);
		auto right = largestBSTSubTreeHelper(root->right);

		// current node is grater than mx in left And smaller than min in right, it is BST
		if (left.mxNode < root->data && root->data < right.mnNode)
			// it is BST
			return NodeValue(min(root->data, left.mnNode), max(root->data, right.mxNode), left.mxSize + right.mxSize + 1);


		// otherwise return [-inf, inf] so that parent can't be valid BST
		return NodeValue(INT_MIN, INT_MAX, max(left.mxSize, right.mxSize));
	}
public :
	int largestBSTSubTree(Node *root) {
		return largestBSTSubTreeHelper(root).mxSize;
	}
};
void solve_binary_search_tree() {
	Node *root = new Node(8);
	root->left = new Node(5);
	root->right = new Node(12);
	root->left->left = new Node(2);
	root->left->right = new Node(7);
	root->right->left = new Node(10);
	root->right->right = new Node(13);
	root->left->left->left = new Node(1);
	root->left->left->right = new Node(3);
	root->left->right->left = new Node(6);
	root->left->left->right->right = new Node(4);

	////////////////////////////////////////////////////////////////////////////
	// L40. Search in a Binary Search Tree | BST
	// int val = 5;
	// if (searchBST(root, val)->data == val) cout << " found value in the BST";
	// else cout << " value is not found in the BST";

	//////////////////////////////////////////////////////////////////////////////////
	// L41. Ceil in a Binary Search Tree | BST
	// cout << findCeil(root, 10);


	///////////////////////////////////////////////////////////////
	// L42. Floor in a Binary Search Tree
	// cout << findFloor(root, 10);


	////////////////////////////////////////////////////////////////////
	// L43. Insert a given Node in Binary Search Tree
	// inOrder(insertIntoBST(root, 11));

	////////////////////////////////////////////////////////////////
	// L44. Delete a Node in Binary Search Tree | BST
	// inOrder(deleteNode(root, 5));

	//////////////////////////////////////////////////////
	// L45. K-th Smallest/Largest Element in BST
	// vector<int> vec;
	// int k = 3;
	// KthSmallest(root, vec);
	// sort(vec.begin(), vec.end()); // sort vector
	// cout << vec[k - 1] << endl;

	// int k = 3;
	// cout << KthSmallest1(root, k);
	// cout << KthLargest(root, k)->data;


	///////////////////////////////////////////////////////////////////////////
	// L46. Check if a tree is a BST or BT | Validate a BST
	// cout << isValidBST(root);

	///////////////////////////////////////////////////////////////////////////
	// L47. LCA in Binary Search Tree (lowest common ancenstore)
	// cout << LCA_BST(root, root->right, root->left->right)->data;
	// cout << LCA_BST1(root, root->right, root->left->right)->data;

	//////////////////////////////////////////////////////////////////////////////
	// L48. Construct a BST from a preorder traversal
	// vector<int> preorder = {8, 5, 1, 7, 10, 12};
	// inOrder(bstFromPreOrder(preorder));

	/////////////////////////////////////////////////////////////////
	// L49. Inorder Successor/Predecessor in BST
	// int val = 7;
	// cout << inorder_succesor(root, 7) << endl;
	// cout << inorder_succesor1(root, 7) << endl;


	//////////////////////////////////////////////////////////////
	// L50. Binary Search Tree Iterator | BST
	// BASIterator bs(root);
	// cout << bs.next()  << " ";
	// cout << bs.next() << endl;
	// cout << (bs.hasNext() ? "Yes" :  "No") << endl;
	// cout << bs.next() << endl;
	// cout << bs.next() << endl;
	// cout << bs.next() << endl;
	// cout << bs.next() << endl;
	// cout << (bs.hasNext() ? "Yes" :  "No") << endl;
	// cout << bs.next() << endl;
	// cout << bs.next() << endl;
	// cout << bs.next() << endl;
	// cout << bs.next() << endl;
	// cout << bs.next() << endl;
	// cout << (bs.hasNext() ? "Yes" :  "No") << endl;

	///////////////////////////////////////////////////////////////////////
	// L51. Two Sum In BST | Check if there exists a pair with Sum K
	// cout << twoSumBST(root, 7);
	// _Solution s;
	// cout << s.findTarget(root, 7);

	///////////////////////////////////////////////////////////////
	// L52. Recover BST | Correct BST with two nodes swapped
	// solve_recoverTree();

	////////////////////////////////////////////////////////////////
	// L53. Largest BST in Binary Tree
	Solution_NodeValue sn;
	cout << sn.largestBSTSubTree(root);
}
void solve_binary_tree() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);

	root->right = new Node(3);
	root->right->left = new Node(7);
	root->right->right = new Node(8);
	root->right->right->left = new Node(9);
	root->right->right->right = new Node(10);



//---------------  recursive methods --------------------
	// preOrder(root); cout << endl;
	// inOrder(root); cout << endl;
	// postOrder(root); cout << endl;
	// for(auto it : levelOrder(root)) {
	// 	for(auto i : it) cout << i << " ";
	// 	cout << endl;
	// }


//--------------- iterative methods --------------------
	// for (auto it : preOrder_loop(root)) cout << it << " "; cout << endl;
	// for (auto it : inOrder_loop(root)) cout << it << " "; cout << endl;
	// for (auto it : postOrder_loop_2stack(root)) cout << it << " "; cout << endl;
	// for (auto it : postOrder_loop_1stack(root)) cout << it << " "; cout << endl;

	//////////////////////////////////////////////////
	// maxDepth
	// cout << maxDepth(root);

	/////////////////////////////////
	// check balnaced BT
	// cout << isBalanced(root);
	// cout << isBalanced1(root);

	////////////////////
	// cout << diameterOfBinaryTree(root);


	///////////////////
	// maxPathSum
	// cout << maxPathSum(root);


	////////////////////////
	// both the tree are same
	// solve_isSameTree();

	////////////////////////
	//  L19. Zig-Zag or Spiral Traversal in Binary Tree
	// for (auto it : zigzageLevel(root)) {
	// 	for (auto x : it) cout << x << " ";
	// 	cout << endl;
	// }

	////////////////////////////////////////
	// L20. Boundary Traversal in Binary Tree
	// for (auto it : printBoundary(root)) cout << it << " ";

	////////////////////////////////////////
	// L21 : Vertical Order Traversal of Binary Tree
	// for (auto i : verticalTraversal(root)) {
	// 	for (auto x : i) cout << x << " ";
	// 	cout << endl;
	// }


	///////////////////////////////////////
	// L22. Top View of Binary Tree
	// for (auto i : topView(root)) cout << i << " ";

	//////////////////////////////////
	// L23. Bottom View of Binary Tree
	// for (auto i : bottomView(root)) cout << i << " ";


	/////////////////////////////////
	// L24 : Right/left view of Binary Tree
	// for (auto i : rightView(root)) cout << i << " ";
	// for (auto i : rightView1(root)) cout << i << " ";
	// for (auto i : leftView(root)) cout << i << " "; cout << endl;
	// for (auto i : leftView1(root)) cout << i << " ";


	/////////////////////////////////////////////
	// L25. Check for Symmetrical Binary Trees
	// solve_isSymmetric();

	////////////////////////////////////////////////////
	// L26. Print Root to Node Path in Binary Tree
	// for (auto it : node_path(root, 7)) cout << it << " ";


	////////////////////////////////////////////////////////
	// L27. Lowest Common Ancestor in Binary Tree
	// ------------- naive approach ---------------
	// int k1 = 6, k2 = 4;
	// vector<int> a1 = node_path(root , k1 );
	// vector<int> a2 = node_path(root , k2);
	// int LCAN; // lowestCommonAncenstor
	// for (int i = 0; i < min(a1.size(), a2.size()); i++)
	// 	if (a1[i] == a2[i]) LCAN = a1[i];
	// cout << LCAN << endl;

	//   ----------- optimal approach
	// Node * p = new Node(6);
	// Node * q = new Node(4);
	// Node* ans = LCA(root, p, q);
	// cout << ans->data << endl;


	/////////////////////////////////////////////////
	// L28. Maximum Width of Binary Tree
	// cout << widthOfBinaryTree(root) << endl;


	////////////////////////////////////////////////////
	// L29. Children sum property in Binary Tree
	// solve_changeTree();
	/////
	// solve_isSumProperty();

	//////////////////////////////////////////
	// L30. Print all the Nodes at a distance of K in Binary Tree
	// solve_distanceK();

	///////////////////////////////////////////////////
	// L31. Minimum time taken to BURN the Binary Tree from a Node
	// solve_timeToBurn();

	//////////////////////////////////////////////////////////
	// L32. Count total Nodes in a COMPLETE Binary Tree
	// solve_countNodes();

	////////////////////////////////////////////////////////////
	// L33. Requirements needed to construct a Unique Binary Tree
	// solve_buildTree();

	////////////////////////////////////////////////////////////////////////
	// L35. Construct the Binary Tree from Postorder and Inorder Traversal
	// solve_buildTree1();

	////////////////////////////////////////////////////////////////////////
	// L36. Serialize and De-serialize Binary Tree
	// inOrder(seralize_deseralize(root)); // free printing


	///////////////////////////////////////////////////////////////////////////////
	// L37. Morris Traversal | Preorder | Inorder
	// for (auto i : getInOrder(root)) cout << i << " "; cout << endl;
	// for (auto i : getPreOrder(root)) cout << i << " "; cout << endl;


	///////////////////////////////////////////////////////////////////////////////////
	// L38. Flatten a Binary Tree to Linked List | 3 Approaches
	// solve_flatten();

	////////////////////////////////////////////////////////////////////////////
	// L40. Search in a Binary Search Tree | BST
	// L41. Ceil in a Binary Search Tree | BST
	// L42. Floor in a Binary Search Tree
	// L43. Insert a given Node in Binary Search Tree
	// L44. Delete a Node in Binary Search Tree | BST
	// L45. K-th Smallest/Largest Element in BST
	solve_binary_search_tree();
}
int main() {
	solve_binary_tree();
}