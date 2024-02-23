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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LinkedListSolution {
public:

    vector<int> getLinkedList(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        return res;
    }

    // 141. Linked List Cycle
    // Given head, the head of a linked list, determine if the linked list has a cycle in it.
    bool hasCycle(ListNode *head) {
        ListNode *walker = head;
        ListNode *runner = head;
        while (runner != NULL && runner->next != NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) return true;
        }
        return false;
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
    // Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    // Given the head of a linked list, rotate the list to the right by k places.
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

    // 83. Remove Duplicates from Sorted List
    // Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }

    // 82. Remove Duplicates from Sorted List II
    // Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
    ListNode* deleteDuplicates2(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next) {
            ListNode* tmp = cur->next->next;
            while (tmp && tmp->val == cur->next->val) {
                tmp = tmp->next;
            }
            if (tmp != cur->next->next) {
                cur->next = tmp;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
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

    // find the cross node of two linked lists
    struct ListNode* findCross(ListNode* list1, ListNode* list2) {
        int n1 = 0;
        ListNode* tmp = list1;
        while (tmp) {
            n1++;
            tmp = tmp->next;
        }
        int n2 = 0;
        tmp = list2;
        while (tmp) {
            n2++;
            tmp = tmp->next;
        }
        ListNode* longer = n1 > n2 ? list1 : list2;
        ListNode* shorter = n1 <= n2 ? list1 : list2;
        int diff = abs(n1 - n2);
        for (int i = 0; i < diff; i++) {
            longer = longer->next;
        }
        while (longer != shorter) {
            longer = longer->next;
            shorter = shorter->next;
        }
        return longer;
    }
};