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

    // 655. Print Binary Tree
    // Given the root of a binary tree, construct a 0-indexed m x n string matrix res that represents a formatted layout of the tree. The formatted layout matrix should be constructed using the following rules:
    // The height of the tree is height and the number of rows m should be equal to height + 1.
    // The number of columns n should be equal to 2height+1 - 1.
    // Place the root node in the middle of the top row (more formally, at location res[0][(n-1)/2]).
    // For each node that has been placed in the matrix at position res[r][c], place its left child at res[r+1][c-2height-r-1] and its right child at res[r+1][c+2height-r-1].
    // Continue this process until all the nodes in the tree have been placed.
    // Any empty cells should contain the empty string "".
    // Return the constructed matrix res.
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

    // 110. Balanced Binary Tree
    // Given a binary tree, determine if it is height-balanced.
    // bool isBalanced(TreeNode* root) {
    //     stack<pair<TreeNode*, int>> st;
    //     TreeNode* cur = root;
    //     int lower = 0, upper = 0;
    //     int cur_height = 0;
    //     while (cur || !st.empty()) {
    //         while (cur) {
    //             cur_height++;
    //             st.push(make_pair(cur, cur_height));
    //             if (!cur->left || !cur->right) { // leaf node
    //                 if (lower == 0) { // init
    //                     lower = cur_height;
    //                     upper = cur_height;
    //                 } else if (upper - 1 > cur_height) { // too short
    //                     return false;
    //                 } else if (lower + 1 < cur_height) { // too long
    //                     return false;
    //                 } else {
    //                     lower = min(lower, cur_height);
    //                     upper = max(upper, cur_height);
    //                 }
    //             }
    //             cur = cur->left;
    //         }
    //         cur = st.top().first->right;
    //         cur_height = st.top().second;
    //         st.pop();
    //     }
    //     return true;
    // }
	int height(TreeNode* root) {
		if (root == NULL)  return 0; // Base case...
		int left_height = height(root->left);
		int right_height = height(root->right);
        // In case of left subtree or right subtree unbalanced or their heights differ by more than ‘1’, return -1...
		if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1)  return -1;
        // Otherwise, return the height of this subtree as max(left_height, right_height) + 1...
		return max(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode* root) {
        // will return -1, when it’s an unbalanced tree...
		return height(root) != -1;
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

    // 226. Invert Binary Tree
    // Given the root of a binary tree, invert the tree, and return its root.
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    // 257. Binary Tree Paths
    // Given the root of a binary tree, return all root-to-leaf paths in any order.
    // A leaf is a node with no children.
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<pair<TreeNode*, string>> st;
        TreeNode* cur = root;
        string cur_str;
        vector<string> res;
        while (cur || !st.empty()) {
            while (cur) {
                cur_str = cur_str + to_string(cur->val) + "->";
                st.push(make_pair(cur, cur_str));
                cur = cur->left;
            }
            TreeNode* tmp = st.top().first;
            string tmp_str = st.top().second;
            if (!tmp->left && !tmp->right) { // leaf node
                res.push_back(tmp_str.substr(0, tmp_str.size() - 2));
            }
            cur = tmp->right;
            cur_str = tmp_str;
            st.pop();
        }
        return res;
    }

    // 563. Binary Tree Tilt
    // Given the root of a binary tree, return the sum of every tree node's tilt.
    // The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.
    int sum(TreeNode* root, int& tilt) {
        if (!root) return 0;
        int left_sum = sum(root->left, tilt);
        int right_sum = sum(root->right, tilt);
        tilt += abs(left_sum - right_sum);
        return left_sum + right_sum + root->val;
    }
    int findTilt(TreeNode* root) {
        int tilt = 0;
        sum(root, tilt);
        return tilt;
    }

    // 654. Maximum Binary Tree
    // You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:
    // Create a root node whose value is the maximum value in nums.
    // Recursively build the left subtree on the subarray prefix to the left of the maximum value.
    // Recursively build the right subtree on the subarray suffix to the right of the maximum value.
    // Return the maximum binary tree built from nums.
    TreeNode* doConstructMaximum(vector<int>& nums, int left, int right) {
        if (left == right) return nullptr;
        int max_val = nums[left], max_idx = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > max_val) {
                max_val = nums[i];
                max_idx = i;
            }
        }
        return new TreeNode(max_val, doConstructMaximum(nums, left, max_idx), doConstructMaximum(nums, max_idx + 1, right));
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return doConstructMaximum(nums, 0, nums.size());
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

    TreeNode* buildTreeHelper(unordered_map<int, int>& in_idx, vector<int>& preorder, int r, int len, vector<int>& inorder, int st, int ed) {
        if (len == 0) {
            return NULL;
        }
        int mid = in_idx[preorder[r]];
        TreeNode* res =
            new TreeNode(preorder[r],
            buildTreeHelper(in_idx, preorder, r + 1, mid - st, inorder, st, mid),
            buildTreeHelper(in_idx, preorder, r + 1 + mid - st, ed - (mid + 1), inorder, mid + 1, ed));
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in_idx;
        for (int i = 0; i < inorder.size(); i++) {
            in_idx[inorder[i]] = i;
        }
        return buildTreeHelper(in_idx, preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    // 95. Unique Binary Search Trees II
    // Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
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
};
