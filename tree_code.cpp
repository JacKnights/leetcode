#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include "helper.cpp"

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class TreeSolution {
   public:

    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> que;
        queue<int> level;
        que.push(root);
        level.push(1);
        int res = 1;
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            int depth = level.front();
            level.pop();
            res = max(res, depth);
            if (cur->left) {
                que.push(cur->left);
                level.push(depth + 1);
            }
            if (cur->right) {
                que.push(cur->right);
                level.push(depth + 1);
            }
        }
        return res;
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int rows = maxDepth(root);
        int cols = pow(2, rows) - 1;
        vector<vector<string>> res(rows, vector<string>(cols, ""));

        stack<pair<TreeNode*, vector<int>>> st;
        TreeNode* cur = root;
        vector<int> xy = {0, (cols - 1) / 2};
        while (!st.empty() || cur) {
            while (cur) {
                st.push(make_pair(cur, xy));

                res[xy[0]][xy[1]] = to_string(cur->val);

                xy[1] = xy[1] - pow(2, rows - 2 - xy[0]);
                xy[0] = xy[0] + 1;
                cur = cur->left;
            }
            cur = st.top().first;
            xy = st.top().second;
            st.pop();

            xy[1] = xy[1] + pow(2, rows - 2 - xy[0]);
            xy[0] = xy[0] + 1;
            cur = cur->right;
        }

        return res;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st0;
        stack<TreeNode*> st1;
        TreeNode* cur0 = p;
        TreeNode* cur1 = q;
        while (!st0.empty() || cur0 || !st1.empty() || cur1) {
            while (cur0 || cur1) {
                if (!cur0 || !cur1) {
                    return false;
                }
                if (cur0->val != cur1->val) {
                    return false;
                }
                st0.push(cur0);
                cur0 = cur0->left;

                st1.push(cur1);
                cur1 = cur1->left;
            }
            cur0 = st0.top();
            st0.pop();
            cur0 = cur0->right;

            cur1 = st1.top();
            st1.pop();
            cur1 = cur1->right;
        }
        return true;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur) {
            if (cur) {
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                cur = cur->right;
            }
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            ans.push_back(cur->val);
            st.pop();
            cur = cur->right;
        }
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                ans.push_back(cur->val);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            cur = cur->left;
        }
        for (int i = 0, j = ans.size() - 1; i < j; i++, j--) {
            int tmp = ans[i];
            ans[i] = ans[j];
            ans[j] = tmp;
        }
        return ans;
    }

    TreeNode* buildTreeHelper(map<int, int>& in_idx, vector<int>& preorder, int r, int len, vector<int>& inorder, int st, int ed) {
        if (len == 0) {
            return NULL;
        }
        int mid = in_idx[preorder[r]];
        TreeNode* res =
            new TreeNode(preorder[r], buildTreeHelper(in_idx, preorder, r + 1, mid - st, inorder, st, mid), buildTreeHelper(in_idx, preorder, r + 1 + mid - st, ed - (mid + 1), inorder, mid + 1, ed));
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> in_idx;
        for (int i = 0; i < inorder.size(); i++) {
            in_idx[inorder[i]] = i;
        }
        return buildTreeHelper(in_idx, preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    // 95. Unique Binary Search Trees II
    vector<TreeNode*> generateTreesHelper(int st, int ed) {
        if (st > ed) {
            return {NULL};
        }
        if (st == ed) {
            return {new TreeNode(st)};
        }
        vector<TreeNode*> res;
        for (int i = st; i <= ed; i++) {
            vector<TreeNode*> left = generateTreesHelper(st, i - 1);
            vector<TreeNode*> right = generateTreesHelper(i + 1, ed);
            for (int x = 0; x < left.size(); x++) {
                for (int y = 0; y < right.size(); y++) {
                    res.push_back(new TreeNode(i, left[x], right[y]));
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            return {};
        }
        return generateTreesHelper(1, n);
    }

    // 98. Validate Binary Search Tree
    bool isValidBST(TreeNode* root) {
        vector<int> inorder = inorderTraversal(root);
        for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i] >= inorder[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // 99. Recover Binary Search Tree
    TreeNode* findMaxOrMinVal(vector<TreeNode*> ns, bool is_max) {
        TreeNode* res = nullptr;
        for (int i = 0; i < ns.size(); i++) {
            if (ns[i]) {
                if (!res || (is_max && res->val < ns[i]->val) || (!is_max && res->val > ns[i]->val)) {
                    res = ns[i];
                }
            }
        }
        return res;
    }
    TreeNode* maxMinVal(TreeNode* root, bool is_max) {
        TreeNode* left = nullptr;
        if (root->left) {
            left = maxMinVal(root->left, is_max);
        }
        TreeNode* right = nullptr;
        if (root->right) {
            right = maxMinVal(root->right, is_max);
        }
        TreeNode* res = findMaxOrMinVal({root, left, right}, is_max);
        return res;
    }
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur) {
            while (cur) {
                TreeNode* max_left = cur;
                TreeNode* min_right = cur;
                if (cur->left) {
                    max_left = maxMinVal(cur->left, true);
                }
                if (cur->right) {
                    min_right = maxMinVal(cur->right, false);
                }
                if (min_right->val < max_left->val) {
                    swap(min_right->val, max_left->val);
                    return;
                }
                if (max_left->val > cur->val) {
                    swap(max_left->val, cur->val);
                    return;
                }
                if (min_right->val < cur->val) {
                    swap(min_right->val, cur->val);
                    return;
                }

                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> tmp;
            int count = que.size();
            for (int i = 0; i < count; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
                tmp.push_back(cur->val);
            }
            ans.push_back(tmp);
        }
        return ans;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans = levelOrder(root);
        for (int i = 0, j = ans.size() - 1; i < j; i++, j--) {
            swap(ans[i], ans[j]);
        }
        return ans;
    }

    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int count = que.size();
            Node* pre = nullptr;
            for (int i = 0; i < count; i++) {
                Node* cur = que.front();
                que.pop();
                if (pre) {
                    pre->next = cur;
                }
                pre = cur;

                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
            }
        }
        return root;
    }

    vector<int> getLinkedList(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        return res;
    }

    // 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode dummy;
        ListNode* cur = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1) {
            cur->next = list1;
        } else if (list2) {
            cur->next = list2;
        }

        return dummy.next;
    }

    // 24. Swap Nodes in Pairs
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (head && head->next) {
            ListNode* nn = head->next->next;
            cur->next = head->next;
            head->next->next = head;
            head->next = nn;
            cur = head;
            head = head->next;
        }
        if (head) {
            cur->next = head;
        }
        return dummy.next;
    }

    // 19. Remove Nth Node From End of List
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        int jump = len - n;
        if (jump < 0) {
            return head;
        }
        ListNode dummy(0, head);
        cur = &dummy;
        for (int i = 0; i < jump; i++) {
            cur = cur->next;
        }
        if (cur->next) {
            cur->next = cur->next->next;
        }
        return dummy.next;
    }

    // 61. Rotate List
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode dummy(0, head);
        ListNode* cur = &dummy;
        while (cur->next) {
            len++;
            cur = cur->next;
        }
        if (len == 0) {
            return nullptr;
        }
        cur->next = head;  // make it circle
        int jump = len - (k % len);
        cur = &dummy;
        for (int i = 0; i < jump; i++) {
            cur = cur->next;
        }
        ListNode* new_head = cur->next;
        cur->next = nullptr;  // break circle
        return new_head;
    }

    // 206. Reverse Linked List
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* cur1 = head;
        ListNode* cur2 = head->next;
        cur1->next = nullptr;
        while (cur1 && cur2) {
            ListNode* nn = cur2->next;
            cur2->next = cur1;
            cur1 = cur2;
            cur2 = nn;
        }
        return cur1;
    }

    // 92. Reverse Linked List II
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) {
            return nullptr;
        }
        ListNode dummy(0, head);
        ListNode* cur = &dummy;
        for (int i = 0; i < left - 1; i++) {  // find left bound to start
            cur = cur->next;
        }
        ListNode* left_break = cur;
        ListNode* cur1 = left_break->next;
        ListNode* cur2 = left_break->next->next;
        for (int i = 0; i < right - left; i++) {  // till reach right bound
            ListNode* nn = cur2->next;
            cur2->next = cur1;
            cur1 = cur2;
            cur2 = nn;
        }
        left_break->next->next = cur2;  // concat left_break with right_reverse
        left_break->next = cur1;        // concat right_break with left_reverse
        return dummy.next;
    }

    // 876. Middle of the Linked List
    ListNode* middleNode(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }
        return slow;
    }

    // 143. Reorder List
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* reversed_tail = reverseList(mid);
        ListNode* cur1 = head;
        ListNode* cur2 = reversed_tail;
        while (cur1 && cur2) {
            ListNode* cur1n = cur1->next;
            ListNode* cur2n = cur2->next;
            if (cur2 != cur1->next) {
                cur2->next = cur1->next;
            }
            if (cur1 != cur2) {
                cur1->next = cur2;
            }
            cur1 = cur1n;
            cur2 = cur2n;
        }
    }
};
