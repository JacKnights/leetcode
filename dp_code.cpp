#include <limits.h>
#include <math.h>
#include <memory.h>
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

class DPSolution {
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
    // Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
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
    // Given a string s, find the longest palindromic subsequence's length in s.
    // A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
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
    // Given an integer array nums, find the subarray with the largest sum, and return its sum.
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
    // You are given an array prices where prices[i] is the price of a given stock on the ith day.
    // You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    // Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
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
    // You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
    // On each day, you may decide to buy and/or sell the stock.
    // You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
    // Find and return the maximum profit you can achieve.
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
    // You are given an array prices where prices[i] is the price of a given stock on the ith day.
    // Find the maximum profit you can achieve. You may complete at most two transactions.
    // Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
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

    // 188. Best Time to Buy and Sell Stock IV
    // You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
    // Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
    // Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
    // dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
    int maxProfit4(int K, vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        vector<vector<int>> dp(K + 1, vector<int>(prices.size(), 0));
        for (int k = 1; k <= K; k++) {
            for (int i = 1; i < len; i++) {
                int minCost = -prices[0];
                for (int j = 1; j < i; j++) {
                    minCost = max(minCost, dp[k - 1][j - 1] - prices[j]);
                }
                dp[k][i] = max(dp[k][i - 1], prices[i] + minCost);
            }
        }
        return dp[K][len - 1];
    }

