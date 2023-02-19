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

struct Node {
    int data ;
    Node *next; // because of this we called this structure , self refrencing structure
    Node(int x) {
        data = x;
        next = NULL;
    }
};

////////////////////////////////////////////////////////////////////////////////
// [25]. => 206. Reverse Linked List
// link  => https://leetcode.com/problems/reverse-linked-list/

Node* reverseList(Node * head) {
    Node * prev = NULL;
    Node * curr = head;
    while (curr != NULL) {
        Node * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void solve_reverseList() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* reversedHead = reverseList(head);
    Node * curr = reversedHead;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
// [26]. => 876. Middle of the Linked List
// link  => https://leetcode.com/problems/middle-of-the-linked-list/description/

// TC -> O(n)
// SC -> O(1)
Node * middleNode(Node * head) {
    Node * curr = head;
    int n = 0;
    while (curr != NULL) {
        n++;
        curr = curr->next;
    }

    int index = (n / 2) + 1; // when odd than -> 5/ 2 = 2 + 1 = 3 is the middle
    //  when enven than 2 middle element => 6 / 2 = 3 and 4 are middle we want second middle = 6 / 2 = 3 + 1 = 4

    curr = head;
    for (int i = 1; i < index; i++) {
        curr = curr->next;
    }
    return curr;
}


// TC -> O(n)
// SC -> O(1)
// optimal approach
Node * middleNode1(Node * head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; // move 1 step
        fast = fast->next->next; // move 2 step
    }
    return slow;
}

void solve_middleNode() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // head->next->next->next->next->next = new Node(6);

    // Node * node = middleNode(head);
    Node * node = middleNode1(head);
    cout << node->data << endl;
}

////////////////////////////////////////////////////////////////////////////////
// [27]. => 21. Merge Two Sorted Lists
// link  => https://leetcode.com/problems/merge-two-sorted-lists/

// TC O(N+M)
// SC O(1)
Node* mergeTwoLists(Node* l1, Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    Node * ptr;
    if (l1->data < l2->data) {
        ptr = l1;
        l1 = l1->next;
    } else {
        ptr = l2;
        l2 = l2->next;
    }

    Node * curr = ptr;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    // reamaning elements from bigger list
    if (!l1) curr->next = l2;
    else curr->next = l1;
    return ptr;
}


