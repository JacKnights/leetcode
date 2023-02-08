#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
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

class Solution {
   public:
    string longestPalindrome(string s) {
        int len = s.size();
        bool** dp = new bool*[len + 1];
        for (int i = 0; i < len + 1; i++) {
            dp[i] = new bool[len + 1];
            for (int j = 0; j < len + 1; j++) {
                dp[i][j] = false;
            }
        }

        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; i - j >= 0 && i + 1 + j < len; j++) {
                if (s[i - j] == s[i + 1 + j]) {
                    dp[i - j][i + 1 + j] = true;
                } else {
                    break;
                }
            }
        }
        for (int i = 1; i < len - 1; i++) {
            for (int j = 0; i - 1 - j >= 0 && i + 1 + j < len; j++) {
                if (s[i - 1 - j] == s[i + 1 + j]) {
                    dp[i - 1 - j][i + 1 + j] = true;
                } else {
                    break;
                }
            }
        }

        int l = 0, r = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (dp[i][j] && j - i > r - l) {
                    l = i;
                    r = j;
                }
            }
        }
        return s.substr(l, r - l + 1);
    }

    bool isPalindrome(int x) {
        char str[25];
        sprintf(str, "%d", x);
        string s = str;
        return longestPalindrome(s) == s;
    }

    string intToRoman(int num) {
        vector<int> vals{1, 5, 10, 50, 100, 500, 1000};
        vector<char> syms{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string res;
        res.reserve(20);
        for (int i = vals.size() - 1; i >= 0; i -= 2) {
            int quo = num / vals[i];
            int mod = num % vals[i];
            if (quo > 0) {
                switch (quo) {
                    case 1: {
                        res += syms[i];
                        break;
                    }
                    case 2: {
                        res += syms[i];
                        res += syms[i];
                        break;
                    }
                    case 3: {
                        res += syms[i];
                        res += syms[i];
                        res += syms[i];
                        break;
                    }
                    case 4: {
                        res += syms[i];
                        res += syms[i + 1];
                        break;
                    }
                    case 5: {
                        res += syms[i + 1];
                        break;
                    }
                    case 6: {
                        res += syms[i + 1];
                        res += syms[i];
                        break;
                    }
                    case 7: {
                        res += syms[i + 1];
                        res += syms[i];
                        res += syms[i];
                        break;
                    }
                    case 8: {
                        res += syms[i + 1];
                        res += syms[i];
                        res += syms[i];
                        res += syms[i];
                        break;
                    }
                    case 9: {
                        res += syms[i];
                        res += syms[i + 2];
                        break;
                    }
                }
                num = mod;
            }
        }
        return res;
    }

    vector<string> letterCombinations(string digits) {
        map<int, vector<char>> letters = {
            {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}},
        };
        vector<string> tmp;
        // tmp.reserve(256);
        for (int i = 0; i < digits.size(); i++) {
            vector<char> ltr = letters[digits[i] - '0'];

            if (tmp.size() == 0) {
                for (int j = 0; j < ltr.size(); j++) {
                    string tmp_str;
                    tmp_str += ltr[j];
                    tmp.push_back(tmp_str);
                }
            } else {
                vector<string> new_tmp;
                for (int k = 0; k < tmp.size(); k++) {
                    for (int j = 0; j < ltr.size(); j++) {
                        string tmp_str = tmp[k] + ltr[j];
                        new_tmp.push_back(tmp_str);
                    }
                }
                tmp = new_tmp;
            }
        }

        return tmp;
    }

    bool isValid(string s) {
        stack<char> st;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                switch (s[i]) {
                    case ')':
                        if (top != '(') {
                            return false;
                        }
                        st.pop();
                        break;
                    case ']':
                        if (top != '[') {
                            return false;
                        }
                        st.pop();
                        break;
                    case '}':
                        if (top != '{') {
                            return false;
                        }
                        st.pop();
                        break;
                    default:
                        return false;
                }
            }
        }
        return st.empty();
    }

    void helper(int open, int close, int n, string current, vector<string>& result) {
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }
        if (open < n) {
            helper(open + 1, close, n, current + "(", result);
        }
        if (close < open) {
            helper(open, close + 1, n, current + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(0, 0, n, "", result);
        return result;
    }

    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int res = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                nums[res] = nums[i + 1];
                res++;
            }
        }
        return res;
    }

    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }

    int strStr(string haystack, string needle) {
        int res = -1;
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            if (haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }
        return res;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int ws = words.size();
        int wss = words[0].size();
        if (s.size() < ws * wss) {
            return res;
        }
        map<string, int> wmap;
        for (int i = 0; i < ws; i++) {
            if (wmap.find(words[i]) == wmap.end()) {
                wmap[words[i]] = 1;
            } else {
                wmap[words[i]]++;
            }
        }
        for (int i = 0; i <= s.size() - ws * wss; i++) {
            map<string, int> smap;
            for (int j = 0; j < ws; j++) {
                string cur = s.substr(i + j * wss, wss);
                if (smap.find(cur) == smap.end()) {
                    smap[cur] = 1;
                } else {
                    smap[cur]++;
                }
            }
            bool ok = true;
            for (auto iter = wmap.begin(); iter != wmap.end(); iter++) {
                string key = iter->first;
                int val = iter->second;
                auto siter = smap.find(key);
                if (siter == smap.end()) {
                    ok = false;
                    break;
                }
                if (siter->second != val) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res.push_back(i);
            }
        }
        return res;
    }

    void nextPermutation(vector<int>& nums) {
        int p = nums.size() - 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                p = i - 1;
                break;
            }
            if (i == 1) {
                p = -1;
            }
        }

        int q = p;
        if (p == -1) {
            q = nums.size() - 1;
        } else {
            for (int i = nums.size() - 1; i > p; i--) {
                if (nums[i] > nums[p]) {
                    q = i;
                    break;
                }
            }
            swap(nums[p], nums[q]);
        }
        for (int i = p + 1, j = nums.size() - 1; i <= j; i++, j--) {
            swap(nums[i], nums[j]);
        }

        return;
    }

    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    st.push(i);
                } else {
                    if (s[st.top()] == '(') {
                        st.pop();
                    } else {
                        st.push(i);
                    }

                    if (st.empty()) {
                        res = i + 1;
                    } else {
                        res = max(res, i - st.top());
                    }
                }
            }
        }
        return res;
    }

    // searchInOrder
    int binsearch1(vector<int>& nums, int st, int ed, int target) {
        int len = ed - st;
        if (len == 0) {
            return -1;
        }
        if (len == 1) {
            return nums[st] == target ? st : -1;
        }
        int mid = st + len / 2;
        if (nums[mid] > target) {
            return binsearch1(nums, st, mid, target);
        } else {
            return binsearch1(nums, mid, ed, target);
        }
    }
    int search1(vector<int>& nums, int target) {
        int len = nums.size();
        return binsearch1(nums, 0, nums.size(), target);
    }

    // rotated
    int binsearch(vector<int>& nums, int st, int ed, int target) {
        int len = ed - st;
        if (len == 0) {
            return -1;
        }
        if (len == 1) {
            return nums[st] == target ? st : -1;
        }
        int mid = st + len / 2;
        if (nums[st] < nums[mid] && nums[mid] < nums[ed - 1]) {
            if (nums[mid] > target) {
                return binsearch(nums, st, mid, target);
            } else {
                return binsearch(nums, mid, ed, target);
            }
        } else {
            int r1 = binsearch(nums, st, mid, target);
            if (r1 != -1) {
                return r1;
            } else {
                return binsearch(nums, mid, ed, target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        return binsearch(nums, 0, len, target);
    }

    // search in range
    vector<int> binsearchRange(vector<int>& nums, int st, int ed, int target) {
        int len = ed - st;
        if (len == 0) {
            return {-1, -1};
        }
        if (len == 1) {
            return (nums[st] == target) ? (vector<int>){st, st} : (vector<int>){-1, -1};
        }
        int mid = st + len / 2;
        if (nums[mid] > target) {
            return binsearchRange(nums, st, mid, target);
        } else if (nums[mid] < target) {
            return binsearchRange(nums, mid, ed, target);
        } else {
            vector<int> res;
            for (int i = st; i < ed; i++) {
                if (nums[i] == target) {
                    if (res.size() == 0) {
                        res.push_back(i);
                        res.push_back(i);
                    } else {
                        res[1] = i;
                    }
                } else if (nums[i] > target) {
                    break;
                }
            }
            return res;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        return binsearchRange(nums, 0, len, target);
    }

    int binsearchInsert(vector<int>& nums, int st, int ed, int target) {
        int len = ed - st;
        if (len == 0) {
            return -1;
        }
        if (len == 1) {
            if (nums[st] == target) {
                return st;
            } else if (nums[st] > target) {
                return st - 1 < 0 ? 0 : st - 1;
            } else {
                return st + 1;
            }
        }
        int mid = st + len / 2;
        if (nums[mid] > target) {
            return binsearchInsert(nums, st, mid, target);
        } else {
            return binsearchInsert(nums, mid, ed, target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        return binsearchInsert(nums, 0, len, target);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            map<char, bool> m;
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] > '0' && board[i][j] <= '9') {
                    if (m.find(board[i][j]) != m.end()) {
                        return false;
                    }
                    m[board[i][j]] = true;
                }
            }
        }
        for (int i = 0; i < board[0].size(); i++) {
            map<char, bool> m;
            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] > '0' && board[j][i] <= '9') {
                    if (m.find(board[j][i]) != m.end()) {
                        return false;
                    }
                    m[board[j][i]] = true;
                }
            }
        }
        for (int i = 0; i + 3 <= board.size(); i += 3) {
            for (int j = 0; j + 3 <= board[i].size(); j += 3) {
                map<char, bool> m;
                for (int ii = i; ii < i + 3; ii++) {
                    for (int jj = j; jj < j + 3; jj++) {
                        if (board[ii][jj] > '0' && board[ii][jj] <= '9') {
                            if (m.find(board[ii][jj]) != m.end()) {
                                return false;
                            }
                            m[board[ii][jj]] = true;
                        }
                    }
                }
            }
        }

        return true;
    }

    bool check(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) {
                return false;
            }
        }
        int i0 = (row / 3) * 3, j0 = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i0 + i][j0 + j] == c) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != '.') {
            if (j + 1 < board[i].size()) {
                return solve(board, i, j + 1);
            } else if (i + 1 < board.size()) {
                return solve(board, i + 1, 0);
            }
            return true;
        }
        for (char c = '1'; c <= '9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solve(board, i, j + 1)) {
                    return true;
                } else {
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
        return;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        map<int, bool> rows;
        map<int, bool> cols;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (auto iter = rows.begin(); iter != rows.end(); iter++) {
            for (int j = 0; j < matrix[iter->first].size(); j++) {
                matrix[iter->first][j] = 0;
            }
        }
        for (auto iter = cols.begin(); iter != cols.end(); iter++) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][iter->first] = 0;
            }
        }
    }

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
        TreeNode* res = new TreeNode(preorder[r], buildTreeHelper(in_idx, preorder, r + 1, mid - st, inorder, st, mid), buildTreeHelper(in_idx, preorder, r + 1 + mid - st, ed - (mid + 1), inorder, mid + 1, ed));
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> in_idx;
        for (int i = 0; i < inorder.size(); i++) {
            in_idx[inorder[i]] = i;
        }
        return buildTreeHelper(in_idx, preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    // unique binary search tree
    int numTrees(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(1, numTrees(i - 0)) * max(1, numTrees(n - i - 1));
        }
        return res;
    }
    int numTreesDP(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int* dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        int res = dp[n];
        delete[] dp;
        return res;
    }

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

    // wrong
    bool isValidBST_wrong(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                if (cur->left) {
                    if (cur->val <= cur->left->val) {
                        return false;
                    }
                }
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (cur->right) {
                if (cur->val >= cur->right->val) {
                    return false;
                }
            }
            cur = cur->right;
        }
        return true;
    }
    bool isValidBST_wrong2(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (root->left) {
            if (root->val <= root->left->val) {
                return false;
            }
        }
        if (root->right) {
            if (root->val >= root->right->val) {
                return false;
            }
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> inorder = inorderTraversal(root);
        for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i] >= inorder[i + 1]) {
                return false;
            }
        }
        return true;
    }

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

    // TreeNode* findMaxOrMinVal(vector<TreeNode*> ns, bool is_max) {
    //     TreeNode* res = nullptr;
    //     for (int i = 0; i < ns.size(); i++) {
    //         if (ns[i]) {
    //             if (!res || (is_max && res->val < ns[i]->val) || (!is_max && res->val > ns[i]->val)) {
    //                 res = ns[i];
    //             }
    //         }
    //     }
    //     return res;
    // }
    // TreeNode* maxMinVal(map<TreeNode*, vector<TreeNode*>*>& min_max_map, TreeNode* root, bool is_max) {
    //     if (min_max_map.find(root) == min_max_map.end()) {
    //         min_max_map[root] = new vector<TreeNode*>{nullptr, nullptr};
    //     }
    //     TreeNode* left = nullptr;
    //     if (root->left) {
    //         if (min_max_map.find(root->left) != min_max_map.end()) {
    //             auto cache = (*min_max_map[root->left])[is_max ? 1 : 0];
    //             printf("cache find%d: %d %d\n", is_max, root->left, root->left->val);
    //             if (cache) {
    //                 left = cache;
    //                 printf("cache hit\n");
    //             } else {
    //                 left = maxMinVal(min_max_map, root->left, is_max);
    //             }
    //         } else {
    //             left = maxMinVal(min_max_map, root->left, is_max);
    //         }
    //     }
    //     TreeNode* right = nullptr;
    //     if (root->right) {
    //         if (min_max_map.find(root->right) != min_max_map.end()) {
    //             auto cache = (*min_max_map[root->right])[is_max ? 1 : 0];
    //             printf("cache find%d: %d %d\n", is_max, root->right, root->right->val);
    //             if (cache) {
    //                 right = cache;
    //                 printf("cache hit\n");
    //             } else {
    //                 right = maxMinVal(min_max_map, root->right, is_max);
    //             }
    //         } else {
    //             right = maxMinVal(min_max_map, root->right, is_max);
    //         }
    //     }
    //     TreeNode* res = findMaxOrMinVal({root, left, right}, is_max);
    //     if (is_max) {
    //         if (!(*min_max_map[root])[1] || (*min_max_map[root])[1]->val < res->val) {
    //             (*min_max_map[root])[1] = res;
    //             // printf("cache set0: %d %d\n", root, root->val);
    //             printf("cache set1: %d %d\n", res, res->val);
    //         }
    //     } else {
    //         if (!(*min_max_map[root])[0] || (*min_max_map[root])[0]->val > res->val) {
    //             (*min_max_map[root])[0] = res;
    //             // printf("cache set0: %d %d\n", root, root->val);
    //             printf("cache set0: %d %d\n", res, res->val);
    //         }
    //     }
    //     return res;
    // }

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

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> que;
        unordered_set<string> unvisited;
        que.push({beginWord, 1});
        unvisited.insert(wordList.begin(), wordList.end());
        unvisited.erase(beginWord);
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            if (cur.first == endWord) {
                return cur.second;
            }
            for (int i = 0; i < cur.first.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string word = cur.first;
                    word[i] = c;
                    if (unvisited.find(word) != unvisited.end()) {
                        que.push({word, cur.second + 1});
                        unvisited.erase(word);
                    }
                }
            }
        }
        return 0;
    }

    // generatePascalTriangle
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);
            res[i][0] = 1;
            res[i][i] = 1;
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int>* a = new vector<int>(rowIndex + 1);
        vector<int>* b = new vector<int>(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            vector<int>*cur, *pre;
            if (i % 2 == 0) {
                cur = a;
                pre = b;
            } else {
                cur = b;
                pre = a;
            }
            (*cur)[0] = 1;
            (*cur)[i] = 1;
            for (int j = 1; j < i; j++) {
                (*cur)[j] = (*pre)[j - 1] + (*pre)[j];
            }
        }
        return rowIndex % 2 == 0 ? *a : *b;
    }

    int maxProfit1(vector<int>& prices) {
        int p1 = INT_MIN;
        int p2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            p2 = max(p2, p1 + prices[i]);
            p1 = max(p1, -prices[i]);
        }
        return p2;
    }
    int maxProfit2(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
    // dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
    int maxProfit3(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        int K = 2;
        vector<vector<int>> dp(K + 1, vector<int>(prices.size(), 0));
        for (int k = 1; k <= K; k++) {
            int minCost = prices[0];
            for (int i = 1; i < len; i++) {
                minCost = min(minCost, prices[i] - dp[k - 1][i - 1]);
                dp[k][i] = max(dp[k][i - 1], prices[i] - minCost);
            }
        }
        return dp[K][len - 1];
    }
    
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool> dp(len, false);
        dp[0] = true;
        for (int i = 1; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && i - j <= nums[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len - 1];

        // // best
        // int len = nums.size();
        // int last = 0;
        // for (int i = 0; i < len && i <= last; i++) {
        //     last = max(last, i + nums[i]);
        // }
        // return last >= len - 1;
    }
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return 0;
        }
        if (nums[0] >= len - 1) {
            return 1;
        }
        vector<int> dp(len, 0);
        for (int i = 1; i <= nums[0]; i++) {
            dp[i] = 1;
        }
        for (int i = nums[0] + 1; i < len; i++) {
            int minStep = INT_MAX;
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] > 0 && i - j <= nums[j]) {
                    minStep = min(minStep, dp[j]);
                }
            }
            if (minStep < INT_MAX) {
                dp[i] = minStep + 1;
            }
        }
        return dp[len - 1];

        // // best
        // int jumps = 0, curEnd = 0, last = 0;
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     last = max(last, i + nums[i]);
        //     if (i == curEnd) {
        //         jumps++;
        //         curEnd = last;
        //     }
        // }
        // return jumps;
    }

    // wildcard matching
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, false));
        dp[0][0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; j++) {
            dp[0][j + 1] = true;
        }

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                if (p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i][j];
                } else {
                    dp[i + 1][j + 1] = (s[i] == p[j] || p[j] == '?') && dp[i][j];
                }
            }
        }

        return dp[s.size()][p.size()];
    }
    
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        // vector<vector<int>> dp(m, vector<int>(n, 1));
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }
        // return dp[m - 1][n - 1];
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m < 1) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (n < 1) {
            return 0;
        }
        vector<int> pre(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> cur(n, 0);
            if (!obstacleGrid[i][0] && (pre[0] > 0 || i == 0)) {
                cur[0] = 1;
            }
            for (int j = 1; j < n; j++) {
                cur[j] = !obstacleGrid[i][j] ? cur[j - 1] + pre[j] : 0;
            }
            swap(pre, cur);
        }
        return pre[n - 1];
    }

    int uniquePathsIIIDFS(vector<vector<int>>& grid, int m, int n, int empty, int x, int y, int step) {
        if (grid[x][y] == -1) {
            return 0;
        }
        if (grid[x][y] == 2) {
            return empty == step ? 1 : 0;
        }
        grid[x][y] = -1;
        int res = 0;
        if (x - 1 >= 0) {
            res += uniquePathsIIIDFS(grid, m, n, empty, x - 1, y, step + 1);
        }
        if (y - 1 >= 0) {
            res += uniquePathsIIIDFS(grid, m, n, empty, x, y - 1, step + 1);
        }
        if (x + 1 < m) {
            res += uniquePathsIIIDFS(grid, m, n, empty, x + 1, y, step + 1);
        }
        if (y + 1 < n) {
            res += uniquePathsIIIDFS(grid, m, n, empty, x, y + 1, step + 1);
        }
        grid[x][y] = 0;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m < 1) {
            return 0;
        }
        int n = grid[0].size();
        if (n < 1) {
            return 0;
        }
        int st_x, st_y;
        int empty = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    st_x = i;
                    st_y = j;
                } else if (grid[i][j] != -1) {
                    empty++;
                }
            }
        }
        return uniquePathsIIIDFS(grid, m, n, empty, st_x, st_y, 0);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m < 1) {
            return 0;
        }
        int n = grid[0].size();
        if (n < 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(), 0);
        if (s[0] <= '9' && s[0] >= '1') {
            dp[0] = 1;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] <= '9' && s[i] >= '1') {
                dp[i] += dp[i - 1];
            }
            if (i > 0 && s[i - 1] != '0') {
                int num = atoi(s.substr(i - 1, 2).c_str());
                if (num <= 26 && num > 0) {
                    dp[i] += (i > 1 ? dp[i - 2] : 1);
                }
            }
            
        }
        return dp[s.length() - 1];
    }
};