    // 55. Jump Game
    // You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
    // Return true if you can reach the last index, or false otherwise.
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int last = 0;
        for (int i = 0; i < len - 1; i++) {
            if (last < i) {
                return false;
            }
            last = max(last, i + nums[i]);
            if (last >= len - 1) {
                return true;
            }
        }
        return last >= len - 1;
    }

    // 45. Jump Game II
    // You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
    // Each element nums[i] represents the maximum length of a forward jump from index i.
    // In other words, if you are at nums[i], you can jump to any nums[i + j] where: 0 <= j <= nums[i] and i + j < n
    // Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
    int jump(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int first = 0, last = 0; // current reachable [first, last]
        for (int i = 0; i < len - 1; i++) {
            last = max(last, i + nums[i]);
            if (i == first) {
                res++;
                first = last;
                if (last >= len - 1) break;
            }
        }
        return res;
    }

    // 1306. Jump Game III
    // Given an array of non-negative integers arr, you are initially positioned at start index of the array.
    // When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.
    // Notice that you can not jump outside of the array at any time.
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> visited;
        return doCanReach(visited, arr, start);
    }
    bool doCanReach(unordered_set<int>& visited, vector<int>& arr, int root) {
        if (root < 0 || root >= arr.size()) return false;
        if (visited.find(root) != visited.end()) return false;
        if (arr[root] == 0) return true;
        visited.insert(root);
        int left = root - arr[root];
        int right = root + arr[root];
        return doCanReach(visited, arr, left) || doCanReach(visited, arr, right);
    }

    // 1345. Jump Game IV
    // Given an array of integers arr, you are initially positioned at the first index of the array.
    // In one step you can jump from index i to index:
    // i + 1 where: i + 1 < arr.length.
    // i - 1 where: i - 1 >= 0.
    // j where: arr[i] == arr[j] and i != j.
    // Return the minimum number of steps to reach the last index of the array.
    // Notice that you can not jump outside of the array at any time.
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        if (len == 1) return 0; 
        vector<int> dp(len, INT_MAX); // record jumps
        unordered_map<int, vector<int>> m; // map value -> indexes
        for (int i = 0; i < len; i++) {
            if (m.find(arr[i]) == m.end()) {
                m[arr[i]] = vector<int>();
            }
            m[arr[i]].push_back(i);
        }
        queue<pair<int, int>> q; // for bfs, record index&value pairs
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            int index = q.front().first;
            int level = q.front().second;
            q.pop();
            if (index == len - 1) return level; // end of search, must break
            dp[index] = level;
            int value = arr[index];
            if (m.find(value) != m.end()) {
                for (auto iter = m[value].begin(); iter != m[value].end(); iter++) {
                    if (dp[*iter] > level + 1) { // if indexes with same value not searched
                        q.push(make_pair(*iter, level + 1));
                    }
                }
                m.erase(value); // save memory or it will exceed for some cases
            }
            if (index > 0 && dp[index - 1] > level + 1) { // if left not searched
                q.push(make_pair(index - 1, level + 1));
            }
            if (index < len - 1 && dp[index + 1] > level + 1) { // if right not searched
                q.push(make_pair(index + 1, level + 1));
            }
        }
        return dp[len - 1];
    }

    // 1340. Jump Game V
    // Given an array of integers arr and an integer d. In one step you can jump from index i to index:
    // i + x where: i + x < arr.length and  0 < x <= d.
    // i - x where: i - x >= 0 and  0 < x <= d.
    // In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).
    // You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.
    // Notice that you can not jump outside of the array at any time.
    int maxJumps(vector<int>& arr, int d) { // my solution
        int len = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (int i = 0; i < len; i++) {
            min_heap.push(make_pair(arr[i], i)); // record indexes ascent order by their values
        }
        vector<int> dp(len, 1); // at least one jump for each
        while (!min_heap.empty()) { // pop index with current smallest value
            int index = min_heap.top().second;
            min_heap.pop();
            int left_max = arr[index]; // cannot jump to left elem smaller than left max
            for (int i = index - 1; i >= max(0, index - d); i--) {
                if (arr[i] > left_max) {
                    dp[i] = max(dp[i], dp[index] + 1);
                }
                left_max = max(left_max, arr[i]);
            }
            int right_max = arr[index]; // cannot jump to right elem smaller than right max
            for (int i = index + 1; i <= min(len - 1, index + d); i++) {
                if (arr[i] > right_max) {
                    dp[i] = max(dp[i], dp[index] + 1);
                }
                right_max = max(right_max, arr[i]);
            }
        }
        int res = *max_element(dp.begin(), dp.end());
        return res;
    }
    // best
    // int dfs(vector<int>& arr, vector<int>& dp, int i, int d, int res = 1) {
    //     if (dp[i]) return dp[i];
    //     int n = arr.size();
    //     for (auto j = i + 1; j <= min(i + d, n - 1) && arr[j] < arr[i]; ++j)
    //         res = max(res, 1 + dfs(arr, dp, j, d));
    //     for (auto j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; --j)
    //         res = max(res, 1 + dfs(arr, dp, j, d));
    //     return dp[i] = res;
    // }
    // int maxJumps(vector<int>& arr, int d, int res = 1) {
    //     vector<int> dp(arr.size(), 0);
    //     for (auto i = 0; i < arr.size(); ++i)
    //         res = max(res, dfs(arr, dp, i, d));
    //     return res;
    // }

    // 1696. Jump Game VI
    // You are given a 0-indexed integer array nums and an integer k.
    // You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array.
    // That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.
    // You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.
    // Return the maximum score you can get.
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> dp(len);
        deque<int> q; // indexes with dp value in descent order
        dp[0] = nums[0];
        q.push_back(0);
        for (int i = 1; i < len; i++) {
            while (q.front() < i - k) { // drop unreachable indexes
                q.pop_front();
            }
            dp[i] = nums[i] + dp[q.front()]; // q front has the max sum for each index i
            while (!q.empty() && dp[q.back()] <= dp[i]) { // make sure every dp with index in q in desc order
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp.back();
    }

    // 1871. Jump Game VII
    // You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'.
    // You can move from index i to index j if the following conditions are fulfilled: i + minJump <= j <= min(i + maxJump, s.length - 1), and s[j] == '0'.
    // Return true if you can reach index s.length - 1 in s, or false otherwise.
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i]) {
                for (last = max(last, i + minJump); last <= min(n - 1, i + maxJump); ++last) {
                    if (s[last] == '0') {
                        dp[last] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }

    // 44. wildcard matching
    // Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    // '?' Matches any single character.
    // '*' Matches any sequence of characters (including the empty sequence).
    // The matching should cover the entire input string (not partial).
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, false));
        dp[0][0] = true; // both empty
        for (int j = 0; j < p.size() && p[j] == '*'; j++) { // match void
            dp[0][j + 1] = true;
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                if (p[j] == '*') { // match multiple or void or single
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i][j];
                } else { // match single
                    dp[i + 1][j + 1] = (s[i] == p[j] || p[j] == '?') && dp[i][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }

    // 62. Unique Paths
    // There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
    // The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
    // The robot can only move either down or right at any point in time.
    // Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
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
    // You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]).
    // The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
    // The robot can only move either down or right at any point in time.
    // An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
    // Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
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

    // 64. Minimum Path Sum
    // Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
    // Note: You can only move either down or right at any point in time.
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

    // 42. Trapping Rain Water
    // Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
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

    // 407. Trapping Rain Water II
    // Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // smallest on top, which is the lowest height
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) { // add the edges and corners
                    min_heap.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }
        int cur_bottom = 0; // current bottom or the water
        int res = 0;
        while (!min_heap.empty()) {
            auto t = min_heap.top();
            min_heap.pop();
            int h = t.first, x0 = t.second / n, y0 = t.second % n;
            cur_bottom = max(cur_bottom, h);
            int dirs[4][2] = {{0,-1},{-1,0},{0,1},{1,0}}; // check 4 adjacent coordinates
            for (int i = 0; i < 4; ++i) {
                int x = x0 + dirs[i][0], y = y0 + dirs[i][1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) {
                    continue;
                }
                if (cur_bottom > heightMap[x][y]) {
                    res += (cur_bottom - heightMap[x][y]);
                }
                min_heap.push({heightMap[x][y], x * n + y});
                visited[x][y] = true;
            }
        }
        return res;
    }

    // 494. Target Sum
    // You are given an integer array nums and an integer target.
    // You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
    // For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
    // Return the number of different expressions that you can build, which evaluates to target.
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || target < -sum) {
            return 0;
        }
        if ((target + sum) % 2 != 0) { // target and sum should both be even or odd
            return 0;
        }
        int new_target = (target + sum) / 2; // sum = A + B and target = A - B, A = (sum+target)/2
        vector<int> dp(new_target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) { // 01 knapsack problem
            for (int j = new_target; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[new_target];
    }

    // 322. Coin Change
    // You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    // Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
    // You may assume that you have an infinite number of each kind of coin.
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount]: -1;
    }

    // 518. Coin Change II
    // You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    // Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
    // You may assume that you have an infinite number of each kind of coin.
    // The answer is guaranteed to fit into a signed 32-bit integer.
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }

    // 474. Ones and Zeros
    // You are given an array of binary strings strs and two integers m and n.
    // Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
    // A set x is a subset of a set y if all elements of x are also elements of y.
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> ones(strs.size(), 0);
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '1') {
                    ones[i]++;
                }
            }
        }
        // not compressed
        // vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // int c1 = ones[0];
        // int c0 = strs[0].size() - c1;
        // for (int j = c0; j <= m; j++) {
        //     for (int k = c1; k <= n; k++) {
        //         dp[0][j][k] = 1;
        //     }
        // }
        // for (int i = 1; i < strs.size(); i++) {
        //     int c1 = ones[i];
        //     int c0 = strs[i].size() - c1;
        //     for (int j = 0; j <= m; j++) {
        //         for (int k = 0; k <= n; k++) {
        //             if (j >= c0 && k >= c1) {
        //                 dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - c0][k - c1] + 1);
        //             } else {
        //                 dp[i][j][k] = dp[i - 1][j][k];
        //             }
        //         }
        //     }
        // }
        // return dp[strs.size() - 1][m][n];

        // compressed
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= strs.size(); i++) {
            int c1 = ones[i - 1];
            int c0 = strs[i - 1].size() - c1;
            for (int j = m; j >= c0; j--) {
                for (int k = n; k >= c1; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - c0][k - c1]);
                }
            }
        }
        return dp[m][n];
    }

    // 279. Perfect Squares
    // Given an integer n, return the least number of perfect square numbers that sum to n.
    // A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.
    // For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
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

    // 403. Frog Jump
    // Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone.
    // Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
    // If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.
    // Input: stones = [0,1,3,5,6,8,12,17]
    // Output: true
    // Explanation: 1 unit to the 2nd stone,
    //  then 2 units to the 3rd stone,
    //   then 2 units to the 4th stone,
    //    then 3 units to the 6th stone,
    //     4 units to the 7th stone,
    //      and 5 units to the 8th stone.
    // bool canCross(vector<int>& stones) {
    //     unordered_set<int> st;
    //     if (stones[0] != 0 || stones[1] != 1) {
    //         return false;
    //     }
    //     st.insert(stones[0]);
    //     for (int i = 1; i < stones.size(); i++) {
    //         if (stones[i] - stones[i-1] > i) {
    //             return false;
    //         }
    //         st.insert(stones[i]);
    //     }
    //     return doCanCross(st, 1, 1, stones[stones.size() - 1]);
    // }
    // bool doCanCross(unordered_set<int>& st, int pos, int k, int end) {
    //     if (pos + k - 1 <= end && pos + k + 1 >= end) {
    //         return true;
    //     }
    //     for (int new_k = k - 1; new_k <= k + 1; new_k++) {
    //         if (new_k < 1) {
    //             continue;
    //         }
    //         if (st.find(pos + new_k) != st.end() && doCanCross(st, pos + new_k, new_k, end)) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // current AC solution
    bool doCanCross(vector<int> &stones, vector<vector<int>> &dp, int cur, int pre_step) {
        if (cur == stones.size() - 1) return true; // reach end
        if (dp[cur][pre_step] != -1) return dp[cur][pre_step]; // already processed

        int min_step = max(1, pre_step - 1); // cannot be zero
        int max_step = pre_step + 1;
        int left = lower_bound(stones.begin(), stones.end(), stones[cur] + min_step) - stones.begin();
        int right = upper_bound(stones.begin(), stones.end(), stones[cur] + max_step) - stones.begin();

        for (int i = left; i < right; i++) {
            if (doCanCross(stones, dp, i, stones[i] - stones[cur])) {
                dp[cur][pre_step] = true;
                return true;
            }
        }
        dp[cur][pre_step] = false;
        return false;
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        return doCanCross(stones, dp, 0, 0);
    }

    // 416. Partition Equal Subset Sum
    // Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
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
            for (int j = target; j >= nums[i]; j--) {
                reach[j] = reach[j] || reach[j - nums[i]];
            }
            if (reach[target]) break;
        }
        return reach[target];
    }

    // 300. Longest Increasing Subsequence
    // Given an integer array nums, return the length of the longest strictly increasing subsequence.
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }

    // 1691. Maximum Height by Stacking Cuboids
    // Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.
    // You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
    // Return the maximum height of the stacked cuboids.
    static bool comp(vector<int> &d1, vector<int> &d2) { // comparator function
        if (d1[0] == d2[0]) {
            if (d1[1] == d2[1]) {
                return d1[2] < d2[2];
            }
            return d1[1] < d2[1];
        }
        return d1[0] < d2[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for (int i = 0; i < cuboids.size(); i++) { // sorting each value
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end(), comp); // sorting the array
        vector<int> dp(cuboids.size(), 0);
        for (int i = 0; i < cuboids.size(); i++) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++) {
                if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end()); // 得到以任意长方体结尾的最大高度中的最大值
    }

    // 1547. Minimum Cost to Cut a Stick
    // Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
    // Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
    // You should perform the cuts in order, you can change the order of the cuts as you wish.
    // The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
    // Return the minimum total cost of the cuts.
    int recursion(vector<vector<int>>& dp, vector<int> &cuts, int l, int r, int left, int right) {
        if (r < l) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        for (int i = l; i <= r; i++) {
            int current = recursion(dp, cuts, l, i - 1, left, cuts[i]) + recursion(dp, cuts, i + 1, r, cuts[i], right);
            int length = right - left;
            ans = min(ans, length + current);
        }
        return dp[l][r] = ans;
    }
    int minCost(int n, vector<int> &cuts) {
        vector<vector<int>> dp = vector<vector<int>>(cuts.size() + 1, vector<int>(cuts.size() + 1, -1));
        sort(cuts.begin(), cuts.end());
        return recursion(dp, cuts, 0, cuts.size() - 1, 0, n);
    }
};
