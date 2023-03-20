#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include "code.cpp"
#include "lru_cache.cpp"
#include "helper.cpp"

using namespace std;

int main() {
    Solution s;
    // {
    //     printf("longestPalindrome: %s\n", s.longestPalindrome("asdasdsad").c_str());
    //     printf("longestPalindrome: %s\n", s.longestPalindrome("ahha").c_str());
    // }
    // {
    //     printf("isPalindrome: %d\n", s.isPalindrome(12321));
    //     printf("isPalindrome: %d\n", s.isPalindrome(12));
    //     printf("isPalindrome: %d\n", s.isPalindrome(1241));
    // }
    // {
    //     printf("intToRoman: %s\n", s.intToRoman(1241).c_str());
    //     printf("intToRoman: %s\n", s.intToRoman(1994).c_str());
    //     printf("intToRoman: %s\n", s.intToRoman(3999).c_str());
    // }

    // {
    //     vector<string> vec_str = s.letterCombinations("234");
    //     printf("letterCombinations: \n");
    //     printVectorString(vec_str, vec_str.size());
    //     printf("\n");
    // }

    // {
    //     printf("isValid: %d\n", s.isValid("["));
    //     printf("isValid: %d\n", s.isValid("]"));
    //     printf("isValid: %d\n", s.isValid("(]"));
    //     printf("isValid: %d\n", s.isValid("[()]"));
    //     printf("isValid: %d\n", s.isValid("()[]{}"));
    // }

    // {
    //     vector<string> vec_str;
    //     vec_str = s.generateParenthesis(3);
    //     printf("generateParenthesis: \n");
    //     printVectorString(vec_str, vec_str.size());
    //     printf("\n");
    // }

    // {
    //     vector<int> nums{0, 1, 1, 2, 2, 3, 3, 4};
    //     int res = s.removeDuplicates(nums);
    //     printf("removeDuplicates: %d\n", res);
    //     printVectorInt(nums, res);
    //     printf("\n");
    // }

    // {
    //     vector<int> nums{0, 1, 1, 2, 2, 3, 3, 4};
    //     int res = s.removeElement(nums, 3);
    //     printf("removeElement: %d\n", res);
    //     printVectorInt(nums, res);
    //     printf("\n");
    // }

    // {
    //     printf("strStr: %d\n", s.strStr("abcdefg", "bcd"));
    //     printf("strStr: %d\n", s.strStr("abcdefg", "efg"));
    //     printf("strStr: %d\n", s.strStr("a", "a"));
    //     printf("strStr: %d\n", s.strStr("abc", "abcd"));
    //     printf("strStr: %d\n", INT32_MAX);
    //     printf("strStr: %d\n", INT32_MIN);
    // }

    // {
    //     string str;
    //     vector<string> words;
    //     vector<int> res;

    //     str = "barfoofoobarthefoobarman";
    //     words = {"bar", "foo", "the"};
    //     res = s.findSubstring(str, words);
    //     printf("findSubstring: \n");
    //     printVectorInt(res, res.size());
    //     printf("\n");

    //     str = "wordgoodgoodgoodbestword";
    //     words = {"word", "good", "best", "good"};
    //     res = s.findSubstring(str, words);
    //     printf("findSubstring: \n");
    //     printVectorInt(res, res.size());
    //     printf("\n");

    //     str = "barfoothefoobarman";
    //     words = {"foo", "bar"};
    //     res = s.findSubstring(str, words);
    //     printf("findSubstring: \n");
    //     printVectorInt(res, res.size());
    //     printf("\n");
    // }

    // {
    //     vector<int> nums;

    //     nums = {1, 2, 3, 4, 5};
    //     s.nextPermutation(nums);
    //     printf("nextPermutation: \n");
    //     printVectorInt(nums, nums.size());

    //     nums = {1, 5, 8, 4, 7, 6, 5, 3, 1};
    //     s.nextPermutation(nums);
    //     printf("nextPermutation: \n");
    //     printVectorInt(nums, nums.size());

    //     nums = {1, 3, 2};
    //     s.nextPermutation(nums);
    //     printf("nextPermutation: \n");
    //     printVectorInt(nums, nums.size());

    //     nums = {3, 2, 1};
    //     s.nextPermutation(nums);
    //     printf("nextPermutation: \n");
    //     printVectorInt(nums, nums.size());
    // }

    // {
    //     printf("longestValidParentheses: %d\n", s.longestValidParentheses("()()()"));
    //     printf("longestValidParentheses: %d\n", s.longestValidParentheses("(())"));
    //     printf("longestValidParentheses: %d\n", s.longestValidParentheses(")())"));
    // }

    // {
    //     vector<int> nums;

    //     nums = {1, 2, 3, 4, 5};
    //     printf("searchInOrder: %d\n", s.search1(nums, 3));

    //     nums = {1, 2, 3, 4, 5};
    //     printf("searchInOrder: %d\n", s.search1(nums, 4));

    //     nums = {1, 2, 3, 4, 5};
    //     printf("searchInOrder: %d\n", s.search1(nums, 6));
    // }

    // {
    //     vector<int> nums;

    //     nums = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    //     printf("searchInRotated: %d\n", s.search(nums, 3));

    //     nums = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    //     printf("searchInRotated: %d\n", s.search(nums, 8));

    //     nums = {1, 2, 3, 4, 5};
    //     printf("searchInRotated: %d\n", s.search(nums, 6));
    // }

    // {
    //     vector<int> nums;
    //     vector<int> res;

    //     nums = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7};
    //     res = s.searchRange(nums, 3);
    //     printf("searchRange: \n");
    //     printVectorInt(res, res.size());

    //     nums = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7};
    //     res = s.searchRange(nums, 5);
    //     printf("searchRange: \n");
    //     printVectorInt(res, res.size());

    //     nums = {1, 1, 2, 3, 3, 3, 4, 4, 6, 6, 7};
    //     res = s.searchRange(nums, 5);
    //     printf("searchRange: \n");
    //     printVectorInt(res, res.size());
    // }

    // {
    //     vector<int> nums;

    //     nums = {1, 2, 3, 4, 5};
    //     printf("searchInsert: %d\n", s.searchInsert(nums, 3));

    //     nums = {1, 2, 3, 5};
    //     printf("searchInsert: %d\n", s.searchInsert(nums, 4));

    //     nums = {2, 3, 4, 5};
    //     printf("searchInsert: %d\n", s.searchInsert(nums, 1));

    //     nums = {1, 2, 3, 4};
    //     printf("searchInsert: %d\n", s.searchInsert(nums, 5));
    // }

    // {
    //     vector<vector<char>> board;

    //     board = {{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
    //              {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
    //              {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
    //              {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
    //              {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
    //              {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
    //              {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
    //              {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
    //              {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
    //     printf("isValidSudoku: %d\n", s.isValidSudoku(board));
    // }

    // {
    //     vector<vector<char>> board;
    //     board = {{'.', '.', '.', '.', '.', '.', '5', '.', '.'},
    //              {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    //              {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    //              {'9', '3', '.', '.', '2', '.', '4', '.', '.'},
    //              {'.', '.', '7', '.', '.', '.', '3', '.', '.'},
    //              {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    //              {'.', '.', '.', '3', '4', '.', '.', '.', '.'},
    //              {'.', '.', '.', '.', '.', '3', '.', '.', '.'},
    //              {'.', '.', '.', '.', '.', '5', '2', '.', '.'}};
    //     printf("isValidSudoku: %d\n", s.isValidSudoku(board));
    // }

    // {
    //     vector<vector<char>> board;
    //     board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    //     s.solveSudoku(board);
    //     printf("solveSudoku: \n");
    //     printVectorChar2D(board);
    // }

    {
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

    {
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

    {
        TreeNode* root;
        vector<vector<string>> res;
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        root = s.buildTree(preorder, inorder);
        res = s.printTree(root);
        printVectorString2D(res);
    }

    {
        for (int i = 0; i < 7; i++) {
            printf("i: %d, numTrees: %d\n", i, s.numTrees(i));
        }
        for (int i = 0; i < 7; i++) {
            printf("i: %d, numTreesDP: %d\n", i, s.numTreesDP(i));
        }
    }

    {
        for (int i = 1; i <= 3; i++) {
            vector<TreeNode*> res;
            res = s.generateTrees(i);

            printf("i: %d, generateTrees: \n", i);
            for (int j = 0; j < res.size(); j++) {
                printVectorString2D(s.printTree(res[j]));
            }
        }
    }

    {
        printf("isValidBST: %d\n", s.isValidBST(new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, new TreeNode(6)), new TreeNode(5)), new TreeNode(3))));
        printf("isValidBST: %d\n", s.isValidBST(new TreeNode(6, new TreeNode(4, new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), nullptr), new TreeNode(5)), new TreeNode(7))));
        printf("isValidBST: %d\n", s.isValidBST(new TreeNode(2, new TreeNode(2), new TreeNode(2))));
    }

    {
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

    {
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

    {
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

    {
        vector<vector<int>> res;
        res = s.generate(1);
        printf("generatePascalTriangle\n");
        printVectorInt2D(res);
        res = s.generate(5);
        printf("generatePascalTriangle\n");
        printVectorInt2D(res);
    }

    {
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

    {
        vector<int> prices;

        prices = {3, 3, 5, 0, 0, 3, 1, 4};
        printf("maxProfit3: %d\n", s.maxProfit3(prices));

        prices = {1, 2, 3, 4, 5};
        printf("maxProfit3: %d\n", s.maxProfit3(prices));
    }

    {
        vector<int> nums;

        nums = {3, 3, 5, 0, 0, 3, 1, 4};
        printf("canJump: %d\n", s.canJump(nums));

        nums = {3, 2, 1, 0, 4};
        printf("canJump: %d\n", s.canJump(nums));
    }

    {
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

    {
        printf("isMatch: %d\n", s.isMatch("abcde", "*a*e"));
        printf("isMatch: %d\n", s.isMatch("abcde", "*a"));
        printf("isMatch: %d\n", s.isMatch("abcde", "*e"));
        printf("isMatch: %d\n", s.isMatch("abcde", "**e"));
        printf("isMatch: %d\n", s.isMatch("abcde", "**"));
    }

    {
        printf("uniquePaths: %d\n", s.uniquePaths(3, 2));
        printf("uniquePaths: %d\n", s.uniquePaths(3, 7));
    }

    {
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

    {
        vector<vector<int>> grid;

        grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        printf("minPathSum: %d\n", s.minPathSum(grid));
    }

    {
        vector<vector<int>> grid;

        grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
        printf("uniquePathsIII: %d\n", s.uniquePathsIII(grid));

        grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
        printf("uniquePathsIII: %d\n", s.uniquePathsIII(grid));
    }

    {
        printf("numDecodings: %d\n", s.numDecodings("12"));
        printf("numDecodings: %d\n", s.numDecodings("226"));
    }

    {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        printf("swapPairs: \n");
        vector<int> vec = s.getLinkedList(s.swapPairs(head));
        printVectorInt(vec, vec.size());
    }

    {
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

    {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        printf("rotateRight: \n");
        vector<int> vec = s.getLinkedList(s.rotateRight(head, 2));
        printVectorInt(vec, vec.size());
    }

    {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        printf("reverseList: \n");
        vector<int> vec = s.getLinkedList(s.reverseList(head));
        printVectorInt(vec, vec.size());
    }

    {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printf("reverseBetween: \n");
        vector<int> vec = s.getLinkedList(s.reverseBetween(head, 2, 4));
        printVectorInt(vec, vec.size());
    }

    {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        printf("reorderList: \n");
        s.reorderList(head);
        vector<int> vec = s.getLinkedList(head);
        printVectorInt(vec, vec.size());
    }

    {
        ListNode* head = new ListNode(1);
        printf("reorderList: \n");
        s.reorderList(head);
        vector<int> vec = s.getLinkedList(head);
        printVectorInt(vec, vec.size());
    }

    {
        ListNode* head = nullptr;
        printf("reorderList: \n");
        s.reorderList(head);
        vector<int> vec = s.getLinkedList(head);
        printVectorInt(vec, vec.size());
    }

    {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
        printf("reorderList: \n");
        s.reorderList(head);
        vector<int> vec = s.getLinkedList(head);
        printVectorInt(vec, vec.size());
    }
}