// TC O(N+M)
// SC O(1)
// less code -> short code approach
Node* mergeTwoLists1(Node* l1, Node* l2) {
    Node * dummy = new Node(-1);
    Node * curr = dummy;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
    }

    curr->next = l1 ? l1 : l2;
    return dummy->next; // dummy -> containt -1, so start from dummy->next
}
void solve_mergeTwoLists() {
    Node* l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = new Node(3);

    Node* l2 = new Node(1);
    l2->next = new Node(1);
    l2->next->next = new Node(3);
    l2->next->next->next = new Node(4);

    // Node * node = mergeTwoLists(l1, l2);
    Node * node = mergeTwoLists(l1, l2);
    while (node != NULL) {
        cout << node->data << "->";
        node = node->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
// [28]. => 19. Remove Nth Node From End of List
// link  => https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// TC O(N)
// SC O(1)
Node* removeNthFromEnd(Node* head, int n) {
    // 1->2->3->4->5 => n = 2 => 4 remove from last
    Node * dummy = new Node(-1);
    dummy->next = head;
    int count = 0;

    Node * curr = dummy;
    while (curr->next) {
        curr = curr->next;
        count++;
    }

    curr = dummy;
    // -1 1 2 3 4 5 // 5 - 2 = 3// i < 3 = 2 ---> so -> 0 1 2
    //  0 1 2 3 4 5
    for (int i = 0; i < count - n; i++) {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return dummy->next;
}

// TC O(N)
// SC O(1)
// optimal approach
Node* removeNthFromEnd1(Node* head, int n) {
    // 1->2->3->4->5 => n = 2 => 4 remove from last
    Node * dummy = new Node(-1);
    dummy->next = head;
    Node * slow = dummy, *fast = dummy;
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}
void solve_removeNthFromEnd() {
    int n = 2;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Node * node = removeNthFromEnd(head, n);
    Node * node = removeNthFromEnd1(head, n);
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}


////////////////////////////////////////////////////////////////////////////////
// [29]. => 2. Add Two Numbers
// link  => https://leetcode.com/problems/add-two-numbers/

// TC O(max(n, m)
// SC O(max(n, m)
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node * dummy = new Node(0);
    Node * curr = dummy;
    int carry = 0;
    while (l1 || l2) {
        int x = l1 ? l1->data : 0;
        int y = l2 ? l2->data : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    // reamaning carry
    if (carry > 0) {
        curr->next = new Node(carry);
    }
    return dummy->next;
}


// TC O(max(n, m))
// SC O(max(n, m))
Node* addTwoNumbers1(Node* l1, Node* l2) {
    Node * dummy = new Node(0);
    Node * curr = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int x = l1 ? l1->data : 0;
        int y = l2 ? l2->data : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy->next;
}

void solve_addTwoNumbers() {
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    // Node * node = addTwoNumbers(l1, l2);
    Node * node = addTwoNumbers1(l1, l2);
    while (node != NULL) {
        cout << node->data << "->";
        node = node->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
// [30]. => 237. Delete Node in a Linked List
// link  => https://leetcode.com/problems/delete-node-in-a-linked-list/


// TC O(1)
// SC O(1)
void deleteNode(Node* node) {
    Node * temp = node->next;
    node->data = temp->data;
    node->next  = temp->next;
    delete temp;
}

void solve_deleteNode() {
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);
    deleteNode(head->next);

    Node * curr = head;
    while (curr != NULL) {
        cout << curr->data << "->";
        curr = curr->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
// [31]. => 160. Intersection of Two Linked Lists
// link  => https://leetcode.com/problems/intersection-of-two-linked-lists/

// TC O(m * n)
// SC O(1)
Node* getIntersectionNode(Node *headA, Node *headB) {
    Node * a = headA;
    while (a != NULL) {
        Node * b = headB;
        while (b != NULL) {
            if (a == b) return a; // check if Address match or not // match than return
            b = b->next;
        }
        a = a->next;
    }
    return NULL;
}


// INTUTION :
/* This approach utilizes the fact that the intersection of two lists will always be the same distance from the
end of both lists, regardless of the length of the lists.
This is due to the fact that the intersection starts at the same point
in both lists and extends to the end.

The approach is to initialize two pointers, "a" and "b", to
the head of the two lists, respectively. Then, while "a" and
"b" are not equal, we update the pointers by moving them to the
next node in their respective lists. If either pointer reaches the end
of its list, we "wrap around" and set it to the head of the other list.

By doing this, both pointers will traverse both lists and
will eventually meet at the intersection point if there is one.
If there is no intersection, both pointers will reach the end of
both lists and will be equal to nullptr.
*/

// TC O(m + n)
// SC O(1)
Node* getIntersectionNode1(Node *headA, Node *headB) {
    Node * a = headA;
    Node * b = headB;

    while (a != b) {
        a = (a != NULL) ? a->next : headB;
        b = (b != NULL) ? b->next : headA;
    }
    return a;
}


void solve_getIntersectionNode() {
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = new Node(8);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next = new Node(5);

    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = headA->next->next; // This makes the intersection at 8
    headB->next->next->next->next = new Node(4);
    headB->next->next->next->next->next = new Node(5);


    // Node * node = getIntersectionNode(headA, headA);
    Node * node = getIntersectionNode1(headA, headA);
    cout << node->data << " ";
}


////////////////////////////////////////////////////////////////////////////////
// [32]. => 141. Linked List Cycle
// link  => https://leetcode.com/problems/linked-list-cycle/

// TC O(n)
// SC O(n)
bool hasCycle(Node * head) {
    if (!head || !head->next) return false;
    unordered_set<Node*> visited;
    Node * curr = head;
    while (curr != NULL) {
        if (visited.find(curr) != visited.end()) return true;
        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}

// TC O(n)
// SC O(1)
bool hasCycle1(Node * head) {
    if (!head || !head->next) return false;
    Node * slow = head;
    Node * fast = head;
    while (fast && fast->next) {
        slow = slow->next; // move 1 step
        fast = fast->next->next; // move 2 step
        if (slow == fast) return true;
    }
    return false;
}
void solve_hasCycle() {
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;

    // bool flag = hasCycle(head);
    bool flag = hasCycle1(head);
    if (flag) cout << " yes cycle is detected" << endl;
    else cout << " No cycle is detected";
}

////////////////////////////////////////////////////////////////////////////////
// [33]. => 25. Reverse Nodes in k-Group
// link  => https://leetcode.com/problems/reverse-nodes-in-k-group/

// TC O(k * n) = O(n) -> because k is constant
Node* reverseKGroup(Node* head, int k) {
    Node * curr = head;
    int count = 0;
    while (curr && count != k) {
        count++;
        curr = curr->next;
    }

    if (count == k) {
        curr = reverseKGroup(curr, k);
        while (count-- > 0) {
            Node * temp = head->next;
            head->next = curr;
            curr = head;
            head = temp;
        }
        head = curr;
    }
    return head;
}

void solve_reverseKGroup() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node * node = reverseKGroup(head, 2);
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}


////////////////////////////////////////////////////////////////////////////////
// [34]. => 234. Palindrome Linked List
// link  => https://leetcode.com/problems/palindrome-linked-list/

// TC O(n)
// TC O(1) // because we are using stack but we are storing half records only
bool isPalindrome(Node* head) {
    Node * slow = head;
    Node * fast = head;
    stack<int> s;
    while (fast && fast->next) {
        s.push(slow->data);
        slow = slow->next; // 1 step move
        fast = fast->next->next; // 2 step move
    }
    if (fast) slow = slow->next; // this is when nodes are odd // so we can reach to middle of the node
    while (slow) {
        int val = s.top();
        s.pop();
        if (val != slow->data) return false;
        slow = slow->next;
    }
    return true;
}

// TC O(n)
// TC O(1)
bool isPalindrome1(Node* head) {
    if (!head || !head->next) return true;
    Node * slow  = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    fast = head;
    slow = slow->next;

    while (slow) {
        if (slow->data  != fast->data) return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
void solve_isPalindrome() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // bool ans = isPalindrome(head);
    bool ans = isPalindrome1(head);
    if (ans) cout << " yes string is palidrome " << endl;
    else cout << " string is not palidrome" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// [35]. => 142. Linked List Cycle II
// link  => https://leetcode.com/problems/linked-list-cycle-ii/

// TC O(N)
// SC O(N)
Node *detectCycle(Node *head) {
    unordered_set<Node*> st;
    Node * curr = head;
    while (curr) {
        if (st.find(curr) != st.end()) return curr;
        st.insert(curr);
        curr = curr->next;
    }
    return NULL;
}


// TC O(N)
// SC O(1)
Node *detectCycle1(Node *head) {
    if (!head || !head->next) return NULL;
    Node * slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            Node * slow2 = head;
            while (slow2 != slow) {
                slow = slow->next;
                slow2 = slow2->next;
            }
            return slow;
        }
    }
    return NULL;
}
void solve_detectCycle() {
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next = head->next;

    // Node * node  = detectCycle(head);
    Node * node  = detectCycle1(head);
    cout << node->data << " ";
}

////////////////////////////////////////////////////////////////////////////////
// [36]. => Flattening a Linked List
// link  => https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
struct Node1 {
    int data ;
    Node1 *next; // because of this we called this structure , self refrencing structure
    Node1 *bottom;
    Node1(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


// TC O(N)
// SC O(1)
Node1* merge(Node1 * a, Node1 * b) {
    Node1 * temp = new Node1(0);
    Node1 * res = temp;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    // reamaning elements
    if (a) temp->bottom = a;
    else temp->bottom = b;
    return res->bottom;
}
Node1* flatten(Node1 * head) {
    if (head == NULL || head->next == NULL) return head;

    // recur for list on right
    head->next = flatten(head->next);

    // now merge
    head = merge(head, head->next);
    return head;
}


void solve_flatten() {
    Node1* head = new Node1(5);
    head->next = new Node1(10);
    head->next->next = new Node1(19);
    head->next->next->next = new Node1(28);

    head->bottom = new Node1(7);
    head->bottom->bottom = new Node1(8);
    head->bottom->bottom->bottom = new Node1(30);

    head->next->bottom = new Node1(20);
    head->next->next->bottom = new Node1(22);
    head->next->next->bottom->bottom = new Node1(50);

    head->next->next->next->bottom = new Node1(35);
    head->next->next->next->bottom->bottom = new Node1(40);
    head->next->next->next->bottom->bottom->bottom = new Node1(45);

    head = flatten(head);

    Node1* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->bottom;
    }
}

////////////////////////////////////////////////////////////////////////////////
// [37]. => 61. Rotate List
// link  => https://leetcode.com/problems/rotate-list/description/


// TC O(N)
// SC O(1)
Node* rotateRight(Node* head, int k) {
    // edge cases
    if (!head || !head->next || k == 0) return head;

    // compute the length
    Node * cur = head;
    int len = 1;
    while (cur->next && len++)
        cur = cur->next;

    // go till last node
    cur->next = head;
    k = k % len;
    k = len - k; // find the new last node
    while (k--) cur = cur->next;

    // make the node head and break the connection
    head = cur->next;
    cur->next = NULL;

    return head;
}

void solve_rotateRight() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 2;
    Node * node = rotateRight(head, k);
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
// [38]. => 138. Copy List with Random Pointer
// link  => https://leetcode.com/problems/copy-list-with-random-pointer/description/

// TC O(N)
// SC O(N)

struct Node2 {
    int data ;
    Node2 *next; // because of this we called this structure , self refrencing structure
    Node2 *random; // because of this we called this structure , self refrencing structure
    Node2(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

// TC O(N)
// SC O(N)
Node2 * copyRandomList(Node2 * head) {
    unordered_map<Node2*, Node2*> cl;
    for (Node2 *curr = head; curr != NULL; curr = curr->next)
        cl[curr] = new Node2(curr->data);

    for (Node2 * curr = head; curr != NULL; curr = curr->next) {
        Node2 * clcurr =  cl[curr];
        clcurr->next = cl[curr->next];
        clcurr->random = cl[curr->random];
    }

    Node2 * head2 = cl[head];
    return head2;
}



// TC O(N)
// SC O(1)
Node2 * copyRandomList1(Node2 * head) {
    // Iterate through the original list and create a copy of each node,
    // and insert it right after the original node
    for (Node2 * curr = head; curr != NULL; curr = curr->next) {
        Node2 * copy = new Node2(curr->data);
        copy->next = curr->next;
        curr->next = copy;
    }

    // Iterate through the copy list and set the random pointer for each node22
    for (Node2 * curr = head; curr != NULL; curr = curr->next)
        curr->next->random = curr->random ? curr->random->next : NULL;

    // separate original linked from copy LinkedList
    Node2 * dummy = new Node2(0);
    Node2 * copy = dummy;
    for (Node2 * curr = head; curr != NULL; curr = curr->next) {
        copy->next = curr->next;
        copy = copy->next;
        curr->next = copy->next;
    }

    return dummy->next;
    // Return the head of the copy list
}

void solve_copyRandomList() {
    // Create the nodes of the list
    Node2 *n1 = new Node2(7);
    Node2 *n2 = new Node2(13);
    Node2 *n3 = new Node2(11);
    Node2 *n4 = new Node2(10);
    Node2 *n5 = new Node2(1);

    // Connect the nodes to form the list
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Set the random pointers for the nodes
    n2->random = n1;
    n4->random = n3;
    n5->random = n1;

    // Head of the list
    Node2 *head = n1;

    // Print the values of the list
    Node2 *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Print the values of the random pointers of the nodes
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL)
            cout << curr->random->data << " ";
        else
            cout << "NULL" << " ";
        curr = curr->next;
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////
// [39]. => 15. 3Sum
// link  => https://leetcode.com/problems/3sum/

// TC O(N ^ 3)
// SC O(N ^ 2)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) return res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> trip = {nums[i] , nums[j] , nums[k]};
                    if (find(res.begin(), res.end(), trip) == res.end()) {
                        res.push_back(trip);
                    }
                }
            }
        }
    }
    return res;
}

// TC O(N * N)
// SC O(N * N)
vector<vector<int>> threeSum1(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 3) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                vector<int> trip = {nums[i] , nums[left] , nums[right]};
                res.push_back(trip);
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right]  == nums[right - 1]) right--;
                left++, right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return res;
}
void solve_threeSum() {
    vector<int> nums = { -1, 0, 1, 2, -1, -4};
    // for (auto i : threeSum(nums)) {
    for (auto i : threeSum1(nums)) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////
// [40]. => 42. Trapping Rain Water
// link  => https://leetcode.com/problems/trapping-rain-water/description/

// TC O(N * N)
// SC O(1)
int trap (vector<int> & height) {
    int n = height.size();
    int waterTrapp = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0) {
            leftMax = max(leftMax, height[j]);
            j--;
        }

        j = i;
        while (j < n) {
            rightMax  = max(rightMax, height[j]);
            j++;
        }
        waterTrapp += min(leftMax, rightMax) - height[i];
    }
    return waterTrapp;
}

