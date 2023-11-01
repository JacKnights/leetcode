#include <vector>
#include <unordered_map>
#include "helper.cpp"

using namespace std;

// 303. Range Sum Query - Immutable
// Given an integer array nums, handle multiple queries of the following type:
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:
// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        sums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            sums.push_back(sums[i] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return this->sums[right + 1] - this->sums[left];
    }
};

// 304. Range Sum Query 2D - Immutable
// Given a 2D matrix matrix, handle multiple queries of the following type:
// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:
// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// You must design an algorithm where sumRegion works on O(1) time complexity.
class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        this->sums = vector<vector<int>>(m, vector<int>(n));
        sums[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) {
            sums[i][0] = sums[i - 1][0] + matrix[i][0];
        }
        for (int j = 1; j < n; j++) {
            sums[0][j] = sums[0][j - 1] + matrix[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sums[i][j] = matrix[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sums[row2][col2];
        if (row1 > 0) {
            ans -= sums[row1 - 1][col2];
        }
        if (col1 > 0) {
            ans -= sums[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0) {
            ans += sums[row1 - 1][col1 - 1];
        }
        return ans;
    }
};