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

class Solution {
   public:
    // 5. Longest Palindromic Substring
    // Given a string s, return the longest palindromic substring in s.
    string longestPalindrome(string s) {
        int len = s.size();
        bool** dp = new bool*[len];
        for (int i = 0; i < len; i++) { // init
            dp[i] = new bool[len];
            for (int j = 0; j < len; j++) {
                dp[i][j] = false;
            }
        }

        for (int i = 0; i < len - 1; i++) { // even
            for (int j = 0; i - j >= 0 && i + 1 + j < len; j++) {
                if (s[i - j] != s[i + 1 + j]) {
                    break;
                }
                dp[i - j][i + 1 + j] = true;
            }
        }
        for (int i = 0; i < len; i++) { // odd
            for (int j = 0; i - j >= 0 && i + j < len; j++) {
                if (s[i - j] != s[i + j]) {
                    break;
                }
                dp[i - j][i + j] = true;
            }
        }
        int l = 0, r = 0;
        for (int i = 0; i < len; i++) { // find longest
            for (int j = len - 1; j >= 0; j--) {
                if (dp[i][j] && j - i > r - l) {
                    l = i;
                    r = j;
                    break;
                }
            }
        }
        return s.substr(l, r - l + 1);
    }

    // 409. Longest Palindrome
    int longestPalindrome2(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }
        bool found_odd = false;
        int ans = 0;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second % 2 == 0) {
                ans += iter->second;
            } else if (!found_odd) {
                ans += iter->second - 1;
                found_odd = true;
            }
        }
        if (found_odd) ans++;
        return ans;
    }

    // 9. Palindrome Number
    // Given an integer x, return true if x is a palindrome, and false otherwise.
    bool isPalindrome(int x) {
        char str[25];
        sprintf(str, "%d", x);
        string s = str;
        return longestPalindrome(s) == s;
    }

    // 516. Longest Palindromic Subsequence
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (s[i] != s[j]) {
                    dp[i][j] = max(dp[i][j + 1], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j + 1] + 2;
                }
            }
        }
        return dp[len - 1][0];
    }

    // 53. Maximum Subarray
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    // 12. Integer to Roman
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

    // 31. Next Permutation
    void nextPermutation(vector<int>& nums) {
        int p = nums.size() - 1;
        bool p_found = false;
        // find last digit p non-desc
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                p = i - 1;
                p_found = true;
                break;
            }
        }

        int q = p;
        if (!p_found) {
            q = nums.size() - 1;
        } else {
            // find last digit q larger than p
            for (int i = nums.size() - 1; i > p; i--) {
                if (nums[i] > nums[p]) {
                    q = i;
                    break;
                }
            }
            swap(nums[p], nums[q]);
        }
        // reverse between (p, end)
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

    // 96. unique binary search tree
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

    // 121. Best Time to Buy and Sell Stock
    int maxProfit1(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int p1 = -prices[0];
        int p2 = 0;
        for (int i = 1; i < prices.size(); i++) {
            p1 = max(p1, -prices[i]);
            p2 = max(p2, p1 + prices[i]);
        }
        return p2;
    }

    // 122. Best Time to Buy and Sell Stock II
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

    // 123. Best Time to Buy and Sell Stock III
    // dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
    int maxProfit3(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        int K = 2;
        vector<vector<int>> dp(K + 1, vector<int>(prices.size(), 0));
        for (int k = 1; k <= K; k++) {
            int minCost = -prices[0];
            for (int i = 1; i < len; i++) {
                minCost = max(minCost, dp[k - 1][i - 1] - prices[i]);
                dp[k][i] = max(dp[k][i - 1], prices[i] + minCost);
            }
        }
        return dp[K][len - 1];
    }

    // 55. Jump Game
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int last = 0;
        for (int i = 0; i < len && i <= last; i++) {
            last = max(last, i + nums[i]);
        }
        return last >= len - 1;
    }

    // 45. Jump Game II
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

    // 62. Unique Paths
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) {
            return 0;
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

    // 63. Unique Paths II
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

    // 980. Unique Paths III
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

    // 3. Longest Substring Without Repeating Characters
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int start = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            us.insert(s[i]);
            int window = i - start + 1;
            if (us.size() == window) {
                ans = max(ans, window);
                continue;
            }
            while (us.size() < window) {
                if (s[start] != s[i]) { // leave current in set
                    us.erase(s[start]);
                }
                start++;
            }
        }
        return ans;
    }

    // 215. Kth Largest Element in an Array
    int findKthLargest(vector<int>& nums, int k) {
        const int MAX_SIZE = 20001;
        vector<int> bucket(MAX_SIZE, 0);
        for (int i = 0; i < nums.size(); i++) {
            bucket[nums[i] + 10000]++;
        }
        int counter = 0;
        int res = 0;
        for (int i = MAX_SIZE - 1; i >= 0; i--) {
            if (bucket[i] + counter < k) {
                counter += bucket[i];
            } else {
                res = i - 10000;
                break;
            }
        }
        return res;
    }

    // 15. 3Sum
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> us;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    us.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                }
            }
        }
        vector<vector<int>> res(us.size());
        int counter = 0;
        for (auto iter = us.begin(); iter != us.end(); iter++) {
            res[counter++] = *iter;
        }
        return res;
    }

    // 42. Trapping Rain Water
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) {
            return 0;
        }
        vector<int> left(len);
        vector<int> right(len);
        left[0] = height[0];
        right[len - 1] = height[len - 1];
        for (int i = 1; i < len - 1; i++) {
            left[i] = max(height[i], left[i - 1]);
        }
        for (int i = len - 2; i > 0; i--) {
            right[i] = max(height[i], right[i + 1]);
        }
        int ans = 0;
        for (int i = 1; i < len - 1; i++) {
            ans += (min(left[i], right[i]) - height[i]);
        }
        return ans;
    }

    // 494. Target Sum
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            sum += nums[i];
        }
        if (S > sum || S < -sum) {
            return 0;
        }
        vector<vector<int>> dp;
        dp.resize(len, vector<int>(2 * sum + 1, 0));
        dp[0][sum + nums[0]]++;
        dp[0][sum - nums[0]]++;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < 2 * sum + 1; j++) {
                if (j + nums[i] < 2 * sum + 1) {
                    dp[i][j + nums[i]] += dp[i - 1][j];
                }
                if (j - nums[i] >= 0) {
                    dp[i][j - nums[i]] += dp[i - 1][j];
                }
            }
        }
        return dp[len - 1][sum + S];
    }

    // 322. Coin Change
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    if ((dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) && dp[i - coins[j]] != -1) {
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }

    // 279. Perfect Squares
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }

    // 416. Partition Equal Subset Sum
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        vector<bool> reach(target + 1, false);
        reach[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target - nums[i]; j >= 0; j--) {
                reach[j + nums[i]] = reach[j + nums[i]] || reach[j];
            }
        }
        return reach[target];
    }
};