// TC O(N)
// SC O(N)
int trap1(vector<int> & height) {
    int n = height.size();
    int left[n], right[n], res = 0;

    left[0] = height[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], height[i]);

    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] =  max(right[i + 1], height[i]);

    for (int i = 0; i < n; i++)
        res = res + min(left[i], right[i]) - height[i];
    return res;
}
void solve_trap() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // cout << "The water that can be trapped is " << trap(arr) << endl;
    cout << "The water that can be trapped is " << trap1(height) << endl;
}

////////////////////////////////////////////////////////////////////////////////
// [41]. => 26. Remove Duplicates from Sorted Array
// link  => https://leetcode.com/problems/remove-duplicates-from-sorted-array/


// TC O(N)
// SC O(N)
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    set < int > set;
    for (int i = 0; i < n; i++) {
        set.insert(nums[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x : set) {
        nums[j++] = x;
    }
    return k;
}

// TC O(N)
// SC O(1)
int removeDuplicates1(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

// TC O(N)
// SC O(1)
int removeDuplicates2(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[i] == nums[j]) {
            nums.erase(nums.begin() + j);
            n--;
            j--;
        } else {
            i++;
        }
    }
    return n;
}
void solve_removeDuplicates() {
    // 0, 1, 2, 3, 4
    // vector<int> nums = {1, 1, 2};
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // cout << removeDuplicates(nums);
    cout << removeDuplicates1(nums);
}

