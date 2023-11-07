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
    int maxHeight(vector<vector<int>> &cuboids) {
        for (int i = 0; i < cuboids.size(); i++) { // sorting each value
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end(), comp); // sorting the array

        vector<vector<int>> dp(cuboids.size() + 1, vector<int>(cuboids.size() + 1, 0));
        for (int i = cuboids.size() - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i][j + 1] = max(dp[i + 1][j + 1], cuboids[i][2] + dp[i + 1][i + 1]);
                } else {
                    dp[i][j + 1] = dp[i + 1][j + 1];
                }
            }
            dp[i][0] = max(dp[i + 1][0], cuboids[i][2] + dp[i + 1][i + 1]);
        }
        return dp[0][0];
    }
};
