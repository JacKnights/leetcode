#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include "code.cpp"
#include "dp_code.cpp"
#include "list_code.cpp"
#include "tree_code.cpp"
#include "lru_cache.cpp"
#include "range_sum.cpp"
#include "helper.cpp"

using namespace std;

class MainSolution: public Solution, public DPSolution, public TreeSolution, public LinkedListSolution {

};

int main(int argc, char *argv[]) {
    set<string> args;
    for (int i = 0; i < argc; i++) {
        args.insert(argv[i]);
    }

    MainSolution s;
    if (args.find("longestPalindrome") != args.end()) {
        printf("longestPalindrome: %s\n", s.longestPalindrome("asdasdsad").c_str());
        printf("longestPalindrome: %s\n", s.longestPalindrome("ahha").c_str());
    }
    if (args.find("countSubstrings") != args.end()) {
        printf("countSubstrings: %d\n", s.countSubstrings("aaa"));
        printf("countSubstrings: %d\n", s.countSubstrings("abcd"));
    }
    if (args.find("isPalindrome") != args.end()) {
        printf("isPalindrome: %d\n", s.isPalindrome(12321));
        printf("isPalindrome: %d\n", s.isPalindrome(12));
        printf("isPalindrome: %d\n", s.isPalindrome(1241));
    }
    if (args.find("intToRoman") != args.end()) {
        printf("intToRoman: %s\n", s.intToRoman(1241).c_str());
        printf("intToRoman: %s\n", s.intToRoman(1994).c_str());
        printf("intToRoman: %s\n", s.intToRoman(3999).c_str());
    }
    if (args.find("romanToInt") != args.end()) {
        printf("romanToInt: %d\n", s.romanToInt("IX"));
        printf("romanToInt: %d\n", s.romanToInt("ID"));
        printf("romanToInt: %d\n", s.romanToInt("DVIII"));
    }

    if (args.find("letterCombinations") != args.end()) {
        vector<string> vec_str = s.letterCombinations("234");
        printf("letterCombinations: \n");
        printVectorString(vec_str, vec_str.size());
        printf("\n");
    }

    if (args.find("isValid") != args.end()) {
        printf("isValid: %d\n", s.isValid("["));
        printf("isValid: %d\n", s.isValid("]"));
        printf("isValid: %d\n", s.isValid("(]"));
        printf("isValid: %d\n", s.isValid("[()]"));
        printf("isValid: %d\n", s.isValid("()[]{}"));
    }

    if (args.find("generateParenthesis") != args.end()) {
        vector<string> vec_str;
        vec_str = s.generateParenthesis(3);
        printf("generateParenthesis: \n");
        printVectorString(vec_str, vec_str.size());
        printf("\n");
    }

    if (args.find("removeDuplicates") != args.end()) {
        vector<int> nums{0, 1, 1, 2, 2, 3, 3, 4};
        int res = s.removeDuplicates(nums);
        printf("removeDuplicates: %d\n", res);
        printVectorInt(nums, res);
        printf("\n");
    }

    if (args.find("removeElement") != args.end()) {
        vector<int> nums{0, 1, 1, 2, 2, 3, 3, 4};
        int res = s.removeElement(nums, 3);
        printf("removeElement: %d\n", res);
        printVectorInt(nums, res);
        printf("\n");
    }

    if (args.find("strStr") != args.end()) {
        printf("strStr: %d\n", s.strStr("abcdefg", "bcd"));
        printf("strStr: %d\n", s.strStr("abcdefg", "efg"));
        printf("strStr: %d\n", s.strStr("a", "a"));
        printf("strStr: %d\n", s.strStr("abc", "abcd"));
        printf("strStr: %d\n", INT32_MAX);
        printf("strStr: %d\n", INT32_MIN);
    }

    if (args.find("findSubstring") != args.end()) {
        string str;
        vector<string> words;
        vector<int> res;

        str = "barfoofoobarthefoobarman";
        words = {"bar", "foo", "the"};
        res = s.findSubstring(str, words);
        printf("findSubstring: \n");
        printVectorInt(res, res.size());
        printf("\n");

        str = "wordgoodgoodgoodbestword";
        words = {"word", "good", "best", "good"};
        res = s.findSubstring(str, words);
        printf("findSubstring: \n");
        printVectorInt(res, res.size());
        printf("\n");

        str = "barfoothefoobarman";
        words = {"foo", "bar"};
        res = s.findSubstring(str, words);
        printf("findSubstring: \n");
        printVectorInt(res, res.size());
        printf("\n");
    }

    if (args.find("nextPermutation") != args.end()) {
        vector<int> nums;

        nums = {1, 2, 3, 4, 5};
        s.nextPermutation(nums);
        printf("nextPermutation: \n");
        printVectorInt(nums, nums.size());

        nums = {1, 5, 8, 4, 7, 6, 5, 3, 1};
        s.nextPermutation(nums);
        printf("nextPermutation: \n");
        printVectorInt(nums, nums.size());

        nums = {1, 3, 2};
        s.nextPermutation(nums);
        printf("nextPermutation: \n");
        printVectorInt(nums, nums.size());

        nums = {3, 2, 1};
        s.nextPermutation(nums);
        printf("nextPermutation: \n");
        printVectorInt(nums, nums.size());
    }

    if (args.find("longestValidParentheses") != args.end()) {
        printf("longestValidParentheses: %d\n", s.longestValidParentheses("()()()"));
        printf("longestValidParentheses: %d\n", s.longestValidParentheses("(())"));
        printf("longestValidParentheses: %d\n", s.longestValidParentheses(")())"));
    }

    if (args.find("searchInOrder") != args.end()) {
        vector<int> nums;

        nums = {1, 2, 3, 4, 5};
        printf("searchInOrder: %d\n", s.search1(nums, 3));

        nums = {1, 2, 3, 4, 5};
        printf("searchInOrder: %d\n", s.search1(nums, 4));

        nums = {1, 2, 3, 4, 5};
        printf("searchInOrder: %d\n", s.search1(nums, 6));
    }

    if (args.find("searchInRotated") != args.end()) {
        vector<int> nums;

        nums = {6, 7, 8, 9, 1, 2, 3, 4, 5};
        printf("searchInRotated: %d\n", s.search(nums, 3));

        nums = {6, 7, 8, 9, 1, 2, 3, 4, 5};
        printf("searchInRotated: %d\n", s.search(nums, 8));

        nums = {1, 2, 3, 4, 5};
        printf("searchInRotated: %d\n", s.search(nums, 6));
    }

    if (args.find("searchRange") != args.end()) {
        vector<int> nums;
        vector<int> res;

        nums = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7};
        res = s.searchRange(nums, 3);
        printf("searchRange: \n");
        printVectorInt(res, res.size());

        nums = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7};
        res = s.searchRange(nums, 5);
        printf("searchRange: \n");
        printVectorInt(res, res.size());

        nums = {1, 1, 2, 3, 3, 3, 4, 4, 6, 6, 7};
        res = s.searchRange(nums, 5);
        printf("searchRange: \n");
        printVectorInt(res, res.size());
    }

    if (args.find("searchInsert") != args.end()) {
        vector<int> nums;

        nums = {1, 2, 3, 4, 5};
        printf("searchInsert: %d\n", s.searchInsert(nums, 3));

        nums = {1, 2, 3, 5};
        printf("searchInsert: %d\n", s.searchInsert(nums, 4));

        nums = {2, 3, 4, 5};
        printf("searchInsert: %d\n", s.searchInsert(nums, 1));

        nums = {1, 2, 3, 4};
        printf("searchInsert: %d\n", s.searchInsert(nums, 5));
    }

    if (args.find("isValidSudoku") != args.end()) {
        vector<vector<char>> board;

        board = {{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                 {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                 {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                 {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                 {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                 {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                 {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                 {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                 {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
        printf("isValidSudoku: %d\n", s.isValidSudoku(board));
    }
    if (args.find("isValidSudoku") != args.end()) {
        vector<vector<char>> board;
        board = {{'.', '.', '.', '.', '.', '.', '5', '.', '.'},
                 {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                 {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                 {'9', '3', '.', '.', '2', '.', '4', '.', '.'},
                 {'.', '.', '7', '.', '.', '.', '3', '.', '.'},
                 {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                 {'.', '.', '.', '3', '4', '.', '.', '.', '.'},
                 {'.', '.', '.', '.', '.', '3', '.', '.', '.'},
                 {'.', '.', '.', '.', '.', '5', '2', '.', '.'}};
        printf("isValidSudoku: %d\n", s.isValidSudoku(board));
    }

    if (args.find("solveSudoku") != args.end()) {
        vector<vector<char>> board;
        board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        s.solveSudoku(board);
        printf("solveSudoku: \n");
        printVectorChar2D(board);
    }

    if (args.find("printTree") != args.end()) {
        TreeNode* root;
        vector<vector<string>> res;

        root = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(6)), new TreeNode(5)), new TreeNode(3));
        res = s.printTree(root);
        printVectorString2D(res);

        root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(5)), nullptr), nullptr);
        res = s.printTree(root);
        printVectorString2D(res);

        root = new TreeNode(1, nullptr, new TreeNode(2));
        res = s.printTree(root);
        printVectorString2D(res);

        root = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
        res = s.printTree(root);
        printVectorString2D(res);
    }

    if (args.find("isSameTree") != args.end()) {
        TreeNode* p;
        TreeNode* q;
        p = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(6)), new TreeNode(5)), new TreeNode(3));
        q = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(6)), new TreeNode(5)), new TreeNode(3));
        printf("isSameTree: %d\n", s.isSameTree(p, q));

        p = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(6)), new TreeNode(5)), new TreeNode(3));
        q = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, nullptr), new TreeNode(5)), new TreeNode(3));
        printf("isSameTree: %d\n", s.isSameTree(p, q));

        p = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(6)), new TreeNode(5)), new TreeNode(3));
        q = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(7)), new TreeNode(5)), new TreeNode(3));
        printf("isSameTree: %d\n", s.isSameTree(p, q));
    }

    if (args.find("buildTree") != args.end()) {
        TreeNode* root;
        vector<vector<string>> res;
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        root = s.buildTree(preorder, inorder);
        res = s.printTree(root);
        printVectorString2D(res);
    }

    if (args.find("numTrees") != args.end()) {
        for (int i = 0; i < 7; i++) {
            printf("i: %d, numTrees: %d\n", i, s.numTrees(i));
        }
        for (int i = 0; i < 7; i++) {
            printf("i: %d, numTreesDP: %d\n", i, s.numTreesDP(i));
        }
    }

    if (args.find("generateTrees") != args.end()) {
        for (int i = 1; i <= 3; i++) {
            vector<TreeNode*> res;
            res = s.generateTrees(i);

            printf("i: %d, generateTrees: \n", i);
            for (int j = 0; j < res.size(); j++) {
                printVectorString2D(s.printTree(res[j]));
            }
        }
    }

    if (args.find("isValidBST") != args.end()) {
        printf("isValidBST: %d\n", s.isValidBST(new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(6)), new TreeNode(5)), new TreeNode(3))));
        printf("isValidBST: %d\n", s.isValidBST(new TreeNode(6, new TreeNode(4, new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), nullptr), new TreeNode(5)), new TreeNode(7))));
        printf("isValidBST: %d\n", s.isValidBST(new TreeNode(2, new TreeNode(2), new TreeNode(2))));
    }

    if (args.find("recoverTree") != args.end()) {
        TreeNode* root;
        vector<vector<string>> res;
        root = new TreeNode(4, new TreeNode(1, new TreeNode(2), new TreeNode(3)), nullptr);
        s.recoverTree(root);
        res = s.printTree(root);
        printVectorString2D(res);

        root = new TreeNode(3, new TreeNode(1), new TreeNode(4, new TreeNode(2), nullptr));
        s.recoverTree(root);
        res = s.printTree(root);
        printVectorString2D(res);

        root = new TreeNode(2, new TreeNode(3), new TreeNode(1));
        s.recoverTree(root);
        res = s.printTree(root);
        printVectorString2D(res);

        root = new TreeNode(146, new TreeNode(71, new TreeNode(55, new TreeNode(321, new TreeNode(-33), nullptr), nullptr), nullptr), new TreeNode(-13, new TreeNode(231), new TreeNode(399)));
        res = s.printTree(root);
        printVectorString2D(res);
        s.recoverTree(root);
        res = s.printTree(root);
        printVectorString2D(res);

        root = new TreeNode(5, new TreeNode(2, nullptr, new TreeNode(4, new TreeNode(3, new TreeNode(1), nullptr), nullptr)), nullptr);
        res = s.printTree(root);
        printVectorString2D(res);
        s.recoverTree(root);
        res = s.printTree(root);
        printVectorString2D(res);
    }

    if (args.find("levelOrder") != args.end()) {
        TreeNode* root;
        vector<vector<int>> res;

        root = new TreeNode(5, new TreeNode(2, nullptr, new TreeNode(4, new TreeNode(3, new TreeNode(1), nullptr), nullptr)), nullptr);
        res = s.levelOrder(root);
        printf("levelOrder:\n");
        printVectorInt2D(res);

        root = new TreeNode(146, new TreeNode(71, new TreeNode(55, new TreeNode(321, new TreeNode(-33), nullptr), nullptr), nullptr), new TreeNode(-13, new TreeNode(231), new TreeNode(399)));
        res = s.levelOrder(root);
        printf("levelOrder:\n");
        printVectorInt2D(res);

        res = s.levelOrderBottom(root);
        printf("levelOrderBottom:\n");
        printVectorInt2D(res);
    }

    if (args.find("ladderLength") != args.end()) {
        string beginWord;
        string endWord;
        vector<string> wordList;

        beginWord = "a";
        endWord = "b";
        wordList = {"a", "b"};
        printf("ladderLength: %d\n", s.ladderLength(beginWord, endWord, wordList));

        beginWord = "ab";
        endWord = "cd";
        wordList = {"cb", "cd"};
        printf("ladderLength: %d\n", s.ladderLength(beginWord, endWord, wordList));
    }

    if (args.find("generatePascalTriangle") != args.end()) {
        vector<vector<int>> res;
        res = s.generate(1);
        printf("generatePascalTriangle\n");
        printVectorInt2D(res);
        res = s.generate(5);
        printf("generatePascalTriangle\n");
        printVectorInt2D(res);
    }

    if (args.find("getRowPascalTriangle") != args.end()) {
        vector<int> res;
        res = s.getRow(0);
        printf("getRowPascalTriangle\n");
        printVectorInt(res, res.size());
        res = s.getRow(1);
        printf("getRowPascalTriangle\n");
        printVectorInt(res, res.size());
        res = s.getRow(4);
        printf("getRowPascalTriangle\n");
        printVectorInt(res, res.size());
        res = s.getRow(5);
        printf("getRowPascalTriangle\n");
        printVectorInt(res, res.size());
    }

    if (args.find("maxProfit3") != args.end()) {
        vector<int> prices;

        prices = {3, 3, 5, 0, 0, 3, 1, 4};
        printf("maxProfit3: %d\n", s.maxProfit3(prices));

        prices = {1, 2, 3, 4, 5};
        printf("maxProfit3: %d\n", s.maxProfit3(prices));
    }

    if (args.find("maxProfit4") != args.end()) {
        vector<int> prices;

        prices = {2,4,1};
        printf("maxProfit4: %d\n", s.maxProfit4(2, prices));

        prices = {3,2,6,5,0,3};
        printf("maxProfit4: %d\n", s.maxProfit4(2, prices));
    }

    if (args.find("canJump") != args.end()) {
        vector<int> nums;

        nums = {3, 3, 5, 0, 0, 3, 1, 4};
        printf("canJump: %d\n", s.canJump(nums));

        nums = {3, 2, 1, 0, 4};
        printf("canJump: %d\n", s.canJump(nums));
    }

    if (args.find("jump") != args.end()) {
        vector<int> nums;

        nums = {3, 3, 5, 0, 0, 3, 1, 4};
        printf("jump: %d\n", s.jump(nums));

        nums = {3, 2, 1, 1, 4};
        printf("jump: %d\n", s.jump(nums));

        nums = {3, 2, 1, 0, 4};
        printf("jump: %d\n", s.jump(nums));

        nums = {2, 3, 1, 1, 4};
        printf("jump: %d\n", s.jump(nums));

        nums = {2, 3, 0, 1, 4};
        printf("jump: %d\n", s.jump(nums));

        nums = {2, 1};
        printf("jump: %d\n", s.jump(nums));
    }

    if (args.find("canReach") != args.end()) {
        vector<int> nums;
        nums = {4,2,3,0,3,1,2};
        printf("canReach: %d\n", s.canReach(nums, 5));
        nums = {4,2,3,0,3,1,2};
        printf("canReach: %d\n", s.canReach(nums, 0));
        nums = {3,0,2,1,2};
        printf("canReach: %d\n", s.canReach(nums, 2));
        nums = {4,4,1,3,0,3};
        printf("canReach: %d\n", s.canReach(nums, 2));
    }

    if (args.find("canReach") != args.end()) {
        printf("canReach: %d\n", s.canReach("011010", 2, 3));
        printf("canReach: %d\n", s.canReach("01101110", 2, 3));
    }

    if (args.find("maxResult") != args.end()) {
        vector<int> nums;
        nums = {1,-1,-2,4,-7,3};
        printf("maxResult: %d\n", s.maxResult(nums, 2));
        nums = {10,-5,-2,4,0,3};
        printf("maxResult: %d\n", s.maxResult(nums, 3));
        nums = {1,-5,-20,4,-1,3,-6,-3};
        printf("maxResult: %d\n", s.maxResult(nums, 2));
    }

    if (args.find("minJumps") != args.end()) {
        vector<int> nums;
        nums = {100,-23,-23,404,100,23,23,23,3,404};
        printf("minJumps: %d\n", s.minJumps(nums));
        nums = {7};
        printf("minJumps: %d\n", s.minJumps(nums));
        nums = {7,6,9,6,9,6,9,7};
        printf("minJumps: %d\n", s.minJumps(nums));
        nums = {11,22,7,7,7,7,7,7,7,22,13};
        printf("minJumps: %d\n", s.minJumps(nums));
        nums = {2,0,2,0};
        printf("minJumps: %d\n", s.minJumps(nums));
        nums = {51,64,-15,58,98,31,48,72,78,-63,92,-5,64,-64,51,-48,64,48,-76,-86,-5,-64,-86,-47,92,-41,58,72,31,78,-15,-76,72,-5,-97,98,78,-97,-41,-47,-86,-97,78,-97,58,-41,72,-41,72,-25,-76,51,-86,-65,78,-63,72,-15,48,-15,-63,-65,31,-41,95,51,-47,51,-41,-76,58,-81,-41,88,58,-81,88,88,-47,-48,72,-25,-86,-41,-86,-64,-15,-63};
        printf("minJumps: %d\n", s.minJumps(nums));
    }

    if (args.find("maxJumps") != args.end()) {
        vector<int> nums;
        nums = {6,4,14,6,8,13,9,7,10,6,12};
        printf("maxJumps: %d\n", s.maxJumps(nums, 2));
        nums = {3,3,3,3,3};
        printf("maxJumps: %d\n", s.maxJumps(nums, 3));
        nums = {7,6,5,4,3,2,1};
        printf("maxJumps: %d\n", s.maxJumps(nums, 1));
    }

    if (args.find("isMatch") != args.end()) {
        printf("isMatch: %d\n", s.isMatch("abcde", "*a*e"));
        printf("isMatch: %d\n", s.isMatch("abcde", "*a"));
        printf("isMatch: %d\n", s.isMatch("abcde", "*e"));
        printf("isMatch: %d\n", s.isMatch("abcde", "**e"));
        printf("isMatch: %d\n", s.isMatch("abcde", "**"));
    }

    if (args.find("uniquePaths") != args.end()) {
        printf("uniquePaths: %d\n", s.uniquePaths(3, 2));
        printf("uniquePaths: %d\n", s.uniquePaths(3, 7));
    }

    if (args.find("uniquePathsWithObstacles") != args.end()) {
        vector<vector<int>> obstacleGrid;

        obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        printf("uniquePathsWithObstacles: %d\n", s.uniquePathsWithObstacles(obstacleGrid));

        obstacleGrid = {{0, 1}, {0, 0}};
        printf("uniquePathsWithObstacles: %d\n", s.uniquePathsWithObstacles(obstacleGrid));

        obstacleGrid = {{0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
        printf("uniquePathsWithObstacles: %d\n", s.uniquePathsWithObstacles(obstacleGrid));

        obstacleGrid = {{1, 0}, {0, 0}};
        printf("uniquePathsWithObstacles: %d\n", s.uniquePathsWithObstacles(obstacleGrid));

        obstacleGrid = {{0, 0}, {1, 1}, {0, 0}};
        printf("uniquePathsWithObstacles: %d\n", s.uniquePathsWithObstacles(obstacleGrid));
    }

    if (args.find("minPathSum") != args.end()) {
        vector<vector<int>> grid;

        grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        printf("minPathSum: %d\n", s.minPathSum(grid));
    }

    if (args.find("uniquePathsIII") != args.end()) {
        vector<vector<int>> grid;

        grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
        printf("uniquePathsIII: %d\n", s.uniquePathsIII(grid));

        grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
        printf("uniquePathsIII: %d\n", s.uniquePathsIII(grid));
    }

    if (args.find("numDecodings") != args.end()) {
        printf("numDecodings: %d\n", s.numDecodings("12"));
        printf("numDecodings: %d\n", s.numDecodings("226"));
    }

    if (args.find("swapPairs") != args.end()) {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        printf("swapPairs: \n");
        vector<int> vec = s.getLinkedList(s.swapPairs(head));
        printVectorInt(vec, vec.size());
    }

    if (args.find("removeNthFromEnd") != args.end()) {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        printf("removeNthFromEnd: \n");
        {
            vector<int> vec = s.getLinkedList(s.removeNthFromEnd(head, 4));
            printVectorInt(vec, vec.size());
        }
        {
            vector<int> vec = s.getLinkedList(s.removeNthFromEnd(head, 1));
            printVectorInt(vec, vec.size());
        }
    }

    if (args.find("rotateRight") != args.end()) {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        printf("rotateRight: \n");
        vector<int> vec = s.getLinkedList(s.rotateRight(head, 2));
        printVectorInt(vec, vec.size());
    }

    if (args.find("reverseList") != args.end()) {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        printf("reverseList: \n");
        vector<int> vec = s.getLinkedList(s.reverseList(head));
        printVectorInt(vec, vec.size());
    }

    if (args.find("reverseBetween") != args.end()) {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printf("reverseBetween: \n");
        vector<int> vec = s.getLinkedList(s.reverseBetween(head, 2, 4));
        printVectorInt(vec, vec.size());
    }

    if (args.find("reorderList") != args.end()) {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printf("reorderList: \n");
        s.reorderList(head);
        vector<int> vec = s.getLinkedList(head);
        printVectorInt(vec, vec.size());
    }
    if (args.find("reorderList") != args.end()) {
        ListNode* head = new ListNode(1);
        printf("reorderList: \n");
        s.reorderList(head);
        vector<int> vec = s.getLinkedList(head);
        printVectorInt(vec, vec.size());
    }
    if (args.find("reorderList") != args.end()) {
        ListNode* head = nullptr;
        printf("reorderList: \n");
        s.reorderList(head);
        vector<int> vec = s.getLinkedList(head);
        printVectorInt(vec, vec.size());
    }
    if (args.find("reorderList") != args.end()) {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
        printf("reorderList: \n");
        s.reorderList(head);
        vector<int> vec = s.getLinkedList(head);
        printVectorInt(vec, vec.size());
    }

    if (args.find("findArray") != args.end()) {
        vector<int> vec = {5, 2, 0, 3, 1};
        auto res = s.findArray(vec);
        printVectorInt(res, res.size());
    }

    if (args.find("binaryGap") != args.end()) {
        printf("binaryGap: %d\n", s.binaryGap(22));
        printf("binaryGap: %d\n", s.binaryGap(8));
    }

    if (args.find("sumRegion") != args.end()) {
        vector<vector<int>> mat{
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5},
        };
        NumMatrix s(mat);
        printf("sumRegion: %d\n", s.sumRegion(2, 1, 4, 3));
        printf("sumRegion: %d\n", s.sumRegion(1, 1, 2, 2));
        printf("sumRegion: %d\n", s.sumRegion(1, 2, 2, 4));
    }

    if (args.find("canCross") != args.end()) {
        vector<int> vec;

        vec = {0,1,3,5,6,8,12,17};
        printf("canCross: %d\n", s.canCross(vec));
        vec = {0,1,2,3,4,8,9,11};
        printf("canCross: %d\n", s.canCross(vec));
    }

    if (args.find("findTargetSumWays") != args.end()) {
        vector<int> vec;

        vec = {1,1,1,1,1};
        printf("findTargetSumWays: %d\n", s.findTargetSumWays(vec, 3));
        vec = {1};
        printf("findTargetSumWays: %d\n", s.findTargetSumWays(vec, 1));
    }

    if (args.find("coinChange") != args.end()) {
        vector<int> vec;

        vec = {1,2,5};
        printf("coinChange: %d\n", s.coinChange(vec, 11));
        vec = {2};
        printf("coinChange: %d\n", s.coinChange(vec, 3));
        vec = {1};
        printf("coinChange: %d\n", s.coinChange(vec, 0));
    }

    if (args.find("coinChange2") != args.end()) {
        vector<int> vec;

        vec = {1,2,5};
        printf("coinChange2: %d\n", s.change(5, vec));
        vec = {2};
        printf("coinChange2: %d\n", s.change(3, vec));
        vec = {10};
        printf("coinChange2: %d\n", s.change(10, vec));
    }

    if (args.find("findMaxForm") != args.end()) {
        vector<string> vec;

        vec = {"10","0001","111001","1","0"};
        printf("findMaxForm: %d\n", s.findMaxForm(vec, 5, 3));
        vec = {"10","0","1"};
        printf("findMaxForm: %d\n", s.findMaxForm(vec, 1, 1));
        vec = {"10","0001","111001","1","0"};
        printf("findMaxForm: %d\n", s.findMaxForm(vec, 3, 4));
    }

    if (args.find("lengthOfLIS") != args.end()) {
        vector<int> vec;

        vec = {0,1,0,3,2,3};
        printf("lengthOfLIS: %d\n", s.lengthOfLIS(vec));
        vec = {7,7,7,7,7,7,7};
        printf("lengthOfLIS: %d\n", s.lengthOfLIS(vec));
        vec = {10,9,2,5,3,7,101,18};
        printf("lengthOfLIS: %d\n", s.lengthOfLIS(vec));
    }

    if (args.find("maxHeight") != args.end()) {
        vector<vector<int>> vec;

        vec = { { 50, 45, 20 }, { 95, 37, 53 }, { 45, 23, 12 } };
        printf("maxHeight: %d\n", s.maxHeight(vec));
        vec = { { 38, 25, 45 }, { 76, 35, 3 } };
        printf("maxHeight: %d\n", s.maxHeight(vec));
        vec = { { 7, 11, 17 }, { 7, 17, 11 }, { 11, 7, 17 }, { 11, 17, 7 }, { 17, 7, 11 }, { 17, 11, 7 } };
        printf("maxHeight: %d\n", s.maxHeight(vec));
        vec = { { 50, 26, 84 }, { 2, 55, 62 }, { 64, 63, 72 } };
        printf("maxHeight: %d\n", s.maxHeight(vec));
    }

    if (args.find("trapRainWater") != args.end()) {
        vector<vector<int>> vec;

        vec = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
        printf("trapRainWater: %d\n", s.trapRainWater(vec));
        vec = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
        printf("trapRainWater: %d\n", s.trapRainWater(vec));
        vec = {{5,5,5,1},{5,1,1,5},{5,1,5,5},{5,2,5,8}};
        printf("trapRainWater: %d\n", s.trapRainWater(vec));
    }

    if (args.find("isBalanced") != args.end()) {
        printf("isBalanced: %d\n", s.isBalanced(new TreeNode(1)));
        printf("isBalanced: %d\n", s.isBalanced(new TreeNode(1, nullptr, new TreeNode(2))));
        printf("isBalanced: %d\n", s.isBalanced(new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr)));
        printf("isBalanced: %d\n", s.isBalanced(new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)))));
        printf("isBalanced: %d\n", s.isBalanced(new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), nullptr)));
        printf("isBalanced: %d\n", s.isBalanced(new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), new TreeNode(4))));
        printf("isBalanced: %d\n", s.isBalanced(new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(8), nullptr), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr))));
    }

    if (args.find("binaryTreePaths") != args.end()) {
        printVectorString(s.binaryTreePaths(new TreeNode(1)));
        printVectorString(s.binaryTreePaths(new TreeNode(1, nullptr, new TreeNode(2))));
        printVectorString(s.binaryTreePaths(new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr)));
        printVectorString(s.binaryTreePaths(new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)))));
        printVectorString(s.binaryTreePaths(new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), nullptr)));
        printVectorString(s.binaryTreePaths(new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), new TreeNode(4))));
        printVectorString(s.binaryTreePaths(new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(8), nullptr), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr))));
    }

    if (args.find("findTilt") != args.end()) {
        printf("findTilt: %d\n", s.findTilt(new TreeNode(1)));
        printf("findTilt: %d\n", s.findTilt(new TreeNode(1, nullptr, new TreeNode(2))));
        printf("findTilt: %d\n", s.findTilt(new TreeNode(1, new TreeNode(3), new TreeNode(2))));
        printf("findTilt: %d\n", s.findTilt(new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr)));
        printf("findTilt: %d\n", s.findTilt(new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)))));
        printf("findTilt: %d\n", s.findTilt(new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), nullptr)));
        printf("findTilt: %d\n", s.findTilt(new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), new TreeNode(4))));
        printf("findTilt: %d\n", s.findTilt(new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(8), nullptr), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr))));
    }

    if (args.find("constructMaximumBinaryTree") != args.end()) {
        {
            vector<int> nums = {3, 2, 1};
            TreeNode* res = s.constructMaximumBinaryTree(nums);
            printVectorString2D(s.printTree(res));
        }
        {
            vector<int> nums = {3,2,1,6,0,5};
            TreeNode* res = s.constructMaximumBinaryTree(nums);
            printVectorString2D(s.printTree(res));
        }
    }

    if (args.find("deleteDuplicates2") != args.end()) {
        printf("deleteDuplicates2: \n");
        ListNode* head;
        vector<int> vec;
        head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(4)))))));
        vec = s.getLinkedList(s.deleteDuplicates2(head));
        printVectorInt(vec, vec.size());
        head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(4)))))));
        vec = s.getLinkedList(s.deleteDuplicates2(head));
        printVectorInt(vec, vec.size());
        head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4))))));
        vec = s.getLinkedList(s.deleteDuplicates2(head));
        printVectorInt(vec, vec.size());
    }
}