////////////////////////////////////////////////////////////////////////////////
// [42]. => 485. Max Consecutive Ones
// link  => https://leetcode.com/problems/max-consecutive-ones/

// TC O(N)
// SC O(N)
int findMaxConsecutiveOnes(vector<int>& nums) {
    unordered_map<int, int> m;
    int mx = 0;
    for (auto x : nums) {
        if (x == 1) m[1]++;
        else m[1] = 0;
        mx = max(mx, m[1]);
    }
    return mx;
}

// TC O(N)
// SC O(1)
int findMaxConsecutiveOnes1(vector<int>& nums) {
    int mx = 0, count = 0;
    for (auto x : nums) {
        if (x == 1) count++;
        else count = 0;
        mx = max(mx, count);
    }
    return mx;
}

void solve_findMaxConsecutiveOnes() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    // cout << findMaxConsecutiveOnes(nums);
    cout << findMaxConsecutiveOnes1(nums);
}



int main() {
    init_code();

    // solve_reverseList(); // 25
    // solve_middleNode(); // 26
    // solve_mergeTwoLists(); // 27
    // solve_removeNthFromEnd(); // 28
    // solve_addTwoNumbers(); // 29
    // solve_deleteNode(); // 30
    // solve_getIntersectionNode(); // 31
    // solve_hasCycle(); // 32
    // solve_reverseKGroup(); // 33
    // solve_isPalindrome(); // 34
    // solve_detectCycle(); // 35
    // solve_flatten(); // 36
    // solve_rotateRight(); // 37
    // solve_copyRandomList(); // 38
    // solve_threeSum(); // 39
    // solve_trap(); // 40
    // solve_removeDuplicates(); // 41
    // solve_findMaxConsecutiveOnes(); // 42
    
}