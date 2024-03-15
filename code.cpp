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

class Solution {
   public:

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

    // 13. Roman to Integer
    int romanToInt(string s) {
        map<char, int> vals = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (vals[s[i]] >= vals[s[i + 1]]) {
                ans += vals[s[i]];
            } else {
                ans -= vals[s[i]];
            }
        }
        ans += vals[s[s.size() - 1]];
        return ans;
    }

    // 17. Letter Combinations of a Phone Number
    vector<string> letterCombinations(string digits) {
        map<int, vector<char>> letters = {
            {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}},
        };
        vector<string> res;
        for (int i = 0; i < digits.size(); i++) {
            vector<char> ltr = letters[digits[i] - '0'];

            if (res.size() == 0) {
                res.reserve(ltr.size());
                for (int j = 0; j < ltr.size(); j++) {
                    string res_str = string(1, ltr[j]);
                    res.push_back(res_str);
                }
            } else {
                vector<string> new_res;
                new_res.reserve(res.size() * ltr.size());
                for (int k = 0; k < res.size(); k++) {
                    for (int j = 0; j < ltr.size(); j++) {
                        string res_str = res[k] + ltr[j];
                        new_res.push_back(res_str);
                    }
                }
                res = new_res;
            }
        }

        return res;
    }

    // 20. Valid Parentheses
    // Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
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

    // 26. Remove Duplicates from Sorted Array
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

    // 27. Remove Element
    // Given an integer array nums and an integer val, remove all occurrences of val in nums in-place
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

    // 647. Palindromic Substrings
    // Given a string s, return the number of palindromic substrings in it.
    int countSubstrings(string s) {
        int len = s.size();
        int ans = 0;
        for (int i = 0; i < len - 1; i++) { // even
            for (int j = 0; i - j >= 0 && i + 1 + j < len; j++) {
                if (s[i - j] != s[i + 1 + j]) {
                    break;
                }
                ans++;
            }
        }
        for (int i = 0; i < len; i++) { // odd
            for (int j = 0; i - j >= 0 && i + j < len; j++) {
                if (s[i - j] != s[i + j]) {
                    break;
                }
                ans++;
            }
        }
        return ans;
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

    // 30. Substring with Concatenation of All Words
    // You are given a string s and an array of strings words. All the strings of words are of the same length.
    // A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
    // Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.
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
    // Given an array of integers nums, find the next permutation of nums.
    // The replacement must be in place and use only constant extra memory.
    void nextPermutation(vector<int>& nums) {
        int p = -1;
        // find last digit p non-desc
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                p = i - 1;
                break;
            }
        }
        if (p >= 0) { // find last digit q larger than p
            int q = p + 1;
            for (int i = nums.size() - 1; i > p; i--) {
                if (nums[i] > nums[p]) {
                    q = i;
                    break;
                }
            }
            swap(nums[p], nums[q]);
        }
        // reverse between (p, end)
        for (int i = p + 1, j = nums.size() - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
        return;
    }

    // 32. Longest Valid Parentheses
    // Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st; // store the index of a potential start
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    st.push(i); // all those before matched
                } else {
                    if (s[st.top()] == '(') {
                        st.pop();
                    } else {
                        st.push(i);
                    }

                    if (st.empty()) {
                        res = i + 1; // all matched
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
    // 704. Binary Search
    // Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
    // If target exists, then return its index. Otherwise, return -1.
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
        if (nums[st] <= nums[mid] && nums[mid] <= nums[ed - 1]) { // not rotated
            if (nums[mid] > target) {
                return binsearch(nums, st, mid, target);
            } else {
                return binsearch(nums, mid, ed, target);
            }
        } else if (nums[st] >= nums[ed - 1]) { // rotated
            if (nums[st] < nums[mid] && nums[st] < target && nums[mid] > target) {
                return binsearch(nums, st, mid, target);
            } else if (nums[mid] < nums[ed - 1] && nums[mid] < target && nums[ed - 1] > target) {
                return binsearch(nums, mid, ed, target);
            }
            // do both
            int r1 = binsearch(nums, st, mid, target);
            if (r1 != -1) {
                return r1;
            }
            return binsearch(nums, mid, ed, target);
        }
        return -1; // illegal
    }
    // 33. Search in Rotated Sorted Array
    // Prior to being passed to your function, nums is possibly rotated at an unknown pivot index
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
            vector<int> res{mid, mid};
            for (int i = mid - 1; i >= st; i--) {
                if (nums[i] != target) {
                    break;
                }
                res[0] = i;
            }
            for (int i = mid + 1; i < ed; i++) {
                if (nums[i] != target) {
                    break;
                }
                res[1] = i;
            }
            return res;
        }
    }
    // 34. Find First and Last Position of Element in Sorted Array
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
                return st == 0 ? 0 : st - 1;
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
    // 35. Search Insert Position
    // Given a sorted array of distinct integers and a target value, return the index if the target is found.
    // If not, return the index where it would be if it were inserted in order.
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
    // 37. Sudoku Solver
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

    // 3. Longest Substring Without Repeating Characters
    // Given a string s, find the length of the longest substring without repeating characters.
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
    // Given an integer array nums and an integer k, return the kth largest element in the array.
    // Note that it is the kth largest element in the sorted order, not the kth distinct element.
    // Can you solve it without sorting?
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
    int partition(vector<int>& nums, int low, int high) {
        int x = nums[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && nums[j] >= x) {
                j--;
            }
            if (i < j) {
                nums[i] = nums[j];
            }
            while (i < j && nums[i] <= x) {
                i++;
            }
            if (i < j) {
                nums[j] = nums[i];
            }
        }
        nums[i] = x;
        return i;
    }
    void doqsort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int p = partition(nums, low, high);
        doqsort(nums, low, p - 1);
        doqsort(nums, p + 1, high);
    }
    void qsort(vector<int>& nums) {
        doqsort(nums, 0, nums.size() - 1);
    }
    int findKthLargestQsort(vector<int>& nums, int k) {
        int low = 0, high = nums.size() - 1;
        int idx = nums.size() - k;
        while (low < high) {
            int p = partition(nums, low, high);
            if (p == idx) {
                return nums[p];
            } else if (p > idx) {
                high = p - 1;
            } else {
                low = p + 1;
            }
        }
        return nums[low];
    }

    // 347. Top K Frequent Elements
    // Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
    // Constraints:
    // 1 <= nums.length <= 105
    // -104 <= nums[i] <= 104
    // k is in the range [1, the number of unique elements in the array].
    // It is guaranteed that the answer is unique.
    int partitionPair(vector<pair<int, int>>& vec, int i, int j) {
        auto x = vec[i];
        while (i < j) {
            while (i < j && vec[j].second >= x.second) {
                j--;
            }
            if (i < j) {
                vec[i] = vec[j];
            }
            while (i < j && vec[i].second <= x.second) {
                i++;
            }
            if (i < j) {
                vec[j] = vec[i];
            }
        }
        vec[i] = x;
        return i;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency; // count frequency
        for (int i = 0; i < nums.size(); i++) {
            if (frequency.find(nums[i]) == frequency.end()) {
                frequency[nums[i]] = 0;
            }
            frequency[nums[i]]++;
        }
        vector<pair<int, int>> vec;
        vec.reserve(frequency.size());
        for (auto iter = frequency.begin(); iter != frequency.end(); iter++) {
            vec.push_back(make_pair(iter->first, iter->second));
        }
        int n = vec.size();
        int low = 0, high = n - 1;
        int revert_k = n - k; // revert
        while (low < high) {
            int p = partitionPair(vec, low, high); // left smaller, right larger
            if (p == revert_k) {
                break;
            } else if (p > revert_k) {
                high = p - 1;
            } else {
                low = p + 1;
            }
        }
        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; i++) {
            res.push_back(vec[n - 1 - i].first);
        }
        return res;
    }

    // 349. Intersection of Two Arrays
    // Given two integer arrays nums1 and nums2, return an array of their intersection.
    // Each element in the result must be unique and you may return the result in any order.
    // Constraints:
    // 1 <= nums1.length, nums2.length <= 1000
    // 0 <= nums1[i], nums2[i] <= 1000
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> hash(1001, 0);
        for (int i = 0; i < nums1.size(); i++) {
            hash[nums1[i]] = 1;
        }
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++) {
            if (hash[nums2[i]]) {
                hash[nums2[i]] = 0;
                res.push_back(nums2[i]);
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

    // 2433. Find The Original Array of Prefix Xor
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        res.reserve(pref.size());
        if (pref.empty()) {
            return res;
        }
        res.push_back(pref[0]);
        for (int i = 1; i < pref.size(); i++) {
            res.push_back(pref[i - 1] ^ pref[i]);
        }
        return res;
    }

    // 868. Binary Gap
    // Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n.
    // If there are no two adjacent 1's, return 0.
    int binaryGap(int n) {
        int mod = 0, quo = n;
        int res = 0;
        int st = -1;
        int i = 0;
        do {
            if (quo % 2 == 1) {
                if (st >= 0) {
                    res = max(res, i - st);
                }
                st = i;
            }
            quo = quo >> 1;
            i++;
        } while (quo > 0);
        return res;
    }

    // 2103. Rings and Rods
    // There are n rings and each ring is either red, green, or blue. The rings are distributed across ten rods labeled from 0 to 9.
    // You are given a string rings of length 2n that describes the n rings that are placed onto the rods. Every two characters in rings forms a color-position pair that is used to describe each ring where:
    // The first character of the ith pair denotes the ith ring's color ('R', 'G', 'B').
    // The second character of the ith pair denotes the rod that the ith ring is placed on ('0' to '9').
    // For example, "R3G2B1" describes n == 3 rings: a red ring placed onto the rod labeled 3, a green ring placed onto the rod labeled 2, and a blue ring placed onto the rod labeled 1.
    // Return the number of rods that have all three colors of rings on them.
    int countPoints(string rings) {
        int len = rings.size() / 2;
        vector<char> buckets(10, 0);
        for (int i = 0; i < rings.size(); i += 2) {
            int key = rings[i + 1] - '0';
            switch (rings[i]) {
                case 'R':
                    buckets[key] |= 1;
                    break;
                case 'G':
                    buckets[key] |= 2;
                    break;
                case 'B':
                    buckets[key] |= 4;
                    break;
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (buckets[i] == 7) ans++;
        }
        return ans;
    }

    // 912. Sort an Array
    // Given an array of integers nums, sort the array in ascending order and return it.
    // You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
    vector<int> sortArray(vector<int>& nums) {
        // quickSortArray(nums, 0, nums.size() - 1); // quick sort won't pass some anti-quick-sort cases
        hashBucketSortArray(nums); // values not too large, can use bucket sort
        return nums;
    }
    void quickSortArray(vector<int>& nums, int start, int end) {
        if (start >= end) return;
        int mid = nums[start];
        int i = start, j = end;
        while (i < j) {
            while (i < j && nums[j] >= mid) {
                j--;
            }
            if (i < j) {
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] <= mid) {
                i++;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }
        nums[i] = mid; // i == j
        quickSortArray(nums, start, i - 1);
        quickSortArray(nums, i + 1, end);
    }
    void hashBucketSortArray(vector<int>& nums) {
        vector<int> m(100001, 0);
        const int offset = 50000;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i] + offset] += 1;
        }
        int cur = 0;
        for (int i = 0; i <= 100000; i++) {
            for (int j = 0; j < m[i]; j++) {
                nums[cur++] = i-offset;
            }
        }
    }
    void treeBucketSortArray(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 0;
            }
            m[nums[i]] += 1;
        }
        int cur = 0;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            for (int i = 0; i < iter->second; i++) {
                nums[cur++] = iter->first;
            }
        }
    }
};
